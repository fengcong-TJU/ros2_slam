# ros2_slam
基于ros2操作系统搭建的slam工程

配置环境

eigen：Mozilla Public License Version 2.0 http://mozilla.org/MPL/2.0/
终端输入
$ sudo apt-get install libeigen3-dev

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
$ git clone https://github.com/fmtlib/fmt.git 或者下载最新的release源代码
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
$ ldconfig
