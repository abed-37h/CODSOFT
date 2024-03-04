#ifndef IMAGE
#define IMAGE

#include <opencv2/opencv.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

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
    void onKeyPress(std::vector<std::pair<cv::TrackbarCallback, int>> callbacksV);
    static void flipWindows(std::string toDestroy, std::string toCreate);

    static void onAlphaBetaTrack(int, void*);
    static void onGammaTrack(int, void*);
    static void onBlurTrack(int, void*);
    static void onScaleTrack(int, void*);
    static void onResizeTrack(int, void*);
    static void onColorFXTrack(int, void*);
    
    static std::string winName;
    static cv::Mat src, dst, res;

    static int alpha, beta, gamma;
    static int sigma;
    static int scaleXY;
    static int width, height;
    static int colorEffect;
    
    static const std::unordered_map<int, std::string> colorMap;

private:
    cv::Mat imageMat;
    std::string filename;
};

#endif