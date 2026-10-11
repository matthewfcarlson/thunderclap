// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002fb190 @ 0x002fb190
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

struct Query {
    char data[0x84];
    void FUN_00306ef0(const V3* origin, const V3* dir, unsigned int mask);
    void FUN_00306fb0();
};

struct Registry {
    char FUN_00304530(Query* shape, unsigned int index, float depth, V3* o1, V3* o2, Context* ctx, int flags);
};
struct Manager { char pad[0x1b0]; Registry reg; };
extern Manager* DAT_00554c14;

void FUN_002fa6b0(V3* a, V3* b, V3* c, V3* normal);

class Tri {
public:
    char run(V3* p, Context* ctx, int flags);
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

char Tri::run(V3* p, Context* ctx, int flags)
{
    struct Frame {
        float diff;
        V3 n;
        V3 hit;
        V3 dir;
        Query obj;
    } f;
    V3* verts = ctx->mesh->verts;
    V3* v0 = &verts[i0];
    V3* v1 = &verts[i1];
    V3* v2 = &verts[i2];

    float t1 = (v2->z - v1->z) * (p->x - v1->x) - (v2->x - v1->x) * (p->z - v1->z);
    float t2 = (v1->z - v0->z) * (p->x - v0->x) - (p->z - v0->z) * (v1->x - v0->x);
    if (!(t2 * t1 >= 0.0f))
        return 0;
    float t3 = (v0->z - v2->z) * (p->x - v2->x) - (p->z - v2->z) * (v0->x - v2->x);
    if (!(t3 * t1 >= 0.0f))
        return 0;

    FUN_002fa6b0(v0, v1, v2, &f.n);
    if (absf(f.n.y) <= 1e-5f)
        return 0;

    float plane = f.n.y * v0->y + f.n.x * v0->x + f.n.z * v0->z;
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
    DAT_00554c14->reg.FUN_00304530(&f.obj, index, f.diff, &f.hit, &f.n, ctx, flags);
    f.obj.FUN_00306fb0();
    return 1;
}
