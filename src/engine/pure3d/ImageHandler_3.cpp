// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ae8a0..0x002af160 (kind game, layer engine, confidence high), dominant class pure3d::ImageHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fee005c0 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fee005c0 {} using namespace fn_fee005c0;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_fee005c0 {
class Obj_2ae910 {
  public:
    virtual void Release(int);
    virtual void Tick();
};
class Container_2ae910 {
  public:
    int count;
    Obj_2ae910* items[31];
    char pad[0x84 - 4 - 31 * 4];
    Obj_2ae910* ref;
};
class Item {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual char match(int);
    virtual bool matches(void* value);
};
class Collection {
  public:
    int count;
    union { Item* entries[1]; Item* items[1]; };
    Item* find(int x);
    Item* FUN_002ae9d0(void* value);
};
struct Context;
struct File {
    virtual void AddRef();
    virtual void Release();
    File* FUN_002644d0(Request* req, Context* ctx, int one);
};
struct Request {
    char name[0x100];
    File* file;
    int pad104;
    int allocTag;
};
struct LoadInventory_2aea70;
struct Context {
    char pad0[0x18];
    LoadInventory_2aea70* loader;
    File* file;
    File* FUN_00266880();
    void FUN_00266850(File* f);
    void FUN_00266820(LoadInventory_2aea70* l);
};
namespace pure3d {
class ImageHandler {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void vfunc_3(Request* req, Context* ctx);
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual const char* f6();
    virtual unsigned char vfunc_7(const char*);
    virtual void _m_vf8();
    virtual void load(File* file, void* builder);
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual int vfunc_15();
    char _m_pad_4[0x4];
    int mode;
    char copyName;
    char _m_pad_d[0x3];
    int f10;
    int f14;
};
}
struct NameField_2aea70 {
    unsigned int keyLo;
    unsigned int keyHi;
    void FUN_0027b040(const char* name);
};
struct Resource_2aea70 {
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    NameField_2aea70 name;
};
struct SpriteObject {
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
    virtual void setSprite(struct Sprite* s);
    char pad04[4];
    NameField_2aea70 name;
    SpriteObject* FUN_002bdee0();
};
struct Sprite {
    Sprite* FUN_002beb20(Resource_2aea70* image, int zero, int one, int a, int b, int c);
};
struct LoadInventory_2aea70 {
    virtual void v0();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void add(unsigned int keyLo, unsigned int keyHi, void* obj);
    LoadInventory_2aea70* FUN_00266480(int size);
};
namespace pure3d {
class TextureBuilder {
public:
    virtual void vfunc_0();
    Resource_2aea70* tex;
    int flags;
    void* surface;
    int stride;
    void* dest;
    int rows;
    int level;
    int width;
    int height;
    int format;
    int depth;
    int bpp;
    TextureBuilder() : tex(0), flags(0), surface(0), stride(0), dest(0), rows(0), level(0), width(8), height(0), format(0), depth(0), bpp(0) {}
};
}
namespace pure3d {
class ImageBuilder {
public:
    virtual void vfunc_0();
    Resource_2aea70* image;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    ImageBuilder() : image(0), f08(0), f0c(0), f10(0), f14(0), f18(0) {}
};
}
extern "C" void* FUN_00263ed0(int size, int tag);
void* FUN_00263ea0(unsigned int size);
extern "C" void FUN_0028fb20(char* dst, const char* src);
struct Input;
struct LoadStream_2aecb0 {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    LoadStream_2aecb0* FUN_00264430(Input*, int, int);
};
struct Sub_2aecb0 {
};
struct Result_2aecb0 {
    char pad[8];
    Sub_2aecb0 sub;
};
namespace pure3d {
struct ImageBuilder_2aecb0 {
    virtual void slot0();
    Result_2aecb0* result;
    int a, b, c, d;
    int context;
};
}
struct Container_2aecb0 {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9(LoadStream_2aecb0*, pure3d::ImageBuilder_2aecb0*) = 0;
};
struct Owner_2aecb0 {
    char pad[0x8c];
    int context;
    Container_2aecb0* FUN_002ae980(Input*);
    Result_2aecb0* target(Input*);
};
extern "C" char DAT_0042e184[];
class ImageBuilder {
  public:
    virtual ~ImageBuilder() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void V8() {}
};
class Iface_2aed60 {
  public:
    virtual ~Iface_2aed60() {}
    virtual void V0() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void Process(void* param2, ImageBuilder* builder) {}
};
struct ThisCall_002ae9d0 {
    Iface_2aed60* FUN_002ae9d0(void* param);
};
extern "C" char DAT_0042e1b4[];
typedef unsigned int u32_2af0c0;
struct Manager_2af0c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32_2af0c0 getA();
    virtual u32_2af0c0 getB();
};
class ImageHandler {
  public:
    int a;
    int b;
    int c;
    unsigned char flag;
    int d;
    int e;
    ImageHandler();
};
class FileLoader_2af100 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public FileLoader_2af100 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x002ae8a0 pure3d::ImageHandler::vfunc_7 (79 B): matches/0x002ae8a0.cpp
// sym: ?vfunc_7@ImageHandler@pure3d@fn_fee005c0@@UAEEPBD@Z
namespace pure3d {
unsigned char ImageHandler::vfunc_7(const char* name) {
    const char* ext = f6();
    hulk_intptr n = strlen(name);
    hulk_intptr m = strlen(ext);
    if (n < m)
        return 0;
    return _stricmp(ext, name + n - m) == 0;
}
}


