// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e780..0x0017e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::SurfTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f90b3df3 {
#define TREE_TU_END }
namespace fn_f90b3df3 {} using namespace fn_f90b3df3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f90b3df3 {
class TrackFactoryTemplate_17e780 {
  public:
    TrackFactoryTemplate_17e780() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a520();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_17e7c0 {
    void* Init();
};
extern int g_vftable_17e7e0;

} // namespace fn_f90b3df3

// 0x0017e780 fight::TrackFactoryCasterTemplate<hulkfight::motion::SurfTrack>::vfunc_1 (60 B): matches/0x0017e780.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSurfTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::SurfTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e780));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e780* t = new (mem) TrackFactoryTemplate_17e780();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a520();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e7c0 fight::TrackFactoryTemplate<hulkfight::motion::SurfTrack>::vfunc_5 (24 B): matches/0x0017e7c0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSurfTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SurfTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_17e7c0*)p)->Init());
    return (void*)(0);
}

namespace fn_f90b3df3 {

// 0x0017e7e0 fight::TrackFactoryTemplate<hulkfight::motion::SurfTrack>::vfunc_2 (43 B): matches/0x0017e7e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f90b3df3@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_17e7e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f90b3df3
