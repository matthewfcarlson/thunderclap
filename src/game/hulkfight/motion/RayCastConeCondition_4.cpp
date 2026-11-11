// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e5b0..0x0016e670 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastConeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7bcb175 {
#define TREE_TU_END }
namespace fn_f7bcb175 {} using namespace fn_f7bcb175;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f7bcb175 {
class TrackFactoryTemplate_16e5b0 {
  public:
    TrackFactoryTemplate_16e5b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016c830();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern char hulk_at_004167b8[];
struct Sub0_16e5f0 {
    void Init_00234590(int);
};
struct Sub1_16e5f0 {
    void Init_0027af00();
};
struct Obj_16e5f0 {
    void* vptr;
    char pad[0x18 - 4];
    int a, b, c;
    float d;
    int e, f;
    u8 flag;
};
extern int hulk_at_00417808;
struct ConditionFactoryTemplate_16e640 {
    void* m_vptr;
    void base1_dtor_00165f10();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f7bcb175

// 0x0016e5b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_1 (60 B): matches/0x0016e5b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16e5b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16e5b0* t = new (mem) TrackFactoryTemplate_16e5b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016c830();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016e5f0 fight::ConditionFactoryTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_5 (78 B): matches/0x0016e5f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_5() {
    Obj_16e5f0* p = (Obj_16e5f0*)FUN_0008d690(0x38);
    if (p) {
        ((Sub0_16e5f0*)p)->Init_00234590(0);
        p->vptr = (void*)hulk_at_004167b8;
        ((Sub1_16e5f0*)((char*)p + 0x10))->Init_0027af00();
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->e = 0;
        p->f = 0;
        p->d = 1.0f;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f7bcb175 {

// 0x0016e640 fight::ConditionFactoryTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_2 (43 B): matches/0x0016e640.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16e640@fn_f7bcb175@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16e640::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00417808;
    base1_dtor_00165f10();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f7bcb175
