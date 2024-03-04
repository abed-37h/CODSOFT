#ifndef HELPER
#define HELPER

#include <opencv2/opencv.hpp>
#include <string>
#include <unordered_map>

namespace helper {
    void onAlphaBetaTrack(int, void*);
    void onGammaTrack(int, void*);
    void onBlurTrack(int, void*);
    void onScaleTrack(int, void*);
    void onResizeTrack(int, void*);
    void onColorFXTrack(int, void*);
    
    void adjustHelper(cv::Mat& src_, std::string filename);
    void blurHelper(cv::Mat& src_, std::string filename);
    void scaleHelper(cv::Mat& src_, std::string filename);
    void resizeHelper(cv::Mat& src_, std::string filename);
    void colorFXHelper(cv::Mat& src_, std::string filename);
    
    static std::string winName = "";
    static cv::Mat src, dst, res;

    static int alpha = 100, beta = 100, gamma = 100;
    static int sigma;
    static int scale;
    static int width, height;
    static int colorEffect;
    
    const std::unordered_map<int, std::string> colorMap = {
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
}

#endif