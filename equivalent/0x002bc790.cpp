// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 66/78, incomplete)
// FUN_002bc790 @ 0x002bc790
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Vec3_2bc790 {
    float x, y, z;
};

namespace pure3d {
class Shader;
}

namespace content {
struct LoadInventory {
    template <class T>
    class DynamicCaster {
    public:
        virtual void *v0() { return 0; }
    };
};
}

class Stream {
public:
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

class Reader {
public:
    char pad00[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class NameHolder_2bc790 {
public:
    char pad00[8];
    void FUN_0027b040(const char *name);
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
    void FUN_002bc520(int n, Child_2bc790 **value);
};

class Mat4_2bc790 {
public:
    float m[16];
    void FUN_0022ba20(const float *q);
    void FUN_0022be40(const Vec3_2bc790 *t);
};

class Quad_2bc790 {
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
    Quad_2bc790 *FUN_002bc580();
    Quad_2bc790 *FUN_002bc660();
};

class ErrorShader {
public:
    ErrorShader *FUN_0028edf0(const char *what, int flag);
};

class Factory_2bc790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ErrorShader *v3(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, unsigned __int64 id);
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
void FUN_0028fcc0(const char *fmt, ...);

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
    void FUN_002a46d0(void *a, Quad_2bc790 *q);
    Child_2bc790 *FUN_002ba8d0(Reader *r, Factory_2bc790 *factory);
    void FUN_002a4b00(void *a, Reader *r, Factory_2bc790 *factory);
    void FUN_002bc790(Parent_2bc790 *parent, Reader *r, Factory_2bc790 *factory);
};

void Group_2bc790::FUN_002bc790(Parent_2bc790 *parent, Reader *r, Factory_2bc790 *factory)
{
    Frame_2bc790 fr;
    char *name1 = (char *)fr.name1;
    char *name2 = (char *)fr.name2;
    fr.self = this;
    r->stream->FUN_002647e0(&fr.f, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n1 = fr.len;
    r->stream->FUN_002647e0(name1, n1, 1, 1);
    name1[n1] = 0;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n2 = fr.len;
    r->stream->FUN_002647e0(name2, n2, 1, 1);
    name2[n2] = 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    fr.len = fr.count != 0;
    Quad_2bc790 *o;
    if (fr.len == 1) {
        void *mem = FUN_00263ea0(0xd0);
        o = 0;
        if (mem != 0)
            o = ((Quad_2bc790 *)mem)->FUN_002bc660();
    } else {
        void *mem = FUN_00263ea0(0x98);
        o = 0;
        if (mem != 0)
            o = ((Quad_2bc790 *)mem)->FUN_002bc580();
    }
    FUN_002a46d0(parent->p48, o);
    parent->name.FUN_0027b040(name1);
    o->name.FUN_0027b040(name1);
    unsigned __int64 id = FUN_0027b020(name2);
    new (&fr.count) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    ErrorShader *shader = factory->v3((content::LoadInventory::DynamicCaster<pure3d::Shader> *)&fr.count, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found for billboard quad group \"%s\"\n", name2, name1);
        void *mem2 = FUN_00263ea0(0x20);
        shader = 0;
        if (mem2 != 0)
            shader = ((ErrorShader *)mem2)->FUN_0028edf0("error", 0);
    }
    o->v8(shader);
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    o->b88 = fr.count != 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    o->b89 = fr.count != 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    o->b8a = fr.count != 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    fr.slot1c = 0;
    fr.idx = 0;
    o->list.FUN_002bc520(fr.count, (Child_2bc790 **)&fr.slot1c);

    if (!r->FUN_002669f0())
        return;
    do {
        int chunk = r->FUN_00266a30();
        if (chunk == 0x10004) {
            r->stream->FUN_002647e0(&o->v2c, 3, 4, 1);
            r->stream->FUN_002647e0(&fr.slot1c, 1, 4, 1);
            o->i38 = fr.slot1c;
        } else if (chunk == 0x10003) {
            r->stream->FUN_002647e0(&o->v14, 3, 4, 1);
            r->stream->FUN_002647e0(&o->v20, 3, 4, 1);
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
            r->stream->FUN_002647e0(&fr.junkA, 1, 4, 1);
            r->stream->FUN_002647e0(fr.q4, 4, 4, 1);
            o->mat40.FUN_0022ba20(fr.q4);
            r->stream->FUN_002647e0(&fr.pos, 3, 4, 1);
            o->mat40.FUN_0022be40(&fr.pos);
        } else if (chunk == 0x1700a) {
            if (fr.len == 1) {
                r->stream->FUN_002647e0(&fr.j5, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.tag1, 1, 4, 1);
                if (fr.tag1 == 0x48544f42)
                    o->f98 = 3;
                else if (fr.tag1 == 0x54524556)
                    o->f98 = 1;
                else if (fr.tag1 == 0x545a5248)
                    o->f98 = 2;
                else
                    o->f98 = 0;
                r->stream->FUN_002647e0(&fr.c0, 1, 4, 1);
                o->fa4 = (float)cos(fr.c0);
                r->stream->FUN_002647e0(&fr.c1, 1, 4, 1);
                o->fa8 = (float)cos(fr.c1);
                r->stream->FUN_002647e0(&fr.c2, 1, 4, 1);
                o->fac = (float)cos(fr.c2);
                r->stream->FUN_002647e0(&fr.c3, 1, 4, 1);
                o->fb0 = (float)cos(fr.c3);
            }
        } else if (chunk == 0x1700c) {
            if (fr.len == 1) {
                r->stream->FUN_002647e0(&fr.j4, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.e2, 1, 4, 1);
                o->fa0 = fr.e2 == 0x454e494c;
                r->stream->FUN_002647e0(&fr.e3, 1, 4, 1);
                o->fc4 = fr.e3;
                r->stream->FUN_002647e0(&fr.e4, 1, 4, 1);
                o->fc8 = fr.e4;
            }
        } else if (chunk == 0x1700b) {
            if (fr.len == 1) {
                r->stream->FUN_002647e0(&fr.j3, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.tag2, 1, 4, 1);
                if (fr.tag2 == 0x48544f42)
                    o->f9c = 3;
                else if (fr.tag2 == 0x54524556)
                    o->f9c = 1;
                else if (fr.tag2 == 0x545a5248)
                    o->f9c = 2;
                else
                    o->f9c = 0;
                r->stream->FUN_002647e0(&fr.d1, 1, 4, 1);
                o->fb4 = (float)cos(fr.d1);
                r->stream->FUN_002647e0(&fr.d2, 1, 4, 1);
                o->fb8 = (float)cos(fr.d2);
                r->stream->FUN_002647e0(&fr.d3, 1, 4, 1);
                o->fbc = (float)cos(fr.d3);
                r->stream->FUN_002647e0(&fr.c4, 1, 4, 1);
                o->fc0 = (float)cos(fr.c4);
            }
        } else if (chunk == 0x121204) {
            FUN_002a4b00(parent->p48, r, factory);
        } else if (chunk == 0x122000) {
            r->stream->FUN_002647e0(&fr.junk2, 1, 4, 1);
            r->stream->FUN_002647e0(&fr.f, 1, 4, 1);
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
