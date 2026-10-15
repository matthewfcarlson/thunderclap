// STATUS: equivalent (tools/equiv.py level 3: 56 inputs, branch coverage 14/14)
// FUN_002c92f0 @ 0x002c92f0
struct Vec3 {
    float x, y, z;
};

struct Mat {
    float m[16];
};

struct MatSet {
    char pad00[8];
    Mat *mats;
};

struct Remap {
    char pad00[8];
    int *map;
};

class Skin {
public:
    char pad00[8];
    unsigned int flags;
    unsigned int count;
    char pad10[8];
    Vec3 *bindPos;
    Vec3 *srcA;
    Vec3 *dstBlend;
    Vec3 *dstA;
    Vec3 *srcB;
    Vec3 *dstB;
    Vec3 *srcC;
    Vec3 *dstC;
    char pad38[0x50 - 0x38];
    unsigned char *idx;
    float *weights;
    void FUN_002c92f0(MatSet *ms, Remap *rm);
};

void Skin::FUN_002c92f0(MatSet *ms, Remap *rm)
{
    for (unsigned int i = 0; i < count; i++) {
        const float *m = ms->mats[rm->map[idx[i * 4]]].m;
        if (flags & 0x10) {
            dstA[i].x = srcA[i].z * m[8] + srcA[i].y * m[4] + srcA[i].x * m[0];
            dstA[i].y = srcA[i].z * m[9] + srcA[i].y * m[5] + m[1] * srcA[i].x;
            dstA[i].z = srcA[i].z * m[10] + srcA[i].y * m[6] + m[2] * srcA[i].x;
        }
        if (flags & 0x800) {
            dstB[i].x = srcB[i].z * m[8] + srcB[i].y * m[4] + m[0] * srcB[i].x;
            dstB[i].y = srcB[i].z * m[9] + srcB[i].y * m[5] + m[1] * srcB[i].x;
            dstB[i].z = srcB[i].z * m[10] + srcB[i].y * m[6] + m[2] * srcB[i].x;
        }
        if (flags & 0x1000) {
            dstC[i].x = srcC[i].z * m[8] + srcC[i].y * m[4] + m[0] * srcC[i].x;
            dstC[i].y = srcC[i].z * m[9] + srcC[i].y * m[5] + m[1] * srcC[i].x;
            dstC[i].z = srcC[i].z * m[10] + srcC[i].y * m[6] + m[2] * srcC[i].x;
        }
        float w;
        if (weights)
            w = weights[i * 3];
        else
            w = 1.0f;
        const Vec3 *p = &bindPos[i];
        double accX = (m[4] * p->y + m[8] * p->z + m[0] * p->x + m[12]) * w;
        float accY = (float)((m[5] * p->y + m[9] * p->z + m[1] * p->x + m[13]) * w);
        float accZ = (float)((m[6] * p->y + m[10] * p->z + m[2] * p->x + m[14]) * w);
        if (!(w == 1.0f)) {
            const float *W = &weights[i * 3];
            w = W[1];
            const float *m1 = ms->mats[rm->map[idx[i * 4 + 1]]].m;
            p = &bindPos[i];
            accX = accX + (m1[8] * p->z + m1[4] * p->y + p->x * m1[0] + m1[12]) * w;
            double ys = (m1[9] * p->z + m1[1] * p->x + m1[5] * p->y + m1[13]) * w + accY;
            accZ = (float)((m1[10] * p->z + m1[2] * p->x + m1[6] * p->y + m1[14]) * w + accZ);
            w = W[2];
            const float *m2 = ms->mats[rm->map[idx[i * 4 + 2]]].m;
            float tx = (float)((m2[8] * p->z + m2[4] * p->y + p->x * m2[0] + m2[12]) * w + accX);
            accY = (float)((m2[9] * p->z + m2[1] * p->x + m2[5] * p->y + m2[13]) * w + ys);
            accZ = (float)((m2[10] * p->z + m2[2] * p->x + m2[6] * p->y + m2[14]) * w + accZ);
            w = 1.0f - (W[2] + W[0] + W[1]);
            const float *m3 = ms->mats[rm->map[idx[i * 4 + 3]]].m;
            accX = (m3[8] * p->z + m3[4] * p->y + p->x * m3[0] + m3[12]) * w + tx;
            accY = (float)((m3[9] * p->z + m3[1] * p->x + m3[5] * p->y + m3[13]) * w + accY);
            accZ = (float)((m3[10] * p->z + m3[2] * p->x + m3[6] * p->y + m3[14]) * w + accZ);
        }
        dstBlend[i].x = (float)accX;
        dstBlend[i].y = accY;
        dstBlend[i].z = accZ;
    }
}
