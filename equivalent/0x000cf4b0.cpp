// STATUS: equivalent (tools/equiv.py level 3: 20035 inputs, branch coverage 36/36)
// FUN_000cf4b0 @ 0x000cf4b0
// FUN_000cf4b0 @ 0x000cf4b0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Track {
    int FUN_001d60c0();
};

struct Node {
    int FUN_001d62d0();
    char pad[0xec - 0];
    Track *track;
};

struct Lookup_cf4b0 {
    Node *FUN_001def30(const char *name);
};

struct Table_cf4b0 {
    float *FUN_00024280(unsigned __int64 key);
};

struct Slot_cf4b0 {
    char name[0x40];
};

struct Owner_cf4b0 {
    char pad0[0x0c];
    Lookup_cf4b0 *lookup;
    char pad1[0x20 - 0x10];
    Table_cf4b0 *table;
};

struct Ctl_cf4b0 {
    char pad0[0x0c];
    Owner_cf4b0 *owner;
    char pad1[0xb8 - 0x10];
    unsigned flags;
    char pad2[0x250 - 0xbc];
    void *p250;
    char pad3[0x264 - 0x254];
    Slot_cf4b0 slots[8];
    char pad4[0x478 - 0x464];
    float f478;
    float f47c;
    float f480;
    float f484;
    float f488;
    float f48c;
    float f490;
    int i494;

    void FUN_000cf4b0(float dt);
};

// equiv-conv: FUN_000cb7d0 ecx edx stack
void __cdecl FUN_000cb7d0(float *obj, float *target, float v);

void Ctl_cf4b0::FUN_000cf4b0(float dt)
{
    if (!(flags & 2))
        return;
    if (!p250)
        return;

    float fx = 0.0f;
    float fy = 0.0f;
    for (int i = 0; i < 8; i++) {
        if (slots[i].name[0] == 0)
            continue;
        Table_cf4b0 *tbl = owner->table;
        float *e = tbl->FUN_00024280(FUN_002672f0(slots[i].name, 0, 0));
        if (e) {
            fx += e[0x1b0c / 4];
            fy += e[0x1b10 / 4];
        } else {
            Node *n = owner->lookup->FUN_001def30(slots[i].name);
            if (n) {
                fx += (float)n->FUN_001d62d0();
                fy += (float)n->track->FUN_001d60c0();
            }
        }
    }

    fx = fx - 1.0f;
    f488 = fy;
    f480 = fx;
    float d = fx - f484;
    if (d < 0) d = -d;
    if (!(d <= 1e-05f)) {
        float d2 = fx - f478;
        if (d2 < 0) d2 = -d2;
        if (!(d2 <= 1e-05f)) {
            f490 = 0.0f;
            float t = fx - f484;
            if (t < 0) t = -t;
            float v = 0.125f * t + 600.0f;
            float r = (t > v) ? v : 4.0f;
            if (!(t < 4.0f) && t <= v)
                r = t;
            f48c = r;
        }
        if (!(f490 <= 0.5f))
            FUN_000cb7d0(&f484, &f480, dt * f48c);
        int *p = &i494;
        if ((*(char*)&DAT_004dde79) == 0) {
            *p += DAT_0049fcb0;
            if (*p > 0xff) {
                *p = 0xff;
                (*(char*)&DAT_004dde79) = 1;
            }
        } else {
            *p -= DAT_0049fcb0;
            if (*p < 0) {
                *p = 0;
                (*(char*)&DAT_004dde79) = 0;
            }
        }
    } else {
        int *p = &i494;
        *p += DAT_0049fcb0;
        if (*p > 0xff)
            *p = 0xff;
    }
    f490 = dt + f490;
    f478 = f480;
    f47c = f484;
}
