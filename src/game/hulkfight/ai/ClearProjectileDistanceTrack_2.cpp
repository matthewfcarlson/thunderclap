// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b010..0x0012b0c0 (kind game, layer game, confidence high), dominant class hulkfight::ai::ClearProjectileDistanceTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c9fc87 {
#define TREE_TU_END }
namespace fn_f9c9fc87 {} using namespace fn_f9c9fc87;
namespace fn_f9c9fc87 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9c9fc87 {
class TrackFactoryTemplate_12b010 {
  public:
    TrackFactoryTemplate_12b010() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129480();
extern int hulk_at_00410b80;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00124410();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f9c9fc87

// 0x0012b010 fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_1 (60 B): matches/0x0012b010.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12b010));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_12b010* t = new (mem) TrackFactoryTemplate_12b010();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129480();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012b050 fight::TrackFactoryTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_5 (63 B): matches/0x0012b050.cpp [wrapped: conflict: fight::Track; fight::TrackFactory]
// sym: ?vfunc_5@Factory@fn_0012b050@@UAEPAVTrack@fight@2@XZ
void* operator new(size_t);
namespace fn_0012b050 {
/* size_t: tree_prelude.h */

namespace fight {
class Track {
  public:
    virtual void f();
    Track() throw();
    char pad[4];
    int count;
};
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Track* vfunc_5();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class ClearProjectileDistanceTrack : public fight::Track {
  public:
    virtual void f();
    ClearProjectileDistanceTrack() throw();
    int unused;
    float distance;
    char flag;
};
} // namespace ai
} // namespace hulkfight
inline hulkfight::ai::ClearProjectileDistanceTrack::ClearProjectileDistanceTrack() throw()
    : unused(0), distance(-1.0f), flag(0) {}
class Factory : public fight::TrackFactory {
  public:
    virtual fight::Track* vfunc_5();
};
fight::Track* Factory::vfunc_5() {
    hulkfight::ai::ClearProjectileDistanceTrack* p = new hulkfight::ai::ClearProjectileDistanceTrack;
    if (p)
        p->count = 1;
    return p;
}
} // namespace fn_0012b050

namespace fn_f9c9fc87 {

// 0x0012b090 fight::TrackFactoryTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_2 (43 B): matches/0x0012b090.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f9c9fc87@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410b80;
    base1_dtor_00124410();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f9c9fc87
