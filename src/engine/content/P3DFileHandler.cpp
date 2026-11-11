// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00265bf0..0x00265ff0 (kind game, layer engine, confidence medium), dominant class content::P3DFileHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f638de75 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f638de75 {} using namespace fn_f638de75;
#include "engine/content.h"

// ---- declarations shared by the functions below
namespace fn_f638de75 {
extern "C" void Init(void*);
extern "C" void AddRef_0008d340(void*);
extern "C" void Release(void*);
struct Obj_265bf0 {
    char pad0[1];
    unsigned char flag;
    char pad2[0x12];
    void* m14;
    void* m18;
    void* m1c;
    char pad20[4];
    char pad24[4];
    void* m28;
    void* m2c;
    void* m30;
};
struct State_265c40 {
    unsigned char p0[1];
    unsigned char flag;
    unsigned char p2[0x12];
    hulk_intptr at14;
    hulk_intptr at18;
    int at1c;
    unsigned char p20[4];
    int at24;
    hulk_intptr at28;
    hulk_intptr at2c;
    int at30;
};
extern "C" void __cdecl thunk_FUN_00267090_a(void*);
extern "C" void __cdecl thunk_FUN_00267090_b(void*);
void* __cdecl FUN_00263ed0(unsigned int size, int flag);
int __cdecl FUN_00266da0(int mode);
struct Ctx_265cd0;
struct Cache_265cd0;
struct LoadInventory_265cd0;
struct Res_265cd0 {
    char pad04[8];
    unsigned char ok;
    char pad0d[3];
    virtual void AddRef();
    virtual void Release();
    Res_265cd0* FUN_002644d0(Ctx_265cd0* a, Cache_265cd0* b, int c);
    void* FUN_00263fb0();
};
struct LoadInventory_265cd0 {
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b, void* obj);
    LoadInventory_265cd0* FUN_00266480(int size);
    void FUN_00266130(int v);
    void FUN_002660a0(void* v);
};
struct Reader {
    char pad00[0x288];
    Reader* FUN_00266cb0(void* handle);
    void FUN_002669d0(Ctx_265cd0* ctx);
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    void FUN_002669c0();
};
struct Ctx_265cd0 {
    char pad00[0x100];
    void* res;
    void* f104;
    void* f108;
};
struct Cache_265cd0 {
    Res_265cd0* FUN_00266880();
    void FUN_00266850(Res_265cd0* r);
    void FUN_00266950(int v);
    int FUN_00266710();
    void FUN_00266820(LoadInventory_265cd0* s);
};
struct Pair_265cd0 {
    int a;
    int b;
};
class LoadedObject {
public:
    virtual void AddRef();
    virtual void Release();
};
namespace content {
class ObjectLoader {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3(LoadedObject** out, Pair_265cd0* pair, void* a2, void* a3, void* a4);
};
}
namespace content {
class SimpleChunkHandler : public ObjectLoader {
public:
    virtual void v4();
    virtual void v5();
    char pad04[8];
    int status;
    Reader* reader;
};
}
struct Registry_265cd0 {
    content::ObjectLoader* FUN_00265310(int type);
};
class Listener_265cd0 {
public:
    virtual void v0(Ctx_265cd0* ctx, void* x);
    virtual void v1(Ctx_265cd0* ctx);
    virtual void v2(int type);
    virtual void v3(int type, LoadedObject* obj, Pair_265cd0* pair);
};
struct Frame_265cd0 {
    LoadedObject* obj;
    Res_265cd0* res;
    void* self;
    int status;
    Pair_265cd0 pair;
    Reader reader;
};
namespace content {
class P3DFileHandler {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Ctx_265cd0* ctx, Cache_265cd0* cache);
    char pad04[4];
    Listener_265cd0* listener;
};
}


// 0x00265bf0 FUN_00265bf0 (75 B): matches/0x00265bf0.cpp
// sym: ?Target@fn_f638de75@@YIXPAUObj_265bf0@1@@Z
// data: gData_265bf0 = DAT_00527c28
void __fastcall Target(Obj_265bf0* self) {
    self->flag = 1;
    Init(&DAT_00527c28);
    void* p = self->m30;
    self->m28 = p;
    self->m2c = p;
    if (p)
        AddRef_0008d340(p);
    p = self->m1c;
    self->m14 = p;
    self->m18 = p;
    if (p)
        AddRef_0008d340(p);
    Release(self);
}


