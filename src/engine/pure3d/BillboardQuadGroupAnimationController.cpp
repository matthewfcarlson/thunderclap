// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a9760..0x002a9cb0 (kind game, layer engine, confidence high), dominant class pure3d::BillboardQuadGroupAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fbb1b687 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fbb1b687 {} using namespace fn_fbb1b687;
#include "engine/pure3d.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fbb1b687 {
extern "C" void __fastcall FUN_00284cd0(void*);
class BillboardQuadGroupAnimationController_2a9760 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    BillboardQuadGroupAnimationController_2a9760();
};
extern "C" char DAT_00475142[];
extern void* hulk_at_0042dedc[];
class Ref_2a98c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a98c0 {
  public:
    void* vptr;
    void Fin_00285800();
};
class BillboardQuadGroupAnimationController_2a98c0 : public SimpleFrameController_2a98c0 {
  public:
    char pad[60];
    Ref_2a98c0* m;
    ~BillboardQuadGroupAnimationController_2a98c0();
};
class Obj_2a98f0 {
  public:
    virtual void f();
    virtual void g();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Obj_2a98f0* mObj;
    void vfunc_8(Obj_2a98f0* p);
};
struct Vec3_2a9920 { float x, y, z; };
union Scalar_2a9920 {
    float f;
    int i;
    unsigned int u;
};
class Channel_2a9920 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void sampleVec3(float frame, Vec3_2a9920 *out);
    virtual void sampleRot(float frame, Vec3_2a9920 *out);
    void FUN_0028ac90(float frame, unsigned char *out);
    void FUN_0028a2c0(float frame, int *out);
};
struct ChannelSet_2a9920 {
    Channel_2a9920 *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};
struct Transform_2a9920 {
    void FUN_0022ba20(Vec3_2a9920 *v);
};
struct Billboard_2a9920 {
    char pad00[8];
    int key0;
    int key1;
    char pad10[0x28];
    unsigned char visible;
    char pad39[3];
    int color;
    Transform_2a9920 xform;
    char pad41[0x80 - 0x40 - sizeof(Transform_2a9920)];
    float width;
    float height;
    Scalar_2a9920 dist;
    char pad8c[0xb8 - 0x8c];
    int off0;
    int off1;
    unsigned int limit;
    unsigned int cur;
};
struct ItemList_2a9920 {
    char pad[0x8c];
    Billboard_2a9920 **begin;
    Billboard_2a9920 **end;
};
struct Resolver_2a9920 {
    ChannelSet_2a9920 *FUN_00288ad0(int key0, int key1);
};
extern void* g_vftable_2a9b80[];
} // namespace fn_fbb1b687
void operator delete(void*);
namespace fn_fbb1b687 {
class Ref_2a9b80 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a9b80 {
  public:
    void* vptr;
    void Fin_00285800();
};
class BillboardQuadGroupAnimationController_2a9b80 : public SimpleFrameController_2a9b80 {
  public:
    char pad[0x40 - 4];
    Ref_2a9b80* m;
    BillboardQuadGroupAnimationController_2a9b80* f2(unsigned char flags);
};
struct BillboardQuadGroupAnimationController_nv_2a9c00 {
    void initialize_00285780(pure3d::BillboardQuadGroupAnimationController*);
};
extern "C" int BQVtable;
extern "C" void* __cdecl alloc(hulk_uintptr);
typedef unsigned int u32_2a9c50;
struct Obj_2a9c50 {
    virtual void f0();
};
struct Ent_2a9c50 {
    virtual void a();
    virtual void b();
};
extern int hulk_at_0048f610, hulk_at_004cfaa4;


// 0x002a9760 FUN_002a9760 (25 B): matches/0x002a9760.cpp
// sym: ??0BillboardQuadGroupAnimationController_2a9760@fn_fbb1b687@@QAE@XZ
// Same code shape as 0x002960e0 (propagated; names are from that function)
BillboardQuadGroupAnimationController_2a9760::BillboardQuadGroupAnimationController_2a9760() {
    FUN_00284cd0((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}

} // namespace fn_fbb1b687

// 0x002a9780 pure3d::BillboardQuadGroupAnimationController::vfunc_3 (3 B): matches/0x002a9780.cpp
// sym: ?vfunc_3@BillboardQuadGroupAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::BillboardQuadGroupAnimationController::vfunc_3() {
    return true;
}


// 0x002a9790 pure3d::BillboardQuadGroupAnimationController::vfunc_26 (32 B): matches/0x002a9790.cpp
// sym: ?vfunc_26@BillboardQuadGroupAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::BillboardQuadGroupAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p) {
        unsigned int x = *(unsigned int*)((char*)p + 0x1c);
        int r = (x == ((int)0x475142));
        return r != 0;
    }
    return false;
}

