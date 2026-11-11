// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c220..0x0018c2d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7c68681 {
#define TREE_TU_END }
namespace fn_f7c68681 {} using namespace fn_f7c68681;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f7c68681 {
class TrackFactoryTemplate_18c220 {
  public:
    TrackFactoryTemplate_18c220() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188490();
extern "C" char DAT_0041950c[];
struct PropTrack_18c260 {
    void Init_00236d40();
    unsigned char pad[0x18];
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_0041a860;

} // namespace fn_f7c68681

// 0x0018c220 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_1 (60 B): matches/0x0018c220.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c220));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_18c220* t = new (mem) TrackFactoryTemplate_18c220();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188490();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c260 fight::TrackFactoryTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_5 (63 B): matches/0x0018c260.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_5() {
    PropTrack_18c260* p = (PropTrack_18c260*)FUN_0008d690((int)sizeof(PropTrack_18c260));
    if (p) {
        p->Init_00236d40();
        p->pad[0x14] = 1;
        *(int*)(p->pad + 8) = 1;
        *(hulk_intptr*)p->pad = ((hulk_intptr)DAT_0041950c);
        *(int*)(p->pad + 0xc) = 0;
        *(int*)(p->pad + 0x10) = 0;
    }
    if (!p)
        return (void*)(0);
    return (void*)(p);
}

namespace fn_f7c68681 {

// 0x0018c2a0 fight::TrackFactoryTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2 (43 B): matches/0x0018c2a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f7c68681@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a860;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f7c68681
