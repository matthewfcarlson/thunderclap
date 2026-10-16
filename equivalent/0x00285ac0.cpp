// STATUS: equivalent (tools/equiv.py level 3: 3090 inputs, branch coverage 5/5)
// FUN_00285ac0 @ 0x00285ac0
// equiv-dead: +0xf6 not taken, +0x10c taken, +0x10c not taken, +0x13c not taken, +0x152 taken, +0x152 not taken, +0x188 not taken, +0x19e taken, +0x19e not taken, +0x1ec not taken, +0x202 taken, +0x202 not taken, +0x250 not taken, +0x266 taken, +0x266 not taken: the constructor zeroes every Entry.src (esi+0x54, +0x80, +0xac, ...) just before the inlined Reset() reads it, so the 's != 0' side and the clamp compares behind it never run
  // 1.0
  // 0.0
#include "decls/data/game/global.h"

struct Source {
    char pad0[0x10];
    float value;
};

struct Entry {              // 0x2c bytes
    int f00;
    int f04;
    float f08;
    int f0c;
    int f10;
    float f14;
    float f18;
    int f1c;
    int f20;
    char f24;
    char pad25[3];
    Source *src;            // 0x28

    void Reset();
};

void Entry::Reset()
{
    Source *s = src;
    f00 = 0;
    f04 = 0;
    float v = (*(float*)&DAT_003f32e0);
    if (s) {
        v = s->value - (*(float*)&DAT_003f32dc);
        if (!(v >= (*(float*)&DAT_003f32e0)))
            v = (*(float*)&DAT_003f32e0);
    }
    f08 = v;
    f0c = 0;
    f10 = 0;
    f14 = 1.0f;
    f18 = 3.4028235e+38f;
    f1c = 0;
    f20 = 0;
    f24 = 1;
}

namespace pure3d {

class __declspec(novtable) BlendFrameControllerBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_0027b070();
    BlendFrameControllerBase() { FUN_0027b070(); }
};

class BlendFrameController : public BlendFrameControllerBase {
public:
    char f10;
    char pad11[7];
    float f18;
    char pad1c[4];
    int f20;
    int f24;
    int f28;
    Entry entries[5];       // 0x2c
    char f108;
    virtual void v1();
    BlendFrameController();
};

BlendFrameController::BlendFrameController()
{
    f10 = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f18 = 1.0f;
    for (int i = 0; i < 5; i++) {
        entries[i].f00 = 0;
        entries[i].f04 = 0;
        entries[i].f08 = 0.0f;
        entries[i].f0c = 0;
        entries[i].f10 = 0;
        entries[i].f14 = 0.0f;
        entries[i].f18 = 3.4028235e+38f;
        entries[i].f1c = 0;
        entries[i].f20 = 0;
        entries[i].f24 = 1;
        entries[i].src = 0;
    }
    f108 = 0;
    for (int i = 0; i < 5; i++)
        entries[i].Reset();
}

}
