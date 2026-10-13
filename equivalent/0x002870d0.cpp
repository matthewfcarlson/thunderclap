// STATUS: equivalent (tools/equiv.py level 3: 3092 inputs, branch coverage 76/86, incomplete)
// pure3d::OldFrameControllerLoader::vfunc_7 @ 0x002870d0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
inline void *operator new(unsigned int, void *p) { return p; }

namespace pure3d {
class Animation;
class Geometry;
class Light;
namespace scenegraph {
class Scenegraph;
class Node { public: virtual void n0(); };
class TransformNode : public Node { public: virtual void t0(); };
class VisibilityNode : public Node { public: virtual void v0(); };
}
}

namespace content { namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
} }

void *thunk_FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class StreamHolder {
public:
    virtual void v0();
    char pad04[0x284 - 4];
    Stream *stream;
};

class Reader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(void *caster, unsigned __int64 key);
};

struct NameHolder {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct IdObj {
    char pad0[8];
    unsigned int lo;
    unsigned int hi;
};

class SceneRes {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11();
};

struct R48 {
    char pad0[0x48];
    int *f48;
};

struct SceneGraphObj {
    pure3d::scenegraph::Node *FUN_002961e0(unsigned int lo, unsigned int hi, int a, int b);
};

class Base {
public:
    IdObj *FUN_00288a10(int a);
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
    virtual void v22();
    virtual void v23();
    virtual void v24(void *a, int b, int c);
    char pad04[4];
    NameHolder nameHolder;
};

class Exp : public Base { public: Exp *FUN_002a9cb0(); void FUN_002a9ea0(void *r); };
class Cam : public Base { public: Cam *FUN_00292eb0(); void FUN_00293100(void *r); };
class Bqg : public Base { public: Bqg *FUN_002a9760(); void FUN_002a98f0(int v); };
class Tex : public Base { public: Tex *FUN_002a9410(); void FUN_002a9540(void *r); };
class Shad : public Base { public: Shad *FUN_002a83e0(); void FUN_002a8650(void *r); };
class Efx : public Base { public: Efx *FUN_002a73d0(); void FUN_002a75a0(void *r); };
class Lite : public Base { public: Lite *FUN_002a87c0(); void FUN_002a8aa0(void *r); };
class Ptrn : public Base { public: Ptrn *FUN_00287860(); void FUN_00288080(int v); };
class Strn : public Base { public: Strn *FUN_002a7730(); void FUN_002a77c0(pure3d::scenegraph::TransformNode *n); };
class Pvis : public Base { public: Pvis *FUN_002a80c0(); void FUN_002a8310(SceneRes *r); };
class Svis : public Base { public: Svis *FUN_002a7b90(); void FUN_002a7cf0(pure3d::scenegraph::VisibilityNode *n); };
class Pvrt : public Base { public: Pvrt *FUN_002a5420(); void FUN_002a6930(void *r); };
class Vrtx : public Base { public: Vrtx *FUN_002a6cb0(); void FUN_002a6ed0(void *r); };

void *__cdecl FUN_00286750(Reader *r, const char *name);
void *__cdecl FUN_000f23a0(Reader *r, const char *name);
R48 *__cdecl FUN_000f2340(Reader *r, const char *name);
void *__cdecl FUN_000c0db0(Reader *r, const char *name);
void *__cdecl FUN_000f2370(Reader *r, const char *name);
SceneRes *__cdecl FUN_000c0d80(Reader *r, const char *name);
SceneGraphObj *__cdecl FUN_000f23d0(Reader *r, const char *name);
void *__cdecl FUN_000c9ba0(Reader *r, const char *name);

struct Frame {
    char pad0[3];
    char b3;                // 0x03
    void *caster;           // 0x04 (placement-new'd DynamicCaster)
    int x8;                 // 0x08
    char name1[0x100];      // 0x0c
    char name2[0x100];      // 0x10c
};

class OldFrameControllerLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual Base *v7(const char *name, unsigned int tag, StreamHolder *sh, Reader *r);
};

