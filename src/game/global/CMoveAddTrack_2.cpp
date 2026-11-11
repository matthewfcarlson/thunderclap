// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077160..0x00077220 (kind game, layer game, confidence high), dominant class CMoveAddTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4a3352a {
#define TREE_TU_END }
namespace fn_f4a3352a {} using namespace fn_f4a3352a;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4a3352a {
class TrackFactoryTemplate_77160 {
  public:
    TrackFactoryTemplate_77160() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000710c0();
extern "C" char DAT_003fbc24[];
struct CMoveAddTrack_771a0 {
    hulk_intptr vf;
    unsigned int x4;
    unsigned int x8;
    unsigned int xc;
    float x10;
    float x14;
    unsigned int x18;
    void Init_00236d40();
};
extern "C" void* FUN_0008d690(hulk_uintptr);
extern int hulk_at_003fea4c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069970();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4a3352a

// 0x00077160 fight::TrackFactoryCasterTemplate<CMoveAddTrack>::vfunc_1 (60 B): matches/0x00077160.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCMoveAddTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CMoveAddTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77160));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77160* t = new (mem) TrackFactoryTemplate_77160();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000710c0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000771a0 fight::TrackFactoryTemplate<CMoveAddTrack>::vfunc_5 (70 B): matches/0x000771a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCMoveAddTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CMoveAddTrack>::vfunc_5() {
    CMoveAddTrack_771a0* p = (CMoveAddTrack_771a0*)FUN_0008d690((int)sizeof(CMoveAddTrack_771a0));
    if (p != 0) {
        p->Init_00236d40();
        p->x10 = 1.0f;
        p->x14 = 1.0f;
        p->vf = ((hulk_intptr)DAT_003fbc24);
        p->xc = 0;
        p->x18 = 0;
        p->x8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4a3352a {

// 0x000771f0 fight::TrackFactoryTemplate<CMoveAddTrack>::vfunc_2 (43 B): matches/0x000771f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f4a3352a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fea4c;
    base1_dtor_00069970();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4a3352a
