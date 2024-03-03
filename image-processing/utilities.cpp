#include "utilities.h"

void blur(image& img) {
    int d, sigma;

    std::cout << "Diameter: ";
    std::cin >> d;

    std::cout << "Sigma: ";
    std::cin >> sigma;

    if (sigma < 1) {
        img.blur(d);
    }
    else {
        img.blur(d, sigma);
    }
}

void fxColor(image& img) {
    std::cout << "FX Options: \n"
        << "\t01: Autumn\n"
        << "\t02: Bone\n"
        << "\t03: Jet\n"
        << "\t04: Winter\n"
        << "\t05: Rainbow\n"
        << "\t06: Ocean\n"
        << "\t07: Summer\n"
        << "\t08: Spring\n"
        << "\t09: Cool\n"
        << "\t10: HSV\n"
        << "\t11: Pink\n"
        << "\t12: Hot\n"
        << "\t13: Parula\n"
        << "\t14: Magma\n"
        << "\t15: Inferno\n"
        << "\t16: Plasma\n"
        << "\t17: Viridis\n"
        << "\t18: Cividis\n"
        << "\t19: Twilight\n"
        << "\t20: Twilight_Shifted\n"
        << "\t21: Turbo\n"
        << "\t22: Deep_Green\n";

    int colorEffect;
    std::cout << "Color Effect: ";
    std::cin >> colorEffect;

    img.addFXColor(static_cast<cv::ColormapTypes>(colorEffect - 1));
}

void resize(image& img) {
    int newWidth, newHeight;

    std::cout << "New Width: ";
    std::cin >> newWidth;
    
    std::cout << "New Height: ";
    std::cin >> newHeight;

    img.resize(newWidth, newHeight);
}

void scale(image& img, bool both) {
    if (both) {
        double scaleXY;
        std::cout << "Scale: ";
        std::cin >> scaleXY;

        img.scale(scaleXY);
    }

    else {
        double scaleX, scaleY;

        std::cout << "Scale X: ";
        std::cin >> scaleX;

        std::cout << "Scale Y: ";
        std::cin >> scaleY;

        img.scale(scaleX, scaleY);
    }
}

void saveAs(image& img) {
    std::string filename;

    do {
        std::cout << "New Filename (with path): ";
        std::getline(std::cin, filename);
    } while (!img.saveAs(filename));
    
}

