/*#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void negativeTransformation(Mat& src) {
    const int N = 256; 

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            src.at<uchar>(y, x) = N - 1 - src.at<uchar>(y, x);
        }
    }
}

int main() {
    Mat img_in;

    img_in = imread("Lena.png");
    cvtColor(img_in, img_in, cv::COLOR_RGB2GRAY);
    imshow("source img", img_in);

    Mat negativeImage = img_in.clone();
    negativeTransformation(negativeImage);

    imshow("Negative Image", negativeImage);

    waitKey(0);

    return 0;
}
*/