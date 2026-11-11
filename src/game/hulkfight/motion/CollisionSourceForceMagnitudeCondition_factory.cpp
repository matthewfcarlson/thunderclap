// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00158fb0..0x00159060 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceForceMagnitudeCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb46c098 {
#define TREE_TU_END }
namespace fn_fb46c098 {} using namespace fn_fb46c098;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb46c098 {
class TrackFactoryTemplate_158fb0 {
  public:
    TrackFactoryTemplate_158fb0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00155160();
extern int g_vftable_159030;
struct ConditionFactoryTemplate_159030 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb46c098

// 0x00158fb0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_1 (60 B): matches/0x00158fb0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_158fb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_158fb0* t = new (mem) TrackFactoryTemplate_158fb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00155160();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00158ff0 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_5 (54 B): matches/0x00158ff0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@fn_00158ff0@@@fight@fn_00158ff0@@UAEPAXXZ
void* operator new(size_t);
namespace fn_00158ff0 {
/* size_t: tree_prelude.h */

namespace hulkfight {
namespace motion {
class Base {
  public:
    virtual void a();
    int x;
    int y;
    Base(int) throw();
};
class CollisionSourceForceMagnitudeCondition : public Base {
  public:
    CollisionSourceForceMagnitudeCondition() throw();
    virtual void a();
    int val1;
    int val2;
};
CollisionSourceForceMagnitudeCondition::CollisionSourceForceMagnitudeCondition() throw()
    : Base(0), val1(0), val2(0) {}
} // namespace motion
} // namespace hulkfight
namespace fight {
class ConditionFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
template <class T> class ConditionFactoryTemplate : public ConditionFactory {
  public:
    virtual void* vfunc_5();
};
template <>
void* ConditionFactoryTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_5() {
    return new hulkfight::motion::CollisionSourceForceMagnitudeCondition();
}
} // namespace fight
} // namespace fn_00158ff0

namespace fn_fb46c098 {

// 0x00159030 fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_2 (43 B): matches/0x00159030.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_159030@fn_fb46c098@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_159030::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_159030;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb46c098
