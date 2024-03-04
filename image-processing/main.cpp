#include <iostream>
#include "image.h"

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
            << "\tscaLe\n"
            << "\tSave\n"
            << "\tsaveAs\n"
            << "\teXit\n";

        char option = img.display();
        std::string filename;

        switch (option) {
            case 'g': img.convert2GrayScale(); break;
            case 'b': img.blur(); break;
            case 'h': img.sharpen(); break;
            case 'j': img.adjustContrastAndBrightness(); break;
            case 'f': img.addFXColor(); break;
            case 'c': img.crop(); break;
            case 'r': img.resize(); break;
            case 'l': img.scale(); break;
            case 's': img.save(); break;
            case 'a':
                do {
                    std::cout << "New Filename (with path): ";
                    std::getline(std::cin, filename);
                } while (!img.saveAs(filename));
                break;
            case 'x': return 0;
            default: std::cout << "Invalid option\n";
        }
    } while (true);
    
}