#include "compat/ptr.h"
extern "C" char DAT_0042e634[];
class ShadowSkinLoader {
  public:
    hulk_intptr v;
    int a;
    int b;
    int c;
    int d;
    ShadowSkinLoader();
};
ShadowSkinLoader::ShadowSkinLoader() {
    a = 0;
    b = 0x10019;
    c = 0;
    d = 0;
    v = ((hulk_intptr)DAT_0042e634);
}