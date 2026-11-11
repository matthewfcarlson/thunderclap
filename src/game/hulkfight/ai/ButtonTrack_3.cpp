// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114bb0..0x00114c70 (kind game, layer game, confidence high), dominant class hulkfight::ai::ButtonTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f459dd82 {
#define TREE_TU_END }
namespace fn_f459dd82 {} using namespace fn_f459dd82;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f459dd82 {
class TrackFactoryTemplate_114bb0 {
  public:
    TrackFactoryTemplate_114bb0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112ba0();
extern "C" char DAT_0040dc74[];
typedef unsigned int u32_114bf0;
struct ButtonTrack_114bf0 {
    hulk_uintptr vft;
    u32_114bf0 q0;
    u32_114bf0 q1;
    u32_114bf0 a;
    u32_114bf0 b;
    u32_114bf0 c;
    u32_114bf0 d;
    u32_114bf0 e;
    u32_114bf0 f;
    void Init();
};
extern "C" void* FUN_0008d690(unsigned int);
extern int g_vftable_114c40;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f459dd82

// 0x00114bb0 fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_1 (60 B): matches/0x00114bb0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114bb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114bb0* t = new (mem) TrackFactoryTemplate_114bb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112ba0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114bf0 fight::TrackFactoryTemplate<hulkfight::ai::ButtonTrack>::vfunc_5 (65 B): matches/0x00114bf0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::ButtonTrack>::vfunc_5() {
    ButtonTrack_114bf0* p = (ButtonTrack_114bf0*)FUN_0008d690((int)sizeof(ButtonTrack_114bf0));
    if (p != 0) {
        p->Init();
        p->a = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->vft = ((hulk_intptr)DAT_0040dc74);
        p->b = 0xbf800000;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f459dd82 {

// 0x00114c40 fight::TrackFactoryTemplate<hulkfight::ai::ButtonTrack>::vfunc_2 (43 B): matches/0x00114c40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f459dd82@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_114c40;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f459dd82
