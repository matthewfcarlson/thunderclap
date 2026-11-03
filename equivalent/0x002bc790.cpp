// STATUS: equivalent (tools/equiv.py level 3: 15709 inputs, branch coverage 78/78)
// FUN_002bc790 @ 0x002bc790
#include "decls/address.h"
#include "gen/pure3d.h"
#include "gen/owners.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Vec3_2bc790 {
    float x, y, z;
};

namespace pure3d {
class Shader_2bc790;
}

namespace content {
struct LoadInventory_2bc790 {
    template <class T>
    class DynamicCaster {
    public:
        virtual void *v0() { return 0; }
    };
};
}

class Stream_2bc790 {
public:
};

class Reader_2bc790 {
public:
    char pad00[0x284];
    Stream_2bc790 *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class NameHolder_2bc790 {
public:
    char pad00[8];
};

class Child_2bc790 {
public:
    virtual void v0();
    virtual void v1();
};

class ChildList_2bc790 {
public:
    Child_2bc790 **begin;
    char pad04[8];
};

class Mat4_2bc790 {
public:
    float m[16];
    void FUN_0022ba20(const float *q);
};

class BillboardCutOffQuadGroup_2bc790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void *shader);
    char pad04[4];
    NameHolder_2bc790 name;
    char pad10[4];
    Vec3_2bc790 v14;
    Vec3_2bc790 v20;
    Vec3_2bc790 v2c;
    int i38;
    char pad3c[0x40 - 0x3c];
    Mat4_2bc790 mat40;
    char pad80[0x88 - 0x80];
    char b88;
    char b89;
    char b8a;
    char pad8b[1];
    ChildList_2bc790 list;
    int f98;
    int f9c;
    int fa0;
    float fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0;
    int fc4, fc8;
    char padcc[4];
    BillboardCutOffQuadGroup_2bc790 *FUN_002bc580();
    BillboardCutOffQuadGroup_2bc790 *FUN_002bc660();
};

struct Shader_nv_2bc790 {
    ::pure3d::Shader *FUN_0028edf0(const char *what, int flag);
};

class Factory_2bc790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ::pure3d::Shader *v3(content::LoadInventory_2bc790::DynamicCaster<pure3d::Shader_2bc790> *caster, unsigned __int64 id);
};

struct Parent_2bc790 {
    char pad00[8];
    NameHolder_2bc790 name;
    char pad10[0x40 - 0x10];
    float f40;
    char pad44[4];
    void *p48;
};

void *FUN_00263ea0(unsigned int size);
extern "C" double cos(double);
extern "C" void FUN_0028fcc0(const char *fmt, ...);

struct Frame_2bc790 {
    unsigned char pad10[3];
    unsigned char len;               // S+0x13 (byte count, then the type flag)
    int count;                       // 0x14
    int idx;                         // 0x18
    int slot1c;                      // 0x1c
    void *self;                      // 0x20
    float f;                         // 0x24
    unsigned int tag2;               // 0x28
    float c4;                        // 0x2c
    float c1;                        // 0x30
    float c0;                        // 0x34
    float c3;                        // 0x38
    float d1;                        // 0x3c
    float d2;                        // 0x40
    unsigned int e4;                 // 0x44
    float d3;                        // 0x48
    unsigned int e3;                 // 0x4c
    float c2;                        // 0x50
    unsigned int tag1;               // 0x54
    unsigned int e2;                 // 0x58
    float junkA;                     // 0x5c
    int junk2;                       // 0x60
    float j3;                        // 0x64
    float j4;                        // 0x68
    float j5;                        // 0x6c
    Vec3_2bc790 pos;                        // 0x70
    float q4[4];                     // 0x7c
    unsigned int name1[64];          // 0x8c
    unsigned int name2[64];          // 0x18c
};

class Group_2bc790 {
public:
    void FUN_002a46d0(void *a, BillboardCutOffQuadGroup_2bc790 *q);
    Child_2bc790 *FUN_002ba8d0(Reader_2bc790 *r, Factory_2bc790 *factory);
    void FUN_002a4b00(void *a, Reader_2bc790 *r, Factory_2bc790 *factory);
    void FUN_002bc790(Parent_2bc790 *parent, Reader_2bc790 *r, Factory_2bc790 *factory);
};

