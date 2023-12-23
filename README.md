###零、在vscode里写markdown
:smile::smile::smile::smile::smile:  
####1、安装markdown  
markdown可在vscode中作为插件安装使用  
先下载vscode，然后在插件商店安装即可  
在文件夹中新建.md格式文件  
安装配套插件：Markdown All in One、Markdown Preview   Ehanced、Paste Image  
安装完成后，重启vscode使插件生效  
Ctrl+，（逗号）=打开setting，进入设置界面  
搜索break，取消勾选Break on single new line，避免不必要的空格  
完成编辑md文件后，右键点击预览（preview），查看效果  
顺带一提，ctrl+b在vscode中打开或关闭左边文件栏  
####2、常规markdown使用  
标题###   行末两个空格换行  
emoji:xxx::blush::smirk::kissing::heart_eyes:  
嵌入代码
```c
 #include<stdio.h>
 ```  



###一、使用虚拟机安装Ubuntu系统
####1、选择虚拟机安装Ubuntu系统  
安装Vmware虚拟机最好划分一片专门的磁盘区域  
在镜像网站下载ubuntu系统文件  
在虚拟机内安装ubuntu  
:x:安装ubuntu时有警告说会删除磁盘内所有文件，我觉得应该早分一个磁盘区域  
但是后来发现它所说的删除磁盘文件指的是虚拟机的而不是主机的  
直接安装:laughing:  :o:
####2、换源,换输入法  
安装完成后需要换服务源，默认的不能用  
在软件更新器中安装选择最佳服务源  
ctrl+alt+T打开命令行输入指令 sudo apt upgrade更新软件  
:x:输入密码时不显示（我还以为出什么问题了）:o:  （指令clear清空）  
安装软件中心
```
sudo apt install pla  
```
```
sudo apt install plasma-discover  
```
安装中文输入法
```
sudo apt install ibus-sunpinyin
```  
:x:我的Ubuntu右上角没有语言栏:dizzy_face:  
在设置里键盘找到输入源添加  
实现可以在命令行中打中文，但是在浏览器里打不出来:dizzy_face:  
重启一下虚拟机就可以了(遇事不决重启一下):sweat::o:  



###二、打印“Hello，World”
####1、下载vscode，配置C++环境  
安装vscode，没什么好说的  
输入指令sudo apt-get install vim安装vim  
sudo apt install g++安装g++  
安装汉化、C\C++插件  
####2、写自定义的hello_world头文件  
:x:但是因为一开始误选了gcc运行时出错了  
在右上角点击齿轮图案重新选择调试配置  
选择g++生成和调试文件:o:  
:heart:main()
```cpp
#include<iostream>
#include"hello.h"
int main(){
    printfhello();
    return 0;
}  
```
:purple_heart:hello.h头文件
```cpp
#include<iostream>
#ifndef HELLOWORLD_H
#define HELLOWORLD_H
void printfhello(){
    printf("Hello,World!\n");
}
#endif
```



