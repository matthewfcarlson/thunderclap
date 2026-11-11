// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b0c0..0x0012b190 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetArcCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f399d1fe {
#define TREE_TU_END }
namespace fn_f399d1fe {} using namespace fn_f399d1fe;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f399d1fe {
class TrackFactoryTemplate_12b0c0 {
  public:
    TrackFactoryTemplate_12b0c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129ab0();
class Child {
  public:
    Child(int);
};
class Sub {
  public:
    Sub();
};
extern char hulk_at_0040fd34[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_00410b9c;
struct ConditionFactoryTemplate_12b160 {
    void* m_vptr;
    void base1_dtor_00123b20();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f399d1fe

// 0x0012b0c0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetArcCondition>::vfunc_1 (60 B): matches/0x0012b0c0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetArcCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetArcCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12b0c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12b0c0* t = new (mem) TrackFactoryTemplate_12b0c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129ab0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012b100 fight::ConditionFactoryTemplate<hulkfight::ai::TargetArcCondition>::vfunc_5 (81 B): matches/0x0012b100.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VTargetArcCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetArcCondition>::vfunc_5() {
    Child* p = (Child*)FUN_0008d690(0x30);
    if (p) {
        p->Child::Child(0);
        *(void**)p = hulk_at_0040fd34;
        *(int*)((char*)p + 0xc) = 0;
        *(float*)((char*)p + 0x10) = 1.5707964f;
        *(char*)((char*)p + 0x14) = 0;
        ((Sub*)((char*)p + 0x18))->Sub::Sub();
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(float*)((char*)p + 0x28) = -1.0f;
        _ReadWriteBarrier();
        *(char*)((char*)p + 0x2c) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f399d1fe {

// 0x0012b160 fight::ConditionFactoryTemplate<hulkfight::ai::TargetArcCondition>::vfunc_2 (43 B): matches/0x0012b160.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12b160@fn_f399d1fe@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12b160::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410b9c;
    base1_dtor_00123b20();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f399d1fe
