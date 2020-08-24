import filterpy.kalman as fp
import numpy as np
from dataclasses import dataclass
import time
from sensor_fusion_msgs.msg import Vinerows

# The vine row width can be assumed to be known, received via CAN
VINE_ROW_WIDTH = 3

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

class SfVinerow:
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
        self.gh.speed = 0.1  # m/s
        self.gh.heading = np.array([0.4, 0.3, 0.6])

    def set_runtime_data(self, i):
        self.runtime[i].time_stamp = time.time()
        self.runtime[i].time_step = self.runtime[i].time_stamp - self.runtime[i].prev_time_stamp
        # print('Time stamp', i, ': ', self.runtime[i].time_stamp, ' Time step: ', self.runtime[i].time_step)
        self.runtime[i].prev_time_stamp = self.runtime[i].time_stamp

    def initialize_filter(self):
        print("Initializing filters")
        # define the limits of a vinerow, normalized to center vinerow
        # the data I receive now, is not centered to tractor center
        # thats why the x limits are now non default
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

            kf.Q = np.diag(np.array([10., 10., 10., 0.3, 0.3, 0.3, 15.]), 0)

            kf.B = np.zeros((7, 7))

    def process_measurements(self, msg):
        print("Processing measurements")
        # make sure that we start with a clean measurement array
        self.z = np.zeros((7, 8))

        for i, vinerow in enumerate(msg.vinerows):
            print('RECEIVED ', i, ':\n' + 'Center: {center_x} {center_y} {center_z}\n'.format(center_x=vinerow.center.x,
                                                                                            center_y=vinerow.center.y,
                                                                                            center_z=vinerow.center.z) +
                  'Direction: {dir_x} {dir_y} {dir_z}\n'.format(dir_x=vinerow.direction.x,
                                                                dir_y=vinerow.direction.y,
                                                                dir_z=vinerow.direction.z) +
                  'Distance till end: {dist}'.format(dist=vinerow.distance)
                  )

            # static vine row checking
            if ((vinerow.center.x >= self.limits.static.center_x_min) and (vinerow.center.x <= self.limits.static.center_x_max) and
                # removed y check for now, not sure what i can apply for limits here
                # ((vinerow.center.y % VINE_ROW_WIDTH) >= self.limits.static.center_y_min) and ((vinerow.center.y %
                    # VINE_ROW_WIDTH) <= self.limits.static.center_y_max) and
                (vinerow.center.z >= self.limits.static.center_z_min) and (vinerow.center.z <= self.limits.static.center_z_max) and
                (vinerow.direction.x >= self.limits.static.direction_x_min) and (vinerow.direction.x <= self.limits.static.direction_x_max) and
                (vinerow.direction.y >= self.limits.static.direction_y_min) and (vinerow.direction.y <= self.limits.static.direction_y_max) and
                (vinerow.direction.z >= self.limits.static.direction_z_min) and (vinerow.direction.z <= self.limits.static.direction_z_max) and
                (vinerow.distance >= self.limits.static.distance_x_min) and (vinerow.distance <= self.limits.static.distance_x_max)):
                print("static check ok")
                # determine the vinerow index
                vinerow_index = self.vinerow_indexing(vinerow.center.y)

                # get variance of measurement
                self.kfs[vinerow_index].R = np.diag(vinerow.variance)

                # only keep 7 vine rows
                if abs(vinerow_index) <= 3:
                    self.z[vinerow_index+3][0] = vinerow.center.x
                    self.z[vinerow_index+3][1] = vinerow.center.y
                    self.z[vinerow_index+3][2] = vinerow.center.z
                    self.z[vinerow_index+3][3] = vinerow.direction.x
                    self.z[vinerow_index+3][4] = vinerow.direction.y
                    self.z[vinerow_index+3][5] = vinerow.direction.z
                    self.z[vinerow_index+3][6] = vinerow.distance
                    self.z[vinerow_index+3][7] = True

            else:
                print('measurement rejected')
                if not((vinerow.center.x >= self.limits.static.center_x_min) and (vinerow.center.x <= self.limits.static.center_x_max)):
                    print('x violation')
                if not(((vinerow.center.y % VINE_ROW_WIDTH) >= self.limits.static.center_y_min) and ((vinerow.center.y % VINE_ROW_WIDTH) <= self.limits.static.center_y_max)):
                    print('y violation')
                if not((vinerow.center.z >= self.limits.static.center_z_min) and (vinerow.center.z <= self.limits.static.center_z_max)):
                    print('z violation')
                if not((vinerow.direction.x >= self.limits.static.direction_x_min) and (vinerow.direction.x <= self.limits.static.direction_x_max)):
                    print('dir x violation')
                if not((vinerow.direction.y >= self.limits.static.direction_y_min) and (vinerow.direction.y <= self.limits.static.direction_y_max)):
                    print('dir y violation')
                if not((vinerow.direction.z >= self.limits.static.direction_z_min) and (vinerow.direction.z <= self.limits.static.direction_z_max)):
                    print('dir z violation')
                if not((vinerow.distance >= self.limits.static.distance_x_min) and (vinerow.distance <= self.limits.static.distance_x_max)):
                    print('distance violation')

        # dynamic vine row checking
        # to be implemented

        print("Processed measurements")
        for i, valid_meas in enumerate(self.z):
            print("meas index: ", i, "center_y: ", self.z[i][1])

    def vinerow_indexing(self, y_pos):
        return round(y_pos / VINE_ROW_WIDTH)


    def predict(self):
        print("predicting")
        for i, kf in enumerate(self.kfs):
            # before prediction, always set the runtime
            self.set_runtime_data(i)  # note that the first time exec, this will contain invalid data
            # only execute prediction after we have received a first measurement (filter init required).
            if not self.first[i]:
                print("prediction w timestep: ", self.runtime[i].time_step, " and speed: ", self.gh.speed)
                kf.F[1][4] = self.gh.speed * self.runtime[i].time_step
                kf.F[2][5] = self.gh.speed * self.runtime[i].time_step
                kf.F[6][3] = -self.gh.speed * self.runtime[i].time_step

                kf.predict(F=kf.F)

    def update(self):
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
                    print("state vector init:", self.kfs[i].x)
                else:  # otherwise update the filters with the measurement
                    # remove the is_valid flag before updating the kalman filter
                    self.kfs[i].update(z=np.delete(self.z[i], 7))
                    print("measurement", i, ": ", np.delete(self.z[i], 7))
