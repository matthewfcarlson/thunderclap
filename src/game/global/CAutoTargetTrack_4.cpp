// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00075ce0..0x00075d70 (kind game, layer game, confidence high), dominant class CAutoTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f05c4ed8 {
#define TREE_TU_END }
namespace fn_f05c4ed8 {} using namespace fn_f05c4ed8;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f05c4ed8 {
class TrackFactoryTemplate_75ce0 {
  public:
    TrackFactoryTemplate_75ce0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_75d20;
struct CAutoTargetTrack_75d20 {
    hulk_uintptr initialize_00069c50();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fe55c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069c20();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f05c4ed8

// 0x00075ce0 fight::TrackFactoryCasterTemplate<CAutoTargetTrack>::vfunc_1 (60 B): matches/0x00075ce0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCAutoTargetTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CAutoTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_75ce0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_75ce0* t = new (mem) TrackFactoryTemplate_75ce0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071430();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00075d20 fight::TrackFactoryTemplate<CAutoTargetTrack>::vfunc_5 (24 B): matches/0x00075d20.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCAutoTargetTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CAutoTargetTrack>::vfunc_5() {
    CAutoTargetTrack_75d20* p = (CAutoTargetTrack_75d20*)FUN_0008d690(0x3c);
    if (p)
        return (void*)(p->initialize_00069c50());
    return (void*)(0);
}

namespace fn_f05c4ed8 {

// 0x00075d40 fight::TrackFactoryTemplate<CAutoTargetTrack>::vfunc_2 (43 B): matches/0x00075d40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f05c4ed8@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe55c;
    base1_dtor_00069c20();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f05c4ed8
