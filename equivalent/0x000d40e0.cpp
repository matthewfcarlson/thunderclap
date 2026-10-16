// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 8/8)
// FUN_000d40e0 @ 0x000d40e0
#include "decls/data/game/global.h"

extern int DAT_004a0704[];

struct V3_d40e0 {
    float x, y, z;
};

struct Source_d40e0 {
    char pad0[0x34];
    int value;
};

struct Mode_d40e0 {
    char pad0[0x10c];
    int kind;
};

struct Camera {
    char pad0[0x2c];
    void *rig;
    float FUN_000d6d90(void *owner);
};

float __cdecl FUN_000f6a70(void *rig, V3_d40e0 *v, Mode_d40e0 *mode);

struct Item_d40e0 {
    short w0;
    char pad02[0xfe];
    int v100;
    float f104;
    int v108;
};

class Screen_d40e0 {
public:
    char pad0[4];
    bool f4;
    char pad5[3];
    Source_d40e0 *source;
    Mode_d40e0 *mode;
    int f10;
    char pad14[0x248 - 0x14];
    bool flagA;
    char pad249[0x484 - 0x249];
    bool flagB;
    char pad485[7];
    Item_d40e0 items[3];
    char pad7b0[4];
    float f7b4;
    int f7b8;
    bool f7bc;
    char pad7bd[7];
    bool f7c4;
    char pad7c5[3];
    int f7c8;
    int f7cc;
    float f7d0;
    char pad7d4[0x804 - 0x7d4];
    int f804;
    float f808;
    bool f80c;

    void FUN_000d40e0(Source_d40e0 *src, Mode_d40e0 *m, Camera *cam);
};

void Screen_d40e0::FUN_000d40e0(Source_d40e0 *src, Mode_d40e0 *m, Camera *cam)
{
    V3_d40e0 v;
    source = src;
    mode = m;
    v.x = DAT_004de600 * -0.5f;
    v.y = DAT_004de604 * 0.5f;
    v.z = 0;
    f7b4 = FUN_000f6a70(cam->rig, &v, m);
    DAT_004ddf98 = 0;
    f808 = DAT_004a06c0 * (mode->kind == 3 ? DAT_004a06c4 : DAT_004a06c8);
    v.x = DAT_004de600;
    v.y = DAT_004de604;
    double aExt = DAT_004de600 * -0.5f;
    volatile float aF = (float)aExt;
    DAT_004ddfc8 = 0;
    double bExt = DAT_004de604 * -0.5f;
    volatile float t1 = (float)(v.y * 0.12f);
    (*(float*)&DAT_004ddfc0) = (float)(v.x * 0.6f + aExt);
    DAT_004ddfc4 = (float)(t1 + bExt);
    if (mode->kind == 3) {
        DAT_004ddfc4 = -8.08f;
        DAT_004a06d0 = 0.183f;
    }
    DAT_004ddfd4 = 0;
    double b2Ext = DAT_004de604 * 0.5f;
    DAT_004ddfe0 = 0;
    DAT_004ddfec = 0;
    volatile float b2F = (float)b2Ext;
    double cExt = v.x * -0.05f;
    double dExt = v.y * 0.25f;
    (*(float*)&DAT_004ddfcc) = (float)(aF - cExt);
    DAT_004ddfd0 = (float)(b2F - dExt);
    volatile float e = (float)(v.y * 0.31f);
    DAT_004ddfd8 = (float)(aF - cExt);
    DAT_004ddfdc = (float)(b2Ext - e);
    double fExt = v.y * 0.41f;
    DAT_004ddfe4 = (float)(aF - cExt);
    DAT_004ddfe8 = (float)(b2F - fExt);
    int j = 0;
    const int *p;
    for (p = DAT_004a06f8; p < DAT_004a0704; p++) {
        items[j].w0 = 0;
        items[j].v100 = *p;
        items[j].f104 = 1000.0f;
        items[j].v108 = 0;
        j++;
    }
    f7b8 = 0;
    f4 = true;
    f7bc = false;
    f7c4 = false;
    f10 = source->value;
    flagA = false;
    flagB = false;
    cam->FUN_000d6d90(this);
    f7c8 = 0;
    f7cc = 0;
    f804 = 0;
    f7d0 = (*(float*)&DAT_004a06b0);
    f80c = true;
}
