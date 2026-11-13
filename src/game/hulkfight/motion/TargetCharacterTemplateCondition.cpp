// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016dce0..0x0016dd80 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetCharacterTemplateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f068b9a4 {
#define TREE_TU_END }
namespace fn_f068b9a4 {} using namespace fn_f068b9a4;
namespace fn_f068b9a4 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f068b9a4 {
class TrackFactoryTemplate_16dce0 {
  public:
    TrackFactoryTemplate_16dce0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b8c0();
extern "C" char DAT_00416878[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetCharacterTemplateCondition_16dd20 {
  public:
    void Init_00234590(int);
    int a;
    int b;
    int c;
};
extern int hulk_at_0041769c;
struct ConditionFactoryTemplate_16dd50 {
    void* m_vptr;
    void base1_dtor_001661c0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f068b9a4

// 0x0016dce0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_1 (60 B): matches/0x0016dce0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16dce0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_16dce0* t = new (mem) TrackFactoryTemplate_16dce0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b8c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016dd20 fight::ConditionFactoryTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_5 (47 B): matches/0x0016dd20.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_5() {
    TargetCharacterTemplateCondition_16dd20* p = (TargetCharacterTemplateCondition_16dd20*)FUN_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_00416878);
        *(int*)((char*)p + 0xc) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f068b9a4 {

// 0x0016dd50 fight::ConditionFactoryTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_2 (43 B): matches/0x0016dd50.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16dd50@fn_f068b9a4@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16dd50::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041769c;
    base1_dtor_001661c0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f068b9a4
