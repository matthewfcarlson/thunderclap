// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000772e0..0x000773b0 (kind game, layer game, confidence high), dominant class COrientTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fed5cdd6 {
#define TREE_TU_END }
namespace fn_fed5cdd6 {} using namespace fn_fed5cdd6;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fed5cdd6 {
class TrackFactoryTemplate_772e0 {
  public:
    TrackFactoryTemplate_772e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_003fbf68[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_77320 {
  public:
    void Init();
};
struct Orient_77320 {
    void* vptr;
    int x4;
    int x8;
    int xC;
    int x10;
    int x14;
    int x18;
    unsigned char x1c;
    char pad[3];
    int x20;
    int x24;
    int x28;
};
extern int g_vftable_77380;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fed5cdd6

// 0x000772e0 fight::TrackFactoryCasterTemplate<COrientTrack>::vfunc_1 (60 B): matches/0x000772e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCOrientTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<COrientTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_772e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_772e0* t = new (mem) TrackFactoryTemplate_772e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071fb0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077320 fight::TrackFactoryTemplate<COrientTrack>::vfunc_5 (82 B): matches/0x00077320.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCOrientTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<COrientTrack>::vfunc_5() {
    Orient_77320* p = (Orient_77320*)FUN_0008d690((int)sizeof(Orient_77320));
    if (p) {
        ((Helper_77320*)p)->Init();
        p->xC = 0;
        p->x18 = 0;
        p->x1c = 0;
        p->x20 = 0;
        p->x24 = 0;
        p->x28 = 0;
        p->vptr = (void*)((hulk_intptr)DAT_003fbf68);
        p->x10 = 0xbf800000;
        p->x14 = 0xbc8efa35;
        p->x8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fed5cdd6 {

// 0x00077380 fight::TrackFactoryTemplate<COrientTrack>::vfunc_2 (43 B): matches/0x00077380.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fed5cdd6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_77380;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fed5cdd6
