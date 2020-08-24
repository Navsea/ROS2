import filterpy.kalman as fp
import numpy as np
from dataclasses import dataclass
import time
from vinerows_msgs.msg import Vinerowlist

# The vine row width can be assumed to be known, received via CAN
VINE_ROW_WIDTH = 3
ENABLE_DEBUG = False


@dataclass
class Object:
    speed: float
    heading: np.ndarray


@dataclass
class Runtime:
    time_stamp: float
    time_step: float
    prev_time_stamp: float


@dataclass
class VinerowStaticLimits:
    center_x_min: float
    center_x_max: float
    center_y_min: float
    center_y_max: float
    center_z_min: float
    center_z_max: float
    direction_x_min: float
    direction_x_max: float
    direction_y_min: float
    direction_y_max: float
    direction_z_min: float
    direction_z_max: float
    distance_x_min: float
    distance_x_max: float


@dataclass
class VinerowData:
    center_x: float
    center_y: float
    center_z: float
    direction_x: float
    direction_y: float
    direction_z: float
    distance_x: float


@dataclass
class VinerowLimits:
    static: VinerowStaticLimits
    dynamic: VinerowData


# check if float is within a range
def in_range(value, min_value, max_value):
    return (value <= max_value) and (value >= min_value)


# determines whether the measurement is within the range of the estimate
def dynamic_check_ok(estimate, measurement, variation):
    return in_range(estimate, measurement - measurement * variation, measurement + measurement * variation)


