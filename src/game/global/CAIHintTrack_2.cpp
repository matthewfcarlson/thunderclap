// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077990..0x00077a50 (kind game, layer game, confidence high), dominant class CAIHintTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fab98861 {
#define TREE_TU_END }
namespace fn_fab98861 {} using namespace fn_fab98861;
namespace fn_fab98861 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fab98861 {
class TrackFactoryTemplate_77990 {
  public:
    TrackFactoryTemplate_77990() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00075b50();
extern "C" char DAT_003fc184[];
struct Sub_779d0 {
    void subinit_0027af00();
};
struct CAIHintTrack_779d0 {
    char pad[32];
    void init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003febbc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006aee0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fab98861

// 0x00077990 fight::TrackFactoryCasterTemplate<CAIHintTrack>::vfunc_1 (60 B): matches/0x00077990.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCAIHintTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CAIHintTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77990));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_77990* t = new (mem) TrackFactoryTemplate_77990();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00075b50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000779d0 fight::TrackFactoryTemplate<CAIHintTrack>::vfunc_5 (67 B): matches/0x000779d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCAIHintTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CAIHintTrack>::vfunc_5() {
    CAIHintTrack_779d0* p = (CAIHintTrack_779d0*)FUN_0008d690((int)sizeof(CAIHintTrack_779d0));
    if (p) {
        p->init_00236d40();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fc184);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        ((Sub_779d0*)((char*)p + 0x18))->subinit_0027af00();
        *(unsigned int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fab98861 {

// 0x00077a20 fight::TrackFactoryTemplate<CAIHintTrack>::vfunc_2 (43 B): matches/0x00077a20.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fab98861@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003febbc;
    base1_dtor_0006aee0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fab98861
