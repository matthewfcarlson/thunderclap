#include "compat/ptr.h"
extern "C" char DAT_0040bf00[];
class CGlowDisplayEffect {
  public:
    hulk_uintptr vptr;
    int a;
    int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int g;
    CGlowDisplayEffect();
};
CGlowDisplayEffect::CGlowDisplayEffect() {
    a = 0;
    b = 0;
    vptr = ((hulk_intptr)DAT_0040bf00);
    c = 0x3dcccccd;
    d = 0x7f00de19;
    e = 0x3f800000;
    g = 0x3e79db23;
}