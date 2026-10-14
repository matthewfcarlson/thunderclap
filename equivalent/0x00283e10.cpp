// STATUS: equivalent (tools/equiv.py level 3: 158 inputs, branch coverage 26/28, incomplete)
// FUN_00283e10 @ 0x00283e10
// FUN_00283e10 @ 0x00283e10: queue a screen quad: clip it against the view planes and emit its vertices
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

typedef unsigned __int64 Key_283e10;

namespace pure3d { class Shader; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct V3_283e10 {
    float x, y, z;
    void FUN_00011090();
};

struct Mat4_283e10 {
    float m[16];
    void FUN_0022ba00();
    void FUN_0022be40(const V3_283e10 *pos);
    void FUN_0022bec0(const V3_283e10 *fwd, const V3_283e10 *up);
    void FUN_0022c120();
    void FUN_0022c410(int n, const V3_283e10 *src, V3_283e10 *dst);
};

struct Plane_283e10 {
    float a, b, c, d;
    void FUN_00078850();
    void FUN_0022dfe0(const V3_283e10 *p0, const V3_283e10 *p1, const V3_283e10 *p2);
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3_283e10::*ctor)());
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Plane_283e10::*ctor)());

struct Vert {
    V3_283e10 pos;
    float w;
    float uv[2];
};

struct Clip {
    char data[0x48];
};

class Renderer_283e10 {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void v13(const V3_283e10 *pos, float w, const float *uv);
};

class Batch_283e10 {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual Renderer_283e10 *v4();
    virtual void v5(Renderer_283e10 *r);
    virtual void v6();
};

class Chunks_283e10 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void v6(unsigned int id, int flag);
};

class Shader {
public:
    virtual void addRef();
    virtual void release();
    char pad4[0xc];
    Chunks_283e10 *chunks;
};

class Loader_283e10 {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual Shader *v3(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, Key_283e10 key);
};

struct World {
    void FUN_002f3830(V3_283e10 *out, int a1);
};

struct Slot_283e10 {
    unsigned int id;
    int tag;
    Shader *shader;
    V3_283e10 pos;
    Batch_283e10 *batch;
};

int __cdecl FUN_00266da0(int mode);
void __cdecl FUN_00281fd0(World *w, float *size, Mat4_283e10 *m, int n, void **objs, Clip *clips);
void __cdecl FUN_00281e60(Plane_283e10 *planes, Clip *clip, Vert *out, int *n);

class Target_283e10;

struct Frame_283e10 {
    union {
        float negHalfH;          // 0x00
        int nloc;
    } u0;
    union {
        Slot_283e10 *slot;              // 0x04
        Batch_283e10 *batch;
    } u4;
    int cnt;                     // 0x08
    Target_283e10 *self;                // 0x0c
    int stash10;                 // 0x10
    unsigned int c;              // 0x14
    Shader *shader;              // 0x18
    content::LoadInventory::DynamicCaster<pure3d::Shader> caster;  // 0x1c
    int oldMode;                 // 0x20
    V3_283e10 out24;                    // 0x24
    V3_283e10 corners[4];               // 0x30
    V3_283e10 p;                        // 0x60
    Mat4_283e10 m;                      // 0x6c
    Plane_283e10 planes[4];             // 0xac
    Mat4_283e10 m2;                     // 0xec
    void *objs[40];              // 0x12c
    Clip clips[40];              // 0x1cc
    Vert verts[0x42];            // 0xd0c
    char unused[0x7d8c - 0xd0c - 0x42 * 0x18];
};

class Target_283e10 {
public:
    char pad0[0x10];
    unsigned int counter;        // 0x10
    int count;                   // 0x14
    Loader_283e10 *loader;              // 0x18
    int mode;                    // 0x1c
    Slot_283e10 slots[100];             // 0x20
    unsigned int FUN_00283e10(Key_283e10 *key, int a1, World *world, V3_283e10 *pos, V3_283e10 *up, float *size, int a6, int a7);
    void FUN_002809b0(World *w, V3_283e10 *pos, float radius, int a1, int a1b, void **out, int *cnt, int max, int z0, int z1);
};

