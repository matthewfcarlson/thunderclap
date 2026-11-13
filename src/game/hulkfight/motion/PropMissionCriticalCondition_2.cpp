// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018b6b0..0x0018b760 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMissionCriticalCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe97ab9a {
#define TREE_TU_END }
namespace fn_fe97ab9a {} using namespace fn_fe97ab9a;
namespace fn_fe97ab9a {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe97ab9a {
class TrackFactoryTemplate_18b6b0 {
  public:
    TrackFactoryTemplate_18b6b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187650();
typedef unsigned int u32_18b6f0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct InitObj_18b6f0 {
    void init_00234590(int);
};
extern int hulk_at_0041912c;
extern int hulk_at_0041a684;
struct ConditionFactoryTemplate_18b730 {
    void* m_vptr;
    void base1_dtor_001805b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe97ab9a

// 0x0018b6b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_1 (60 B): matches/0x0018b6b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18b6b0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_18b6b0* t = new (mem) TrackFactoryTemplate_18b6b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187650();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018b6f0 fight::ConditionFactoryTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_5 (51 B): matches/0x0018b6f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x14);
    if (p) {
        ((InitObj_18b6f0*)p)->init_00234590(0);
        *(hulk_uintptr*)p = (hulk_uintptr)&hulk_at_0041912c;
        *(u32_18b6f0*)(p + 0xc) = 0xffffffff;
        p[0x10] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe97ab9a {

// 0x0018b730 fight::ConditionFactoryTemplate<hulkfight::motion::PropMissionCriticalCondition>::vfunc_2 (43 B): matches/0x0018b730.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18b730@fn_fe97ab9a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18b730::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a684;
    base1_dtor_001805b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe97ab9a
