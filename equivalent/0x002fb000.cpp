// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_002fb000 @ 0x002fb000
// FUN_002fb000 @ 0x002fb000
struct V3 { float x, y, z; };

struct Tri;

struct Mesh {
    char pad0[8];
    V3* verts;
    char pad1[0x18 - 0xc];
    Tri* tris;
};

struct Context {
    char pad[0x44];
    Mesh* mesh;
};

class Shape {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3* v4(); // the shape's reference point, tested against the triangle
};

struct Registry {
    char FUN_00304530(Shape* shape, unsigned int index, float depth, V3* o1, V3* o2, Context* ctx, int flags);
};
struct Manager { char pad[0x1b0]; Registry reg; };
extern Manager* DAT_00554c14;

void FUN_002fa6b0(V3* a, V3* b, V3* c, V3* normal);
char FUN_00359260(V3* ref, float margin, V3* a, V3* b, V3* c, V3* n, float* depth, V3* o1, V3* o2,
                  int f1, int f2, int f3);

union Flag { char b; int w; };
struct Frame {
    float margin;
    float depth;
    Flag f3;
    Flag f2;
    Flag f1;
    int touch;
    V3 normal;
    V3 o2;
    V3 o1;
};

class Tri {
public:
    char run(Shape* shape, Context* ctx, int flags);
    char pad0[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short triFlags;
    char pad1[8];
};

char Tri::run(Shape* shape, Context* ctx, int flags)
{
    Frame f;
    V3* verts = ctx->mesh->verts;
    V3* v0 = &verts[i0];
    V3* v1 = &verts[i1];
    V3* v2 = &verts[i2];

    FUN_002fa6b0(v0, v1, v2, &f.normal);

    f.f1.b = (triFlags & 1) != 0;
    f.f2.b = (triFlags & 2) == 2;
    f.f3.b = (triFlags & 4) == 4;
    f.margin = *(float*)((char*)shape + 0x34);
    f.touch = flags & 1;
    if (f.touch)
        f.margin = 0.02f + f.margin;

    char hit = FUN_00359260(shape->v4(), f.margin, v0, v1, v2, &f.normal, &f.depth, &f.o1, &f.o2,
                             f.f1.w, f.f2.w, f.f3.w);
    if (f.touch)
        f.depth = 0.02f + f.depth;
    if (hit) {
        unsigned int index = (unsigned int)((char*)this - (char*)ctx->mesh->tris) / 24;
        DAT_00554c14->reg.FUN_00304530(shape, index, f.depth, &f.o1, &f.o2, ctx, flags);
    }
    return hit;
}
