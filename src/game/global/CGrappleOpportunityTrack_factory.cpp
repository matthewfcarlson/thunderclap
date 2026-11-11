// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f810..0x0006f8a0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f56dbf80 {
#define TREE_TU_END }
namespace fn_f56dbf80 {} using namespace fn_f56dbf80;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f56dbf80 {
class TrackFactoryTemplate_6f810 {
  public:
    TrackFactoryTemplate_6f810() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005c320();
typedef unsigned int u32_6f850;
struct Grapple_6f850 {
    hulk_uintptr ctor_0005ad00();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_003fd144;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005acd0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f56dbf80

// 0x0006f810 fight::TrackFactoryCasterTemplate<CGrappleOpportunityTrack>::vfunc_1 (60 B): matches/0x0006f810.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleOpportunityTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleOpportunityTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f810));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f810* t = new (mem) TrackFactoryTemplate_6f810();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005c320();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f850 fight::TrackFactoryTemplate<CGrappleOpportunityTrack>::vfunc_5 (24 B): matches/0x0006f850.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleOpportunityTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CGrappleOpportunityTrack>::vfunc_5() {
    Grapple_6f850* p = (Grapple_6f850*)FUN_0008d690(0x2c);
    if (p)
        return (void*)(p->ctor_0005ad00());
    return (void*)(0);
}

namespace fn_f56dbf80 {

// 0x0006f870 fight::TrackFactoryTemplate<CGrappleOpportunityTrack>::vfunc_2 (43 B): matches/0x0006f870.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f56dbf80@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd144;
    base1_dtor_0005acd0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f56dbf80