// 0x002ae910 FUN_002ae910 (53 B): matches/0x002ae910.cpp
// sym: @FUN_002ae910@4
extern "C" void __fastcall FUN_002ae910(Container_2ae910* p) {
    Obj_2ae910* r = p->ref;
    if (r)
        r->Release(1);
    for (int i = 0; i < p->count; ++i)
        p->items[i]->Tick();
}

} // namespace fn_fee005c0

// 0x002ae950 FUN_002ae950 (43 B): matches/0x002ae950.cpp
// sym: ?FUN_002ae950@C_2ae950@owners@@QAEXHHHH@Z
void owners::C_2ae950::FUN_002ae950(int x, int y, int z, int w) {
    a = x;
    b = y;
    c = z;
    d = w;
}

namespace fn_fee005c0 {

// 0x002ae980 FUN_002ae980 (65 B): matches/0x002ae980.cpp
// sym: ?find@Collection@fn_fee005c0@@QAEPAVItem@2@H@Z
Item* Collection::find(int x) {
    Item* result = 0;
    for (int i = 0; i < count; ++i) {
        if (entries[i]->match(x)) {
            result = entries[i];
            break;
        }
    }
    return result;
}


// 0x002ae9d0 FUN_002ae9d0 (65 B): equivalent/0x002ae9d0.cpp
// sym: ?FUN_002ae9d0@Collection@fn_fee005c0@@QAEPAVItem@2@PAX@Z @b6eb5602814b @w2c8215f181ac
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002ae9d0 @ 0x002ae9d0
Item* Collection::FUN_002ae9d0(void* value) { for (int i = 0; i < count; ++i) { if (items[i]->matches(value)) return items[i]; } return 0; }


// 0x002aea70 pure3d::ImageHandler::vfunc_3 (575 B): equivalent/0x002aea70.cpp
// sym: ?vfunc_3@ImageHandler@pure3d@fn_fee005c0@@UAEXPAURequest@3@PAUContext@3@@Z @95ff84ed5f2d @w75736fd2503b
// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 18/24, incomplete)
// pure3d::ImageHandler::vfunc_3 @ 0x002aea70
void pure3d::ImageHandler::vfunc_3(Request* req, Context* ctx)
{
    char name[0x100];

    File* file = ctx->FUN_00266880();
    if (file == 0) {
        void* mem = FUN_00263ed0(0x48, 1);
        if (mem)
            file = ((File*)mem)->FUN_002644d0(req, ctx, 1);
        else
            file = 0;
        ctx->FUN_00266850(file);
    }
    req->file = file;
    file->AddRef();

    if (copyName) {
        const char* src = req->name;
        char* dst = name;
        char c;
        do {
            c = *src;
            *dst = c;
            src++;
            dst++;
        } while (c != 0);
    } else {
        FUN_0028fb20(name, req->name);
    }

    void* lmem = FUN_00263ed0(0x14, req->allocTag);
    LoadInventory_2aea70* loader = 0;
    if (lmem)
        loader = ((LoadInventory_2aea70*)lmem)->FUN_00266480(0x400);

    if (mode == 1) {
        pure3d::TextureBuilder builder;
        load(file, &builder);
        Resource_2aea70* tex = builder.tex;
        if (tex != 0) {
            tex->name.FUN_0027b040(name);
            loader->add(tex->name.keyLo, tex->name.keyHi, tex);
        }
    } else if (mode == 0) {
        pure3d::ImageBuilder builder;
        load(file, &builder);
        Resource_2aea70* image = builder.image;
        if (image != 0) {
            image->name.FUN_0027b040(name);
            loader->add(image->name.keyLo, image->name.keyHi, image);
        }
    } else if (mode == 2) {
        pure3d::ImageBuilder builder;
        load(file, &builder);
        Resource_2aea70* image = builder.image;
        if (image != 0) {
            void* smem = FUN_00263ea0(0xa8);
            Sprite* sprite = 0;
            if (smem)
                sprite = ((Sprite*)smem)->FUN_002beb20(image, 0, 1, f10, f14, vfunc_15());
            void* omem = FUN_00263ea0(0x58);
            SpriteObject* obj = 0;
            if (omem)
                obj = ((SpriteObject*)omem)->FUN_002bdee0();
            obj->setSprite(sprite);
            obj->name.FUN_0027b040(name);
            loader->add(obj->name.keyLo, obj->name.keyHi, obj);
            image->Release();
        }
    }

    file->Release();
    ctx->FUN_00266820(loader);
}


// 0x002aecb0 FUN_002aecb0 (172 B): matches/0x002aecb0.cpp
// sym: ?target@Owner_2aecb0@fn_fee005c0@@QAEPAUResult_2aecb0@2@PAUInput@2@@Z
Result_2aecb0* Owner_2aecb0::target(Input* input) {
    LoadStream_2aecb0* mem = (LoadStream_2aecb0*)thunk_FUN_0008d690(0x48);
    LoadStream_2aecb0* r = mem ? mem->FUN_00264430(input, 0, 1) : 0;
    r->slot0();
    Container_2aecb0* c = FUN_002ae980(input);
    if (!c) {
        r->slot1();
        return 0;
    }
    pure3d::ImageBuilder_2aecb0 builder;
    builder.result = 0;
    builder.a = 0;
    builder.b = 0;
    builder.c = 0;
    builder.d = 0;
    builder.context = context;
    c->s9(r, &builder);
    Result_2aecb0* result = builder.result;
    if (result)
        ((owners::Target_27b040 *)&(result->sub))->FUN_0027b040((hulk_uintptr)(Input *)input);
    r->slot1();
    return result;
}

} // namespace fn_fee005c0

