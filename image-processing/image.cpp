#include <filesystem>
#include "image.h"

image::image(void) = default;

image::image(std::string filename) {
    load(filename);
}

bool image::load(std::string filename) {
    this->imageMat = cv::imread(filename);
    if (imageMat.empty()) return false;
    this->filename = filename;
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

void image::adjustContrast(double alpha) {
    adjustContrastAndBrightness(alpha, 0);
}

void image::adjustBrightness(int beta) {
    adjustContrastAndBrightness(1, beta);
}

void image::adjustContrastAndBrightness(double alpha, int beta, double gamma) {
    this->imageMat.convertTo(this->imageMat, -1, alpha, beta);
    if (gamma) {
        gammaCorrection(gamma);
    }
}

void image::gammaCorrection(double gamma) {
    cv::Mat lookup(1, 256, CV_8U);
    uchar* p = lookup.ptr();

    for (int i = 0; i < 256; i++) {
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
    }

    cv::LUT(this->imageMat, lookup, this->imageMat);
}

void image::addFXColor(cv::ColormapTypes colorEffect) {
    cv::applyColorMap(this->imageMat, this->imageMat, colorEffect);
}

void image::crop(int startX, int startY, int width, int height) {
    this->imageMat = this->imageMat(cv::Rect(startX, startY, width, height));
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
    this->filename = filename;

    return true;
}
