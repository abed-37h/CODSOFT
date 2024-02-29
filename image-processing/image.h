#ifndef IMAGE
#define IMAGE

#include <opencv2/opencv.hpp>
#include <string>

class image {
public:
    image(void);
    image(std::string filename);
    bool load(std::string filename);
    void display(void) const;
    void convert2GrayScale(void);
    void blur(int d, int sigma = 0);
    void sharpen(void);
    void adjustContrast(double alpha);
    void adjustBrightness(int beta);
    void adjustContrastAndBrightness(double alpha, int beta, double gamma = 0);
    void gammaCorrection(double gamma);
    void addFXColor(cv::ColormapTypes colorEffect);
    void save(void);
    bool saveAs(std::string filename);

private:
    cv::Mat imageMat;
    std::string filename;
};

#endif