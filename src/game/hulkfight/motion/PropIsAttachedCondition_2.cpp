// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018b960..0x0018ba10 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropIsAttachedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5ef234b {
#define TREE_TU_END }
namespace fn_f5ef234b {} using namespace fn_f5ef234b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5ef234b {
class TrackFactoryTemplate_18b960 {
  public:
    TrackFactoryTemplate_18b960() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187a20();
typedef unsigned int u32_18b9a0;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct InitObj_18b9a0 {
    void init(int);
};
extern int vtable_18b9a0;
extern int g_vftable_18b9e0;
struct ConditionFactoryTemplate_18b9e0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5ef234b

// 0x0018b960 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_1 (60 B): matches/0x0018b960.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18b960));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18b960* t = new (mem) TrackFactoryTemplate_18b960();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187a20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018b9a0 fight::ConditionFactoryTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_5 (51 B): matches/0x0018b9a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0018b6f0 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x14);
    if (p) {
        ((InitObj_18b9a0*)p)->init(0);
        *(hulk_uintptr*)p = (hulk_uintptr)&vtable_18b9a0;
        *(u32_18b9a0*)(p + 0xc) = 0xffffffff;
        p[0x10] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5ef234b {

// 0x0018b9e0 fight::ConditionFactoryTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_2 (43 B): matches/0x0018b9e0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_18b9e0@fn_f5ef234b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_18b9e0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18b9e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5ef234b
