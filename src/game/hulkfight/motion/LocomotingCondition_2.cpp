// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00164d70..0x00164e10 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotingCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd5e66b9 {
#define TREE_TU_END }
namespace fn_fd5e66b9 {} using namespace fn_fd5e66b9;
namespace fn_fd5e66b9 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd5e66b9 {
class TrackFactoryTemplate_164d70 {
  public:
    TrackFactoryTemplate_164d70() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00161280();
extern "C" char DAT_00415950[];
class Entity_164db0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Factory_164db0 : public Entity_164db0 {
    char pad[12];
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Init_164db0 {
  public:
    void InitIt_00234590(int);
};
extern int hulk_at_00416494;
struct ConditionFactoryTemplate_164de0 {
    void* m_vptr;
    void base1_dtor_0015b760();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd5e66b9

// 0x00164d70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition>::vfunc_1 (60 B): matches/0x00164d70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VLocomotingCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_164d70));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_164d70* t = new (mem) TrackFactoryTemplate_164d70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00161280();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00164db0 fight::ConditionFactoryTemplate<hulkfight::motion::LocomotingCondition>::vfunc_5 (44 B): matches/0x00164db0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VLocomotingCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::LocomotingCondition>::vfunc_5() {
    Init_164db0* p = (Init_164db0*)FUN_0008d690(0x10);
    if (p) {
        p->InitIt_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_00415950);
        *((char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd5e66b9 {

// 0x00164de0 fight::ConditionFactoryTemplate<hulkfight::motion::LocomotingCondition>::vfunc_2 (43 B): matches/0x00164de0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_164de0@fn_fd5e66b9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_164de0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00416494;
    base1_dtor_0015b760();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd5e66b9
