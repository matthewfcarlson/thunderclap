// STATUS: equivalent (tools/equiv.py level 3: 23251 inputs, branch coverage 184/187, incomplete)
// FUN_0001b510 @ 0x0001b510
#include "decls/address.h"
typedef unsigned __int64 u64;

struct V3 {
    float x, y, z;
    float FUN_000111f0();
    float FUN_0022d110();
    void FUN_00011160(float f, V3 *v);
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Request {
    int r00;
    int r04;
    V3 target;                     // 8
    float f14;
    V3 aim;                        // 0x18
    unsigned char flag24;          // 0x24
    char pad25[0x38 - 0x25];
    V3 v38;
    unsigned char b44;
    char pad45[0x4c - 0x45];
    RefObj *f4c;
    RefObj *f50;
    int r54;
    float r58;
    char pad5c[0x68 - 0x5c];
    float r68;
    RefObj *f6c;
    int f70;
    void *f74;
    float f78;
    float f7c;
    float f80;
    char pad84[0x98 - 0x84];
    void FUN_00059820();
    void FUN_000595f0(V3 *v, float a, float b, float c);
    void FUN_00059300();
};

struct Job {
    virtual void v0();
    virtual void v1();
    Job *FUN_000598e0(void *a, Request *req);
};

struct Sink;
struct Handle {
    char FUN_00231ad0(Sink *sink, Job *job, int n);
};
struct Sink {
    int v;
    char FUN_00231e80(Handle *h);
};

struct Queue {
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual Handle *Submit(Job *job, int n);
};

struct Ctrl {
    char pad0[0x10];
    unsigned char b10;
    char pad11[3];
    int f14;
    char pad18[4];
    float f1c;
    char pad20[0x2c - 0x20];
    float f2c;
    char pad30[0x170 - 0x30];
    float f170;
    char pad174[0x1b0 - 0x174];
    int f1b0;
    char pad1b4[0x30c - 0x1b4];
    float f30c;
};

struct Item;
struct Pad;
struct Target;
struct Holder;

struct Player {
    char pad0[0xdc];
    Sink s0dc;
    char pade0[0x11c - 0xe0];
    Ctrl *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x334 - 0x32c];
    Pad *f334;
    Pad *f338;
    char pad33c[0x390 - 0x33c];
    Pad *f390;
    char pad394[0x1b28 - 0x394];
    int f1b28;
    float FUN_0003ebb0(int a);
    char FUN_00035c30(Item *it);
    void FUN_00035c70(void *it);
    void FUN_00035230(V3 *out);
    void FUN_0003ffa0(void *obj, int zero);
    RefObj *FUN_00035ef0(int a);
    void FUN_00035b70(int a, int b, int c);
    void FUN_0003a9d0(RefObj *o);
};

struct Slot {
    float FUN_001d4e90();
    u64 FUN_001d4f70();
};

struct Aux {
    char pad0[8];
    int f08;
    int f0c;
};

struct Pad {
    char pad0[0x10];
    struct Anchor *f10;
    char pad14[0xdc - 0x14];
    Sink s0dc;
    char pade0[0xec - 0xe0];
    Slot *fec;
    char padf0[0x108 - 0xf0];
    int f108;
    char pad10c[4];
    char b110;
    char pad111[3];
    Aux *f114;
    char pad118[0x11c - 0x118];
    Ctrl *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    char pad130[0x140 - 0x130];
    int f140;
    char pad144[0x148 - 0x144];
    int f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    float f19c;
    char pad1a0[0x3a4 - 0x1a0];
    int f3a4;
    char pad3a8[0x20b0 - 0x3a8];
    int f20b0;
    char FUN_000360f0();
    void FUN_000437a0(float v, Request *req, int a, int b, int c);
    void FUN_00035b70(float a, float b, float c);
    void FUN_0003a9d0(RefObj *o);
    void FUN_0003ffa0(void *obj, int zero);
    char FUN_001d6980();
    int FUN_001d64a0();
    void FUN_001d86d0(V3 *a, V3 *b);
    char FUN_001d6ec0(int a, RefObj *b, int c);
    void FUN_0027d4f0(int a);
};

