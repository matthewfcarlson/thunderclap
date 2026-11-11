// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056c60..0x00056d10 (kind game, layer game, confidence high), dominant class CAxisDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff557179 {
#define TREE_TU_END }
namespace fn_ff557179 {} using namespace fn_ff557179;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff557179 {
class TrackFactoryTemplate_56c60 {
  public:
    TrackFactoryTemplate_56c60() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053080();
extern "C" char DAT_003f6f34[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct CAxisDirectionCondition_56ca0 {
    hulk_intptr vt;
    void Init_00234590(int);
    char pad[8];
    int a;
    int b;
    int c;
};
extern int hulk_at_003f9044;
struct ConditionFactoryTemplate_56ce0 {
    void* m_vptr;
    void base1_dtor_00048990();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff557179

// 0x00056c60 fight::ConditionFactoryCasterTemplate<CAxisDirectionCondition>::vfunc_1 (60 B): matches/0x00056c60.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisDirectionCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisDirectionCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56c60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56c60* t = new (mem) TrackFactoryTemplate_56c60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053080();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00056ca0 fight::ConditionFactoryTemplate<CAxisDirectionCondition>::vfunc_5 (61 B): matches/0x00056ca0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisDirectionCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisDirectionCondition>::vfunc_5() {
    CAxisDirectionCondition_56ca0* p = (CAxisDirectionCondition_56ca0*)FUN_0008d690((int)sizeof(CAxisDirectionCondition_56ca0));
    if (p) {
        p->Init_00234590(0);
        p->vt = ((hulk_intptr)DAT_003f6f34);
        p->a = 0;
        p->b = 0;
        p->c = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff557179 {

// 0x00056ce0 fight::ConditionFactoryTemplate<CAxisDirectionCondition>::vfunc_2 (43 B): matches/0x00056ce0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56ce0@fn_ff557179@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56ce0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9044;
    base1_dtor_00048990();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff557179
