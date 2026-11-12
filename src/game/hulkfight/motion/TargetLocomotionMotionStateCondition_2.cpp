// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016dad0..0x0016db80 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetLocomotionMotionStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faefdf3f {
#define TREE_TU_END }
namespace fn_faefdf3f {} using namespace fn_faefdf3f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_faefdf3f {
class TrackFactoryTemplate_16dad0 {
  public:
    TrackFactoryTemplate_16dad0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b650();
extern char hulk_at_00416818[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Create();
    int x;
    int y;
    int z;
    int w;
    TargetCondition(int);
};
extern int hulk_at_00417648;
struct ConditionFactoryTemplate_16db50 {
    void* m_vptr;
    void base1_dtor_00166070();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_faefdf3f

// 0x0016dad0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_1 (60 B): matches/0x0016dad0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16dad0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16dad0* t = new (mem) TrackFactoryTemplate_16dad0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b650();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_faefdf3f {

// 0x0016db10 fight::ConditionFactoryTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_5 (54 B): matches/0x0016db10.cpp
// sym: ?Create@TargetCondition@fn_faefdf3f@@UAEPAXXZ
void* TargetCondition::Create() {
    TargetCondition* p = (TargetCondition*)FUN_0008d690((int)sizeof(TargetCondition));
    if (p) {
        p->TargetCondition::TargetCondition(0);
        *(void**)p = hulk_at_00416818;
        p->z = 0;
        p->w = 0;
        return p;
    }
    return 0;
}


// 0x0016db50 fight::ConditionFactoryTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_2 (43 B): matches/0x0016db50.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16db50@fn_faefdf3f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16db50::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417648;
    base1_dtor_00166070();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_faefdf3f
