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
    void blur(void);
    void sharpen(void);
    void adjustContrastAndBrightness(void);
    void addFXColor(void);
    void crop(void);
    void resize(void);
    void scale(void);
    void save(void);
    bool saveAs(std::string filename);

private:
    cv::Mat imageMat;
    std::string filename;
};

#endif