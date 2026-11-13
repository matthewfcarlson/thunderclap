// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f0c0..0x0006f150 (kind game, layer game, confidence high), dominant class CClearHitRecordsTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f05fd2cd {
#define TREE_TU_END }
namespace fn_f05fd2cd {} using namespace fn_f05fd2cd;
namespace fn_f05fd2cd {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f05fd2cd {
class TrackFactoryTemplate_6f0c0 {
  public:
    TrackFactoryTemplate_6f0c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005ef60();
struct Allocated_6f100 {
    hulk_intptr Finish_0005dff0();
};
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_003fcf48;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005dfc0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f05fd2cd

// 0x0006f0c0 fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack>::vfunc_1 (60 B): matches/0x0006f0c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCClearHitRecordsTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f0c0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6f0c0* t = new (mem) TrackFactoryTemplate_6f0c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005ef60();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f100 fight::TrackFactoryTemplate<CClearHitRecordsTrack>::vfunc_5 (24 B): matches/0x0006f100.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCClearHitRecordsTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CClearHitRecordsTrack>::vfunc_5() {
    Allocated_6f100* p = (Allocated_6f100*)FUN_0008d690(0x10);
    if (p)
        return (void*)(p->Finish_0005dff0());
    return (void*)(0);
}

namespace fn_f05fd2cd {

// 0x0006f120 fight::TrackFactoryTemplate<CClearHitRecordsTrack>::vfunc_2 (43 B): matches/0x0006f120.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f05fd2cd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcf48;
    base1_dtor_0005dfc0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f05fd2cd
