#include "compat/ptr.h"
extern "C" char DAT_0042d1b0[];
class TextureFontLoader {
  public:
    hulk_intptr a;
    int m4;
    int m8;
    int mc;
    int m10;
    TextureFontLoader();
};
TextureFontLoader::TextureFontLoader() {
    m4 = 0;
    m8 = 0x22000;
    mc = 0;
    m10 = 0;
    this->a = ((hulk_intptr)DAT_0042d1b0);
}