struct Target {
    char pad0[0x64];
    float a;
    float b;
    float c;
    char pad70[0x100 - 0x70];
    void *obj;
    void FUN_00081420(Request *req);
};

struct Item : RefObj {
    int pad4;
    void *f08;
    int f0c;
};

struct Blob {
    char f0;
};

struct Cfg {
    char pad0[0x14];
    int f14;
    char pad18[4];
    int f1c;
    int f20;
    char pad24[4];
    int f28;
    Queue *f2c;
    char pad30[8];
    Queue *f38;
    char pad3c[0x48 - 0x3c];
    RefObj *f48;
    int f4c;
    Blob f50;
    char pad54[0x90 - 0x54];
    float f90;
    float f94;
    char pad98[0xb0 - 0x98];
    int fb0;
    int fb4;
    char padb8[0xc4 - 0xb8];
    int fc4;
    float fc8;
    unsigned char fcc;
    char padcd[3];
    float fd0;
    float fd4;
    float fd8;
    float fdc;
    float fe0;
    unsigned char fe4;
    char pade5[3];
    float fe8;
    float fec;
    float ff0;
    float ff4;
    float ff8;
    void FUN_00012590(V3 *out);
    void FUN_000125c0(V3 *out);
    void FUN_00012610(V3 *out);
};

struct Holder {
    virtual void h0();
    char pad4[0x34 - 4];
    unsigned char b34;
    char pad35[0x4c - 0x35];
    RefObj *f4c;
};

struct Anchor {
    void *f0;
    Player *FUN_00059a30();
    void FUN_00059a50(V3 *out);
};

struct Owner {
    virtual void o0(); virtual void o1(); virtual void o2();
    virtual Holder *o3();
    int f04;
    void *f08;
    Anchor *FUN_000592a0();
};

struct Hud {
    void FUN_001cbd10(const char *s);
};

struct Scale {
    float FUN_001dddf0();
};

struct Runner {
    void FUN_001ecc80(Player *y, Pad *o, RefObj *r, Blob *b);
    void FUN_001ee090(Player *y, Pad *o, RefObj *r, Blob *b);
};

struct JudgeCfg {
    char pad0[0x352];
    unsigned char b352;
};

struct World {
    char pad0[0xc];
    Scale *f0c;
    char pad10[0x20 - 0x10];
    JudgeCfg *f20;
    char pad24[0x30 - 0x24];
    Hud *f30;
    Runner *f34;
};

extern u64 DAT_004dc030;

int __cdecl FUN_00266da0(int v);
Job *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj **slot, RefObj *obj);
void __cdecl FUN_000187a0(RefObj **slot, RefObj *obj);
void __cdecl FUN_00018840(int *slot, int v);
char __cdecl FUN_000444f0(int v);
float __cdecl FUN_00224f10(V3 *v);
void __cdecl FUN_00224d70(float f, V3 *v);
float __cdecl FUN_000964e0();
float __cdecl FUN_000445a0();
float __cdecl FUN_000445b0();
// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Player *frame, void *obj, V3 *out);


struct Frame {
    union {
        volatile float mult;
        Ctrl *ctrl;
    };                             // E-256
    union {
        float l252;
        Aux *aux;
    };                             // E-252
    float l248;                    // E-248
    int token;                     // E-244
    char pad240[3];
    unsigned char flag;            // E-237
    Player *Y;                     // E-236
    union {
        int l232;
        float f232;
    };                             // E-232
    V3 mid;                        // E-228
    V3 p216;                       // E-216
    V3 p204;                       // E-204
    float l192;                    // E-192
    V3 p188;                       // E-188
    V3 p176;                       // E-176
    Request req;                   // E-164
    V3 out;                        // E-12
};

