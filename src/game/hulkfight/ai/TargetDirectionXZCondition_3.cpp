// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012ac00..0x0012acb0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionXZCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5952644 {
#define TREE_TU_END }
namespace fn_f5952644 {} using namespace fn_f5952644;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5952644 {
class TrackFactoryTemplate_12ac00 {
  public:
    TrackFactoryTemplate_12ac00() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129060();
} // namespace fn_f5952644
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace hulkfight { namespace ai {
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void f0();
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    char pad[8];
};
} }
namespace hulkfight { namespace ai {
class TargetDirectionXZCondition_12ac40 : public BaseCondition {
  public:
    TargetDirectionXZCondition_12ac40() throw() : BaseCondition(0), a(0), b(0) {}
    virtual void f0();
    int a;
    int b;
};
} }
namespace fight {
class ConditionFactory_12ac40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual hulkfight::ai::TargetDirectionXZCondition_12ac40* vfunc_5();
};
}
namespace fn_f5952644 {
extern int hulk_at_00410ad8;
struct ConditionFactoryTemplate_12ac80 {
    void* m_vptr;
    void base1_dtor_00124150();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5952644

// 0x0012ac00 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_1 (60 B): matches/0x0012ac00.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12ac00));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12ac00* t = new (mem) TrackFactoryTemplate_12ac00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129060();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012ac40 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_5 (54 B): matches/0x0012ac40.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_5() {
    return (void*)(new hulkfight::ai::TargetDirectionXZCondition_12ac40);
}

namespace fn_f5952644 {

// 0x0012ac80 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_2 (43 B): matches/0x0012ac80.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12ac80@fn_f5952644@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12ac80::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410ad8;
    base1_dtor_00124150();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5952644