// 0x002aed60 FUN_002aed60 (97 B): matches/0x002aed60.cpp
// sym: ?FUN_002aed60@SomeClass_2aed60@owners@@QAEHPAX0@Z
hulk_intptr owners::SomeClass_2aed60::FUN_002aed60(void* param2, void* param3) {
    Iface_2aed60* iface = ((ThisCall_002ae9d0*)(this))->FUN_002ae9d0(param3);
    if (!iface)
        return 0;

    struct ParamBlock {
        void* vptr;
        int zero1;
        int zero2;
        int zero3;
        int zero4;
        int zero5;
        int field_8C;
    } pb;

    pb.zero1 = 0;
    pb.zero2 = 0;
    pb.zero3 = 0;
    pb.zero4 = 0;
    pb.zero5 = 0;
    pb.field_8C = this->field_8C;

    // Direct immediate assignment to match target's mov [esp+8], 0x42e184
    pb.vptr = (void*)((hulk_intptr)DAT_0042e184);

    iface->Process(param2, (ImageBuilder*)&pb.vptr);

    return pb.zero1;
}


// 0x002aedd0 FUN_002aedd0 (230 B): equivalent/0x002aedd0.cpp [wrapped: compile error C2440: 'initializing' : cannot convert from 'fn_fee005c0::pure3d::Texture *' to 'fn_fee005c0::Texture *']
// sym: ?target@Owner_2aedd0@fn_002aedd0@@QAEPAUTexture@2@PAX@Z @92376fb8bc70 @w91138fa829d7
namespace fn_002aedd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 5/6, incomplete)
// FUN_002aedd0 @ 0x002aedd0
void* __cdecl FUN_00263ea0(unsigned int);
struct LoadStream_2aedd0 { virtual void slot0(); virtual void slot1(); LoadStream_2aedd0* FUN_00264430(void*, int, int); void FUN_00263fb0(); };
struct Link_2aedd0 {  };
struct Texture { char pad[8]; Link_2aedd0 link; };
namespace pure3d { struct TextureBuilder_2aedd0 { virtual void slot0(); Texture* result; unsigned int f08,f0c,f10,f14,f18,f1c; unsigned int f20,f24,f28,f2c,f30; }; }
struct Loader_2aedd0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(LoadStream_2aedd0*, pure3d::TextureBuilder_2aedd0*); };
struct Owner_2aedd0 { char pad[0x8c]; unsigned int f8c,f90,f94,f98,f9c,fa0; Loader_2aedd0* FUN_002ae980(void*); Texture* target(void*); };
Texture* Owner_2aedd0::target(void* arg) {
 LoadStream_2aedd0* raw=(LoadStream_2aedd0*)FUN_00263ea0(0x48);
 LoadStream_2aedd0* resource=raw ? raw->FUN_00264430(arg,0,1) : 0;
 resource->slot0();
 Loader_2aedd0* loader=FUN_002ae980(arg);
 if (!loader) return 0;
 pure3d::TextureBuilder_2aedd0 builder;
 builder.result=0; builder.f08=0; builder.f0c=0; builder.f10=0; builder.f14=0; builder.f18=0; builder.f1c=0;
 builder.f20=f94; builder.f24=f98; builder.f28=f9c; builder.f2c=fa0; builder.f30=f8c;
 resource->FUN_00263fb0();
 loader->v9(resource,&builder);
 Texture* result=builder.result;
 if(result) ((owners::Target_27b040 *)&(result->link))->FUN_0027b040((hulk_uintptr)arg);
 resource->slot1();
 return result;
}
} // namespace fn_002aedd0


