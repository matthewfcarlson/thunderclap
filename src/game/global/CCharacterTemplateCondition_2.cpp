// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058c80..0x00058d30 (kind game, layer game, confidence high), dominant class CCharacterTemplateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5377be3 {
#define TREE_TU_END }
namespace fn_f5377be3 {} using namespace fn_f5377be3;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5377be3 {
class TrackFactoryTemplate_58c80 {
  public:
    TrackFactoryTemplate_58c80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000568e0();
extern "C" char DAT_003f7328[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct Obj_58cc0 {
    void Init_00234590(int);
};
struct Sub_58cc0 {
    void Init_0027af00();
};
struct CCharacterTemplateCondition_58cc0 {
    char pad[24];
};
extern int hulk_at_003f9700;
struct ConditionFactoryTemplate_58d00 {
    void* m_vptr;
    void base1_dtor_00049ef0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5377be3

// 0x00058c80 fight::ConditionFactoryCasterTemplate<CCharacterTemplateCondition>::vfunc_1 (60 B): matches/0x00058c80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCharacterTemplateCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCharacterTemplateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58c80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58c80* t = new (mem) TrackFactoryTemplate_58c80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000568e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058cc0 fight::ConditionFactoryTemplate<CCharacterTemplateCondition>::vfunc_5 (55 B): matches/0x00058cc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCharacterTemplateCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCharacterTemplateCondition>::vfunc_5() {
    CCharacterTemplateCondition_58cc0* p = (CCharacterTemplateCondition_58cc0*)Alloc(0x18);
    if (p) {
        ((Obj_58cc0*)p)->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7328);
        *(unsigned int*)((char*)p + 0xc) = 0;
        ((Sub_58cc0*)((char*)p + 0x10))->Init_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5377be3 {

// 0x00058d00 fight::ConditionFactoryTemplate<CCharacterTemplateCondition>::vfunc_2 (43 B): matches/0x00058d00.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58d00@fn_f5377be3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58d00::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9700;
    base1_dtor_00049ef0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5377be3
