# CMake generated Testfile for 
# Source directory: /home/kenneth/PycharmProjects/ros2_ws_fix/src/sensor_fusion_msgs
# Build directory: /home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lint_cmake "/usr/bin/python3" "-u" "/opt/ros/eloquent/share/ament_cmake_test/cmake/run_test.py" "/home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs/test_results/sensor_fusion_msgs/lint_cmake.xunit.xml" "--package-name" "sensor_fusion_msgs" "--output-file" "/home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/eloquent/bin/ament_lint_cmake" "--xunit-file" "/home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs/test_results/sensor_fusion_msgs/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/kenneth/PycharmProjects/ros2_ws_fix/src/sensor_fusion_msgs")
add_test(xmllint "/usr/bin/python3" "-u" "/opt/ros/eloquent/share/ament_cmake_test/cmake/run_test.py" "/home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs/test_results/sensor_fusion_msgs/xmllint.xunit.xml" "--package-name" "sensor_fusion_msgs" "--output-file" "/home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs/ament_xmllint/xmllint.txt" "--command" "/opt/ros/eloquent/bin/ament_xmllint" "--xunit-file" "/home/kenneth/PycharmProjects/ros2_ws_fix/src/build/sensor_fusion_msgs/test_results/sensor_fusion_msgs/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/kenneth/PycharmProjects/ros2_ws_fix/src/sensor_fusion_msgs")
subdirs("sensor_fusion_msgs__py")
