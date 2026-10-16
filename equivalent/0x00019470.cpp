// STATUS: equivalent (tools/equiv.py level 3: 3083 inputs, branch coverage 99/100, incomplete)
// FUN_00019470 @ 0x00019470
#include "decls/address.h"
extern int DAT_004dc0e0;
extern int DAT_004dc0e4;

struct Vec3_19470 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_000111f0();
    void FUN_00011160(float s, const Vec3_19470 *d);
};

struct RefObj_19470 {
    virtual void AddRef();
    virtual void Release();
};

struct Mat;

struct Request {
    int r00;
    int r04;
    Vec3_19470 target;
    char pad14[4];
    Vec3_19470 aim;
    unsigned char flag24;
    char pad25[0x38 - 0x25];
    Vec3_19470 v38;
    char pad44[4];
    int w48;
    RefObj_19470 *ref;
    RefObj_19470 *ref50;
    int r54;
    float r58;
    char pad5c[0x68 - 0x5c];
    float r68;
    int r6c;
    int r70;
    int f74;
    int r78;
    float f7c;
    float f80;
    char pad84[0x91 - 0x84];
    unsigned char r91;
    char pad92[0xb0 - 0x92];
    Request *FUN_00059820();
    void FUN_000595f0(Vec3_19470 *v, float a, float b, float c);
    void FUN_00059300();
    Request *FUN_000598e0(RefObj_19470 *r, Request *src);
};

struct Chooser_19470 {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual RefObj_19470 *v8(RefObj_19470 *r, int z);
};

struct Params {
    char pad00[0x30];
    int f30;
    int f34;
    char b38;
    char pad39[2];
    unsigned char b3b;
    char pad3c[0x44 - 0x3c];
    int f44;
    char pad48[0x4c - 0x48];
    Chooser_19470 *f4c;
    char pad50[0x58 - 0x50];
    Chooser_19470 *f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    int f6c;
    char pad70[0x78 - 0x70];
    char s78[0x20];
    char pad98[0xd8 - 0x98];
    int mode;
    int fdc;
    char pade0[0xec - 0xe0];
    int fec;
    unsigned char bf0;
    char padf1[3];
    float ff4;
    float ff8;
    float ffc;
    float f100;
    float f104;
    unsigned char b108;
    char pad109[3];
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    void FUN_00012f50(Vec3_19470 *out);
    void FUN_00012f80(Vec3_19470 *out);
    void FUN_00012fd0(Vec3_19470 *out);
};

struct Slot231 {
    void FUN_00231ad0(void *key, RefObj_19470 *r, int v);
};

struct Key231 {
    char FUN_00231e80(void *res);
};

struct Gear_19470 {
    char pad00[0x14];
    int f14;
    char pad18[4];
    float f1c;
    char pad20[0x1b0 - 0x20];
    int f1b0;
    __int64 FUN_000443c0();
};

struct Tracker_19470 {
    char pad00[0x34];
    char b34;
    char pad35[0x4c - 0x35];
    RefObj_19470 *f4c;
};

struct Holder10_19470 { RefObj_19470 *first; };

struct Fighter128_19470 {
    void FUN_001d86d0(Vec3_19470 *a, Vec3_19470 *b);
};

struct Fighter_19470 {
    char pad00[0x10];
    Holder10_19470 *f10;
    char pad14[0xdc - 0x14];
    int fdc;
    char pad_e0[0x11c - 0xe0];
    Gear_19470 *f11c;
    char pad120[0x128 - 0x120];
    Fighter128_19470 *f128;
    RefObj_19470 *f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x334 - 0x32c];
    Fighter_19470 *f334;
    Fighter_19470 *f338;
    char pad33c[0x390 - 0x33c];
    Fighter_19470 *f390;
    char pad394[0x20b0 - 0x394];
    int f20b0;
    void FUN_00035230(Vec3_19470 *out);
    char FUN_0003a590(void *world, Fighter_19470 *t);
    float FUN_0003ebb0(int a);
    char FUN_000373d0();
    char FUN_000360f0();
    char FUN_000437a0(Gear_19470 *g, Request *req, int a, int b, int c);
    char FUN_00043350(int a, RefObj_19470 *b, int c, float d, int e, int f);
    void FUN_00035b70(float x, float a, float b);
    void FUN_0003ffa0(RefObj_19470 *o, int z);
    void FUN_00035c70(RefObj_19470 *o);
};

