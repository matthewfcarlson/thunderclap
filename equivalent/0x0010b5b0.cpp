// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 39/43, incomplete)
// hulkfight::ai::FaceTargetAction::vfunc_5 @ 0x0010b5b0
extern "C" double fabs(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Pos {
    void FUN_00059a50(V3 *out);
};

struct Ctl {
    unsigned __int64 FUN_000443c0();
    char pad0[0x1b0];
    int f1b0;               // 0x1b0
    char pad1b4[0x478 - 0x1b4];
    float thr2;             // 0x478
    float thr1;             // 0x47c
};

struct Sub {
    char pad0[0x24];
    int f24;                // 0x24
    char pad28[0x54 - 0x28];
    int f54;                // 0x54
    char pad58[0x6c - 0x58];
    int f6c;                // 0x6c
    char pad70[0x78 - 0x70];
    int f78;                // 0x78
    char pad7c[0x11c - 0x7c];
    V3 dir;                 // 0x11c
    char pad128[0x150 - 0x128];
};

struct Tgt {
    char pad0[0x40];
    V3 pos;                 // 0x40
};

struct Player {
    char pad0[0x10];
    Pos *pos;               // 0x10
    char pad14[0x11c - 0x14];
    Ctl *ctl;               // 0x11c
    char pad120[0x328 - 0x120];
    Tgt *tgt;               // 0x328
    char pad32c[0x1b78 - 0x32c];
    V3 aim;                 // 0x1b78
    char pad1b84[0x1f58 - 0x1b84];
    Sub sub;                // 0x1f58
    int f20a8;              // 0x20a8
    float FUN_00035700();
    void FUN_00035550(V3 *out);
    void FUN_0010b580(V3 *p);
};

struct Me {
    char pad0[0x11c];
    Ctl *ctl;               // 0x11c
    char pad120[0x12c - 0x120];
    Tgt *tgt;               // 0x12c
};

struct Owner {
    Player *FUN_00059a30();
};

struct Link {
    Owner *FUN_000592a0();
};

struct Hold {
    char pad0[0x124];
    Me *me;                 // 0x124
};

struct Game {
    char pad0[0x20];
    Hold *hold;             // 0x20
};

extern Game *DAT_004dd700;
extern unsigned __int64 DAT_004dc0c8;
extern float __cdecl FUN_00224ea0(float a, float b);

class FaceTargetAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x1c];
    Link *link;             // 0x20
};

bool FaceTargetAction::vfunc_5(int a, int b)
{
    if (a != 0)
        return true;
    if (link == 0)
        return false;
    Player *p = link->FUN_000592a0()->FUN_00059a30();
    if (p == 0)
        return false;
    bool ok = p->ctl->FUN_000443c0() == DAT_004dc0c8;
    Tgt *t = p->tgt;
    if (t == 0) {
        if (p->f20a8 >= 0)
            return false;
        Ctl *pc = p->ctl;
        if (pc == 0)
            return false;
        Me *me = DAT_004dd700->hold->me;
        if (me == 0)
            return false;
        Tgt *mt = me->tgt;
        if (mt == 0)
            return false;
        Ctl *mc = me->ctl;
        if (mc == 0)
            return false;
        if (pc->f1b0 == mc->f1b0)
            return false;
        t = mt;
    }
    struct Frame {
        V3 u;                   // esp+0xc
        V3 d;                   // esp+0x18
        union {                 // esp+0x24: one slot, three lives
            V3 tp;              //   the target position
            V3 aim;             //   a copy of p->aim
            V3 vf;              //   FUN_00035550's out-vector
        } t;
        V3 w;                   // esp+0x30
    } f;
    f.t.tp = t->pos;
    f.u.x = 0.0f; f.u.y = 0.0f; f.u.z = 0.0f;
    p->pos->FUN_00059a50(&f.u);
    f.d.x = f.t.tp.x - f.u.x;
    f.d.y = f.t.tp.y - f.u.y;
    f.d.z = f.t.tp.z - f.u.z;
    f.d.FUN_0022d110();
    Sub *sub = &p->sub;
    float F = p->FUN_00035700();
    // The original copies p->aim with x and y on the FPU stack and z through the dead tp slot.
    float ax = p->aim.x, ay = p->aim.y;
    f.t.aim.z = p->aim.z;
    f.w.x = ax - f.u.x;
    f.w.y = ay - f.u.y;
    f.w.z = f.t.aim.z - f.u.z;
    bool far = f.w.FUN_0022d110() > 1.0f;
    if (ok && sub != 0 && F == 0.0f && far) {
        float a1 = FUN_00224ea0(f.d.x, f.d.z);
        p->FUN_00035550(&f.t.vf);
        Ctl *pc;
        double dd = a1 * 57.2957764f - FUN_00224ea0(f.t.vf.x, f.t.vf.z) * 57.2957764f;
        pc = p->ctl;
        float delta = (float)dd;
        double ad = fabs(dd);
        if (ad > pc->thr1 && ad < pc->thr1 + 50.0f) {
            sub->f54 = 1;
            sub->f24 = 1;
            p->FUN_0010b580(&f.u);
        } else if (ad > pc->thr2 && ad < pc->thr2 + 50.0f) {
            sub->f24 = 1;
            if (delta < 0.0f)
                sub->f6c = 1;
            else
                sub->f78 = 1;
            p->FUN_0010b580(&f.u);
        }
    }
    sub->dir = f.d;
    return true;
}
