// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a180..0x0015a230 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f28f0564 {
#define TREE_TU_END }
namespace fn_f28f0564 {} using namespace fn_f28f0564;
namespace fn_f28f0564 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f28f0564 {
class TrackFactoryTemplate_15a180 {
  public:
    TrackFactoryTemplate_15a180() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156520();
extern "C" char DAT_00414420[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
    int a;
    int b;
    unsigned char c, d, e;
    void Init_00236d40();
    void* Make();
};
extern int hulk_at_00415810;

} // namespace fn_f28f0564

// 0x0015a180 fight::TrackFactoryCasterTemplate<hulkfight::motion::HealthTrack>::vfunc_1 (60 B): matches/0x0015a180.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHealthTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::HealthTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a180));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_15a180* t = new (mem) TrackFactoryTemplate_15a180();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156520();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f28f0564 {

// 0x0015a1c0 fight::TrackFactoryTemplate<hulkfight::motion::HealthTrack>::vfunc_5 (58 B): matches/0x0015a1c0.cpp
// sym: ?Make@Track@fn_f28f0564@@QAEPAXXZ
void* Track::Make() {
    Track* p = (Track*)FUN_0008d690((int)sizeof(Track));
    if (p) {
        p->Init_00236d40();
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414420);
        return p;
    }
    return 0;
}


// 0x0015a200 fight::TrackFactoryTemplate<hulkfight::motion::HealthTrack>::vfunc_2 (43 B): matches/0x0015a200.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f28f0564@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415810;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f28f0564
