// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00058300..0x000583b0 (kind game, layer game, confidence high), dominant class CLuaNumberCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff8b2601 {
#define TREE_TU_END }
namespace fn_ff8b2601 {} using namespace fn_ff8b2601;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff8b2601 {
class TrackFactoryTemplate_58300 {
  public:
    TrackFactoryTemplate_58300() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053ef0();
extern "C" char DAT_003f7304[];
struct CLuaNumberCondition_58340 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f9578;
struct ConditionFactoryTemplate_58380 {
    void* m_vptr;
    void base1_dtor_00049e60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff8b2601

// 0x00058300 fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>::vfunc_1 (60 B): matches/0x00058300.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCLuaNumberCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_58300));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_58300* t = new (mem) TrackFactoryTemplate_58300();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053ef0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00058340 fight::ConditionFactoryTemplate<CLuaNumberCondition>::vfunc_5 (58 B): matches/0x00058340.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCLuaNumberCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CLuaNumberCondition>::vfunc_5() {
    CLuaNumberCondition_58340* p = (CLuaNumberCondition_58340*)FUN_0008d690(0x54);
    if (p) {
        p->init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7304);
        *(unsigned int*)((char*)p + 0xc) = 2;
        *(unsigned int*)((char*)p + 0x50) = 0;
        *((unsigned char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff8b2601 {

// 0x00058380 fight::ConditionFactoryTemplate<CLuaNumberCondition>::vfunc_2 (43 B): matches/0x00058380.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58380@fn_ff8b2601@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58380::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9578;
    base1_dtor_00049e60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff8b2601
