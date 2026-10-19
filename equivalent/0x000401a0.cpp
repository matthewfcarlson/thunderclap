// STATUS: equivalent (tools/equiv.py level 3: 19195 inputs, branch coverage 38/38)
// FUN_000401a0 @ 0x000401a0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/unknown.h"

struct Tuning_401a0 {
    bool FUN_00092940(int id);
};

struct Rig_401a0 {
    char pad0[0x128];
    float f128;  // 0x128
    float f12c;  // 0x12c
    char pad130[0x8];
    float f138;  // 0x138
    float f13c;  // 0x13c
    float f140;  // 0x140
    float f144;  // 0x144
    float f148;  // 0x148
    float f14c;  // 0x14c
    __int64 FUN_000443c0();
};

struct Hud_401a0 {
    char pad00[8];
    void* panel;
};

struct Pause {
    void FUN_000d2c30();
};

struct PauseHolder {
    char pad00[8];
    Pause* pause;           // 0x08
};

struct World {
    char pad00[0x3c];
    PauseHolder* holder;    // 0x3c
    char pad40[0x54 - 0x40];
    struct Registry_401a0* registry;  // 0x54
};

struct Registry_401a0 {
    Tuning_401a0* FUN_00086340();
};


class Character_401a0 {
public:
    void FUN_000401a0();

    char pad0[0x11c];
    Rig_401a0* rig;  // 0x11c
    char pad120[0x19ec];
    float f1b0c;  // 0x1b0c
    float f1b10;  // 0x1b10
    float f1b14;  // 0x1b14
    char pad1b18[0x10];
    int f1b28;  // 0x1b28
    char pad1b2c[0x584];
    int f20b0;  // 0x20b0
};

void Character_401a0::FUN_000401a0()
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (rig == 0) {
        f20b0 = 0;
    } else {
        f20b0 = 0;
        Tuning_401a0* tuning = DAT_004dd700->registry->FUN_00086340();
        Rig_401a0* r = rig;
        // the load of f128 happens before the null test (hidden from the compiler)
        f1b10 = r->f128;
        if (rig && rig->FUN_000443c0() == (*(__int64*)&DAT_004dc0e0)) {
            if (tuning->FUN_00092940(0x27b)) {
                f1b10 = rig->f138 + f1b10;
                if (tuning->FUN_00092940(0x298)) {
                    f1b10 = rig->f13c + f1b10;
                    if (tuning->FUN_00092940(0x2ba))
                        f1b10 = rig->f140 + f1b10;
                }
            }
            f1b14 = f1b10;
            f1b10 = rig->f144 + f1b10;
            if (tuning->FUN_00092940(0x28b)) {
                f1b10 = rig->f148 + f1b10;
                if (tuning->FUN_00092940(0x29e))
                    f1b10 = rig->f14c + f1b10;
            }
        }

        r = rig;
        if (r && r->FUN_000443c0() == (*(__int64*)&DAT_004dc0e0)) {
            if (tuning->FUN_00092940(0x2e5)) {
                f1b10 = f1b10 + f1b10;
                f1b14 = f1b14 + f1b14;
            }
        } else {
            if (tuning->FUN_00092940(0x2e6))
                f1b10 = f1b10 + f1b10;
            if (tuning->FUN_00092940(0x2e7))
                f1b10 = f1b10 * 0.5f;
            f1b14 = f1b10;
        }

        r = rig;
        f1b28 = 0;
        f1b0c = r->f12c * f1b14;
        if (rig && rig->FUN_000443c0() == (*(__int64*)&DAT_004dc0e0)) {
            Pause* pause = DAT_004dd700->holder->pause;
            if (pause)
                pause->FUN_000d2c30();
        }
    }
}
