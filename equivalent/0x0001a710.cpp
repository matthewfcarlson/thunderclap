// STATUS: equivalent (tools/equiv.py level 3: 3208 inputs, branch coverage 108/108)
// FUN_0001a710 @ 0x0001a710
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned __int64 u64;

struct V3 {
    float x, y, z;
    float FUN_000111f0();
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
    char pad14[4];
    V3 aim;                        // 0x18
    char pad24[0x44 - 0x24];
    unsigned char b44;
    char pad45[0x4c - 0x45];
    RefObj *f4c;
    RefObj *f50;
    char pad54[0x6c - 0x54];
    RefObj *f6c;
    int f70;
    char pad74[4];
    float f78;
    char pad7c[0x98 - 0x7c];
    void FUN_00059820();
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
    char pad18[0x1b0 - 0x18];
    int f1b0;
};

struct Player {
    char pad0[0xdc];
    Sink s0dc;
    char pade0[0x11c - 0xe0];
    Ctrl *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    float FUN_0003ebb0(int a);
    char FUN_00035c30(struct Item *it);
    void FUN_00035c70(struct Item *it);
};

struct Slot {
    char FUN_001d4e40();
    float FUN_001d4e90();
    u64 FUN_001d4f70();
};

struct Aux {
    char pad0[8];
    int f08;
    int f0c;
};

struct Pad {
    char pad0[0xec];
    Slot *fec;
    char padf0[0x108 - 0xf0];
    int f108;
    char pad10c[4];
    char b110;
    char pad111[3];
    Aux *f114;
    char pad118[0x148 - 0x118];
    int f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    float f19c;
    char FUN_001d6980();
    int FUN_001d64a0();
    RefObj *FUN_001d72e0();
    void FUN_001d86d0(V3 *a, V3 *b);
    char FUN_001d6ec0(int a, RefObj *b, int c);
    void FUN_0027d4f0(int a);
};

struct Target {
    char pad0[0x10];
    int f10;
};

struct Item : RefObj {
    int pad4;
    Pad *f08;
    int f0c;
};

struct Blob {
    int x;
};

struct Cfg {
    char pad0[0x30];
    int f30;
    int f34;
    char pad38[3];
    unsigned char b3b;
    char pad3c[0x44 - 0x3c];
    int f44;
    char pad48[0x58 - 0x48];
    Queue *f58;
    char pad5c[0x78 - 0x5c];
    Blob f78;
    char pad7c[0xd8 - 0x7c];
    int fd8;
    char pade0[0x352 - 0xdc];
    unsigned char b352;
    void FUN_00012f50(V3 *out);
    void FUN_00012f80(V3 *out);
};

struct Link {
    char pad0[8];
    Player *pl;
    int f0c;
};

struct Holder2 {
    char pad0[0x4c];
    Link *f4c;
};

struct Anchor {
    Player *FUN_00059a30();
    void FUN_00059a40();
};

struct Owner {
    virtual void o0(); virtual void o1(); virtual void o2();
    virtual Holder2 *o3();
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
    void FUN_001ecb60(Player *y, Pad *o, Blob *b);
};

struct World {
    char pad0[0xc];
    Scale *f0c;
    char pad10[0x20 - 0x10];
    struct JudgeCfg *f20;
    char pad24[0x30 - 0x24];
    Hud *f30;
    Runner *f34;
};

struct JudgeCfg {
    char pad0[0x352];
    unsigned char b352;
    char FUN_00024540(Player *y);
};


int __cdecl FUN_00266da0(int v);
Job *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj **slot, RefObj *obj);
void __cdecl FUN_000187a0(RefObj **slot, RefObj *obj);
void __cdecl FUN_00018840(int *slot, int v);
char __cdecl FUN_00044500(int v);
float __cdecl FUN_00224f10(V3 *v);
void __cdecl FUN_00224d70(float f, V3 *v);
// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Player *frame, RefObj *obj, V3 *out);

struct Frame {
    int slot0;                     // E-0xd4
    char pad4[3];
    unsigned char flag;            // E-0xcd
    int prev;                      // E-0xcc
    float l1c;                     // E-0xc8
    float l20;                     // E-0xc4
    Player *Y;                     // E-0xc0
    V3 l28;                        // E-0xbc
    V3 l34;                        // E-0xb0
    V3 l40;                        // E-0xa4
    Request req;            // E-0x98
};

#define SPAWN(ZQ, FLOATV, BYTEV, F4CV)                                      \
    f.req.FUN_00059820();                                                  \
    f.req.target = *arg2;                                                    \
    f.req.aim = *arg3;                                                       \
    FUN_000187a0(&f.req.f6c, f48);                                           \
    FUN_00018840(&f.req.f70, Y->s0dc.v);                                        \
    f.req.f78 = (FLOATV);                                                    \
    f.req.b44 = (BYTEV);                                                     \
    FUN_00018810(&f.req.f4c, (F4CV));                                        \
    FUN_00018810(&f.req.f50, arg1);                                          \
    Job *job = FUN_0008d690(0xb0);                                         \
    if (job)                                                               \
        job = job->FUN_000598e0(f1c->f08, &f.req);                           \
    job->v0();                                                             \
    Handle *hd = (ZQ)->Submit(job, 0);                                     \
    if (hd) {                                                              \
        Sink *sk = &Y->s0dc;                                        \
        if (!sk->FUN_00231e80(hd))                                         \
            hd->FUN_00231ad0(sk, job, -1);                                 \
    }                                                                      \
    job->v1();                                                             \
    f.req.FUN_00059300();

