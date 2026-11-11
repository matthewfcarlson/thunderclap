// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c1c00..0x002c25b0 (kind game, layer engine, confidence high), dominant class pure3d::Texture
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f9a208e6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f9a208e6 {} using namespace fn_f9a208e6;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f9a208e6 {
class X_2c1c00 {
  public:
    char pad[0x18];
    int m18;
    void Set(int v);
};
extern "C" char DAT_0042ec20[];
class Texture_2c1c30 {
  public:
    hulk_intptr v;
    char pad[12];
    int field10;
};
struct Texture_nv_2c1c30 {
    void Init_0027b070();
};
} // namespace fn_f9a208e6
namespace pure3d {
class Entity_2c1c60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_f9a208e6 {
struct Args_2c1c70 {
    int a;
    int b;
    int pad;
    int c;
    int d;
    int e;
    int f;
    int g;
    char i;
    char j;
};
struct Object {
    virtual void Run();
};
struct Manager_2c1c70 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    virtual void H();
    virtual void I();
    virtual Object* Create(Args_2c1c70*);
};
struct Owner_2c1c70 {
    char pad[16];
    Object* value;
    bool Fn(int, int, int, int, int, int, int);
};
struct Request {
    int x[8];
    char a;
    char b;
};
class Result_2c1cf0 {
  public:
    virtual void Finish();
};
class Factory_2c1cf0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual Result_2c1cf0* Create(Request*);
};
class Owner_2c1cf0 {
  public:
    char pad[0x10];
    Result_2c1cf0* result;
    bool Run(int, int, int, int, int, int, int, int);
};
struct StrField_2c1d70 {
    int a, b;
};
struct Sprite_2c1d70 {
    char pad0[8];
    StrField_2c1d70 name;
};
struct TextureBuilder_nv_2c1d70 {
    Sprite_2c1d70 *FUN_002aedd0(const char *name);
    Sprite_2c1d70 *FUN_002aeec0(int h, int a, int b);
    void FUN_002aef60(const char *name, Sprite_2c1d70 *existing, int arg);
    void FUN_002af010(int h, Sprite_2c1d70 *existing, int b, int arg);
};
struct Stream_2c1d70 {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};
struct Reader_2c1d70 {
    char pad0[0x284];
    Stream_2c1d70 *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    void FUN_00266ca0(int v);
};
class Loader_2c1d70 {
public:
    char pad00[0x14];
    pure3d::TextureBuilder *data;
    Sprite_2c1d70 *FUN_002c1d70(Reader_2c1d70 *r, pure3d::TextureBuilder *sd, Sprite_2c1d70 *existing, int arg);
};
extern "C" void *FUN_0008d6d0(unsigned int size);
void FUN_0008d340(void *p);
class Ref_2c1f80 {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Stream {
  public:
    char FUN_002647e0(void* dest, int a, int b, int c);
};
struct Reader {
  public:
    char _m_pad_0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    void FUN_00266ca0(int handle);
};
struct Factory_2c1f80 {
    Ref_2c1f80 *FUN_002aecb0(char *name);
};
class Sink_2c1f80 {
public:
    virtual void v0();
    virtual void v1();
    virtual void *Install(Ref_2c1f80 **items, int count, int a, int b);
    virtual void *InstallScaled(Ref_2c1f80 **items, int count, int a, int b);
};
class Loader_2c1f80 {
public:
    char pad0[0x14];
    Factory_2c1f80 *defaultFactory;    // 0x14
    Sink_2c1f80 *sink;                 // 0x18

