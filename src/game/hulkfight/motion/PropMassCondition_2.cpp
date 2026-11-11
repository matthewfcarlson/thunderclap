// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c5b0..0x0018c670 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMassCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffe1b429 {
#define TREE_TU_END }
namespace fn_ffe1b429 {} using namespace fn_ffe1b429;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffe1b429 {
class TrackFactoryTemplate_18c5b0 {
  public:
    TrackFactoryTemplate_18c5b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00189ba0();
extern "C" void* __cdecl operator_new(unsigned int);
struct Condition_18c5f0 {
    virtual void f0();
    Condition_18c5f0(int);
    char pad[8];
};
struct Sub_18c5f0 {
    Sub_18c5f0();
    char pad[8];
};
struct PropMassCondition_18c5f0 : Condition_18c5f0 {
    PropMassCondition_18c5f0() : Condition_18c5f0(0), a(0), b(0), s(), mass(1.0f) {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int a;
    int b;
    char gap[4];
    Sub_18c5f0 s;
    float mass;
};
extern int g_vftable_18c640;
struct ConditionFactoryTemplate_18c640 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ffe1b429

// 0x0018c5b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_1 (60 B): matches/0x0018c5b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMassCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c5b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c5b0* t = new (mem) TrackFactoryTemplate_18c5b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00189ba0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_ffe1b429 {

// 0x0018c5f0 fight::ConditionFactoryTemplate<hulkfight::motion::PropMassCondition>::vfunc_5 (69 B): matches/0x0018c5f0.cpp
// sym: ?factory_vfunc_5@fn_ffe1b429@@YAPAUPropMassCondition_18c5f0@1@XZ
PropMassCondition_18c5f0* factory_vfunc_5() {
    PropMassCondition_18c5f0* p = (PropMassCondition_18c5f0*)operator_new(0x28);
    if (p) {
        p = new (p) PropMassCondition_18c5f0();
    } else
        p = 0;
    return p;
}


// 0x0018c640 fight::ConditionFactoryTemplate<hulkfight::motion::PropMassCondition>::vfunc_2 (43 B): matches/0x0018c640.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18c640@fn_ffe1b429@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18c640::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18c640;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffe1b429
