// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 38/38)
// FUN_001d7b80 @ 0x001d7b80
#include "decls/address.h"
struct Vec3_1d7b80 {
    float x, y, z;
};

struct Key_1d7b80 {
    unsigned int lo;
    unsigned int hi;
};

struct Flags_1d7b80 {
    char pad00[0x68];
    unsigned char b68;
    unsigned char b69;
};

struct State_1d7b80 {
    char pad00[8];
    void *owner;              // 0x08
    int mode;                 // 0x0c
    char pad10[0x74 - 0x10];
    Flags_1d7b80 *flags;             // 0x74
};

struct Xform_1d7b80 {
    char pad00[0x30];
    Vec3_1d7b80 pos;                 // 0x30
};

class Part_1d7b80 {
public:
    char pad00[0x10];
    State_1d7b80 *state;             // 0x10
    Xform_1d7b80 *FUN_002fc6f0();
};

class Locator {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual Vec3_1d7b80 *l4();
};

struct Matched {
    char pad00[8];
    unsigned int lo;          // 0x08
    unsigned int hi;          // 0x0c
};

struct Recorder {
    void FUN_00066a10();
};

struct World {
    char pad00[0xc];
    struct Listener_1d7b80 *listener; // 0x0c
};

class Actor_1d7b80;
struct Listener_1d7b80 {
    void FUN_001dc170(Actor_1d7b80 *a, int flag);
};

extern Key_1d7b80 DAT_004e2520;
extern Key_1d7b80 DAT_004e2528;
extern Key_1d7b80 DAT_004e2530;
extern Key_1d7b80 DAT_004e2550;
extern Key_1d7b80 DAT_004e2558;

Recorder *__stdcall FUN_000678d0(Key_1d7b80 *key);

class Actor_1d7b80 {
public:
    char pad000[8];
    Key_1d7b80 key;                  // 0x08
    char pad10[0xa0 - 0x10];
    Part_1d7b80 *part;               // 0xa0
    char pada4[0xb0 - 0xa4];
    unsigned char hasHook;    // 0xb0
    char padb1[0xec - 0xb1];
    Matched *match;           // 0xec
    int fF0;
    int fF4;
    unsigned char fF8;
    char padF9[3];
    int fFC;
    char pad100[0x11c - 0x100];
    Locator *locator;         // 0x11c
    char pad120[0x164 - 0x120];
    Vec3_1d7b80 posA;                // 0x164
    Vec3_1d7b80 posB;                // 0x170
    Vec3_1d7b80 posC;                // 0x17c
    Vec3_1d7b80 posD;                // 0x188
    char pad194[0x1a0 - 0x194];
    unsigned char fired;      // 0x1a0

    void FUN_0027de50(int a, Actor_1d7b80 *b);
    void FUN_001d7b80(int a, int b);
};

void Actor_1d7b80::FUN_001d7b80(int a, int b)
{
    fFC = 0;
    if (part) {
        State_1d7b80 *st = part->state;
        if (st) {
            st->mode = 5;
            st->owner = this;
            Flags_1d7b80 *fl = st->flags;
            if (fl) {
                fl->b69 = 0;
                fl->b68 = 0;
            }
        }
    }
    if (hasHook)
        FUN_0027de50(5, this);

    const Vec3_1d7b80 *src;
    if (part)
        src = &part->FUN_002fc6f0()->pos;
    else
        src = locator->l4();
    posB = *src;
    posA = posB;

    if (part)
        src = &part->FUN_002fc6f0()->pos;
    else
        src = locator->l4();
    posC = *src;

    if (part)
        src = &part->FUN_002fc6f0()->pos;
    else
        src = locator->l4();
    posD = *src;

    Matched *m = match;
    fF0 = 0;
    fF4 = 0;
    fF8 = 0;
    if (m) {
        if (m->lo == DAT_004e2530.lo && m->hi == DAT_004e2530.hi) {
            if (key.lo == DAT_004e2528.lo && key.hi == DAT_004e2528.hi)
                return;
            if (key.lo == DAT_004e2550.lo && key.hi == DAT_004e2550.hi)
                return;
            if (key.lo == DAT_004e2558.lo && key.hi == DAT_004e2558.hi)
                return;
            if (key.lo == DAT_004e2520.lo && key.hi == DAT_004e2520.hi)
                return;
            Key_1d7b80 k;
            k.lo = key.lo;
            k.hi = key.hi;
            FUN_000678d0(&k)->FUN_00066a10();
            fired = 1;
            Listener_1d7b80 *l = DAT_004dd700->listener;
            if (l)
                l->FUN_001dc170(this, 1);
        }
    }
}
