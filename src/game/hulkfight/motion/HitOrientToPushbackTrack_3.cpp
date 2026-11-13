// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159ea0..0x00159f60 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitOrientToPushbackTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5b18566 {
#define TREE_TU_END }
namespace fn_f5b18566 {} using namespace fn_f5b18566;
namespace fn_f5b18566 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5b18566 {
class TrackFactoryTemplate_159ea0 {
  public:
    TrackFactoryTemplate_159ea0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156110();
extern int hulk_at_004157a0;

} // namespace fn_f5b18566

// 0x00159ea0 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_1 (60 B): matches/0x00159ea0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_159ea0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_159ea0* t = new (mem) TrackFactoryTemplate_159ea0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156110();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f5b18566 {

// 0x00159f30 fight::TrackFactoryTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_2 (43 B): matches/0x00159f30.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5b18566@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004157a0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f5b18566
