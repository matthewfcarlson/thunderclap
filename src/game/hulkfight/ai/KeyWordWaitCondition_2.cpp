// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001142a0..0x00114350 (kind game, layer game, confidence high), dominant class hulkfight::ai::KeyWordWaitCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbde9503 {
#define TREE_TU_END }
namespace fn_fbde9503 {} using namespace fn_fbde9503;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbde9503 {
class TrackFactoryTemplate_1142a0 {
  public:
    TrackFactoryTemplate_1142a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112060();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Condition_1142e0 {
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
extern int hulk_at_0040e8a4;
struct ConditionFactoryTemplate_114320 {
    void* m_vptr;
    void base1_dtor_0010cbc0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbde9503

// 0x001142a0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_1 (60 B): matches/0x001142a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1142a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1142a0* t = new (mem) TrackFactoryTemplate_1142a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112060();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001142e0 fight::ConditionFactoryTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_5 (61 B): matches/0x001142e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_5() {
    Condition_1142e0* p = (Condition_1142e0*)FUN_0008d690((int)sizeof(Condition_1142e0));
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

namespace fn_fbde9503 {

// 0x00114320 fight::ConditionFactoryTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_2 (43 B): matches/0x00114320.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114320@fn_fbde9503@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114320::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e8a4;
    base1_dtor_0010cbc0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbde9503
