// STATUS: equivalent (tools/equiv.py level 3: 15869 inputs, branch coverage 56/61, incomplete)
// pure3d::GeometryLoader::vfunc_5 @ 0x002c2ab0
// pure3d::GeometryLoader::vfunc_5 @ 0x002c2ab0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
inline void* operator new(unsigned int, void* p) throw() { return p; }
inline void operator delete(void*, void*) throw() {}
void* thunk_FUN_0008d690(unsigned int size) throw();
void* FUN_0008d690(unsigned int size) throw();
typedef unsigned long long u64_2c2ab0;
struct Words64_2c2ab0 { unsigned int lo, hi; };    // 4-aligned stand-in for a 64-bit out value

class RefObj_2c2ab0 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

namespace content {
class ObjectLoader : public RefObj_2c2ab0 {
public:
    virtual void v2() throw();
};
}

struct Ctx;
struct Loader_2c2ab0;
class Geometry;

namespace pure3d {
class FrameController : public RefObj_2c2ab0 {
public:
    virtual void v2() throw();
};
class VertexAnimController : public FrameController {
public:
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5(Geometry* g) throw();
};
class ProceduralVertexAnimController : public FrameController {
public:
    virtual void v3() throw();
    void FUN_002a6930(Geometry* g) throw();
};
class FrameControllerLoader : public content::ObjectLoader {
public:
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5(FrameController** out, Words64_2c2ab0* res, Loader_2c2ab0* ld, Ctx* ctx) throw();
};
}

struct Stream {
    void FUN_002647e0(void* dst, int a, int b, int c) throw();
};

struct Loader_2c2ab0 {
    char pad000[0x284];
    Stream* stream;
    bool FUN_002669f0() throw();
    unsigned int FUN_00266a30() throw();
    void FUN_00266be0() throw();
};

struct Mgr_2c2ab0 {
    content::ObjectLoader* FUN_00265310(unsigned int id) throw();
};
extern Mgr_2c2ab0* DAT_00527c58;

struct Holder_2c2ab0 {
    void* p;
    void FUN_002e4e90() throw();
    RefObj_2c2ab0* FUN_002e6340(Loader_2c2ab0* ld, Ctx* ctx) throw();
    void FUN_002e4ea0() throw();
};

struct Pair_2c2ab0 {
    unsigned int w16;
    unsigned int w20;
};

struct Obj18_2c2ab0 : public RefObj_2c2ab0 {
    Obj18_2c2ab0* FUN_002d1090(Geometry* g) throw();
};

struct NameObj_2c2ab0 {
    char data[0xc];
    void FUN_0027b040(const char* s) throw();
};

class __declspec(novtable) GeometryBase {
public:
    virtual void g0() throw();
    virtual void g1() throw();
    char pad04[4];
    NameObj_2c2ab0 name;
    float v14[3];
    float v20[3];
    float v2c[3];
    unsigned int f38;
    char pad3c[4];
    float f40;
    char pad44[4];
    char* buf48;
    char pad4c[0xc];
    void FUN_002a4e10(unsigned int n) throw();
    GeometryBase(unsigned int n) { FUN_002a4e10(n); }
};

class Geometry : public GeometryBase {
public:
    Geometry(unsigned int n) : GeometryBase(n) { p58 = 0; p5c = 0; p60 = 0; p64 = 0; }
    virtual void g0() throw();
    virtual void g1() throw();
    RefObj_2c2ab0* p58;
    RefObj_2c2ab0* p5c;
    pure3d::VertexAnimController* p60;
    pure3d::ProceduralVertexAnimController* p64;
};

struct SubA_2c2ab0 {
    void FUN_002df840(unsigned int a) throw();
    void FUN_002e4d70(char* dst, Loader_2c2ab0* ld, Ctx* ctx, int z, int f, Pair_2c2ab0* p) throw();
};
struct SubB_2c2ab0 {
    void FUN_002df890(unsigned int a) throw();
    void FUN_002e4e00(char* dst, Loader_2c2ab0* ld, Ctx* ctx, int z, bool f) throw();
};

u64_2c2ab0 FUN_002672f0(const char* name, int a, int b) throw();

