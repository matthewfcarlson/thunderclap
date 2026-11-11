// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159100..0x001591b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceSizeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe47b234 {
#define TREE_TU_END }
namespace fn_fe47b234 {} using namespace fn_fe47b234;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe47b234 {
class TrackFactoryTemplate_159100 {
  public:
    TrackFactoryTemplate_159100() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155270();
extern "C" char DAT_00413fd0[];
extern "C" void* __cdecl Alloc(hulk_intptr);
struct Obj_159140 {
    hulk_intptr vf;
    int pad[4];
    void Init_00234590(int);
};
extern int hulk_at_00415570;
struct ConditionFactoryTemplate_159180 {
    void* m_vptr;
    void base1_dtor_0014d390();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe47b234

// 0x00159100 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_1 (60 B): matches/0x00159100.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159100));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_159100* t = new (mem) TrackFactoryTemplate_159100();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155270();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159140 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_5 (54 B): matches/0x00159140.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_5() {
    Obj_159140* p = (Obj_159140*)Alloc(0x14);
    if (p) {
        p->Init_00234590(0);
        p->vf = ((hulk_intptr)DAT_00413fd0);
        p->pad[2] = 0;
        p->pad[3] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe47b234 {

// 0x00159180 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_2 (43 B): matches/0x00159180.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159180@fn_fe47b234@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159180::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415570;
    base1_dtor_0014d390();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe47b234
