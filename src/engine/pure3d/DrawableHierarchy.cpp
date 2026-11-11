// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a34c0..0x002a3660 (kind game, layer engine, confidence high), dominant class pure3d::DrawableHierarchy
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fbc2d490 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fbc2d490 {} using namespace fn_fbc2d490;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fbc2d490 {
struct Sub_2a3530 {
    void Copy(const Sub_2a3530* o);
    char p[8];
};
struct Entity_2a3530 {
    Entity_2a3530();
    virtual void f0();
    int b4;
    Sub_2a3530 s;
};
struct DrawableHierarchy_2a3530 : Entity_2a3530 {
    DrawableHierarchy_2a3530(const DrawableHierarchy_2a3530& o);
    virtual void f1();
    int m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38;
};
class Item_2a35a0 {
  public:
    virtual void First();
    virtual void Second();
};
class Obj_2a35d0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern void* g_vftable_2a35f0[];
class Ref_2a35f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2a35f0 {
  public:
    void* vptr;
    void Fin();
};
class DrawableHierarchy_2a35f0 : public Entity_2a35f0 {
  public:
    char pad[12];
    Ref_2a35f0* m;
    ~DrawableHierarchy_2a35f0();
};
extern void* g_vftable_2a3620[];
} // namespace fn_fbc2d490
void operator delete(void*);
namespace fn_fbc2d490 {
class Ref_2a3620 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2a3620 {
  public:
    void* vptr;
    void Fin();
};
class DrawableHierarchy_2a3620 : public Entity_2a3620 {
  public:
    char pad[12];
    Ref_2a3620* m;
    DrawableHierarchy_2a3620* f2(unsigned char flags);
};

} // namespace fn_fbc2d490

// 0x002a34c0 pure3d::DrawableHierarchy::vfunc_10 (3 B): matches/0x002a34c0.cpp
// sym: ?vfunc_10@DrawableHierarchy@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::DrawableHierarchy::vfunc_10(hulk_intptr a) {
    (void)a;
}

namespace fn_fbc2d490 {

// 0x002a34d0 pure3d::DrawableHierarchy::vfunc_11 (3 B): matches/0x002a34d0.cpp
// sym: ?GetZero@fn_fbc2d490@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x002a3530 FUN_002a3530 (105 B): matches/0x002a3530.cpp
// sym: ??0DrawableHierarchy_2a3530@fn_fbc2d490@@QAE@ABU01@@Z
DrawableHierarchy_2a3530::DrawableHierarchy_2a3530(const DrawableHierarchy_2a3530& o) {
    m10 = 0;
    s.Copy(&o.s);
    m14 = o.m14;
    m18 = o.m18;
    m1c = o.m1c;
    m20 = o.m20;
    m24 = o.m24;
    m28 = o.m28;
    m2c = o.m2c;
    m30 = o.m30;
    m34 = o.m34;
    m38 = o.m38;
}

} // namespace fn_fbc2d490

// 0x002a35a0 pure3d::DrawableHierarchy::vfunc_13 (38 B): matches/0x002a35a0.cpp
// sym: ?vfunc_13@DrawableHierarchy@pure3d@@UAEXPAX@Z
// Same code shape as 0x00059790 (propagated; names are from that function)
void pure3d::DrawableHierarchy::vfunc_13(void* __p0) { Item_2a35a0 * p = (Item_2a35a0 *)__p0;

    if (p)
        p->First();
    if ((*(Item_2a35a0 * *)&this->f_10))
        (*(Item_2a35a0 * *)&this->f_10)->Second();
    (*(Item_2a35a0 * *)&this->f_10) = p;
}


// 0x002a35d0 pure3d::DrawableHierarchy::vfunc_14 (24 B): matches/0x002a35d0.cpp
// sym: ?vfunc_14@DrawableHierarchy@pure3d@@UAEXXZ
void pure3d::DrawableHierarchy::vfunc_14() {
    if ((*(Obj_2a35d0 * *)&this->f_10)) {
        (*(Obj_2a35d0 * *)&this->f_10)->f1();
        (*(Obj_2a35d0 * *)&this->f_10) = 0;
    }
}

namespace fn_fbc2d490 {

// 0x002a35f0 FUN_002a35f0 (36 B): matches/0x002a35f0.cpp
// sym: ??1DrawableHierarchy_2a35f0@fn_fbc2d490@@QAE@XZ
DrawableHierarchy_2a35f0::~DrawableHierarchy_2a35f0() {
    vptr = g_vftable_2a35f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}


// 0x002a3620 pure3d::DrawableHierarchy::vfunc_2 (57 B): matches/0x002a3620.cpp
// sym: ?f2@DrawableHierarchy_2a3620@fn_fbc2d490@@QAEPAV12@E@Z
DrawableHierarchy_2a3620* DrawableHierarchy_2a3620::f2(unsigned char flags) {
    vptr = g_vftable_2a3620;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fbc2d490
