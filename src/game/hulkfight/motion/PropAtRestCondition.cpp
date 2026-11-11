// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018b8c0..0x0018b960 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAtRestCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9b92d91 {
#define TREE_TU_END }
namespace fn_f9b92d91 {} using namespace fn_f9b92d91;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9b92d91 {
class TrackFactoryTemplate_18b8c0 {
  public:
    TrackFactoryTemplate_18b8c0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001879c0();
struct PropAtRestCondition_nv_18b900 {
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_004191cc;
extern int hulk_at_0041a6d8;
struct ConditionFactoryTemplate_18b930 {
    void* m_vptr;
    void base1_dtor_00180800();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f9b92d91

// 0x0018b8c0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_1 (60 B): matches/0x0018b8c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropAtRestCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18b8c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18b8c0* t = new (mem) TrackFactoryTemplate_18b8c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001879c0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f9b92d91 {

// 0x0018b900 fight::ConditionFactoryTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_5 (44 B): matches/0x0018b900.cpp
// sym: ?Factory_vfunc5@fn_f9b92d91@@YAPAXXZ
void* Factory_vfunc5() {
    hulkfight::motion::PropAtRestCondition* p = (hulkfight::motion::PropAtRestCondition*)FUN_0008d690((int)sizeof(hulkfight::motion::PropAtRestCondition));
    if (p) {
        ((PropAtRestCondition_nv_18b900*)(p))->Init_00234590(0);
        *((hulk_intptr*)p) = (hulk_intptr)&hulk_at_004191cc;
        (*(unsigned char *)&p->f_0c) = 1;
        return p;
    }
    return 0;
}


// 0x0018b930 fight::ConditionFactoryTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_2 (43 B): matches/0x0018b930.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18b930@fn_f9b92d91@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18b930::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a6d8;
    base1_dtor_00180800();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9b92d91
