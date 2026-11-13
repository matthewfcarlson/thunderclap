// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a9f0..0x0012aaa0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f06bc341 {
#define TREE_TU_END }
namespace fn_f06bc341 {} using namespace fn_f06bc341;
namespace fn_f06bc341 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f06bc341 {
class TrackFactoryTemplate_12a9f0 {
  public:
    TrackFactoryTemplate_12a9f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128db0();
extern "C" void* __cdecl alloc(hulk_uintptr);
class TDC_12aa30 {
  public:
    hulk_intptr vf;
    char pad[8];
    int x;
    int y;
    unsigned char a;
    unsigned char b;
    void init_00234590(int);
};
extern int hulk_at_00410a84;
struct ConditionFactoryTemplate_12aa70 {
    void* m_vptr;
    void base1_dtor_00124000();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f06bc341

// 0x0012a9f0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_1 (60 B): matches/0x0012a9f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a9f0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_12a9f0* t = new (mem) TrackFactoryTemplate_12a9f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128db0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f06bc341 {

// 0x0012aa30 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_5 (56 B): matches/0x0012aa30.cpp
// sym: ?target@fn_f06bc341@@YAPAVTDC_12aa30@1@XZ
// Same code shape as 0x0012a410 (propagated; names are from that function)
TDC_12aa30* __cdecl target() {
    TDC_12aa30* p = (TDC_12aa30*)alloc(0x18);
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


// 0x0012aa70 fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2 (43 B): matches/0x0012aa70.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12aa70@fn_f06bc341@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12aa70::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410a84;
    base1_dtor_00124000();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f06bc341
