// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bac0..0x0018bb70 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMissileCountCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdbc4aa5 {
#define TREE_TU_END }
namespace fn_fdbc4aa5 {} using namespace fn_fdbc4aa5;
namespace fn_fdbc4aa5 { extern "C" char DAT_0041924c[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fdbc4aa5 {
class TrackFactoryTemplate_18bac0 {
  public:
    TrackFactoryTemplate_18bac0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187bb0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Condition_18bb00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init_00234590(int);
    int x;
    int y;
    int z;
    int w;
    int q;
};
extern int hulk_at_0041a72c;
struct ConditionFactoryTemplate_18bb40 {
    void* m_vptr;
    void base1_dtor_001809b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fdbc4aa5

// 0x0018bac0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_1 (60 B): matches/0x0018bac0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bac0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18bac0* t = new (mem) TrackFactoryTemplate_18bac0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187bb0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bb00 fight::ConditionFactoryTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_5 (61 B): matches/0x0018bb00.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_5() {
    Condition_18bb00* p = (Condition_18bb00*)FUN_0008d690((int)sizeof(Condition_18bb00));
    void* result;
    if (p) {
        p->Init_00234590(0);
        *(int**)p = ((int*)DAT_0041924c);
        p->z = 0;
        p->w = 0;
        p->q = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}

namespace fn_fdbc4aa5 {

// 0x0018bb40 fight::ConditionFactoryTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_2 (43 B): matches/0x0018bb40.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18bb40@fn_fdbc4aa5@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18bb40::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a72c;
    base1_dtor_001809b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fdbc4aa5
