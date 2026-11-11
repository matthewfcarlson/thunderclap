// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076270..0x00076310 (kind game, layer game, confidence high), dominant class CDeathTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f55a049d {
#define TREE_TU_END }
namespace fn_f55a049d {} using namespace fn_f55a049d;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f55a049d {
class TrackFactoryTemplate_76270 {
  public:
    TrackFactoryTemplate_76270() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072640();
extern "C" char DAT_003fc148[];
class CDeathTrack_762b0 {
  public:
    int pad[4];
    void init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_762e0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f55a049d

// 0x00076270 fight::TrackFactoryCasterTemplate<CDeathTrack>::vfunc_1 (60 B): matches/0x00076270.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCDeathTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CDeathTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76270));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76270* t = new (mem) TrackFactoryTemplate_76270();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072640();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000762b0 fight::TrackFactoryTemplate<CDeathTrack>::vfunc_5 (45 B): matches/0x000762b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCDeathTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CDeathTrack>::vfunc_5() {
    CDeathTrack_762b0* p = (CDeathTrack_762b0*)FUN_0008d690((int)sizeof(CDeathTrack_762b0));
    if (p) {
        p->init();
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003fc148);
        *(unsigned long*)((char*)p + 0xc) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f55a049d {

// 0x000762e0 fight::TrackFactoryTemplate<CDeathTrack>::vfunc_2 (43 B): matches/0x000762e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f55a049d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_762e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f55a049d
