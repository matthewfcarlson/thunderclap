// STATUS: equivalent (tools/equiv.py level 3: 3092 inputs, branch coverage 76/86, incomplete)
// pure3d::OldFrameControllerLoader::vfunc_7 @ 0x002870d0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
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

struct NameHolder_2870d0 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct IdObj_2870d0 {
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

class Base_2870d0 {
public:
    IdObj_2870d0 *FUN_00288a10(int a);
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
    NameHolder_2870d0 nameHolder;
};

class ExpressionAnimationController_2870d0 : public Base_2870d0 { public: ExpressionAnimationController_2870d0 *FUN_002a9cb0(); void FUN_002a9ea0(void *r); };
class CameraAnimationController_2870d0 : public Base_2870d0 { public: CameraAnimationController_2870d0 *FUN_00292eb0(); void FUN_00293100(void *r); };
class BillboardQuadGroupAnimationController_2870d0 : public Base_2870d0 { public: BillboardQuadGroupAnimationController_2870d0 *FUN_002a9760(); void FUN_002a98f0(int v); };
class TextureAnimationController_2870d0 : public Base_2870d0 { public: TextureAnimationController_2870d0 *FUN_002a9410(); void FUN_002a9540(void *r); };
class ShaderAnimationController_2870d0 : public Base_2870d0 { public: ShaderAnimationController_2870d0 *FUN_002a83e0(); void FUN_002a8650(void *r); };
class ParticleController_2870d0 : public Base_2870d0 { public: ParticleController_2870d0 *FUN_002a73d0(); void FUN_002a75a0(void *r); };
class LightAnimationController_2870d0 : public Base_2870d0 { public: LightAnimationController_2870d0 *FUN_002a87c0(); void FUN_002a8aa0(void *r); };
class PoseAnimationController_2870d0 : public Base_2870d0 { public: PoseAnimationController_2870d0 *FUN_00287860(); void FUN_00288080(int v); };
class SceneGraphTransformAnimationController_2870d0 : public Base_2870d0 { public: SceneGraphTransformAnimationController_2870d0 *FUN_002a7730(); void FUN_002a77c0(pure3d::scenegraph::TransformNode *n); };
class CompDrawVisibilityAnimationController_2870d0 : public Base_2870d0 { public: CompDrawVisibilityAnimationController_2870d0 *FUN_002a80c0(); void FUN_002a8310(SceneRes *r); };
class SceneGraphVisibilityAnimationController_2870d0 : public Base_2870d0 { public: SceneGraphVisibilityAnimationController_2870d0 *FUN_002a7b90(); void FUN_002a7cf0(pure3d::scenegraph::VisibilityNode *n); };
class ProceduralVertexAnimController_2870d0 : public Base_2870d0 { public: ProceduralVertexAnimController_2870d0 *FUN_002a5420(); void FUN_002a6930(void *r); };
class VertexAnimController_2870d0 : public Base_2870d0 { public: VertexAnimController_2870d0 *FUN_002a6cb0(); void FUN_002a6ed0(void *r); };

void *__cdecl FUN_00286750(Reader *r, const char *name);
void *__cdecl FUN_000f23a0(Reader *r, const char *name);
R48 *__cdecl FUN_000f2340(Reader *r, const char *name);
void *__cdecl FUN_000c0db0(Reader *r, const char *name);
void *__cdecl FUN_000f2370(Reader *r, const char *name);
SceneRes *__cdecl FUN_000c0d80(Reader *r, const char *name);
SceneGraphObj *__cdecl FUN_000f23d0(Reader *r, const char *name);
void *__cdecl FUN_000c9ba0(Reader *r, const char *name);

struct Frame_2870d0 {
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
    virtual Base_2870d0 *v7(const char *name, unsigned int tag, StreamHolder *sh, Reader *r);
};

Base_2870d0 *OldFrameControllerLoader::v7(const char *name, unsigned int tag, StreamHolder *sh, Reader *r)
{
    Frame_2870d0 f;
    Base_2870d0 *esi = 0;
    Base_2870d0 *obj;
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
        esi = (Base_2870d0 *)r->v3(new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>, key);
    }

    switch (tag) {
    case 0x505845: {
        ExpressionAnimationController_2870d0 *p = (ExpressionAnimationController_2870d0 *)thunk_FUN_0008d690(0x50);
        ExpressionAnimationController_2870d0 *o;
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
        CameraAnimationController_2870d0 *p = (CameraAnimationController_2870d0 *)thunk_FUN_0008d690(0x118);
        CameraAnimationController_2870d0 *o;
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
        TextureAnimationController_2870d0 *p = (TextureAnimationController_2870d0 *)thunk_FUN_0008d690(0x48);
        TextureAnimationController_2870d0 *o;
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
        ShaderAnimationController_2870d0 *p = (ShaderAnimationController_2870d0 *)thunk_FUN_0008d690(0x48);
        ShaderAnimationController_2870d0 *o;
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
        VertexAnimController_2870d0 *p = (VertexAnimController_2870d0 *)thunk_FUN_0008d690(0x48);
        VertexAnimController_2870d0 *o;
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
        BillboardQuadGroupAnimationController_2870d0 *p = (BillboardQuadGroupAnimationController_2870d0 *)thunk_FUN_0008d690(0x48);
        BillboardQuadGroupAnimationController_2870d0 *o;
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
        ParticleController_2870d0 *p = (ParticleController_2870d0 *)thunk_FUN_0008d690(0x60);
        ParticleController_2870d0 *o;
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
        LightAnimationController_2870d0 *p = (LightAnimationController_2870d0 *)thunk_FUN_0008d690(0x118);
        LightAnimationController_2870d0 *o;
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
        PoseAnimationController_2870d0 *p = (PoseAnimationController_2870d0 *)thunk_FUN_0008d690(0x150);
        PoseAnimationController_2870d0 *o;
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
        SceneGraphTransformAnimationController_2870d0 *p = (SceneGraphTransformAnimationController_2870d0 *)thunk_FUN_0008d690(0x118);
        SceneGraphTransformAnimationController_2870d0 *o;
        if (p != 0)
            o = p->FUN_002a7730();
        else
            o = 0;
        o->nameHolder.FUN_0027b040(name);
        o->v24(esi, 0, 0);
        SceneGraphObj *sg = FUN_000f23d0(r, f.name1);
        if (sg == 0)
            return o;
        IdObj_2870d0 *id = esi->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = sg->FUN_002961e0(id->lo, id->hi, 2, 0);
        o->FUN_002a77c0(dynamic_cast<pure3d::scenegraph::TransformNode *>(nd));
        return o;
    }
    case 0x53495650: {
        CompDrawVisibilityAnimationController_2870d0 *p = (CompDrawVisibilityAnimationController_2870d0 *)thunk_FUN_0008d690(0x60);
        CompDrawVisibilityAnimationController_2870d0 *o;
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
        SceneGraphVisibilityAnimationController_2870d0 *p = (SceneGraphVisibilityAnimationController_2870d0 *)thunk_FUN_0008d690(0x48);
        SceneGraphVisibilityAnimationController_2870d0 *o;
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
        IdObj_2870d0 *id = esi->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = sg->FUN_002961e0(id->lo, id->hi, 4, 0);
        o->FUN_002a7cf0(dynamic_cast<pure3d::scenegraph::VisibilityNode *>(nd));
        return o;
    }
    case 0x54525650: {
        ProceduralVertexAnimController_2870d0 *p = (ProceduralVertexAnimController_2870d0 *)thunk_FUN_0008d690(0x58);
        ProceduralVertexAnimController_2870d0 *o;
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
