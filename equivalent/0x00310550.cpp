// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 22/22)
// FUN_00310550 @ 0x00310550
struct Vec3 {
    float x, y, z;
};

struct Mat4 {
    float m[16];
    void FUN_0022c0b0();
    void FUN_0022c3b0(Vec3* in, Vec3* out);
};

struct SymMatrix {
    int vptr;
    int m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
    void FUN_002fd0a0();
    void FUN_002fcaf0(SymMatrix* other);
    void FUN_002fcd60(void* basis);
    void FUN_002fd0c0(SymMatrix* total);
};

struct Joint {
    Joint* FUN_0030f100();
};

struct Link {
    Joint* FUN_0030edf0();
};

struct Manager {
    Link* FUN_0030f490(int index);
};

struct Owner {
    char pad00[0x40];
    Vec3 pos;
    char pad4c[0x94 - 0x4c];
    char frozen;
};

struct Body {
    char pad00[4];
    char active;
    char pad05[0x38 - 5];
    float mass;
    char pad3c[0x68 - 0x3c];
    int inertia[6];
    float ax, ay, az;
    char pad8c[0xd4 - 0x8c];
    float bx, by, bz;
};

void FUN_00305b00(SymMatrix* out, Vec3* offset, float mass);

struct Frame {
    Vec3 v;
    SymMatrix s2;
    Vec3 w;
    SymMatrix s1;
    Mat4 m;
};

class Rigid {
public:
    char pad00[0x10];
    Owner* owner;
    char pad14[0x40 - 0x14];
    float mass;
    float invMass;
    char pad48[0x58 - 0x48];
    Mat4 mat;
    float cx, cy, cz;
    char flaga4;
    char pada5[3];
    Vec3 localCenter;
    Vec3 refPoint;
    char padc0[0xdc - 0xc0];
    SymMatrix inertiaBody;
    SymMatrix total;
    SymMatrix inertiaWorld;
    char pad130[0x1f8 - 0x130];
    Body** bodies;
    char pad1fc[4];
    int count;
    char pad204[4];
    Manager* manager;
    float time;
    float timeMax;

    void FUN_00310550();
};

void Rigid::FUN_00310550()
{
    if (!(mass > 0.0f))
        return;
    if (!(time >= timeMax))
        return;
    if (owner->frozen)
        return;

    Frame f;
    time = 0;
    cz = 0;
    cy = 0;
    cx = 0;
    for (int i = 0; i < count; i++) {
        Body* b = bodies[i];
        if (b->mass > 0.0f && b->active) {
            f.v.x = b->bx + b->ax;
            f.v.y = b->by + b->ay;
            f.v.z = b->bz + b->az;
            float mass1 = bodies[i]->mass;
            cx = f.v.x * mass1 + cx;
            cy = f.v.y * mass1 + cy;
            cz = f.v.z * mass1 + cz;
        }
    }
    cx = invMass * cx;
    cy = invMass * cy;
    cz = invMass * cz;
    Vec3* op = &owner->pos;
    f.w.x = cx - op->x;
    f.w.y = cy - op->y;
    f.w.z = cz - op->z;
    f.m = mat;
    f.m.FUN_0022c0b0();
    f.m.FUN_0022c3b0(&f.w, &localCenter);
    flaga4 = 0;
    f.s1.FUN_002fca90();
    f.s2.FUN_002fca90();
    total.FUN_002fd0a0();
    for (int i = 0; i < count; i++) {
        Body* b = bodies[i];
        if (b->mass > 0.0f && b->active) {
            f.v.x = b->ax + b->bx;
            f.v.y = b->ay + b->by;
            f.v.z = b->az + b->bz - cz;
            f.v.x = f.v.x - cx;
            f.v.y = f.v.y - cy;
            FUN_00305b00(&f.s1, &f.v, bodies[i]->mass);
            Body* b2 = bodies[i];
            f.s2.m[0] = b2->inertia[0];
            f.s2.m[1] = b2->inertia[1];
            f.s2.m[2] = b2->inertia[2];
            f.s2.m[3] = b2->inertia[3];
            f.s2.m[4] = b2->inertia[4];
            f.s2.m[5] = b2->inertia[5];
            f.s2.FUN_002fcd60(manager->FUN_0030f490(i)->FUN_0030edf0()->FUN_0030f100());
            f.s1.FUN_002fcaf0(&f.s2);
            total.FUN_002fcaf0(&f.s1);
        }
    }
    inertiaBody.m[0] = total.m[0];
    inertiaBody.m[1] = total.m[1];
    inertiaBody.m[2] = total.m[2];
    inertiaBody.m[3] = total.m[3];
    inertiaBody.m[4] = total.m[4];
    inertiaBody.m[5] = total.m[5];
    f.m = mat;
    f.m.FUN_0022c0b0();
    inertiaBody.FUN_002fcd60(&f.m);
    inertiaWorld.FUN_002fd0c0(&total);
    mat.FUN_0022c3b0(&refPoint, &f.v);
    cx = f.v.x + cx;
    cy = f.v.y + cy;
    cz = f.v.z + cz;
    f.s2.FUN_002fcaa0();
    f.s1.FUN_002fcaa0();
}
