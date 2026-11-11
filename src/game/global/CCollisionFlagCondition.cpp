// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058de0..0x00058eb0 (kind game, layer game, confidence high), dominant class CCollisionFlagCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9d74a4d {
#define TREE_TU_END }
namespace fn_f9d74a4d {} using namespace fn_f9d74a4d;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9d74a4d {
class TrackFactoryTemplate_58de0 {
  public:
    TrackFactoryTemplate_58de0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f9738;
struct ConditionFactoryTemplate_58e20 {
    void* m_vptr;
    void base1_dtor_00048d30();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_003f9754[];
class CCollisionFlagCondition_58e50 {
  public:
    hulk_intptr vf;
    void Init_00048d60();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* hulk_at_003f9754[];
class CNameFlagConditionBase_58e80 {
  public:
    void Destroy_00048d90(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9d74a4d
class CCollisionFlagCondition : public CNameFlagConditionBase_58e80 {
  public:
    CCollisionFlagCondition* vfunc_5(signed char flags);
};


// 0x00058de0 fight::ConditionFactoryCasterTemplate<CCollisionFlagCondition>::vfunc_1 (60 B): matches/0x00058de0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionFlagCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionFlagCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58de0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58de0* t = new (mem) TrackFactoryTemplate_58de0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056570();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f9d74a4d {

// 0x00058e20 fight::ConditionFactoryTemplate<CCollisionFlagCondition>::vfunc_2 (43 B): matches/0x00058e20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58e20@fn_f9d74a4d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58e20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9738;
    base1_dtor_00048d30();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9d74a4d

// 0x00058e50 fight::ConditionFactoryTemplate<CCollisionFlagCondition>::vfunc_5 (38 B): matches/0x00058e50.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionFlagCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionFlagCondition>::vfunc_5() {
    CCollisionFlagCondition_58e50* p = (CCollisionFlagCondition_58e50*)FUN_0008d690(0x18);
    if (p) {
        p->Init_00048d60();
        p->vf = ((hulk_intptr)DAT_003f9754);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00058e80 CCollisionFlagCondition::vfunc_5 (36 B): matches/0x00058e80.cpp
// sym: ?vfunc_5@CCollisionFlagCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionFlagCondition* CCollisionFlagCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f9754;
    Destroy_00048d90();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

