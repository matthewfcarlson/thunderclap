// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c670..0x0018c720 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropStateByNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd0a5b33 {
#define TREE_TU_END }
namespace fn_fd0a5b33 {} using namespace fn_fd0a5b33;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd0a5b33 {
class TrackFactoryTemplate_18c670 {
  public:
    TrackFactoryTemplate_18c670() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00189d50();
extern "C" char DAT_0041920c[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Sub_18c6b0 {
  public:
    void Init_0027af00();
};
class PropStateByNameCondition_18c6b0 {
  public:
    void Init_00234590(int);
    char vptr[4];
    char pad04[8];
    int x;
    int y;
    char pad14[4];
    Sub_18c6b0 sub;
};
extern int hulk_at_0041a908;
struct ConditionFactoryTemplate_18c6f0 {
    void* m_vptr;
    void base1_dtor_001808c0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd0a5b33

// 0x0018c670 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_1 (60 B): matches/0x0018c670.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c670));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c670* t = new (mem) TrackFactoryTemplate_18c670();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00189d50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c6b0 fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_5 (62 B): matches/0x0018c6b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_5() {
    PropStateByNameCondition_18c6b0* p = (PropStateByNameCondition_18c6b0*)FUN_0008d690(0x20);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041920c);
        p->x = -1;
        p->y = 0;
        p->sub.Init_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd0a5b33 {

// 0x0018c6f0 fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_2 (43 B): matches/0x0018c6f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18c6f0@fn_fd0a5b33@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18c6f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a908;
    base1_dtor_001808c0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd0a5b33