unsigned int Target_283e10::FUN_00283e10(Key_283e10 *key, int a1, World *world, V3_283e10 *pos, V3_283e10 *up, float *size, int a6, int a7)
{
    Frame_283e10 f;
    int i;
    f.self = this;
    new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Shader>;
    f.shader = loader->v3(&f.caster, *key);
    if (f.shader == 0)
        return 0;
    int n0 = count;
    if (n0 <= 1)
        return 0;
    f.c = counter;
    Slot_283e10 *slot = &slots[f.c % 100];
    f.u4.slot = slot;
    count = n0 - 1;
    f.shader->chunks->v6(0x444d5655, 1);
    world->FUN_002f3830(&f.out24, a1);
    f.m.FUN_0022ba00();
    f.m.FUN_0022be40(pos);
    f.m.FUN_0022bec0(&f.out24, up);
    memcpy(&f.m2, &f.m, sizeof(Mat4_283e10));
    f.m2.FUN_0022c120();
    FUN_00011520(f.planes, 0x10, 4, &Plane_283e10::FUN_00078850);
    FUN_00011520(f.corners, 0xc, 4, &V3_283e10::FUN_00011090);
    float hw = size[0] * 0.5f;
    float hh = size[1] * 0.5f;
    f.corners[0].z = 0;
    f.corners[1].z = 0;
    f.corners[2].z = 0;
    f.corners[3].z = 0;
    f.corners[0].x = -hw;
    f.u0.negHalfH = -hh;
    f.corners[0].y = f.u0.negHalfH;
    f.corners[3].y = f.u0.negHalfH;
    f.corners[1].x = -hw;
    f.corners[1].y = hh;
    f.corners[2].x = hw;
    f.corners[2].y = hh;
    f.corners[3].x = hw;
    f.m.FUN_0022c410(4, f.corners, f.corners);
    for (i = 0; i < 4; i++) {
        f.p.x = f.out24.x + f.corners[i].x;
        f.p.y = f.out24.y + f.corners[i].y;
        f.p.z = f.out24.z + f.corners[i].z;
        f.planes[i].FUN_0022dfe0(&f.corners[i], &f.corners[(i + 1) % 4], &f.p);
        f.planes[i].a = f.planes[i].a * -1.0f;
        f.planes[i].b = f.planes[i].b * -1.0f;
        f.planes[i].c = f.planes[i].c * -1.0f;
        f.planes[i].d = f.planes[i].d * -1.0f;
    }
    f.cnt = 0;
    float radius = (size[0] < size[1] ? size[1] : size[0]) * 0.71f;
    FUN_002809b0(world, pos, radius, a1, a1, f.objs, &f.cnt, 0x28, 0, 0);
    FUN_00281fd0(world, size, &f.m2, f.cnt, f.objs, f.clips);
    int total = 0;
    int cnt = f.cnt;
    if (cnt > 0) {
        for (i = 0; i < f.cnt; i++) {
            FUN_00281e60(f.planes, &f.clips[i], &f.verts[total], &f.u0.nloc);
            total += f.u0.nloc;
        }
        if (total > 0) {
            f.oldMode = FUN_00266da0(mode);
            if (total >= 0x42)
                total = 0x42;
            f.u4.batch = slot->batch;
            Renderer_283e10 *r = f.u4.batch->v4();
            for (i = 0; i < total; i++)
                r->v13(&f.verts[i].pos, f.verts[i].w, f.verts[i].uv);
            if (total < 0x42) {
                Vert *last = &f.verts[total - 1];
                for (i = 0x42 - total; i > 0; i--)
                    r->v13(&last->pos, last->w, last->uv);
            }
            f.u4.batch->v5(r);
            f.u4.batch->v6();
            FUN_00266da0(f.oldMode);
        }
    }
    f.shader->addRef();
    if (slot->shader != 0)
        slot->shader->release();
    slot->shader = f.shader;
    slot->tag = a7;
    slot->id = f.c;
    slot->pos = *pos;
    counter = counter + 1;
    return f.c;
}