    void *FUN_002c1f80(Reader *r, Factory_2c1f80 *factory, hulk_intptr a3, int a4, int a5);
};
extern void* hulk_at_0042ec20[];
class Ref_2c22d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2c22d0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class Texture_2c22d0 : public Entity_2c22d0 {
  public:
    char pad[12];
    Ref_2c22d0* m;
    ~Texture_2c22d0();
};
class IRefCount {
  public:
    virtual void Release(int);
};
class TextureLoader {
  public:
    virtual void v0();
    char pad[0x10];
    void* mTexture;
    void* mOther;
};
struct Holder_2c2330 {
    char pad[0x14];
    void* p;
    void* q;
};
extern "C" void __fastcall FUN_002ae910(void*);
void __cdecl thunk_FUN_00267090(void*);
extern int hulk_at_0042ec44, hulk_at_003f6098;
struct Name_2c2370 {
    void FUN_0027b040(const char* s);
};
struct Created_2c2370 {
    char pad0[8];
    Name_2c2370 name;
};
struct Target_2c2370 {
    char pad0[0x8c];
    int f8c;
    char pad90[4];
    void FUN_002ae950(int a, int b, int c, int d);
};
class Loader_2c2370 {
  public:
    char pad0[0x14];
    Target_2c2370* target;
    Created_2c2370* FUN_002c1f80(Reader* rd, Target_2c2370* t, Created_2c2370* prev, int index, int count);
    Created_2c2370* FUN_002c1d70(Reader* rd, Target_2c2370* t, Created_2c2370* prev, int index);
    Created_2c2370* FUN_002c2370(Reader* rd);
};
extern void* g_vftable_2c2570[];
} // namespace fn_f9a208e6
void operator delete(void*);
namespace fn_f9a208e6 {
class Ref_2c2570 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2c2570 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class Texture_2c2570 : public Entity_2c2570 {
  public:
    char pad[0x10 - 4];
    Ref_2c2570* m;
    Texture_2c2570* f2(unsigned char flags);
};


// 0x002c1c00 FUN_002c1c00 (10 B): matches/0x002c1c00.cpp
// sym: ?Set@X_2c1c00@fn_f9a208e6@@QAEXH@Z
void X_2c1c00::Set(int v) {
    m18 = v;
}


// 0x002c1c30 FUN_002c1c30 (25 B): matches/0x002c1c30.cpp
// sym: ?FUN_002c1c30@fn_f9a208e6@@YIPAVTexture_2c1c30@1@PAV21@@Z
Texture_2c1c30* __fastcall FUN_002c1c30(Texture_2c1c30* self) {
    ((Texture_nv_2c1c30*)(((pure3d::Texture*)(self))))->Init_0027b070();
    self->v = ((hulk_intptr)DAT_0042ec20);
    self->field10 = 0;
    return self;
}

} // namespace fn_f9a208e6

// 0x002c1c50 pure3d::Texture::vfunc_5 (3 B): matches/0x002c1c50.cpp
// sym: ?vfunc_5@Texture@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::Texture::vfunc_5() {
    return 0;
}


// 0x002c1c60 pure3d::Texture::vfunc_4 (3 B): matches/0x002c1c60.cpp
// sym: ?vfunc_4@Texture@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Texture::vfunc_4() {
    return (void*)(this);
}

