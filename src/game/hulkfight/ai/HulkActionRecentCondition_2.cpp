// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114150..0x00114200 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionRecentCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4bd8044 {
#define TREE_TU_END }
namespace fn_f4bd8044 {} using namespace fn_f4bd8044;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4bd8044 {
class TrackFactoryTemplate_114150 {
  public:
    TrackFactoryTemplate_114150() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111f50();
struct Base_114190 {
    Base_114190(int) throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_114190* f();
    int m4, m8;
};
struct Cond_114190 : Base_114190 {
    int mc, m10;
    Cond_114190() throw() : Base_114190(0) {
        mc = 0;
        m10 = 0;
    }
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_114190* f();
};
extern int hulk_at_0040e86c;
struct ConditionFactoryTemplate_1141d0 {
    void* m_vptr;
    void base1_dtor_0010ca80();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4bd8044

// 0x00114150 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_1 (60 B): matches/0x00114150.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114150));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114150* t = new (mem) TrackFactoryTemplate_114150();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111f50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114190 fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_5 (54 B): matches/0x00114190.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_5() {
    return (void*)(new Cond_114190);
}

namespace fn_f4bd8044 {

// 0x001141d0 fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_2 (43 B): matches/0x001141d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1141d0@fn_f4bd8044@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1141d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e86c;
    base1_dtor_0010ca80();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4bd8044