// 0x002aeec0 FUN_002aeec0 (145 B): equivalent/0x002aeec0.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?FUN_002aeec0@ImageRegistry_2aeec0@fn_002aeec0@@QAEHHHH@Z @a2b5c4d0a18b @w63b7b092adc6
namespace fn_002aeec0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002aeec0 @ 0x002aeec0
class TextureBuilder {
public:
    int result, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30;
    TextureBuilder(int a, int b, int c, int d, int e)
    {
        result = 0;
        f8 = 0;
        fc = 0;
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1c = 0;
        f20 = a;
        f24 = b;
        f28 = c;
        f2c = d;
        f30 = e;
    }
    virtual void v0();
};

class ImageHandler {
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
    virtual void v9(int stream, TextureBuilder *tb);
};

class ImageRegistry_2aeec0 {
public:
    char pad0[0x8c];
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;

    ImageHandler *FUN_002ae9d0(int type);
    hulk_intptr FUN_002aeec0(int stream, int unused, int type);
};

hulk_intptr ImageRegistry_2aeec0::FUN_002aeec0(int stream, int unused, int type)
{
    ImageHandler *h = FUN_002ae9d0(type);
    if (h == 0)
        return 0;
    TextureBuilder tb(p94, p98, p9c, pa0, p8c);
    h->v9(stream, &tb);
    return tb.result;
}
} // namespace fn_002aeec0


