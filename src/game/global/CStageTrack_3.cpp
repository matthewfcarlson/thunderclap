// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000775e0..0x00077690 (kind game, layer game, confidence high), dominant class CStageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbee1db8 {
#define TREE_TU_END }
namespace fn_fbee1db8 {} using namespace fn_fbee1db8;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbee1db8 {
class TrackFactoryTemplate_775e0 {
  public:
    TrackFactoryTemplate_775e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000724f0();
extern "C" char DAT_003fc094[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class CStageTrack_77620 {
  public:
    void Init_00236d40();
};
extern int hulk_at_003feb30;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006ab20();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbee1db8

// 0x000775e0 fight::TrackFactoryCasterTemplate<CStageTrack>::vfunc_1 (60 B): matches/0x000775e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCStageTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CStageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_775e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_775e0* t = new (mem) TrackFactoryTemplate_775e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000724f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077620 fight::TrackFactoryTemplate<CStageTrack>::vfunc_5 (59 B): matches/0x00077620.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCStageTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CStageTrack>::vfunc_5() {
    CStageTrack_77620* p = (CStageTrack_77620*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fc094);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fbee1db8 {

// 0x00077660 fight::TrackFactoryTemplate<CStageTrack>::vfunc_2 (43 B): matches/0x00077660.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbee1db8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feb30;
    base1_dtor_0006ab20();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbee1db8
