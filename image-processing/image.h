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
    void save(void);
    bool saveAs(std::string filename);

private:
    cv::Mat imageMat;
    std::string filename;
};

#endif