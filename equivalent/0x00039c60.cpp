// STATUS: equivalent (tools/equiv.py level 3: 19400 inputs, branch coverage 118/150, incomplete)
// FUN_00039c60 @ 0x00039c60
// equiv-conv: FUN_00035e70 eax stack
// equiv-dead: +0x59 not taken, +0x405 not taken: a2 < 0 (or NaN) cannot also be > 2pi; ii < 100 with bestRank >= 100 is skipped at +0x26e before +0x405
#include "compat/ptr.h"
#include "decls/address.h"
extern "C" double cos(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    float FUN_000111f0();
};

struct HitObj {
    char pad0[0x10];
    int f10;
};

struct Sub11c {
    char pad0[0x1a0];
    float f1a0;
};

struct Sub8 {
    char pad0[0x40];
    int f40;
    char pad44[0x11c - 0x44];
    Sub11c *p11c;
    HitObj *FUN_001d75c0(int idx);
};

struct Thing {
    char pad0[8];
    Sub8 *p8;
    int type;
    char pad10[8];
    int f18;
    float FUN_002ef420();
};

struct Ray {
    char FUN_00201e00(V3 *from, V3 *to, int one, V3 *outA, V3 *outB, int z1, int *hit);
};

struct Cam {
    V3 *FUN_001c39d0();
};
Cam *FUN_001c3d90();

struct List {
    int **begin;
    int **end;
};
struct ListOwner {
    List *FUN_002ed700();
};
struct Mid {
    char pad0[8];
    ListOwner *p8;
};
struct World {
    char pad0[0x10];
    Mid *p10;
    char pad14[0x24 - 0x14];
    Ray *p24;
};

Thing *__cdecl FUN_000969d0(int a);
char FUN_00035e70(Thing *t, float score);
float __cdecl FUN_00224f10(V3 *v);
float __cdecl FUN_00224fc0(float a, float b);

struct Frame {
    char pad0[3];
    char flag;          // 0x03
    float dot;          // 0x04
    float score;        // 0x08
    float bestDot;      // 0x0c
    float bestScore;    // 0x10
    V3 w;               // 0x14
    int ii;             // 0x20
    V3 e;               // 0x24
    V3 v88;             // 0x30
    V3 d;               // 0x3c
    int q70;            // 0x48
    int count;          // 0x4c
    void *best;         // 0x50
    V3 h;               // 0x54
    void *thisSpill;    // 0x60
    List *list;         // 0x64
    int index;          // 0x68
    V3 ww;              // 0x6c
    V3 v40;             // 0x78
    float cs;           // 0x84
    float t30;          // 0x88
    Ray *ray;           // 0x8c
    float t28;          // 0x90
    V3 r24;             // 0x94
    V3 o18;             // 0xa0
    V3 oc;              // 0xac
};

class Picker {
public:
    char pad0[8];
    Picker *f8;
    int fc;
    char pad10[0x80 - 0x10];
    V3 v80;
    char pad8c[0x11c - 0x8c];
    void *f11c;
    void FUN_000350c0(V3 *out);
    void FUN_00035550(V3 *out);
    float FUN_000354c0();
    char FUN_00039440(Thing *t, V3 *out, int *score, int flag);
    Thing *FUN_00039c60(V3 *a0, V3 *a1, float a2, float a3, int a4, Thing **a5, float a6);
};

