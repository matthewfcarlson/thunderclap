// STATUS: equivalent (tools/equiv.py level 3: 562 inputs, branch coverage 322/376, incomplete)
// FUN_002cd130 @ 0x002cd130
struct Vec2_2cd130 { float x, y; };
struct Vec3_2cd130 { float x, y, z; };

struct Blend_2cd130 {
    char pad00[0x10];
    Vec3_2cd130* q0;
    Vec3_2cd130* q1;
    Vec2_2cd130* r0;
    Vec2_2cd130* r1;
    Vec2_2cd130* r2;
    Vec2_2cd130* r3;
    short* d0;
    short* d1;
};

struct Source_2cd130 {
    char pad00[8];
    unsigned flags;
    char pad0c[4];
    unsigned count;
    unsigned short* index;
    Vec3_2cd130* p0;
    Vec3_2cd130* p1;
    Vec3_2cd130* p2;
    Vec3_2cd130* p3;
    Vec3_2cd130* t0;
    Vec3_2cd130* t1;
    Vec3_2cd130* t2;
    Vec3_2cd130* t3;
    Vec2_2cd130* s0;
    Vec2_2cd130* s1;
    Vec2_2cd130* s2;
    Vec2_2cd130* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2cd130* blend;
};

struct VertexSink_2cd130 {
    virtual void SetPos(Vec3_2cd130 v);
    virtual void SetNormal(Vec3_2cd130 v);
    virtual void SetExtra0(Vec3_2cd130 v);
    virtual void SetExtra1(Vec3_2cd130 v);
    virtual void SetColor(unsigned c, int k);
    virtual void vf5();
    virtual void SetUv(Vec2_2cd130 uv, int k);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void SetPosNormalUv(Vec3_2cd130* pos, Vec3_2cd130* normal, Vec2_2cd130* uv);
    virtual void SetPosColorUv(Vec3_2cd130* pos, unsigned color, Vec2_2cd130* uv);
    virtual void SetPosUv(Vec3_2cd130* pos, Vec2_2cd130* uv);
    virtual void SetPosNormal(Vec3_2cd130* pos, Vec3_2cd130* normal);
    virtual void SetPosColor(Vec3_2cd130* pos, unsigned color);
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

static __forceinline Vec3_2cd130 Add3(const Vec3_2cd130& a, const Vec3_2cd130& b)
{
    Vec3_2cd130 v;
    v.z = a.z + b.z;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}

static __forceinline Vec2_2cd130 Add2(const Vec2_2cd130& a, const Vec2_2cd130& b)
{
    Vec2_2cd130 v;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}

// equiv-conv: FUN_002cd130 eax edx esi
void FUN_002cd130(Source_2cd130* src, unsigned char flag, VertexSink_2cd130* out)
{
    unsigned count = src->count;
    unsigned short* index = src->index;
    Vec3_2cd130* p0;
    Vec3_2cd130* p1;
    Vec3_2cd130* t0;
    Vec3_2cd130* t1;
    if (flag == 1) {
        p0 = src->p2;
        p1 = src->p3;
        t0 = src->t1;
        t1 = src->t3;
    } else {
        p0 = src->p0;
        p1 = src->p1;
        t0 = src->t0;
        t1 = src->t2;
    }
    unsigned* col0 = src->col0;
    unsigned* col1 = src->col1;
    Vec2_2cd130* s0 = src->s0;
    Vec2_2cd130* s1 = src->s1;
    Vec2_2cd130* s2 = src->s2;
    Vec2_2cd130* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2cd130* b = src->blend;
    Vec3_2cd130* q0 = 0;
    Vec3_2cd130* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2cd130* r0 = b->r0;
    Vec2_2cd130* r1 = b->r1;
    Vec2_2cd130* r2 = b->r2;
    Vec2_2cd130* r3 = b->r3;
    unsigned i;

    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[index[i]], 0);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColor(&p0[index[i]], col0[index[i]]);
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetNormal(p1[index[i]]);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormal(&p0[index[i]], &p1[index[i]]);
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[index[i]], 0);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosUv(&p0[index[i]], &s0[index[i]]);
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                        out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                        out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetPos(p0[index[i]]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                    out->SetUv(s0[index[i]], 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                out->SetUv(s0[index[i]], 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(col0[index[i]], 0);
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(col0[index[i]], 0);
                out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[index[i]], 0);
                out->SetUv(s0[index[i]], 0);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColorUv(&p0[index[i]], col0[index[i]], &s0[index[i]]);
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                        out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                        out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                    out->SetPos(p0[index[i]]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetNormal(p1[index[i]]);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                out->SetNormal(p1[index[i]]);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(s0[index[i]], 0);
                    out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(s0[index[i]], 0);
                out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[index[i]], 0);
                out->SetNormal(p1[index[i]]);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormalUv(&p0[index[i]], &p1[index[i]], &s0[index[i]]);
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            out->SetNormal(q1 ? Add3(p1[index[i]], q1[index[i]]) : p1[index[i]]);
        if (t0)
            out->SetExtra0(t0[index[i]]);
        if (t1)
            out->SetExtra1(t1[index[i]]);
        if (col0)
            out->SetColor(d0 ? AddColor(col0[index[i]], &d0[index[i] * 4]) : col0[index[i]], 0);
        if (col1)
            out->SetColor(d1 ? AddColor(col1[index[i]], &d1[index[i] * 4]) : col1[index[i]], 1);
        if (s0)
            out->SetUv(r0 ? Add2(s0[index[i]], r0[index[i]]) : s0[index[i]], 0);
        if (s1)
            out->SetUv(r1 ? Add2(s1[index[i]], r1[index[i]]) : s1[index[i]], 1);
        if (s2)
            out->SetUv(r2 ? Add2(s2[index[i]], r2[index[i]]) : s2[index[i]], 2);
        if (s3)
            out->SetUv(r3 ? Add2(s3[index[i]], r3[index[i]]) : s3[index[i]], 3);
        out->SetPos(q0 ? Add3(p0[index[i]], q0[index[i]]) : p0[index[i]]);
    }
}
