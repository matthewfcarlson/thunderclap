// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016d6c0..0x0016d770 (kind game, layer game, confidence high), dominant class hulkfight::motion::TurningVelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f782cc80 {
#define TREE_TU_END }
namespace fn_f782cc80 {} using namespace fn_f782cc80;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f782cc80 {
class TrackFactoryTemplate_16d6c0 {
  public:
    TrackFactoryTemplate_16d6c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b210();
struct Turning {
    hulk_intptr vptr;
    int x;
    int y;
    int z;
    int w;
    void Init_00234590(int);
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int hulk_at_00416738;
extern int hulk_at_004175a0;
struct ConditionFactoryTemplate_16d740 {
    void* m_vptr;
    void base1_dtor_00165d50();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f782cc80

// 0x0016d6c0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_1 (60 B): matches/0x0016d6c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16d6c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16d6c0* t = new (mem) TrackFactoryTemplate_16d6c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b210();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016d700 fight::ConditionFactoryTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_5 (54 B): matches/0x0016d700.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_5() {
    Turning* p = (Turning*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vptr = (hulk_intptr)&hulk_at_00416738;
        p->z = 0;
        p->w = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f782cc80 {

// 0x0016d740 fight::ConditionFactoryTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_2 (43 B): matches/0x0016d740.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d740@fn_f782cc80@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d740::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004175a0;
    base1_dtor_00165d50();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f782cc80
