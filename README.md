# ros2_slam
基于ros2操作系统搭建的slam工程

配置环境
一键安装ros2 humble：
$ wget http://fishros.com/install -O fishros && . fishros

eigen：Mozilla Public License Version 2.0 http://mozilla.org/MPL/2.0/
官网下载最新安装包：http://eigen.tuxfamily.org/index.php?title=Main_Page
终端输入(卸载老版本eigen)
$ sudo rm -rf /usr/include/eigen3 /usr/lib/cmake/eigen3 /usr/share/doc/libeigen3-dev /usr/share/pkgconfig/eigen3.pc /var/lib/dpkg/info/libeigen3-dev.list /var/lib/dpkg/info/libeigen3-dev.md5sums  
安装
$ mkdir build
$ cd build
$ cmake . -DCMAKE_INSTALL_PREFIX=/usr ..
$ sudo make install

gtsam：BSD-licensed https://www.linfo.org/bsdlicense.html
gtsam官网及官方文档：https://gtsam.org
在终端输入
$ sudo apt-get install libboost-all-dev
$ sudo apt-get install cmake
$ sudo apt-get install libtbb-dev
下载源代码https://github.com/borglab/gtsam/releases/tag/4.2（这是4.2版本，写文档时的最新版）
解压后在<源代码文件夹>中打开终端并输入
$ mkdir build
$ cd build
$ cmake ..
$ make check (optional, runs unit tests)
$ sudo make install

opencv：Apache License Version 2.0, January 2004 http://www.apache.org/licenses/
首先安装需要的包，在终端输入
sudo apt-get install libgtk2.0-dev pkg-config
下载相应的opencv
$ git clone https://github.com/opencv/opencv.git 或者下载最新的release源代码
$ mkdir build
$ cd build
$ cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..
$ make -j8
$ sudo make install
$ sudo ldconfig

pangolin： MIT license https://github.com/stevenlovegrove/Pangolin/blob/master/LICENCE
在终端输入：
$ git clone https://github.com/stevenlovegrove/Pangolin.git 或者下载最新的release源代码
$ cd Pangolin
$ mkdir build
$ cd build
$ cmake ..
$ make -j16
$ sudo make install
$ sudo ldconfig

fmt:https://github.com/fmtlib/fmt/blob/master/LICENSE
在终端输入
$ git clone https://github.com/fmtlib/fmt.git 或者下载最新的release源代码（为了保持兼容性，本案例使用fmt-9.1.0）
在CMakeists.txt中添加编译选项
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
在终端输入
$ cd fmt
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
$ sudo ldconfig

Sophus:https://github.com/strasdat/Sophus/blob/main-1.x/LICENSE.txt
在终端输入
$ git clone https://github.com/strasdat/Sophus.git 或者下载最新的release源代码
$ cd Sophus
$ mkdir build
$ cd build
$ cmake ..
$ make -j16
$ sudo make install
$ sudo ldconfig

spdlog:MIT License https://github.com/gabime/spdlog/blob/v1.x/LICENSE
$ git clone https://github.com/gabime/spdlog.git 或者下载最新的release源代码
在CMakeists.txt中添加编译选项
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
$ cd spdlog
$ mkdir build
$ cd build
$ cmake ..
$ make -j16
$ sudo make install
$ sudo ldconfig

g2o:g2o is licensed under the BSD License. However, some libraries are available under different license terms. 
$ git clone https://github.com/RainerKuemmerle/g2o.git 或者下载最新的release源代码(为了兼容性，使用20230223版本)
$ cd g2o
$ mkdir build
$ cd build
$ cmake ..
$ make -j16
$ sudo make install
$ sudo ldconfig

ceres: Apache License Version 2.0 https://github.com/ceres-solver/ceres-solver/blob/master/LICENSE
在终端输入
$ sudo apt-get install  liblapack-dev libsuitesparse-dev libcxsparse3 libgflags-dev libgoogle-glog-dev libgtest-dev
$ git clone https://github.com/ceres-solver/ceres-solver.git
$ cd ceres-solver
$ mkdir build
$ cd build
$ cmake ..
$ make -j16
$ sudo make install
$ sudo ldconfig

sudo apt-get install libpcap-dev
https://blog.csdn.net/qq_35097289/article/details/130690974

Livox SDK2:MIT License https://github.com/Livox-SDK/Livox-SDK2/blob/master/LICENSE.txt
在终端输入
$ git clone https://github.com/Livox-SDK/Livox-SDK2.git
$ cd ./Livox-SDK2/
$ mkdir build
$ cd build
$ cmake .. && make -j
$ sudo make install

Livox ROS Driver 2：MIT License https://github.com/Livox-SDK/livox_ros_driver2/blob/master/LICENSE.txt
在终端输入
$ cd ros2_slam/src
$ git clone https://github.com/Livox-SDK/livox_ros_driver2.git livox_ros_driver2
$ source /opt/ros/humble/setup.sh
cd 到功能包源代码目录中
$ ./build.sh humble
$ source ../../install/setup.sh
$ ros2 launch livox_ros_driver2 rviz_HAP_launch.py