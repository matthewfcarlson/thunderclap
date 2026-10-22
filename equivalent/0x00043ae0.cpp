// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 46/48, incomplete)
// FUN_00043ae0 @ 0x00043ae0
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" double __cdecl sqrt(double);

class RefObj_43ae0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct V3_43ae0 {
    float x, y, z;
    float FUN_00018990();
    float FUN_0022d110();
    void FUN_000344b0(float v);
};

struct Request {
    int e0;                          // 0x00
    int e4;                          // 0x04
    V3_43ae0 target;                       // 0x08
    char pad14[4];
    V3_43ae0 aim;                          // 0x18
    char b24;                        // 0x24
    char pad25[3];
    V3_43ae0 vec28;                        // 0x28
    char pad34[0x4c - 0x34];
    RefObj_43ae0 *p4c;                     // 0x4c
    RefObj_43ae0 *p50;                     // 0x50
    int r54;                         // 0x54
    float f58;                       // 0x58
    float f5c;                       // 0x5c
    RefObj_43ae0 *p60;                     // 0x60
    float f64;                       // 0x64
    float f68;                       // 0x68
    char pad6c[8];
    int mode;                        // 0x74
    float val;                       // 0x78
    char pad7c[4];
    float one;                       // 0x80
    char pad84[0x90 - 0x84];
    char b90;                        // 0x90
    char pad91[7];
    Request *FUN_00059820();
    void FUN_00059300();
};

struct Entry_43ae0 {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
};

struct Params {
    float g0[7];
    float g1c;
    float g20;
    float g24;
};


struct CCharacter_43ae0 {
    char pad00[0x14];
    int f14;
    unsigned __int64 FUN_000443c0();
};

struct Obj_43ae0 {
    char pad00[8];
    int f8;
    int fc;
    char pad10[0x110 - 0x10];
    float f110;
    int f114;
    char pad118[4];
    CCharacter_43ae0 *f11c;
    char pad120[0x12c - 0x120];
    RefObj_43ae0 *f12c;
    char FUN_00043350(float dt, RefObj_43ae0 *r, int a, int b, int c, int d);
    void FUN_000350c0(V3_43ae0 *out);
    void FUN_000352b0(V3_43ae0 *out);
    char FUN_000437a0(float dt, Request *r, int a, int b, int c);
    void FUN_00043ae0(RefObj_43ae0 *a1, V3_43ae0 *p, float dt, int a4, float a5, int a6, int a7, char a8, RefObj_43ae0 *a9);
};

void Obj_43ae0::FUN_00043ae0(RefObj_43ae0 *a1, V3_43ae0 *p, float dt, int a4, float a5, int a6, int a7, char a8, RefObj_43ae0 *a9)
{
    struct Frame {
        float s;                     // 0x00
        V3_43ae0 d;                        // 0x04
        V3_43ae0 e;                        // 0x10
        V3_43ae0 a;                        // 0x1c
        Request x;                   // 0x28
    } f;

    if (dt <= 0.0f)
        return;
    if (f110 > 0.0f || f114 > 0) {
        FUN_00043350(a5, a1, 0, 0, 0, 0);
        return;
    }

    f.x.FUN_00059820();
    int idx = f11c->f14;
    if (f12c != 0) {
        f.a.x = 0.0f;
        f.a.y = 0.0f;
        f.a.z = 0.0f;
        FUN_000350c0(&f.a);
        f.d.x = f.a.x - p->x;
        f.d.y = f.a.y - p->y;
        f.d.z = f.a.z - p->z;
        if (sqrt(f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x) < 0.001f) {
            f.d.x = 0.0f;
            f.d.y = 1.0f;
            f.d.z = 0.0f;
        }
        f.e = f.d;
        f.e.FUN_0022d110();

        Entry_43ae0 *t = &((Entry_43ae0*)&DAT_004dc360)[idx];
        if (t->f0 <= 0.0f) {
            f.s = 0.0f;
        } else {
            f.s = dt / t->f0;
            if (f.s > 1.0f)
                f.s = 1.0f;
        }

        f.x.e0 = a6;
        f.x.e4 = a7;
        if (a1 != 0)
            a1->AddRef();
        if (f.x.p4c != 0)
            f.x.p4c->Release();
        f.x.p4c = a1;
        RefObj_43ae0 *owner = f12c;
        if (owner != 0)
            owner->AddRef();
        if (f.x.p50 != 0)
            f.x.p50->Release();
        f.x.p50 = owner;
        f.x.mode = 2;
        FUN_000352b0(&f.x.target);

        f.x.f58 = f.s * t->f8;
        f.x.aim = f.e;
        f.x.r54 = a4;
        f.x.val = a5;
        Params *g = (*(Params**)&DAT_00554c10);
        f.x.b90 = a8;
        f.x.one = 1.0f;
        f.x.f64 = (float)sqrt(g->g1c * g->g1c + g->g20 * g->g20 + g->g24 * g->g24);
        f.x.f5c = f.s * t->f10;
        if (a9 != 0)
            a9->AddRef();
        if (f.x.p60 != 0)
            f.x.p60->Release();
        f.x.p60 = a9;
        if (f.s < 0.15f || !(f.s < 25.0f))
            f.x.f68 = 0.0f;
        else
            f.x.f68 = f.s * t->f14;

        if (f.s < 0.25f) {
            f.x.b24 = 0;
        } else {
            f.x.b24 = 1;
            f.x.vec28.y = 0.0f;
            if (f.s < 0.5f) {
                f.x.vec28.x = 0.0f;
                f.x.vec28.z = 0.0f;
            } else {
                if (f.s < 0.75) {
                    f.x.vec28.x = f.e.x;
                    f.x.vec28.z = f.e.z;
                    if (f8 == (*(int*)&DAT_004dc0e0) && fc == (*(int*)((char*)&DAT_004dc0e0 + 4)))
                        f.x.vec28.FUN_000344b0(f.s * t->f4 * 0.5f);
                    else
                        f.x.vec28.FUN_000344b0(f.s * t->f4);
                } else {
                    f.x.vec28.x = f.d.x;
                    f.x.vec28.z = f.d.z;
                    f.x.vec28.y = f.x.vec28.FUN_00018990() * f.s;
                    f.x.vec28.FUN_0022d110();
                    f.x.vec28.FUN_000344b0(f.s * t->f4);
                }
            }
        }

        unsigned __int64 key = f11c->FUN_000443c0();
        if ((unsigned int)key == DAT_004dc080 && (unsigned int)(key >> 32) == DAT_004dc084 && f.x.b90 != 0)
            a5 = 0.0f;
        FUN_000437a0(a5, &f.x, 0, 0, 0);
    }
    f.x.FUN_00059300();
}
