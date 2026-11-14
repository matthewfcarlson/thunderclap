// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058f60..0x00059030 (kind game, layer game, confidence high), dominant class CNameFlagCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f738f905 {
#define TREE_TU_END }
namespace fn_f738f905 {} using namespace fn_f738f905;
namespace fn_f738f905 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
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
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f9794;
struct ConditionFactoryTemplate_58fa0 {
    void* m_vptr;
    void base1_dtor_00048d30();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
struct Base_58fd0 {
    virtual void f0();
    Base_58fd0();
    char pad[0x14];
};
struct CNameFlagCondition_58fd0 : Base_58fd0 {
    CNameFlagCondition_58fd0() {}
    virtual void f0();
};
extern void* hulk_at_003f97b0[];
class CNameFlagConditionBase_59000 {
  public:
    void Destroy_00048d90(); // FUN_00236d60, __thiscall, this in ecx
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
        ((FactoryCtor*)mem)->init_002343b0();
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
    m_vptr = (void*)&hulk_at_003f9794;
    base1_dtor_00048d30();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
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
    *(void***)this = hulk_at_003f97b0;
    Destroy_00048d90();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

