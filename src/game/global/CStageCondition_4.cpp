// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058bd0..0x00058c80 (kind game, layer game, confidence high), dominant class CStageCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#include "gen/global.h"   // (dtor1) CStageCondition, the stub class's real class
#define TREE_TU_BEGIN namespace fn_fbbe4521 {
#define TREE_TU_END }
namespace fn_fbbe4521 {} using namespace fn_fbbe4521;
namespace fn_fbbe4521 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbbe4521 {
class TrackFactoryTemplate_58bd0 {
  public:
    TrackFactoryTemplate_58bd0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00052720();
extern int hulk_at_003f96e4;
struct ConditionFactoryTemplate_58c50 {
    void* m_vptr;
    void base1_dtor_000482e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbbe4521

// 0x00058bd0 fight::ConditionFactoryCasterTemplate<CStageCondition>::vfunc_1 (60 B): matches/0x00058bd0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCStageCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CStageCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58bd0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_58bd0* t = new (mem) TrackFactoryTemplate_58bd0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052720();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058c10 fight::ConditionFactoryTemplate<CStageCondition>::vfunc_5 (54 B): matches/0x00058c10.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?f5@Factory@fn_00058c10@@UAEPAVCStageCondition@2@XZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_00058c10 {
/* size_t: tree_prelude.h */

class CCondition_58c10 {
  public:
    CCondition_58c10(int) throw();
    virtual void f0();
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    int a;
    int b;
};
class CStageCondition : public ::CStageCondition {
  public:
    CStageCondition() throw();
};
CStageCondition::CStageCondition() throw() : ::CStageCondition(0) {
    f_0c = 2;
    f_10 = 0;
}
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CStageCondition* f5();
};
CStageCondition* Factory::f5() {
    return new CStageCondition;
}
} // namespace fn_00058c10

namespace fn_fbbe4521 {

// 0x00058c50 fight::ConditionFactoryTemplate<CStageCondition>::vfunc_2 (43 B): matches/0x00058c50.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58c50@fn_fbbe4521@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58c50::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f96e4;
    base1_dtor_000482e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fbbe4521
