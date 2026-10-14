// STATUS: equivalent (tools/equiv.py level 3: 46 inputs, branch coverage 35/38, incomplete)
// FUN_002a5570 @ 0x002a5570
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" double sqrt(double);

struct V2_2a5570 {
    float x, y;
};

struct V3_2a5570 {
    float x, y, z;
};

struct Mesh_2a5570 {
    char pad00[0xc];
    unsigned int count;
    char pad10[8];
    V3_2a5570 *verts;
    char pad1c[0x38 - 0x1c];
    V2_2a5570 *uv[4];
};

struct Ripple {
    float speed;
    float cx;
    float cy;
    float cz;
    float radius;
    float ampA;
    float ampB;
};

extern float DAT_0042d9a4;
extern unsigned int DAT_0042d9c0[4];

static float Smooth(float w)
{
    if (w <= 0.0f)
        return 0.0f;
    if (w >= 1.0f)
        return 1.0f;
    return (3.0f - 2.0f * w) * w * w;
}

void __cdecl FUN_002a5570(float t, Mesh_2a5570 *a, Mesh_2a5570 *b, unsigned int mask, Ripple *p)
{
    unsigned int n = a->count;
    V3_2a5570 *bv = b->verts;
    V3_2a5570 *av = a->verts;
    V2_2a5570 *srcUv[4];
    V2_2a5570 *dstUv[4];
    srcUv[0] = a->uv[0];
    dstUv[0] = b->uv[0];
    srcUv[1] = a->uv[1];
    dstUv[1] = b->uv[1];
    srcUv[2] = a->uv[2];
    dstUv[2] = b->uv[2];
    srcUv[3] = a->uv[3];
    dstUv[3] = b->uv[3];
    volatile float phase = t * p->speed * DAT_0042d9a4;
    if (n == 0)
        return;

    unsigned int vflag = mask & 0x10;
    unsigned int i = n;
    do {
        i--;
        if (vflag) {
            volatile float w = 1.0f;
            float dx = av[i].x - p->cx;
            float dy = av[i].y - p->cy;
            volatile float dz = av[i].z - p->cz;
            if (p->radius > 0.0) {
                double d = sqrt((double)((dy * dy + dz * dz) + dx * dx));
                float r = (float)(p->radius - d);
                if (!(0.0f < r))
                    r = 0.0f;
                w = r / p->radius;
            }
            volatile float angle = dx + phase;
            double X = Smooth(w) * (cos((double)angle) * p->ampA);
            angle = dz + phase;
            double Z = Smooth(w) * (sin((double)angle) * p->ampA);
            bv[i].x = (float)(X + av[i].x);
            bv[i].z = (float)(Z + av[i].z);
        }
        for (int j = 0; j < 4; j++) {
            if (!(DAT_0042d9c0[j] & mask))
                continue;
            V2_2a5570 *src = srcUv[j];
            if (!src)
                continue;
            V2_2a5570 *dst = dstUv[j];
            if (!dst)
                continue;
            volatile float w = 1.0f;
            volatile float du = src[i].x - p->cx;
            volatile float dv = src[i].y - p->cy;
            if (p->radius > 0.0) {
                double d = sqrt((double)(dv * dv + du * du));
                float r = (float)(p->radius - d);
                if (!(0.0f < r))
                    r = 0.0f;
                w = r / p->radius;
            }
            volatile float angle = du + phase;
            double X = Smooth(w) * (cos((double)angle) * p->ampB);
            angle = dv + phase;
            double Z = Smooth(w) * (sin((double)angle) * p->ampB);
            dst[i].x = (float)(X + src[i].x);
            dst[i].y = (float)(Z + src[i].y);
        }
    } while (i != 0);
}
