// STATUS: equivalent (tools/equiv.py level 3: 20114 inputs, branch coverage 121/124, incomplete)
// FUN_001b1710 @ 0x001b1710
// FUN_001b1710 @ 0x001b1710
// equiv-conv: FUN_001b0470 eax ecx stack
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl _sprintf(char *, const char *, ...);

struct V3_1b1710 {
    float x, y, z;
    void FUN_00011160(float s, V3_1b1710 *u);
};

struct Id64_1b1710 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
    void FUN_0027af50();
};

struct Body_1b1710;

struct Obj70_1b1710 {
    void FUN_0016fc90(V3_1b1710 *out);
};

struct Thing_1b1710 {
    char pad0[8];
    Body_1b1710 *f8;
    int fc;
    char pad10[0x50 - 0x10];
    V3_1b1710 f50;
    char pad5c[0x6c - 0x5c];
    int f6c;
    Obj70_1b1710 *f70;
};

struct Thing114 {
    char pad0[8];
    struct Thing114b *f8;
    int fc;
};
struct Thing114b {
    char pad0[8];
    unsigned int f8;
    unsigned int fc;
};

struct Sub1a4_1b1710 {
    char pad[0x25];
    char FUN_001b6e90(Thing_1b1710 *t);
    void FUN_001b6e60(Thing_1b1710 *t);
};

struct Sub11c_1b1710 {
    unsigned __int64 FUN_000443c0();
    char pad[0x14];
    int f14;
};

struct Reg_1b1710 {
    char FUN_00079950(void *name);
    int FUN_00079800(void *name);
    void FUN_0007ba60(int i);
    float FUN_0007a820(int i);
    int FUN_0007ad00(void *name);
};

struct F58 {
    float FUN_00086080();
};

struct R_1b1710 {
    unsigned int FUN_0027b200(unsigned int lo, unsigned int hi);
};
struct Q_1b1710 {
    char pad0[8];
    R_1b1710 *f8;
};
struct P_1b1710 {
    char pad0[0x64];
    Q_1b1710 *f64;
};
struct Obj10_1b1710 {
    P_1b1710 *FUN_00059a40();
};

struct Obj124_1b1710 {
    char pad0[0x12c];
    Thing_1b1710 *f12c;
};
struct F20_1b1710 {
    char pad0[0x124];
    Obj124_1b1710 *f124;
};
struct F34 {
    void FUN_001ebd80(Body_1b1710 *b, const char *name, float v, int z);
};

struct World {
    char pad0[0x20];
    F20_1b1710 *f20;
    char pad24[0x34 - 0x24];
    F34 *f34;
    char pad38[0x4c - 0x38];
    Reg_1b1710 *f4c;
    char pad50[0x58 - 0x50];
    F58 *f58;
};

struct Obj5Z {
    int FUN_001d5e80(int a);
};

struct Obj134 {
    int FUN_0001b510(Thing_1b1710 *a, V3_1b1710 *b, V3_1b1710 *c, int d);
};

struct Body_1b1710 {
    char pad0[8];
    char name8[8];
    Obj10_1b1710 *f10;
    char pad14[0x40 - 0x14];
    int f40;
    char pad44[0xa0 - 0x44];
    Thing_1b1710 *fa0;
    char pad_a4[0xec - 0xa4];
    Obj5Z *fec;
    char pad_f0[0x114 - 0xf0];
    Thing114 *f114;
    int f118;
    Sub11c_1b1710 *f11c;
    char pad120[0x128 - 0x120];
    Body_1b1710 *f128;
    Thing_1b1710 *f12c;
    char pad130[0x134 - 0x130];
    Obj134 *f134;
    char pad138[0x148 - 0x138];
    Body_1b1710 *f148;
    char b14c;
    char b14d;
    char pad14e[0x1a4 - 0x14e];
    Sub1a4_1b1710 s1a4;
    char b1c9;
    char pad1ca[0x1ed - 0x1ca];
    char b1ed;
    char pad1ee[0x1fc - 0x1ee];
    int f1fc;
    char pad200[0x334 - 0x200];
    Body_1b1710 *f334;
    Body_1b1710 *f338;
    char pad33c[0x1b88 - 0x33c];
    float f1b88;
    char pad1b8c[0x1ced - 0x1b8c];
    unsigned char b1ced;
    char pad1cee[0x1e50 - 0x1cee];
    Thing_1b1710 *f1e50;
    float f1e54;
    char pad1e58[0x20b0 - 0x1e58];
    int f20b0;

