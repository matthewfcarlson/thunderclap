// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 40/40)
// FUN_00301790 @ 0x00301790
// equiv-map: ?thunk_FUN_002fb860@Shape@@QAEXPAUVec3@@H@Z = 0x002fb940
struct Vec3_301790 {
    float x, y, z;
    void FUN_0022d180();
    void FUN_000111b0(const Vec3_301790 *a, const Vec3_301790 *b);
    void FUN_001f6bc0(const Vec3_301790 *a, float s, const Vec3_301790 *b);
};

float FUN_00083d90(float *v);

struct Span_301790 {
    int begin;
    int end;
};

class Plane_301790 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_301790 *vfunc_4();
    char pad04[0x38 - 4];
    Vec3_301790 normal;
};

class Shape {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_301790 *vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    char pad08[0x14 - 4];
    Span_301790 *span;
    char pad18[0x34 - 0x18];
    float radius;
    char pad38[0x44 - 0x38];
    Vec3_301790 axis;
    float f50;
    float f54;
    char b58;
    void thunk_FUN_002fb860(Vec3_301790 *out, int i);
};

// Locals of the original's 0x40-byte frame.
struct Frame_301790 {
    float d0;
    float f4;
    float f8;
    float f12;
    Vec3_301790 v16;
    Vec3_301790 v28;
    Vec3_301790 v40;
    Vec3_301790 v52;
};

class Solver_301790 {
public:
    char pad0[0xc];
    float margin;
    char pad10[4];
    Vec3_301790 rel;
    void FUN_00314be0(Shape *s, Vec3_301790 *a, Plane_301790 *p, Vec3_301790 *b, float d, const Vec3_301790 *n);
    void FUN_00302c20(Shape *s, Plane_301790 *p);
    void FUN_00301790(Plane_301790 *a0, Shape *shape);
};

