// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c390..0x0018c450 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f18335cb {
#define TREE_TU_END }
namespace fn_f18335cb {} using namespace fn_f18335cb;
namespace fn_f18335cb {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f18335cb {
class TrackFactoryTemplate_18c390 {
  public:
    TrackFactoryTemplate_18c390() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00188650();
extern "C" char DAT_0041956c[];
extern "C" void* Alloc(hulk_uintptr);
class Track_18c3d0 {
  public:
    Track_18c3d0();
    virtual void a();
    virtual void b();
    virtual void c();
};
class PropDamageTrack_18c3d0 : public Track_18c3d0 {
  public:
    int x4;
    int x8;
    int xc;
    int x10;
    int x14;
};
extern int hulk_at_0041a898;

} // namespace fn_f18335cb

// 0x0018c390 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_1 (60 B): matches/0x0018c390.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPropDamageTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c390));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_18c390* t = new (mem) TrackFactoryTemplate_18c390();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00188650();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c3d0 fight::TrackFactoryTemplate<hulkfight::motion::PropDamageTrack>::vfunc_5 (66 B): matches/0x0018c3d0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPropDamageTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropDamageTrack>::vfunc_5() {
    PropDamageTrack_18c3d0* p = (PropDamageTrack_18c3d0*)Alloc(0x18);
    if (p) {
        p->Track_18c3d0::Track_18c3d0();
        *(volatile hulk_uintptr*)p = ((hulk_intptr)DAT_0041956c);
        p->xc = 0;
        p->x10 = 0;
        p->x14 = 0;
        p->x8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f18335cb {

// 0x0018c420 fight::TrackFactoryTemplate<hulkfight::motion::PropDamageTrack>::vfunc_2 (43 B): matches/0x0018c420.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f18335cb@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a898;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f18335cb
