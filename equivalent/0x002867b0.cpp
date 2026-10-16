// STATUS: equivalent (tools/equiv.py level 3: 12106 inputs, branch coverage 106/106)
// pure3d::DefaultFrameControllerHandler::vfunc_4 @ 0x002867b0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

void *thunk_FUN_0008d690(unsigned int size);

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class Animation;
class CompositeDrawable;
class Geometry;
class ParticleSystem;
namespace scenegraph {
class Node {
public:
    virtual void n0();
};
class TransformNode : public Node {
public:
    virtual void t0();
};
class VisibilityNode : public Node {
public:
    virtual void v0();
};
}
}

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
};

struct NameHolder {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct TaPair {
    char pad00[8];
    int f8;
    int fc;
};

class Cast2 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void *c11();
    TaPair *FUN_00288a10(int z);
};

class Inv {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Cast2 *i3(void *caster, unsigned __int64 key);
};

class Res {
public:
    pure3d::scenegraph::Node *FUN_002961e0(int a, int b, int c, int d);
    char pad00[0x48];
};

class FcBase {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int mode);
    virtual void v17();
    virtual void v18(int v);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(void *anim, int a, int b);
    char pad04[4];
    NameHolder name;
};

class FcExp : public FcBase {
public:
    FcExp *FUN_002a9cb0();
    void FUN_002a9ea0(void *r);
};

class FcMac : public FcBase {
public:
    FcMac *FUN_00292eb0();
    void FUN_00293100(void *r);
};

class FcBqg : public FcBase {
public:
    FcBqg *FUN_002a9760();
    void FUN_002a98f0(void *r);
};

class FcTex : public FcBase {
public:
    FcTex *FUN_002a9410();
    void FUN_002a9540(void *r);
};

class FcShad : public FcBase {
public:
    FcShad *FUN_002a83e0();
    void FUN_002a8650(void *r);
};

class FcLite : public FcBase {
public:
    FcLite *FUN_002a87c0();
    void FUN_002a8aa0(void *r);
};

class FcPtrn : public FcBase {
public:
    FcPtrn *FUN_00287860();
    void FUN_00288080(void *r);
};

class FcStrn : public FcBase {
public:
    FcStrn *FUN_002a7730();
    void FUN_002a77c0(pure3d::scenegraph::TransformNode *r);
};

class FcPvis : public FcBase {
public:
    FcPvis *FUN_002a80c0();
    void FUN_002a8310(void *r);
};

class FcSvis : public FcBase {
public:
    FcSvis *FUN_002a7b90();
    void FUN_002a7cf0(pure3d::scenegraph::VisibilityNode *r);
};

class FcTrvp : public FcBase {
public:
    FcTrvp *FUN_002a5420();
    void FUN_002a6930(void *r);
};

class FcVrtx : public FcBase {
public:
    FcVrtx *FUN_002a6cb0();
    void FUN_002a6ed0(void *r);
};

class FcParticle : public FcBase {
public:
    FcParticle *FUN_002a73d0();
    void FUN_002a75a0(void *r);
};

void *__cdecl FUN_00286750(Inv *inv, char *name);
void *__cdecl FUN_000f23a0(Inv *inv, char *name);
void *__cdecl FUN_000f2340(Inv *inv, char *name);
void *__cdecl FUN_000c0db0(Inv *inv, char *name);
void *__cdecl FUN_000c0db0(Inv *inv, char *name);
void *__cdecl FUN_00286780(Inv *inv, char *name);
void *__cdecl FUN_000f23d0(Inv *inv, char *name);
void *__cdecl FUN_000c0d80(Inv *inv, char *name);
void *__cdecl FUN_000f23d0(Inv *inv, char *name);
void *__cdecl FUN_000c9ba0(Inv *inv, char *name);

extern "C" void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);


#define FC_INIT(T, SZ, CTOR)                                  \
    T *obj;                                                   \
    {                                                         \
        void *m_ = thunk_FUN_0008d690(SZ);                    \
        if (m_)                                               \
            obj = ((T *)m_)->CTOR();                          \
        else                                                  \
            obj = 0;                                          \
    }                                                         \
    obj->name.FUN_0027b040(arg1);                             \
    obj->v24(anim, 0, 0);                                     \
    obj->v16(mode);                                           \
    obj->v18(ebx);


class Handler {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    FcBase *FUN_002867b0(const char *arg1, unsigned int type, unsigned int ver, Reader *R, Inv *inv);
};

