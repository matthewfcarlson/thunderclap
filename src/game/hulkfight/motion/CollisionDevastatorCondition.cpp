// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159310..0x001593b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionDevastatorCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0fe9045 {
#define TREE_TU_END }
namespace fn_f0fe9045 {} using namespace fn_f0fe9045;
namespace fn_f0fe9045 {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0fe9045 {
class TrackFactoryTemplate_159310 {
  public:
    TrackFactoryTemplate_159310() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001554a0();
extern "C" char DAT_00414030[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CollisionDevastatorCondition_159350 {
  public:
    hulk_intptr vptr;
    char pad[8];
    char flag;
    CollisionDevastatorCondition_159350(int);
};
extern int hulk_at_004155c4;
struct ConditionFactoryTemplate_159380 {
    void* m_vptr;
    void base1_dtor_0014d4e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f0fe9045

// 0x00159310 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_1 (60 B): matches/0x00159310.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159310));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_159310* t = new (mem) TrackFactoryTemplate_159310();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001554a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00159350 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_5 (44 B): matches/0x00159350.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_5() {
    CollisionDevastatorCondition_159350* p = (CollisionDevastatorCondition_159350*)FUN_0008d690((int)sizeof(CollisionDevastatorCondition_159350));
    if (p) {
        p->CollisionDevastatorCondition_159350::CollisionDevastatorCondition_159350(0);
        p->vptr = ((hulk_intptr)DAT_00414030);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0fe9045 {

// 0x00159380 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_2 (43 B): matches/0x00159380.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159380@fn_f0fe9045@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159380::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004155c4;
    base1_dtor_0014d4e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f0fe9045
