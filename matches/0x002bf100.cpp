#include "compat/ptr.h"
extern "C" char DAT_0042e9bc[];
typedef unsigned int u32_2bf100;
struct Ctor_0027b070 {
    Ctor_0027b070();
};
struct ImageFont : public Ctor_0027b070 {
    volatile u32_2bf100 vt;
    char pad[12];
    volatile u32_2bf100 a, b, c, d, e;
    volatile int f;
    volatile u32_2bf100 g, h, i, j;
    ImageFont();
};
ImageFont::ImageFont() : Ctor_0027b070() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    vt = ((hulk_intptr)DAT_0042e9bc);
    f = -1;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
}
