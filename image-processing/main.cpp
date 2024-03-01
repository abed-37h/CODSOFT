#include "utilities.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "You have to specify the image path";
        return -1;
    }
    
    image img;
    if (!img.load(argv[1])) {
        std::cout << "Invalid path: " << argv[1] << '\n';
        return -1;
    }

    do {
        system("clear");

        std::cout << "Options:\n"
            << "\tGrayscale\n"
            << "\tBlur\n"
            << "\tsHarpen\n"
            << "\tadJust contrast and brightness\n"
            << "\tadd Fx colors\n"
            << "\tCrop\n"
            << "\tResize\n"
            << "\tscaLe (similar)\n"
            << "\tscalE (separately)\n"
            << "\tSave\n"
            << "\tsaveAs\n"
            << "\teXit\n";

        char option = img.display();

        switch (option) {
            case 'g': img.convert2GrayScale(); break;
            case 'b': blur(img); break;
            case 'h': img.sharpen(); break;
            case 'j': adjustContrastAndBrightness(img); break;
            case 'f': fxColor(img); break;
            case 'c': crop(img); break;
            case 'r': resize(img); break;
            case 'l': scale(img, true); break;
            case 'e': scale(img, false); break;
            case 's': img.save(); break;
            case 'a': saveAs(img); break;
            case 'x': return 0;
            default: std::cout << "Invalid option\n";
        }
    } while (true);
    
}