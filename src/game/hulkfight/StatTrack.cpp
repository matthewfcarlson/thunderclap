// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00132eb0..0x00132f60 (kind game, layer game, confidence high), dominant class hulkfight::StatTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f24af925 {
#define TREE_TU_END }
namespace fn_f24af925 {} using namespace fn_f24af925;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f24af925 {
class TrackFactoryTemplate_132eb0 {
  public:
    TrackFactoryTemplate_132eb0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00131d30();
extern int hulk_at_00411b54;

} // namespace fn_f24af925

// 0x00132eb0 fight::TrackFactoryCasterTemplate<hulkfight::StatTrack>::vfunc_1 (60 B): matches/0x00132eb0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VStatTrack@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::StatTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_132eb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_132eb0* t = new (mem) TrackFactoryTemplate_132eb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00131d30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00132ef0 fight::TrackFactoryTemplate<hulkfight::StatTrack>::vfunc_5 (52 B): matches/0x00132ef0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Create@StatTrack@fn_00132ef0@@UAEPAV12@XZ
namespace fn_00132ef0 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Track_132ef0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    Track_132ef0();
};
class StatTrack : public Track_132ef0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual StatTrack* Create();
    StatTrack();
    char pad[8];
    int a;
    int b;
};
StatTrack::StatTrack() : Track_132ef0(), a(0), b(0) {}
StatTrack* StatTrack::Create() {
    StatTrack* p = (StatTrack*)FUN_0008d690((int)sizeof(StatTrack));
    if (p) {
        p->StatTrack::StatTrack();
        return p;
    }
    return 0;
}
} // namespace fn_00132ef0

namespace fn_f24af925 {

// 0x00132f30 fight::TrackFactoryTemplate<hulkfight::StatTrack>::vfunc_2 (43 B): matches/0x00132f30.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f24af925@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00411b54;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f24af925
