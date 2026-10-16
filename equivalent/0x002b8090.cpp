// STATUS: equivalent (tools/equiv.py level 3: 15980 inputs, branch coverage 62/65, incomplete)
// pure3d::PolySkinLoader::vfunc_5 @ 0x002b8090
// equiv-map: ??_R0?AVFrameControllerLoader@pure3d@@@8 = 0x004ce770
// equiv-map: ??_R0?AVObjectLoader@content@@@8 = 0x0049c7dc
// equiv-map: ??_R0?AVExpressionAnimationController@pure3d@@@8 = 0x004cfadc
// equiv-map: ??_R0?AVFrameController@pure3d@@@8 = 0x0049fd74
// equiv-map: ??_R0?AVProceduralVertexAnimController@pure3d@@@8 = 0x004cf8b4
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/data/engine/content.h"

inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);

struct Stream;
struct Ctx;
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
class ObjectLoader {
public:
    virtual void AddRef();
    virtual void Release();
};
}

namespace pure3d {
class Skeleton;
class FrameController {
public:
    virtual void AddRef();
    virtual void Release();
};
class ExpressionAnimationController : public FrameController {
public:
    virtual void e2();
};
class ProceduralVertexAnimController : public FrameController {
public:
    virtual void p2();
};
class FrameControllerLoader : public content::ObjectLoader {
public:
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void load(FrameController **out, unsigned __int64 *outId, Stream *s, Ctx *ctx);
};
}

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Shared : RefObj {
    char pad04[0xc];
    int f10;
    int FUN_0027b240();
};

struct SkinInfo : RefObj {
    char pad04[0x10];
    SkinInfo *FUN_002e1750(int n);
};

struct Binder : RefObj {
    char pad04[0x14];
    Binder *FUN_002d0fa0(void *owner);
};

struct LinkedA : RefObj {
    virtual void a2();
    virtual void a3();
    virtual LinkedA *Clone();
    void FUN_002a9f30(void *owner);
};

struct LinkedB : RefObj {
    virtual void b2();
    virtual void b3();
    virtual LinkedB *Clone();
    void FUN_002a6a20(void *owner);
};

struct Ctx {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual Shared *load(content::LoadInventory::DynamicCaster<pure3d::Skeleton> *caster, unsigned __int64 id);
};

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Part {
    void *prim;
    char pad04[12];
};

struct TmpObj {
    char pad[4];
    TmpObj *FUN_002e4e90();
    void FUN_002e4ea0();
    RefObj *FUN_002e6340(Stream *s, Ctx *ctx);
};

struct Helper1 {
    void FUN_002df840(int a);
    void FUN_002e4d70(Part *part, Stream *s, Ctx *ctx, SkinInfo *info, bool flag, void *blob);
};

struct Helper2 {
    void FUN_002df890(int a);
    void FUN_002e4e00(Part *part, Stream *s, Ctx *ctx, SkinInfo *info, bool flag);
};


struct LoaderRegistry {
    content::ObjectLoader *FUN_00265310(unsigned int id);
};

class __declspec(novtable) DrawableContainerBase {
public:
    virtual void v0();
    char pad04[4];
    Name name;
    char pad10[4];
    float v14[3];
    float v20[3];
    float v2c[3];
    unsigned int f38;
    char pad3c[4];
    float f40;
    char pad44[4];
    Part *partsBegin;
    Part *partsEnd;
    char pad50[8];
    DrawableContainerBase *FUN_002a4e10(int n);
    DrawableContainerBase(int n) { FUN_002a4e10(n); }
};

namespace pure3d {
class PolySkin : public DrawableContainerBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void SetInfo(int v);
    SkinInfo *info;
    Shared *shared;
    int field60;
    RefObj *binderShared;
    Binder *binder;
    pure3d::ExpressionAnimationController *linkA;
    pure3d::ProceduralVertexAnimController *linkB;
    PolySkin(int n) : DrawableContainerBase(n)
    {
        info = 0;
        shared = 0;
        field60 = 0;
        binderShared = 0;
        binder = 0;
        linkA = 0;
        linkB = 0;
    }
};
}
using pure3d::PolySkin;

