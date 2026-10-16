// STATUS: equivalent (tools/equiv.py level 3: 722 inputs, branch coverage 19/22, incomplete)
// CGlowDisplayEffect::vfunc_0 @ 0x000df110
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
extern "C" double cos(double);
extern "C" double sin(double);

struct Vec3_df110 {
    float x, y, z;
};

class Target1 {
public:
    virtual void v00();
    virtual void v04(unsigned int color);
    virtual void v08(unsigned int *color);
    virtual float v0c();
};

class Device_df110 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c(int a);
    virtual void v40(int a);
};

struct Holder_df110 {
    Device_df110 *device;
    void FUN_00293d00(Vec3_df110 *v);
};

class Gfx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8(int a);
    virtual char vec();
};


struct Entry_df110 {
    float a, b;
    int level;
};

class CDisplayEffect {
public:
    virtual void vfunc_0(Target1 *t);
};

class CGlowDisplayEffect : public CDisplayEffect {
public:
    int kind;
    int axis;
    float amount;
    unsigned char c0, c1, c2, c3;
    float f14;
    float f18;
    virtual void vfunc_0(Target1 *t);
};

void CGlowDisplayEffect::vfunc_0(Target1 *t)
{
    Vec3_df110 V;
    V.x = 0.0f;
    V.y = 0.0f;
    V.z = 0.0f;
    float sign = 1.0f;
    float *slotB;
    float *slotA;
    if (axis == 1) {
        slotB = &V.z;
        slotA = &V.y;
        sign = -1.0f;
    } else if (axis == 2) {
        slotB = &V.z;
        slotA = &V.y;
    } else {
        slotB = &V.y;
        slotA = &V.z;
    }
    union {
        char b;
        int w;
    } saved;
    saved.b = DAT_0052c2a8->vec();
    DAT_0052c2a8->ve8(0);
    *slotA = sign * 0.01f;
    (*(Holder_df110**)&DAT_0052c2ac)->device->v3c(0);
    (*(Holder_df110**)&DAT_0052c2ac)->FUN_00293d00(&V);
    *slotA = 0.0f;

    unsigned int origColor;
    t->v08(&origColor);
    double s = 0.0;
    if (kind == 0)
        s = (double)t->v0c() * amount;
    else if (kind == 1)
        s = amount;
    float h = (float)(0.70710677f * s);
    if (!((*(unsigned int*)((char*)&DAT_004de8d0 + 116)) & 1)) {
        (*(unsigned int*)((char*)&DAT_004de8d0 + 116)) |= 1;
        double c = cos(0.39269909262657166);
        (*(float*)((char*)&DAT_004de8d0 + 112)) = (float)(c + c);
    }
    if (!((*(unsigned int*)((char*)&DAT_004de8d0 + 116)) & 2)) {
        (*(unsigned int*)((char*)&DAT_004de8d0 + 116)) |= 2;
        double c = sin(0.39269909262657166);
        (*(float*)((char*)&DAT_004de8d0 + 108)) = (float)(c + c);
    }
    float cs = (float)((*(float*)((char*)&DAT_004de8d0 + 112)) * s);
    float ss = (float)((*(float*)((char*)&DAT_004de8d0 + 108)) * s);
    float fs = (float)s;

    Entry_df110 e[24];
    e[0].a = h;   e[0].b = h;   e[0].level = 1;
    e[1].a = -h;  e[1].b = h;   e[1].level = 1;
    e[2].a = -h;  e[2].b = -h;  e[2].level = 1;
    e[3].a = h;   e[3].b = -h;  e[3].level = 1;
    e[4].a = fs;  e[4].b = 0.0f; e[4].level = 1;
    e[5].a = -fs; e[5].b = 0.0f; e[5].level = 1;
    e[6].a = 0.0f; e[6].b = -fs; e[6].level = 1;
    e[7].a = 0.0f; e[7].b = fs;  e[7].level = 1;
    float h2 = h + h;
    float hm2 = h * -2.0f;
    e[8].a = h2;   e[8].b = h2;   e[8].level = 2;
    e[9].a = hm2;  e[9].b = h2;   e[9].level = 2;
    e[10].a = hm2; e[10].b = hm2; e[10].level = 2;
    e[11].a = h2;  e[11].b = hm2; e[11].level = 2;
    float s2 = (float)(s + s);
    float sm2 = (float)(s * -2.0f);
    e[12].a = s2;   e[12].b = 0.0f; e[12].level = 2;
    e[13].a = sm2;  e[13].b = 0.0f; e[13].level = 2;
    e[14].a = 0.0f; e[14].b = sm2;  e[14].level = 2;
    e[15].a = 0.0f; e[15].b = s2;   e[15].level = 2;
    e[16].a = -cs; e[16].b = ss;  e[16].level = 2;
    e[17].a = -ss; e[17].b = cs;  e[17].level = 2;
    e[18].a = cs;  e[18].b = ss;  e[18].level = 2;
    e[19].a = ss;  e[19].b = cs;  e[19].level = 2;
    e[20].a = cs;  e[20].b = -ss; e[20].level = 2;
    e[21].a = ss;  e[21].b = -cs; e[21].level = 2;
    e[22].a = -cs; e[22].b = -ss; e[22].level = 2;
    e[23].a = -ss; e[23].b = -cs; e[23].level = 2;

    for (int i = 0; i < 24; i++) {
        (*(Holder_df110**)&DAT_0052c2ac)->device->v3c(0);
        V.x = e[i].a;
        *slotB = e[i].b;
        (*(Holder_df110**)&DAT_0052c2ac)->FUN_00293d00(&V);

        int n = e[i].level - 1;
        unsigned int k = n < 0 ? -n : n;
        double pw = 1.0;
        double base = f18;
        while (k != 0) {
            if (k & 1)
                pw = pw * base;
            k >>= 1;
            if (k != 0)
                base = base * base;
        }
        if (n < 0)
            pw = 1.0 / pw;
        int alpha = (int)((double)(int)(origColor >> 24) * (int)c3 * pw * f14 * 0.0039215688f);
        unsigned int color = ((((((unsigned int)alpha << 8) | c2) << 8) | c1) << 8) | c0;
        t->v04(color);
        t->v00();
        (*(Holder_df110**)&DAT_0052c2ac)->device->v40(0);
    }
    (*(Holder_df110**)&DAT_0052c2ac)->device->v40(0);
    DAT_0052c2a8->ve8(saved.w);
    t->v04(origColor);
}