###三、编写代码调用摄像头
####1、安装OpenCV  
#####使用包管理器安装OpenCV
安装编译工具
```
sudo apt-get install build-essential 
``` 
安装从cmake,git,pkg-config辅助工具
```
sudo apt-get install cmake git pkg-config libgtk2.0-dev libavcodec-dev libavformat-dev libswscale-dev  
sudo apt-get install cmake  
sudo apt-get update  
sudo apt-get install libopencv-dev  
```
安装关联库
```
sudo apt-get install python-dev python-opencv python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```
:x:报错本人搞不定，打算手动安装源代码  
#####手动安装源代码
更新软件和软件源  
```
sudo apt-get update 
sudo apt-get upgrade 
```
安装依赖库  
```
sudo apt-get install build-essential libgtk2.0-dev libgtk-3-dev libavcodec-dev libavformat-dev libjpeg-dev libswscale-dev libtiff5-dev
```
下载OpenCV源代码,从官网上下载source文件  
将文件解压缩到Codes文件夹中，并重命名为opencv  
进入到下载好的opencv目录中，新建目录build并进入build目录  
```
cd opencv
mkdir build
cd build
```
编译debug模式opencv库文件  
```
cmake -D CMAKE_BUILD_TYPE=Debug -D OPENCV_GENERATE_PKGCONFIG=YES -D CMAKE_INSTALL_PREFIX=/usr/local/OpenCV/Debug -D WITH_FFMPEG=ON ..
```  
编译安装OpenCV，使用make编译  
```
make -j8
```
使用make安装  
```
sudo make install
```
:x:安装过程中出错了,报错设备上空间不够，但是我明明划了100GB的磁盘空间  
打开磁盘资源管理器，看一下是根文件夹不足，为什么主文件夹只有2.7GB  
下载安装gparted来进行磁盘管理  
```
sudo apt update
sudo apt install gparted
```
打开gparted
```
sudo gparted
```
通过gparted发现又80GB的空间未分配，尝试扩大主文件夹，报错  
```
unable to resize read-only file system /dev/sda3
The file system can not be realized while it is mounted read-only.
Either unmount the file system or remount it read-write
```
无法调整只读文件系统/dev/sda3的大小  
使用lsof命令来检查确认没有任何正在使用/dev/sda3文件系统的进程  
```
sudo lsof | grep /dev/sda3
```
使用umount命令来卸载/dev/sda3文件系统：
```
sudo umount /dev/sda3
```
使用mount命令将/dev/sda3文件系统重新挂载为读写模式
```
sudo mount -o remount,rw /dev/sda3
```
然后通过gparted扩大主文件夹  
成功了成功了成功了！:o::laughing::laughing::laughing:  
环境配置  
打开/etc/ld.so.conf  
```
sudo gedit /etc/ld.so.conf
```
在文件中加上一行  
```
include /usr/local/lib
```
加入缓存  
```
 sudo ldconfig
```
打开 /etc/bash.bashrc 文件  
```
sudo gedit /etc/bash.bashrc
```
末尾加上  
```
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
export PKG_CONFIG_PATH
```
再输入命令  
```
source /etc/bash.bashrc
```
检验  
```
pkg-config opencv --modversion
```
会出现opencv的版本  
:x:但是报错:dizzy_face:  
```
Package opencv was not found in the pkg-config search path.
```
创建pkgconfig文件
```
cd /usr/local/lib
 
sudo mkdir pkgconfig
cd pkgconfig
sudo touch opencv.pc
sudo vim opencv.pc
```
进入vim模式插入代码   :qa! 不保存退出  :wq  保存退出
```
prefix=/usr/local
exec_prefix=${prefix}
includedir=${prefix}/include
libdir=${exec_prefix}/lib
 
Name: opencv
Description: The opencv library
Version:4.8.0
Cflags: -I${includedir}/opencv4
Libs: -L${libdir} -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann  -lopencv_core
```
检验:o:  
```
pkg-config opencv --modversion
```
转到 opencv-4.5.2/sample/cpp/example_cmake 目录下，打开终端  
```
cmake .
make
./opencv_example
```
转到 opencv-4.5.2/sample/cpp/example_cmake 目录下，打开终端  
```
cmake .
make
./opencv_example
```
"Hello,OpenCV"安装成功:laughing:
:x:但是摄像头并没有打开  
```
Built with OpenCV 4.8.0
[ WARN:0@0.002] global cap_v4l.cpp:982 open VIDEOIO(V4L2:/dev/video0): can't open camera by index
[ERROR:0@0.002] global obsensor_uvc_stream_channel.cpp:156 getStreamChannelGroup Camera index out of range
No capture
```
我猜测是因为虚拟机并没有连接到主机的摄像头  
在虚拟机设置里将USB版本改到3.1  
然后在虚拟机右下角点击摄像头图标，连接  
再次转到 opencv-4.5.2/sample/cpp/example_cmake 目录下，打开终端  
```
cmake .
make
./opencv_example
```
成功调取摄像头:o::laughing:  


