// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 33/41, incomplete)
// FUN_002f19d0 @ 0x002f19d0
struct Vec3 {
    float x, y, z;
};

struct Vec3Thiscall : Vec3 {
    void FUN_00011160(float scale, const float *dir);
};

union FloatBits {
    float f;
    unsigned int u;
};

static float AbsF(float x)
{
    FloatBits b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

class Shape;

struct ShapeList {
    Shape **begin;
    Shape **end;
};

class Shape {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3 *Center();
    virtual void v5();
    virtual int Type();
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void Prepare();
    char pad04[0x10];
    ShapeList *children;
    char pad18;
    char ready;
    char pad1a[0xe];
    float boxHalf[3];
    float radius;
    int axisAligned;
    char pad3c[8];
    union {
        struct {
            float axis[3];
            float halfLength;
            float radius2;
            char flat;
        } capsule;
        struct {
            float pad44;
            float half[3];
            float axes[9];
        } box;
    };
};

bool FUN_002f19d0(Vec3 *p, Shape *shape)
{
    if (!shape->ready)
        shape->Prepare();

    Vec3 *c = shape->Center();
    Vec3Thiscall d;
    d.x = p->x - c->x;
    d.y = p->y - c->y;
    d.z = p->z - c->z;

    switch (shape->Type()) {
    case 1:
        if (!(AbsF(d.x) <= shape->boxHalf[0]))
            return false;
        if (!(AbsF(d.y) <= shape->boxHalf[1]))
            return false;
        if (!(AbsF(d.z) <= shape->boxHalf[2]))
            return false;
        for (unsigned int i = 0; i < (unsigned int)(shape->children->end - shape->children->begin); i++) {
            if (FUN_002f19d0(p, shape->children->begin[i]))
                return true;
        }
        return false;

    case 2: {
        double t = (double)d.z * shape->capsule.axis[2] + (double)d.y * shape->capsule.axis[1] + (double)d.x * shape->capsule.axis[0];
        double lim;
        if (shape->capsule.flat)
            lim = 0.0f;
        else
            lim = shape->capsule.radius2;
        float tf = (float)t;
        lim = lim + shape->capsule.halfLength;
        if (!(lim >= AbsF(tf)))
            return false;
        d.FUN_00011160(-tf, shape->capsule.axis);
        double sum = (double)d.z * d.z + (double)d.y * d.y + (double)d.x * d.x;
        return sum <= shape->capsule.radius2;
    }

    case 5:
        if (shape->axisAligned == 0) {
            const float *m = shape->box.axes;
            float t0 = (float)((double)d.z * m[2] + (double)d.y * m[1] + (double)d.x * m[0]);
            if (!(AbsF(t0) <= shape->box.half[0]))
                return false;
            float t1 = (float)((double)d.z * m[5] + (double)d.y * m[4] + (double)d.x * m[3]);
            if (!(AbsF(t1) <= shape->box.half[1]))
                return false;
            float t2 = (float)((double)d.z * m[8] + (double)d.y * m[7] + (double)d.x * m[6]);
            return AbsF(t2) <= shape->box.half[2];
        }
        if (!(AbsF(d.x) <= shape->box.half[0]))
            return false;
        if (!(AbsF(d.y) <= shape->box.half[1]))
            return false;
        return AbsF(d.z) <= shape->box.half[2];

    case 7: {
        double sum = (double)d.z * d.z + (double)d.y * d.y + (double)d.x * d.x;
        double r2 = (double)shape->radius * shape->radius;
        return r2 >= sum;
    }
    }
    return false;
}
