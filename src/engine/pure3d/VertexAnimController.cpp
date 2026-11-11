// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a6cb0..0x002a6fb0 (kind game, layer engine, confidence high), dominant class pure3d::VertexAnimController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f729aa84 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f729aa84 {} using namespace fn_f729aa84;
#include "engine/pure3d.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f729aa84 {
extern "C" void __fastcall FUN_00284cd0(void*);
class VertexAnimController_2a6cb0 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    VertexAnimController_2a6cb0();
};
struct Track_2a6d10;
struct Channel_2a6d10 {
    Track_2a6d10* FUN_00288960(unsigned int, unsigned int);
};
struct Animation_2a6d10 {
};
struct Track_2a6d10 {
    int unused;
    int count;
};
struct Geometry_2a6d10 {
    void FUN_002d0d20(void*, int);
    void FUN_002d0da0(void*, float, int);
};
extern void* hulk_at_0042da6c[];
class Ref_2a6e50 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a6e50 {
  public:
    void* vptr;
    void Fin_00285800();
};
class VertexAnimController_2a6e50 : public SimpleFrameController_2a6e50 {
  public:
    char pad[60];
    Ref_2a6e50* m;
    ~VertexAnimController_2a6e50();
};
extern "C" char DAT_0042da6c[];
void* __cdecl alloc_00263ea0(hulk_uintptr);
class Base_2a6e80 {
  public:
    void init_00285780(pure3d::VertexAnimController*);
};
class Helper_2a6e80 {
  public:
    virtual void release();
    virtual void destroy();
};
class A_2a6ed0 {
  public:
    virtual void f();
};
class B_2a6ed0 {
  public:
    virtual void f();
    virtual void g();
};
class C_2a6ed0 {
    char pad[0x40];
    B_2a6ed0* m;

  public:
    void set(A_2a6ed0*);
};
class D {
  public:
    char pad[0x5c];
    A_2a6ed0* m;
};
extern void* g_vftable_2a6f00[];
} // namespace fn_f729aa84
void operator delete(void*);
namespace fn_f729aa84 {
class Ref_2a6f00 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a6f00 {
  public:
    void* vptr;
    void Fin_00285800();
};
class VertexAnimController_2a6f00 : public SimpleFrameController_2a6f00 {
  public:
    char pad[60];
    Ref_2a6f00* m;
    VertexAnimController_2a6f00* f2(unsigned char flags);
};
typedef unsigned int u32_2a6f40;
typedef unsigned int Type;
struct R_2a6f40 {
    virtual void f0();
    virtual void f1();
};
extern Type hulk_at_0048f610;
extern Type hulk_at_0049fc80;


// 0x002a6cb0 FUN_002a6cb0 (25 B): matches/0x002a6cb0.cpp
// sym: ??0VertexAnimController_2a6cb0@fn_f729aa84@@QAE@XZ
// Same code shape as 0x002960e0 (propagated; names are from that function)
VertexAnimController_2a6cb0::VertexAnimController_2a6cb0() {
    FUN_00284cd0((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}

} // namespace fn_f729aa84

// 0x002a6cd0 pure3d::VertexAnimController::vfunc_3 (3 B): matches/0x002a6cd0.cpp
// sym: ?vfunc_3@VertexAnimController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::VertexAnimController::vfunc_3() {
    return true;
}


// 0x002a6ce0 pure3d::VertexAnimController::vfunc_26 (39 B): matches/0x002a6ce0.cpp
// sym: ?vfunc_26@VertexAnimController@pure3d@@UAE_NPAX@Z
bool pure3d::VertexAnimController::vfunc_26(void* __p0) { hulk_intptr p = (hulk_intptr)__p0;

    if (p && *(int*)(p + 0x28) > 0)
        return *(int*)(p + 0x1c) == 0x58545256;
    return false;
}


// 0x002a6d10 pure3d::VertexAnimController::vfunc_7 (170 B): matches/0x002a6d10.cpp
// sym: ?vfunc_7@VertexAnimController@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::VertexAnimController::vfunc_7() {
    Track_2a6d10* track = ((Channel_2a6d10 *)((owners::Target_288a10 *)((*(Animation_2a6d10 * *)&this->f_3c)))->FUN_00288a10(0))->FUN_00288960(0x58545256, 0x544e49);
    if (track) {
        int first, second;
        float firstTime, secondTime;
        void* firstData;
        void* secondData;
        ((owners::Table_289f80 *)track)->FUN_00289f80(this->f_34, &first, &second);
        ((owners::X_28a080 *)track)->FUN_0028a080(first, &firstTime, (int *)(&firstData));
        (*(Geometry_2a6d10 * *)&this->f_40)->FUN_002d0d20(firstData, 1);
        if (first != second) {
            ((owners::X_28a080 *)track)->FUN_0028a080(second, &secondTime, (int *)(&secondData));
            (*(Geometry_2a6d10 * *)&this->f_40)->FUN_002d0da0(secondData, (this->f_34 - firstTime) / (secondTime - firstTime), track->count);
        }
    }
}

