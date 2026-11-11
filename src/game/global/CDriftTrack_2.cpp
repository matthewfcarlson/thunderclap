// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000763d0..0x00076490 (kind game, layer game, confidence high), dominant class CDriftTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2b51e98 {
#define TREE_TU_END }
namespace fn_f2b51e98 {} using namespace fn_f2b51e98;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f2b51e98 {
class TrackFactoryTemplate_763d0 {
  public:
    TrackFactoryTemplate_763d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072180();
extern "C" char DAT_003fbfa4[];
struct CDriftTrack_76410 {
    hulk_uintptr vptr;
    unsigned int pad4;
    int field8;
    unsigned int fieldc;
    float field10;
    unsigned int field14;
    float field18;
    void init_00236d40();
};
extern int hulk_at_003fe674;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a7c0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f2b51e98

// 0x000763d0 fight::TrackFactoryCasterTemplate<CDriftTrack>::vfunc_1 (60 B): matches/0x000763d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCDriftTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CDriftTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_763d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_763d0* t = new (mem) TrackFactoryTemplate_763d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072180();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076410 fight::TrackFactoryTemplate<CDriftTrack>::vfunc_5 (73 B): matches/0x00076410.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCDriftTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CDriftTrack>::vfunc_5() {
    CDriftTrack_76410* p = (CDriftTrack_76410*)operator_new(0x1c);
    if (p) {
        p->init_00236d40();
        p->vptr = ((hulk_intptr)DAT_003fbfa4);
        p->fieldc = 0;
        p->field10 = -1.0f;
        p->field14 = 0;
        p->field18 = 1.0f;
        p->field8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f2b51e98 {

// 0x00076460 fight::TrackFactoryTemplate<CDriftTrack>::vfunc_2 (43 B): matches/0x00076460.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f2b51e98@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe674;
    base1_dtor_0006a7c0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f2b51e98