    Thing_1b1710 *FUN_001d72e0();
    char FUN_000373d0();
    char FUN_001d6a80();
    void FUN_001d7510();
    void FUN_001d6ec0(int a, Thing_1b1710 *b, int c);
    Body_1b1710 *FUN_00035ef0(int i);
    int FUN_00035f40();
    void FUN_0003acf0(int a, Body_1b1710 *b, unsigned int c, int d, int e, int f);
    char FUN_001d6640();
    void FUN_00043ae0(Thing_1b1710 *a, V3_1b1710 *w, float f1, int z1, float f2, float f3, float f4, int z2, int z3);
    void FUN_00038e80(Thing_1b1710 *a, Thing_1b1710 *b, int m, V3_1b1710 *c, V3_1b1710 *d, float e);
    int FUN_001da540(Thing_1b1710 *a, V3_1b1710 *b, V3_1b1710 *c, float d);
    void FUN_000350c0(V3_1b1710 *out);
    void FUN_001d66b0(V3_1b1710 *a, V3_1b1710 *b);
    void FUN_001d8cd0();
    void FUN_001d8d90(int a);
    char FUN_001b02c0();
    void FUN_0027d4f0(int a);
};

struct Handler_1b1710 {
    char FUN_001b15b0(Body_1b1710 *a, Body_1b1710 *b);
    int FUN_001b1710(Thing_1b1710 *a0, Thing_1b1710 *a1, Thing_1b1710 *a2, V3_1b1710 *a3, V3_1b1710 *a4, float a5);
};


float FUN_001b0470(Body_1b1710 *s, Body_1b1710 *d, V3_1b1710 *w);

struct Frame_1b1710 {
    char pad0[3];
    char b3;            // 0x03
    V3_1b1710 u;               // 0x04
    Id64_1b1710 id;            // 0x10 (id.lo doubles as the result)
    Body_1b1710 *p148;         // 0x18
    float f1c;          // 0x1c
    V3_1b1710 w;               // 0x20
    Handler_1b1710 *self;      // 0x2c
    char buf[0x80];     // 0x30
    unsigned int cookie; // 0xb0
};