class SpawnAction {
public:
    char pad00[0x1c];
    Owner *f1c;
    Cfg *f20;
    char pad24[0x34 - 0x24];
    int f34;
    int f38;
    char pad3c[0x48 - 0x3c];
    RefObj *f48;

    void FUN_00019d30(Target *t, V3 *p1, V3 *p2);
    void FUN_00019470(int h, int z, V3 *p1, V3 *p2, float v);
    void FUN_00013f20(float k, Item *it, float *outA, float *outB);
    void FUN_0001a710(Item *arg1, V3 *arg2, V3 *arg3);
};

void SpawnAction::FUN_0001a710(Item *arg1, V3 *arg2, V3 *arg3)
{
    Player *Y0 = f1c->FUN_000592a0()->FUN_00059a30();
    if (!(Y0 != 0 && Y0->f11c != 0 && Y0->f11c->b10 != 0)) {
        Cfg *c = f20;
        if (c->f30 > 0 && f34 >= c->f30 && c->f34 > 0 && f38 >= c->f34)
            return;
    }

    Frame f;
    f.prev = FUN_00266da0(0xd);
    Anchor *an = f1c->FUN_000592a0();
    Player *Y = an->FUN_00059a30();
    f.Y = Y;
    do {
        if (DAT_004dd700->f20->FUN_00024540(Y))
            break;
        an->FUN_00059a40();
        if (Y->FUN_00035c30(arg1))
            break;
        Y->FUN_00035c70(arg1);

        if (arg1->f0c == 7) {
            Target *T = (Target *)arg1->f08;
            FUN_00019d30(T, arg2, arg3);
            if (T->f10 == 5)
                break;
            Queue *Z = f20->f58;
            if (Z == 0)
                break;
            SPAWN(Z, 1.0f, 0, Y->f12c)
        } else {
            Pad *O = arg1->f08;
            if (O->FUN_001d6980())
                break;
            if (f20->b3b != 0) {
                if (O->fec->FUN_001d4e40())
                    break;
            }
            int h = O->f148;
            float v = 1.0f;
            if (h == 0) {
                Aux *a = O->f114;
                if (a != 0 && a->f0c == 1) {
                    v = O->fec->FUN_001d4e90();
                    if (v > 0.0f && O->b110 == 0 && a->f08 != 0)
                        h = a->f08;
                }
            }
            if (h != 0) {
                FUN_00019470(h, 0, arg2, arg3, v);
                break;
            }
            if (f20->f44 == 2)
                break;
            Holder2 *pl = f1c->o3();
            Player *P = 0;
            if (pl != 0) {
                Link *lk = pl->f4c;
                if (lk != 0 && lk->f0c == 1)
                    P = lk->pl;
            }
            if (!DAT_004dd700->f20->b352)
                break;
            if (!FUN_00044500(Y->f11c->f14)) {
                if (P == 0)
                    break;
                if (!FUN_00044500(P->f11c->f14))
                    break;
            }
            if (O->FUN_001d64a0() == 4 || O->FUN_001d64a0() == 3) {
                Cfg *c = f20;
                int c34 = c->f34;
                int c30 = c->f30;
                if (!(c34 > 0 && f38 >= c34) && !(c30 > 0 && f34 >= c30)) {
                    f38++;
                    f34++;
                }
            } else {
                int c30 = f20->f30;
                if (!(c30 > 0 && f34 >= c30))
                    f34++;
            }
            FUN_00013f20(1.0f, arg1, &f.l1c, &f.l20);
            int k;
            if (P != 0)
                k = P->f11c->f1b0;
            else
                k = Y->f11c->f1b0;
            if (O->f198 == k)
                f.l1c = f.l1c * O->f19c;
            if (k == 2)
                f.l1c = DAT_004dd700->f0c->FUN_001dddf0() * f.l1c;
            RefObj *val;
            if (P != 0)
                val = P->f12c;
            else
                val = Y->f12c;
            f.flag = O->FUN_001d6ec0((int)f.l1c, val, 0);
            if (f.flag) {
                if (O->f108 > 0)
                    O->FUN_0027d4f0(1);
                DAT_004dd700->f34->FUN_001ecb60(Y, O, &f20->f78);
            }
            Cfg *cfg = f20;
            cfg->FUN_00012f50(&f.l34);
            cfg->FUN_00012f80(&f.l28);
            if (f.l28.FUN_000111f0() > 0.0f) {
                f.l40.x = f.l28.x - f.l34.x;
                f.l40.y = f.l28.y - f.l34.y;
                f.l40.z = f.l28.z - f.l34.z;
                f.l34.FUN_00011160(Y->FUN_0003ebb0(1), &f.l40);
            }
            if (O->FUN_001d72e0() != 0 && f.l34.FUN_000111f0() > 0.0f) {
                int m = f20->fd8;
                RefObj *q2 = O->FUN_001d72e0();
                FUN_00014210(m, Y, q2, &f.l40);
                float len = FUN_00224f10(&f.l40);
                f.l28.x = f.l34.x;
                f.l28.y = f.l34.y;
                f.l28.z = f.l34.z;
                FUN_00224d70(len, &f.l28);
                O->FUN_001d86d0(&f.l28, arg2);
                if (O->fec->FUN_001d4f70() == (*(u64*)&DAT_004dc030))
                    DAT_004dd700->f30->FUN_001cbd10("golf_stroke");
            }
            Queue *Z = f20->f58;
            if (Z == 0)
                break;
            SPAWN(Z, f.l1c, f.flag == 0, val)
        }
    } while (0);
    FUN_00266da0(f.prev);
}