class SpawnAction {
public:
    char pad00[0x1c];
    Owner *f1c;
    Cfg *f20;
    Item *f24;
    char pad28[4];
    int f2c;
    int f30;
    char pad34[0x74 - 0x34];
    float f74;
    float f78;
    RefObj *f7c;

    void FUN_0001b510(Item *a4, V3 *a8, V3 *a12, void *a16);
};

#define SPAWN(ZQ, B44V)                                                    \
    f.req.FUN_00059820();                                                  \
    f.req.target = *a8;                                                    \
    f.req.aim = *a12;                                                      \
    f.req.f78 = f.l248;                                                    \
    f.req.b44 = (B44V);                                                    \
    Job *job = FUN_0008d690(0xb0);                                         \
    if (job)                                                               \
        job = job->FUN_000598e0(f1c->f08, &f.req);                         \
    job->v0();                                                             \
    Handle *hd = (ZQ)->Submit(job, 0);                                     \
    if (hd) {                                                              \
        if (!f.Y->s0dc.FUN_00231e80(hd))                                    \
            hd->FUN_00231ad0(&f.Y->s0dc, job, -1);                         \
    }                                                                      \
    job->v1();                                                             \
    f.req.FUN_00059300();

void SpawnAction::FUN_0001b510(Item *e, V3 *a8, V3 *a12, void *a16)
{
    Frame f;
    {
        Cfg *c = f20;
        if (c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20)
            return;
    }
    if (f24 == 0)
        return;
    if (e == 0 || e == f24)
        return;
    f.token = FUN_00266da0(0xd);
    do {
    Player *Y = f1c->FUN_000592a0()->FUN_00059a30();
    f.Y = Y;
    if ((RefObj *)e == Y->f12c || Y->FUN_00035c30(e)) {
        break;
    }
    Y->FUN_00035c70(e);
    f.l232 = (int)DAT_004dd700->f20;
    Pad *O = 0;
    f.flag = 0;
    f.mult = 1.0f;
    if (e->f0c == 1) {
        O = (Pad *)e->f08;
    } else if (e->f0c == 7) {
        Anchor *anchor = f1c->FUN_000592a0();
        Player *fighter = anchor->FUN_00059a30();
        Target *t = (Target *)e->f08;
        if (t != 0) {
            f.p204.x = 0.0f;
            f.p204.y = 0.0f;
            f.p204.z = 0.0f;
            anchor->FUN_00059a50(&f.p204);
            f.p216.x = 0.0f;
            f.p216.y = 0.0f;
            f.p216.z = 0.0f;
            fighter->FUN_00035230(&f.p216);
            f.req.FUN_00059820();
            f.req.target.x = a8->x + t->a;
            f.req.target.y = a8->y + t->b;
            f.req.target.z = a8->z + t->c;
            f.req.target.x = f.req.target.x * 0.5f;
            f.req.target.y = f.req.target.y * 0.5f;
            f.req.target.z = f.req.target.z * 0.5f;
            f.mid = f.req.target;
            f.mid.x = f.mid.x - a8->x;
            f.mid.y = f.mid.y - a8->y;
            f.mid.z = f.mid.z - a8->z;
            if (f.mid.FUN_0022d110() > 1.0f) {
                f.req.target = *a8;
                f.req.target.FUN_00011160(1.0f, &f.mid);
            }
            f.req.aim = *a12;
            Cfg *c = f20;
            f.req.r00 = (int)c->f48;
            f.req.r04 = c->f4c;
            f.req.r54 = c->fb4;
            FUN_00018810(&f.req.f4c, fighter->f12c);
            FUN_00014210(f20->fb0, fighter, t->obj, &f.p188);
            c = f20;
            f.req.flag24 = c->fcc;
            f.req.r58 = c->fd0;
            f.req.r68 = c->fe0;
            f.l192 = c->fd8;
            f.l252 = c->fdc;
            f.f232 = c->fd4;
            if (f.req.r58 < 0.0f)
                f.req.r58 = -(FUN_000964e0() * f.req.r58);
            if (f.req.r68 < 0.0f)
                f.req.r68 = -(FUN_000964e0() * f.req.r68);
            f.req.f78 = 1.0f;
            if (f.l192 <= 0.0f)
                f.l192 = f.req.r58;
            f.req.FUN_000595f0(&f.p188, f.f232, f.l192, f.l252);
            t->FUN_00081420(&f.req);
            if (fighter->f328 == 0)
                fighter->FUN_0003ffa0(t->obj, 0);
            fighter->FUN_00035c70(t->obj);
            f.req.FUN_00059300();
        }
        break;
    } else if (e->f0c == 5) {
        Pad *p = (Pad *)e->f08;
        O = (Pad *)p->f148;
        if (O == 0) {
            f.aux = p->f114;
            if (f.aux != 0 && f.aux->f0c == 1) {
                f.mult = p->fec->FUN_001d4e90();
                if (f.mult > 0.0f && p->b110 == 0)
                    O = (Pad *)f.aux->f08;
                else
                    f.mult = 1.0f;
            }
        }
    }

    {
        // lo and hi live in the (not yet used) l248 / l252 slots
        f.l248 = f20->f90;
        f.l252 = f20->f94;
        float v = f.l248;
        if (f.l252 > 0.0f)
            v = Y->FUN_0003ebb0(1) * (f.l252 - f.l248) + f.l248;
        v = v * f.mult;
        if (Y->f1b28 != 0)
            f.l248 = (Y->f11c->f30c * Y->f11c->f170) * v;
        else
            f.l248 = v * Y->f11c->f30c;
    }

    if (O != 0) {
        if (f20->f28 == 1 || O->f20b0 != 0 || O == Y->f338 || O == Y->f334 || O == Y->f390 || O->FUN_000360f0()) {
            break;
        }
        f.ctrl = O->f11c;
        Cfg *c = f20;
        if (f.ctrl->f14 != 0) {
            int l2 = c->f20;
            int l1 = c->f1c;
            if (l2 > 0 && f30 >= l2) {
                break;
            }
            if (l1 > 0 && f2c >= l1) {
                break;
            }
            f30++;
        } else {
            int l1 = c->f1c;
            if (l1 > 0 && f2c >= l1) {
                break;
            }
        }
        f2c++;
        Blob *b = &f20->f50;
        if (b && b->f0) {
            RefObj *r = Y->FUN_00035ef0(c->f14);
            if (r)
                DAT_004dd700->f34->FUN_001ee090(Y, O, r, &f20->f50);
        }
        Holder *pl = f1c->o3();
        f.req.FUN_00059820();
        FUN_00018810(&f.req.f4c, (pl && pl->b34) ? pl->f4c : Y->f12c);
        FUN_00018810(&f.req.f50, O->f12c);
        FUN_000187a0(&f.req.f6c, f7c);
        FUN_00018840(&f.req.f70, Y->s0dc.v);
        {
            int fc4 = f20->fc4;
            if (fc4 != 0)
                f.req.f74 = (void *)fc4;
            else
                f.req.f74 = a16;
        }
        f.p176 = *a8;
        O->f10->FUN_00059a50(&f.p176);
        if (O->f140 == 1 || O->f140 == 2)
            f.p176.y = f.p176.y + f.ctrl->f2c;
        f.req.target.z = a8->z;
        f.req.target.x = f.p176.x + a8->x;
        f.req.target.x = f.req.target.x * 0.5f;
        f.mid.x = f.req.target.x;
        f.req.target.y = (a8->y + f.p176.y) * 0.5f;
        f.mid.y = f.req.target.y;
        f.req.target.z = (f.p176.z + f.req.target.z) * 0.5f;
        f.mid.z = f.req.target.z;
        f.mid.x = f.mid.x - a8->x;
        f.mid.y = f.mid.y - a8->y;
        f.mid.z = f.mid.z - a8->z;
        if (f.mid.FUN_0022d110() > 1.0f) {
            f.req.target = *a8;
            f.req.target.FUN_00011160(1.0f, &f.mid);
        }
        f.req.aim = *a12;
        f.req.r00 = (int)f20->f48;
        f.req.r04 = f20->f4c;
        f.req.f78 = f.l248;
        f.req.r54 = f20->fb4;
        f.req.f7c = Y->FUN_0003ebb0(1);
        f.req.f80 = 1.0f;
        FUN_00014210(f20->fb0, Y, e, &f.out);
        {
            Cfg *c2 = f20;
            c2->FUN_00012590(&f.p216);
            c2->FUN_000125c0(&f.p204);
            if (f.p204.FUN_000111f0() > 0.0f) {
                f.p188.x = f.p204.x - f.p216.x;
                f.p188.y = f.p204.y - f.p216.y;
                f.p188.z = f.p204.z - f.p216.z;
                f.p216.FUN_00011160(Y->FUN_0003ebb0(1), &f.p188);
            }
        }
        f.l252 = FUN_00224f10(&f.out);
        FUN_00224d70(f.l252, &f.p216);
        f.req.v38 = f.p216;
        {
            int sel = O->f11c->f14;
            Cfg *c3;
            if (FUN_000444f0(sel)) {
                c3 = f20;
                f.req.flag24 = c3->fcc;
                f.req.r58 = c3->fd0;
                f.req.r68 = c3->fe0;
                f.l192 = c3->fd8;
                f.l252 = c3->fd4;
                f.f232 = c3->fdc;
                f.mult = f.ctrl->f1c;
                f.mult = FUN_000445a0() / f.mult;
            } else {
                if (sel == 1) {
                    c3 = f20;
                    f.req.flag24 = c3->fe4;
                    f.req.r58 = c3->fe8;
                    f.req.r68 = c3->ff8;
                    f.l192 = c3->ff0;
                    f.l252 = c3->fec;
                    f.f232 = c3->ff4;
                    f.mult = f.ctrl->f1c;
                } else {
                    f.req.flag24 = 0;
                    f.req.r58 = 0.0f;
                    f.req.r68 = 0.0f;
                    f.l192 = 0.0f;
                    f.l252 = 0.0f;
                    f.f232 = 0.0f;
                    f.mult = f.ctrl->f1c;
                }
                f.mult = FUN_000445b0() / f.mult;
            }
        }
        if (f.req.r58 < 0.0f)
            f.req.r58 = -(FUN_000964e0() * f.req.r58);
        if (f.req.r68 < 0.0f)
            f.req.r68 = -(FUN_000964e0() * f.req.r68);
        if (f.l192 <= 0.0f)
            f.l192 = f.req.r58;
        f.req.FUN_000595f0(&f.out, f.mult * f.l252, f.mult * f.l192, f.mult * f.f232);
        if (O->f3a4 == 0 && f24 != 0)
            O->FUN_0003a9d0(f24);
        {
            Queue *q = f20->f2c;
            Handle *hd = 0;
            if (q) {
                Job *job = FUN_0008d690(0xb0);
                if (job)
                    job = job->FUN_000598e0(O->f10->f0, &f.req);
                job->v0();
                hd = q->Submit(job, 0);
                if (hd)
                    hd->FUN_00231ad0(&O->s0dc, job, -1);
                job->v1();
            }
            if (hd == 0)
                O->FUN_000437a0(f.l248, &f.req, 0, 0, 0);
        }
        f20->FUN_00012610(&f.p188);
        O->FUN_00035b70(f.p188.x, f74, f78);
        f74 = f74 * 0.75f;
        f78 = f78 * 0.75f;
        {
            Queue *q2 = f20->f38;
            if (q2) {
                Job *job = FUN_0008d690(0xb0);
                if (job)
                    job = job->FUN_000598e0(f1c->f08, &f.req);
                job->v0();
                Handle *h2 = q2->Submit(job, 0);
                if (h2) {
                    if (!f.Y->s0dc.FUN_00231e80(h2))
                        h2->FUN_00231ad0(&f.Y->s0dc, job, -1);
                }
                job->v1();
            }
        }
        if (f.Y->f328 == 0)
            f.Y->FUN_0003ffa0(O->f12c, 0);
        f.req.FUN_00059300();
    } else {
        if (e->f0c == 5) {
            Pad *p = (Pad *)e->f08;
            int run = 1;
            if (f20->f28 == 2)
                run = 0;
            else if (((JudgeCfg *)f.l232)->b352 == 0)
                run = 2;
            else if (p->FUN_001d6980())
                run = 0;
            if (run == 0) {
                break;
            }
            if (run == 1) {
                if (p->fec->FUN_001d4f70() == DAT_004dc030)
                    DAT_004dd700->f30->FUN_001cbd10("golf_stroke");
                Player *Yp = f.Y;
                int k = Yp->f11c->f1b0;
                if (p->f198 == k)
                    f.l248 = f.l248 * p->f19c;
                if (k == 2)
                    f.l248 = DAT_004dd700->f0c->FUN_001dddf0() * f.l248;
                if (p->FUN_001d6ec0((int)f.l248, Yp->f12c, 0)) {
                    p->FUN_0027d4f0(1);
                    f.flag = 1;
                    if (p->FUN_001d64a0() == 4 || p->FUN_001d64a0() == 3) {
                        Cfg *c4 = f20;
                        int c20 = c4->f20;
                        int c1c = c4->f1c;
                        if (!(c20 > 0 && f30 >= c20) && !(c1c > 0 && f2c >= c1c)) {
                            f30++;
                            f2c++;
                        }
                    } else {
                        int c1c = f20->f1c;
                        if (!(c1c > 0 && f2c >= c1c))
                            f2c++;
                    }
                }
                Cfg *c5 = f20;
                c5->FUN_00012590(&f.p216);
                c5->FUN_000125c0(&f.p204);
                if (f.p204.FUN_000111f0() > 0.0f) {
                    f.p188.x = f.p204.x - f.p216.x;
                    f.p188.y = f.p204.y - f.p216.y;
                    f.p188.z = f.p204.z - f.p216.z;
                    f.p216.FUN_00011160(Yp->FUN_0003ebb0(1), &f.p188);
                }
                if (f.p216.FUN_000111f0() > 0.0f) {
                    FUN_00014210(f20->fb0, Yp, e, &f.out);
                    f.l252 = FUN_00224f10(&f.out);
                    f.p204 = f.p216;
                    FUN_00224d70(f.l252, &f.p204);
                    p->FUN_001d86d0(&f.p204, a8);
                }
                RefObj *r = Yp->FUN_00035ef0(f20->f14);
                if (r != 0 && (Pad *)r != p)
                    DAT_004dd700->f34->FUN_001ecc80(Yp, (Pad *)p, r, &f20->f50);
                Queue *q3 = f20->f38;
                if (q3) {
                    f.req.FUN_00059820();
                    f.req.target = *a8;
                    f.req.aim = *a12;
                    f.req.f78 = f.l248;
                    f.req.b44 = (f.flag == 0);
                    Job *job = FUN_0008d690(0xb0);
                    if (job)
                        job = job->FUN_000598e0(f1c->f08, &f.req);
                    job->v0();
                    Handle *hd = q3->Submit(job, 0);
                    if (hd) {
                        if (!f.Y->s0dc.FUN_00231e80(hd))
                            hd->FUN_00231ad0(&f.Y->s0dc, job, -1);
                    }
                    job->v1();
                    f.req.FUN_00059300();
                }
            }
        }
    }
        if (f2c == 1 && f24->f0c == 5) {
            Pad *p = (Pad *)f24->f08;
            float amount = f20->fc8;
            if (amount < 0.0f)
                amount = f.l248 * 0.5f;
            p->FUN_001d6ec0((int)amount, f.Y->f12c, 1);
        }
    } while (0);
    FUN_00266da0(f.token);
}
