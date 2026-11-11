// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057f80..0x00058030 (kind game, layer game, confidence high), dominant class CGrappleSizeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5af57eb {
#define TREE_TU_END }
namespace fn_f5af57eb {} using namespace fn_f5af57eb;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5af57eb {
class TrackFactoryTemplate_57f80 {
  public:
    TrackFactoryTemplate_57f80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00053e30();
extern "C" char DAT_003f72e0[];
class AllocObj_57fc0 {
  public:
    void Init_00234590(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003f94ec;
struct ConditionFactoryTemplate_58000 {
    void* m_vptr;
    void base1_dtor_00049d70();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5af57eb

// 0x00057f80 fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>::vfunc_1 (60 B): matches/0x00057f80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCGrappleSizeCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57f80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57f80* t = new (mem) TrackFactoryTemplate_57f80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00053e30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00057fc0 fight::ConditionFactoryTemplate<CGrappleSizeCondition>::vfunc_5 (54 B): matches/0x00057fc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCGrappleSizeCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CGrappleSizeCondition>::vfunc_5() {
    AllocObj_57fc0* p = (AllocObj_57fc0*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_003f72e0);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5af57eb {

// 0x00058000 fight::ConditionFactoryTemplate<CGrappleSizeCondition>::vfunc_2 (43 B): matches/0x00058000.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_58000@fn_f5af57eb@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_58000::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f94ec;
    base1_dtor_00049d70();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5af57eb
