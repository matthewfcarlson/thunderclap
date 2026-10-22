// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 42/42)
// FUN_002c8a80 @ 0x002c8a80
#include "compat/ptr.h"

struct V3 { float x, y, z; };

struct Mat4 { float m[16]; };

struct Pal {
    char pad00[8];
    Mat4 *mats;
};

struct Map {
    char pad00[8];
    int *idx;
};

struct Sub {
    char pad00[0x10];
    V3 *f10;
    V3 *f14;
};

// rotate (no translation) with the upper 3x3 of the matrix
#define ROT_X(M, x, y, z) ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0])
#define ROT_Y(M, x, y, z) ((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1])
#define ROT_Z(M, x, y, z) ((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2])
// transform with translation
#define XF_X(M, x, y, z) ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12])
#define XF_Y(M, x, y, z) ((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13])
#define XF_Z(M, x, y, z) ((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14])

// the original re-reads the base pointer and every source component for each output component
#define PTR(m) (*(V3 * volatile *)&(m))
#define VF(x) (*(volatile float *)&(x))

struct Skin {
    char pad00[0xc];
    unsigned int count;
    char pad10[0x18 - 0x10];
    V3 *f18;
    V3 *f1c;
    V3 *f20;
    V3 *f24;
    V3 *f28;
    V3 *f2c;
    V3 *f30;
    V3 *f34;
    char pad38[0x50 - 0x38];
    unsigned char (*bones)[4];
    float (*weights)[3];
    Sub *sub;
    void Apply(Pal *a, Map *b);
};

