extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Pos {
    void FUN_00059a50(V3 *out);
};

struct Q {
    char pad0[8];
    unsigned __int64 id;    // 0x8
};

struct Ent {
    char pad0[8];
    unsigned __int64 id;    // 0x8
    Pos *pos;               // 0x10
    char pad14[0xdc - 0x14];
    Q *anim;                // 0xdc
    void FUN_00035550(V3 *out);
};

struct Tgt {
    char pad0[8];
    Ent *ent;               // 0x8
    int count;              // 0xc
};

struct Ctl {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual Ent *v6();
    char pad04[0x60 - 0x4];
    Tgt *tgt;               // 0x60
};

struct Rng {
    float FUN_00078780();
};

extern Rng *FUN_000964d0();
extern unsigned __int64 __cdecl FUN_0027b020(const char *s);
extern unsigned __int64 DAT_004dc0e0;

struct Self {
    char pad0[0x58];
    Ctl *ctl;               // 0x58
    char pad5c[0xa0 - 0x5c];
    float f_a0;             // 0xa0
    bool FUN_00107410(int a, int b);
};

bool Self::FUN_00107410(int a, int b)
{
    Rng *rng = FUN_000964d0();
    Ent *pl = ctl->v6();
    Tgt *tg = ctl->tgt;
    if (tg->count != 1)
        return false;
    Ent *e = tg->ent;
    bool same = true;
    if (e->id != DAT_004dc0e0)
        same = false;
    V3 v1;
    v1.x = 0.0f; v1.y = 0.0f; v1.z = 0.0f;
    pl->pos->FUN_00059a50(&v1);
    V3 v2;
    v2.x = 0.0f; v2.y = 0.0f; v2.z = 0.0f;
    e->pos->FUN_00059a50(&v2);
    V3 w;
    w.x = v2.x - v1.x;
    w.y = 0.0f;
    w.z = v2.z - v1.z;
    float dist = (float)sqrt(w.z * w.z + w.x * w.x);
    w.FUN_0022d110();
    V3 n1;
    e->FUN_00035550(&n1);
    n1.y = 0.0f;
    n1.FUN_0022d110();
    V3 n2;
    pl->FUN_00035550(&n2);
    n2.y = 0.0f;
    n2.FUN_0022d110();
    if (!same)
        return false;
    if (!(f_a0 < -3.0f))
        return false;
    if (!(dist < 15.0f))
        return false;
    Q *q = e->anim;
    if (q == 0)
        return false;
    unsigned __int64 id = q->id;
    bool hit = false;
    if (n2.z * n1.z + n2.x * n1.x + n2.y * n1.y < -0.9f) {
        if (id == FUN_0027b020("jump_punch_charge")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("jump_gamma_charge")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("charge")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("sonic_clap_hold")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("hook_l_hold")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("hook_r_hold")) hit = true; } } } } }
    } else {
        if (id == FUN_0027b020("jump_gamma_charge")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("rage")) hit = true;
        else { id = q->id; if (id == FUN_0027b020("rage2")) hit = true; } }
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
