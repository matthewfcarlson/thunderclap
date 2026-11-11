// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017e8d0..0x0017e980 (kind game, layer game, confidence high), dominant class hulkfight::motion::CriticalMassDrainTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff12b9e5 {
#define TREE_TU_END }
namespace fn_ff12b9e5 {} using namespace fn_ff12b9e5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff12b9e5 {
class TrackFactoryTemplate_17e8d0 {
  public:
    TrackFactoryTemplate_17e8d0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017a9a0();
extern "C" char DAT_00417c28[];
struct Base_17e910 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct CriticalMassDrainTrack_17e910 : Base_17e910 {
    int pad4;
    int m8;
    int mC;
    int m10;
    void Init();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern int g_vftable_17e950;

} // namespace fn_ff12b9e5

// 0x0017e8d0 fight::TrackFactoryCasterTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_1 (60 B): matches/0x0017e8d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCriticalMassDrainTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17e8d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17e8d0* t = new (mem) TrackFactoryTemplate_17e8d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017a9a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0017e910 fight::TrackFactoryTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_5 (59 B): matches/0x0017e910.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCriticalMassDrainTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_5() {
    CriticalMassDrainTrack_17e910* p = (CriticalMassDrainTrack_17e910*)operator_new(0x14);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00417c28);
        p->mC = 0;
        p->m10 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ff12b9e5 {

// 0x0017e950 fight::TrackFactoryTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_2 (43 B): matches/0x0017e950.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff12b9e5@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_17e950;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff12b9e5
