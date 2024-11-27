/*#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;


Mat gammaTransformation(const ::Mat& src, double gamma) {
    Mat dst = src.clone();
        
    const double Gamma = 1.0 / gamma;

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            float normalizedPixel = src.at<uchar>(y, x) / 255.0;
            float correctedPixel = pow(normalizedPixel, Gamma);

            dst.at<uchar>(y, x) = static_cast<uchar>(correctedPixel * 255.0);
        }
    }
    return dst;
}

int main() {
    Mat img_in;
   
    img_in = imread("Lena.png");
    cvtColor(img_in, img_in, cv::COLOR_RGB2GRAY);
    imshow("source img", img_in);

    Mat gamma0_5 = gammaTransformation(img_in, 0.5);
    Mat gamma1_5 = gammaTransformation(img_in, 1.5);

    imshow("Gamma 0.5", gamma0_5);
    imshow("Gamma 1.5", gamma1_5);

    waitKey(0);

    return 0;
}*/