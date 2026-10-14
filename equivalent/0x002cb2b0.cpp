// STATUS: equivalent (tools/equiv.py level 3: 472 inputs, branch coverage 307/382, incomplete)
// FUN_002cb2b0 @ 0x002cb2b0
struct Vec2_2cb2b0 { float x, y; };
struct Vec3_2cb2b0 { float x, y, z; };

struct Blend_2cb2b0 {
    char pad00[0x10];
    Vec3_2cb2b0* q0;
    Vec3_2cb2b0* q1;
    Vec2_2cb2b0* r0;
    Vec2_2cb2b0* r1;
    Vec2_2cb2b0* r2;
    Vec2_2cb2b0* r3;
    short* d0;
    short* d1;
};

struct Source_2cb2b0 {
    char pad00[8];
    unsigned flags;
    unsigned count;
    char pad10[4];
    unsigned short* index;
    Vec3_2cb2b0* p0;
    Vec3_2cb2b0* p1;
    Vec3_2cb2b0* p2;
    Vec3_2cb2b0* p3;
    char pad28[0x38 - 0x28];
    Vec2_2cb2b0* s0;
    Vec2_2cb2b0* s1;
    Vec2_2cb2b0* s2;
    Vec2_2cb2b0* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2cb2b0* blend;
};

struct VertexSink_2cb2b0 {
    char pad00[8];
    Vec3_2cb2b0* pos;
    Vec3_2cb2b0* normal;
    unsigned* color;
    Vec2_2cb2b0* uv;
    void FUN_0008ef00();
};

static __forceinline int Clamp255(int v)
{
    if (v < 0)
        return 0;
    if (v > 255)
        return 255;
    return v;
}

static __forceinline unsigned AddColor(unsigned c, const short* d)
{
    int r = Clamp255(((c >> 16) & 0xff) + d[0]);
    int g = Clamp255(((c >> 8) & 0xff) + d[1]);
    int b = Clamp255((c & 0xff) + d[2]);
    int a = Clamp255((c >> 24) + d[3]);
    return (((a << 8 | r) << 8 | g) << 8) | b;
}

static __forceinline void PutPos(VertexSink_2cb2b0* out, const Vec3_2cb2b0* p, const Vec3_2cb2b0* q)
{
    if (q) {
        float z = p->z + q->z;
        float y = p->y + q->y;
        float x = p->x + q->x;
        out->pos->x = x;
        out->pos->y = y;
        out->pos->z = z;
    } else {
        float z = p->z;
        float y = p->y;
        float x = p->x;
        out->pos->x = x;
        out->pos->y = y;
        out->pos->z = z;
    }
}

static __forceinline void PutNormal(VertexSink_2cb2b0* out, const Vec3_2cb2b0* p, const Vec3_2cb2b0* q)
{
    if (q) {
        float z = p->z + q->z;
        float y = p->y + q->y;
        float x = p->x + q->x;
        out->normal->x = x;
        out->normal->y = y;
        out->normal->z = z;
    } else {
        float z = p->z;
        float y = p->y;
        float x = p->x;
        out->normal->x = x;
        out->normal->y = y;
        out->normal->z = z;
    }
}

// out->uv is reloaded before every store: the fuzzed pointer may point into the sink itself.
static __forceinline void PutUv(VertexSink_2cb2b0* out, int k, const Vec2_2cb2b0* s, const Vec2_2cb2b0* r)
{
    if (r) {
        float y = s->y + r->y;
        float x = s->x + r->x;
        out->uv[k].x = x;
        out->uv[k].y = y;
    } else {
        float y = s->y;
        float x = s->x;
        out->uv[k].x = x;
        out->uv[k].y = y;
    }
}

static __forceinline void PutColor(unsigned* dst, const unsigned* c, const short* d, unsigned i)
{
    if (d)
        *dst = AddColor(c[i], d + i * 4);
    else
        *dst = c[i];
}

// equiv-conv: FUN_002cb2b0 ecx stack esi
void FUN_002cb2b0(Source_2cb2b0* src, unsigned char flag, VertexSink_2cb2b0* out)
{
    unsigned count = src->count;
    Vec3_2cb2b0* p0;
    Vec3_2cb2b0* p1;
    if (flag == 1) {
        p0 = src->p2;
        p1 = src->p3;
    } else {
        p0 = src->p0;
        p1 = src->p1;
    }
    unsigned* col0 = src->col0;
    unsigned* col1 = src->col1;
    Vec2_2cb2b0* s0 = src->s0;
    Vec2_2cb2b0* s1 = src->s1;
    Vec2_2cb2b0* s2 = src->s2;
    Vec2_2cb2b0* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2cb2b0* b = src->blend;
    Vec3_2cb2b0* q0 = 0;
    Vec3_2cb2b0* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2cb2b0* r0 = b->r0;
    Vec2_2cb2b0* r1 = b->r1;
    Vec2_2cb2b0* r2 = b->r2;
    Vec2_2cb2b0* r3 = b->r3;
    unsigned i;

    // jump table 0x2cd0e8 / byte table 0x2cd100: flags-0x2001 = 0x00, 0x0f, 0x10, 0x1f, 0x20 (everything else: the generic loop)
    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[i], &d0[i * 4]);
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = AddColor(col0[i], &d0[i * 4]);
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->color[0] = col0[i];
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            unsigned c = col0[v];
            *out->pos = p0[v];
            out->color[0] = c;
            out->FUN_0008ef00();
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            *out->pos = p0[v];
            *out->normal = p1[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            *out->pos = p0[v];
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->color[0] = AddColor(col0[i], &d0[i * 4]);
                        { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                        { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                        out->FUN_0008ef00();
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[i], &d0[i * 4]);
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[i], &d0[i * 4]);
                    { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = AddColor(col0[i], &d0[i * 4]);
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = col0[i];
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = col0[i];
                { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->color[0] = col0[i];
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            unsigned c = col0[v];
            *out->pos = p0[v];
            out->color[0] = c;
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                        { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                        { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                        out->FUN_0008ef00();
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            *out->pos = p0[v];
            *out->normal = p1[v];
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            PutNormal(out, &p1[i], q1 ? &q1[i] : 0);
        if (col0) PutColor(&out->color[0], col0, d0, i);
        if (col1) PutColor(&out->color[1], col1, d1, i);
        if (s0) PutUv(out, 0, &s0[i], r0 ? &r0[i] : 0);
        if (s1) PutUv(out, 1, &s1[i], r1 ? &r1[i] : 0);
        if (s2) PutUv(out, 2, &s2[i], r2 ? &r2[i] : 0);
        if (s3) PutUv(out, 3, &s3[i], r3 ? &r3[i] : 0);
        PutPos(out, &p0[i], q0 ? &q0[i] : 0);
        out->FUN_0008ef00();
    }
}
