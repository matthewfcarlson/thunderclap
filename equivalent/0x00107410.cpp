// STATUS: equivalent (tools/equiv.py level 3: 3076 inputs, branch coverage 51/52, incomplete)
// FUN_00107410 @ 0x00107410
#include "decls/address.h"
extern "C" double sqrt(double);

struct V3_107410 {
    float x, y, z;
    float FUN_0022d110();
};

struct Pos_107410 {
    void FUN_00059a50(V3_107410 *out);
};

struct Q_107410 {
    char pad0[8];
    unsigned __int64 id;    // 0x8
};

struct Ent_107410 {
    char pad0[8];
    unsigned __int64 id;    // 0x8
    Pos_107410 *pos;               // 0x10
    char pad14[0xdc - 0x14];
    Q_107410 *anim;                // 0xdc
    void FUN_00035550(V3_107410 *out);
};

struct Tgt_107410 {
    char pad0[8];
    Ent_107410 *ent;               // 0x8
    int count;              // 0xc
};

struct Ctl_107410 {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual Ent_107410 *v6();
    char pad04[0x60 - 0x4];
    Tgt_107410 *tgt;               // 0x60
};

struct Rng_107410 {
    float FUN_00078780();
};

extern Rng_107410 *FUN_000964d0();
extern unsigned __int64 DAT_004dc0e0;

struct Self_107410 {
    char pad0[0x58];
    Ctl_107410 *ctl;               // 0x58
    char pad5c[0xa0 - 0x5c];
    float f_a0;             // 0xa0
    bool FUN_00107410(int a, int b);
};

bool Self_107410::FUN_00107410(int a, int b)
{
    Rng_107410 *rng = FUN_000964d0();
    Ent_107410 *pl = ctl->v6();
    Tgt_107410 *tg = ctl->tgt;
    if (tg->count != 1)
        return false;
    Ent_107410 *e = tg->ent;
    bool same = true;
    if (e->id != DAT_004dc0e0)
        same = false;
    V3_107410 v1;
    v1.x = 0.0f; v1.y = 0.0f; v1.z = 0.0f;
    pl->pos->FUN_00059a50(&v1);
    V3_107410 v2;
    v2.x = 0.0f; v2.y = 0.0f; v2.z = 0.0f;
    e->pos->FUN_00059a50(&v2);
    V3_107410 w;
    w.x = v2.x - v1.x;
    w.y = 0.0f;
    w.z = v2.z - v1.z;
    float dist = (float)sqrt(w.z * w.z + w.x * w.x);
    w.FUN_0022d110();
    V3_107410 n1;
    e->FUN_00035550(&n1);
    n1.y = 0.0f;
    n1.FUN_0022d110();
    V3_107410 n2;
    pl->FUN_00035550(&n2);
    n2.y = 0.0f;
    n2.FUN_0022d110();
    if (!same)
        return false;
    if (!(f_a0 < -3.0f))
        return false;
    if (!(dist < 15.0f))
        return false;
    Q_107410 *q = e->anim;
    if (q == 0)
        return false;
    bool hit = false;
    unsigned __int64 id = q->id;
    if (n2.z * n1.z + n2.x * n1.x + n2.y * n1.y < -0.9f) {
        if (id == FUN_0027b020("jump_punch_charge"))
            hit = true;
        else {
            id = q->id;
            if (id == FUN_0027b020("jump_gamma_charge"))
                hit = true;
            else {
                id = q->id;
                if (id == FUN_0027b020("charge"))
                    hit = true;
                else {
                    id = q->id;
                    if (id == FUN_0027b020("sonic_clap_hold"))
                        hit = true;
                    else {
                        id = q->id;
                        if (id == FUN_0027b020("hook_l_hold"))
                            hit = true;
                        else {
                            id = q->id;
                            if (id == FUN_0027b020("hook_r_hold"))
                                hit = true;
                        }
                    }
                }
            }
        }
    } else {
        if (id == FUN_0027b020("jump_gamma_charge"))
            hit = true;
        else {
            id = q->id;
            if (id == FUN_0027b020("rage"))
                hit = true;
            else {
                id = q->id;
                if (id == FUN_0027b020("rage2"))
                    hit = true;
            }
        }
    }
    if (!hit)
        return false;
    if (!(rng->FUN_00078780() < 0.3f) && !(dist < 8.0f)) {
        f_a0 = 0.0f;
        return false;
    }
    f_a0 = rng->FUN_00078780() * 0.5f;
    return false;
}