FcBase *Handler::FUN_002867b0(const char *arg1, unsigned int type, unsigned int ver, Reader *R, Inv *inv)
{
    struct Frame {
        union {
            unsigned int tag;
            int mode;
        } u;
        unsigned char pad4[3];
        unsigned char len;
        union {
            float ff;
            int ebx;
            int fl;
        } t;
        char buf1[0x100];
        char buf2[0x100];
    } f;
    unsigned int &tag = f.u.tag;
    int &mode = f.u.mode;
    unsigned char &len = f.len;
    char *buf1 = f.buf1;
    char *buf2 = f.buf2;
    float &ff = f.t.ff;
    int &fl = f.t.fl;
    int ebx;
    int &ebxs = f.t.ebx;
    R->stream->FUN_002647e0(&tag, 1, 4, 1);
    if (tag == 0x444c4f48)
        mode = 1;
    else if (tag == 0x445746)
        mode = 2;
    else if (tag == 0x44464b42)
        mode = 5;
    else if (tag == 0x4b424446)
        mode = 4;
    else if (tag == 0x4b434142)
        mode = 3;
    else
        mode = 0;
    if (ver < 1) {
        R->stream->FUN_002647e0(&ff, 1, 4, 1);
        ebx = (int)ff;
    } else {
        R->stream->FUN_002647e0(&ebxs, 1, 4, 1);
        ebx = ebxs;
    }
    R->stream->FUN_002647e0(&fl, 1, 4, 1);
    if (fl != 0)
        ebx = 0;
    R->stream->FUN_002647e0(&len, 1, 1, 1);
    unsigned int n1 = len;
    R->stream->FUN_002647e0(buf1, n1, 1, 1);
    buf1[n1] = 0;
    R->stream->FUN_002647e0(&len, 1, 1, 1);
    unsigned int n2 = len;
    R->stream->FUN_002647e0(buf2, n2, 1, 1);
    buf2[n2] = 0;
    Cast2 *anim = 0;
    if (type != 0x53595350 && type != 0x584645) {
        content::LoadInventory::DynamicCaster<pure3d::Animation> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        unsigned __int64 key = FUN_0027b020(buf2);
        anim = inv->i3(&c, key);
    }

    if (type == 0x53595350 || type == 0x584645) {
        FcParticle *obj;
        void *m_ = thunk_FUN_0008d690(0x60);
        if (m_)
            obj = ((FcParticle *)m_)->FUN_002a73d0();
        else
            obj = 0;
        obj->name.FUN_0027b040(arg1);
        obj->v16(mode);
        obj->v18(ebx);
        content::LoadInventory::DynamicCaster<pure3d::ParticleSystem> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::ParticleSystem>;
        unsigned __int64 key = FUN_0027b020(buf1);
        Cast2 *o = inv->i3(&c, key);
        if (!o)
            return obj;
        obj->FUN_002a75a0(o);
        return obj;
    }
    if (type == 0x505845) {
        FC_INIT(FcExp, 0x50, FUN_002a9cb0)
        void *r = FUN_00286750(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a9ea0(r);
        return obj;
    }
    if (type == 0x4d4143) {
        FC_INIT(FcMac, 0x118, FUN_00292eb0)
        void *r = FUN_000f23a0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_00293100(r);
        return obj;
    }
    if (type == 0x475142) {
        FC_INIT(FcBqg, 0x48, FUN_002a9760)
        TaPair *r = (TaPair *)FUN_000f2340(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a98f0(**(void ***)((char *)r + 0x48));
        return obj;
    }
    if (type == 0x584554) {
        FC_INIT(FcTex, 0x48, FUN_002a9410)
        void *r = FUN_000c0db0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a9540(r);
        return obj;
    }
    if (type == 0x44414853) {
        FC_INIT(FcShad, 0x48, FUN_002a83e0)
        void *r = FUN_000c0db0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a8650(r);
        return obj;
    }
    if (type == 0x4554494c) {
        FC_INIT(FcLite, 0x118, FUN_002a87c0)
        void *r = FUN_00286780(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a8aa0(r);
        return obj;
    }
    if (type == 0x4e525450) {
        FC_INIT(FcPtrn, 0x150, FUN_00287860)
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
        unsigned __int64 key = FUN_0027b020(buf1);
        Cast2 *o = inv->i3(&c, key);
        if (!o)
            return obj;
        obj->FUN_00288080(o->c11());
        return obj;
    }
    if (type == 0x53495653) {
        FC_INIT(FcSvis, 0x48, FUN_002a7b90)
        Res *r = (Res *)FUN_000f23d0(inv, buf1);
        if (!r)
            return obj;
        TaPair *ta = anim->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = r->FUN_002961e0(ta->f8, ta->fc, 4, 0);
        obj->FUN_002a7cf0(dynamic_cast<pure3d::scenegraph::VisibilityNode *>(nd));
        return obj;
    }
    if (type == 0x53495650) {
        FC_INIT(FcPvis, 0x60, FUN_002a80c0)
        void *r = FUN_000c0d80(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a8310(r);
        return obj;
    }
    if (type == 0x4e525453) {
        FC_INIT(FcStrn, 0x118, FUN_002a7730)
        Res *r = (Res *)FUN_000f23d0(inv, buf1);
        if (!r)
            return obj;
        TaPair *ta = anim->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = r->FUN_002961e0(ta->f8, ta->fc, 2, 0);
        obj->FUN_002a77c0(dynamic_cast<pure3d::scenegraph::TransformNode *>(nd));
        return obj;
    }
    if (type == 0x54525650) {
        FC_INIT(FcTrvp, 0x58, FUN_002a5420)
        content::LoadInventory::DynamicCaster<pure3d::Geometry> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::Geometry>;
        unsigned __int64 key = FUN_0027b020(buf1);
        Cast2 *o = inv->i3(&c, key);
        if (!o)
            return obj;
        obj->FUN_002a6930(o);
        return obj;
    }
    if (type == 0x58545256) {
        FC_INIT(FcVrtx, 0x48, FUN_002a6cb0)
        void *r = FUN_000c9ba0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a6ed0(r);
        return obj;
    }
    return 0;
}
