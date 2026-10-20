// STATUS: equivalent (tools/equiv.py level 3: 20039 inputs, branch coverage 63/80, incomplete)
// FUN_001ae450 @ 0x001ae450
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"

extern "C" double sqrt(double);

struct Vec3_1ae450 {
    float x, y, z;
};

struct Plane_1ae450 {
    float x, y, d;
    void FUN_001acfa0(const Vec3_1ae450 *a, const Vec3_1ae450 *b) throw();
};

struct Box_1ae450 {
    Vec3_1ae450 mn;
    Vec3_1ae450 mx;
};

struct Seg_1ae450 {
    Vec3_1ae450 a, b;
    void FUN_0022fe40(Box_1ae450 *out) throw();
};

struct Elem_1ae450 {
    int f0;
    int f4;
    Vec3_1ae450 v;
};

struct Owner_1ae450 {
    void FUN_001b5760(int a) throw();
    Vec3_1ae450 *FUN_001b56a0(int a, int b) throw();
};

struct Cont {
    char pad00[4];
    Elem_1ae450 *begin;
    Elem_1ae450 *end;
    char pad0c[8];
    Owner_1ae450 *owner;
};

union Arg1 {
    Cont *c;
    float t;
};

union Arg3 {
    char flag;
    Elem_1ae450 *cur;
    unsigned int bits;
    unsigned char flags[4];
};


