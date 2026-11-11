// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00056ba0..0x00056c60 (kind game, layer game, confidence high), dominant class CAxisArcCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faa38447 {
#define TREE_TU_END }
namespace fn_faa38447 {} using namespace fn_faa38447;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_faa38447 {
class TrackFactoryTemplate_56ba0 {
  public:
    TrackFactoryTemplate_56ba0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00052db0();
extern "C" char DAT_003f6ed8[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class CAxisArcCondition_56be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    void Init_00234590(int);
};
extern int hulk_at_003f9028;
struct ConditionFactoryTemplate_56c30 {
    void* m_vptr;
    void base1_dtor_00048890();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_faa38447

// 0x00056ba0 fight::ConditionFactoryCasterTemplate<CAxisArcCondition>::vfunc_1 (60 B): matches/0x00056ba0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCAxisArcCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CAxisArcCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_56ba0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_56ba0* t = new (mem) TrackFactoryTemplate_56ba0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00052db0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00056be0 fight::ConditionFactoryTemplate<CAxisArcCondition>::vfunc_5 (75 B): matches/0x00056be0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCAxisArcCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CAxisArcCondition>::vfunc_5() {
    CAxisArcCondition_56be0* p = (CAxisArcCondition_56be0*)FUN_0008d690((int)sizeof(CAxisArcCondition_56be0));
    if (p) {
        p->Init_00234590(0);
        *(int*)((char*)p + 0xc) = 0;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f6ed8);
        *(int*)((char*)p + 0x18) = 5;
        *(unsigned int*)((char*)p + 0x1c) = 0x3fc90fdb;
        *(int*)((char*)p + 0x10) = 0;
        *(unsigned int*)((char*)p + 0x14) = 0x3f000000;
        return (void*)(p);
    } else {
        return (void*)((CAxisArcCondition_56be0*)0);
    }
}

namespace fn_faa38447 {

// 0x00056c30 fight::ConditionFactoryTemplate<CAxisArcCondition>::vfunc_2 (43 B): matches/0x00056c30.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_56c30@fn_faa38447@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_56c30::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9028;
    base1_dtor_00048890();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_faa38447
