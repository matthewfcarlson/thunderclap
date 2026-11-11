// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a3d0..0x0012a480 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fac1b2ca {
#define TREE_TU_END }
namespace fn_fac1b2ca {} using namespace fn_fac1b2ca;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fac1b2ca {
class TrackFactoryTemplate_12a3d0 {
  public:
    TrackFactoryTemplate_12a3d0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128660();
extern "C" void* __cdecl alloc(hulk_uintptr);
class TDC_12a410 {
  public:
    hulk_intptr vf;
    char pad[8];
    int x;
    int y;
    unsigned char a;
    unsigned char b;
    void init_00234590(int);
};
extern int hulk_at_00410988;
struct ConditionFactoryTemplate_12a450 {
    void* m_vptr;
    void base1_dtor_00123c20();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fac1b2ca

// 0x0012a3d0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceCondition>::vfunc_1 (60 B): matches/0x0012a3d0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetDistanceCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a3d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a3d0* t = new (mem) TrackFactoryTemplate_12a3d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128660();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fac1b2ca {

// 0x0012a410 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceCondition>::vfunc_5 (56 B): matches/0x0012a410.cpp
// sym: ?target@fn_fac1b2ca@@YAPAVTDC_12a410@1@XZ
TDC_12a410* __cdecl target() {
    TDC_12a410* p = (TDC_12a410*)alloc(0x18);
    int z = 0;
    if (p) {
        p->init_00234590(z);
        p->x = z;
        p->y = z;
        p->a = (unsigned char)z;
        p->b = (unsigned char)z;
        p->vf = (hulk_intptr)&tdcVtable;
        return p;
    }
    return 0;
}


// 0x0012a450 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceCondition>::vfunc_2 (43 B): matches/0x0012a450.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a450@fn_fac1b2ca@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a450::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410988;
    base1_dtor_00123c20();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fac1b2ca
