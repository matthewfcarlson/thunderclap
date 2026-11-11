// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070110..0x000701a0 (kind game, layer game, confidence high), dominant class CSmartPropRemoveInstanceTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f36db68b {
#define TREE_TU_END }
namespace fn_f36db68b {} using namespace fn_f36db68b;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f36db68b {
class TrackFactoryTemplate_70110 {
  public:
    TrackFactoryTemplate_70110() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00064750();
struct Thing_70150 {
    hulk_intptr init_00062c10();
};
extern int hulk_at_003fd3a4;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062be0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f36db68b

// 0x00070110 fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::vfunc_1 (60 B): matches/0x00070110.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropRemoveInstanceTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70110));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_70110* t = new (mem) TrackFactoryTemplate_70110();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00064750();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070150 fight::TrackFactoryTemplate<CSmartPropRemoveInstanceTrack>::vfunc_5 (24 B): matches/0x00070150.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropRemoveInstanceTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f4f0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropRemoveInstanceTrack>::vfunc_5() {
    Thing_70150* p = (Thing_70150*)operator new(0x14);
    if (p)
        return (void*)(p->init_00062c10());
    return (void*)(0);
}

namespace fn_f36db68b {

// 0x00070170 fight::TrackFactoryTemplate<CSmartPropRemoveInstanceTrack>::vfunc_2 (43 B): matches/0x00070170.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f36db68b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd3a4;
    base1_dtor_00062be0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f36db68b
