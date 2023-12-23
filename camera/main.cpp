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