namespace fn_f9a208e6 {

// 0x002c1c70 FUN_002c1c70 (125 B): matches/0x002c1c70.cpp
// sym: ?Fn@Owner_2c1c70@fn_f9a208e6@@QAE_NHHHHHHH@Z
// data: gManager_2c1c70 = DAT_0052c2a0
bool Owner_2c1c70::Fn(int a, int b, int c, int d, int e, int f, int g) {
    Args_2c1c70 x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    x.e = e;
    x.pad = 0;
    x.i = 0;
    x.j = 0;
    x.f = f;
    x.g = g;
    Object* r = (*(Manager_2c1c70**)&DAT_0052c2a0)->Create(&x);
    value = r;
    if (!r)
        return false;
    r->Run();
    return true;
}


// 0x002c1cf0 FUN_002c1cf0 (126 B): matches/0x002c1cf0.cpp
// sym: ?Run@Owner_2c1cf0@fn_f9a208e6@@QAE_NHHHHHHHH@Z
// data: gFactory_2c1cf0 = DAT_0052c2a0
bool Owner_2c1cf0::Run(int a, int b, int c, int d, int e, int f, int g, int h) {
    Request request;
    request.b = 0;
    request.x[0] = a;
    request.x[1] = b;
    request.x[2] = c;
    request.x[3] = d;
    request.x[4] = e;
    request.x[5] = f;
    request.x[6] = g;
    request.x[7] = h;
    request.a = 1;
    result = (*(Factory_2c1cf0**)&DAT_0052c2a0)->Create(&request);
    if (!result)
        return false;
    result->Finish();
    return true;
}


// 0x002c1d70 FUN_002c1d70 (526 B): equivalent/0x002c1d70.cpp
// sym: ?FUN_002c1d70@Loader_2c1d70@fn_f9a208e6@@QAEPAUSprite_2c1d70@2@PAUReader_2c1d70@2@PAVTextureBuilder@pure3d@@PAU32@H@Z @ff7d0a84bbb3 @wa0be06b7c6b5
// STATUS: equivalent (tools/equiv.py level 3: 16754 inputs, branch coverage 16/16)
// FUN_002c1d70 @ 0x002c1d70
Sprite_2c1d70 *Loader_2c1d70::FUN_002c1d70(Reader_2c1d70 *r, pure3d::TextureBuilder *sd, Sprite_2c1d70 *existing, int arg)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        int a;
        int b;
        char buf[0x180];
    } fr;

    if (sd == 0)
        sd = data;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n = fr.len;
    r->stream->FUN_002647e0(fr.buf, n, 1, 1);
    fr.buf[n] = 0;
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x19002) {
                r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
                int h = ((int)((owners::Target_266c90 *)r)->FUN_00266c90());
                if (existing == 0)
                    existing = ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002aeec0(h, fr.a, fr.b);
                else
                    ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002af010(h, existing, fr.b, arg);
                r->FUN_00266ca0(h);
            } else if (id == 0x19003) {
                r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
                unsigned int m = fr.len;
                char *name2 = &fr.buf[0x80];
                r->stream->FUN_002647e0(name2, m, 1, 1);
                name2[m] = 0;
                if (existing == 0)
                    existing = ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002aedd0(name2);
                else
                    ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002aef60(name2, existing, arg);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    if (existing != 0)
        ((owners::Target_27b040 *)&(existing->name))->FUN_0027b040((hulk_uintptr)(fr.buf));
    return existing;
}


// 0x002c1f80 FUN_002c1f80 (758 B): equivalent/0x002c1f80.cpp
// sym: ?FUN_002c1f80@Loader_2c1f80@fn_f9a208e6@@QAEPAXPAUReader@2@PAUFactory_2c1f80@2@HHH@Z @7b3575889106 @we683bcb48451
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 24/28, incomplete)
// FUN_002c1f80 @ 0x002c1f80
void *Loader_2c1f80::FUN_002c1f80(Reader *r, Factory_2c1f80 *factory, hulk_intptr a3, int a4, int a5)
{
    if (factory == 0)
        factory = defaultFactory;

    // One contiguous frame (the stream stubs fill through these pointers).
    struct {
        char pad[3];
        unsigned char len;
        int v0;
        Ref_2c1f80 **items;
        void *result;
        Loader_2c1f80 *self;
        int count;
        int v2;
        char buf1[0x80];
        char buf2[0x100];
        char buf3[0x100];
    } f;

    f.self = this;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    int len = f.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.buf1), (hulk_intptr)len, 1, (hulk_intptr)1);
    f.buf1[len] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1);

    f.result = (void *)a3;
    f.items = (Ref_2c1f80 **)FUN_0008d6d0(f.count * sizeof(Ref_2c1f80 *));
    int n = 0;
    if (r->FUN_002669f0()) {
        do {
            if (r->FUN_00266a30() == 0x19001 && n < f.count) {
                bool found = false;
                sprintf(f.buf3, "%s_%i", f.buf1, n);
                while (r->FUN_002669f0() && !found) {
                    int id = r->FUN_00266a30();
                    if (id == 0x19002) {
                        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v2), (hulk_intptr)1, 4, (hulk_intptr)1);
                        int h = ((int)((owners::Target_266c90 *)r)->FUN_00266c90());
                        Ref_2c1f80 *obj = ((Ref_2c1f80 *)((owners::SomeClass_2aed60 *)factory)->FUN_002aed60((void *)(hulk_uintptr)(int)h, (void *)(hulk_uintptr)(int)(f.v0)));
                        f.items[n] = obj;
                        obj->AddRef();
                        r->FUN_00266ca0(h);
                        n++;
                        found = true;
                    } else if (id == 0x19003) {
                        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
                        int l2 = f.len;
                        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.buf2), (hulk_intptr)l2, 1, (hulk_intptr)1);
                        f.buf2[l2] = 0;
                        Ref_2c1f80 *obj = factory->FUN_002aecb0(f.buf2);
                        f.items[n] = obj;
                        obj->AddRef();
                        n++;
                        found = true;
                    }
                    r->FUN_00266be0();
                }
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    if (n > 0) {
        if (a3 == 0)
            f.result = f.self->sink->Install(f.items, n, a5, 0);
        else
            f.result = f.self->sink->InstallScaled(f.items, n, a3, a4);
    }
    for (int i = 0; i < n; i++)
        f.items[i]->Release();
    FUN_0008d340(f.items);
    return f.result;
}


