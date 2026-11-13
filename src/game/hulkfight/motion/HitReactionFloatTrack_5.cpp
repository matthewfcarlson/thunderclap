// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a700..0x0015a790 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionFloatTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7a21593 {
#define TREE_TU_END }
namespace fn_f7a21593 {} using namespace fn_f7a21593;
namespace fn_f7a21593 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f7a21593 {
class TrackFactoryTemplate_15a700 {
  public:
    TrackFactoryTemplate_15a700() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001582f0();
struct TrackFactory_15a740 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_15a740 {
    void* init_0014dca0();
};
extern int hulk_at_004158f0;

} // namespace fn_f7a21593

// 0x0015a700 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_1 (60 B): matches/0x0015a700.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a700));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_15a700* t = new (mem) TrackFactoryTemplate_15a700();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001582f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0015a740 fight::TrackFactoryTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_5 (24 B): matches/0x0015a740.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0013e710 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_15a740*)p)->init_0014dca0());
    return (void*)(0);
}

namespace fn_f7a21593 {

// 0x0015a760 fight::TrackFactoryTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_2 (43 B): matches/0x0015a760.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f7a21593@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004158f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f7a21593
