#include <opencv2/opencv.hpp>

using namespace std;

void myTrackbarCallback(int pos, cv::Mat& lut) {
    for(int i = 0; i < 256; ++i) {
        lut.at<uchar>(i) = std::pow((i*1.0) / 255, pos * 1.0 / 100) * 255;
    }
}

int main()
{
    cv::Mat image=cv::imread("/home/sergey/im.png");

    int dim(256);
    cv::Mat lut(1, &dim, CV_8U);
    cv::namedWindow("Example");
    int current_position = 0;
    cv::createTrackbar("Position", "Example", &current_position, 200);
    while (1) {
        cv::Mat image_clone = image.clone();
        cv::Mat two_images(image.rows, image.cols * 2, image.type());
        cv::Mat roi_left = two_images(cv::Rect(0, 0, image.cols, image.rows));
        cv::Mat roi_right = two_images(cv::Rect(image.cols, 0, image.cols, image.rows));
        myTrackbarCallback(current_position, lut);
        cv::LUT(image_clone, lut, image_clone);
        image.copyTo(roi_left);
        image_clone.copyTo(roi_right);
        cv::imshow("Example", two_images);
        char c = cv::waitKey(33);
        if (c == 27)
            break;
    }
    cv::destroyWindow("Example");
}
