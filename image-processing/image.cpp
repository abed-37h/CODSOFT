#include <filesystem>
#include "image.h"

const int ENTER = 13;
const int SPACE = ' ';
const int ESCAPE = 27;
const int CANCEL = 'c';

std::string image::winName = "";
cv::Mat image::src = cv::Mat();
cv::Mat image::dst = cv::Mat();
cv::Mat image::res = cv::Mat();

int image::alpha = 0;
int image::beta = 0;
int image::gamma = 0;
int image::sigma = 0;
int image::scaleXY = 0;
int image::width = 0;
int image::height = 0;
int image::colorEffect = 0;

const std::unordered_map<int, std::string> image::colorMap = {
    {0, "Original"},
    {1, "Autumn"},
    {2, "Bone"},
    {3, "Jet"},
    {4, "Winter"},
    {5, "Rainbow"},
    {6, "Ocean"},
    {7, "Summer"},
    {8, "Spring"},
    {9, "Cool"},
    {10, "HSV"},
    {11, "Pink"},
    {12, "Hot"},
    {13, "Parula"},
    {14, "Magma"},
    {15, "Inferno"},
    {16, "Plasma"},
    {17, "Viridis"},
    {18, "Cividis"},
    {19, "Twilight"},
    {20, "Twilight_Shifted"},
    {21, "Turbo"},
    {22, "Deep_Green"}
};

image::image(void) = default;

image::image(std::string filename) {
    load(filename);
}

bool image::load(std::string filename) {
    this->imageMat = cv::imread(filename);
    if (imageMat.empty()) return false;
    this->filename = filename;
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
    return true;
}

char image::display(void) const {
    cv::imshow(this->filename, this->imageMat);
    return cv::waitKey(0);
}

void image::convert2GrayScale(void) {
    cv::cvtColor(this->imageMat, this->imageMat, cv::COLOR_BGR2GRAY);
}

