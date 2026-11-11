// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c020..0x0018c0e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByIndexTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb862f4a {
#define TREE_TU_END }
namespace fn_fb862f4a {} using namespace fn_fb862f4a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb862f4a {
class TrackFactoryTemplate_18c020 {
  public:
    TrackFactoryTemplate_18c020() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188140();
extern "C" char DAT_0041944c[];
class PropSetStateByIndexTrack_18c060 {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_18c0b0;

} // namespace fn_fb862f4a

// 0x0018c020 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_1 (60 B): matches/0x0018c020.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c020));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c020* t = new (mem) TrackFactoryTemplate_18c020();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188140();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c060 fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_5 (66 B): matches/0x0018c060.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_5() {
    PropSetStateByIndexTrack_18c060* p = (PropSetStateByIndexTrack_18c060*)FUN_0008d690((int)sizeof(PropSetStateByIndexTrack_18c060));
    if (p) {
        p->Init();
        p->a = ((hulk_intptr)DAT_0041944c);
        p->d = 0;
        p->e = -1;
        p->f = 0;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fb862f4a {

// 0x0018c0b0 fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_2 (43 B): matches/0x0018c0b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb862f4a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18c0b0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb862f4a
