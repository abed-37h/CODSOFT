#ifndef IMAGE
#define IMAGE

#include <opencv2/opencv.hpp>
#include <string>

class image {
public:
    image(void);
    image(std::string filename);
    bool load(std::string filename);
    char display(void) const;
    void convert2GrayScale(void);
    void blur(int d, int sigma = 0);
    void sharpen(void);
    void adjustContrastAndBrightness(void);
    void addFXColor(cv::ColormapTypes colorEffect);
    void crop(int startX, int startY, int width, int height);
    void resize(int toWidth, int toHeight);
    void scale(double scaleX, double scaleY);
    void scale(double scaleXY);
    void save(void);
    bool saveAs(std::string filename);

private:
    cv::Mat imageMat;
    std::string filename;
};

#endif