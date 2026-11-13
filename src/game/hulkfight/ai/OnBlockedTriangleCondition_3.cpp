// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00113d50..0x00113e00 (kind game, layer game, confidence high), dominant class hulkfight::ai::OnBlockedTriangleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe36cded {
#define TREE_TU_END }
namespace fn_fe36cded {} using namespace fn_fe36cded;
namespace fn_fe36cded {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe36cded {
class TrackFactoryTemplate_113d50 {
  public:
    TrackFactoryTemplate_113d50() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00111b50();
extern "C" char DAT_0040d984[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Condition_113d90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[0x14];
};
class Base_113d90 {
  public:
    void Init_00234590(int);
};
extern int hulk_at_0040e7c4;
struct ConditionFactoryTemplate_113dd0 {
    void* m_vptr;
    void base1_dtor_0010c710();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe36cded

// 0x00113d50 fight::ConditionFactoryCasterTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_1 (60 B): matches/0x00113d50.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_113d50));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_113d50* t = new (mem) TrackFactoryTemplate_113d50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00111b50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00113d90 fight::ConditionFactoryTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_5 (58 B): matches/0x00113d90.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_5() {
    Condition_113d90* p = (Condition_113d90*)FUN_0008d690((int)sizeof(Condition_113d90));
    if (p) {
        ((Base_113d90*)p)->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040d984);
        *(uint*)((char*)p + 0xc) = 0;
        *((char*)p + 0x10) = 0;
        *(uint*)((char*)p + 0x14) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe36cded {

// 0x00113dd0 fight::ConditionFactoryTemplate<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2 (43 B): matches/0x00113dd0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_113dd0@fn_fe36cded@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_113dd0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e7c4;
    base1_dtor_0010c710();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe36cded
