#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat source = cv::imread("image.JPG");
    cv::Mat gray, gray2;
    cv::Mat edges;
    cv::Mat color;
    cv::Mat distribution;

    if (source.empty()) {
        std::cout << "No Image" << std::endl;
        return 1;
    } 

    std::cout << source.size() << std::endl;
    std::cout << gray.size() << std::endl;

    cv::cvtColor(source, gray, cv::COLOR_RGB2GRAY);
    std::cout << gray.size() << std::endl;
    std::cout << "cvtColor" << std::endl;
    gray.copySize(gray2);
    cv::medianBlur(gray, gray2, 5);
    std::cout << "medianBlur" << std::endl;
    cv::adaptiveThreshold(gray, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 35, 9);
    std::cout << "adaptiveThreshold" << std::endl;
    cv::bilateralFilter(source, color, 9, 300, 300);
    std::cout << "bilateralFilter" << std::endl;
    cv::bitwise_and(color, color, distribution, edges);
    std::cout << "bitwise_and" << std::endl;

    cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
    cv::imshow("window", distribution);
    cv::waitKey(0);
    cv::destroyWindow("window");

    return 0;
}
