// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 40/42, incomplete)
// FUN_001afba0 @ 0x001afba0
#include "decls/address.h"
struct Vec3_1afba0 {
    float x, y, z;
};

struct Probe_1afba0 {
    float FUN_000111f0();
};

struct Stats_1afba0 {
    char pad0[0x3a];
    char flag3a;
    char pad3b[0xb8 - 0x3b];
    float f_b8;
    Probe_1afba0 *FUN_00012f50(Vec3_1afba0 *out);
};

struct Region_1afba0 {
    char pad0[0x1b0];
    int id;
};

struct Anchor_1afba0 {
    char pad0[0x1b0];
    int id;
};

struct Holder_1afba0 {
    char pad0[0x11c];
    Anchor_1afba0 *anchor;
    char pad120[0x1b88 - 0x120];
    float stamp;
};

struct Gadget_1afba0 {
    char FUN_001d4e30();
};

struct Hit_1afba0;

struct Target_1afba0 {
    char pad0[8];
    int f8;
    char pad0c[0xec - 0xc];
    Gadget_1afba0 *gadget;
    char pad0f0[0x114 - 0xf0];
    int f114;
    char pad118[0x148 - 0x118];
    Holder_1afba0 *holder;
    char pad14c;
    char f14d;
    char pad14e[0x1c9 - 0x14e];
    char f1c9;
    Hit_1afba0 *FUN_001d72e0();
    char FUN_001d6a80();
    void FUN_001d82d0();
    void FUN_001d74c0(int a, int b, float c, int d);
    void FUN_001d7510();
};

struct Hit_1afba0 {
    char pad0[8];
    Target_1afba0 *target;
    int type;
    char pad10[0x6c - 0x10];
    int f6c;
};

struct Fx_1afba0 {
    void FUN_00083320(int a, int b, float t, int one, Probe_1afba0 *p, int zero);
};

struct Sys4c {
    Fx_1afba0 *FUN_0007ad00(int *key);
};

struct Clock_1afba0 {
    float FUN_00086080();
};

struct Cue_1afba0 {
    void FUN_001ec980(int id, const char *name);
};

struct Slot20_1afba0 {
    char pad0[0x124];
    int id;
};

struct World {
    char pad0[0x20];
    Slot20_1afba0 *slot20;
    char pad24[0x34 - 0x24];
    Cue_1afba0 *cue;
    char pad38[0x4c - 0x38];
    Sys4c *sys;
    char pad50[0x58 - 0x50];
    Clock_1afba0 *clock;
};


struct Body_1afba0 {
    char pad0[0x11c];
    Anchor_1afba0 *anchor;
    char pad120[0x128 - 0x120];
    Target_1afba0 *owner;
    int f12c;
    char pad130[0x334 - 0x130];
    Body_1afba0 *other;
};

struct Fighter_1afba0 {
    char pad0[0x20];
    Stats_1afba0 *stats;
    float FUN_00014580();
    Body_1afba0 *FUN_00013ec0();
    void FUN_0001a710(Hit_1afba0 *hit, int a, int b);
};

struct Controller_1afba0 {
    char pad0[8];
    Fighter_1afba0 *fighter;
};

int __stdcall FUN_001afba0(Controller_1afba0 *ctl, Hit_1afba0 *hit, int a, int b, float t)
{
    Vec3_1afba0 tmp;

    if (hit->type != 5)
        return 1;

    Fighter_1afba0 *f = ctl->fighter;
    if (f->FUN_00014580() < t)
        return 1;

    Body_1afba0 *body = f->FUN_00013ec0();
    if (body->owner != 0) {
        if (body->owner->FUN_001d72e0() == hit)
            return 1;
    }

    Target_1afba0 *tgt = hit->target;
    Holder_1afba0 *h = tgt->holder;
    if (h != 0) {
        if (DAT_004dd700 != 0)
            h->stamp = DAT_004dd700->clock->FUN_00086080();
        if (body->anchor->id == tgt->holder->anchor->id)
            return 1;
    }

    if (f->stats->flag3a) {
        if (tgt->gadget->FUN_001d4e30())
            return 1;
        if (tgt->f1c9)
            return 1;
    }

    int cur = tgt->f114;
    if (cur == body->f12c)
        return 1;
    if (body->other != 0) {
        if (cur == body->other->f12c)
            return 1;
    }

    Stats_1afba0 *st = f->stats;
    if (st->f_b8 > 0.0f || st->FUN_00012f50(&tmp)->FUN_000111f0() > 0.0f)
        tgt->FUN_001d82d0();

    if (tgt->f14d) {
        if (tgt->FUN_001d72e0()->f6c == 0) {
            Fx_1afba0 *fx = DAT_004dd700->sys->FUN_0007ad00(&tgt->f8);
            if (fx != 0) {
                Probe_1afba0 *p = f->stats->FUN_00012f50(&tmp);
                fx->FUN_00083320(a, b, t, 1, p, 0);
                DAT_004dd700->cue->FUN_001ec980(DAT_004dd700->slot20->id, "punch");
            }
        }
    }

    if (tgt->FUN_001d6a80()) {
        Stats_1afba0 *st2 = f->stats;
        if (st2->f_b8 > 0.0f || st2->FUN_00012f50(&tmp)->FUN_000111f0() > 0.0f) {
            tgt->FUN_001d74c0(0, 0, 10.0f, 1);
            tgt->FUN_001d7510();
        }
    }

    f->FUN_0001a710(hit, a, b);
    return 1;
}
