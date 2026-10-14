// STATUS: equivalent (tools/equiv.py level 3: 196 inputs, branch coverage 54/64, incomplete)
// FUN_002ac610 @ 0x002ac610
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ??_R0?AVAnimationLoader@pure3d@@@8 = 0x004ce974
// equiv-map: ??_R0?AVObjectLoader@content@@@8 = 0x0049c7dc
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
struct Stream;
struct Ctx_2ac610;
namespace pure3d { class Shader; }

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

struct RefObj_2ac610 {
    virtual void AddRef();
    virtual void Release();
};

struct LoadedRes : RefObj_2ac610 {
    char pad04[0x18];
    unsigned int type;
    char pad20[8];
    int count;
    LoadedRes *FUN_00288a10(int i);
    int FUN_00288960(unsigned int a, unsigned int b);
};

namespace pure3d {
class AnimationLoader : public content::ObjectLoader {
public:
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void load(LoadedRes **out, unsigned __int64 *id, Stream *s, Ctx_2ac610 *ctx);
    int FUN_00288e90();
    void FUN_00288e80(int v);
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
    int FUN_00266c30();
};

struct LoaderRegistry {
    content::ObjectLoader *FUN_00265310(unsigned int id);
};
extern LoaderRegistry *DAT_00527c58;

class Ctx_2ac610 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual RefObj_2ac610 *load(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, unsigned __int64 id);
};

struct Name_2ac610 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct IntVec_2ac610 {
    unsigned int *begin;
    unsigned int *end;
    void FUN_002ab880(unsigned int n, const unsigned int *def);
};

struct PtrVec_2ac610 {
    RefObj_2ac610 **begin;
    RefObj_2ac610 **end;
    void FUN_002ab8e0(int n, const unsigned int *def);
};

struct Matrix {
    void FUN_0022b980();
};
struct Small_2ac610 {
    Small_2ac610 *FUN_002d6760();
    virtual void AddRef();
    virtual void Release();
};
struct Sub4c : RefObj_2ac610 {
    Sub4c *FUN_002d4040(LoadedRes *r);
};
struct Sub30 : RefObj_2ac610 {
    Sub30 *FUN_002d5640(LoadedRes *r, unsigned int n, float f);
};
RefObj_2ac610 *__cdecl FUN_002aa160(unsigned int v);

class Obj_2ac610 : public RefObj_2ac610 {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void SetShader(RefObj_2ac610 *s);
    char pad24[4];
    Name_2ac610 name;
    char pad10[4];
    float v14[3];
    float v20[3];
    float v2c[3];
    unsigned int f38;
    char pad3c[0x4c];
    RefObj_2ac610 *f88;
    RefObj_2ac610 *f8c;
    Small_2ac610 *f90;
    int f94;
    char pad98[0xd];
    unsigned char fa5;
    unsigned char fa6;
    char pada7[0x130 - 0xa7];
    int f130;
    int f134;
    char pad138[4];
    int f13c;
    Matrix *f140;
    unsigned int f144;
    unsigned int f148;
    char pad14c[0x10];
    unsigned char f15c;
    char pad15d[0x184 - 0x15d];
    unsigned int f184;
    unsigned int f188;
    char pad18c[0x30];
    RefObj_2ac610 *f1bc;
    RefObj_2ac610 *f1c0;
    RefObj_2ac610 *f1c4;
    IntVec_2ac610 f1c8;
    char pad1d0[4];
    PtrVec_2ac610 f1d4;
    char pad1dc[0x1e0 - 0x1dc];
    Obj_2ac610 *FUN_002d63a0();
};

struct Extra_2ac610 {
    char FUN_002aa550(int v);
    RefObj_2ac610 *FUN_002aa590(Stream *s, Ctx_2ac610 *ctx);
};

class Loader_2ac610 {
public:
    void FUN_002a46d0(int a1, Obj_2ac610 *o);
    void FUN_002a4b00(int a1, Stream *s, Ctx_2ac610 *ctx);
    void FUN_002ac610(int a1, Stream *stream, Ctx_2ac610 *ctx, Extra_2ac610 *a4);
};