namespace pure3d {
class GeometryLoader {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual u64_2c2ab0 vfunc_5(Geometry** out, u64_2c2ab0* hashOut, Loader_2c2ab0* ld, Ctx* ctx) throw();
    char pad04[0x10];
    unsigned char f14;
    char pad15[3];
    unsigned int f18;
    SubA_2c2ab0* f1c;
    SubB_2c2ab0* f20;
    unsigned int f24;
    unsigned int f28;
};

u64_2c2ab0 GeometryLoader::vfunc_5(Geometry** out, u64_2c2ab0* hashOut, Loader_2c2ab0* ld, Ctx* ctx)
{
    struct Frame {
        char pad0[3];
        unsigned char lenFlag;      // S+3
        union {
            unsigned int version;   // S+4
            Holder_2c2ab0 holder;
        };
        FrameController* ctl;       // S+8
        GeometryLoader* self;       // S+12
        union {                     // S+16
            Pair_2c2ab0 pair;
            unsigned char b[8];
        };
        int offset;                 // S+24
        unsigned int r5;            // S+28
        float clampv;               // S+32
        unsigned int r3;            // S+36
        ProceduralVertexAnimController* proc;  // S+40
        unsigned int vtxAttr;       // S+44
        unsigned int r4;            // S+48
        unsigned int r2;            // S+52
        unsigned int r6;            // S+56
        unsigned int r8;            // S+60
        unsigned int r7;            // S+64
        unsigned int r1;            // S+68
        unsigned int skip;          // S+72
        Words64_2c2ab0 res;         // S+76
        char name[256];             // S+84
    } fr;

    fr.pair.w20 = f28;
    fr.self = this;
    fr.pair.w16 = f24;
    ld->stream->FUN_002647e0(&fr.lenFlag, 1, 1, 1);
    ld->stream->FUN_002647e0(fr.name, fr.lenFlag, 1, 1);
    fr.name[fr.lenFlag] = 0;
    ld->stream->FUN_002647e0(&fr.version, 1, 4, 1);
    fr.lenFlag = (fr.version != 1);
    Geometry* g;
    void* mem = thunk_FUN_0008d690(0x68);
    if (mem) {
        ld->stream->FUN_002647e0(&fr.version, 1, 4, 1);
        g = new (mem) Geometry(fr.version);
    } else {
        g = 0;
    }
    g->name.FUN_0027b040(fr.name);
    if (ld->FUN_002669f0()) {
        fr.offset = 0;
        do {
            switch (ld->FUN_00266a30()) {
            case 0x10020:
                f1c->FUN_002df840(f18);
                f1c->FUN_002e4d70(g->buf48 + fr.offset, ld, ctx, 0, f14, &fr.pair);
                fr.offset += 0x10;
                break;
            case 0x10002:
                f20->FUN_002df890(f18);
                f20->FUN_002e4e00(g->buf48 + fr.offset, ld, ctx, 0, f14 && fr.lenFlag);
                fr.offset += 0x10;
                break;
            case 0x10003:
                ld->stream->FUN_002647e0(g->v14, 3, 4, 1);
                ld->stream->FUN_002647e0(g->v20, 3, 4, 1);
                break;
            case 0x10004:
                ld->stream->FUN_002647e0(g->v2c, 3, 4, 1);
                ld->stream->FUN_002647e0(&fr.vtxAttr, 1, 4, 1);
                g->f38 = fr.vtxAttr;
                break;
            case 0x10021:
                ld->stream->FUN_002647e0(&fr.r1, 1, 4, 1);
                ld->stream->FUN_002647e0(&fr.r2, 1, 4, 1);
                fr.b[0] = (unsigned char)fr.r2;
                ld->stream->FUN_002647e0(&fr.r3, 1, 4, 1);
                fr.b[1] = (unsigned char)fr.r3;
                ld->stream->FUN_002647e0(&fr.r4, 1, 4, 1);
                fr.b[2] = (unsigned char)fr.r4;
                ld->stream->FUN_002647e0(&fr.r5, 1, 4, 1);
                fr.b[3] = (unsigned char)fr.r5;
                ld->stream->FUN_002647e0(&fr.r6, 1, 4, 1);
                fr.b[4] = (unsigned char)fr.r6;
                ld->stream->FUN_002647e0(&fr.r7, 1, 4, 1);
                fr.b[5] = (unsigned char)fr.r7;
                ld->stream->FUN_002647e0(&fr.r8, 1, 4, 1);
                fr.b[6] = (unsigned char)fr.r8;
                break;
            case 0x122000:
                ld->stream->FUN_002647e0(&fr.skip, 1, 4, 1);
                ld->stream->FUN_002647e0(&fr.clampv, 1, 4, 1);
                if (!(fr.clampv >= 0.0f))
                    g->f40 = 0.0f;
                else if (fr.clampv > 1.0f)
                    g->f40 = 1.0f;
                else
                    g->f40 = fr.clampv;
                break;
            case 0x121305: {
                fr.holder.FUN_002e4e90();
                RefObj_2c2ab0* a = fr.holder.FUN_002e6340(ld, ctx);
                if (a)
                    a->AddRef();
                if (g->p58)
                    g->p58->Release();
                g->p58 = a;
                void* m = FUN_0008d690(0x18);
                Obj18_2c2ab0* o;
                if (m)
                    o = ((Obj18_2c2ab0*)m)->FUN_002d1090(g);
                else
                    o = 0;
                if (o)
                    o->AddRef();
                if (g->p5c)
                    g->p5c->Release();
                g->p5c = o;
                fr.holder.FUN_002e4ea0();
                break;
            }
            case 0x121201: {
                FrameControllerLoader* fl = dynamic_cast<FrameControllerLoader*>(DAT_00527c58->FUN_00265310(0x121201));
                fl->AddRef();
                fr.ctl = 0;
                fl->v5(&fr.ctl, &fr.res, ld, ctx);
                if (fr.ctl) {
                    VertexAnimController* va = dynamic_cast<VertexAnimController*>(fr.ctl);
                    fr.proc = dynamic_cast<ProceduralVertexAnimController*>(fr.ctl);
                    if (va) {
                        va->AddRef();
                        if (g->p60)
                            g->p60->Release();
                        g->p60 = va;
                        if (va)
                            va->v5(g);
                    } else if (fr.proc) {
                        fr.proc->AddRef();
                        if (g->p64)
                            g->p64->Release();
                        g->p64 = fr.proc;
                        if (fr.proc)
                            fr.proc->FUN_002a6930(g);
                    } else {
                        fr.ctl->Release();
                        fr.ctl = 0;
                    }
                }
                fl->Release();
                break;
            }
            default:
                break;
            }
            ld->FUN_00266be0();
        } while (ld->FUN_002669f0());
    }
    *out = g;
    u64_2c2ab0 r = FUN_002672f0(fr.name, 0, 0);
    *hashOut = r;
    return r;
}
}
