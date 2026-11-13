// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070470..0x00070500 (kind game, layer game, confidence high), dominant class CSnapToWallTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f19ab246 {
#define TREE_TU_END }
namespace fn_f19ab246 {} using namespace fn_f19ab246;
namespace fn_f19ab246 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f19ab246 {
class TrackFactoryTemplate_70470 {
  public:
    TrackFactoryTemplate_70470() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005ed90();
extern "C" hulk_intptr __fastcall Construct(void*);
extern int hulk_at_003fd44c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005dee0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f19ab246

// 0x00070470 fight::TrackFactoryCasterTemplate<CSnapToWallTrack>::vfunc_1 (60 B): matches/0x00070470.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSnapToWallTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSnapToWallTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70470));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_70470* t = new (mem) TrackFactoryTemplate_70470();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005ed90();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000704b0 fight::TrackFactoryTemplate<CSnapToWallTrack>::vfunc_5 (24 B): matches/0x000704b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSnapToWallTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CSnapToWallTrack>::vfunc_5() {
    void* p = operator_new(0x34);
    if (p)
        return (void*)(Construct(p));
    return (void*)(0);
}

namespace fn_f19ab246 {

// 0x000704d0 fight::TrackFactoryTemplate<CSnapToWallTrack>::vfunc_2 (43 B): matches/0x000704d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f19ab246@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd44c;
    base1_dtor_0005dee0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f19ab246
