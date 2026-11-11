// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058670..0x00058710 (kind game, layer game, confidence high), dominant class CRageModeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff2800b1 {
#define TREE_TU_END }
namespace fn_ff2800b1 {} using namespace fn_ff2800b1;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff2800b1 {
class TrackFactoryTemplate_58670 {
  public:
    TrackFactoryTemplate_58670() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054300();
extern "C" char DAT_003f742c[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class CRageModeCondition_586b0 {
  public:
    void Init_00234590(int);
};
extern int hulk_at_003f9604;
struct ConditionFactoryTemplate_586e0 {
    void* m_vptr;
    void base1_dtor_0004a5a0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff2800b1

// 0x00058670 fight::ConditionFactoryCasterTemplate<CRageModeCondition>::vfunc_1 (60 B): matches/0x00058670.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCRageModeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CRageModeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58670));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58670* t = new (mem) TrackFactoryTemplate_58670();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054300();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000586b0 fight::ConditionFactoryTemplate<CRageModeCondition>::vfunc_5 (44 B): matches/0x000586b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCRageModeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CRageModeCondition>::vfunc_5() {
    CRageModeCondition_586b0* p = (CRageModeCondition_586b0*)Alloc(0x10);
    if (p) {
        p->Init_00234590(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f742c);
        *((char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_ff2800b1 {

// 0x000586e0 fight::ConditionFactoryTemplate<CRageModeCondition>::vfunc_2 (43 B): matches/0x000586e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_586e0@fn_ff2800b1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_586e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9604;
    base1_dtor_0004a5a0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff2800b1
