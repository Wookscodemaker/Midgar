#include <iostream>
#include <cmath> // 包含数学函数库18.281
using namespace std;

// 函数：将度分秒转换为十进制度数
double convertDMS2DD(int degrees, int minutes, double seconds) {
    return degrees + minutes / 60.0 + seconds / 3600.0;
}

// 函数：计算坐标变化量
void calculateCoordinateChange(double distance, double azimuth, double& deltaX, double& deltaY) {
    // 将方位角从度转换为弧度
    double angleInRadians = azimuth * M_PI / 180.0;

    // 计算坐标变化量
    // 假设方位角是从正北方向顺时针测量的
    deltaX = distance * sin(angleInRadians); // x方向的变化量
    deltaY = distance * cos(angleInRadians); // y方向的变化量
}

int main() {
    double distance; // 两点间距离
    int degrees;     // 方位角的度
    int minutes;     // 方位角的分
    double seconds;  // 方位角的秒
    double azimuth;  // 转换后的十进制度数
    double deltaX, deltaY; // 坐标变化量

    // 输入两点间距离
    cout << "请输入两点间的距离：";
    cin >> distance;

    // 输入方位角的度分秒
    cout << "请输入方位角的度：";
    cin >> degrees;
    cout << "请输入方位角的分：";
    cin >> minutes;
    cout << "请输入方位角的秒：";
    cin >> seconds;

    // 将度分秒转换为十进制度数
    azimuth = convertDMS2DD(degrees, minutes, seconds);

    // 计算坐标变化量
    calculateCoordinateChange(distance, azimuth, deltaX, deltaY);

    // 输出结果
    cout << "x方向的坐标变化量为：" << deltaX << endl;
    cout << "y方向的坐标变化量为：" << deltaY << endl;

    return 0;
}