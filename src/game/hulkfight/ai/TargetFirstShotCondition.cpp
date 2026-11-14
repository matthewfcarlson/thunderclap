// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012acb0..0x0012ad50 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetFirstShotCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f31a095d {
#define TREE_TU_END }
namespace fn_f31a095d {} using namespace fn_f31a095d;
namespace fn_f31a095d {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f31a095d {
class TrackFactoryTemplate_12acb0 {
  public:
    TrackFactoryTemplate_12acb0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129110();
extern int hulk_at_00410af4;
struct ConditionFactoryTemplate_12ad20 {
    void* m_vptr;
    void base1_dtor_001241c0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f31a095d

// 0x0012acb0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_1 (60 B): matches/0x0012acb0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12acb0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_12acb0* t = new (mem) TrackFactoryTemplate_12acb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129110();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012acf0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_5 (44 B): matches/0x0012acf0.cpp [wrapped: conflict: operatornew]
// sym: ?vfunc_5@ConditionFactory@fn_0012acf0@@UAEPAVCondition_12acf0@2@XZ
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_0012acf0 {

class Condition_12acf0 {
  public:
    Condition_12acf0(int);
    virtual void v0();
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    char pad[8];
};
class TargetFirstShotCondition : public Condition_12acf0 {
  public:
    TargetFirstShotCondition() : Condition_12acf0(0) { flag = 1; }
    virtual void v0();
    char flag;
};
class ConditionFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Condition_12acf0* vfunc_5();
};
Condition_12acf0* ConditionFactory::vfunc_5() {
    return new TargetFirstShotCondition;
}
} // namespace fn_0012acf0

namespace fn_f31a095d {

// 0x0012ad20 fight::ConditionFactoryTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_2 (43 B): matches/0x0012ad20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12ad20@fn_f31a095d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12ad20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410af4;
    base1_dtor_001241c0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f31a095d
