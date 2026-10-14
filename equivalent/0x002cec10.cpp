// STATUS: equivalent (tools/equiv.py level 3: 604 inputs, branch coverage 302/376, incomplete)
// FUN_002cec10 @ 0x002cec10
struct Vec2_2cec10 { float x, y; };
struct Vec3_2cec10 { float x, y, z; };

struct Blend_2cec10 {
    char pad00[0x10];
    Vec3_2cec10* q0;
    Vec3_2cec10* q1;
    Vec2_2cec10* r0;
    Vec2_2cec10* r1;
    Vec2_2cec10* r2;
    Vec2_2cec10* r3;
    short* d0;
    short* d1;
};

struct Source_2cec10 {
    char pad00[8];
    unsigned flags;
    unsigned count;
    char pad10[8];
    Vec3_2cec10* p0;
    Vec3_2cec10* p1;
    Vec3_2cec10* p2;
    Vec3_2cec10* p3;
    Vec3_2cec10* t0;
    Vec3_2cec10* t1;
    Vec3_2cec10* t2;
    Vec3_2cec10* t3;
    Vec2_2cec10* s0;
    Vec2_2cec10* s1;
    Vec2_2cec10* s2;
    Vec2_2cec10* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2cec10* blend;
};

struct VertexSink_2cec10 {
    virtual void SetPos(Vec3_2cec10 v);
    virtual void SetNormal(Vec3_2cec10 v);
    virtual void SetExtra0(Vec3_2cec10 v);
    virtual void SetExtra1(Vec3_2cec10 v);
    virtual void SetColor(unsigned c, int k);
    virtual void vf5();
    virtual void SetUv(Vec2_2cec10 uv, int k);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void SetPosNormalUv(Vec3_2cec10* pos, Vec3_2cec10* normal, Vec2_2cec10* uv);
    virtual void SetPosColorUv(Vec3_2cec10* pos, unsigned color, Vec2_2cec10* uv);
    virtual void SetPosUv(Vec3_2cec10* pos, Vec2_2cec10* uv);
    virtual void SetPosNormal(Vec3_2cec10* pos, Vec3_2cec10* normal);
    virtual void SetPosColor(Vec3_2cec10* pos, unsigned color);
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

static __forceinline Vec3_2cec10 Add3(const Vec3_2cec10& a, const Vec3_2cec10& b)
{
    Vec3_2cec10 v;
    v.z = a.z + b.z;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}

static __forceinline Vec2_2cec10 Add2(const Vec2_2cec10& a, const Vec2_2cec10& b)
{
    Vec2_2cec10 v;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}

// equiv-conv: FUN_002cec10 ecx edx esi
void FUN_002cec10(Source_2cec10* src, unsigned char flag, VertexSink_2cec10* out)
{
    unsigned count = src->count;
    Vec3_2cec10* p0;
    Vec3_2cec10* p1;
    Vec3_2cec10* t0;
    Vec3_2cec10* t1;
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
    Vec2_2cec10* s0 = src->s0;
    Vec2_2cec10* s1 = src->s1;
    Vec2_2cec10* s2 = src->s2;
    Vec2_2cec10* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2cec10* b = src->blend;
    Vec3_2cec10* q0 = 0;
    Vec3_2cec10* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2cec10* r0 = b->r0;
    Vec2_2cec10* r1 = b->r1;
    Vec2_2cec10* r2 = b->r2;
    Vec2_2cec10* r3 = b->r3;
    unsigned i;

    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[i], 0);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColor(&p0[i], col0[i]);
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetNormal(Add3(p1[i], q1[i]));
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetNormal(Add3(p1[i], q1[i]));
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetNormal(p1[i]);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormal(&p0[i], &p1[i]);
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[i], r0[i]), 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[i], 0);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosUv(&p0[i], &s0[i]);
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                        out->SetUv(Add2(s0[i], r0[i]), 0);
                        out->SetPos(Add3(p0[i], q0[i]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetPos(p0[i]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                    out->SetUv(s0[i], 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                out->SetUv(s0[i], 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(col0[i], 0);
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(col0[i], 0);
                out->SetUv(Add2(s0[i], r0[i]), 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[i], 0);
                out->SetUv(s0[i], 0);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColorUv(&p0[i], col0[i], &s0[i]);
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetUv(Add2(s0[i], r0[i]), 0);
                        out->SetNormal(Add3(p1[i], q1[i]));
                        out->SetPos(Add3(p0[i], q0[i]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetNormal(Add3(p1[i], q1[i]));
                    out->SetPos(p0[i]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetNormal(p1[i]);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[i], r0[i]), 0);
                out->SetNormal(p1[i]);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(s0[i], 0);
                    out->SetNormal(Add3(p1[i], q1[i]));
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(s0[i], 0);
                out->SetNormal(Add3(p1[i], q1[i]));
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[i], 0);
                out->SetNormal(p1[i]);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormalUv(&p0[i], &p1[i], &s0[i]);
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            out->SetNormal(q1 ? Add3(p1[i], q1[i]) : p1[i]);
        if (t0)
            out->SetExtra0(t0[i]);
        if (t1)
            out->SetExtra1(t1[i]);
        if (col0)
            out->SetColor(d0 ? AddColor(col0[i], &d0[i * 4]) : col0[i], 0);
        if (col1)
            out->SetColor(d1 ? AddColor(col1[i], &d1[i * 4]) : col1[i], 1);
        if (s0)
            out->SetUv(r0 ? Add2(s0[i], r0[i]) : s0[i], 0);
        if (s1)
            out->SetUv(r1 ? Add2(s1[i], r1[i]) : s1[i], 1);
        if (s2)
            out->SetUv(r2 ? Add2(s2[i], r2[i]) : s2[i], 2);
        if (s3)
            out->SetUv(r3 ? Add2(s3[i], r3[i]) : s3[i], 3);
        out->SetPos(q0 ? Add3(p0[i], q0[i]) : p0[i]);
    }
}
