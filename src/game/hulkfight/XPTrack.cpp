// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00132f60..0x00133010 (kind game, layer game, confidence high), dominant class hulkfight::XPTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa572e86 {
#define TREE_TU_END }
namespace fn_fa572e86 {} using namespace fn_fa572e86;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fa572e86 {
class TrackFactoryTemplate_132f60 {
  public:
    TrackFactoryTemplate_132f60() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00131dd0();
extern int g_vftable_132fe0;

} // namespace fn_fa572e86

// 0x00132f60 fight::TrackFactoryCasterTemplate<hulkfight::XPTrack>::vfunc_1 (60 B): matches/0x00132f60.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VXPTrack@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::XPTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_132f60));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_132f60* t = new (mem) TrackFactoryTemplate_132f60();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00131dd0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00132fa0 fight::TrackFactoryTemplate<hulkfight::XPTrack>::vfunc_5 (52 B): matches/0x00132fa0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@TrackFactoryTemplate@fight@fn_00132fa0@@UAEPAVXPTrack@hulkfight@3@XZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_00132fa0 {
/* size_t: tree_prelude.h */

namespace hulkfight {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[8];
};
class XPTrack : public BaseTrack {
  public:
    XPTrack() throw();
    virtual void v0();
    int a, b;
};
XPTrack::XPTrack() throw() : BaseTrack(), a(0), b(0) {}
} // namespace hulkfight
namespace fight {
class TrackFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::XPTrack* vfunc_5();
};
hulkfight::XPTrack* TrackFactoryTemplate::vfunc_5() {
    return new hulkfight::XPTrack;
}
} // namespace fight
} // namespace fn_00132fa0

namespace fn_fa572e86 {

// 0x00132fe0 fight::TrackFactoryTemplate<hulkfight::XPTrack>::vfunc_2 (43 B): matches/0x00132fe0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fa572e86@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_132fe0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fa572e86