Base *OldFrameControllerLoader::v7(const char *name, unsigned int tag, StreamHolder *sh, Reader *r)
{
    Frame f;
    Base *esi = 0;
    Base *obj;
    unsigned int len;

    sh->stream->FUN_002647e0(&f.x8, 1, 4, 1);
    sh->stream->FUN_002647e0(&f.b3, 1, 1, 1);
    len = (unsigned char)f.b3;
    sh->stream->FUN_002647e0(f.name1, len, 1, 1);
    sh->stream->FUN_002647e0(&f.b3, 1, 1, 1);
    f.name1[len] = 0;
    len = (unsigned char)f.b3;
    sh->stream->FUN_002647e0(f.name2, len, 1, 1);
    f.name2[len] = 0;
    if (tag != 0x584645) {
        unsigned __int64 key = FUN_0027b020(f.name2);
        esi = (Base *)r->v3(new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>, key);
    }

    switch (tag) {
    case 0x505845: {
        Exp *p = (Exp *)thunk_FUN_0008d690(0x50);
        Exp *o;
        if (p != 0)
            o = p->FUN_002a9cb0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        void *res = FUN_00286750(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_002a9ea0(res);
        return o;
    }
    case 0x4d4143: {
        Cam *p = (Cam *)thunk_FUN_0008d690(0x118);
        Cam *o;
        if (p != 0)
            o = p->FUN_00292eb0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        void *res = FUN_000f23a0(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_00293100(res);
        return o;
    }
    case 0x584554: {
        Tex *p = (Tex *)thunk_FUN_0008d690(0x48);
        Tex *o;
        if (p != 0)
            o = p->FUN_002a9410();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        void *res = FUN_000c0db0(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_002a9540(res);
        return o;
    }
    case 0x44414853: {
        Shad *p = (Shad *)thunk_FUN_0008d690(0x48);
        Shad *o;
        if (p != 0)
            o = p->FUN_002a83e0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        void *res = FUN_000c0db0(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_002a8650(res);
        return o;
    }
    case 0x58545256: {
        Vrtx *p = (Vrtx *)thunk_FUN_0008d690(0x48);
        Vrtx *o;
        if (p != 0)
            o = p->FUN_002a6cb0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        void *res = FUN_000c9ba0(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_002a6ed0(res);
        return o;
    }
    case 0x475142: {
        Bqg *p = (Bqg *)thunk_FUN_0008d690(0x48);
        Bqg *o;
        if (p != 0)
            o = p->FUN_002a9760();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        R48 *res = FUN_000f2340(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_002a98f0(*res->f48);
        return o;
    }
    case 0x584645: {
        Efx *p = (Efx *)thunk_FUN_0008d690(0x60);
        Efx *o;
        if (p != 0)
            o = p->FUN_002a73d0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        void *res = FUN_000f2370(r, f.name1);
        if (res != 0)
            o->FUN_002a75a0(res);
        return o;
    }
    case 0x4554494c: {
        Lite *p = (Lite *)thunk_FUN_0008d690(0x118);
        Lite *o;
        if (p != 0)
            o = p->FUN_002a87c0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        unsigned __int64 key = FUN_0027b020(f.name1);
        void *res = r->v3(new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Light>, key);
        if (res == 0)
            return o;
        o->FUN_002a8aa0(res);
        return o;
    }
    case 0x4e525450: {
        Ptrn *p = (Ptrn *)thunk_FUN_0008d690(0x150);
        Ptrn *o;
        if (p != 0)
            o = p->FUN_00287860();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        SceneRes *res = FUN_000c0d80(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_00288080(res->s11());
        return o;
    }
    case 0x4e525453: {
        Strn *p = (Strn *)thunk_FUN_0008d690(0x118);
        Strn *o;
        if (p != 0)
            o = p->FUN_002a7730();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        SceneGraphObj *sg = FUN_000f23d0(r, f.name1);
        if (sg == 0)
            return o;
        IdObj *id = esi->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = sg->FUN_002961e0(id->lo, id->hi, 2, 0);
        o->FUN_002a77c0(dynamic_cast<pure3d::scenegraph::TransformNode *>(nd));
        return o;
    }
    case 0x53495650: {
        Pvis *p = (Pvis *)thunk_FUN_0008d690(0x60);
        Pvis *o;
        if (p != 0)
            o = p->FUN_002a80c0();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        SceneRes *res = FUN_000c0d80(r, f.name1);
        if (res == 0)
            return o;
        o->FUN_002a8310(res);
        return o;
    }
    case 0x53495653: {
        Svis *p = (Svis *)thunk_FUN_0008d690(0x48);
        Svis *o;
        if (p != 0)
            o = p->FUN_002a7b90();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        unsigned __int64 key = FUN_0027b020(f.name1);
        SceneGraphObj *sg = (SceneGraphObj *)r->v3(new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph>, key);
        if (sg == 0)
            return o;
        IdObj *id = esi->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = sg->FUN_002961e0(id->lo, id->hi, 4, 0);
        o->FUN_002a7cf0(dynamic_cast<pure3d::scenegraph::VisibilityNode *>(nd));
        return o;
    }
    case 0x54525650: {
        Pvrt *p = (Pvrt *)thunk_FUN_0008d690(0x58);
        Pvrt *o;
        if (p != 0)
            o = p->FUN_002a5420();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        unsigned __int64 key = FUN_0027b020(f.name1);
        void *res = r->v3(new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Geometry>, key);
        if (res == 0)
            return o;
        o->FUN_002a6930(res);
        return o;
    }
    default:
        return 0;
    }
}