class VinerowFilter:
    def __init__(self):
        self.kfs = []
        static_limits = VinerowStaticLimits(0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.)
        dynamic_limits = VinerowData(0., 0., 0., 0., 0., 0., 0.)
        self.limits = VinerowLimits(static=static_limits, dynamic=dynamic_limits)
        self.gh = Object(0., np.array([0., 0., 0.]))
        self.runtime = [Runtime(0., 0., 0.) for _ in range(7)]
        self.set_gh_data()
        self.first = [True] * 7
        self.z = np.zeros((7, 8))
        self.initialize_filter()
        print("Vinerow filter initialization done")

    def set_gh_data(self):
        self.gh.speed = 1  # m/s
        self.gh.heading = np.array([0.4, 0.3, 0.6])

    def set_runtime_data(self, i):
        self.runtime[i].time_stamp = time.time()
        self.runtime[i].time_step = self.runtime[i].time_stamp - self.runtime[i].prev_time_stamp
        # print('Time stamp', i, ': ', self.runtime[i].time_stamp, ' Time step: ', self.runtime[i].time_step)
        self.runtime[i].prev_time_stamp = self.runtime[i].time_stamp

    def set_runtime_data_msg(self, msg):
        print('Time stamp: {}'.format(msg.header.stamp.nanosec))
        for runtime in self.runtime:
            runtime.time_stamp = msg.header.stamp.nanosec
            runtime.time_step = (runtime.time_stamp - runtime.prev_time_stamp)/1e6
            runtime.prev_time_stamp = runtime.time_stamp
            # print('Time stamp: {}, Time step: {}'.format(runtime.time_stamp, runtime.time_step))

    def initialize_filter(self):
        print("Initializing filters")
        # define the limits of a vinerow, normalized to center vinerow
        # the data I receive now, is not centered to tractor center
        # that's why the x limits are now non default
        self.limits.static.center_x_max = -5
        self.limits.static.center_x_min = -11
        self.limits.static.center_y_max = 1.5
        self.limits.static.center_y_min = -1.5
        self.limits.static.center_z_max = 0.5
        self.limits.static.center_z_min = -0.5
        self.limits.static.direction_x_max = 1
        self.limits.static.direction_x_min = -1
        self.limits.static.direction_y_max = 1
        self.limits.static.direction_y_min = -1
        self.limits.static.direction_z_max = 1
        self.limits.static.direction_z_min = -1
        self.limits.static.distance_x_max = 110
        self.limits.static.distance_x_min = -110

        self.limits.dynamic.center_x = 1
        self.limits.dynamic.center_y = 0.05
        self.limits.dynamic.center_z = 0.05
        self.limits.dynamic.direction_x = 0.05
        self.limits.dynamic.direction_y = 0.05
        self.limits.dynamic.direction_z = 0.05
        self.limits.dynamic.distance_x = 0.20

        # create a list of 7 kalman filters, one for each vine row
        for i in range(7):
            self.kfs.append(fp.KalmanFilter(dim_x=7, dim_z=7))
        # initialize all the filters
        for i, kf in enumerate(self.kfs):
            kf.x = np.zeros(7)

            kf.F = np.array([[1., 0., 0., 0., 0., 0., 0.],
                             [0., 1., 0., 0., self.gh.speed * self.runtime[i].time_step, 0., 0.],
                             [0., 0., 1., 0., 0, self.gh.speed * self.runtime[i].time_step, 0.],
                             [0., 0., 0., 1., 0., 0., 0.],
                             [0., 0., 0., 0., 1., 0., 0.],
                             [0., 0., 0., 0., 0., 1., 0.],
                             [0., 0., 0., self.gh.speed * self.runtime[i].time_step, 0., 0., 1.]])

            kf.H = np.diag(np.full(7, 1))

            kf.P = np.diag(np.array([100., 100., 100., 0.64, 0.64, 0.64, 400.]))

            kf.R = np.diag(np.array([10., 10., 10., 0.3, 0.3, 0.3, 15.]), 0)

            kf.Q = np.diag(np.array([1., 1., 1., 0.3, 0.3, 0.3, 15.]), 0)

            kf.B = np.zeros((7, 7))

    def process_measurements(self, msg):
        # allow the function to report
        VERBOSE = True

        if VERBOSE: print("Processing measurements")
        # make sure that we start with a clean measurement array
        self.z = np.zeros((7, 8))

        # the lidar measurements contain an offset, remove that offset here for now
        for i, measurement in enumerate(msg.vinerows):
            msg.vinerows[i].center.y = measurement.center.y + 1.43

        # register the time stamps of the messages
        # self.set_runtime_data_msg(msg)

        # determine whether the measurement is a reasonable vine row measurement
        self.static_measurement_validation(msg)

        # determine the vine row index of the measurements, fill in the measurement array and register variance in kalman filters
        self.vinerow_indexing(msg)

        # determine whether the measurement is within a reasonable range of the previously determined position
        self.dynamic_measurement_validation()

        if VERBOSE:
            for i, valid_meas in enumerate(self.z):
                print("meas index {} - status: {}, y pos: {}".format(i, self.z[i][7], self.z[i][1]))

    # static vine row checking
    # this function checks whether the measurement is a reasonable vine row measurement
    def static_measurement_validation(self, msg):
        VERBOSE = True
        for i, measurement in enumerate(msg.vinerows):
            measurement_ok = True
            if not in_range(measurement.center.x, self.limits.static.center_x_min, self.limits.static.center_x_max):
                if VERBOSE: print("measurement {}: static x violation".format(i))
                measurement_ok = False
            if not in_range((measurement.center.y % VINE_ROW_WIDTH), self.limits.static.center_y_min, self.limits.static.center_y_max):
                if VERBOSE: print("measurement {}: static y violation".format(i))
                measurement_ok = False
            if not in_range(measurement.center.z, self.limits.static.center_z_min, self.limits.static.center_z_max):
                if VERBOSE: print("measurement {}: static z violation".format(i))
                measurement_ok = False
            if not in_range(measurement.direction.x ,self.limits.static.direction_x_min, self.limits.static.direction_x_max):
                if VERBOSE: print("measurement {}: static dir x violation".format(i))
                measurement_ok = False
            if not in_range(measurement.direction.y, self.limits.static.direction_y_min, self.limits.static.direction_y_max):
                if VERBOSE: print("measurement {}: static dir y violation".format(i))
                measurement_ok = False
            if not in_range(measurement.direction.z, self.limits.static.direction_z_min, self.limits.static.direction_z_max):
                if VERBOSE: print("measurement {}: static dir z violation".format(i))
                measurement_ok = False
            if not in_range(measurement.distance, self.limits.static.distance_x_min, self.limits.static.distance_x_max):
                if VERBOSE: print("measurement {}: static distance violation".format(i))
                measurement_ok = False

            # store the result of the static check
            measurement.is_valid = float(measurement_ok)

    # determine the vine row index of the measurements and fill in measurement matrix
    def vinerow_indexing(self, msg):
        # for every vinerow measurement
        for i, measurement in enumerate(msg.vinerows):
            # check if static check was ok
            if measurement.is_valid:
                # determine the vinerow index
                vinerow_index = round(measurement.center.y / VINE_ROW_WIDTH)

                # only keep 7 vine rows
                if abs(vinerow_index) <= 3:
                    self.z[vinerow_index + 3][0] = measurement.center.x
                    self.z[vinerow_index + 3][1] = measurement.center.y
                    self.z[vinerow_index + 3][2] = measurement.center.z
                    self.z[vinerow_index + 3][3] = measurement.direction.x
                    self.z[vinerow_index + 3][4] = measurement.direction.y
                    self.z[vinerow_index + 3][5] = measurement.direction.z
                    self.z[vinerow_index + 3][6] = measurement.distance
                    self.z[vinerow_index + 3][7] = measurement.is_valid

                    # register the variance of the measurements
                    self.kfs[vinerow_index + 3].R = np.diag(measurement.variance)

    # dynamic vine row checking
    # this function checks whether the measurement is within a reasonable range of the previously determined position
    def dynamic_measurement_validation(self):
        VERBOSE = True
        for i, measurement in enumerate(self.z):
            measurement_ok = True
            # only process when the static check was ok and we already have processed one measurement before (so you can compare it to prev measurement)
            if measurement[7] and not self.first:
                if not (dynamic_check_ok(self.kfs[i].x[0], measurement[0], self.limits.dynamic.center_x)):
                    if VERBOSE: print("measurement {}: dynamic x violation".format(i))
                    measurement_ok = False
                if not (dynamic_check_ok(self.kfs[i].x[1], measurement[1], self.limits.dynamic.center_y)):
                    if VERBOSE: print("measurement {}: dynamic y violation".format(i))
                    measurement_ok = False
                if not (dynamic_check_ok(self.kfs[i].x[2], measurement[2], self.limits.dynamic.center_z)):
                    if VERBOSE: print("measurement {}: dynamic z violation".format(i))
                    measurement_ok = False
                if not (dynamic_check_ok(self.kfs[i].x[3], measurement[3], self.limits.dynamic.direction_x)):
                    if VERBOSE: print("measurement {}: dynamic dir x violation".format(i))
                    measurement_ok = False
                if not (dynamic_check_ok(self.kfs[i].x[4], measurement[4], self.limits.dynamic.direction_y)):
                    if VERBOSE: print("measurement {}: dynamic dir y violation".format(i))
                    measurement_ok = False
                if not (dynamic_check_ok(self.kfs[i].x[5], measurement[5], self.limits.dynamic.direction_z)):
                    if VERBOSE: print("measurement {}: dynamic dir z violation".format(i))
                    measurement_ok = False
                if not (dynamic_check_ok(self.kfs[i].x[6], measurement[6], self.limits.dynamic.distance_x)):
                    if VERBOSE: print("measurement {}: dynamic distance violation".format(i))
                    measurement_ok = False

                measurement[7] = measurement_ok

    def predict(self):
        VERBOSE = False
        if VERBOSE: print("predicting")
        for i, kf in enumerate(self.kfs):
            # before prediction, always set the runtime
            self.set_runtime_data(i)  # note that the first time exec, this will contain invalid data
            # only execute prediction after we have received a first measurement (filter init required).
            if not self.first[i]:
                if VERBOSE: print("prediction w timestep: ", self.runtime[i].time_step, " and speed: ", self.gh.speed)
                kf.F[1][4] = self.gh.speed * self.runtime[i].time_step
                kf.F[2][5] = self.gh.speed * self.runtime[i].time_step
                kf.F[6][3] = -self.gh.speed * self.runtime[i].time_step

                kf.predict(F=kf.F)

    def update(self):
        if ENABLE_DEBUG:
            print("updating")

        # for every vine row measurement
        for i, single_row in enumerate(self.z):
            # only update if the measurement was valid
            if single_row[7]:
                # check if this was the first valid measurement
                if self.first[i]:
                    self.first[i] = False
                    # remove the is_valid flag from the measurement and use the first measurement as the state vector
                    self.kfs[i].x = np.delete(self.z[i], 7)
                    if ENABLE_DEBUG:
                        print("state vector init:", self.kfs[i].x)
                else:  # otherwise update the filters with the measurement
                    # remove the is_valid flag before updating the kalman filter
                    self.kfs[i].update(z=np.delete(self.z[i], 7))
                    if ENABLE_DEBUG:
                        print("measurement", i, ": ", np.delete(self.z[i], 7))