int Handler_1b1710::FUN_001b1710(Thing_1b1710 *a0, Thing_1b1710 *a1, Thing_1b1710 *a2, V3_1b1710 *a3, V3_1b1710 *a4, float a5)
{
    Frame_1b1710 f;
    int i;

    f.cookie = DAT_004d9968;
    f.self = this;
    if ((*(char*)&DAT_004e1804) && a5 > 0.0f) {
        __security_check_cookie(f.cookie);
        return 0;
    }
    Body_1b1710 *S = a2->f8;
    Body_1b1710 *D = a1->f8;
    if (DAT_004dd700)
        D->f1b88 = DAT_004dd700->f58->FUN_00086080();
    if (D->f128 && a0 != D->f128->FUN_001d72e0()) {
        __security_check_cookie(f.cookie);
        return 1;
    }
    D->FUN_000373d0();
    unsigned __int64 id = D->f11c->FUN_000443c0();
    if ((unsigned int)id == (*(unsigned int*)&DAT_004dc060) && (unsigned int)(id >> 32) == (*(unsigned int*)((char*)&DAT_004dc060 + 4))) {
        __security_check_cookie(f.cookie);
        return 1;
    }
    if (S->FUN_001d6a80()) {
        __security_check_cookie(f.cookie);
        return 1;
    }

    if (S->b14c) {
        if (S->FUN_001d72e0()->f6c == 0) {
            Reg_1b1710 *reg = DAT_004dd700->f4c;
            if (reg->FUN_00079950(S->name8)) {
                S->FUN_001d7510();
                int slot = reg->FUN_00079800(S->name8);
                if (slot != -1) {
                    reg->FUN_0007ba60(slot);
                    if (reg->FUN_0007a820(slot) > DAT_004c3734)
                        S->FUN_001d6ec0((int)DAT_004c3730, a1, 0);
                }
            }
        }
    }
    if (S->b14d) {
        if (S->FUN_001d72e0()->f6c == 0) {
            if (DAT_004dd700->f4c->FUN_0007ad00(S->name8) != 0)
                goto ret1;
        }
    }
    if (D->f20b0 != 0)
        goto ret1;
    for (i = 0; i < 8; i++) {
        if (D->FUN_00035ef0(i) == S)
            goto ret1;
    }
    Body_1b1710 *b334 = D->f334;
    if (b334) {
        for (i = 0; i < 8; i++) {
            if (b334->FUN_00035ef0(i) == S)
                goto ret1;
        }
    }
    if (S->b1ed) {
        f.id.lo = D->b1ced;
        if ((float)(int)f.id.lo != 0.0f) {
            P_1b1710 *pp = D->f10->FUN_00059a40();
            f.id.FUN_0027af00();
            if (pp != 0) {
                Q_1b1710 *q = pp->f64;
                if (q != 0) {
                    if (D->FUN_00035f40() + 1 < 8) {
                        int n = D->FUN_00035f40() + 1;
                        _sprintf(f.buf, "%s%d", "object_shield_", n);
                        f.id.FUN_0027b040(f.buf);
                        unsigned int r = q->f8->FUN_0027b200(f.id.lo, f.id.hi);
                        D->FUN_0003acf0(D->FUN_00035f40() + 1, S, r, 0, 0, 0);
                        f.id.FUN_0027af50();
                        __security_check_cookie(f.cookie);
                        return 1;
                    }
                }
            }
            f.id.FUN_0027af50();
        }
    }
    if (D->f128 && D->f128->FUN_001d72e0() == a2)
        goto ret1;
    f.p148 = 0;
    if (S->f148 != 0) {
        f.p148 = S->f148;
        if (D->f338 == S->f148)
            goto ret1;
        if (S->f148->f338 == D)
            goto ret1;
    }
    {
        Thing_1b1710 *ebx = D->f12c;
        Thing114 *p114 = S->f114;
        if ((Thing_1b1710 *)p114 == ebx)
            goto ret1;
        if (D->f1e50 == a2) {
            if (D->f1e54 > 0.0f)
                goto ret1;
        }
        if (S->f134 != 0) {
            S->f134->FUN_0001b510(ebx, a3, a4, 2);
            __security_check_cookie(f.cookie);
            return 1;
        }
        if (p114 != 0 && p114->fc == 1 && p114->f8->f8 == (*(unsigned int*)&DAT_004dc0e0) && p114->f8->fc == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4))) {
            __security_check_cookie(f.cookie);
            return 1;
        }
    }
    {
        Thing_1b1710 *A1 = a1;
        f.b3 = S->s1a4.FUN_001b6e90(A1);
        if (S->FUN_001d6640() && *(unsigned int *)&D->name8 == (*(unsigned int*)&DAT_004dc0e0) && *(unsigned int *)&D->name8[4] == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4))) {
            if (f.b3)
                goto ret1;
            S->s1a4.FUN_001b6e60(A1);
            f.w.x = a3->x;
            f.w.y = a3->y;
            f.w.z = a3->z;
            D->FUN_00043ae0(a2, &f.w, (*(float*)&DAT_0048e06c), 0, (*(float*)&DAT_0048e070), DAT_004e1808, DAT_004e180c, 0, 0);
            if ((*(char*)&DAT_004c37f4))
                D->FUN_00038e80(a0, a2, -1, a3, a4, a5);
            goto ret1;
        }
        f.u.x = a2->f50.x;
        f.u.y = a2->f50.y;
        f.u.z = a2->f50.z;
        if (!(f.u.y < 0.0f))
            f.u.y = 0.0f;
        f.id.lo = 0;
        if (S->b1c9 && f.u.z * f.u.z + f.u.x * f.u.x + f.u.y * f.u.y > 25.0f) {
            if (!f.b3) {
                bool done = false;
                if (S->FUN_001b02c0()) {
                    f.id.lo = S->FUN_001da540(A1, a3, a4, a5);
                    done = true;
                } else if (A1 == (Thing_1b1710 *)S->f1fc || A1 == (Thing_1b1710 *)S->f118) {
                    done = true;
                } else {
                    if (S->fec->FUN_001d5e80(S->f40) == 2) {
                        F20_1b1710 *o20 = DAT_004dd700->f20;
                        if (o20->f124 && o20->f124->f12c == A1)
                            done = true;
                    }
                    if (!done) {
                        f.w.x = 0.0f;
                        f.w.y = 0.0f;
                        f.w.z = 0.0f;
                        D->FUN_000350c0(&f.w);
                        f.u.x = 0.0f;
                        f.u.y = 0.0f;
                        f.u.z = 0.0f;
                        if (a2->f70) {
                            a2->f70->FUN_0016fc90(&f.u);
                        } else {
                            f.u.x = a2->f50.x;
                            f.u.y = a2->f50.y;
                            f.u.z = a2->f50.z;
                        }
                        f.w.FUN_00011160(-1.0f, &f.u);
                        f.f1c = FUN_001b0470(S, D, &f.w);
                        if (f.f1c > 0.0f)
                            S->FUN_001d66b0(a3, a4);
                        if (D->f11c->f14) {
                            S->FUN_001d6ec0((int)f.f1c, (Thing_1b1710 *)S->f118, 0);
                            S->FUN_001d8cd0();
                            S->FUN_001d8d90(0);
                        } else {
                            S->FUN_001d6ec0((int)(f.f1c * 0.25f), (Thing_1b1710 *)S->f118, 0);
                        }
                        DAT_004dd700->f34->FUN_001ebd80((Body_1b1710 *)S, "Bounce", 100.0f, 0);
                    }
                }
                S->s1a4.FUN_001b6e60(A1);
            }
            if ((int)A1 == S->f118)
                goto ret1;
        }
        D->FUN_00038e80(a0, a2, -1, a3, a4, a5);
        if (f.p148 != 0) {
            f.u.x = a4->x * -1.0f;
            f.u.y = a4->y * -1.0f;
            f.u.z = a4->z * -1.0f;
            f.p148->FUN_00038e80(A1, A1, -1, a3, &f.u, a5);
        }
        if (D->FUN_000373d0()) {
            if (!f.self->FUN_001b15b0((Body_1b1710 *)D, (Body_1b1710 *)S))
                goto ret1;
        }
        S->FUN_0027d4f0(7);
        __security_check_cookie(f.cookie);
        return f.id.lo;
    }
ret1:
    __security_check_cookie(f.cookie);
    return 1;
}
