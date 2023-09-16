在工作目录下
mkdir src
cd src
ros2 pkg create sensor_test_tools --build-type ament_cmake --dependencies rclspp sensor_msgs

运行，删除build文件夹后
colcon build
source install/setup.bash
ros2 run sensor_test_tools lidar_subscribe

如果在更新完include后，
发现还显示检测到 #include 错误。请更新 includePath。
此时，不必慌张，只需要在 vscode 界面上，按住 Ctrl+Shift+P，然后再在输入框输入 reload，并选择开发人员：重新加载窗口。
加载完成之后，问题即可得到解决。