void Group_2bc790::FUN_002bc790(Parent_2bc790 *parent, Reader_2bc790 *r, Factory_2bc790 *factory)
{
    Frame_2bc790 fr;
    char *name1 = (char *)fr.name1;
    char *name2 = (char *)fr.name2;
    fr.self = this;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.f), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n1 = fr.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)name1, (hulk_intptr)n1, 1, (hulk_intptr)1);
    name1[n1] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n2 = fr.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)name2, (hulk_intptr)n2, 1, (hulk_intptr)1);
    name2[n2] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    fr.len = fr.count != 0;
    BillboardCutOffQuadGroup_2bc790 *o;
    if (fr.len == 1) {
        void *mem = FUN_00263ea0(0xd0);
        o = 0;
        if (mem != 0)
            o = ((BillboardCutOffQuadGroup_2bc790 *)mem)->FUN_002bc660();
    } else {
        void *mem = FUN_00263ea0(0x98);
        o = 0;
        if (mem != 0)
            o = ((BillboardCutOffQuadGroup_2bc790 *)mem)->FUN_002bc580();
    }
    FUN_002a46d0(parent->p48, o);
    ((owners::Target_27b040 *)&(parent->name))->FUN_0027b040((hulk_uintptr)name1);
    ((owners::Target_27b040 *)&(o->name))->FUN_0027b040((hulk_uintptr)name1);
    unsigned __int64 id = FUN_0027b020(name2);
    new (&fr.count) content::LoadInventory_2bc790::DynamicCaster<pure3d::Shader_2bc790>();
    ::pure3d::Shader *shader = factory->v3((content::LoadInventory_2bc790::DynamicCaster<pure3d::Shader_2bc790> *)&fr.count, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found for billboard quad group \"%s\"\n", name2, name1);
        void *mem2 = FUN_00263ea0(0x20);
        shader = 0;
        if (mem2 != 0)
            shader = ((Shader_nv_2bc790*)(((::pure3d::Shader *)mem2)))->FUN_0028edf0("error", 0);
    }
    o->v8(shader);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    o->b88 = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    o->b89 = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    o->b8a = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    fr.slot1c = 0;
    fr.idx = 0;
    ((owners::Buffer_2bc520 *)&(o->list))->FUN_002bc520((unsigned int)(fr.count), (Child_2bc790 * *)((Child_2bc790 **)&fr.slot1c));

    if (!r->FUN_002669f0())
        return;
    do {
        int chunk = r->FUN_00266a30();
        if (chunk == 0x10004) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v2c), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.slot1c), (hulk_intptr)1, 4, (hulk_intptr)1);
            o->i38 = fr.slot1c;
        } else if (chunk == 0x10003) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v14), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v20), (hulk_intptr)3, 4, (hulk_intptr)1);
        } else if (chunk == 0x17005) {
            if ((unsigned int)fr.idx < (unsigned int)fr.count) {
                Child_2bc790 **slot = o->list.begin + fr.idx;
                Child_2bc790 *child = FUN_002ba8d0(r, factory);
                if (child != 0)
                    child->v0();
                if (*slot != 0)
                    (*slot)->v1();
                fr.idx++;
                *slot = child;
            }
        } else if (chunk == 0x17007) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.junkA), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(fr.q4), (hulk_intptr)4, 4, (hulk_intptr)1);
            o->mat40.FUN_0022ba20(fr.q4);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.pos), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::Target_22be40 *)&(o->mat40))->FUN_0022be40((const int *)(const Vec3_2bc790 *)(&fr.pos));
        } else if (chunk == 0x1700a) {
            if (fr.len == 1) {
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.j5), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.tag1), (hulk_intptr)1, 4, (hulk_intptr)1);
                if (fr.tag1 == 0x48544f42)
                    o->f98 = 3;
                else if (fr.tag1 == 0x54524556)
                    o->f98 = 1;
                else if (fr.tag1 == 0x545a5248)
                    o->f98 = 2;
                else
                    o->f98 = 0;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c0), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fa4 = (float)cos(fr.c0);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c1), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fa8 = (float)cos(fr.c1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c2), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fac = (float)cos(fr.c2);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c3), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fb0 = (float)cos(fr.c3);
            }
        } else if (chunk == 0x1700c) {
            if (fr.len == 1) {
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.j4), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.e2), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fa0 = fr.e2 == 0x454e494c;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.e3), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fc4 = fr.e3;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.e4), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fc8 = fr.e4;
            }
        } else if (chunk == 0x1700b) {
            if (fr.len == 1) {
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.j3), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.tag2), (hulk_intptr)1, 4, (hulk_intptr)1);
                if (fr.tag2 == 0x48544f42)
                    o->f9c = 3;
                else if (fr.tag2 == 0x54524556)
                    o->f9c = 1;
                else if (fr.tag2 == 0x545a5248)
                    o->f9c = 2;
                else
                    o->f9c = 0;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.d1), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fb4 = (float)cos(fr.d1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.d2), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fb8 = (float)cos(fr.d2);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.d3), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fbc = (float)cos(fr.d3);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c4), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fc0 = (float)cos(fr.c4);
            }
        } else if (chunk == 0x121204) {
            FUN_002a4b00(parent->p48, r, factory);
        } else if (chunk == 0x122000) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.junk2), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.f), (hulk_intptr)1, 4, (hulk_intptr)1);
            float v = fr.f;
            if (!(v >= 0.0f))
                v = 0.0f;
            else if (v > 1.0f)
                v = 1.0f;
            parent->f40 = v;
        }
        r->FUN_00266be0();
    } while (r->FUN_002669f0());
}