// 0x00265c40 FUN_00265c40 (89 B): matches/0x00265c40.cpp
// sym: _FUN_00265c40
extern "C" void __cdecl FUN_00265c40(void) {
    State_265c40* s = (*(State_265c40**)&DAT_00527c58);
    s->flag = 1;
    FUN_0026d7a0(&DAT_00527c28);
    hulk_intptr x = s->at30;
    s->at28 = x;
    s->at2c = x;
    if (x)
        thunk_FUN_00267090_a((void*)x);
    x = s->at1c;
    s->at14 = x;
    s->at18 = x;
    if (x)
        thunk_FUN_00267090_a((void*)x);
    thunk_FUN_00267090_b(s);
    (*(State_265c40**)&DAT_00527c58) = 0;
}


// 0x00265cd0 content::P3DFileHandler::vfunc_3 (799 B): equivalent/0x00265cd0.cpp
// sym: ?vfunc_3@P3DFileHandler@content@fn_f638de75@@UAEXPAUCtx_265cd0@3@PAUCache_265cd0@3@@Z @63d7fc7850c5 @w446350521156
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 36/38, incomplete)
// content::P3DFileHandler::vfunc_3 @ 0x00265cd0
namespace content {
void P3DFileHandler::vfunc_3(Ctx_265cd0* ctx, Cache_265cd0* cache)
{
    Frame_265cd0 f;
    f.self = this;
    Res_265cd0* res = cache->FUN_00266880();
    bool created = false;
    f.res = res;
    if (res == 0) {
        created = true;
        void* mem = FUN_00263ed0(0x48, 1);
        if (mem != 0)
            f.res = ((Res_265cd0*)mem)->FUN_002644d0(ctx, cache, 1);
        else
            f.res = 0;
        cache->FUN_00266850(f.res);
        res = f.res;
    }
    if (res->ok == 0) {
        if (created)
            cache->FUN_00266850(0);
        cache->FUN_00266950(5);
        return;
    }
    ctx->res = res;
    res->AddRef();
    if (listener != 0)
        listener->v0(ctx, res->FUN_00263fb0());
    int old = FUN_00266da0(1);
    void* mem2 = FUN_00263ed0(0x14, 1);
    LoadInventory_265cd0* stream = 0;
    if (mem2 != 0)
        stream = ((LoadInventory_265cd0*)mem2)->FUN_00266480(0x400);
    FUN_00266da0(old);
    stream->FUN_00266130(0);
    stream->FUN_002660a0(ctx->f104);
    stream->AddRef();
    f.reader.FUN_00266cb0(ctx->res);
    f.reader.FUN_002669d0(ctx);
    f.status = 0;
    if (f.reader.FUN_002669f0()) {
        do {
            if (cache->FUN_00266710() == 4)
                break;
            f.reader.FUN_00266a30();
            content::ObjectLoader* ld = (*(Registry_265cd0**)&DAT_00527c58)->FUN_00265310(f.reader.FUN_00266c30());
            if (ld != 0) {
                if (listener != 0)
                    listener->v2(f.reader.FUN_00266c30());
                ld->AddRef();
                f.obj = 0;
                f.pair.a = 0;
                f.pair.b = 0;
                content::SimpleChunkHandler* sh = dynamic_cast<content::SimpleChunkHandler*>(ld);
                if (sh != 0) {
                    sh->reader = &f.reader;
                    sh->v3(&f.obj, &f.pair, 0, 0, stream);
                    if (f.obj != 0)
                        f.obj->AddRef();
                    int st = f.status;
                    sh->reader = 0;
                    if (st == 1)
                        f.status = sh->status;
                } else {
                    ld->v3(&f.obj, &f.pair, ctx->res, ctx->f108, ctx->f104);
                }
                ld->Release();
                if (listener != 0)
                    listener->v3(f.reader.FUN_00266c30(), f.obj, &f.pair);
                if (f.obj != 0) {
                    stream->v4(f.pair.a, f.pair.b, f.obj);
                    f.obj->Release();
                }
            }
            f.reader.FUN_00266be0();
        } while (f.reader.FUN_002669f0());
    }
    stream->FUN_002660a0(0);
    if (cache->FUN_00266710() != 4 && f.status == 0)
        cache->FUN_00266820(stream);
    res->Release();
    stream->Release();
    if (listener != 0)
        listener->v1(ctx);
    f.reader.FUN_002669c0();
}
}

} // namespace fn_f638de75
