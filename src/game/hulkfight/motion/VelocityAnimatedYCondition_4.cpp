// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016da20..0x0016dad0 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f808ce35 {
#define TREE_TU_END }
namespace fn_f808ce35 {} using namespace fn_f808ce35;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f808ce35 {
class TrackFactoryTemplate_16da20 {
  public:
    TrackFactoryTemplate_16da20() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b5a0();
extern "C" char DAT_004167f8[];
class ConditionFactory_16da60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
} // namespace fn_f808ce35
namespace hulkfight { namespace motion {
class VelocityAnimatedYCondition_16da60 {
  public:
    void Init(int);
    hulk_intptr vptr;
    int m4;
    int m8;
    int mC;
    int m10;
};
} }
namespace fn_f808ce35 {
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_16daa0;
struct ConditionFactoryTemplate_16daa0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f808ce35

// 0x0016da20 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_1 (60 B): matches/0x0016da20.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16da20));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16da20* t = new (mem) TrackFactoryTemplate_16da20();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b5a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016da60 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_5 (54 B): matches/0x0016da60.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_5() {
    hulkfight::motion::VelocityAnimatedYCondition_16da60* p =
        (hulkfight::motion::VelocityAnimatedYCondition_16da60*)FUN_0008d690((int)sizeof(hulkfight::motion::VelocityAnimatedYCondition_16da60));
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_004167f8);
        p->mC = 0;
        p->m10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f808ce35 {

// 0x0016daa0 fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_2 (43 B): matches/0x0016daa0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16daa0@fn_f808ce35@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16daa0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_16daa0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f808ce35
