// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076490..0x00076520 (kind game, layer game, confidence high), dominant class CDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f586c699 {
#define TREE_TU_END }
namespace fn_f586c699 {} using namespace fn_f586c699;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f586c699 {
class TrackFactoryTemplate_76490 {
  public:
    TrackFactoryTemplate_76490() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00070ab0();
typedef unsigned int u32_764d0;
struct CAutoTargetTrack_764d0 {
    hulk_uintptr initialize();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int g_vftable_764f0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f586c699

// 0x00076490 fight::TrackFactoryCasterTemplate<CDropTrack>::vfunc_1 (60 B): matches/0x00076490.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCDropTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CDropTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76490));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76490* t = new (mem) TrackFactoryTemplate_76490();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00070ab0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000764d0 fight::TrackFactoryTemplate<CDropTrack>::vfunc_5 (24 B): matches/0x000764d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCDropTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x00075d20 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CDropTrack>::vfunc_5() {
    CAutoTargetTrack_764d0* p = (CAutoTargetTrack_764d0*)FUN_0008d690(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}

namespace fn_f586c699 {

// 0x000764f0 fight::TrackFactoryTemplate<CDropTrack>::vfunc_2 (43 B): matches/0x000764f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f586c699@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_764f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f586c699
