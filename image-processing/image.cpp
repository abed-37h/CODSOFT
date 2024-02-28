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

void image::display(void) const {
    cv::imshow(this->filename, this->imageMat);
    cv::waitKey(0);
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

void image::save(void) {
    cv::imwrite(this->filename, this->imageMat);
}

bool image::saveAs(std::string filename) {
    if (std::filesystem::exists(filename) || !cv::imwrite(filename, this->imageMat)) return false;
    this->filename = filename;

    return true;
}
