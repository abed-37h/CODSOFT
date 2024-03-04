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

void helper::onBlurTrack(int, void*) {
    int diameter = 6 * sigma + 1;
    cv::GaussianBlur(src, dst, cv::Size(diameter, diameter), sigma, sigma);
    cv::imshow(winName, dst);
}

void helper::onScaleTrack(int, void*) {
    cv::resize(src, dst, cv::Size(), scale / 100.0, scale / 100.0);
    cv::imshow(winName, dst);
}

void helper::onResizeTrack(int, void*) {
    cv::resize(src, dst, cv::Size(width, height));
    cv::imshow(winName, dst);
}

void helper::onColorFXTrack(int, void*) {
    if (colorEffect == 0) dst = src.clone();
    else cv::applyColorMap(src, dst, static_cast<cv::ColormapTypes>(colorEffect - 1));
    res = dst.clone();
    cv::putText(res, colorMap.at(colorEffect), cv::Point(src.rows / 2.5, src.cols / 2), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 0, 0), 2);
    cv::imshow(winName, res);
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

void helper::scaleHelper(cv::Mat& src_, std::string filename) {
    src = src_.clone();
    winName = "[Scale] " + filename;
    scale = 100;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::resizeWindow(winName, cv::Size(2 * src.cols, 2 * src.rows));

    cv::createTrackbar("Scale (in %)", winName, &scale, 200, onScaleTrack);

    onScaleTrack(100, 0);

    char key = cv::waitKey(0);

    if (key == 'p') {
        src_ = dst.clone();
    }
    cv::destroyWindow(winName);
}

void helper::resizeHelper(cv::Mat& src_, std::string filename) {
    src = src_.clone();
    winName = "[Resize] " + filename;
    width = src.cols;
    height = src.rows;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::resizeWindow(winName, cv::Size(2 * src.cols, 2 * src.rows));

    cv::createTrackbar("New Width", winName, &width, 1000, onResizeTrack);
    cv::createTrackbar("New Height", winName, &height, 1000, onResizeTrack);

    onResizeTrack(src.cols, 0);
    onResizeTrack(src.rows, 0);

    char key = cv::waitKey(0);

    if (key == 'p') {
        src_ = dst.clone();
    }
    cv::destroyWindow(winName);
}

void helper::colorFXHelper(cv::Mat& src_, std::string filename) {
    src = src_.clone();
    winName = "[Add Color Fx] " + filename;
    colorEffect = 0;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);

    cv::createTrackbar("Color FX", winName, &colorEffect, 22, onColorFXTrack);

    onColorFXTrack(0, 0);

    char key = cv::waitKey(0);

    if (key == 'p') {
        src_ = dst.clone();
    }
    cv::destroyWindow(winName);
}
