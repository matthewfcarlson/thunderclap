// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 44/54, incomplete)
// FUN_002a5a20 @ 0x002a5a20
extern "C" double __cdecl sin(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Vec2 {
    float u, v;
};

struct Mesh {
    char pad00[0xc];
    int count;
    char pad10[8];
    Vec3 *pos;
    char pad1c[0x38 - 0x1c];
    Vec2 *uv[4];
    unsigned char *color;
};

struct WaveParams {
    float speed;
    float cx, cy, cz;
    float dirx, diry, dirz;
    float radius;
    float falloff;
    float displace;
    float k28;
    float k2c;
    float k30;
    float uvAmp;
};

extern unsigned int DAT_0042d9c0[4];

union FloatBits {
    float f;
    unsigned int u;
};

static inline int Clamp255(int v)
{
    if (v < 0) {
        return 0;
    }
    if (v > 255) {
        return 255;
    }
    return v;
}

void FUN_002a5a20(float time, Mesh *a, Mesh *b, unsigned int flags, WaveParams *p)
{
    unsigned char *srcColor = a->color;
    unsigned char *dstColor = b->color;
    Vec3 *srcPos = a->pos;
    Vec3 *dstPos = b->pos;
    Vec2 *src[4];
    Vec2 *dst[4];
    int c;
    for (c = 0; c < 4; c++) {
        src[c] = a->uv[c];
    }
    for (c = 0; c < 4; c++) {
        dst[c] = b->uv[c];
    }
    int i = a->count;

    Vec3 axis;
    axis.x = p->dirx;
    axis.y = p->diry;
    axis.z = 0.0f;
    axis.FUN_0022d110();

    while (i != 0) {
        i--;
        Vec3 *v = &srcPos[i];
        float dx = v->x - p->cx;
        float dy = v->y - p->cy;
        float dz = v->z - p->cz;
        float dot = dx * p->dirx + (dy * p->diry + dz * p->dirz);
        float t;
        if (p->radius != 0.0f) {
            t = dot / p->radius;
        } else {
            t = 0.0f;
        }
        volatile float u = time * p->speed + t;
        float falloff = 1.0f;
        if (p->falloff > 0.0) {
            FloatBits ab;
            ab.f = dot;
            ab.u &= 0x7fffffff;
            float x = p->falloff - ab.f;
            if (!(0.0f < x)) {
                x = 0.0f;
            }
            falloff = x / p->falloff;
        }
        float w = (float)(sin(u * 6.2831855f) * falloff);
        if (flags & 0x10) {
            dstPos[i].y = w * p->displace + srcPos[i].y;
        }
        if ((flags & 0x40) && srcColor != 0) {
            float s = w + p->k30;
            double m1 = p->k28 * 255.0f;
            int d1 = (int)(m1 * s);
            double m2 = p->k2c * 255.0f;
            int d2 = (int)(m2 * s);
            unsigned char *e = &srcColor[i * 4];
            int r2 = Clamp255(e[2] + d1);
            int r1 = Clamp255(e[1] + d1);
            int r0 = Clamp255(e[0] + d1);
            int r3 = Clamp255(e[3] + d2);
            ((unsigned int *)dstColor)[i] = (unsigned int)((((r3 << 8 | r2) << 8 | r1) << 8) | r0);
        }
        for (c = 0; c < 4; c++) {
            if ((DAT_0042d9c0[c] & flags) && src[c] != 0 && dst[c] != 0) {
                float du = src[c][i].u - p->cx;
                float dv = src[c][i].v - p->cy;
                float dot2 = du * p->dirx + (dv * p->diry + p->dirz * 0.0f);
                float t2;
                if (p->radius != 0.0f) {
                    t2 = dot2 / p->radius;
                } else {
                    t2 = 0.0f;
                }
                volatile float u2 = time * p->speed + t2;
                float falloff2 = 1.0f;
                if (p->falloff > 0.0) {
                    FloatBits ab2;
                    ab2.f = dot2;
                    ab2.u &= 0x7fffffff;
                    float x2 = p->falloff - ab2.f;
                    if (!(0.0f < x2)) {
                        x2 = 0.0f;
                    }
                    falloff2 = x2 / p->falloff;
                }
                float amp = p->uvAmp;
                float w2 = (float)(sin(u2 * 6.2831855f) * falloff2);
                volatile float wy = w2 * p->diry;
                dst[c][i].u = w2 * p->dirx * amp + src[c][i].u;
                dst[c][i].v = wy * amp + src[c][i].v;
            }
        }
    }
}