// 0x002aef60 FUN_002aef60 (161 B): equivalent/0x002aef60.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002aef60@Owner_2aef60@fn_002aef60@@QAEXIHH@Z @5f98d1561bc5 @w75a04eefa465
namespace fn_002aef60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002aef60 @ 0x002aef60
// FUN_002aef60 @ 0x002aef60: builds a texture request for a stream and hands it to the stream owner's handler
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);

class Stream {
public:
    virtual void AddRef();
    virtual void Release();
    Stream *FUN_00264430(unsigned int id, int a, int b);
};

class TextureBuilder {
public:
    virtual void v0();
    int f04;
    int f08, f0c, f10, f14, f18;
    int f1c;
    int f20;
    int f24, f28, f2c, f30;
    TextureBuilder(int a, int b);
};

class Handler_2aef60 {
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
    virtual void Build(Stream *stream, TextureBuilder *builder);
};

class Owner_2aef60 {
public:
    Handler_2aef60 *FUN_002ae980(unsigned int id);
    void FUN_002aef60(hulk_uintptr id, hulk_intptr a, int b);
};

TextureBuilder::TextureBuilder(int a, int b)
{
    f04 = a;
    f08 = 0;
    f0c = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f20 = 8;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f1c = b;
}

void Owner_2aef60::FUN_002aef60(hulk_uintptr id, hulk_intptr a, int b)
{
    void *memory = thunk_FUN_0008d690(0x48);
    Stream *stream = memory ? ((Stream *)memory)->FUN_00264430(id, 0, 0) : 0;
    stream->AddRef();
    Handler_2aef60 *handler = FUN_002ae980(id);
    if (handler) {
        TextureBuilder builder(a, b);
        handler->Build(stream, &builder);
        stream->Release();
    }
}
} // namespace fn_002aef60


// 0x002af010 FUN_002af010 (109 B): equivalent/0x002af010.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?FUN_002af010@ThisWrap_002af010@fn_002af010@@QAEXHHHH@Z @a82edd933c73 @w7d03dd76ea8d
namespace fn_002af010 {
// STATUS: equivalent (tools/equiv.py level 3: 17396 inputs, branch coverage 2/2)
// FUN_002af010 @ 0x002af010
class TextureBuilder {
public:
    int f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30;
    TextureBuilder(int a, int b)
    {
        f8 = 0;
        fc = 0;
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f24 = 0;
        f28 = 0;
        f2c = 0;
        f30 = 0;
        f4 = a;
        f20 = 8;
        f1c = b;
    }
    virtual void v0();
};
class Builder {
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
    virtual void v9(int a, TextureBuilder *tb);
};
struct ThisWrap_002af010 {
    Builder * FUN_002ae9d0(int a);
    void FUN_002af010(int a1, hulk_intptr a2, int a3, int a4);
};

void ThisWrap_002af010::FUN_002af010(int a1, hulk_intptr a2, int a3, int a4) {
    Builder *b = this->FUN_002ae9d0(a3);
    if (b != 0) {
        TextureBuilder tb(a2, a4);
        b->v9(a1, &tb);
    }
}
} // namespace fn_002af010

namespace fn_fee005c0 {

// 0x002af0c0 FUN_002af0c0 (52 B): matches/0x002af0c0.cpp
// sym: ??0ImageHandler@fn_fee005c0@@QAE@XZ
// data: gManager_2af0c0 = DAT_0052c2a4
ImageHandler::ImageHandler() {
    b = 0;
    *(volatile hulk_uintptr*)this = ((hulk_intptr)DAT_0042e1b4);
    c = 0;
    flag = 0;
    d = (*(Manager_2af0c0**)&DAT_0052c2a4)->getB();
    e = (*(Manager_2af0c0**)&DAT_0052c2a4)->getA();
}


// 0x002af100 pure3d::ImageHandler::vfunc_2 (31 B): matches/0x002af100.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fee005c0@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fee005c0
