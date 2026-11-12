// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001591b0..0x00159260 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8633f69 {
#define TREE_TU_END }
namespace fn_f8633f69 {} using namespace fn_f8633f69;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8633f69 {
class TrackFactoryTemplate_1591b0 {
  public:
    TrackFactoryTemplate_1591b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155330();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* hulk_at_00413ff0;
class Condition {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual Condition* vfunc_5();
    char pad[8];
    int x;
    int y;
    void Init_00234590(int);
};
extern int hulk_at_0041558c;
struct ConditionFactoryTemplate_159230 {
    void* m_vptr;
    void base1_dtor_0014d400();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8633f69

// 0x001591b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_1 (60 B): matches/0x001591b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1591b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1591b0* t = new (mem) TrackFactoryTemplate_1591b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155330();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f8633f69 {

// 0x001591f0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_5 (54 B): matches/0x001591f0.cpp
// sym: ?vfunc_5@Condition@fn_f8633f69@@UAEPAV12@XZ
Condition* Condition::vfunc_5() {
    Condition* p = (Condition*)FUN_0008d690((int)sizeof(Condition));
    if (p) {
        p->Init_00234590(0);
        *(void**)p = &hulk_at_00413ff0;
        p->x = 0;
        p->y = 0;
        return p;
    }
    return 0;
}


// 0x00159230 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_2 (43 B): matches/0x00159230.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159230@fn_f8633f69@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159230::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041558c;
    base1_dtor_0014d400();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8633f69