struct Frame_2ac610 {
    char pad10[3];
    unsigned char b13;
    union {
        unsigned int u;
        float f;
    } s14;
    union {
        unsigned int u;
        float f;
        LoadedRes *res;
    } s18;
    char pad1c[3];
    unsigned char flagC;
    unsigned int s20;
    unsigned int s24;
    unsigned int s28;
    unsigned int s2c;
    unsigned int s30;
    unsigned int s34;
    Loader_2ac610 *self;
    unsigned int casterSlot;
    unsigned int s40[2];
    char name1[0x100];
    char name2[0x100];
};

void Loader_2ac610::FUN_002ac610(int a1, Stream *stream, Ctx_2ac610 *ctx, Extra_2ac610 *a4)
{
    Frame_2ac610 f;
    f.self = this;
    stream->reader->FUN_002647e0(&f.s2c, 1, 4, 1);
    stream->reader->FUN_002647e0(&f.b13, 1, 1, 1);
    unsigned int len = f.b13;
    stream->reader->FUN_002647e0(f.name1, len, 1, 1);
    stream->reader->FUN_002647e0(&f.b13, 1, 1, 1);
    f.name1[len] = 0;
    len = f.b13;
    stream->reader->FUN_002647e0(f.name2, len, 1, 1);
    f.name2[len] = 0;
    stream->reader->FUN_002647e0(&f.s28, 1, 4, 1);
    stream->reader->FUN_002647e0(&f.s14.u, 1, 4, 1);
    bool flagA = f.s14.u != 0;
    stream->reader->FUN_002647e0(&f.s14.u, 1, 4, 1);
    unsigned int tb = f.s14.u;
    stream->reader->FUN_002647e0(&f.s20, 1, 4, 1);
    f.b13 = tb != 0;
    stream->reader->FUN_002647e0(&f.s14.u, 1, 4, 1);
    unsigned int e = f.s14.u;
    stream->reader->FUN_002647e0(&f.s2c, 1, 4, 1);
    f.flagC = e != 0;
    stream->reader->FUN_002647e0(&f.s30, 1, 4, 1);
    stream->reader->FUN_002647e0(&f.s40[0], 1, 4, 1);
    stream->reader->FUN_002647e0(&f.s24, 1, 4, 1);
    stream->reader->FUN_002647e0(&f.s18.u, 1, 4, 1);
    stream->reader->FUN_002647e0(&f.s14.u, 1, 4, 1);

    void *mem = thunk_FUN_0008d690(0x1e0);
    Obj_2ac610 *obj = 0;
    if (mem != 0)
        obj = ((Obj_2ac610 *)mem)->FUN_002d63a0();
    FUN_002a46d0(a1, obj);
    obj->name.FUN_0027b040(f.name1);
    unsigned __int64 id = FUN_0027b020(f.name2);
    content::LoadInventory::DynamicCaster<pure3d::Shader> *caster =
        new (&f.casterSlot) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    obj->SetShader(ctx->load(caster, id));
    obj->fa6 = f.b13;
    obj->f15c = f.flagC;
    obj->f188 = f.s24;
    obj->f144 = f.s18.u;
    obj->f184 = f.s40[0];
    obj->fa5 = flagA;
    obj->f148 = f.s14.u;
    f.s24 = 0;
    obj->f1c8.FUN_002ab880(f.s20, &f.s24);
    if (f.s18.f > 0.0f || f.s14.f > 0.0f) {
        void *m = FUN_0008d690(0x40);
        obj->f140 = (Matrix *)m;
        ((Matrix *)m)->FUN_0022b980();
    }
    void *sm = FUN_0008d690(8);
    Small_2ac610 *small = 0;
    if (sm != 0)
        small = ((Small_2ac610 *)sm)->FUN_002d6760();
    obj->f90 = small;
    small->AddRef();
    RefObj_2ac610 *hold = FUN_002aa160(f.s28);
    if (hold != 0)
        hold->AddRef();
    if (obj->f8c != 0)
        obj->f8c->Release();
    obj->f8c = hold;
    while (stream->FUN_002669f0()) {
        unsigned int cid = stream->FUN_00266a30();
        if (cid == 0x121000) {
            content::ObjectLoader *ol = DAT_00527c58->FUN_00265310(0x121000);
            pure3d::AnimationLoader *al = dynamic_cast<pure3d::AnimationLoader *>(ol);
            al->AddRef();
            f.s24 = al->FUN_00288e90();
            al->FUN_00288e80(1);
            al->load(&f.s18.res, (unsigned __int64 *)f.s40, stream, ctx);
            LoadedRes *r = f.s18.res;
            if (r != 0) {
                if (r->type == 0x4d455053) {
                    r->AddRef();
                    if (obj->f1c0 != 0)
                        obj->f1c0->Release();
                    obj->f1c0 = r;
                    f.s14.u = f.s18.res->count;
                    f.s20 = 0;
                    obj->f1d4.FUN_002ab8e0(f.s14.u, &f.s20);
                    int i = 0;
                    if ((int)f.s14.u > 0) {
                        do {
                            void *m = FUN_0008d690(0x4c);
                            f.s20 = (unsigned int)m;
                            Sub4c *sub = 0;
                            if (m != 0)
                                sub = ((Sub4c *)m)->FUN_002d4040(f.s18.res->FUN_00288a10(i));
                            obj->f1d4.begin[obj->f94] = sub;
                            obj->f1d4.begin[obj->f94]->AddRef();
                            obj->f94++;
                            i++;
                        } while (i < (int)f.s14.u);
                    }
                    LoadedRes *r0 = f.s18.res->FUN_00288a10(0);
                    obj->f130 = r0->FUN_00288960('T' | ('R' << 8) | ('A' << 16), 'V' | ('E' << 8) | ('C' << 16) | ('T' << 24));
                    obj->f134 = r0->FUN_00288960('R' | ('O' << 8) | ('T' << 16), 'R' | ('O' << 8) | ('T' << 16));
                    obj->f13c = r0->FUN_00288960('V' | ('I' << 8) | ('S' << 16), 'B' | ('O' << 8) | ('O' << 16) | ('L' << 24));
                } else if (r->type == 0x52415053) {
                    r->AddRef();
                    if (obj->f1c4 != 0)
                        obj->f1c4->Release();
                    obj->f1c4 = r;
                    void *m = FUN_0008d690(0x30);
                    Sub30 *s30 = 0;
                    if (m != 0)
                        s30 = ((Sub30 *)m)->FUN_002d5640(f.s18.res, f.s2c, (float)f.s30);
                    if (s30 != 0)
                        s30->AddRef();
                    if (obj->f1bc != 0)
                        obj->f1bc->Release();
                    obj->f1bc = s30;
                }
            }
            al->FUN_00288e80(f.s24);
            al->Release();
        } else if (cid == 0x10003) {
            stream->reader->FUN_002647e0(obj->v14, 3, 4, 1);
            stream->reader->FUN_002647e0(obj->v20, 3, 4, 1);
        } else if (cid == 0x10004) {
            stream->reader->FUN_002647e0(obj->v2c, 3, 4, 1);
            stream->reader->FUN_002647e0(&f.s28, 1, 4, 1);
            obj->f38 = f.s28;
        } else if (cid == 0x121204) {
            f.self->FUN_002a4b00(a1, stream, ctx);
        } else if (a4 != 0) {
            if (a4->FUN_002aa550(stream->FUN_00266c30()) == 1) {
                RefObj_2ac610 *nr = a4->FUN_002aa590(stream, ctx);
                if (nr != 0)
                    nr->AddRef();
                if (obj->f88 != 0)
                    obj->f88->Release();
                obj->f88 = nr;
            }
        }
        stream->FUN_00266be0();
    }
}