// 0x002c22d0 FUN_002c22d0 (36 B): matches/0x002c22d0.cpp
// sym: ??1Texture_2c22d0@fn_f9a208e6@@QAE@XZ
Texture_2c22d0::~Texture_2c22d0() {
    vptr = hulk_at_0042ec20;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_0027afd0();
}


// 0x002c2330 FUN_002c2330 (55 B): matches/0x002c2330.cpp
// sym: ?FUN_002c2330@fn_f9a208e6@@YIXPAVTextureLoader@1@@Z
void __fastcall FUN_002c2330(TextureLoader* self) {
    void* p = ((Holder_2c2330*)self)->p;
    *(int**)self = &hulk_at_0042ec44;
    if (p) {
        FUN_002ae910(p);
        thunk_FUN_00267090(p);
    }
    if (((Holder_2c2330*)self)->q)
        ((IRefCount*)((Holder_2c2330*)self)->q)->Release(1);
    *(int**)self = &hulk_at_003f6098;
}


// 0x002c2370 FUN_002c2370 (504 B): equivalent/0x002c2370.cpp
// sym: ?FUN_002c2370@Loader_2c2370@fn_f9a208e6@@QAEPAUCreated_2c2370@2@PAUReader@2@@Z @21d7f1b3c386 @wf76cfc935d96
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 16/18, incomplete)
// FUN_002c2370 @ 0x002c2370
Created_2c2370* Loader_2c2370::FUN_002c2370(Reader* rd)
{
    struct Frame {
        char pad10[2];
        unsigned char len;
        unsigned char flagB;
        int count;
        int va;
        int ve;
        int vb;
        int vd;
        int vf;
        char name[0x80];
    } fr;
    unsigned char flagA;

    rd->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    int len = fr.len;
    rd->stream->FUN_002647e0(fr.name, len, 1, 1);
    fr.name[len] = 0;
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.vb, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    if (fr.count != 0)
        fr.count--;
    rd->stream->FUN_002647e0(&fr.vd, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.ve, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.vf, 1, 4, 1);

    target->f8c = fr.vb;
    target->FUN_002ae950(fr.va, fr.count, fr.vd, fr.ve);

    Created_2c2370* made = 0;
    int index = 0;
    fr.flagB = 0;
    flagA = 0;
    // flagA lives in the len byte of the frame in the original
    while (rd->FUN_002669f0()) {
        if (index > fr.count)
            break;
        int id = rd->FUN_00266a30();
        if (id == 0x19001) {
            if (!fr.flagB) {
                made = FUN_002c1d70(rd, target, made, index);
                fr.flagB = 0;
                flagA = 1;
                index++;
            }
        } else if (id == 0x19004) {
            if (!flagA) {
                made = FUN_002c1f80(rd, target, made, index, fr.count);
                fr.flagB = 1;
                flagA = 0;
                index++;
            }
        }
        rd->FUN_00266be0();
    }
    if (made)
        made->name.FUN_0027b040(fr.name);
    return made;
}


// 0x002c2570 pure3d::Texture::vfunc_2 (57 B): matches/0x002c2570.cpp
// sym: ?f2@Texture_2c2570@fn_f9a208e6@@QAEPAV12@E@Z
Texture_2c2570* Texture_2c2570::f2(unsigned char flags) {
    vptr = g_vftable_2c2570;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_0027afd0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f9a208e6
