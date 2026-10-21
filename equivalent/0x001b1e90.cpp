// STATUS: equivalent (tools/equiv.py level 3: 20064 inputs, branch coverage 96/96)
// FUN_001b1e90 @ 0x001b1e90
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
typedef unsigned __int64 u64_1b1e90;

struct V3_1b1e90 {
    float x, y, z;
    float FUN_000111f0();
};

struct Actor_1b1e90;

struct Holder_1b1e90 {
    char pad0[8];
    Actor_1b1e90 *actor;                  // 8
    char pad0c[0x50 - 0xc];
    V3_1b1e90 v50;                        // 0x50
    char pad5c[0x6c - 0x5c];
    int f6c;
};

struct Sub_1b1e90 {
    char pad0[0x12c];
    Holder_1b1e90 *f12c;
    char pad130[0x1d4d - 0x130];
    unsigned char b1d4d;
};

struct Id_1b1e90 {
    char pad0[8];
    u64_1b1e90 id;                        // 8
};

struct Aux_1b1e90 {
    char pad0[8];
    Id_1b1e90 *f08;
    int f0c;
};

struct Eff_1b1e90 {
    void FUN_0001b510(Holder_1b1e90 *a, int b, V3_1b1e90 *dir, int mode);
};

struct Pos_1b1e90 {
    float x, y, z;
};

struct Actor_1b1e90 {
    char pad0[8];
    V3_1b1e90 v8;                         // 8
    char pad14[0x114 - 0x14];
    Aux_1b1e90 *f114;
    char pad118[0x134 - 0x118];
    Eff_1b1e90 *f134;
    char pad138[0x148 - 0x138];
    Sub_1b1e90 *f148;
    unsigned char b14c;
    unsigned char b14d;
    char pad14e[0x1c9 - 0x14e];
    unsigned char b1c9;
    char pad1ca[0x1ed - 0x1ca];
    unsigned char b1ed;
    char pad1ee[0x1fc - 0x1ee];
    int f1fc;

    int FUN_001da540(Holder_1b1e90 *h, int v, V3_1b1e90 *dir, float s);
    int FUN_001d82d0();
    float FUN_001afb00();
    void FUN_001d6ec0(int a, int b, int c);
    char FUN_001d6a80();
    char FUN_001d7300();
    Pos_1b1e90 *FUN_001d6b40();
    void FUN_001d7810(V3_1b1e90 p);
    void FUN_0027d4f0(int a);
    struct Part_1b1e90 *FUN_001d77c0();
};

struct Part_1b1e90 {
    float FUN_00018990();
};

struct Hit_1b1e90 {
    void FUN_00083320(int a, V3_1b1e90 *dir, float s, int flag, V3_1b1e90 *vec, int one);
};

struct Mon {
    float FUN_0007a820(int i);
    Hit_1b1e90 *FUN_0007ad00(V3_1b1e90 *p);
};

struct Fx_1b1e90 {
    void FUN_001ebd80(Actor_1b1e90 *a, const char *name, float v, int z);
};

struct World {
    char pad0[0x34];
    Fx_1b1e90 *f34;
    char pad38[0x4c - 0x38];
    Mon *f4c;
};

union Slot5_1b1e90 {
    V3_1b1e90 *dir;
    float mag;
    Mon *mon;
};

int __stdcall FUN_001aff50(Holder_1b1e90 *a1, Holder_1b1e90 *a2, Holder_1b1e90 *a3, Holder_1b1e90 *a4, int a5, int a6, V3_1b1e90 *a7, float a8);

class Self_1b1e90 {
public:
    int FUN_001b1710(Holder_1b1e90 *a1, Holder_1b1e90 *a2, Holder_1b1e90 *a3, int a4, V3_1b1e90 *a5, float a6);
    int FUN_001b1e90(Holder_1b1e90 *h1, Holder_1b1e90 *h2, int arg3, int arg4, Slot5_1b1e90 a5, float arg6);
};

struct Frame_1b1e90 {
    int result;                    // E-0x1c
    V3_1b1e90 n1;                         // E-0x18
    V3_1b1e90 n2;                         // E-0xc
};

