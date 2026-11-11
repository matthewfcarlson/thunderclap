// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077c30..0x00077cc0 (kind game, layer game, confidence high), dominant class CJointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0575914 {
#define TREE_TU_END }
namespace fn_f0575914 {} using namespace fn_f0575914;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f0575914 {
class TrackFactoryTemplate_77c30 {
  public:
    TrackFactoryTemplate_77c30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00074ab0();
extern int hulk_at_003fec68;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00068cc0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
typedef unsigned int u32_77ca0;
struct CGrabTrack_77ca0 {
    hulk_uintptr init_0006b410();
};

} // namespace fn_f0575914

// 0x00077c30 fight::TrackFactoryCasterTemplate<CJointTrack>::vfunc_1 (60 B): matches/0x00077c30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCJointTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CJointTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77c30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77c30* t = new (mem) TrackFactoryTemplate_77c30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00074ab0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f0575914 {

// 0x00077c70 fight::TrackFactoryTemplate<CJointTrack>::vfunc_2 (43 B): matches/0x00077c70.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f0575914@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fec68;
    base1_dtor_00068cc0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f0575914

// 0x00077ca0 fight::TrackFactoryTemplate<CJointTrack>::vfunc_5 (24 B): matches/0x00077ca0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCJointTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CJointTrack>::vfunc_5() {
    CGrabTrack_77ca0* p = (CGrabTrack_77ca0*)operator_new(0x50);
    if (p)
        return (void*)(p->init_0006b410());
    return (void*)(0);
}

