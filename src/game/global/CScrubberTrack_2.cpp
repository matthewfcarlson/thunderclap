// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077d50..0x00077df0 (kind game, layer game, confidence high), dominant class CScrubberTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcd56763 {
#define TREE_TU_END }
namespace fn_fcd56763 {} using namespace fn_fcd56763;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcd56763 {
class TrackFactoryTemplate_77d50 {
  public:
    TrackFactoryTemplate_77d50() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00074cf0();
extern "C" char DAT_003fba00[];
struct CScrubberTrack_77d90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    void Ctor();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_77dc0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcd56763

// 0x00077d50 fight::TrackFactoryCasterTemplate<CScrubberTrack>::vfunc_1 (60 B): matches/0x00077d50.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCScrubberTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CScrubberTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77d50));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77d50* t = new (mem) TrackFactoryTemplate_77d50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00074cf0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077d90 fight::TrackFactoryTemplate<CScrubberTrack>::vfunc_5 (38 B): matches/0x00077d90.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCScrubberTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CScrubberTrack>::vfunc_5() {
    CScrubberTrack_77d90* p = (CScrubberTrack_77d90*)FUN_0008d690(0x0c);
    if (p) {
        p->Ctor();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fba00);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fcd56763 {

// 0x00077dc0 fight::TrackFactoryTemplate<CScrubberTrack>::vfunc_2 (43 B): matches/0x00077dc0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fcd56763@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_77dc0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcd56763
