// STATUS: equivalent (tools/equiv.py level 3: 3108 inputs, branch coverage 76/76)
// hulkfight::motion::ProjectileGroundShockwave::vfunc_6 @ 0x00199060
// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
#include "decls/address.h"
#include "decls/data/game/global.h"
struct V3_199060 {
    float x, y, z;
    float FUN_0022d110();
};

struct Name_199060 {
    unsigned int lo, hi;
};

struct Mat4_199060 {
    float m[16];
    void FUN_0022b980();
};

struct HitInfo_199060 {
    char pad0[8];
    V3_199060 pos;
    char pad14[0x28 - 0x14];
    V3_199060 ref;
    char pad34[0x64 - 0x34];
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
    char pad7c[0x90 - 0x7c];
    char b90;
    char pad91[3];
    void FUN_00059820();
    void FUN_00059300();
};

class Ref_199060 {
public:
    virtual void v0();
    virtual void v1();
};

struct Req_199060 {
    void FUN_00083320(V3_199060 *a, int b, int c, int d, V3_199060 *e, int f);
};
struct Hub4c_199060 {
    Req_199060 *FUN_0007ad00(void *p);
};

struct Fx_199060 {
    int FUN_00283a40(Name_199060 *id, Mat4_199060 *m, float a, float b);
};
Fx_199060 *FUN_0027f250();

struct Holder_199060 {
    float FUN_001dddf0();
};

struct Obj18_199060 {
    char pad0[0x38];
    float f38;
    char pad3c[0x74 - 0x3c];
    int f74;
    float f78;
    float f7c;
    V3_199060 v80;
    V3_199060 v8c;
    int f98;
    char pad9c[0xa8 - 0x9c];
    Name_199060 ida8;
};

struct Pad24 {
    char pad0[0x40];
    V3_199060 v40;
};

struct Info11c {
    char pad0[0x1b0];
    int f1b0;
};

class Ent_199060 {
public:
    char pad0[0x108];
    int f108;
    char pad10c[0x148 - 0x10c];
    void *f148;
    char pad14c[0x14d - 0x14c];
    char b14d;
    char pad14e[0x198 - 0x14e];
    int f198;
    float f19c;
    struct Sub6c *FUN_001d72e0();
    void FUN_001d82d0();
    char FUN_001d6ec0(int dmg, void *a, int b);
    void FUN_0027d4f0(int a);
    void FUN_001d86d0(V3_199060 *v, V3_199060 *hit);
};
struct Sub6c {
    char pad0[0x6c];
    void *f6c;
};

struct Own_199060 {
    char pad0[0x11c];
    Info11c *p11c;
    char pad120[0x12c - 0x120];
    void *f12c;
    Ent_199060 *FUN_00035ef0(int i);
};

struct Pool44 {
    Own_199060 *FUN_00059c10(int id);
};
struct World {
    char pad0[0xc];
    Holder_199060 *pc;
    char pad10[0x44 - 0x10];
    Pool44 *p44;
    char pad48[4];
    Hub4c_199060 *p4c;
};

struct IdHolder_199060 {
    char pad0[8];
    unsigned int lo;
    unsigned int hi;
};

class Thing_199060 {
public:
    char pad0[8];
    void *owner;
    int type;
    char pad10[0x74 - 0x10];
    IdHolder_199060 *p74;
};

struct Carried {
    char pad0[0x12c];
    Own_199060 *f12c;
};

struct OwnerObj_199060 {
    char pad0[0x10];
    int f10;
    struct Obj8_199060 *FUN_00081420x();
};
struct Obj8_199060 {
    void FUN_00081420(HitInfo_199060 *h);
};

class Other_199060 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    char pad04[0x38 - 4];
    int f38;
    Ent_199060 *f3c;
};

int FUN_00266da0(int mode);
void FUN_00224d70(float angle, V3_199060 *v);
float FUN_00224f10(V3_199060 *v);
char FUN_00195560(V3_199060 *pn, void *own, V3_199060 *b, int f1c, int f98, int z0, int a4, int Tbits, int f78, int f20, int f74,
                  int z1, float one, int z2);
extern "C" int __cdecl FUN_0034483c();

class ProjectileGroundShockwave {
public:
    char pad0[0xc];
    float f0c;
    char pad10[8];
    Obj18_199060 *p18;
    int f1c;
    float f20;
    Pad24 *p24;
    V3_199060 v28;
    char pad34[0x3c - 0x34];
    Ref_199060 *objs[32];
    int idx;
    char F(Thing_199060 *a1, Other_199060 *a2, V3_199060 *a3, int a4, int a5);
};

static void PlayEffect(ProjectileGroundShockwave *self, Mat4_199060 &M, V3_199060 *a3)
{
    if (self->p18->ida8.lo | self->p18->ida8.hi) {
        M.FUN_0022b980();
        float *t = &M.m[12];
        V3_199060 hit = *a3;
        t[0] = hit.x;
        t[1] = hit.y;
        t[2] = hit.z;
        Fx_199060 *fx = FUN_0027f250();
        fx->FUN_00283a40(&self->p18->ida8, &M, -1.0f, 1.0f);
    }
}