void Solver_301790::FUN_00301790(Plane_301790 *a0, Shape *shape)
{
    Frame_301790 f;
    Vec3_301790 *pc = a0->vfunc_4();
    Vec3_301790 *sc = shape->vfunc_4();
    rel.x = sc->x - pc->x;
    rel.y = sc->y - pc->y;
    rel.z = sc->z - pc->z;
    const Vec3_301790 *n = &a0->normal;
    f.d0 = n->z * rel.z + n->y * rel.y + n->x * rel.x;
    if (f.d0 > shape->radius + margin)
        return;

    if (shape->span && ((shape->span->end - shape->span->begin) & 0xfffffffc)) {
        switch (shape->vfunc_6()) {
        case 0:
        case 7:
            FUN_00302c20(shape, a0);
            return;
        case 2: {
            float t = n->z * shape->axis.z + n->y * shape->axis.y + n->x * shape->axis.x;
            *(int *)&t &= 0x7fffffff;
            if (!(f.d0 - (t * shape->f50 + shape->f54) <= margin))
                return;
            FUN_00302c20(shape, a0);
            return;
        }
        case 5: {
            for (int i = 0; i < 4; i++) {
                shape->thunk_FUN_002fb860(&f.v40, i);
                float t = f.v40.z * n->z + f.v40.y * n->y + f.v40.x * n->x;
                *(int *)&t &= 0x7fffffff;
                if (f.d0 - t < margin) {
                    FUN_00302c20(shape, a0);
                    return;
                }
            }
            return;
        }
        default:
            return;
        }
    }

    switch (shape->vfunc_6()) {
    case 0:
    case 7: {
        float res = f.d0 - shape->radius;
        float k = -shape->radius;
        Vec3_301790 *c = shape->vfunc_4();
        f.v16.FUN_001f6bc0(c, k, n);
        if (!(res < margin))
            return;
        f.v28.FUN_001f6bc0(&f.v16, -res, n);
        FUN_00314be0(shape, &f.v16, a0, &f.v28, res, n);
        return;
    }
    case 2: {
        const Vec3_301790 *ax = &shape->axis;
        if (!shape->b58) {
            f.f12 = n->z * ax->z + n->y * ax->y + n->x * ax->x;
            float a = f.f12;
            *(int *)&a &= 0x7fffffff;
            float res = f.d0 - (a * shape->f50 + shape->f54);
            if (!(res <= margin))
                return;
            float k = -(FUN_00083d90(&f.f12) * shape->f50);
            Vec3_301790 *c = shape->vfunc_4();
            f.v16.FUN_001f6bc0(c, k, ax);
            f.v16.FUN_001f6bc0(&f.v16, -shape->f54, n);
            f.v28.FUN_001f6bc0(&f.v16, -res, n);
            FUN_00314be0(shape, &f.v16, a0, &f.v28, res, n);

            float a2 = f.f12;
            *(int *)&a2 &= 0x7fffffff;
            float res2 = f.d0 - (shape->f54 - a2 * shape->f50);
            if (!(res2 <= margin))
                return;
            float k2 = -(FUN_00083d90(&f.f12) * shape->f50);
            Vec3_301790 *c2 = shape->vfunc_4();
            f.v16.FUN_001f6bc0(c2, k2, ax);
            f.v16.FUN_001f6bc0(&f.v16, -shape->f54, n);
            f.v28.FUN_001f6bc0(&f.v16, -res2, n);
            FUN_00314be0(shape, &f.v16, a0, &f.v28, res2, n);
            return;
        }
        f.v28.FUN_000111b0(ax, n);
        f.v16.FUN_000111b0(ax, &f.v28);
        f.v16.FUN_0022d180();
        f.f4 = (f.v16.y * n->y + f.v16.z * n->z + f.v16.x * n->x) * shape->f54;
        float absS = f.f4;
        *(int *)&absS &= 0x7fffffff;
        f.f8 = (n->z * ax->z + n->y * ax->y + ax->x * n->x) * shape->f50;
        f.f12 = f.f8;
        *(int *)&f.f12 &= 0x7fffffff;
        float res1 = f.d0 - absS - f.f12;
        if (res1 < margin) {
            float k1 = -(FUN_00083d90(&f.f4) * shape->f54);
            Vec3_301790 *c = shape->vfunc_4();
            f.v40.FUN_001f6bc0(c, k1, &f.v16);
            float k2 = -(FUN_00083d90(&f.f8) * shape->f50);
            f.v40.FUN_001f6bc0(&f.v40, k2, ax);
            f.v52.FUN_001f6bc0(&f.v40, -res1, n);
            FUN_00314be0(shape, &f.v40, a0, &f.v52, res1, n);
        }
        float absS2 = f.f4;
        *(int *)&absS2 &= 0x7fffffff;
        f.f12 = f.f8;
        *(int *)&f.f12 &= 0x7fffffff;
        float res2 = f.d0 - absS2 + f.f12;
        if (!(res2 < margin))
            return;
        float k1 = -(FUN_00083d90(&f.f4) * shape->f54);
        Vec3_301790 *c = shape->vfunc_4();
        f.v40.FUN_001f6bc0(c, k1, &f.v16);
        float k2 = FUN_00083d90(&f.f8) * shape->f50;
        f.v40.FUN_001f6bc0(&f.v40, k2, ax);
        f.v52.FUN_001f6bc0(&f.v40, -res2, n);
        FUN_00314be0(shape, &f.v40, a0, &f.v52, res2, n);
        return;
    }
    case 5: {
        for (int i = 0; i < 4; i++) {
            shape->thunk_FUN_002fb860(&f.v28, i);
            f.f12 = f.v28.y * n->y + f.v28.z * n->z + f.v28.x * n->x;
            float a = f.f12;
            *(int *)&a &= 0x7fffffff;
            float res = f.d0 - a;
            if (!(res < margin))
                continue;
            f.f8 = -FUN_00083d90(&f.f12);
            Vec3_301790 *c = shape->vfunc_4();
            f.v16.x = f.f8 * f.v28.x + c->x;
            f.v16.y = f.v28.y * f.f8 + c->y;
            f.v16.z = f.v28.z * f.f8 + c->z;
            f.v28.x = -res * n->x + f.v16.x;
            f.v28.y = -res * n->y + f.v16.y;
            f.v28.z = -res * n->z + f.v16.z;
            FUN_00314be0(shape, &f.v16, a0, &f.v28, res, n);
        }
        return;
    }
    default:
        return;
    }
}
