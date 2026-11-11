// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00113f40..0x00113ff0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistoryNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbe259a7 {
#define TREE_TU_END }
namespace fn_fbe259a7 {} using namespace fn_fbe259a7;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbe259a7 {
class TrackFactoryTemplate_113f40 {
  public:
    TrackFactoryTemplate_113f40() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111d00();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Condition_113f80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init_00234590(int);
    int x;
    int y;
    int z;
    int w;
    int q;
};
extern int hulk_at_0040e818;
struct ConditionFactoryTemplate_113fc0 {
    void* m_vptr;
    void base1_dtor_0010c850();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbe259a7

// 0x00113f40 fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_1 (60 B): matches/0x00113f40.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_113f40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_113f40* t = new (mem) TrackFactoryTemplate_113f40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111d00();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00113f80 fight::ConditionFactoryTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_5 (61 B): matches/0x00113f80.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_5() {
    Condition_113f80* p = (Condition_113f80*)FUN_0008d690((int)sizeof(Condition_113f80));
    void* result;
    if (p) {
        p->Init_00234590(0);
        *(int**)p = &AIHistoryNameCondition_vftable;
        p->z = 0;
        p->w = 0;
        p->q = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}

namespace fn_fbe259a7 {

// 0x00113fc0 fight::ConditionFactoryTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_2 (43 B): matches/0x00113fc0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_113fc0@fn_fbe259a7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_113fc0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e818;
    base1_dtor_0010c850();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbe259a7
