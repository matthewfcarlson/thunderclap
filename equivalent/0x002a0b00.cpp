// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002a0b00 @ 0x002a0b00
#include "compat/ptr.h"
extern char DAT_0042d668[];

struct Vec3_2a0b00 { float x, y, z; };

struct Light {
    int vptr;
    char pad04[0xc];
    char b10, b11, b12, b13;
    int f14;
    Vec3_2a0b00 v18;
    int f24;
    char pad28[4];
    int f2c;
    Vec3_2a0b00 v30;
    Vec3_2a0b00 v3c;
    int f48, f4c, f50, f54;
    void FUN_0027b0b0(const Light *src);
    Light *FUN_002a0b00(const Light *src);
};

Light *Light::FUN_002a0b00(const Light *src)
{
    FUN_0027b0b0(src);
    vptr = (hulk_intptr)DAT_0042d668;
    b10 = 0;
    b11 = src->b11;
    b12 = src->b12;
    b13 = 0;
    f14 = src->f14;
    v18 = src->v18;
    f24 = -1;
    f2c = src->f2c;
    v30 = src->v30;
    v3c = src->v3c;
    f48 = src->f48;
    f4c = src->f4c;
    f50 = 0;
    f54 = src->f54;
    return this;
}