void Skin::Apply(Pal *a, Map *b)
{
    V3 *off10 = sub->f10;
    V3 *off14 = sub->f14;
    unsigned int i;

    if (f1c) {
        if (off14) {
            for (i = 0; i < *(volatile unsigned int *)&count; i++) {
                Mat4 *M = &a->mats[b->idx[bones[i][0]]];
                hulk_freg x = off14[i].x + f1c[i].x;
                hulk_freg y = off14[i].y + f1c[i].y;
                hulk_freg z = f1c[i].z + off14[i].z;
                PTR(f24)[i].x = ROT_X(M, x, y, z);
                PTR(f24)[i].y = ROT_Y(M, x, y, z);
                PTR(f24)[i].z = ROT_Z(M, x, y, z);
            }
        } else {
            for (i = 0; i < *(volatile unsigned int *)&count; i++) {
                Mat4 *M = &a->mats[b->idx[bones[i][0]]];
                PTR(f24)[i].x = ROT_X(M, VF(PTR(f1c)[i].x), VF(PTR(f1c)[i].y), VF(PTR(f1c)[i].z));
                PTR(f24)[i].y = ROT_Y(M, VF(PTR(f1c)[i].x), VF(PTR(f1c)[i].y), VF(PTR(f1c)[i].z));
                PTR(f24)[i].z = ROT_Z(M, VF(PTR(f1c)[i].x), VF(PTR(f1c)[i].y), VF(PTR(f1c)[i].z));
            }
        }
    }

    if (off10) {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            float x = f18[i].x + off10[i].x;
            float y = f18[i].y + off10[i].y;
            float z = f18[i].z + off10[i].z;
            float w0;
            if (weights)
                w0 = weights[i][0];
            else
                w0 = 1.0f;
            double rx = ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12]) * w0;
            volatile float ry = (float)(((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13]) * w0);
            volatile float rz = (float)(((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14]) * w0);
            if (!(w0 == 1.0f)) {
                float w1 = weights[i][1];
                Mat4 *M1 = &a->mats[b->idx[bones[i][1]]];
                double ax = rx + ((z) * (M1)->m[8] + (y) * (M1)->m[4] + (x) * (M1)->m[0] + (M1)->m[12]) * w1;
                double ay = ((z) * (M1)->m[9] + (y) * (M1)->m[5] + (x) * (M1)->m[1] + (M1)->m[13]) * w1 + ry;
                rz = (float)(((z) * (M1)->m[10] + (y) * (M1)->m[6] + (x) * (M1)->m[2] + (M1)->m[14]) * w1 + rz);
                float w2 = weights[i][2];
                Mat4 *M2 = &a->mats[b->idx[bones[i][2]]];
                volatile float bx = (float)(((z) * (M2)->m[8] + (y) * (M2)->m[4] + (x) * (M2)->m[0] + (M2)->m[12]) * w2 + ax);
                ry = (float)(((z) * (M2)->m[9] + (y) * (M2)->m[5] + (x) * (M2)->m[1] + (M2)->m[13]) * w2 + ay);
                rz = (float)(((z) * (M2)->m[10] + (y) * (M2)->m[6] + (x) * (M2)->m[2] + (M2)->m[14]) * w2 + rz);
                float w3 = (float)(1.0f - (weights[i][2] + weights[i][0] + weights[i][1]));
                Mat4 *M3 = &a->mats[b->idx[bones[i][3]]];
                rx = ((z) * (M3)->m[8] + (y) * (M3)->m[4] + (x) * (M3)->m[0] + (M3)->m[12]) * w3 + bx;
                ry = (float)(((z) * (M3)->m[9] + (y) * (M3)->m[5] + (x) * (M3)->m[1] + (M3)->m[13]) * w3 + ry);
                rz = (float)(((z) * (M3)->m[10] + (y) * (M3)->m[6] + (x) * (M3)->m[2] + (M3)->m[14]) * w3 + rz);
            }
            V3 *dst3 = f20;
            dst3[i].x = (float)rx;
            dst3[i].y = ry;
            dst3[i].z = rz;
        }
    } else {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            float w0;
            if (weights)
                w0 = weights[i][0];
            else
                w0 = 1.0f;
            float x = f18[i].x, y = f18[i].y, z = f18[i].z;
            double rx = ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12]) * w0;
            volatile float ry = (float)(((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13]) * w0);
            volatile float rz = (float)(((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14]) * w0);
            if (!(w0 == 1.0f)) {
                float w1 = weights[i][1];
                Mat4 *M1 = &a->mats[b->idx[bones[i][1]]];
                double ax = rx + ((z) * (M1)->m[8] + (y) * (M1)->m[4] + (x) * (M1)->m[0] + (M1)->m[12]) * w1;
                double ay = ((z) * (M1)->m[9] + (x) * (M1)->m[1] + (y) * (M1)->m[5] + (M1)->m[13]) * w1 + ry;
                rz = (float)(((z) * (M1)->m[10] + (x) * (M1)->m[2] + (y) * (M1)->m[6] + (M1)->m[14]) * w1 + rz);
                float w2 = weights[i][2];
                Mat4 *M2 = &a->mats[b->idx[bones[i][2]]];
                volatile float bx = (float)(((z) * (M2)->m[8] + (y) * (M2)->m[4] + (x) * (M2)->m[0] + (M2)->m[12]) * w2 + ax);
                ry = (float)(((z) * (M2)->m[9] + (x) * (M2)->m[1] + (y) * (M2)->m[5] + (M2)->m[13]) * w2 + ay);
                rz = (float)(((z) * (M2)->m[10] + (x) * (M2)->m[2] + (y) * (M2)->m[6] + (M2)->m[14]) * w2 + rz);
                float w3 = (float)(1.0f - (weights[i][2] + weights[i][0] + weights[i][1]));
                Mat4 *M3 = &a->mats[b->idx[bones[i][3]]];
                rx = ((z) * (M3)->m[8] + (y) * (M3)->m[4] + (x) * (M3)->m[0] + (M3)->m[12]) * w3 + bx;
                ry = (float)(((z) * (M3)->m[9] + (x) * (M3)->m[1] + (y) * (M3)->m[5] + (M3)->m[13]) * w3 + ry);
                rz = (float)(((z) * (M3)->m[10] + (x) * (M3)->m[2] + (y) * (M3)->m[6] + (M3)->m[14]) * w3 + rz);
            }
            V3 *dst3 = f20;
            dst3[i].x = (float)rx;
            dst3[i].y = ry;
            dst3[i].z = rz;
        }
    }

    if (f28) {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            PTR(f2c)[i].x = ROT_X(M, VF(PTR(f28)[i].x), VF(PTR(f28)[i].y), VF(PTR(f28)[i].z));
            PTR(f2c)[i].y = ROT_Y(M, VF(PTR(f28)[i].x), VF(PTR(f28)[i].y), VF(PTR(f28)[i].z));
            PTR(f2c)[i].z = ROT_Z(M, VF(PTR(f28)[i].x), VF(PTR(f28)[i].y), VF(PTR(f28)[i].z));
        }
    }
    if (f30) {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            PTR(f34)[i].x = ROT_X(M, VF(PTR(f30)[i].x), VF(PTR(f30)[i].y), VF(PTR(f30)[i].z));
            PTR(f34)[i].y = ROT_Y(M, VF(PTR(f30)[i].x), VF(PTR(f30)[i].y), VF(PTR(f30)[i].z));
            PTR(f34)[i].z = ROT_Z(M, VF(PTR(f30)[i].x), VF(PTR(f30)[i].y), VF(PTR(f30)[i].z));
        }
    }
}
