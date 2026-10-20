#include "compat/ptr.h"
extern "C" char DAT_0042ea08[];
class ImageFontLoader {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    int d;
    ImageFontLoader();
};
ImageFontLoader::ImageFontLoader() {
    a = 0;
    b = 0x22002;
    c = 0;
    d = 0;
    vf = ((hulk_intptr)DAT_0042ea08);
}