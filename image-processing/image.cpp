#include <filesystem>
#include "image.h"
#include "helper.h"

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

void image::blur(int d, int sigma) {
    cv::GaussianBlur(this->imageMat, this->imageMat, cv::Size(d, d), sigma, sigma);
}

void image::sharpen(void) {
    cv::Mat kernel = (cv::Mat_<double>(3, 3) <<  0, -1,  0,
                                                -1,  5, -1,
                                                 0, -1,  0);
    cv::filter2D(this->imageMat, this->imageMat, -1, kernel);
}

void image::adjustContrastAndBrightness(void) {
    cv::destroyWindow(this->filename);
    helper::adjustHelper(this->imageMat, this->filename);
    cv::namedWindow(this->filename, cv::WINDOW_AUTOSIZE);
}

void image::addFXColor(cv::ColormapTypes colorEffect) {
    cv::applyColorMap(this->imageMat, this->imageMat, colorEffect);
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

void image::resize(int toWidth, int toHeight) {
    cv::resize(this->imageMat, this->imageMat, cv::Size(toWidth, toHeight));
}

void image::scale(double scaleX, double scaleY) {
    cv::resize(this->imageMat, this->imageMat, cv::Size(), scaleX, scaleY);
}

void image::scale(double scaleXY) {
    scale(scaleXY, scaleXY);
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