int __stdcall FUN_001ae450(Arg1 a1, Vec3_1ae450 *out, Arg3 a3, int a4)
{
    union Frame {
        Plane_1ae450 D;
        Seg_1ae450 s23;
    } f23;
    Seg_1ae450 s45;
    Box_1ae450 b1;
    Box_1ae450 b2;

    Owner_1ae450 *O = a1.c->owner;
    if (a3.flag)
        return 0;
    Elem_1ae450 *begin = a1.c->begin;
    Elem_1ae450 *end = a1.c->end;
    if ((unsigned int)(end - begin) <= 1) {
        *out = begin->v;
        return 0;
    }
    Elem_1ae450 *end2 = a1.c->end;
    Elem_1ae450 *last = end2 - 1;
    hulk_uintptr n2 = end2 - begin;
    Elem_1ae450 *start = begin;
    if (n2 > 5)
        start = end - 5;
    a3.cur = start;
    bool toEnd = false;
    bool to140 = false;
    if (start == last) {
        toEnd = true;
    } else {
        for (;;) {
            f23.D.FUN_001acfa0(&last->v, &a3.cur->v);
            if (a3.cur == last) {
                toEnd = true;
                break;
            }
            a1.t = -f23.D.d;
            Elem_1ae450 *cur = a3.cur;
            for (;;) {
                O->FUN_001b5760(cur->f0);
                Vec3_1ae450 *p1 = O->FUN_001b56a0(cur[1].f0, cur->f4);
                Vec3_1ae450 *p2 = O->FUN_001b56a0(cur[1].f0, ((signed char*)&DAT_0041d7f8)[cur->f4]);
                bool s1 = f23.D.y * p1->z + f23.D.x * p1->x < a1.t;
                bool s2 = f23.D.y * p2->z + f23.D.x * p2->x < a1.t;
                if (s1 == s2)
                    break;
                cur = cur + 1;
                if (cur == last) {
                    to140 = true;
                    break;
                }
            }
            if (to140)
                break;
            if (cur == last) {
                to140 = true;
                break;
            }
            Elem_1ae450 *n = a3.cur + 1;
            a3.cur = n;
            if (n == last) {
                toEnd = true;
                break;
            }
        }
    }
    if (!toEnd && a3.cur == last)
        toEnd = true;
    if (toEnd) {
        int k = last[-1].f4;
        Vec3_1ae450 *A = O->FUN_001b56a0(last->f0, k);
        Vec3_1ae450 *B = O->FUN_001b56a0(last->f0, ((signed char*)&DAT_0041d7f8)[k]);
        volatile float ys = B->y + A->y;
        volatile float zs = B->z + A->z;
        out->x = (B->x + A->x) * 0.5f;
        out->y = ys * 0.5f;
        out->z = zs * 0.5f;
        return 0;
    }
    Elem_1ae450 *c0 = a3.cur;
    if (c0->f4 < 0) {
        *out = c0->v;
        return 0;
    }
    int k4 = a4;
    if (k4 < 0) {
        *out = c0->v;
        return 0;
    }
    if (!((*(unsigned char*)((char*)&DAT_004e17c0 + 48)) & 1))
        (*(unsigned char*)((char*)&DAT_004e17c0 + 48)) |= 1;
    a3.bits = 0;
    Vec3_1ae450 *r = O->FUN_001b56a0(last->f0, k4);
    ((Vec3_1ae450*)&DAT_004e17c0)[0] = *r;
    Vec3_1ae450 *r2 = O->FUN_001b56a0(last->f0, ((signed char*)&DAT_0041d7f8)[k4]);
    ((Vec3_1ae450*)&DAT_004e17c0)[1] = *r2;
    s45.a = ((Vec3_1ae450*)&DAT_004e17c0)[0];
    s45.b = ((Vec3_1ae450*)&DAT_004e17c0)[1];
    Vec3_1ae450 *r3 = O->FUN_001b56a0(c0->f0, c0->f4);
    ((Vec3_1ae450*)&DAT_004e17c0)[2] = *r3;
    Vec3_1ae450 *r4 = O->FUN_001b56a0(c0->f0, ((signed char*)&DAT_0041d7f8)[c0->f4]);
    ((Vec3_1ae450*)&DAT_004e17c0)[3] = *r4;
    f23.s23.a = ((Vec3_1ae450*)&DAT_004e17c0)[2];
    f23.s23.b = ((Vec3_1ae450*)&DAT_004e17c0)[3];
    for (int i = 0; i < 4; i++) {
        f23.s23.FUN_0022fe40(&b1);
        s45.FUN_0022fe40(&b2);
        const Vec3_1ae450 &p = ((Vec3_1ae450*)&DAT_004e17c0)[i];
        bool in1 = p.x >= b1.mn.x && p.x <= b1.mx.x && p.y >= b1.mn.y && p.y <= b1.mx.y && p.z >= b1.mn.z && p.z <= b1.mx.z;
        bool in2 = p.x >= b2.mn.x && p.x <= b2.mx.x && p.y >= b2.mn.y && p.y <= b2.mx.y && p.z >= b2.mn.z && p.z <= b2.mx.z;
        if (in1 && in2)
            a3.flags[i] = 1;
    }
    int bi = -1;
    int bj = -1;
    a1.t = 0.0f;
    for (int j = 0; j < 4; j++) {
        if (j == 0)
            continue;
        if (a3.flags[j] && a3.flags[0]) {
            double dx = ((Vec3_1ae450*)&DAT_004e17c0)[j].x - ((Vec3_1ae450*)&DAT_004e17c0)[0].x;
            double dy = ((Vec3_1ae450*)&DAT_004e17c0)[j].y - ((Vec3_1ae450*)&DAT_004e17c0)[0].y;
            double dz = ((Vec3_1ae450*)&DAT_004e17c0)[j].z - ((Vec3_1ae450*)&DAT_004e17c0)[0].z;
            double d = sqrt(dz * dz + dy * dy + dx * dx);
            if (bi < 0 || d < a1.t) {
                a1.t = (float)d;
                bi = j;
                bj = 0;
            }
        }
    }
    if (bi < 0 || bj < 0) {
        *out = c0->v;
        return 0;
    }
    volatile float ys = ((Vec3_1ae450*)&DAT_004e17c0)[bj].y + ((Vec3_1ae450*)&DAT_004e17c0)[bi].y;
    volatile float zs = ((Vec3_1ae450*)&DAT_004e17c0)[bj].z + ((Vec3_1ae450*)&DAT_004e17c0)[bi].z;
    out->x = (((Vec3_1ae450*)&DAT_004e17c0)[bi].x + ((Vec3_1ae450*)&DAT_004e17c0)[bj].x) * 0.5f;
    out->y = ys * 0.5f;
    out->z = zs * 0.5f;
    return 0;
}