Thing *Picker::FUN_00039c60(V3 *a0, V3 *a1, float a2, float a3, int a4, Thing **a5, float a6)
{
    Frame f;
    int bestRank;

    f.thisSpill = this;
    if (f11c == 0)
        return 0;

    float c;
    if (a2 >= 0.0f) {
        if (a2 <= 6.2831854820251465f)
            c = a2;
        else
            c = 6.2831854820251465f;
    } else {
        c = 0.0f;
    }
    f.v88.x = 0.0f;
    f.v88.y = 0.0f;
    f.v88.z = 0.0f;
    f.cs = (float)cos((double)(c * 0.5f));
    FUN_000350c0(&f.v88);

    f.v40.x = v80.x;
    f.v40.y = v80.y;
    f.v40.z = v80.z;
    hulk_freg len = f.v40.FUN_0022d110();
    float m;
    if (len <= 0.0f) {
        FUN_00035550(&f.v40);
        m = 1.0f;
    } else if (len < 1.0f) {
        m = 1.0f;
    } else {
        m = len;
    }
    hulk_freg hh = m * 0.5f;
    f.w.x = f.v40.x;
    f.w.y = f.v40.y;
    f.w.z = f.v40.z;
    World *hub = DAT_004dd700;
    f.w.y = f.w.y * hh;
    f.best = 0;
    f.w.z = f.w.z * hh;
    f.bestScore = 3.4028234663852886e+38f;
    bestRank = (int)0x80000000;
    f.bestDot = -1.0f;
    f.flag = 0;
    f.v88.x = f.v88.x + f.w.x * hh;
    f.v88.y = f.w.y + f.v88.y;
    f.v88.z = f.w.z + f.v88.z;
    f.ray = hub->p24;
    f.list = hub->p10->p8->FUN_002ed700();
    if (f.list == 0)
        return (Thing *)f.best;

    f.count = (int)(f.list->end - f.list->begin);
    for (f.index = 0; f.index < f.count; f.index++) {
        int *item = f.list->begin[f.index];
        if (item == 0)
            continue;
        Thing *th = FUN_000969d0(item[6]);
        if (th == 0)
            continue;
        if (th == (Thing *)f.best)
            continue;
        if (a5 != 0) {
            Thing **p = a5;
            Thing *x = *p;
            bool excluded = false;
            while (x != 0) {
                if (th == x) {
                    excluded = true;
                    break;
                }
                x = p[1];
                p++;
            }
            if (excluded)
                continue;
        }

        f.w.x = 0.0f;
        f.w.y = 0.0f;
        f.w.z = 0.0f;
        f.ii = (int)0x80000000;
        if (!FUN_00039440(th, &f.w, &f.ii, 1))
            continue;
        if (f.ii < a4)
            continue;
        if (bestRank >= 100 && f.ii < 100)
            continue;

        f.d.x = f.w.x - f.v88.x;
        f.d.y = f.w.y - f.v88.y;
        f.d.z = f.w.z - f.v88.z;
        if (f.d.y > 0.0f)
            f.d.y = f.d.y * 0.5f;
        f.dot = f.d.FUN_00018990();
        double sc = f.dot - th->FUN_002ef420() * 0.3333333432674408f;
        f.score = (float)sc;
        if (sc > a3)
            continue;

        f.e.x = f.w.x - a0->x;
        f.e.y = f.w.y - a0->y;
        f.e.z = f.w.z - a0->z;
        f.e.FUN_0022d110();
        double dd = f.e.z * a1->z + f.e.y * a1->y + f.e.x * a1->x;
        f.dot = (float)dd;
        if (dd < f.cs)
            continue;

        if (a6 > 0.0f) {
            f.t30 = FUN_00224f10(&f.e);
            f.t28 = FUN_000354c0();
            if (FUN_00224fc0(f.t28, f.t30) > a6)
                continue;
        }

        // verdict: 0 skip, 1 accept
        int verdict = 1;
        int target;   // 0 = 0x415, 1 = 0x51d
        int ii = f.ii;
        if (ii < 100) {
            if (f.dot <= 0.0f)
                continue;
            target = (bestRank >= 100) ? 1 : 0;
        } else {
            target = (bestRank < 100) ? 1 : 0;
        }
        if (target == 0) {
            do {
                if (f.score < 15.0f && f.bestScore >= 15.0f) {
                    if (ii >= 104 || bestRank < 104)
                        break;
                }
                if (f.score >= 15.0f && f.bestScore < 15.0f) {
                    if (ii < 104 || bestRank >= 104) {
                        verdict = 0;
                        break;
                    }
                }
                if (f.dot > 0.7071067690849304f) {
                    if (f.bestDot < 0.7071067690849304f)
                        break;
                }
                if (f.score < 50.0f && f.bestScore >= 50.0f)
                    break;
                if (!f.flag) {
                    if (f.dot < 0.7071067690849304f && f.bestDot > 0.7071067690849304f) {
                        verdict = 0;
                        break;
                    }
                    if (f.score >= 50.0f && f.bestScore < 50.0f) {
                        verdict = 0;
                        break;
                    }
                }
                target = 1;
            } while (0);
        }
        if (target == 1) {
            if (ii > bestRank) {
                verdict = 1;
            } else if (ii != bestRank) {
                verdict = 0;
            } else {
                bool toTie = true;      // reach 0x599
                if (f.dot >= 0.0f && f.bestDot < 0.0f) {
                    verdict = 1;
                    toTie = false;
                } else if (f.dot < 0.0f && f.bestDot < 0.0f) {
                    toTie = true;
                } else if (f.dot < 0.0f || !(f.dot >= 0.0f) || f.bestDot < 0.0f || !(f.bestDot >= 0.0f)) {
                    verdict = 0;
                    toTie = false;
                }
                if (toTie)
                    verdict = (f.score < f.bestScore) ? 1 : 0;
            }
        }
        if (!verdict)
            continue;

        char bl = 0;
        if (FUN_00035e70(th, f.score)) {
            V3 *cp = FUN_001c3d90()->FUN_001c39d0();
            f.r24.x = cp->x;
            f.r24.y = cp->y;
            f.r24.z = cp->z;
            f.ww.x = f.w.x;
            f.ww.y = f.w.y;
            f.ww.z = f.w.z;
            f.q70 = 0;
            if (th->type == 1 && th->p8 && th->p8->p11c)
                f.ww.y = f.ww.y + th->p8->p11c->f1a0;
            bl = f.ray->FUN_00201e00(&f.r24, &f.ww, 1, &f.o18, &f.oc, 0, &f.q70);
            if (bl) {
                f.h.x = f.o18.x - f.ww.x;
                f.h.y = f.o18.y - f.ww.y;
                f.h.z = f.o18.z - f.ww.z;
                if (f.h.FUN_000111f0() < 100.0f) {
                    bl = 0;
                } else {
                    bool store = false;
                    if (f.q70 && th->type == 5 && th->p8) {
                        HitObj *ho = th->p8->FUN_001d75c0(th->p8->f40);
                        if (ho && ho->f10 == f.q70) {
                            bl = 0;
                            store = true;
                        }
                    }
                    if (!store) {
                        if (f.score >= 100.0f || !(f.score < 100.0f))
                            continue;
                        if (ii >= 100 && bestRank < 100) {
                            store = true;
                        } else {
                            if (!f.flag)
                                continue;
                            if (ii < bestRank)
                                continue;
                            if (f.dot < 0.0f && !(f.bestDot < 0.0f))
                                continue;
                            if (f.dot < 0.7071067690849304f && !(f.bestDot < 0.7071067690849304f))
                                continue;
                            if (!(f.score < f.bestScore))
                                continue;
                            store = true;
                        }
                    }
                }
            }
        }
        f.best = th;
        f.bestScore = f.score;
        f.bestDot = f.dot;
        bestRank = ii;
        f.flag = bl;
    }
    return (Thing *)f.best;
}
