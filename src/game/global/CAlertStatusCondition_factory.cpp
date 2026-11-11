// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056af0..0x00056ba0 (kind game, layer game, confidence high), dominant class CAlertStatusCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb5b56c3 {
#define TREE_TU_END }
namespace fn_fb5b56c3 {} using namespace fn_fb5b56c3;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb5b56c3 {
class TrackFactoryTemplate_56af0 {
  public:
    TrackFactoryTemplate_56af0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct InitObj_56b30 {
    void Init(int);
};
struct CAlertStatusCondition_56b30 {
    hulk_intptr a, b, c, d, e;
};
extern int g_vftable_56b70;
struct ConditionFactoryTemplate_56b70 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb5b56c3

// 0x00056af0 fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_1 (60 B): matches/0x00056af0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAlertStatusCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56af0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56af0* t = new (mem) TrackFactoryTemplate_56af0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054240();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00056b30 fight::ConditionFactoryTemplate<CAlertStatusCondition>::vfunc_5 (54 B): matches/0x00056b30.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAlertStatusCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAlertStatusCondition>::vfunc_5() {
    CAlertStatusCondition_56b30* p = (CAlertStatusCondition_56b30*)Alloc(0x14);
    if (p != 0) {
        ((InitObj_56b30*)p)->Init(0);
        p->a = ((hulk_intptr)DAT_003f7404);
        p->d = 0;
        p->e = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fb5b56c3 {

// 0x00056b70 fight::ConditionFactoryTemplate<CAlertStatusCondition>::vfunc_2 (43 B): matches/0x00056b70.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56b70@fn_fb5b56c3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56b70::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_56b70;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb5b56c3
