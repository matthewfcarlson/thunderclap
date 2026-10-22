// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 34/36, incomplete)
// FUN_0003b620 @ 0x0003b620
#include "compat/ptr.h"
struct Mat;

struct Ref_3b620 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Sub_3b620 {
    char data[0x28];
    void FUN_00232240();
};

struct Weapon_3b620 {
    char pad00[0xec];
    int fec;
};

struct Slot_3b620 {
    Weapon_3b620 *weapon;
    char pad04[0x50 - 4];
};

struct Bank {
    char pad00[0xa8];
    char flagA8;
    char pada9[3];
    hulk_intptr FUN_000446c0(int index);
};

struct Link124_3b620 {
    char pad00[0x10];
    Bank *owner;
};

class CCharacter_3b620 {
public:
    char pad00[0xb4];
    Sub_3b620 sub0;
    Sub_3b620 sub1;
    char pad104[4];
    Ref_3b620 *f108;
    Ref_3b620 *f10c;
    char pad110[0x11c - 0x110];
    Bank *bank;
    char pad120[0x124 - 0x120];
    Link124_3b620 *f124;
    CCharacter_3b620 *f128;
    char pad12c[0x300 - 0x12c];
    int f300;
    int f304;
    char pad308[0x320 - 0x308];
    int f320;
    char pad324[0x334 - 0x324];
    CCharacter_3b620 *f334;
    CCharacter_3b620 *f338;
    char pad33c[0x3a8 - 0x33c];
    Slot_3b620 slots[8];
    char pad628[4];
    Ref_3b620 *f62c;
    Ref_3b620 *f630;
    char pad634[0x1ad0 - 0x634];
    Ref_3b620 *f1ad0;
    char pad1ad4[0x1b60 - 0x1ad4];
    Ref_3b620 *f1b60;
    int f1b64;
    char pad1b68[0x1e58 - 0x1b68];
    int f1e58;
    void FUN_00038c40();
    void FUN_000393c0();
    void FUN_0003a680(CCharacter_3b620 *target, int a, int b, int c, Mat *m, float e5, float e6, float e7);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
    char FUN_0003b620(char reset);
};

char CCharacter_3b620::FUN_0003b620(char reset)
{
    f1b64 = 0;
    FUN_00038c40();
    sub0.FUN_00232240();
    sub1.FUN_00232240();
    if (f108) {
        f108->vfunc_1();
        f108 = 0;
    }
    if (f10c) {
        f10c->vfunc_1();
        f10c = 0;
    }
    if (f1ad0) {
        f1ad0->vfunc_1();
        f1ad0 = 0;
    }
    f1e58 = 0;
    FUN_000393c0();
    f320 = 0;
    if (f338) {
        f338->f334 = 0;
        FUN_0003a680(0, 0xffff, 0, 0, 0, 0.0f, 1.0f, 0.0f);
    }
    if (f334) {
        f334->FUN_0003a680(0, 0xffff, 0, 0, 0, 0.0f, 1.0f, 0.0f);
        f334 = 0;
    }
    if (f62c)
        f62c->vfunc_1();
    f62c = 0;
    if (f630)
        f630->vfunc_1();
    f630 = 0;
    if (reset) {
        for (int i = 0; i < 8; i++) {
            Weapon_3b620 *w = slots[i].weapon;
            if (w && bank) {
                int cur = w->fec;
                if (cur == bank->FUN_000446c0(i))
                    continue;
            }
            FUN_0003acf0(i, 0, -1, 0, 0, 0);
        }
    }
    f300 = 0;
    f304 = 0;
    if (f1b60) {
        f1b60->vfunc_1();
        f1b60 = 0;
    }
    Bank *o;
    if (f124) {
        o = f124->owner;
    } else {
        if (!f128)
            return 1;
        o = f128->bank;
    }
    if (o)
        o->flagA8 = 1;
    return 1;
}
