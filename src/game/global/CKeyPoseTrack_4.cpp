// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077cc0..0x00077d50 (kind game, layer game, confidence high), dominant class CKeyPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc7b27ca {
#define TREE_TU_END }
namespace fn_fc7b27ca {} using namespace fn_fc7b27ca;
namespace fn_fc7b27ca {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc7b27ca {
class TrackFactoryTemplate_77cc0 {
  public:
    TrackFactoryTemplate_77cc0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_77d00;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CKeyPoseTrack_77d00 {
    hulk_uintptr init_00069520();
};
extern int hulk_at_003fec84;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000694f0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc7b27ca

// 0x00077cc0 fight::TrackFactoryCasterTemplate<CKeyPoseTrack>::vfunc_1 (60 B): matches/0x00077cc0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCKeyPoseTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CKeyPoseTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77cc0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_77cc0* t = new (mem) TrackFactoryTemplate_77cc0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00074d90();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077d00 fight::TrackFactoryTemplate<CKeyPoseTrack>::vfunc_5 (24 B): matches/0x00077d00.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCKeyPoseTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CKeyPoseTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x78);
    if (p)
        return (void*)(((CKeyPoseTrack_77d00*)p)->init_00069520());
    return (void*)(0);
}

namespace fn_fc7b27ca {

// 0x00077d20 fight::TrackFactoryTemplate<CKeyPoseTrack>::vfunc_2 (43 B): matches/0x00077d20.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc7b27ca@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fec84;
    base1_dtor_000694f0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fc7b27ca
