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

void image::save(void) {
    cv::imwrite(this->filename, this->imageMat);
}

bool image::saveAs(std::string filename) {
    if (std::filesystem::exists(filename) || !cv::imwrite(filename, this->imageMat)) return false;
    this->filename = filename;

    return true;
}
