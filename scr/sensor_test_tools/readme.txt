在工作目录下
mkdir src
cd src
ros2 pkg create sensor_test_tools --build-type ament_cmake --dependencies rclspp sensor_msgs

运行，删除build文件夹后
colcon build
source install/setup.bash
ros2 run sensor_test_tools lidar_subscribe