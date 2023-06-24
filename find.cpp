#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // 读取图片
    Mat img = imread("../logo.png");

    // 转换为灰度图
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // 检测角点
    vector<Point2f> corners;
    goodFeaturesToTrack(gray, corners, 100, 0.01, 10);

    // 在角点上绘制圆圈和文字
    for (size_t i = 0; i < corners.size(); i++) {
        circle(img, corners[i], 3, Scalar(0, 0, 255), -1);
        stringstream ss;
        ss << "(" << corners[i].x << ", " << corners[i].y << ")";
        putText(img, ss.str(), corners[i], FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));
    }

    // 保存处理后的图片
    imwrite("../save.png", img);

    // 将检测到的角点坐标输出到文件
    ofstream ofs("../Points.txt");
    for (size_t i = 0; i < corners.size(); i++) {
        ofs << "(" << corners[i].x << ", " << corners[i].y << ")" << endl;
    }
    ofs.close();

    // 显示结果
    imshow("Corners", img);
    waitKey(0);

    return 0;
}
