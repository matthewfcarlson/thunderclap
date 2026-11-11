// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000770a0..0x00077160 (kind game, layer game, confidence high), dominant class CMoveTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9897173 {
#define TREE_TU_END }
namespace fn_f9897173 {} using namespace fn_f9897173;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9897173 {
class TrackFactoryTemplate_770a0 {
  public:
    TrackFactoryTemplate_770a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00070f20();
extern "C" char DAT_003fbbe8[];
class CMoveTrack_770e0 {
  public:
    void Init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fea30;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069880();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f9897173

// 0x000770a0 fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_1 (60 B): matches/0x000770a0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCMoveTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_770a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_770a0* t = new (mem) TrackFactoryTemplate_770a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00070f20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000770e0 fight::TrackFactoryTemplate<CMoveTrack>::vfunc_5 (80 B): matches/0x000770e0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCMoveTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CMoveTrack>::vfunc_5() {
    CMoveTrack_770e0* p = (CMoveTrack_770e0*)FUN_0008d690(0x28);
    if (p) {
        p->Init_00236d40();
        *(int*)((char*)p + 0x0c) = 0;
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(float*)((char*)p + 0x10) = 1.0f;
        *(float*)((char*)p + 0x14) = 1.0f;
        *(hulk_intptr*)((char*)p) = ((hulk_intptr)DAT_003fbbe8);
        *(int*)((char*)p + 0x1c) = -1;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f9897173 {

// 0x00077130 fight::TrackFactoryTemplate<CMoveTrack>::vfunc_2 (43 B): matches/0x00077130.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f9897173@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fea30;
    base1_dtor_00069880();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9897173
