#include "compat/ptr.h"
extern int gVtable_2c14c0;
class LightGroupLoader {
  public:
    int vf;
    int a;
    int b;
    int c;
    int d;
    LightGroupLoader();
};
LightGroupLoader::LightGroupLoader() {
    a = 0;
    b = 0x2380;
    c = 0;
    d = 0;
    vf = (hulk_intptr)&gVtable_2c14c0;
}