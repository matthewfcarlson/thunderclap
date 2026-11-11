// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001144b0..0x00114560 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionCountCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc8eb1c1 {
#define TREE_TU_END }
namespace fn_fc8eb1c1 {} using namespace fn_fc8eb1c1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc8eb1c1 {
class TrackFactoryTemplate_1144b0 {
  public:
    TrackFactoryTemplate_1144b0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001122b0();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Condition_1144f0 {
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
extern int hulk_at_0040e8f8;
struct ConditionFactoryTemplate_114530 {
    void* m_vptr;
    void base1_dtor_0010cde0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc8eb1c1

// 0x001144b0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_1 (60 B): matches/0x001144b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1144b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1144b0* t = new (mem) TrackFactoryTemplate_1144b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001122b0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001144f0 fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_5 (61 B): matches/0x001144f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_5() {
    Condition_1144f0* p = (Condition_1144f0*)FUN_0008d690((int)sizeof(Condition_1144f0));
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

namespace fn_fc8eb1c1 {

// 0x00114530 fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionCountCondition>::vfunc_2 (43 B): matches/0x00114530.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114530@fn_fc8eb1c1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114530::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e8f8;
    base1_dtor_0010cde0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc8eb1c1
