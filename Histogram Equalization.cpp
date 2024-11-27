#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void transform1(const Mat& src, Mat& dst) {
    dst = src.clone(); // ���纻 ����
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            dst.at<uchar>(y, x) = src.at<uchar>(y, x) / 2; // s = r / 2
        }
    }
}

void transform2(const Mat& src, Mat& dst) {
    dst = src.clone(); // ���纻 ����
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            dst.at<uchar>(y, x) = 128 + src.at<uchar>(y, x) / 2; // s = 128 + r / 2
        }
    }
}

/* // Step 2: ������׷� ��Ȱȭ �Լ�
vector<int> calculateHistogram(const Mat& src) {
    vector<int> histogram(256, 0); // 256 ũ���� ������׷� �ʱ�ȭ (0 ~ 255)

    // �� �ȼ� ���� ���� ������׷� ���
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int pixelValue = src.at<uchar>(y, x);
            histogram[pixelValue]++;
        }
    }

    return histogram;
}

// ���� ���� �Լ� ��� �Լ�
vector<int> calculate(const vector<int>& histogram, int totalPixels) {
    vector<int> cdf(256, 0);
    cdf[0] = histogram[0];

    // ���� ���� ���
    for (int i = 1; i < 256; i++) {
        cdf[i] = cdf[i - 1] + histogram[i];
    }

    return cdf;
}

// ������׷� ��Ȱȭ ���� �Լ�
Mat applyHistogramEqualization(const Mat& src) {
    // 1. ������׷� ���
    vector<int> histogram = calculateHistogram(src);

    // 2. ���� ���� �Լ� ���
    int totalPixels = src.rows * src.cols;
    vector<int> cdf = calculate(histogram, totalPixels);

    // 3. �ȼ� �� ����
    vector<int> equalizedMap(256, 0);
    for (int i = 0; i < 256; i++) {
        equalizedMap[i] = static_cast<int>(255.0 * (cdf[i] - cdf[0]) / (totalPixels - cdf[0])); // ��ȯ �Լ� ����
        if (equalizedMap[i] < 0) equalizedMap[i] = 0;   // ���� ó��
        if (equalizedMap[i] > 255) equalizedMap[i] = 255; // ���� ó��
    }

    // 4. ���� �̹����� ��Ȱȭ�� ���� ������ ���ο� �̹��� ����
    Mat dst = src.clone();
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int pixelValue = src.at<uchar>(y, x);
            dst.at<uchar>(y, x) = equalizedMap[pixelValue]; // ��Ȱȭ�� �ȼ� ������ ����
        }
    }
    return dst;
}*/


int main() {
    Mat img_in;

    img_in = imread("Lena.png");
    cvtColor(img_in, img_in, COLOR_RGB2GRAY);
    // Step 1: lena1 (s = r / 2), lena2 (s = 128 + r / 2) �̹��� ����
    Mat lena1, lena2;
    transform1(img_in, lena1);
    transform2(img_in, lena2);
    
    // Step 2: ������׷� ��Ȱȭ ����(�Լ��� ���� �Ͽ�����, ����� ���� ���� ����)
    /*
    img_in = applyHistogramEqualization(img_in);
    lena1 = applyHistogramEqualization(lena1);
    lena2 = applyHistogramEqualization(lena2);
    */
    imshow("Original Lena", img_in);
    imshow("Lena1 (s = r / 2)", lena1);
    imshow("Lena2 (s = 128 + r / 2)", lena2);
    // Ű �Է� ���
    waitKey(0);

    return 0;
}
