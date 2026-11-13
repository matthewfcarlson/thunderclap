// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a650..0x0015a700 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceNameCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4aac511 {
#define TREE_TU_END }
namespace fn_f4aac511 {} using namespace fn_f4aac511;
namespace fn_f4aac511 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4aac511 {
class TrackFactoryTemplate_15a650 {
  public:
    TrackFactoryTemplate_15a650() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001581b0();
} // namespace fn_f4aac511
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_f4aac511 {
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class Sub {
  public:
    Sub() throw();
    char pad[8];
};
class Condition_15a690 : public Base {
  public:
    Condition_15a690() throw() : Base(0), field(0), sub() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int field;
    Sub sub;
};
extern int hulk_at_004158d4;
struct ConditionFactoryTemplate_15a6d0 {
    void* m_vptr;
    void base1_dtor_0014dac0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4aac511

// 0x0015a650 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_1 (60 B): matches/0x0015a650.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a650));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_15a650* t = new (mem) TrackFactoryTemplate_15a650();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001581b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a690 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_5 (55 B): matches/0x0015a690.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_5() {
    return (void*)(new Condition_15a690);
}

namespace fn_f4aac511 {

// 0x0015a6d0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_2 (43 B): matches/0x0015a6d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_15a6d0@fn_f4aac511@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_15a6d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004158d4;
    base1_dtor_0014dac0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4aac511
