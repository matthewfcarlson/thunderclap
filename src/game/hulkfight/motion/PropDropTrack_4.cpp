// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018bec0..0x0018bf70 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd9a71ee {
#define TREE_TU_END }
namespace fn_fd9a71ee {} using namespace fn_fd9a71ee;
namespace fn_fd9a71ee {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd9a71ee {
class TrackFactoryTemplate_18bec0 {
  public:
    TrackFactoryTemplate_18bec0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00187fa0();
extern "C" char DAT_0041935c[];
class PropDropTrack_18bf00 {
  public:
    void Init_00236d40();
    hulk_intptr vt;
    int pad;
    int e;
    int c;
    int d;
};
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_0041a7d4;

} // namespace fn_fd9a71ee

// 0x0018bec0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDropTrack>::vfunc_1 (60 B): matches/0x0018bec0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropDropTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDropTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18bec0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_18bec0* t = new (mem) TrackFactoryTemplate_18bec0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00187fa0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018bf00 fight::TrackFactoryTemplate<hulkfight::motion::PropDropTrack>::vfunc_5 (59 B): matches/0x0018bf00.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropDropTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropDropTrack>::vfunc_5() {
    PropDropTrack_18bf00* p = (PropDropTrack_18bf00*)FUN_0008d690((int)sizeof(PropDropTrack_18bf00));
    if (p) {
        p->Init_00236d40();
        p->vt = ((hulk_intptr)DAT_0041935c);
        p->c = 0;
        p->d = -1;
        p->e = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd9a71ee {

// 0x0018bf40 fight::TrackFactoryTemplate<hulkfight::motion::PropDropTrack>::vfunc_2 (43 B): matches/0x0018bf40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd9a71ee@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a7d4;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd9a71ee
