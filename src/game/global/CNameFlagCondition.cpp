// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058f60..0x00059030 (kind game, layer game, confidence high), dominant class CNameFlagCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f738f905 {
#define TREE_TU_END }
namespace fn_f738f905 {} using namespace fn_f738f905;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f738f905 {
class TrackFactoryTemplate_58f60 {
  public:
    TrackFactoryTemplate_58f60() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_58fa0;
struct ConditionFactoryTemplate_58fa0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
struct Base_58fd0 {
    virtual void f0();
    Base_58fd0() throw();
    char pad[0x14];
};
struct CNameFlagCondition_58fd0 : Base_58fd0 {
    CNameFlagCondition_58fd0() throw() {}
    virtual void f0();
};
extern void* CNameFlagConditionBase_59000_vftable[];
class CNameFlagConditionBase_59000 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f738f905
class CNameFlagCondition : public CNameFlagConditionBase_59000 {
  public:
    CNameFlagCondition* vfunc_5(signed char flags);
};


// 0x00058f60 fight::ConditionFactoryCasterTemplate<CNameFlagCondition>::vfunc_1 (60 B): matches/0x00058f60.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCNameFlagCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CNameFlagCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58f60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58f60* t = new (mem) TrackFactoryTemplate_58f60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00056570();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f738f905 {

// 0x00058fa0 fight::ConditionFactoryTemplate<CNameFlagCondition>::vfunc_2 (43 B): matches/0x00058fa0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58fa0@fn_f738f905@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58fa0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_58fa0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f738f905

// 0x00058fd0 fight::ConditionFactoryTemplate<CNameFlagCondition>::vfunc_5 (38 B): matches/0x00058fd0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCNameFlagCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CNameFlagCondition>::vfunc_5() {
    return (void*)(new CNameFlagCondition_58fd0);
}


// 0x00059000 CNameFlagCondition::vfunc_5 (36 B): matches/0x00059000.cpp
// sym: ?vfunc_5@CNameFlagCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CNameFlagCondition* CNameFlagCondition::vfunc_5(signed char flags) {
    *(void***)this = CNameFlagConditionBase_59000_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