namespace pure3d { class PolySkinLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(PolySkin **out, unsigned __int64 *outId, Stream *s, Ctx *ctx);
    char pad04[0x10];
    bool f14;
    char pad15[3];
    int f18;
    Helper1 *h1;
    Helper2 *h2;
    int f24;
    int f28;
}; }

void pure3d::PolySkinLoader::vfunc_5(PolySkin **out, unsigned __int64 *outId, Stream *stream, Ctx *ctx)
{
    struct Frame {
        char pad10[3];
        unsigned char len;
        unsigned int count;
        pure3d::FrameController *ctl;
        char pad1c[3];
        bool notPlain;
        int partOff;
        void *spill;
        union {
            unsigned char b[8];
            unsigned int w[2];
        } blob;
        unsigned int t4;
        float v;
        pure3d::ProceduralVertexAnimController *pv;
        unsigned int t3;
        unsigned int t7;
        unsigned int t2;
        unsigned int t6;
        unsigned int pad4c;
        unsigned int t1;
        unsigned int t5;
        unsigned int t0;
        unsigned int dummy;
        unsigned int tmpId[2];
        char name1[0x100];
        char name2[0x100];
    } f;
    f.spill = this;
    f.blob.w[0] = f24;
    f.blob.w[1] = f28;

    stream->reader->FUN_002647e0(&f.len, 1, 1, 1);
    stream->reader->FUN_002647e0(f.name1, f.len, 1, 1);
    stream->reader->FUN_002647e0(&f.count, 1, 4, 1);
    f.name1[f.len] = 0;
    f.notPlain = f.count != 4;
    stream->reader->FUN_002647e0(&f.len, 1, 1, 1);
    stream->reader->FUN_002647e0(f.name2, f.len, 1, 1);
    f.name2[f.len] = 0;

    void *mem = thunk_FUN_0008d690(0x78);
    PolySkin *skin = 0;
    if (mem != 0) {
        stream->reader->FUN_002647e0(&f.count, 1, 4, 1);
        skin = new (mem) PolySkin(f.count);
    }
    skin->name.FUN_0027b040(f.name1);
    unsigned __int64 id = FUN_0027b020(f.name2);
    {
        content::LoadInventory::DynamicCaster<pure3d::Skeleton> *caster =
            new (&f.count) content::LoadInventory::DynamicCaster<pure3d::Skeleton>();
        skin->shared = ctx->load(caster, id);
    }
    if (skin->shared != 0) {
        void *m = FUN_0008d690(0x14);
        SkinInfo *si = 0;
        if (m != 0)
            si = ((SkinInfo *)m)->FUN_002e1750(skin->shared->f10 + 1);
        skin->info = si;
        si->AddRef();
        skin->shared->AddRef();
        skin->SetInfo(skin->shared->FUN_0027b240());
    }

    f.partOff = 0;
    while (stream->FUN_002669f0()) {
        unsigned int cid = stream->FUN_00266a30();
        switch (cid) {
        case 0x121201: {
                content::ObjectLoader *ol = (*(LoaderRegistry**)&DAT_00527c58)->FUN_00265310(0x121201);
                pure3d::FrameControllerLoader *fl = dynamic_cast<pure3d::FrameControllerLoader *>(ol);
                fl->AddRef();
                f.ctl = 0;
                fl->load(&f.ctl, (unsigned __int64 *)f.tmpId, stream, ctx);
                pure3d::FrameController *ctl = f.ctl;
                if (ctl != 0) {
                    pure3d::ExpressionAnimationController *ea = dynamic_cast<pure3d::ExpressionAnimationController *>(ctl);
                    f.pv = dynamic_cast<pure3d::ProceduralVertexAnimController *>(ctl);
                    if (ea != 0) {
                        ea->AddRef();
                        if (skin->linkA != 0)
                            skin->linkA->Release();
                        skin->linkA = ea;
                        if (ea != 0)
                            ((LinkedA *)ea)->FUN_002a9f30(skin);
                    } else if (f.pv != 0) {
                        f.pv->AddRef();
                        if (skin->linkB != 0)
                            skin->linkB->Release();
                        skin->linkB = f.pv;
                        if (f.pv != 0)
                            ((LinkedB *)f.pv)->FUN_002a6a20(skin);
                    } else {
                        ctl->Release();
                        f.ctl = 0;
                    }
                }
                fl->Release();
            break;
        }
        case 0x121305: {
                TmpObj &tmp = *(TmpObj *)&f.count;
                tmp.FUN_002e4e90();
                RefObj *b = tmp.FUN_002e6340(stream, ctx);
                if (b != 0)
                    b->AddRef();
                if (skin->binderShared != 0)
                    skin->binderShared->Release();
                skin->binderShared = b;
                void *m = FUN_0008d690(0x18);
                Binder *nb = 0;
                if (m != 0)
                    nb = ((Binder *)m)->FUN_002d0fa0(skin);
                if (nb != 0)
                    nb->AddRef();
                if (skin->binder != 0)
                    skin->binder->Release();
                skin->binder = nb;
                tmp.FUN_002e4ea0();
            break;
        }
        case 0x122000: {
                stream->reader->FUN_002647e0(&f.dummy, 1, 4, 1);
                stream->reader->FUN_002647e0(&f.v, 1, 4, 1);
                float v = f.v;
                if (v >= 0.0f) {
                    if (v <= 1.0f)
                        skin->f40 = v;
                    else
                        skin->f40 = 1.0f;
                } else {
                    skin->f40 = 0.0f;
                }
            break;
        }
        case 0x10021: {
            stream->reader->FUN_002647e0(&f.t0, 1, 4, 1);
            stream->reader->FUN_002647e0(&f.t1, 1, 4, 1);
            f.blob.b[0] = (unsigned char)f.t1;
            stream->reader->FUN_002647e0(&f.t2, 1, 4, 1);
            f.blob.b[1] = (unsigned char)f.t2;
            stream->reader->FUN_002647e0(&f.t3, 1, 4, 1);
            f.blob.b[2] = (unsigned char)f.t3;
            stream->reader->FUN_002647e0(&f.t4, 1, 4, 1);
            f.blob.b[3] = (unsigned char)f.t4;
            stream->reader->FUN_002647e0(&f.t5, 1, 4, 1);
            f.blob.b[4] = (unsigned char)f.t5;
            stream->reader->FUN_002647e0(&f.t6, 1, 4, 1);
            f.blob.b[5] = (unsigned char)f.t6;
            stream->reader->FUN_002647e0(&f.t7, 1, 4, 1);
            f.blob.b[6] = (unsigned char)f.t7;
            break;
        }
        case 0x10020: {
            h1->FUN_002df840(f18);
            h1->FUN_002e4d70((Part *)((char *)skin->partsBegin + f.partOff), stream, ctx, skin->info, f14, &f.blob);
            f.partOff += sizeof(Part);
            break;
        }
        case 0x10002: {
            h2->FUN_002df890(f18);
            h2->FUN_002e4e00((Part *)((char *)skin->partsBegin + f.partOff), stream, ctx, skin->info, f14 && f.notPlain);
            f.partOff += sizeof(Part);
            break;
        }
        case 0x10003: {
            stream->reader->FUN_002647e0(skin->v14, 3, 4, 1);
            stream->reader->FUN_002647e0(skin->v20, 3, 4, 1);
            break;
        }
        case 0x10004: {
            stream->reader->FUN_002647e0(skin->v2c, 3, 4, 1);
            stream->reader->FUN_002647e0(&f.pad4c, 1, 4, 1);
            skin->f38 = f.pad4c;
            break;
        }
        }
        stream->FUN_00266be0();
    }
    *out = skin;
    *outId = FUN_002672f0(f.name1, 0);
}
