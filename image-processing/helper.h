#ifndef HELPER
#define HELPER

#include <opencv2/opencv.hpp>
#include <string>

namespace helper {
    void onAlphaBetaTrack(int, void*);
    void onGammaTrack(int, void*);
    void adjustHelper(cv::Mat& src_, std::string filename);
    
    static std::string winName = "";
    static cv::Mat src, dst, res;
    static int alpha = 100, beta = 100, gamma = 100;
}

#endif