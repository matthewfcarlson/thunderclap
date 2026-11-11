// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a320..0x0012a3d0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetTypeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f96db5a8 {
#define TREE_TU_END }
namespace fn_f96db5a8 {} using namespace fn_f96db5a8;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f96db5a8 {
class TrackFactoryTemplate_12a320 {
  public:
    TrackFactoryTemplate_12a320() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001285a0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* hulk_at_0040fd54[];
class Cond {
  public:
    Cond(int);
    virtual void a();
    char pad[0xc - 4];
    int x;
    int y;
};
extern int hulk_at_0041096c;
struct ConditionFactoryTemplate_12a3a0 {
    void* m_vptr;
    void base1_dtor_00123bb0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f96db5a8

// 0x0012a320 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_1 (60 B): matches/0x0012a320.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetTypeCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a320));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a320* t = new (mem) TrackFactoryTemplate_12a320();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001285a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012a360 fight::ConditionFactoryTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_5 (54 B): matches/0x0012a360.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetTypeCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_5() {
    Cond* p = (Cond*)FUN_0008d690((int)sizeof(Cond));
    if (p) {
        p->Cond::Cond(0);
        *(void* volatile*)p = hulk_at_0040fd54;
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f96db5a8 {

// 0x0012a3a0 fight::ConditionFactoryTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_2 (43 B): matches/0x0012a3a0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a3a0@fn_f96db5a8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a3a0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041096c;
    base1_dtor_00123bb0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f96db5a8
