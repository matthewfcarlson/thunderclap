// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057d30..0x00057de0 (kind game, layer game, confidence high), dominant class CFightNodePrevCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_febbe3be {
#define TREE_TU_END }
namespace fn_febbe3be {} using namespace fn_febbe3be;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_febbe3be {
class TrackFactoryTemplate_57d30 {
  public:
    TrackFactoryTemplate_57d30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00054660();
extern "C" char DAT_003f74e0[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct Obj_57d70 {
    void Init_00234590(int);
};
struct Tail_57d70 {
    void Init_00233dd0();
};
struct Raw_57d70 {
    hulk_uintptr vptr;
    char pad[8];
    int f;
    char pad2[12];
    unsigned char b;
};
extern int hulk_at_003f9448;
struct ConditionFactoryTemplate_57db0 {
    void* m_vptr;
    void base1_dtor_0004a820();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_febbe3be

// 0x00057d30 fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition>::vfunc_1 (60 B): matches/0x00057d30.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCFightNodePrevCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57d30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57d30* t = new (mem) TrackFactoryTemplate_57d30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00054660();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057d70 fight::ConditionFactoryTemplate<CFightNodePrevCondition>::vfunc_5 (59 B): matches/0x00057d70.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCFightNodePrevCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CFightNodePrevCondition>::vfunc_5() {
    Raw_57d70* p = (Raw_57d70*)FUN_0008d690((int)sizeof(Raw_57d70));
    if (p != 0) {
        ((Obj_57d70*)p)->Init_00234590(0);
        p->vptr = ((hulk_intptr)DAT_003f74e0);
        p->f = 0;
        ((Tail_57d70*)((char*)p + 0x10))->Init_00233dd0();
        p->b = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_febbe3be {

// 0x00057db0 fight::ConditionFactoryTemplate<CFightNodePrevCondition>::vfunc_2 (43 B): matches/0x00057db0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_57db0@fn_febbe3be@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_57db0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9448;
    base1_dtor_0004a820();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_febbe3be
