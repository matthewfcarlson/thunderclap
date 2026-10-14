// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 27/28, incomplete)
// physics::PhysicsJoint::vfunc_14 @ 0x0030a410
extern "C" double sqrt(double);

struct Vec3_30a410 {
    float x, y, z;
    void FUN_000111b0(Vec3_30a410* a, Vec3_30a410* b);
};

struct Basis_30a410 {
    void FUN_002fd020(Vec3_30a410* in, Vec3_30a410* out);
};

extern float DAT_004d31b0;
extern float DAT_004d3184;
extern float DAT_00555450;

namespace physics {

class PhysicsJoint;

struct JointEntry {
    char pad00[0x18];
    float limit;
};

struct JointTable {
    char pad00[0x10];
    JointEntry* entries;
};

class PhysicsJoint {
public:
    virtual void vfunc_0();
    char active;
    char pad05[3];
    int index;
    char pad0c[0x18 - 0xc];
    class PhysicsObjectBase* owner;
    PhysicsJoint* child;
    char pad20[0xd4 - 0x20];
    Vec3_30a410 anchor;
    char padE0[0xe8 - 0xe0];
    float weight;
    char padEC;
    char flagED;
    char flagEE;
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13();
    virtual bool vfunc_14(Vec3_30a410* p1, Vec3_30a410* p2, Basis_30a410* basis);
    virtual void vfunc_15();
    virtual void vfunc_16(Vec3_30a410* in, Vec3_30a410* out);
    virtual void vfunc_17(Vec3_30a410* a, float len, Vec3_30a410* b);
    virtual void vfunc_18();
    virtual void vfunc_19(Vec3_30a410* v);
    virtual float vfunc_20(Vec3_30a410* v);
    virtual void vfunc_21(Vec3_30a410* v);
};

class PhysicsObjectBase {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26();
    virtual void vfunc_27(int a);
    char pad04[0x218 - 4];
    PhysicsJoint* current;
    char pad21c[4];
    JointTable* table;
    float scale;
};

bool PhysicsJoint::vfunc_14(Vec3_30a410* p1, Vec3_30a410* p2, Basis_30a410* basis)
{
    if (this == owner->current)
        return true;

    if (weight > 0.0f && !flagED && active) {
        struct Frame {
            Vec3_30a410 b;
            Vec3_30a410 a;
            Vec3_30a410 c;
            Vec3_30a410 d;
        } f;
        float len;

        f.a.x = p1->x - anchor.x;
        f.a.y = p1->y - anchor.y;
        f.a.z = p1->z - anchor.z;
        vfunc_16(&f.a, &f.a);
        len = (float)sqrt(f.a.z * f.a.z + f.a.y * f.a.y + f.a.x * f.a.x);
        basis->FUN_002fd020(p2, &f.b);

        f.b.x = f.b.x * weight;
        f.b.y = f.b.y * weight;
        f.b.z = f.b.z * weight;
        vfunc_17(&f.a, len, &f.b);

        double bmag = sqrt(f.b.z * f.b.z + f.b.y * f.b.y + f.b.x * f.b.x);
        float limit = owner->table->entries[index].limit;
        if (limit < len)
            limit = len;
        double t = limit / owner->scale * DAT_004d31b0;
        if (bmag > t) {
            flagEE = 1;
            weight = weight / bmag * t * 0.99f;
            return false;
        }

        float inv = 1.0f / bmag;
        float dot = (f.b.y * p2->y + f.b.z * p2->z + f.b.x * p2->x) * inv;
        if (!(dot > 0.0f) || !(bmag > DAT_00555450)) {
            weight = 0.0f;
            return false;
        }

        double s = inv * weight * dot;
        f.d.x = f.b.x * s;
        f.d.y = f.b.y * s;
        f.d.z = f.b.z * s;
        f.c.FUN_000111b0(&f.a, &f.b);
        double k = 1.0f / (len * len);
        f.c.x = f.c.x * k;
        f.c.y = f.c.y * k;
        f.c.z = f.c.z * k;
        float r = vfunc_20(&f.c);
        if (r < DAT_004d3184) {
            weight = r * weight;
            if (r == 0.0f)
                vfunc_21(&f.c);
            return false;
        }
        p2->x = p2->x - f.d.x;
        p2->y = p2->y - f.d.y;
        p2->z = p2->z - f.d.z;
        vfunc_19(&f.c);
        flagED = 1;
    } else if (weight > 0.0f) {
        float rest = 1.0f - weight;
        p2->x = p2->x * rest;
        p2->y = p2->y * rest;
        p2->z = p2->z * rest;
    }

    float ax = p2->x < 0 ? -p2->x : p2->x;
    float ay = p2->y < 0 ? -p2->y : p2->y;
    float az = p2->z < 0 ? -p2->z : p2->z;
    PhysicsJoint* c = child;
    if (az + ay + ax > 0.000001f) {
        if (c)
            return c->vfunc_14(p1, p2, basis);
        return true;
    }
    if (c)
        c->vfunc_3();
    else
        owner->vfunc_27(-1);
    return true;
}

}
