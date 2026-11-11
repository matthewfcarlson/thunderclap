// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00306ef0..0x00307030 (kind game, layer engine, confidence high), dominant class physics::CollisionRay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f163d5a2 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f163d5a2 {} using namespace fn_f163d5a2;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f163d5a2 {
struct Vec3_306ef0 {
    float x, y, z;
};
class CollisionVolume_306ef0 {
  public:
    virtual void BaseFn_00018b30();
    char m_pad[0x64];
    CollisionVolume_306ef0();
};
class CollisionRay : public CollisionVolume_306ef0 {
  public:
    virtual void RayFn_00018b40();
    Vec3_306ef0 m_a; // 0x68
    Vec3_306ef0 m_b; // 0x74
    int m_c;  // 0x80
    CollisionRay(const Vec3_306ef0* a, const Vec3_306ef0* b, int c);
};
class CollisionVolume_306f70 {
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
    virtual void* vfunc_16();
    virtual void v17();
    virtual void v18();
};
class CollisionVolume_306f80 {
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
    virtual void* vfunc_16();
    virtual void v17();
    virtual void v18();
};
void __fastcall FUN_00306ac0(CEffectStopTrack*);
class Helper_306fd0 {
  public:
};
extern void* hulk_at_00431bec[];
class CollisionVolume_307000 {
  public:
    void Destroy_00306ac0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionRay_307000 : public CollisionVolume_307000 {
  public:
    CollisionRay_307000* vfunc_5(signed char flags);
};


// 0x00306ef0 FUN_00306ef0 (72 B): matches/0x00306ef0.cpp
// sym: ??0CollisionRay@fn_f163d5a2@@QAE@PBUVec3_306ef0@1@0H@Z
CollisionRay::CollisionRay(const Vec3_306ef0* a, const Vec3_306ef0* b, int c) {
    m_a.x = a->x;
    m_a.y = a->y;
    m_a.z = a->z;
    m_b.x = b->x;
    m_b.y = b->y;
    m_b.z = b->z;
    m_c = c;
}

} // namespace fn_f163d5a2

// 0x00306f40 physics::CollisionRay::vfunc_6 (6 B): matches/0x00306f40.cpp
// sym: ?vfunc_6@CollisionRay@physics@@UAEHXZ
// Same code shape as 0x0004df30 (propagated; names are from that function)
int physics::CollisionRay::vfunc_6() {
    return 6;
}


// 0x00306f50 physics::CollisionRay::vfunc_4 (4 B): matches/0x00306f50.cpp
// sym: ?vfunc_4@CollisionRay@physics@@UAEHXZ
// Same code shape as 0x00091d50 (propagated; names are from that function)
hulk_intptr physics::CollisionRay::vfunc_4() {
    return (hulk_intptr)((physics::CollisionRay*)((char*)this + 0x68));
}


// 0x00306f60 physics::CollisionRay::vfunc_3 (4 B): matches/0x00306f60.cpp
// sym: ?vfunc_3@CollisionRay@physics@@UAEHXZ
// Same code shape as 0x00091d50 (propagated; names are from that function)
hulk_intptr physics::CollisionRay::vfunc_3() {
    return (hulk_intptr)((physics::CollisionRay*)((char*)this + 0x68));
}


// 0x00306f70 physics::CollisionRay::vfunc_16 (4 B): matches/0x00306f70.cpp
// sym: ?vfunc_16@CollisionRay@physics@@UAEPAXXZ
void* physics::CollisionRay::vfunc_16() {
    return (void*)((char*)this + 0x74);
}


// 0x00306f80 physics::CollisionRay::vfunc_15 (4 B): matches/0x00306f80.cpp
// sym: ?vfunc_15@CollisionRay@physics@@UAEPAXXZ
// Same code shape as 0x00306f70 (propagated; names are from that function)
void* physics::CollisionRay::vfunc_15() {
    return (void*)((char*)this + 0x74);
}


// 0x00306f90 physics::CollisionRay::vfunc_17 (7 B): matches/0x00306f90.cpp
// sym: ?vfunc_17@CollisionRay@physics@@UAEMXZ
 // namespace physics
hulk_freg physics::CollisionRay::vfunc_17() {
    return this->f_80;
}


// 0x00306fa0 physics::CollisionRay::vfunc_18 (13 B): matches/0x00306fa0.cpp
// sym: ?vfunc_18@CollisionRay@physics@@UAEXI@Z
 // namespace physics
void physics::CollisionRay::vfunc_18(unsigned int value) {
    *(unsigned int*)((char*)this + 0x80) = value;
}

namespace fn_f163d5a2 {

// 0x00306fb0 FUN_00306fb0 (11 B): matches/0x00306fb0.cpp
// sym: ?FUN_00306fb0@fn_f163d5a2@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_00306fb0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_00306ac0(self);
}

} // namespace fn_f163d5a2

// 0x00306fc0 physics::CollisionRay::vfunc_5 (3 B): matches/0x00306fc0.cpp
// sym: ?vfunc_5@CollisionRay@physics@@UAEXHH@Z
void physics::CollisionRay::vfunc_5(int a, int b) {}


// 0x00306fd0 physics::CollisionRay::vfunc_11 (46 B): matches/0x00306fd0.cpp
// sym: ?vfunc_11@CollisionRay@physics@@UAEXPAX@Z
void physics::CollisionRay::vfunc_11(void* __p0) { Helper_306fd0 * h = (Helper_306fd0 *)__p0;

    hulk_intptr a = vfunc_4();
    ((owners::Mat_22c2b0 *)h)->FUN_0022c2b0((float *)(hulk_uintptr)(hulk_intptr)(vfunc_4()), (float *)(hulk_uintptr)(hulk_intptr)a);
    ((owners::M_22c3b0 *)h)->FUN_0022c3b0((float *)((char*)this + 0x74), (float *)((char*)this + 0x74));
}

namespace fn_f163d5a2 {

// 0x00307000 physics::CollisionRay::vfunc_2 (36 B): matches/0x00307000.cpp
// sym: ?vfunc_5@CollisionRay_307000@fn_f163d5a2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionRay_307000* CollisionRay_307000::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00431bec;
    Destroy_00306ac0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f163d5a2
