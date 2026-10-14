// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_00318de0 @ 0x00318de0
extern "C" double sqrt(double);

struct V3_318de0 {
    float x;
    float y;
    float z;
};

class Box_318de0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_318de0 *v4();
    char pad04[0x48 - 4];
    float ext[3];
    V3_318de0 axes[3];
    void FUN_002fb990(V3_318de0 *out, int axis, int side);
};

class Collider_318de0 {
public:
    char pad0[0xc];
    float thr;
    char pad10[4];
    V3_318de0 d;
    char pad20[0x30 - 0x20];
    int count;
    void FUN_00313650(int *order, float *gap);
    void FUN_00315620(V3_318de0 *p, V3_318de0 *aAxis, float aExt, V3_318de0 *q, V3_318de0 *bAxis, float bExt, V3_318de0 *n, float len, float gap, Box_318de0 *a0, Box_318de0 *a1);
    void FUN_00318de0(Box_318de0 *a0, Box_318de0 *a1);
};

struct Frame_318de0 {
    int k;
    float t14;
    V3_318de0 n;
    float *aExtPtr;
    float *bAxisPtr;
    float *aAxisPtr;
    Collider_318de0 *self;
    float inv;
    float t38;
    int j;
    float t40;
    float *bExtPtr;
    float absPd;
    int i;
    float pd;
    float t54;
    float absPa;
    float absPb;
    float pa[4];
    float pb[4];
    float gap[4];
    V3_318de0 q[4];
    int order[4];
    V3_318de0 p[4];
};

#define BITS(x) (*(unsigned int *)&(x))
#define FL(x) (*(float *)&(x))

void Collider_318de0::FUN_00318de0(Box_318de0 *a0, Box_318de0 *a1)
{
    Frame_318de0 f;

    V3_318de0 *posA = a0->v4();
    V3_318de0 *posB = a1->v4();
    f.self = this;
    f.self->d.x = posB->x - posA->x;
    f.self->d.y = posB->y - posA->y;
    f.self->d.z = posB->z - posA->z;

    for (f.i = 0; f.i < 3; f.i++) {
        for (f.j = 0; f.j < 3; f.j++) {
            V3_318de0 *ax = &a0->axes[f.i];
            V3_318de0 *bx = &a1->axes[f.j];
            double cx = ax->y * bx->z - ax->z * bx->y;
            double cy = ax->z * bx->x - ax->x * bx->z;
            f.n.z = bx->y * ax->x - ax->y * bx->x;
            double p = a1->ext[f.j] * a0->ext[f.i];
            f.t14 = (float)p;
            f.n.x = (float)(p * cx);
            f.n.y = (float)(cy * f.t14);
            double nzx = f.n.z * f.t14;
            f.n.z = (float)nzx;
            double l = nzx * f.n.z;
            l = l + f.n.y * f.n.y;
            l = l + f.n.x * f.n.x;
            f.t14 = (float)l;
            if (!(l > 1.0e-6f))
                continue;
            double proj = f.n.z * f.self->d.z;
            proj = proj + f.n.y * f.self->d.y;
            proj = proj + f.n.x * f.self->d.x;
            f.t40 = (float)proj;
            BITS(f.t40) &= 0x7fffffff;
            if (!(f.t40 > 1.0e-6f))
                continue;
            volatile float *vt = &f.t14;
            *vt = (float)sqrt((double)f.t14);
            double invx = 1.0f / *vt;
            f.inv = (float)invx;
            f.pd = (float)(invx * proj);

            int idx = 0;
            for (f.k = 0; f.k < 2; f.k++) {
                for (int m = 0; m < 2; m++) {
                    a0->FUN_002fb990(&f.p[idx], f.i, f.k);
                    a1->FUN_002fb990(&f.q[idx], f.j, m);
                    double pa = (f.n.z * f.p[idx].z + f.n.y * f.p[idx].y + f.n.x * f.p[idx].x) * f.inv;
                    f.pa[idx] = (float)pa;
                    double pb = (f.n.z * f.q[idx].z + f.n.y * f.q[idx].y + f.n.x * f.q[idx].x) * f.inv;
                    f.pb[idx] = (float)pb;
                    BITS(f.absPd) = BITS(f.pd) & 0x7fffffff;
                    f.t54 = (float)pa;
                    f.t38 = (float)pb;
                    BITS(f.t54) &= 0x7fffffff;
                    BITS(f.t38) &= 0x7fffffff;
                    f.gap[idx] = (float)(f.absPd - (f.t38 + f.t54));
                    idx++;
                }
            }

            f.self->FUN_00313650(f.order, f.gap);
            for (int e = 3; e >= 0; e--) {
                int c = f.order[e];
                BITS(f.k) = BITS(f.pb[c]);
                BITS(f.absPb) = BITS(f.k) & 0x7fffffff;
                BITS(f.k) = BITS(f.pa[c]);
                BITS(f.absPa) = BITS(f.k) & 0x7fffffff;
                double mm;
                if (f.absPa < f.absPb)
                    mm = f.absPa;
                else
                    mm = f.absPb;
                BITS(f.k) = BITS(f.pa[c]) & 0x7fffffff;
                if (!(FL(f.k) > 1.0e-6f))
                    continue;
                BITS(f.k) = BITS(f.pb[c]) & 0x7fffffff;
                if (!(FL(f.k) > 1.0e-6f))
                    continue;
                if (!(f.gap[c] < f.self->thr))
                    continue;
                if (!(-mm < f.gap[c]))
                    continue;
                if (f.pd * f.pa[c] < 0.0f) {
                    f.p[c].x = f.p[c].x * -1.0f;
                    f.p[c].y = f.p[c].y * -1.0f;
                    f.p[c].z = f.p[c].z * -1.0f;
                }
                if (-(f.pd * f.pb[c]) < 0.0f) {
                    f.q[c].x = f.q[c].x * -1.0f;
                    f.q[c].y = f.q[c].y * -1.0f;
                    f.q[c].z = f.q[c].z * -1.0f;
                }
                f.self->FUN_00315620(&f.p[c], &a0->axes[f.i], a0->ext[f.i], &f.q[c], &a1->axes[f.j], a1->ext[f.j], &f.n, f.t14, f.gap[c], a0, a1);
                if (f.self->count > 3)
                    break;
            }
        }
    }
}