struct Anchor_19470 {
    Fighter_19470 *FUN_00059a30();
    void FUN_00059a50(Vec3_19470 *out);
};

struct Owner_19470 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Tracker_19470 *v3();
    char pad04[4];
    RefObj_19470 *f8;
    Anchor_19470 *FUN_000592a0();
};

struct Fx_19470 {
    void FUN_001eca40(Fighter_19470 *a, Fighter_19470 *b, const char *s);
};
struct World {
    char pad00[0x34];
    Fx_19470 *f34;
};

void *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj_19470 **slot, RefObj_19470 *obj);
void __cdecl FUN_000187a0(void *slot, int v);
void __cdecl FUN_00018840(void *slot, int v);
void __cdecl FUN_00096a90(RefObj_19470 *obj, Vec3_19470 *out);
float __cdecl FUN_00224f10(Mat *m);
void __cdecl FUN_00224d70(float angle, Vec3_19470 *axis);
char __cdecl FUN_000444f0(int v);
float __cdecl FUN_000445a0();
float __cdecl FUN_000445b0();
float __cdecl FUN_000964e0();
// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Fighter_19470 *frame, void *obj, Vec3_19470 *out);

struct Frame_19470 {
    float d;                // 0x00
    union {                 // 0x04
        Gear_19470 *attGear;
        int outA;
        int lim34;
        Chooser_19470 *nod;
    } slot14;
    union { int gm; float angle; Chooser_19470 *nod; } u08;   // 0x08
    float fc;               // 0x0c (outB / fc)
    float fa;               // 0x10
    union { float fb; Gear_19470 *tg; } u14;   // 0x14
    Fighter_19470 *att;           // 0x18
    World *world;           // 0x1c
    Vec3_19470 delta;             // 0x20
    Vec3_19470 A;                 // 0x2c
    Vec3_19470 hp;                // 0x38
    Vec3_19470 Bv;                // 0x44
    Vec3_19470 B;                 // 0x50
    Request req;            // 0x5c .. 0x10c
    Vec3_19470 outv;              // 0x10c
};

class Attack {
public:
    char pad00[0x1c];
    Owner_19470 *owner;
    Params *params;
    char pad24[0x34 - 0x24];
    int f34;
    int f38;
    int pad3c;
    float f40;
    float f44;
    int f48;
    void FUN_00013f20(int a, RefObj_19470 *b, int *outA, int *outB);
    void FUN_00019470(Fighter_19470 *t, int a2, Vec3_19470 *P, Vec3_19470 *N, int a5);
};

