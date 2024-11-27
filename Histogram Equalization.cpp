#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void transform1(const Mat& src, Mat& dst) {
    dst = src.clone(); // 복사본 생성
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            dst.at<uchar>(y, x) = src.at<uchar>(y, x) / 2; // s = r / 2
        }
    }
}

void transform2(const Mat& src, Mat& dst) {
    dst = src.clone(); // 복사본 생성
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            dst.at<uchar>(y, x) = 128 + src.at<uchar>(y, x) / 2; // s = 128 + r / 2
        }
    }
}

/* // Step 2: 히스토그램 평활화 함수
vector<int> calculateHistogram(const Mat& src) {
    vector<int> histogram(256, 0); // 256 크기의 히스토그램 초기화 (0 ~ 255)

    // 각 픽셀 값에 대해 히스토그램 계산
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int pixelValue = src.at<uchar>(y, x);
            histogram[pixelValue]++;
        }
    }

    return histogram;
}

// 누적 분포 함수 계산 함수
vector<int> calculate(const vector<int>& histogram, int totalPixels) {
    vector<int> cdf(256, 0);
    cdf[0] = histogram[0];

    // 누적 분포 계산
    for (int i = 1; i < 256; i++) {
        cdf[i] = cdf[i - 1] + histogram[i];
    }

    return cdf;
}

// 히스토그램 평활화 적용 함수
Mat applyHistogramEqualization(const Mat& src) {
    // 1. 히스토그램 계산
    vector<int> histogram = calculateHistogram(src);

    // 2. 누적 분포 함수 계산
    int totalPixels = src.rows * src.cols;
    vector<int> cdf = calculate(histogram, totalPixels);

    // 3. 픽셀 값 매핑
    vector<int> equalizedMap(256, 0);
    for (int i = 0; i < 256; i++) {
        equalizedMap[i] = static_cast<int>(255.0 * (cdf[i] - cdf[0]) / (totalPixels - cdf[0])); // 변환 함수 적용
        if (equalizedMap[i] < 0) equalizedMap[i] = 0;   // 하한 처리
        if (equalizedMap[i] > 255) equalizedMap[i] = 255; // 상한 처리
    }

    // 4. 원본 이미지에 평활화된 값을 적용한 새로운 이미지 생성
    Mat dst = src.clone();
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int pixelValue = src.at<uchar>(y, x);
            dst.at<uchar>(y, x) = equalizedMap[pixelValue]; // 평활화된 픽셀 값으로 매핑
        }
    }
    return dst;
}*/


int main() {
    Mat img_in;

    img_in = imread("Lena.png");
    cvtColor(img_in, img_in, COLOR_RGB2GRAY);
    // Step 1: lena1 (s = r / 2), lena2 (s = 128 + r / 2) 이미지 생성
    Mat lena1, lena2;
    transform1(img_in, lena1);
    transform2(img_in, lena2);
    
    // Step 2: 히스토그램 평활화 적용(함수를 구현 하였지만, 제대로 적용 되지 않음)
    /*
    img_in = applyHistogramEqualization(img_in);
    lena1 = applyHistogramEqualization(lena1);
    lena2 = applyHistogramEqualization(lena2);
    */
    imshow("Original Lena", img_in);
    imshow("Lena1 (s = r / 2)", lena1);
    imshow("Lena2 (s = 128 + r / 2)", lena2);
    // 키 입력 대기
    waitKey(0);

    return 0;
}