namespace fn_fbb1b687 {

// 0x002a98c0 FUN_002a98c0 (36 B): matches/0x002a98c0.cpp
// sym: ??1BillboardQuadGroupAnimationController_2a98c0@fn_fbb1b687@@QAE@XZ
BillboardQuadGroupAnimationController_2a98c0::~BillboardQuadGroupAnimationController_2a98c0() {
    vptr = hulk_at_0042dedc;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285800();
}


// 0x002a98f0 FUN_002a98f0 (38 B): matches/0x002a98f0.cpp
// sym: ?vfunc_8@CMotionTrail@fn_fbb1b687@@QAEXPAVObj_2a98f0@2@@Z
// Same code shape as 0x002830e0 (propagated; names are from that function)
void CMotionTrail::vfunc_8(Obj_2a98f0* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}

} // namespace fn_fbb1b687

// 0x002a9920 pure3d::BillboardQuadGroupAnimationController::vfunc_7 (604 B): equivalent/0x002a9920.cpp
// sym: ?vfunc_7@BillboardQuadGroupAnimationController@pure3d@@UAEXXZ @ff20e2e7e088 @wc76f4d0ff55e
// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 29/30, incomplete)
// pure3d::BillboardQuadGroupAnimationController::vfunc_7 @ 0x002a9920
void pure3d::BillboardQuadGroupAnimationController::vfunc_7() {
    struct Frame {
        char pad[3];
        unsigned char b;
        Scalar_2a9920 a;
        float f2;
        int i3;
        int i4;
        unsigned int u5;
        int pair[2];
        Vec3_2a9920 v1;
        Vec3_2a9920 v2;
        int xpad[8];
    } fr;
    unsigned int i;

    for (i = 0; i < (unsigned int)((*(ItemList_2a9920 * *)&this->f_40)->end - (*(ItemList_2a9920 * *)&this->f_40)->begin); i++) {
        if (i >= (unsigned int)((*(ItemList_2a9920 * *)&this->f_40)->end - (*(ItemList_2a9920 * *)&this->f_40)->begin))
            continue;
        Billboard_2a9920 *item = (*(ItemList_2a9920 * *)&this->f_40)->begin[i];
        if (item == 0)
            continue;
        ChannelSet_2a9920 *cs = (*(Resolver_2a9920 * *)&this->f_3c)->FUN_00288ad0(item->key0, item->key1);
        if (cs == 0)
            continue;

        Channel_2a9920 *c = cs->FUN_00288960(0x534956, 0x4c4f4f42);
        if (c != 0) {
            c->FUN_0028ac90(this->f_34, &fr.b);
            item->visible = fr.b;
        }
        c = cs->FUN_00288960(0x4e415254, 0x54434556);
        if (c != 0) {
            c->sampleVec3(this->f_34, &fr.v1);
            ((owners::Target_22be40 *)&(item->xform))->FUN_0022be40((const int *)(Vec3_2a9920 *)(&fr.v1));
        }
        c = cs->FUN_00288960(0x544f52, 0x544f52);
        if (c != 0) {
            c->sampleRot(this->f_34, &fr.v2);
            item->xform.FUN_0022ba20(&fr.v2);
        }
        c = cs->FUN_00288960(0x544457, 0x31544c46);
        if (c != 0) {
            ((owners::Curve_28a1c0 *)c)->FUN_0028a1c0(this->f_34, (float *)(Scalar_2a9920 *)(&fr.a));
            item->width = fr.a.f * 0.5f;
        }
        c = cs->FUN_00288960(0x544748, 0x31544c46);
        if (c != 0) {
            ((owners::Curve_28a1c0 *)c)->FUN_0028a1c0(this->f_34, (float *)(Scalar_2a9920 *)((Scalar_2a9920 *)&fr.f2));
            item->height = fr.f2 * 0.5f;
        }
        c = cs->FUN_00288960(0x54534944, 0x31544c46);
        if (c != 0) {
            ((owners::Curve_28a1c0 *)c)->FUN_0028a1c0(this->f_34, (float *)(Scalar_2a9920 *)((Scalar_2a9920 *)&fr.i3));
            item->dist.i = fr.i3;
        }
        c = cs->FUN_00288960(0x524c43, 0x524c43);
        if (c != 0) {
            ((owners::Track_28ad20 *)c)->FUN_0028ad20(this->f_34, (unsigned int *)(&fr.i4));
            item->color = fr.i4;
        }
        c = cs->FUN_00288960(0x465346, 0x544e49);
        if (c != 0) {
            ((owners::Track_28a0b0 *)c)->FUN_0028a0b0(this->f_34, (int *)(&fr.u5));
            unsigned int lim = item->cur;
            if (fr.u5 <= lim)
                lim = fr.u5;
            item->limit = lim;
        }
        c = cs->FUN_00288960(0x46464f, 0x32544c46);
        if (c != 0) {
            c->FUN_0028a2c0(this->f_34, fr.pair);
            item->off0 = fr.pair[0];
            item->off1 = fr.pair[1];
        }
    }
}