void image::blur(void) {
    cv::destroyWindow(this->filename);
    src = this->imageMat.clone();
    winName = "[Blur] " + this->filename;
    sigma = 0;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Blur", winName, &sigma, 10, onBlurTrack);

    int key;
    do {
        onBlurTrack(0, 0);

        key = cv::waitKey(0);

        if (key == ENTER || key == SPACE) {
            this->imageMat = dst.clone();
            break;
        }
    } while (key != ESCAPE && key != CANCEL);
    
    cv::destroyWindow(winName);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::sharpen(void) {
    cv::Mat kernel = (cv::Mat_<double>(3, 3) <<  0, -1,  0,
                                                -1,  5, -1,
                                                 0, -1,  0);
    cv::filter2D(this->imageMat, this->imageMat, -1, kernel);
}

void image::adjustContrastAndBrightness(void) {
    cv::destroyWindow(this->filename);
    src = this->imageMat.clone();
    winName = "[Adjust Contrast and Brightness] " + this->filename;
    alpha = beta = gamma = 100;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Contrast", winName, &alpha, 500, onAlphaBetaTrack);
    cv::createTrackbar("Brightness", winName, &beta, 200, onAlphaBetaTrack);
    cv::createTrackbar("Correction", winName, &gamma, 200, onGammaTrack);
    
    int key;
    do {
        onAlphaBetaTrack(0, 0);
        onGammaTrack(0, 0);

        key = cv::waitKey(0);

        if (key == ENTER || key == SPACE) {
            this->imageMat = dst.clone();
            break;
        }
    } while (key != ESCAPE && key != CANCEL);

    cv::destroyWindow(winName);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::addFXColor(void) {
    cv::destroyWindow(this->filename);
    src = this->imageMat.clone();
    winName = "[Add Color Fx] " + this->filename;
    colorEffect = 0;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Color FX", winName, &colorEffect, 22, onColorFXTrack);

    int key;
    do {
        onColorFXTrack(0, 0);

        key = cv::waitKey(0);

        if (key == ENTER || key == SPACE) {
            this->imageMat = dst.clone();
            break;
        }
    } while (key != ESCAPE && key != CANCEL);
    
    cv::destroyWindow(winName);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::crop(void) {
    std::string winName = "[Crop] " + this->filename;

    cv::destroyWindow(this->filename);
    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);

    cv::Rect roi = cv::selectROI(winName, this->imageMat, false);
    if (!roi.empty()) this->imageMat = this->imageMat(roi);

    cv::destroyWindow(winName);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::resize(void) {
    cv::destroyWindow(this->filename);
    src = this->imageMat.clone();
    winName = "[Resize] " + this->filename;
    width = this->imageMat.cols;
    height = this->imageMat.rows;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::resizeWindow(winName, cv::Size(2 * src.cols, 2 * src.rows));

    cv::createTrackbar("New Width", winName, &width, 1000, onResizeTrack);
    cv::createTrackbar("New Height", winName, &height, 1000, onResizeTrack);

    int key;
    do {
        onResizeTrack(this->imageMat.cols, 0);
        onResizeTrack(this->imageMat.rows, 0);

        key = cv::waitKey(0);

        if (key == ENTER || key == SPACE) {
            this->imageMat = dst.clone();
            break;
        }
    } while (key != ESCAPE && key != CANCEL);
    
    cv::destroyWindow(winName);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::scale(void) {
    cv::destroyWindow(this->filename);
    src = this->imageMat.clone();
    winName = "[Scale] " + this->filename;
    scaleXY = 100;

    cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
    cv::resizeWindow(winName, cv::Size(2 * src.cols, 2 * src.rows));

    cv::createTrackbar("Scale (in %)", winName, &scaleXY, 200, onScaleTrack);

    int key;
    do {
        onScaleTrack(100, 0);

        key = cv::waitKey(0);

        if (key == ENTER || key == SPACE) {
            this->imageMat = dst.clone();
            break;
        }
    } while (key != ESCAPE && key != CANCEL);
    
    cv::destroyWindow(winName);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::save(void) {
    cv::imwrite(this->filename, this->imageMat);
}

bool image::saveAs(std::string filename) {
    if (std::filesystem::exists(filename) || !cv::imwrite(filename, this->imageMat)) return false;
    cv::destroyWindow(this->filename);
    this->filename = filename;
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);

    return true;
}

void image::onAlphaBetaTrack(int, void*) {
    src.convertTo(dst, -1, alpha / 100.0, beta - 100);
    res = dst.clone();
    cv::imshow(winName, dst);
}

void image::onGammaTrack(int, void*) {

    cv::Mat lookup(1, 256, CV_8U);
    uchar* p = lookup.ptr();

    for (int i = 0; i < 256; i++) {
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma / 100.0) * 255.0);
    }
    
    cv::LUT(res, lookup, dst);
    cv::imshow(winName, dst);
}

void image::onBlurTrack(int, void*) {
    int diameter = 6 * sigma + 1;
    cv::GaussianBlur(src, dst, cv::Size(diameter, diameter), sigma, sigma);
    cv::imshow(winName, dst);
}

void image::onScaleTrack(int, void*) {
    cv::resize(src, dst, cv::Size(), scaleXY / 100.0, scaleXY / 100.0);
    cv::imshow(winName, dst);
}

void image::onResizeTrack(int, void*) {
    cv::resize(src, dst, cv::Size(width, height));
    cv::imshow(winName, dst);
}

void image::onColorFXTrack(int, void*) {
    if (colorEffect == 0) dst = src.clone();
    else cv::applyColorMap(src, dst, static_cast<cv::ColormapTypes>(colorEffect - 1));
    res = dst.clone();
    cv::putText(res, colorMap.at(colorEffect), cv::Point(src.rows / 2.5, src.cols / 2), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 0, 0), 2);
    cv::imshow(winName, res);
}
