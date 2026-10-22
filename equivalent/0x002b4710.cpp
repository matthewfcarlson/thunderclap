// STATUS: equivalent (tools/equiv.py level 3: 154 inputs, branch coverage 4/4)
// FUN_002b4710 @ 0x002b4710
#include "compat/ptr.h"
#include "decls/address.h"
struct Stream {
    char pad0[0x8];
    float *pos;
    char pad1[4];
    int *flag;
    void FUN_0008ef00();
};
struct Idx { unsigned short a, b, c; unsigned short pad[3]; };
struct Vec3_2b4710 { float x, y, z; };
struct MeshA { char pad0[0xc]; unsigned int count; Idx *indices; };
struct MeshB { char pad0[0x10]; Vec3_2b4710 *verts; Vec3_2b4710 *offsets; };
class Obj_2b4710 {
public:
    char pad0[0x44];
    MeshA *a;
    MeshB *b;
    void FUN_002b4710();
};
class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Stream *v30(int a, int b, int c, int d, int e);
    virtual void v31(Stream *s);
};

void Obj_2b4710::FUN_002b4710()
{
    unsigned int n = a->count;
    Stream *s = DAT_0052c2a8->v30(0, 2, 0x2020, n * 2, 0);
    Idx *idx = a->indices;
    Vec3_2b4710 *q = b->offsets;
    Vec3_2b4710 *v = b->verts;
    for (unsigned int i = 0; i < n; i++) {
        const Vec3_2b4710 &p0 = v[idx[i].a];
        const Vec3_2b4710 &p1 = v[idx[i].b];
        const Vec3_2b4710 &p2 = v[idx[i].c];
        hulk_freg mx = (p1.x - p0.x) * 0.5f + p0.x;
        hulk_freg my = (p1.y - p0.y) * 0.5f + p0.y;
        float mz = (p1.z - p0.z) * 0.5f + p0.z;
        hulk_freg nx = (p2.x - mx) * 0.5f + mx;
        hulk_freg ny = (p2.y - my) * 0.5f + my;
        hulk_freg nz = (p2.z - mz) * 0.5f + mz;
        *s->flag = -1;
        s->pos[0] = nx;
        s->pos[1] = ny;
        s->pos[2] = nz;
        s->FUN_0008ef00();
        hulk_freg x2 = nx + q[i].x;
        hulk_freg y2 = ny + q[i].y;
        hulk_freg z2 = nz + q[i].z;
        *s->flag = -1;
        s->pos[0] = x2;
        s->pos[1] = y2;
        s->pos[2] = z2;
        s->FUN_0008ef00();
    }
    DAT_0052c2a8->v31(s);
}