namespace fn_fbb1b687 {

// 0x002a9b80 pure3d::BillboardQuadGroupAnimationController::vfunc_2 (57 B): matches/0x002a9b80.cpp
// sym: ?f2@BillboardQuadGroupAnimationController_2a9b80@fn_fbb1b687@@QAEPAV12@E@Z
BillboardQuadGroupAnimationController_2a9b80* BillboardQuadGroupAnimationController_2a9b80::f2(unsigned char flags) {
    vptr = g_vftable_2a9b80;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285800();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fbb1b687

// 0x002a9c00 pure3d::BillboardQuadGroupAnimationController::vfunc_4 (79 B): matches/0x002a9c00.cpp
// sym: ?vfunc_4@BillboardQuadGroupAnimationController@pure3d@@UAEPAXXZ
void* pure3d::BillboardQuadGroupAnimationController::vfunc_4() {
    pure3d::BillboardQuadGroupAnimationController* p = (pure3d::BillboardQuadGroupAnimationController*)alloc(0x48);
    if (p) {
        ((BillboardQuadGroupAnimationController_nv_2a9c00*)(p))->initialize_00285780(this);
        *(hulk_intptr*)p = (hulk_intptr)&BQVtable;
        int* z = (int*)((char*)p + 0x40);
        *z = 0;
        pure3d::BillboardQuadGroupAnimationController* q = (*(pure3d::BillboardQuadGroupAnimationController * *)&this->f_40);
        if (q)
            q->vfunc_0();
        pure3d::BillboardQuadGroupAnimationController* old = (*(pure3d::BillboardQuadGroupAnimationController * *)&p->f_40);
        if (old)
            old->vfunc_1();
        (*(pure3d::BillboardQuadGroupAnimationController * *)&p->f_40) = q;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x002a9c50 pure3d::BillboardQuadGroupAnimationController::vfunc_5 (63 B): matches/0x002a9c50.cpp
// sym: ?vfunc_5@BillboardQuadGroupAnimationController@pure3d@@UAEXPAX@Z
void pure3d::BillboardQuadGroupAnimationController::vfunc_5(void* __p0) { Obj_2a9c50 * p = (Obj_2a9c50 *)__p0;

    Obj_2a9c50* x = ((Obj_2a9c50 *)__RTDynamicCast(p, 0, (void*)(&hulk_at_0048f610), (void*)(&hulk_at_004cfaa4), 0));
    if (x)
        x->f0();
    if ((*(Ent_2a9c50 * *)&this->f_40))
        (*(Ent_2a9c50 * *)&this->f_40)->b();
    (*(Ent_2a9c50 * *)&this->f_40) = (Ent_2a9c50*)x;
}

