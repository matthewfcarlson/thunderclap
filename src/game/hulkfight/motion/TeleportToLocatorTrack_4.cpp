// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017ebc0..0x0017ec80 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportToLocatorTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fee0a622 {
#define TREE_TU_END }
namespace fn_fee0a622 {} using namespace fn_fee0a622;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fee0a622 {
class TrackFactoryTemplate_17ebc0 {
  public:
    TrackFactoryTemplate_17ebc0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ad20();
} // namespace fn_fee0a622
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fee0a622 {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[4];
    int ref;
};
class MidTrack : public BaseTrack {
  public:
    MidTrack() throw() : a(0), b(0) {}
    int a, b;
};
struct Values {
    Values() throw() {
        _ReadWriteBarrier();
        c = 0;
        d = 0;
        f = -1.0f;
    }
    int c, d;
    float f;
};
class TeleportToLocatorTrack_17ec00 : public MidTrack {
  public:
    TeleportToLocatorTrack_17ec00() throw() { ref = 1; }
    virtual void v0();
    Values v;
};
class TrackFactory_17ec00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BaseTrack* vfunc_5();
};
extern int hulk_at_00418fa0;

} // namespace fn_fee0a622

// 0x0017ebc0 fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_1 (60 B): matches/0x0017ebc0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17ebc0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17ebc0* t = new (mem) TrackFactoryTemplate_17ebc0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ad20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017ec00 fight::TrackFactoryTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_5 (69 B): matches/0x0017ec00.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_5() {
    return (void*)(new TeleportToLocatorTrack_17ec00);
}

namespace fn_fee0a622 {

// 0x0017ec50 fight::TrackFactoryTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2 (43 B): matches/0x0017ec50.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fee0a622@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418fa0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fee0a622
