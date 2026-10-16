// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 43/44, incomplete)
// pure3d::ParticleSystemLoader::vfunc_5 @ 0x002ab030
// pure3d::ParticleSystemLoader::vfunc_5 @ 0x002ab030
#include "decls/address.h"
typedef unsigned __int64 Key_2ab030;
extern char DAT_0049c7dc[];
extern char DAT_004ce770[];
extern char DAT_0049fd74[];
extern char DAT_0049fd9c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_00263ea0(unsigned int size);

struct V3_2ab030 {
    float x, y, z;
};

struct Mat4_2ab030 {
    float m[16];
    void FUN_0022be40(const V3_2ab030 *pos);
};

struct Quat_2ab030 {
    float x, y, z, w;
    void FUN_0022b650(Mat4_2ab030 *out);
};

struct NameHolder_2ab030 {
    char data[8];
    void FUN_0027b040(const char *name);
    void FUN_0027af70(const NameHolder_2ab030 *other);
};

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int one);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
};

class Object {
public:
    virtual void retain();
    virtual void release();
};

class Factory_2ab030 {
public:
    virtual void retain();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void create(Object **out, unsigned *aux, Reader *reader, unsigned arg);
};

struct Manager_2ab030 {
    void *FUN_00265310(unsigned id);
};
extern Manager_2ab030 *DAT_00527c58;

class Emitter_2ab030 {
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
    virtual int v11();
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
    virtual void v25(Object *arg);
};

struct Slot16_2ab030 {
    Emitter_2ab030 *emitter;
    char pad[12];
};

class Gen_2ab030 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

class Binder_2ab030 {
public:
    char pad0[0x38];
    struct Bind *dummy;
};

struct BindTable {
    char FUN_002aa6d0(int id);
    void FUN_002aa720(Slot16_2ab030 *slot, Reader *r, unsigned arg);
};

class Particle_2ab030 {
public:
    virtual void v0();
    char pad4[4];
    NameHolder_2ab030 name;      // 8
    char pad10[4];
    V3_2ab030 v14;
    V3_2ab030 v20;
    V3_2ab030 v2c;
    float f38;
    char pad3c[4];
    float f40;
    char pad44[4];
    Slot16_2ab030 *slots;        // 0x48
    char pad4c[0xc];
    char b58;
    float f5c;
    int f60;
    Mat4_2ab030 mat;             // 0x64
    char pad_a4_[0xa4 - 0xa4];
    Particle_2ab030 *FUN_002a3660(int a);
    void FUN_002a3c80(void *child);
};

class Child_2ab030 {
public:
    char pad0[8];
    NameHolder_2ab030 name;
    Child_2ab030 *FUN_002a73d0();
};

struct Frame_2ab030 {
    char pad10[4];
    unsigned f14;
    unsigned f18;
    int f1c;
    Object *f20;
    void *self;
    float f28;
    float f2c;
    int f30;
    float f34;
    V3_2ab030 pos;
    unsigned aux;
    char pad48[4];
    Quat_2ab030 quat;
    char name[0x100];
};

class Loader_2ab030 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad4[0x10];
    unsigned count;
    Gen_2ab030 *list[8];
    BindTable *table;
    unsigned FUN_002ab030(Particle_2ab030 **out, Key_2ab030 *outId, Reader *reader, unsigned arg);
};

unsigned Loader_2ab030::FUN_002ab030(Particle_2ab030 **out, Key_2ab030 *outId, Reader *reader, unsigned arg)
{
    Frame_2ab030 f;
    f.self = this;
    reader->stream->FUN_002647e0(&f.f28, 1, 4, 1);
    reader->stream->FUN_002647e0(&f.name[0xff], 1, 1, 1);
    unsigned char len = (unsigned char)f.name[0xff];
    reader->stream->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    reader->stream->FUN_002647e0(&f.f1c, 1, 4, 1);
    reader->stream->FUN_002647e0(&f.f18, 1, 4, 1);
    reader->stream->FUN_002647e0(&f.f14, 1, 4, 1);
    bool flag = f.f14 != 0;
    reader->stream->FUN_002647e0(&f.quat, 4, 4, 1);
    reader->stream->FUN_002647e0(&f.pos, 3, 4, 1);
    reader->stream->FUN_002647e0(&f.f14, 1, 4, 1);
    void *mem = FUN_00263ea0(0xb0);
    Particle_2ab030 *p;
    if (mem)
        p = ((Particle_2ab030 *)mem)->FUN_002a3660(f.f14);
    else
        p = 0;
    p->name.FUN_0027b040(f.name);
    p->f60 = f.f1c;
    p->f5c = (float)f.f18;
    p->b58 = flag;
    f.quat.FUN_0022b650(&p->mat);
    p->mat.FUN_0022be40(&f.pos);
    int off = 0;
    while (reader->FUN_002669f0()) {
        int id = reader->FUN_00266a30();
        switch (id) {
        case 0x10003:
            reader->stream->FUN_002647e0(&p->v14, 3, 4, 1);
            reader->stream->FUN_002647e0(&p->v20, 3, 4, 1);
            break;
        case 0x10004:
            reader->stream->FUN_002647e0(&p->v2c, 3, 4, 1);
            reader->stream->FUN_002647e0(&f.f2c, 1, 4, 1);
            p->f38 = f.f2c;
            break;
        case 0x121201: {
            Factory_2ab030 *factory = (Factory_2ab030 *)FUN_00344e74(DAT_00527c58->FUN_00265310(0x121201), 0, DAT_0049c7dc, DAT_004ce770, 0);
            factory->retain();
            f.f20 = 0;
            factory->create(&f.f20, &f.aux, reader, arg);
            if (f.f20) {
                void *child = FUN_00344e74(f.f20, 0, DAT_0049fd74, DAT_0049fd9c, 0);
                if (child) {
                    p->FUN_002a3c80(child);
                    factory->release();
                    break;
                }
                if (f.f20) {
                    f.f20->release();
                    f.f20 = 0;
                }
            }
            factory->release();
            break;
        }
        case 0x122000: {
            reader->stream->FUN_002647e0(&f.f34, 1, 4, 1);
            reader->stream->FUN_002647e0(&f.f28, 1, 4, 1);
            float v = f.f28;
            if (v >= 0.0f) {
                if (!(v <= 1.0f))
                    v = 1.0f;
            } else {
                v = 0.0f;
            }
            p->f40 = v;
            break;
        }
        default: {
            Loader_2ab030 *self = (Loader_2ab030 *)f.self;
            if (self->table->FUN_002aa6d0(reader->FUN_00266c30()) == 1) {
                self->table->FUN_002aa720(&p->slots[off], reader, arg);
                Emitter_2ab030 *e = p->slots[off].emitter;
                unsigned i;
                for (i = 0; i < self->count; i++) {
                    if (self->list[i]->v3() == e->v11()) {
                        e->v25((Object *)self->list[i]);
                        break;
                    }
                }
                off++;
            }
            break;
        }
        }
        reader->FUN_00266be0();
    }
    if (*(void **)((char *)p + 0xa4) == 0) {
        void *m2 = FUN_00263ea0(0x60);
        Child_2ab030 *c;
        if (m2)
            c = ((Child_2ab030 *)m2)->FUN_002a73d0();
        else
            c = 0;
        c->name.FUN_0027af70(&p->name);
        p->FUN_002a3c80(c);
    }
    *out = p;
    Key_2ab030 key = FUN_002672f0(f.name, 0, 0);
    *outId = key;
    return (unsigned)key;
}
