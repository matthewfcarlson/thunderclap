// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114200..0x001142a0 (kind game, layer game, confidence high), dominant class hulkfight::ai::LeashedCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0bba2c9 {
#define TREE_TU_END }
namespace fn_f0bba2c9 {} using namespace fn_f0bba2c9;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0bba2c9 {
class TrackFactoryTemplate_114200 {
  public:
    TrackFactoryTemplate_114200() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112000();
extern int hulk_at_0040e888;
struct ConditionFactoryTemplate_114270 {
    void* m_vptr;
    void base1_dtor_0010cb60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0bba2c9

// 0x00114200 fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_1 (60 B): matches/0x00114200.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VLeashedCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::LeashedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114200));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114200* t = new (mem) TrackFactoryTemplate_114200();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112000();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114240 fight::ConditionFactoryTemplate<hulkfight::ai::LeashedCondition>::vfunc_5 (44 B): matches/0x00114240.cpp [wrapped: conflict: operatornew]
// sym: ?vfunc_5@ConditionFactory@fn_00114240@@UAEPAVCondition_114240@2@XZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_00114240 {

class Condition_114240 {
  public:
    virtual void v0();
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    char pad[8];
    Condition_114240(int) throw();
};
class LeashedCondition : public Condition_114240 {
  public:
    virtual void v0();
    char enabled;
    LeashedCondition() throw() : Condition_114240(0) { enabled = 1; }
};
class ConditionFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Condition_114240* vfunc_5();
};
Condition_114240* ConditionFactory::vfunc_5() {
    return new LeashedCondition;
}
} // namespace fn_00114240

namespace fn_f0bba2c9 {

// 0x00114270 fight::ConditionFactoryTemplate<hulkfight::ai::LeashedCondition>::vfunc_2 (43 B): matches/0x00114270.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114270@fn_f0bba2c9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114270::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e888;
    base1_dtor_0010cb60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0bba2c9
