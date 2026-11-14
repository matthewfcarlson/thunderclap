// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001595a0..0x00159640 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceIsMissileCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f966cbed {
#define TREE_TU_END }
namespace fn_f966cbed {} using namespace fn_f966cbed;
namespace fn_f966cbed {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f966cbed {
class TrackFactoryTemplate_1595a0 {
  public:
    TrackFactoryTemplate_1595a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155680();
} // namespace fn_f966cbed
void* operator new(size_t) HULK_NEW_THROW;
namespace hulkfight { namespace motion {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    BaseCondition(int);
};
} }
namespace hulkfight { namespace motion {
class CollisionSourceIsMissileCondition_1595e0 : public BaseCondition {
  public:
    CollisionSourceIsMissileCondition_1595e0() : BaseCondition(0) { flag = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    char flag;
};
} }
namespace fn_f966cbed {
extern int hulk_at_00415634;
struct ConditionFactoryTemplate_159610 {
    void* m_vptr;
    void base1_dtor_0014d670();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f966cbed

// 0x001595a0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_1 (60 B): matches/0x001595a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionSourceIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1595a0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_1595a0* t = new (mem) TrackFactoryTemplate_1595a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155680();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001595e0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_5 (44 B): matches/0x001595e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionSourceIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::CollisionSourceIsMissileCondition_1595e0);
}

namespace fn_f966cbed {

// 0x00159610 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_2 (43 B): matches/0x00159610.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159610@fn_f966cbed@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159610::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415634;
    base1_dtor_0014d670();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f966cbed
