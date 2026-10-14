// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 36/38, incomplete)
// content::P3DFileHandler::vfunc_3 @ 0x00265cd0
void* __cdecl FUN_00263ed0(unsigned int size, int flag);
int __cdecl FUN_00266da0(int mode);

struct Ctx_265cd0;
struct Cache_265cd0;
struct Stream;

struct Res_265cd0 {
    char pad04[8];
    unsigned char ok;
    char pad0d[3];
    virtual void AddRef();
    virtual void Release();
    Res_265cd0* FUN_002644d0(Ctx_265cd0* a, Cache_265cd0* b, int c);
    void* FUN_00263fb0();
};

struct Stream {
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b, void* obj);
    Stream* FUN_00266480(int size);
    void FUN_00266130(int v);
    void FUN_002660a0(void* v);
};

struct Reader {
    char pad00[0x288];
    Reader* FUN_00266cb0(void* handle);
    void FUN_002669d0(Ctx_265cd0* ctx);
    bool FUN_002669f0();
    int FUN_00266a30();
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
    void FUN_00266820(Stream* s);
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

extern Registry_265cd0* DAT_00527c58;

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
    Stream* stream = 0;
    if (mem2 != 0)
        stream = ((Stream*)mem2)->FUN_00266480(0x400);
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
            content::ObjectLoader* ld = DAT_00527c58->FUN_00265310(f.reader.FUN_00266c30());
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
