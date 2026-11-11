// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a5a0..0x0015a650 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff9138b1 {
#define TREE_TU_END }
namespace fn_ff9138b1 {} using namespace fn_ff9138b1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff9138b1 {
class TrackFactoryTemplate_15a5a0 {
  public:
    TrackFactoryTemplate_15a5a0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00158040();
extern "C" char DAT_00414170[];
class Obj_15a5e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern "C" void* __cdecl alloc(hulk_uintptr);
class Temp_15a5e0 {
  public:
    void Init(int);
};
class Tail_15a5e0 {
  public:
    void Init();
};
extern int g_vftable_15a620;
struct ConditionFactoryTemplate_15a620 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff9138b1

// 0x0015a5a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_1 (60 B): matches/0x0015a5a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a5a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_15a5a0* t = new (mem) TrackFactoryTemplate_15a5a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00158040();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_ff9138b1 {

// 0x0015a5e0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_5 (55 B): matches/0x0015a5e0.cpp
// sym: ?Factory_vfunc5@fn_ff9138b1@@YAPAXPAVObj_15a5e0@1@@Z
void* Factory_vfunc5(Obj_15a5e0* self) {
    Obj_15a5e0* p = (Obj_15a5e0*)alloc(0x18);
    if (p) {
        ((Temp_15a5e0*)p)->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414170);
        *(int*)((char*)p + 0xc) = 0;
        ((Tail_15a5e0*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}


// 0x0015a620 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_2 (43 B): matches/0x0015a620.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_15a620@fn_ff9138b1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_15a620::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_15a620;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff9138b1
