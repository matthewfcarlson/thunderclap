// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 6/6)
// FUN_002fb190 @ 0x002fb190
#include "decls/data/game/global.h"
#include "compat/ptr.h"

struct V3_2fb190 { float x, y, z; };

struct Tri_2fb190;

struct Mesh_2fb190 {
    char pad0[8];
    V3_2fb190* verts;
    char pad1[0x18 - 0xc];
    Tri_2fb190* tris;
};

struct Context {
    char pad[0x44];
    Mesh_2fb190* mesh;
};

struct CollisionRay_2fb190 {
    char data[0x84];
    void FUN_00306ef0(const V3_2fb190* origin, const V3_2fb190* dir, unsigned int mask);
    void FUN_00306fb0();
};

struct Registry_2fb190 {
    char FUN_00304530(CollisionRay_2fb190* shape, unsigned int index, float depth, V3_2fb190* o1, V3_2fb190* o2, Context* ctx, int flags);
};
struct Manager_2fb190 { char pad[0x1b0]; Registry_2fb190 reg; };

void FUN_002fa6b0(V3_2fb190* a, V3_2fb190* b, V3_2fb190* c, V3_2fb190* normal);

class Tri_2fb190 {
public:
    char run(V3_2fb190* p, Context* ctx, int flags);
    char pad0[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short triFlags;
    char pad1[8];
};

static inline float absf(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}

// x87: the three edge tests and the plane distance stay in registers (53 bits)
char Tri_2fb190::run(V3_2fb190* p, Context* ctx, int flags)
{
    struct Frame {
        float diff;
        V3_2fb190 n;
        V3_2fb190 hit;
        V3_2fb190 dir;
        CollisionRay_2fb190 obj;
    } f;
    V3_2fb190* verts = ctx->mesh->verts;
    V3_2fb190* v0 = &verts[i0];
    V3_2fb190* v1 = &verts[i1];
    V3_2fb190* v2 = &verts[i2];

    hulk_freg t1 = (v2->z - v1->z) * (p->x - v1->x) - (v2->x - v1->x) * (p->z - v1->z);
    hulk_freg t2 = (v1->z - v0->z) * (p->x - v0->x) - (p->z - v0->z) * (v1->x - v0->x);
    if (!(t2 * t1 >= 0.0f))
        return 0;
    hulk_freg t3 = (v0->z - v2->z) * (p->x - v2->x) - (p->z - v2->z) * (v0->x - v2->x);
    if (!(t3 * t1 >= 0.0f))
        return 0;

    FUN_002fa6b0(v0, v1, v2, &f.n);
    if (absf(f.n.y) <= 1e-5f)
        return 0;

    hulk_freg plane = f.n.y * v0->y + f.n.x * v0->x + f.n.z * v0->z;
    f.hit.x = p->x;
    f.hit.z = p->z;
    f.dir.x = 0.0f;
    f.dir.y = -1.0f;
    f.dir.z = 0.0f;
    double neg = -plane;
    double part = neg + f.n.z * p->z;
    f.hit.y = (float)((part + f.n.x * p->x) * (-1.0f / f.n.y));
    f.diff = p->y - f.hit.y;

    f.obj.FUN_00306ef0(p, &f.dir, 0x5368d4a5);
    unsigned int index = (unsigned int)((char*)this - (char*)ctx->mesh->tris) / 24;
    (*(Manager_2fb190**)&DAT_00554c14)->reg.FUN_00304530(&f.obj, index, f.diff, &f.hit, &f.n, ctx, flags);
    f.obj.FUN_00306fb0();
    return 1;
}