int Self_1b1e90::FUN_001b1e90(Holder_1b1e90 *h1, Holder_1b1e90 *h2, int arg3, int arg4, Slot5_1b1e90 a5, float arg6)
{
    Frame_1b1e90 f;
    Actor_1b1e90 *B = h2->actor;
    Sub_1b1e90 *b148 = B->f148;
    Actor_1b1e90 *A = h1->actor;
    Sub_1b1e90 *a148 = A->f148;
    if (a148 != 0) {
        if (b148 != 0) {
            if (a148->b1d4d != 0 || b148->b1d4d != 0)
                return FUN_001aff50(h1, a148->f12c, h2, b148->f12c, arg3, arg4, a5.dir, arg6);
        } else {
            return FUN_001b1710(h1, a148->f12c, h2, arg3, a5.dir, arg6);
        }
    } else if (b148 != 0) {
        V3_1b1e90 *src = a5.dir;
        f.n1.x = src->x * -1.0f;
        f.n1.y = src->y * -1.0f;
        f.n1.z = src->z * -1.0f;
        return FUN_001b1710(h2, b148->f12c, h1, arg4, &f.n1, arg6);
    }

    f.result = 0;
    if (A->b1ed != 0) {
        if (B->b1ed != 0)
            return 1;
    }
    V3_1b1e90 *dir = a5.dir;
    if (A->b1c9 != 0 && A->f1fc != 0)
        f.result = A->FUN_001da540(h2, arg4, dir, arg6);
    if (B->b1c9 != 0 && B->f1fc != 0) {
        f.n1.x = dir->x * -1.0f;
        f.n1.y = dir->y * -1.0f;
        f.n1.z = dir->z * -1.0f;
        f.result = B->FUN_001da540(h1, arg3, &f.n1, arg6);
    }

    if (A->b14c != 0 || B->b14c != 0) {
        Mon *mon = DAT_004dd700->f4c;
        a5.mag = 0.0f;
        int ai = A->FUN_001d82d0();
        if (ai >= 0) {
            if (mon->FUN_0007a820(ai) > 15.0f)
                a5.mag = A->FUN_001afb00();
        }
        int bi = B->FUN_001d82d0();
        if (bi >= 0) {
            if (mon->FUN_0007a820(bi) > 15.0f)
                a5.mag = B->FUN_001afb00();
        }
        if (a5.mag > 0.0f) {
            int m = (int)a5.mag;
            A->FUN_001d6ec0(m, 0, 0);
            B->FUN_001d6ec0(m, 0, 0);
        }
    }

    if (A->b14d != 0 || B->b14d != 0) {
        a5.mon = DAT_004dd700->f4c;
        if (A->b14d != 0 && h1->f6c == 0) {
            Hit_1b1e90 *q = a5.mon->FUN_0007ad00(&A->v8);
            if (q != 0) {
                if (h2->v50.FUN_000111f0() > 16.0f && B->b14d == 0)
                    q->FUN_00083320(arg3, dir, arg6, 1, &h2->v50, 1);
                else {
                    f.n1.x = 0.0f;
                    f.n1.y = 0.0f;
                    f.n1.z = 0.0f;
                    q->FUN_00083320(arg3, dir, arg6, 0, &f.n1, 1);
                }
            }
        }
        if (B->b14d != 0 && h2->f6c == 0) {
            Hit_1b1e90 *q = a5.mon->FUN_0007ad00(&B->v8);
            if (q != 0) {
                if (h1->v50.FUN_000111f0() > 16.0f && A->b14d == 0) {
                    f.n1.x = -dir->x;
                    f.n1.y = -dir->y;
                    f.n1.z = -dir->z;
                    q->FUN_00083320(arg4, &f.n1, arg6, 1, &h1->v50, 1);
                } else {
                    f.n2.x = -dir->x;
                    f.n2.y = -dir->y;
                    f.n2.z = -dir->z;
                    f.n1.x = 0.0f;
                    f.n1.y = 0.0f;
                    f.n1.z = 0.0f;
                    q->FUN_00083320(arg4, &f.n2, arg6, 0, &f.n1, 1);
                }
            }
        }
    }

    if (A->FUN_001d6a80() && B->FUN_001d6a80())
        return 1;
    if (A->FUN_001d6a80()) {
        if (B->FUN_001d7300()) {
            f.n1.x = dir->x * arg6;
            f.n1.y = dir->y * arg6;
            f.n1.z = dir->z * arg6;
            Pos_1b1e90 *p = B->FUN_001d6b40();
            V3_1b1e90 t;
            t.x = f.n1.x + p->x;
            t.y = f.n1.y + p->y;
            t.z = f.n1.z + p->z;
            B->FUN_001d7810(t);
        }
        return 1;
    }
    if (B->FUN_001d6a80()) {
        if (A->FUN_001d7300()) {
            hulk_freg ns = -arg6;
            f.n1.x = dir->x * ns;
            f.n1.y = dir->y * ns;
            f.n1.z = dir->z * ns;
            Pos_1b1e90 *p = A->FUN_001d6b40();
            V3_1b1e90 t;
            t.x = f.n1.x + p->x;
            t.y = f.n1.y + p->y;
            t.z = f.n1.z + p->z;
            A->FUN_001d7810(t);
        }
        return 1;
    }

    if (A->f134 != 0)
        A->f134->FUN_0001b510(h2, arg4, dir, 2);
    if (B->f134 != 0) {
        f.n1.x = dir->x * -1.0f;
        f.n1.y = dir->y * -1.0f;
        f.n1.z = dir->z * -1.0f;
        B->f134->FUN_0001b510(h1, arg3, &f.n1, 2);
    }
    u64_1b1e90 want = (*(u64_1b1e90*)&DAT_004dc0e0);
    if (A->f114 != 0 && A->f114->f0c == 1 && A->f114->f08->id == want)
        return 1;
    if (B->f114 != 0 && B->f114->f0c == 1 && B->f114->f08->id == want)
        return 1;
    A->FUN_0027d4f0(7);
    B->FUN_0027d4f0(7);
    if (A->FUN_001d77c0()->FUN_00018990() > 5.0f)
        DAT_004dd700->f34->FUN_001ebd80(A, "impact_sml", 100.0f, 0);
    if (B->FUN_001d77c0()->FUN_00018990() > 5.0f)
        DAT_004dd700->f34->FUN_001ebd80(B, "impact_sml", 100.0f, 0);
    return f.result;
}
