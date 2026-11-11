// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00113ff0..0x001140a0 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionLargestCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3343a7f {
#define TREE_TU_END }
namespace fn_f3343a7f {} using namespace fn_f3343a7f;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3343a7f {
class TrackFactoryTemplate_113ff0 {
  public:
    TrackFactoryTemplate_113ff0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111df0();
} // namespace fn_f3343a7f
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_f3343a7f {
class Base {
  public:
    Base(int) throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
};
class HulkActionLargestCondition_114030 : public Base {
  public:
    HulkActionLargestCondition_114030() throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int a;
    int b;
};
inline HulkActionLargestCondition_114030::HulkActionLargestCondition_114030() throw() : Base(0), a(0), b(0) {}
extern int g_vftable_114070;
struct ConditionFactoryTemplate_114070 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f3343a7f

// 0x00113ff0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_1 (60 B): matches/0x00113ff0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_113ff0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_113ff0* t = new (mem) TrackFactoryTemplate_113ff0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111df0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114030 fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_5 (54 B): matches/0x00114030.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_5() {
    return (void*)(new HulkActionLargestCondition_114030);
}

namespace fn_f3343a7f {

// 0x00114070 fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_2 (43 B): matches/0x00114070.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_114070@fn_f3343a7f@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_114070::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_114070;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f3343a7f
