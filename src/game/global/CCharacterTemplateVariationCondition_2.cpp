// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058d30..0x00058de0 (kind game, layer game, confidence high), dominant class CCharacterTemplateVariationCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0389c66 {
#define TREE_TU_END }
namespace fn_f0389c66 {} using namespace fn_f0389c66;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0389c66 {
class TrackFactoryTemplate_58d30 {
  public:
    TrackFactoryTemplate_58d30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00056990();
extern "C" char DAT_003f734c[];
extern "C" void* __cdecl Alloc(hulk_intptr);
struct Entity_58d70 {
    void Init();
};
struct Condition_58d70 {
    char pad[0xc];
    int value;
    Entity_58d70 ent;
    void Ctor(int);
};
extern int g_vftable_58db0;
struct ConditionFactoryTemplate_58db0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0389c66

// 0x00058d30 fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::vfunc_1 (60 B): matches/0x00058d30.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58d30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58d30* t = new (mem) TrackFactoryTemplate_58d30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056990();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058d70 fight::ConditionFactoryTemplate<CCharacterTemplateVariationCondition>::vfunc_5 (55 B): matches/0x00058d70.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCharacterTemplateVariationCondition>::vfunc_5() {
    Condition_58d70* p = (Condition_58d70*)Alloc(0x18);
    if (p) {
        p->Ctor(0);
        *(void**)p = (void*)((hulk_intptr)DAT_003f734c);
        *(int*)((char*)p + 0xc) = 0;
        p->ent.Init();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0389c66 {

// 0x00058db0 fight::ConditionFactoryTemplate<CCharacterTemplateVariationCondition>::vfunc_2 (43 B): matches/0x00058db0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58db0@fn_f0389c66@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58db0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_58db0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0389c66
