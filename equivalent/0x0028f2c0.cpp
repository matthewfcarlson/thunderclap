// STATUS: equivalent (tools/equiv.py level 3: 226 inputs, branch coverage 31/31)
// pure3d::ShaderLoader::vfunc_5 @ 0x0028f2c0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"

inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_00266e00(int count, int size);
void FUN_00267090(void *p);

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Texture; }

struct Pair_28f2c0 {
    unsigned int lo;
    unsigned int hi;
};
Pair_28f2c0 FUN_002672f0(const char *name, int a, int b);
Pair_28f2c0 FUN_0027b020(const char *name);

struct Name_28f2c0 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

class __declspec(novtable) Entity_28f2c0 {
public:
    virtual void v0();
    char pad04[4];
    Name_28f2c0 name;
    void FUN_0027b070();
    Entity_28f2c0() { FUN_0027b070(); }
};

class Impl_28f2c0 {
public:
    virtual void AddRef();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a, void *b);
    virtual void v6(int a, int b);
    virtual void v7(int a, int b);
    virtual void v8(int a, int b);
    virtual void v9(int a, float *b);
    virtual void v10(int a, float *b);
};

class Dev_28f2c0 {
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
    virtual Impl_28f2c0 *v11(const char *name, void *data);
};

class TexRes {
public:
    char pad0[0x10];
    void *f10;
};

class Factory_28f2c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TexRes *v3(content::LoadInventory::DynamicCaster<pure3d::Texture> *caster, unsigned int lo,
                        unsigned int hi);
};

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

namespace pure3d {
class Shader : public Entity_28f2c0 {
public:
    Impl_28f2c0 *f10;
    char f14;
    char pad15[3];
    int f18;
    char pad1c[4];
    virtual void Release();
    Shader() : f14(0), f18(0) {}
};

class ShaderLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(Shader **out, Pair_28f2c0 *outId, Reader *r, Factory_28f2c0 *f);
};

void ShaderLoader::vfunc_5(Shader **out, Pair_28f2c0 *outId, Reader *r, Factory_28f2c0 *f)
{
    struct Frame {
        char pad0[2];
        unsigned char len2;
        unsigned char len3;
        int v4;
        int v8;
        int vC;
        int v10;
        int v14;
        int v18;
        int v1c;
        int v20;
        int v24;
        int v28;
        int v2c;
        int v30[3];
        int mat[16];
        char buf1[0x100];
        char buf2[0x100];
        char buf4[0x100];
        char buf3[0x100];
    } fr;

    r->stream->FUN_002647e0(&fr.len2, 1, 1, 1);
    unsigned int n = fr.len2;
    r->stream->FUN_002647e0(fr.buf1, n, 1, 1);
    r->stream->FUN_002647e0(&fr.v4, 1, 4, 1);
    fr.buf1[n] = 0;
    r->stream->FUN_002647e0(&fr.len2, 1, 1, 1);
    n = fr.len2;
    r->stream->FUN_002647e0(fr.buf2, n, 1, 1);
    r->stream->FUN_002647e0(&fr.v4, 1, 4, 1);
    fr.buf2[n] = 0;
    r->stream->FUN_002647e0(&fr.v4, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.v4, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.v4, 1, 4, 1);

    void *mem = thunk_FUN_0008d690(0x20);
    Shader *obj = 0;
    if (mem) {
        obj = new (mem) Shader();
        obj->f10 = (*(Dev_28f2c0**)&DAT_0052c2a0)->v11(fr.buf2, 0);
        obj->f10->AddRef();
    }

    if (r->FUN_002669f0()) {
        do {
            switch (r->FUN_00266a30()) {
            case 0x11001: {
                if (obj != 0)
                    obj->Release();
                r->stream->FUN_002647e0(&fr.len2, 1, 1, 1);
                unsigned int len = fr.len2;
                r->stream->FUN_002647e0(fr.buf3, len, 1, 1);
                r->stream->FUN_002647e0(&fr.v28, 1, 4, 1);
                fr.buf3[len] = 0;
                int count = fr.v28;
                char *data = (char *)FUN_00266e00(1, count + 1);
                r->stream->FUN_002647e0(data, count, 1, 1);
                data[count] = 0;
                void *mem2 = thunk_FUN_0008d690(0x20);
                if (mem2) {
                    obj = new (mem2) Shader();
                    obj->f10 = (*(Dev_28f2c0**)&DAT_0052c2a0)->v11(fr.buf2, data);
                    obj->f10->AddRef();
                    FUN_00267090(data);
                } else {
                    obj = 0;
                    FUN_00267090(data);
                }
                break;
            }
            case 0x11002: {
                r->stream->FUN_002647e0(&fr.v24, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.len3, 1, 1, 1);
                unsigned int len = fr.len3;
                r->stream->FUN_002647e0(fr.buf4, len, 1, 1);
                fr.buf4[len] = 0;
                Pair_28f2c0 h = FUN_0027b020(fr.buf4);
                content::LoadInventory::DynamicCaster<pure3d::Texture> *caster =
                    new ((void *)&fr.v14) content::LoadInventory::DynamicCaster<pure3d::Texture>;
                TexRes *tex = f->v3(caster, h.lo, h.hi);
                if (tex != 0)
                    obj->f10->v5(fr.v24, tex->f10);
                break;
            }
            case 0x11003: {
                r->stream->FUN_002647e0(&fr.v18, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.v8, 1, 4, 1);
                int key = fr.v18;
                if (key == 0x54494c) {
                    char flag = fr.v8 != 0;
                    obj->f10->v6(0x54494c, flag);
                    obj->f14 = flag;
                } else if (key == 0x444d4c42) {
                    int val = fr.v8;
                    obj->f10->v6(0x444d4c42, val);
                    obj->f18 = val;
                } else {
                    obj->f10->v6(key, fr.v8);
                }
                break;
            }
            case 0x11004:
                r->stream->FUN_002647e0(&fr.v20, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.v2c, 1, 4, 1);
                obj->f10->v7(fr.v20, fr.v2c);
                break;
            case 0x11005: {
                r->stream->FUN_002647e0(&fr.vC, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.v1c, 1, 4, 1);
                int a = fr.vC;
                int b = fr.v1c;
                if (a != 0x49424d41)
                    obj->f10->v8(a, b);
                if (a == 0x46464944)
                    obj->f10->v8(0x49424d41, b);
                break;
            }
            case 0x11006:
                r->stream->FUN_002647e0(&fr.v10, 1, 4, 1);
                r->stream->FUN_002647e0(fr.v30, 3, 4, 1);
                obj->f10->v9(fr.v10, (float *)fr.v30);
                break;
            case 0x11007:
                r->stream->FUN_002647e0(&fr.v4, 1, 4, 1);
                r->stream->FUN_002647e0(fr.mat, 0x10, 4, 1);
                obj->f10->v10(fr.v4, (float *)fr.mat);
                break;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    obj->name.FUN_0027b040(fr.buf1);
    *out = obj;
    *outId = FUN_002672f0(fr.buf1, 0, 0);
}
}