####2、编写调用摄像头代码
一开始的代码  
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0); // 打开默认摄像头
    if (!cap.isOpened()) {
        std::cerr << "无法打开摄像头" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // 从摄像头获取新的一帧
        cv::imshow("Camera", frame);
        if (cv::waitKey(30) >= 0) // 按任意键退出
            break;
    }

    cap.release(); // 释放摄像头
    cv::destroyAllWindows(); // 关闭所有窗口

    return 0;
}
```
:x:报错：
```
/usr/bin/g++ -fdiagnostics-color=always -g /home/laoyoutiao/Codes/camera/main.cpp -o /home/laoyoutiao/Codes/camera/main
/home/laoyoutiao/Codes/camera/main.cpp:1:10: fatal error: opencv2/opencv.hpp: 没有那个文件或目录
    1 | #include <opencv2/opencv.hpp>
      |          ^~~~~~~~~~~~~~~~~~~~
compilation terminated.
```  
OpenCV路径出错，找到正确的路径/usr/lib/x86_64-linux-gnu  
安装库文件一时半会搞不定，回到上一步试试从源代码安装  
好安装好源代码后  
:x:运行程序，报错  
```
 fatal error: opencv/opencv.hpp: 没有那个文件或目录
```
找不到文件Opencv2，应该是路径的问题  
在/usr/include/opencv4/opencv2找到opencv2文件  
然后在usr/include/中创建一个opencv2的文件链接命令如下：  
```
sudo ln -s /usr/include/opencv4/opencv2 /usr/include/
```
再次运行文件，之前的报错似乎解决了:o:  
:x:但是又有新的报错  
```
collect2: error: ld returned 1 exit status
```
链接器无法成功地将所有的目标文件和库文件连接成一个可执行文件  
我在usr/include和usr/local/include都复制了一份Opencv2  
需要链接OpenCV库以便在程序中使用相关函数和类  
编译你的程序，使用以下命令：  
```
g++ -o main main.cpp `pkg-config opencv --cflags --libs`
```
:x:报错
```
/usr/bin/ld: 找不到 -lopencv_shape: 没有那个文件或目录
/usr/bin/ld: 找不到 -lopencv_superres: 没有那个文件或目录
/usr/bin/ld: 找不到 -lopencv_videostab: 没有那个文件或目录
collect2: error: ld returned 1 exit status
```
尝试使用另一个版本的 OpenCV,下面使用以下命令安装 OpenCV 4.5.3：  
```
sudo apt-get install libopencv-dev=4.5.3-4
```
然后，使用以下命令编译程序：  
```
g++ -fdiagnostics-color=always -g /home/laoyoutiao/Codes/camera/main.cpp -o /home/laoyoutiao/Codes/camera/main `pkg-config --cflags --libs opencv4`
```
运行程序  
```
./main
```
成功！！！！！！！！！！:o::grin::grin::grin:  
![Alt text](%E5%9B%BE%E7%89%871.png)


###四、将代码上传到github上  
####1、新建github仓库  
没什么可说的
####2、将本地代码推送到github上  
新建文件夹，输入命令  
```
git init
```
把这个文件夹变成Git可管理的仓库
输入命令  
```
git add .
```
把这个文件夹下的目录的全部文件文件添加到缓存区  
查看现在的提交状态  
```
git status
```
把文件提交到本地仓库  
```
git commit -m "这里面写你的注释"  
```
连接本地Git仓库和Github仓库
格式
```
$ git remote add origin git@github.com:用户名/仓库名.git
```
```
$ git remote add origin git@github.com:YuanJieMaster/Invoke-the-camera.git
```
推送代码
```
git push origin main
```
github仓库的默认分支名是main，而较老版本的git在本地仓库默认的分支名是master，所以之前会出现上传后github上多了一个master的分支，如果想改成一致，可以使用如下命令：  
```
git branch -m master main
```
使用这个命令时需保证远程github仓库时没有本地提交的分支，如果提交main，而github上又设置选了README就会失败，:x:报错：  
```
error: failed to push some refs to 'github.com:YuanJieMaster/Invoke-the-camera.git'
```
此时可以使用以下命令将远程仓库中的更改合并到你的本地仓库中
```
git pull origin main
```
之后再使用push命令:o:  