void Attack::FUN_00019470(Fighter_19470 *t, int a2, Vec3_19470 *P, Vec3_19470 *N, int a5)
{
    Frame_19470 f;
    if (params->f44 == 1)
        return;
    Anchor_19470 *anchor = owner->FUN_000592a0();
    f.att = anchor->FUN_00059a30();
    Fighter_19470 *&att = f.att;
    f.world = DAT_004dd700;
    World *&world = f.world;
    if (t == att || t == 0 || t->f20b0 != 0 || t == att->f338 || t == att->f334 || t == att->f390)
        return;
    f.slot14.attGear = att->f11c;
    Gear_19470 *&attGear = f.slot14.attGear;
    if (!att->FUN_0003a590(world, t))
        return;
    Vec3_19470 *p1 = (Vec3_19470 *)((char *)&f.req + 0x98);    // scratch vectors overlay the not yet built request
    p1->x = 0;
    p1->y = 0;
    p1->z = 0;
    anchor->FUN_00059a50(p1);
    Vec3_19470 *p2 = (Vec3_19470 *)((char *)&f.req + 0xa4);
    p2->x = 0;
    p2->y = 0;
    p2->z = 0;
    att->FUN_00035230(p2);
    f.u14.tg = t->f11c;
    Gear_19470 *tg = f.u14.tg;
    if (!tg)
        return;
    Params *pr = params;
    if (pr->b38 || pr->b3b) {
        if (attGear->f1b0 == tg->f1b0)
            return;
    }
    if (tg->f14 != 0) {
        int lim38 = pr->f34;
        f.slot14.lim34 = pr->f30;
        __int64 id = tg->FUN_000443c0();
        if (!((unsigned int)id == (unsigned int)DAT_004dc0e0 && (unsigned int)(id >> 32) == (unsigned int)DAT_004dc0e4)) {
            if (lim38 > 0 && f38 >= lim38)
                return;
            if (f.slot14.lim34 > 0 && f34 >= f.slot14.lim34)
                return;
        }
        f38++;
    } else {
        if (pr->f30 > 0 && f34 >= pr->f30)
            return;
    }
    f34++;
    FUN_00013f20(a5, t->f12c, &f.slot14.outA, (int *)&f.fc);
    int &outA = f.slot14.outA;

    Tracker_19470 *trk = owner->v3();
    Request &req = f.req;
    req.FUN_00059820();
    if (trk && trk->b34)
        FUN_00018810(&req.ref, trk->f4c);
    else
        FUN_00018810(&req.ref, att->f12c);
    FUN_00018810(&req.ref50, t->f12c);
    FUN_000187a0(&req.r6c, f48);
    FUN_00018840(&req.r70, att->fdc);
    pr = params;
    if (pr->fec == 0)
        req.f74 = a2;
    else
        req.f74 = pr->fec;

    Vec3_19470 &hp = f.hp;
    hp.x = P->x;
    hp.y = P->y;
    hp.z = P->z;
    FUN_00096a90(t->f12c, &hp);
    req.target.x = (P->x + hp.x) * 0.5f;
    req.target.y = (P->y + hp.y) * 0.5f;
    req.target.z = (P->z + hp.z) * 0.5f;
    Vec3_19470 &delta = f.delta;
    delta.x = req.target.x - P->x;
    delta.y = req.target.y - P->y;
    delta.z = req.target.z - P->z;
    if (delta.FUN_0022d110() > 1.0f) {
        req.target.x = P->x;
        req.target.y = P->y;
        req.target.z = P->z;
        req.target.FUN_00011160(1.0f, &delta);
    }
    req.aim = *N;
    pr = params;
    req.r00 = pr->f68;
    req.r04 = pr->f6c;
    req.r91 = pr->b3b;
    req.r54 = pr->fdc;
    Vec3_19470 &outv = f.outv;
    FUN_00014210(pr->mode, att, t->f12c, &outv);

    Params *pp = params;
    Vec3_19470 &A = f.A;
    pp->FUN_00012f50(&A);
    Vec3_19470 &B = f.B;
    pp->FUN_00012f80(&B);
    if (B.FUN_000111f0() > 0.0f) {
        float tt = att->FUN_0003ebb0(1);
        Vec3_19470 &Bv = f.Bv;
        Bv.x = B.x - A.x;
        Bv.y = B.y - A.y;
        Bv.z = B.z - A.z;
        A.FUN_00011160(tt, &Bv);
    }
    f.u08.angle = FUN_00224f10((Mat *)&outv);
    FUN_00224d70(f.u08.angle, &A);
    req.v38 = A;
    req.f7c = att->FUN_0003ebb0(1);
    req.f80 = f.fc;
    f.u08.gm = tg->f14;
    int gm = f.u08.gm;
    float &fa = f.fa;
    float &fb = f.u14.fb;
    float &fc = f.fc;
    float &d = f.d;
    if (FUN_000444f0(gm)) {
        pp = params;
        req.flag24 = pp->bf0;
        req.r58 = pp->ff4;
        req.r68 = pp->f104;
        fa = pp->ffc;
        fc = pp->ff8;
        fb = pp->f100;
        d = tg->f1c;
        d = FUN_000445a0() / d;
    } else {
        pp = params;
        if (gm == 1) {
            req.flag24 = pp->b108;
            req.r58 = pp->f10c;
            req.r68 = pp->f11c;
            fa = pp->f114;
            fc = pp->f110;
            fb = pp->f118;
        } else {
            req.flag24 = 0;
            req.r58 = 0;
            req.r68 = 0;
            fa = 0;
            fc = 0;
            fb = 0;
        }
        d = tg->f1c;
        d = FUN_000445b0() / d;
    }
    if (req.r58 < 0.0f)
        req.r58 = -(FUN_000964e0() * req.r58);
    if (req.r68 < 0.0f)
        req.r68 = -(FUN_000964e0() * req.r68);
    req.r78 = outA;
    if (fa <= 0.0f)
        fa = req.r58;
    req.FUN_000595f0(&outv, d * fc, d * fa, d * fb);

    if (!t->FUN_000373d0()) {
        Fighter128_19470 *f128 = t->f128;
        if (f128) {
            if (A.FUN_000111f0() > 0.0f)
                f128->FUN_001d86d0(&A, P);
        }
    }
    if (t->FUN_000360f0()) {
        if (req.r91 == 0 || gm == 2 || gm == 3) {
            t->FUN_00043350(req.r78, req.ref, req.w48, req.f80, 0, *(int *)&req.r91);
            goto L7fd;
        }
    }
    {
        f.u08.nod = params->f4c;
        bool found = false;
        if (f.u08.nod) {
            Request *np = (Request *)FUN_0008d690(0xb0);
            RefObj_19470 *ns = np ? (RefObj_19470 *)np->FUN_000598e0(t->f10->first, &req) : 0;
            ns->AddRef();
            RefObj_19470 *fo = f.u08.nod->v8(ns, 0);
            if (fo)
                ((Slot231 *)fo)->FUN_00231ad0(&t->fdc, ns, -1);
            ns->Release();
            if (fo)
                found = true;
        }
        if (found) {
            world->f34->FUN_001eca40(att, t, params->s78);
        } else {
            char al = t->FUN_000437a0((Gear_19470 *)f.slot14.outA, &req, 0, 0, 0);
            const char *snd = params->s78;
            if (snd && *snd) {
                if (al)
                    world->f34->FUN_001eca40(att, t, snd);
                else
                    world->f34->FUN_001eca40(att, t, "whiff");
            }
        }
    }
    {
        params->FUN_00012fd0(&f.Bv);
        t->FUN_00035b70(f.Bv.x, f40, f44);
        f40 = f40 * 0.75f;
        f44 = f44 * 0.75f;
    }
L7fd:
    {
        f.slot14.nod = params->f58;
        if (f.slot14.nod) {
            Request *np = (Request *)FUN_0008d690(0xb0);
            RefObj_19470 *ns = np ? (RefObj_19470 *)np->FUN_000598e0(owner->f8, &req) : 0;
            ns->AddRef();
            RefObj_19470 *fo = f.slot14.nod->v8(ns, 0);
            if (fo) {
                if (!((Key231 *)&att->fdc)->FUN_00231e80(fo))
                    ((Slot231 *)fo)->FUN_00231ad0(&att->fdc, ns, -1);
            }
            ns->Release();
        }
    }
    if (att->f328 == 0)
        att->FUN_0003ffa0(t->f12c, 0);
    att->FUN_00035c70(t->f12c);
    req.FUN_00059300();
}