namespace fn_f729aa84 {

// 0x002a6e50 FUN_002a6e50 (36 B): matches/0x002a6e50.cpp
// sym: ??1VertexAnimController_2a6e50@fn_f729aa84@@QAE@XZ
VertexAnimController_2a6e50::~VertexAnimController_2a6e50() {
    vptr = hulk_at_0042da6c;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285800();
}

} // namespace fn_f729aa84

// 0x002a6e80 pure3d::VertexAnimController::vfunc_4 (79 B): matches/0x002a6e80.cpp
// sym: ?vfunc_4@VertexAnimController@pure3d@@UAEPAXXZ
void* pure3d::VertexAnimController::vfunc_4() {
    pure3d::VertexAnimController* p = (pure3d::VertexAnimController*)alloc_00263ea0(0x48);
    if (p) {
        ((Base_2a6e80*)p)->init_00285780(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042da6c);
        (*(Helper_2a6e80 * *)&p->f_40) = 0;
        Helper_2a6e80* old = (*(Helper_2a6e80 * *)&this->f_40);
        if (old)
            old->release();
        Helper_2a6e80* cur = (*(Helper_2a6e80 * *)&p->f_40);
        if (cur)
            cur->destroy();
        (*(Helper_2a6e80 * *)&p->f_40) = old;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f729aa84 {

// 0x002a6ed0 FUN_002a6ed0 (41 B): matches/0x002a6ed0.cpp
// sym: ?set@C_2a6ed0@fn_f729aa84@@QAEXPAVA_2a6ed0@2@@Z
void C_2a6ed0::set(A_2a6ed0* p) {
    A_2a6ed0* n = ((D*)p)->m;
    if (n)
        n->f();
    if (m)
        m->g();
    m = (B_2a6ed0*)n;
}


// 0x002a6f00 pure3d::VertexAnimController::vfunc_2 (57 B): matches/0x002a6f00.cpp
// sym: ?f2@VertexAnimController_2a6f00@fn_f729aa84@@QAEPAV12@E@Z
VertexAnimController_2a6f00* VertexAnimController_2a6f00::f2(unsigned char flags) {
    vptr = g_vftable_2a6f00;
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

} // namespace fn_f729aa84

// 0x002a6f40 pure3d::VertexAnimController::vfunc_5 (64 B): matches/0x002a6f40.cpp
// sym: ?vfunc_5@VertexAnimController@pure3d@@UAEXPAX@Z
void pure3d::VertexAnimController::vfunc_5(void* __p0) { hulk_uintptr p = (hulk_uintptr)__p0;

    R_2a6f40* r = ((R_2a6f40 *)__RTDynamicCast((void*)(p), 0, (void*)(&hulk_at_0048f610), (void*)(&hulk_at_0049fc80), 0));
    R_2a6f40* n = *(R_2a6f40**)((char*)r + 0x5c);
    if (n)
        n->f0();
    if ((*(R_2a6f40 * *)&this->f_40))
        (*(R_2a6f40 * *)&this->f_40)->f1();
    (*(R_2a6f40 * *)&this->f_40) = n;
}

