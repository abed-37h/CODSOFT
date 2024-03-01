#include <iostream>
#include "image.h"

void blur(image& img);
void adjustContrastAndBrightness(image& img);
void fxColor(image& img);
void crop(image& img);
void resize(image& img);
void scale(image& img, bool both);
void saveAs(image& img);