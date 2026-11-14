// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00164e10..0x00164ec0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PhaseCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe3cb10d {
#define TREE_TU_END }
namespace fn_fe3cb10d {} using namespace fn_fe3cb10d;
namespace fn_fe3cb10d {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe3cb10d {
class TrackFactoryTemplate_164e10 {
  public:
    TrackFactoryTemplate_164e10() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001612e0();
} // namespace fn_fe3cb10d
void* operator new(size_t);
namespace hulkfight { namespace motion {
class Base {
  public:
    Base(int);
    virtual void f0();
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    int a;
    int b;
};
} }
namespace hulkfight { namespace motion {
class PhaseCondition_164e50 : public Base {
  public:
    PhaseCondition_164e50() : Base(0), c(0), d(0) {}
    virtual void f0();
    int c;
    int d;
};
} }
namespace fight {
class ConditionFactory_164e50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
}
namespace fn_fe3cb10d {
extern int hulk_at_004164b0;
struct ConditionFactoryTemplate_164e90 {
    void* m_vptr;
    void base1_dtor_0015b840();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe3cb10d

// 0x00164e10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition>::vfunc_1 (60 B): matches/0x00164e10.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPhaseCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_164e10));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_164e10* t = new (mem) TrackFactoryTemplate_164e10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001612e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00164e50 fight::ConditionFactoryTemplate<hulkfight::motion::PhaseCondition>::vfunc_5 (54 B): matches/0x00164e50.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPhaseCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PhaseCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::PhaseCondition_164e50);
}

namespace fn_fe3cb10d {

// 0x00164e90 fight::ConditionFactoryTemplate<hulkfight::motion::PhaseCondition>::vfunc_2 (43 B): matches/0x00164e90.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_164e90@fn_fe3cb10d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_164e90::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004164b0;
    base1_dtor_0015b840();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe3cb10d
