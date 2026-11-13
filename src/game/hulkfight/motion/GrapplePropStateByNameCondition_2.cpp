// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c500..0x0018c5b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrapplePropStateByNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4f943b3 {
#define TREE_TU_END }
namespace fn_f4f943b3 {} using namespace fn_f4f943b3;
namespace fn_f4f943b3 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4f943b3 {
class TrackFactoryTemplate_18c500 {
  public:
    TrackFactoryTemplate_18c500() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00189a50();
extern "C" char DAT_0041916c[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Base_18c540 {
    void Init_00234590(int);
};
struct Sub_18c540 {
    void Setup_0027af00();
};
extern int hulk_at_0041a8d0;
struct ConditionFactoryTemplate_18c580 {
    void* m_vptr;
    void base1_dtor_00180690();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4f943b3

// 0x0018c500 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_1 (60 B): matches/0x0018c500.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c500));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_18c500* t = new (mem) TrackFactoryTemplate_18c500();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00189a50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c540 fight::ConditionFactoryTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_5 (62 B): matches/0x0018c540.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_5() {
    Base_18c540* p = (Base_18c540*)FUN_0008d690(0x20);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041916c);
        ((uint*)p)[3] = 0xffffffff;
        ((uint*)p)[4] = 0;
        ((Sub_18c540*)((char*)p + 0x18))->Setup_0027af00();
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_f4f943b3 {

// 0x0018c580 fight::ConditionFactoryTemplate<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_2 (43 B): matches/0x0018c580.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18c580@fn_f4f943b3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18c580::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a8d0;
    base1_dtor_00180690();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4f943b3
