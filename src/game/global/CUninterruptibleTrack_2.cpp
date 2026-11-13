// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077800..0x000778c0 (kind game, layer game, confidence high), dominant class CUninterruptibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbba5966 {
#define TREE_TU_END }
namespace fn_fbba5966 {} using namespace fn_fbba5966;
namespace fn_fbba5966 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbba5966 {
class TrackFactoryTemplate_77800 {
  public:
    TrackFactoryTemplate_77800() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_003fbfe0[];
class Track_77840 {
  public:
    virtual void v();
    Track_77840();
    char pad[8];
    int a;
    int b;
    int c;
};
extern int hulk_at_003feb84;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a890();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbba5966

// 0x00077800 fight::TrackFactoryCasterTemplate<CUninterruptibleTrack>::vfunc_1 (60 B): matches/0x00077800.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCUninterruptibleTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CUninterruptibleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77800));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_77800* t = new (mem) TrackFactoryTemplate_77800();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072280();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077840 fight::TrackFactoryTemplate<CUninterruptibleTrack>::vfunc_5 (66 B): matches/0x00077840.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCUninterruptibleTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CUninterruptibleTrack>::vfunc_5() {
    Track_77840* p = (Track_77840*)operator_new(0x18);
    if (p) {
        p->Track_77840::Track_77840();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fbfe0);
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fbba5966 {

// 0x00077890 fight::TrackFactoryTemplate<CUninterruptibleTrack>::vfunc_2 (43 B): matches/0x00077890.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbba5966@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feb84;
    base1_dtor_0006a890();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fbba5966
