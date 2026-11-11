// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f930..0x0006f9f0 (kind game, layer game, confidence high), dominant class CGrappleSmartPropDropTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc2e3ce6 {
#define TREE_TU_END }
namespace fn_fc2e3ce6 {} using namespace fn_fc2e3ce6;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc2e3ce6 {
class TrackFactoryTemplate_6f930 {
  public:
    TrackFactoryTemplate_6f930() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fd17c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062a50();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
struct CFightNodeTimeCondition_6f9a0 {
    virtual ~CFightNodeTimeCondition_6f9a0();
    char pad[0x10];
    void Initialize_00062a80();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_fc2e3ce6

// 0x0006f930 fight::TrackFactoryCasterTemplate<CGrappleSmartPropDropTrack>::vfunc_1 (60 B): matches/0x0006f930.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleSmartPropDropTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleSmartPropDropTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f930));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_6f930* t = new (mem) TrackFactoryTemplate_6f930();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000645c0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc2e3ce6 {

// 0x0006f970 fight::TrackFactoryTemplate<CGrappleSmartPropDropTrack>::vfunc_2 (43 B): matches/0x0006f970.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc2e3ce6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd17c;
    base1_dtor_00062a50();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc2e3ce6

// 0x0006f9a0 fight::TrackFactoryTemplate<CGrappleSmartPropDropTrack>::vfunc_5 (38 B): matches/0x0006f9a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleSmartPropDropTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x000521a0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CGrappleSmartPropDropTrack>::vfunc_5() {
    CFightNodeTimeCondition_6f9a0* p = (CFightNodeTimeCondition_6f9a0*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_6f9a0));
    if (p) {
        p->Initialize_00062a80();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0006f9d0 CGrappleSmartPropDropTrack::vfunc_5 (30 B): matches/0x0006f9d0.cpp
// sym: ??_GCGrappleSmartPropDropTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrappleSmartPropDropTrack::~CGrappleSmartPropDropTrack() {}

