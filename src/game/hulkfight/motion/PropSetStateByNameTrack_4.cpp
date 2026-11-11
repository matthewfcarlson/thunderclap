// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c720..0x0018c7e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByNameTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5f77793 {
#define TREE_TU_END }
namespace fn_f5f77793 {} using namespace fn_f5f77793;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5f77793 {
class TrackFactoryTemplate_18c720 {
  public:
    TrackFactoryTemplate_18c720() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00189f90();
extern "C" char DAT_004192fc[];
class Sub_18c760 {
  public:
    void initSub_0027af00();
};
class PropSetStateByNameTrack_18c760 {
  public:
    void baseInit_00236d40();
    char pad[0x18];
    Sub_18c760 sub;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_0041a924;

} // namespace fn_f5f77793

// 0x0018c720 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_1 (60 B): matches/0x0018c720.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c720));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c720* t = new (mem) TrackFactoryTemplate_18c720();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00189f90();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c760 fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_5 (67 B): matches/0x0018c760.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_5() {
    PropSetStateByNameTrack_18c760* p = (PropSetStateByNameTrack_18c760*)FUN_0008d690(0x20);
    if (p) {
        p->baseInit_00236d40();
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_004192fc);
        *(unsigned long*)((char*)p + 0xc) = 0;
        *(unsigned long*)((char*)p + 0x10) = 0xffffffff;
        p->sub.initSub_0027af00();
        *(unsigned long*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5f77793 {

// 0x0018c7b0 fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_2 (43 B): matches/0x0018c7b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5f77793@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a924;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5f77793
