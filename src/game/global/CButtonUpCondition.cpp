// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057430..0x00057500 (kind game, layer game, confidence high), dominant class CButtonUpCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4fd780c {
#define TREE_TU_END }
namespace fn_f4fd780c {} using namespace fn_f4fd780c;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4fd780c {
class TrackFactoryTemplate_57430 {
  public:
    TrackFactoryTemplate_57430() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003f92ac;
struct ConditionFactoryTemplate_57470 {
    void* m_vptr;
    void base1_dtor_00048450();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
struct Base_574a0 {
    virtual void f0();
    Base_574a0() throw();
    char pad[0x14];
};
struct CButtonUpCondition_574a0 : Base_574a0 {
    CButtonUpCondition_574a0() throw() {}
    virtual void f0();
};
extern void* hulk_at_003f6d50[];
class CButtonCondition_574d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f4fd780c
class CButtonUpCondition : public CButtonCondition_574d0 {
  public:
    CButtonUpCondition* vfunc_5(signed char flags);
};


// 0x00057430 fight::ConditionFactoryCasterTemplate<CButtonUpCondition>::vfunc_1 (60 B): matches/0x00057430.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCButtonUpCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CButtonUpCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57430));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57430* t = new (mem) TrackFactoryTemplate_57430();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000527d0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f4fd780c {

// 0x00057470 fight::ConditionFactoryTemplate<CButtonUpCondition>::vfunc_2 (43 B): matches/0x00057470.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57470@fn_f4fd780c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57470::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f92ac;
    base1_dtor_00048450();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4fd780c

// 0x000574a0 fight::ConditionFactoryTemplate<CButtonUpCondition>::vfunc_5 (38 B): matches/0x000574a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCButtonUpCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CButtonUpCondition>::vfunc_5() {
    return (void*)(new CButtonUpCondition_574a0);
}


// 0x000574d0 CButtonUpCondition::vfunc_5 (36 B): matches/0x000574d0.cpp
// sym: ?vfunc_5@CButtonUpCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CButtonUpCondition* CButtonUpCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

