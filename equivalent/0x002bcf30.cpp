// STATUS: equivalent (tools/equiv.py level 3: 210 inputs, branch coverage 34/40, incomplete)
// FUN_002bcf30 @ 0x002bcf30
#include "decls/address.h"
#include "gen/pure3d.h"
struct Vec3_2bcf30 {
    float x, y, z;
};

namespace pure3d {
class Shader_2bcf30;
}

namespace content {
struct LoadInventory_2bcf30 {
    template <class T>
    class DynamicCaster {
    public:
        virtual void *v0() { return 0; }
    };
};
}

class Stream_2bcf30 {
public:
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

class Reader_2bcf30 {
public:
    char pad00[0x284];
    Stream_2bcf30 *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class NameHolder_2bcf30 {
public:
    char pad00[8];
    void FUN_0027b040(const char *name);
};

class Child_2bcf30 {
public:
    virtual void v0();
    virtual void v1();
};

class ChildList_2bcf30 {
public:
    Child_2bcf30 **begin;
    char pad04[8];
    void FUN_002bc520(int n, Child_2bcf30 **value);
};

class Quad_2bcf30 {
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
    NameHolder_2bcf30 name;
    char pad10[4];
    Vec3_2bcf30 v14;
    Vec3_2bcf30 v20;
    Vec3_2bcf30 v2c;
    int i38;
    char pad3c[0x88 - 0x3c];
    char b88;
    char b89;
    char b8a;
    char pad8b[1];
    ChildList_2bcf30 list;
    Quad_2bcf30 *FUN_002bc580();
};

struct Shader_nv_2bcf30 {
    ::pure3d::Shader *FUN_0028edf0(const char *what, int flag);
};

class Factory_2bcf30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ::pure3d::Shader *v3(content::LoadInventory_2bcf30::DynamicCaster<pure3d::Shader_2bcf30> *caster, unsigned __int64 id);
};

struct Parent_2bcf30 {
    char pad00[8];
    NameHolder_2bcf30 name;
    char pad10[0x40 - 0x10];
    float f40;
    char pad44[4];
    void *p48;
};

void *FUN_00263ea0(unsigned int size);
void FUN_0028fcc0(const char *fmt, ...);

struct Frame_2bcf30 {
    unsigned char pad10[3];
    unsigned char len;
    int count;
    unsigned char pad18[3];
    unsigned char flag3;
    int slot1c;
    int idx;
    float f;
    void *self;
    int junk;
    unsigned int name1[64];
    unsigned int name2[64];
};

class Group_2bcf30 {
public:
    void FUN_002a46d0(void *a, Quad_2bcf30 *q);
    Child_2bcf30 *FUN_002bb0b0(Reader_2bcf30 *r, Factory_2bcf30 *factory);
    void FUN_002a4b00(void *a, Reader_2bcf30 *r, Factory_2bcf30 *factory);
    void FUN_002bcf30(Parent_2bcf30 *parent, Reader_2bcf30 *r, Factory_2bcf30 *factory);
};

void Group_2bcf30::FUN_002bcf30(Parent_2bcf30 *parent, Reader_2bcf30 *r, Factory_2bcf30 *factory)
{
    Frame_2bcf30 fr;
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
    bool flag1 = fr.count != 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    fr.len = fr.count != 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    fr.flag3 = fr.count != 0;
    r->stream->FUN_002647e0(&fr.count, 1, 4, 1);

    void *mem = FUN_00263ea0(0x98);
    Quad_2bcf30 *o = 0;
    if (mem != 0) {
        o = ((Quad_2bcf30 *)mem)->FUN_002bc580();
    }
    FUN_002a46d0(parent->p48, o);
    parent->name.FUN_0027b040(name1);
    o->name.FUN_0027b040(name1);
    unsigned __int64 id = FUN_0027b020(name2);
    content::LoadInventory_2bcf30::DynamicCaster<pure3d::Shader_2bcf30> caster;
    ::pure3d::Shader *shader = factory->v3(&caster, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found for billboard quad group \"%s\"\n", name2, name1);
        void *mem2 = FUN_00263ea0(0x20);
        shader = 0;
        if (mem2 != 0) {
            shader = ((Shader_nv_2bcf30*)(((::pure3d::Shader *)mem2)))->FUN_0028edf0("error", 0);
        }
    }
    o->v8(shader);
    o->b89 = fr.len;
    o->b88 = flag1;
    o->b8a = fr.flag3;
    fr.slot1c = 0;
    fr.idx = 0;
    o->list.FUN_002bc520(fr.count, (Child_2bcf30 **)&fr.slot1c);

    if (!r->FUN_002669f0()) {
        return;
    }
    do {
        int chunk = r->FUN_00266a30();
        if (chunk == 0x10004) {
            r->stream->FUN_002647e0(&o->v2c, 3, 4, 1);
            r->stream->FUN_002647e0(&fr.slot1c, 1, 4, 1);
            o->i38 = fr.slot1c;
        } else if (chunk == 0x10003) {
            r->stream->FUN_002647e0(&o->v14, 3, 4, 1);
            r->stream->FUN_002647e0(&o->v20, 3, 4, 1);
        } else if (chunk == 0x17001) {
            if ((unsigned int)fr.idx < (unsigned int)fr.count) {
                Child_2bcf30 **slot = o->list.begin + fr.idx;
                Child_2bcf30 *child = FUN_002bb0b0(r, factory);
                if (child != 0) {
                    child->v0();
                }
                if (*slot != 0) {
                    (*slot)->v1();
                }
                fr.idx++;
                *slot = child;
            }
        } else if (chunk == 0x122000) {
            r->stream->FUN_002647e0(&fr.junk, 1, 4, 1);
            r->stream->FUN_002647e0(&fr.f, 1, 4, 1);
            float v = fr.f;
            if (!(v >= 0.0f)) {
                v = 0.0f;
            } else if (v > 1.0f) {
                v = 1.0f;
            }
            parent->f40 = v;
        } else if (chunk == 0x121204) {
            FUN_002a4b00(parent->p48, r, factory);
        }
        r->FUN_00266be0();
    } while (r->FUN_002669f0());
}
