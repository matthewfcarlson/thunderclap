// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e670..0x0016e720 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8e6264 {
#define TREE_TU_END }
namespace fn_fb8e6264 {} using namespace fn_fb8e6264;
namespace fn_fb8e6264 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb8e6264 {
class TrackFactoryTemplate_16e670 {
  public:
    TrackFactoryTemplate_16e670() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016cb50();
typedef unsigned int u32_16e6b0;
struct Grapple_16e6b0 {
    hulk_uintptr BuildTrack_001663a0();
};
extern int hulk_at_00417824;
struct ConditionFactoryTemplate_16e6d0 {
    void* m_vptr;
    void base1_dtor_00166370();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb8e6264

// 0x0016e670 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_1 (60 B): matches/0x0016e670.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e670));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_16e670* t = new (mem) TrackFactoryTemplate_16e670();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016cb50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e6b0 fight::ConditionFactoryTemplate<hulkfight::motion::RayCastCondition>::vfunc_5 (24 B): matches/0x0016e6b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fa30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RayCastCondition>::vfunc_5() {
    Grapple_16e6b0* p = (Grapple_16e6b0*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack_001663a0());
    return (void*)(0);
}

namespace fn_fb8e6264 {

// 0x0016e6d0 fight::ConditionFactoryTemplate<hulkfight::motion::RayCastCondition>::vfunc_2 (43 B): matches/0x0016e6d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e6d0@fn_fb8e6264@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e6d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417824;
    base1_dtor_00166370();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fb8e6264
