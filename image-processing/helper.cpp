#include "helper.h"

void helper::onAlphaBetaTrack(int, void*) {
    src.convertTo(dst, -1, alpha / 100.0, beta - 100);
    res = dst.clone();
    cv::imshow(winName, dst);
}

void helper::onGammaTrack(int, void*) {

    cv::Mat lookup(1, 256, CV_8U);
    uchar* p = lookup.ptr();

    for (int i = 0; i < 256; i++) {
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma / 100.0) * 255.0);
    }
    
    cv::LUT(res, lookup, dst);
    cv::imshow(winName, dst);
}

void helper::onBlurTrack(int, void *) {
    int diameter = 6 * sigma + 1;
    cv::GaussianBlur(src, dst, cv::Size(diameter, diameter), sigma, sigma);
    cv::imshow(winName, dst);
}

void helper::adjustHelper(cv::Mat& src_, std::string filename) {
    src = src_.clone();
    winName = "[Adjust Contrast and Brightness] " + filename;
    alpha = beta = gamma = 100;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);

    cv::createTrackbar("Contrast", winName, &alpha, 500, onAlphaBetaTrack);
    cv::createTrackbar("Brightness", winName, &beta, 200, onAlphaBetaTrack);
    cv::createTrackbar("Correction", winName, &gamma, 200, onGammaTrack);

    onAlphaBetaTrack(0, 0);
    onGammaTrack(0, 0);
    
    char key = cv::waitKey(0);

    if (key == 'p') {
        src_ = dst.clone();
    }
    cv::destroyWindow(winName);
}

void helper::blurHelper(cv::Mat& src_, std::string filename) {
    src = src_.clone();
    winName = "[Blur] " + filename;
    sigma = 0;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);

    cv::createTrackbar("Blur", winName, &sigma, 10, onBlurTrack);

    onBlurTrack(0, 0);

    char key = cv::waitKey(0);

    if (key == 'p') {
        src_ = dst.clone();
    }
    cv::destroyWindow(winName);
}