char ProjectileGroundShockwave::F(Thing_199060 *a1, Other_199060 *a2, V3_199060 *a3, int a4, int a5)
{
    struct Frame {
        float T;
        float f14;
        V3_199060 Q;
        int old;
        V3_199060 P;
        Mat4_199060 M;
        HitInfo_199060 X;
    } fr;
    int old = FUN_00266da0(0xd);
    fr.old = old;
    do {
        if (f0c < 0.0f)
            break;
        V3_199060 W0 = p24->v40;
        if (a3->y < W0.y)
            break;
        if (a3->y - W0.y > p18->f38)
            break;
        void *ebx = a1;
        Ent_199060 *edi = 0;
        if (a1->p74->lo == DAT_004e2198 && a1->p74->hi == (*(unsigned int*)&DAT_004e219c)) {
            if (a2->v6() == 4) {
                if (a2->f38 != 5)
                    break;
                edi = a2->f3c;
                ebx = edi->FUN_001d72e0();
            }
        }
        bool found = false;
        for (int i = 0; i < 32; i++) {
            if (objs[i] == (Ref_199060 *)ebx) {
                found = true;
                break;
            }
        }
        if (found)
            break;
        Ref_199060 **slot = &objs[idx];
        if (ebx)
            ((Ref_199060 *)ebx)->v0();
        if (*slot)
            (*slot)->v1();
        *slot = (Ref_199060 *)ebx;
        idx = (idx + 1) % 32;
        Own_199060 *own = DAT_004dd700->p44->FUN_00059c10(f1c);
        if (own && own->f12c == ebx)
            break;
        Obj18_199060 *o18 = p18;
        fr.T = o18->f78;
        if (o18->f7c > 0.0f)
            fr.T = (o18->f7c - fr.T) * f20 + fr.T;
        fr.P = o18->v80;
        fr.Q = o18->v8c;
        if (fr.Q.z * fr.Q.z + fr.Q.y * fr.Q.y + fr.Q.x * fr.Q.x > 0.0f) {
            fr.f14 = f20;
            float dx = fr.Q.x - fr.P.x;
            float dy = fr.Q.y - fr.P.y;
            float dz = fr.Q.z - fr.P.z;
            fr.P.x = dx * f20 + fr.P.x;
            fr.P.y = dy * f20 + fr.P.y;
            fr.P.z = dz * f20 + fr.P.z;
        }
        bool carried = false;
        void *carriedObj = 0;
        if (edi == 0) {
            int ty = ((Thing_199060 *)ebx)->type;
            bool toEdi = false;
            if (ty == 5) {
                edi = (Ent_199060 *)((Thing_199060 *)ebx)->owner;
                if (edi)
                    toEdi = true;
            }
            if (!toEdi) {
                if (ty == 1) {
                    carriedObj = ((Thing_199060 *)ebx)->owner;
                    if (!carriedObj)
                        break;
                    carried = true;
                } else if (ty == 7) {
                    OwnerObj_199060 *oo = (OwnerObj_199060 *)((Thing_199060 *)ebx)->owner;
                    if (oo->f10 == 5)
                        break;
                    fr.X.FUN_00059820();
                    fr.X.pos.x = a3->x;
                    fr.X.pos.y = a3->y;
                    fr.X.pos.z = a3->z;
                    fr.X.ref.x = fr.P.x;
                    fr.X.ref.y = fr.P.y;
                    fr.X.ref.z = fr.P.z;
                    fr.X.f78 = 1.0f;
                    fr.X.f64 = 30.0f;
                    fr.X.b90 = 1;
                    ((Obj8_199060 *)oo)->FUN_00081420(&fr.X);
                    fr.X.FUN_00059300();
                    break;
                } else {
                    break;
                }
            }
        }
        if (!carried) {
            void *f148 = edi->f148;
            if (f148 != 0) {
                carriedObj = f148;
                carried = true;
            }
        }
        if (carried) {
            fr.Q = fr.P;
            fr.T = fr.Q.FUN_0022d110();
            float ang = FUN_00224f10(&v28);
            FUN_00224d70(ang, &fr.Q);
            Obj18_199060 *o = p18;
            char r = FUN_00195560(&fr.Q, ((Carried *)carriedObj)->f12c, a3, f1c, o->f98, 0, a4, *(int *)&fr.T,
                                  *(int *)&o->f78, *(int *)&f20, o->f74, 0, 1.0f, 0);
            if (r)
                PlayEffect(this, fr.M, a3);
            break;
        }
        if (own) {
            bool same = false;
            for (int b = 0; b < 8; b++) {
                if (own->FUN_00035ef0(b) == edi) {
                    same = true;
                    break;
                }
            }
            if (same)
                break;
        }
        edi->FUN_001d82d0();
        void *ownerF12c = 0;
        if (own) {
            int k = own->p11c->f1b0;
            if (edi->f198 == k)
                fr.T = fr.T * edi->f19c;
            if (k == 2)
                fr.T = DAT_004dd700->pc->FUN_001dddf0() * fr.T;
            ownerF12c = own->f12c;
        }
        char hit = edi->FUN_001d6ec0((int)fr.T, ownerF12c, 0);
        if (hit) {
            if (edi->f108 > 0)
                edi->FUN_0027d4f0(1);
        }
        PlayEffect(this, fr.M, a3);
        if (edi->b14d) {
            Sub6c *ev = edi->FUN_001d72e0();
            if (ev->f6c == 0) {
                Req_199060 *r = DAT_004dd700->p4c->FUN_0007ad00((char *)edi + 8);
                if (!r)
                    break;
                V3_199060 V = p18->v80;
                r->FUN_00083320(a3, a4, a5, 1, &V, 0);
                break;
            }
        }
        float ang = FUN_00224f10(&v28);
        FUN_00224d70(ang, &fr.P);
        edi->FUN_001d86d0(&fr.P, a3);
    } while (0);
    FUN_00266da0(old);
    return 1;
}
