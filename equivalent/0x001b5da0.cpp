// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 12/12)
// FUN_001b5da0 @ 0x001b5da0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

class Settings_1b5da0 {
public:
    unsigned char FUN_0023f760(const char *name, int a, int b);
};

class Input_1b5da0 {
public:
    unsigned char FUN_00092940(int button);
};

class Display_1b5da0 {
public:
    char pad0[0x54];
    Input_1b5da0 *input;
};

class Pad_1b5da0 {
public:
    Input_1b5da0 *FUN_00086340();
};

class Gravity_1b5da0 {
public:
    void FUN_002ece90(float x, float y, float z);
};

class Anim_1b5da0 {
public:
    void FUN_002eea80();
    void FUN_002ed6e0(int t);
};

class Timer {
public:
    void FUN_002f9660();
};

struct World {
    char pad0[0x54];
    Pad_1b5da0 *pad;
};


class Physics_1b5da0 {
public:
    void FUN_001b5da0(int a, int b);
    void FUN_001b4d00(int a, int b);

    char pad0[8];
    Anim_1b5da0 *anim;
    char pad1[0x5a8 - 0xc];
    float gravityY;
};

void Physics_1b5da0::FUN_001b5da0(int a, int b)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if ((*(Settings_1b5da0**)&DAT_004dd6e8)->FUN_0023f760("DoPhysics", 0x66, 1)) {
        Input_1b5da0 *input = DAT_004dd700->pad->FUN_00086340();
        union { float f; unsigned int u; } d;
        bool set = false;
        if (input->FUN_00092940(0x13)) {
            d.f = gravityY - -500.0f;
            d.u &= 0x7fffffff;
            if (!(d.f <= 1e-05f)) {
                gravityY = -500.0f;
                set = true;
                (*(Gravity_1b5da0**)&DAT_00554c10)->FUN_002ece90(0.0f, -500.0f, 0.0f);
            }
        }
        if (!set) {
            d.f = gravityY - -3000.0f;
            d.u &= 0x7fffffff;
            if (!(d.f <= 1e-05f) && !input->FUN_00092940(0x13)) {
                gravityY = -3000.0f;
                (*(Gravity_1b5da0**)&DAT_00554c10)->FUN_002ece90(0.0f, -3000.0f, 0.0f);
            }
        }
        FUN_001b4d00(a, b);
        if (anim) {
            anim->FUN_002eea80();
            anim->FUN_002ed6e0(b);
        }
        (*(Timer*)&DAT_0055545c).FUN_002f9660();
    }
}
