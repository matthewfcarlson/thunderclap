// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056af0..0x00056ba0 (kind game, layer game, confidence high), dominant class CAlertStatusCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb5b56c3 {
#define TREE_TU_END }
namespace fn_fb5b56c3 {} using namespace fn_fb5b56c3;
namespace fn_fb5b56c3 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
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
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct InitObj_56b30 {
    void Init_00234590(int);
};
struct CAlertStatusCondition_56b30 {
    hulk_intptr a, b, c, d, e;
};
extern int hulk_at_003f900c;
struct ConditionFactoryTemplate_56b70 {
    void* m_vptr;
    void base1_dtor_0004a470();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb5b56c3

// 0x00056af0 fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_1 (60 B): matches/0x00056af0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAlertStatusCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56af0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
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
        ((InitObj_56b30*)p)->Init_00234590(0);
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
    m_vptr = (void*)&hulk_at_003f900c;
    base1_dtor_0004a470();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fb5b56c3
