// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_002faa30 @ 0x002faa30
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

struct V3_2faa30 {
    float x, y, z;
};

struct Box_2faa30 {
    V3_2faa30 lo;
    V3_2faa30 hi;
    char FUN_002f3360(Box_2faa30 *other);
};

struct Tri_2faa30;

struct Mesh_2faa30 {
    char pad0[8];
    V3_2faa30 *verts;
    char pad1[0x18 - 0xc];
    Tri_2faa30 *tris;
};

struct Context {
    char pad[0x44];
    Mesh_2faa30 *mesh;
};

struct Basis_2faa30 {
    V3_2faa30 pos;
    char pad0c[0xc];
    V3_2faa30 axisX;                        // 0x18
    V3_2faa30 axisY;                        // 0x24
    V3_2faa30 axisZ;                        // 0x30
};

class Shape_2faa30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_2faa30 *v4();                // the shape's reference point
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Basis_2faa30 *v15();
    char pad04[0x28 - 4];
    V3_2faa30 half;                         // 0x28
    char pad34[0x48 - 0x34];
    V3_2faa30 f48;                          // 0x48
};

struct Registry_2faa30 {
    char FUN_00304530(Shape_2faa30 *shape, unsigned int index, float depth, V3_2faa30 *o1, V3_2faa30 *o2, Context *ctx, int flags);
};
struct Manager_2faa30 {
    char pad[0x1b0];
    Registry_2faa30 reg;
};

void FUN_002fa6b0(V3_2faa30 *a, V3_2faa30 *b, V3_2faa30 *c, V3_2faa30 *normal);
char FUN_0035a2a0(V3_2faa30 *a1, V3_2faa30 *a2, V3_2faa30 *axisX, V3_2faa30 *axisY, V3_2faa30 *axisZ, V3_2faa30 *v0, V3_2faa30 *v1, V3_2faa30 *v2, V3_2faa30 *normal,
                  float *depth, V3_2faa30 *centre, V3_2faa30 *outN, int f1, int f2, int f4);

union Flag_2faa30 {
    char b;
    int w;
};

struct Frame_2faa30 {
    V3_2faa30 v2;
    V3_2faa30 v1;
    Box_2faa30 tri;
    float depth;
    V3_2faa30 vB;
    V3_2faa30 pt;
    V3_2faa30 v0;
    Box_2faa30 sb;
    char pad70[0x88 - 0x70];
    Flag_2faa30 f4;
    Flag_2faa30 f2;
    Flag_2faa30 f1;
    Basis_2faa30 *t2;
    Basis_2faa30 *t3;
    V3_2faa30 normal;
    V3_2faa30 centre;
    V3_2faa30 outN;
};

class Tri_2faa30 {
public:
    char FUN_002faa30(Shape_2faa30 *shape, Context *ctx, int flags);
    char pad0[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short triFlags;
    char pad1[8];
};

char Tri_2faa30::FUN_002faa30(Shape_2faa30 *shape, Context *ctx, int flags)
{
    Frame_2faa30 f;
    V3_2faa30 *verts = ctx->mesh->verts;
    f.v0 = verts[i0];
    f.v1 = verts[i1];
    f.v2 = verts[i2];

    if (f.v0.x < f.v1.x) {
        f.tri.lo.x = f.v0.x;
        f.tri.hi.x = f.v1.x;
    } else {
        f.tri.hi.x = f.v0.x;
        f.tri.lo.x = f.v1.x;
    }
    if (f.tri.lo.x > f.v2.x)
        f.tri.lo.x = f.v2.x;
    else if (f.tri.hi.x < f.v2.x)
        f.tri.hi.x = f.v2.x;

    if (f.v0.y < f.v1.y) {
        f.tri.lo.y = f.v0.y;
        f.tri.hi.y = f.v1.y;
    } else {
        f.tri.hi.y = f.v0.y;
        f.tri.lo.y = f.v1.y;
    }
    if (f.tri.lo.y > f.v2.y)
        f.tri.lo.y = f.v2.y;
    else if (f.tri.hi.y < f.v2.y)
        f.tri.hi.y = f.v2.y;

    if (f.v0.z < f.v1.z) {
        f.tri.lo.z = f.v0.z;
        f.tri.hi.z = f.v1.z;
    } else {
        f.tri.hi.z = f.v0.z;
        f.tri.lo.z = f.v1.z;
    }
    if (f.tri.lo.z > f.v2.z)
        f.tri.lo.z = f.v2.z;
    else if (f.tri.hi.z < f.v2.z)
        f.tri.hi.z = f.v2.z;

    f.pt = *shape->v4();
    f.sb.hi.x = shape->half.x + f.pt.x;
    f.sb.hi.y = shape->half.y + f.pt.y;
    f.sb.hi.z = shape->half.z + f.pt.z;
    f.sb.lo.x = f.pt.x - shape->half.x;
    f.sb.lo.y = f.pt.y - shape->half.y;
    f.sb.lo.z = f.pt.z - shape->half.z;
    if (!f.tri.FUN_002f3360(&f.sb))
        return 0;

    FUN_002fa6b0(&f.v0, &f.v1, &f.v2, &f.normal);

    f.f1.b = (triFlags & 1) != 0;
    f.f2.b = (triFlags & 2) == 2;
    f.f4.b = (triFlags & 4) == 4;
    int touch = flags & 1;
    f.vB = shape->f48;
    if (touch) {
        f.vB.x = f.vB.x + DAT_004d2cb4;
        f.vB.y = f.vB.y + DAT_004d2cb4;
        f.vB.z = f.vB.z + DAT_004d2cb4;
    }
    Basis_2faa30 *b1 = shape->v15();
    f.t2 = shape->v15();
    f.t3 = shape->v15();
    Basis_2faa30 *b4 = shape->v15();
    char hit = FUN_0035a2a0(&b4->pos, &f.vB, &f.t3->axisX, &f.t2->axisY, &b1->axisZ, &f.v0, &f.v1, &f.v2,
                            &f.normal, &f.depth, &f.centre, &f.outN, f.f1.w, f.f2.w, f.f4.w);
    if (touch)
        f.depth = f.depth + DAT_004d2cb4;
    if (hit) {
        unsigned int index = (unsigned int)((char *)this - (char *)ctx->mesh->tris) / 24;
        (*(Manager_2faa30**)&DAT_00554c14)->reg.FUN_00304530(shape, index, f.depth, &f.centre, &f.outN, ctx, flags);
    }
    return hit;
}
