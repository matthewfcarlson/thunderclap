// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000580f0..0x000581a0 (kind game, layer game, confidence high), dominant class CGroundDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5f5c4c9 {
#define TREE_TU_END }
namespace fn_f5f5c4c9 {} using namespace fn_f5f5c4c9;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5f5c4c9 {
class TrackFactoryTemplate_580f0 {
  public:
    TrackFactoryTemplate_580f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053170();
extern "C" char DAT_003f6f5c[];
class GroundCondition {
  public:
    void Init_00234590(int);
};
extern "C" void* Alloc(hulk_uintptr);
extern int hulk_at_003f9524;
struct ConditionFactoryTemplate_58170 {
    void* m_vptr;
    void base1_dtor_00048a00();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5f5c4c9

// 0x000580f0 fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition>::vfunc_1 (60 B): matches/0x000580f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGroundDistanceCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_580f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_580f0* t = new (mem) TrackFactoryTemplate_580f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053170();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058130 fight::ConditionFactoryTemplate<CGroundDistanceCondition>::vfunc_5 (54 B): matches/0x00058130.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGroundDistanceCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CGroundDistanceCondition>::vfunc_5() {
    GroundCondition* p = (GroundCondition*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f6f5c);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5f5c4c9 {

// 0x00058170 fight::ConditionFactoryTemplate<CGroundDistanceCondition>::vfunc_2 (43 B): matches/0x00058170.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58170@fn_f5f5c4c9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58170::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9524;
    base1_dtor_00048a00();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5f5c4c9
