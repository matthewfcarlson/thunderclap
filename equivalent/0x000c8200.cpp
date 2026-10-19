// STATUS: equivalent (tools/equiv.py level 3: 11572 inputs, branch coverage 6/6)
// FUN_000c8200 @ 0x000c8200
// cl-flags: /GS
#include "decls/address.h"

struct Vec3 { float x, y, z; };

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const Vec3 *pos);
    void FUN_0022bc20(float x, float y, float z);
};

struct Key {
    unsigned int lo, hi;
    Key *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Id64 {
    unsigned int lo, hi;
    void FUN_0027af70(unsigned int *src);
};

struct Markers {
    char pad0[0xc];
};

struct Mgr {
    int FUN_001dd330(Key *b, Key *a, Matrix *m, int p0, int p1, int p2, int p3);
    void FUN_001dc2d0(int id, int a0);
    void FUN_001dc230(int id, int mode);
};

struct World {
    char pad0[0xc];
    Mgr *mgr;
};

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct MarkerSlot {
    int f00;
    float f04, f08, f0c;
    Id64 f10;
    float f18, f1c, f20, f24, f28, f2c;
    int f30;
    int f34;
};

class Obj_c8200 {
public:
    char pad0[0x2258];
    MarkerSlot slots[32];
    int FUN_000c8200(int a0, unsigned int *a1, float a2, float a3, float a4,
                     float a5, float a6, float a7, float a8, float a9, float a10);
};

int Obj_c8200::FUN_000c8200(int a0, unsigned int *a1, float a2, float a3, float a4,
                            float a5, float a6, float a7, float a8, float a9, float a10)
{
    struct Frame {
        Vec3 tmp;
        Key keyB;
        Key keyA;
        Matrix m;
        char name[0x40];
    } f;
    int r = -1;
    int i;
    for (i = 0; i < 32; i++) {
        if (slots[i].f00 != 0)
            continue;
        MarkerSlot *s = &slots[i];
        FUN_000964a0(f.name, 0x40, "%s_%d_%d", "markerObjective_markerObjective", -1, i);
        f.tmp.x = a5 + a2;
        f.tmp.y = a6 + a3;
        f.tmp.z = a7 + a4;
        f.m.FUN_0022b980();
        f.m.FUN_0022be40(&f.tmp);
        f.m.FUN_0022bc20(a8 * 0.0174532924f, a9 * 0.0174532924f, a10 * 0.0174532924f);
        Mgr *mgr = DAT_004dd700->mgr;
        s->f30 = mgr->FUN_001dd330(f.keyB.FUN_0027b0e0(f.name),
                                   f.keyA.FUN_0027b0e0("markerObjective_markerObjective"),
                                   &f.m, 0, 0, 0, 0);
        f.keyB.FUN_0027af50();
        f.keyA.FUN_0027af50();
        if (s->f30 == -1)
            break;
        mgr->FUN_001dc2d0(s->f30, a0);
        mgr->FUN_001dc230(s->f30, 3);
        s->f00 = a0;
        s->f10.FUN_0027af70(a1);
        s->f04 = a2;
        s->f08 = a3;
        s->f0c = a4;
        s->f18 = a5;
        s->f1c = a6;
        s->f20 = a7;
        s->f24 = a8;
        s->f28 = a9;
        s->f2c = a10;
        s->f34 = -1;
        r = i;
        break;
    }
    return r;
}
