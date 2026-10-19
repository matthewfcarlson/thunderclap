// STATUS: equivalent (tools/equiv.py level 3: 20077 inputs, branch coverage 77/78, incomplete)
// FUN_00040970 @ 0x00040970
// cl-flags: /GS
#include "decls/address.h"

union Bits_40970 {
    float f;
    unsigned int u;
};

struct Buf_40970 {
    char data[0xb0];
    void FUN_001c9a40(unsigned int id);
};

struct Flags_40970 {
    bool FUN_00092940(int id);
};

struct Opts_40970 {
    Flags_40970 *FUN_00086340();
};

struct Sink_40970 {
    void FUN_001cbc20(Buf_40970 *b);
};

struct Hero_40970;
struct World {
    char pad00[0x20];
    struct Hero_40970 *hero;          // 0x20
    char pad24[0xc];
    Sink_40970 *sink30;               // 0x30
    char pad34[0x20];
    Opts_40970 *opts;                 // 0x54
};

struct Hero_40970 {
    bool FUN_00025d30(void *self);
};


struct Ref_40970 {
    unsigned int *id;
};

struct Obj11c_40970 {
    char pad00[0x130];
    float f130;
    float f134;
    char pad138[0x18];
    Bits_40970 f150;
    float f154;
    float f158;
    float f15c;
    char pad160[0x4c];
    float f1ac;
    void FUN_000443c0();
};

struct Sub_40970 {
    void FUN_00059790(int v);
};

struct Timer {
    unsigned int first;
    void FUN_002322f0(int a, float dt);
};

class Actor_40970 {
public:
    char pad000[0x10];
    unsigned int *f10;          // 0x10
    char pad14[0xc8];
    Timer t0dc;                 // 0xdc
    char pad0e0[0x24];
    Sub_40970 *sub104;                // 0x104
    unsigned int f108;          // 0x108
    float f10c;
    float f110;
    char pad114[4];
    char b118;                  // 0x118
    char pad119[3];
    Obj11c_40970 *o11c;               // 0x11c
    char pad120[0x1e0];
    float f300;
    float f304;
    char pad308[0xc];
    float f314;                 // 0x314
    char pad318[8];
    float f320;
    char pad324[0x10];
    int f334;
    int f338;
    char pad33c[0x50];
    float f38c;
    char pad390[0x1b0c - 0x390];
    Bits_40970 f1b0c;                 // 0x1b0c
    float f1b10;
    float f1b14;
    float f1b18;
    int f1b1c;
    char pad1b20[8];
    int f1b28;                  // 0x1b28
    float f1b2c;
    float f1b30;
    char b1b34;                 // 0x1b34
    char pad1b35[0x1e48 - 0x1b35];
    float f1e48;
    float f1e4c;
    int f1e50;
    float f1e54;
    char pad1e58[8];
    float f1e60[14];
    void FUN_00040550(float dt);
    void FUN_00040970(World *w, float dt);
};

void Actor_40970::FUN_00040970(World *w, float dt)
{
    struct Frame {
        float limit;
        Bits_40970 g;
        Bits_40970 av;
        Buf_40970 buf;
    } f;
    if (b118 != 0) {
        return;
    }
    dt = dt * f314;
    if (f110 > 0.0f) {
        double r = f110 - dt;
        f110 = r;
        if (r < 0.0)
            f110 = 0.0f;
    }
    if (f1b18 > 0.0f) {
        double r = f1b18 - dt;
        f1b18 = r;
        if (r < 0.0)
            f1b18 = 0.0f;
    }
    FUN_00040550(dt);
    sub104->FUN_00059790(0);
    f1e48 = dt + f1e48;
    f1e4c = dt + f1e4c;
    if (f1b28 != 0)
        f1b2c = dt + f1b2c;
    Obj11c_40970 *o = o11c;
    if (o != 0) {
        double v = f1b30 - dt * o->f15c;
        if (!(0.0 < v))
            v = 0.0;
        f1b30 = v;
        o->FUN_000443c0();
    }
    if (f1e50 != 0 && f1e54 > 0.0f)
        f1e54 = f1e54 - dt;
    for (int i = 0; i < 14; i++)
        f1e60[i] = dt + f1e60[i];

    if (o11c != 0) {
        if (f1b0c.f > 0.0f) {
            f.av = f1b0c;
            f.limit = o11c->f130 * f1b14;
            Obj11c_40970 *oc = o11c;
            bool proceed;
            if (b1b34 == 0) {
                if (f1e4c > oc->f154) {
                    b1b34 = 1;
                    f1b30 = 0.0f;
                }
                proceed = false;
            } else if (!(f1b30 >= oc->f158)) {
                proceed = true;
            } else {
                b1b34 = 0;
                proceed = false;
            }
            if (proceed && f.av.f < f.limit) {
                f.g = oc->f150;
                double base;
                if (((Hero_40970 *)w->hero)->FUN_00025d30(this) && w->opts->FUN_00086340()->FUN_00092940(0x2e2))
                    base = f.g.f * 10.0f;
                else
                    base = f.g.f;
                double t = base * dt + f.av.f;
                if (t > f.limit)
                    t = f.limit;
                bool skip = false;
                if (f1b18 > 0.0f || f1b1c > 0)
                    if (t < f1b0c.f)
                        skip = true;
                if (!skip) {
                    World *wd = DAT_004dd700;
                    bool wasNeg = (f1b0c.f <= 0.0f);
                    f1b0c.f = t;
                    if (t < 0.0)
                        f1b0c.f = 0.0f;
                    if (o11c != 0) {
                        if (f1b10 < f1b0c.f)
                            f1b0c.f = f1b10;
                        if (o11c->f134 > f1b0c.f && f1b28 != 2)
                            f1b0c.f = o11c->f134;
                        if (f1b0c.f <= 0.0f && !wasNeg && wd->sink30 != 0) {
                            f.buf.FUN_001c9a40(*f10);
                            wd->sink30->FUN_001cbc20(&f.buf);
                        }
                    }
                }
            }
        }
        if (f320 > 0.0f) {
            double r = f320 - dt * o11c->f1ac;
            f320 = r;
            if (r < 0.0)
                f320 = 0.0f;
        }
    }
    if (f334 != 0 || f338 != 0)
        f38c = dt + f38c;
    t0dc.FUN_002322f0(2, dt);
    if (f108 != t0dc.first) {
        f300 = 0.0f;
        f304 = 0.0f;
    }
}
