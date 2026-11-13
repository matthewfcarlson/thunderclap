// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018c170..0x0018c220 (kind game, layer game, confidence high), dominant class hulkfight::motion::ShieldArcTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5aaf014 {
#define TREE_TU_END }
namespace fn_f5aaf014 {} using namespace fn_f5aaf014;
namespace fn_f5aaf014 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5aaf014 {
class TrackFactoryTemplate_18c170 {
  public:
    TrackFactoryTemplate_18c170() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001883f0();
extern "C" char DAT_004194dc[];
typedef unsigned int u32_18c1b0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class ShieldArcTrack_18c1b0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    u32_18c1b0 pad;
    void Init_00236d40();
};
extern int hulk_at_0041a844;

} // namespace fn_f5aaf014

// 0x0018c170 fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_1 (60 B): matches/0x0018c170.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VShieldArcTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_18c170));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_18c170* t = new (mem) TrackFactoryTemplate_18c170();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001883f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0018c1b0 fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_5 (59 B): matches/0x0018c1b0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VShieldArcTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_5() {
    ShieldArcTrack_18c1b0* p = (ShieldArcTrack_18c1b0*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00236d40();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004194dc);
        *(u32_18c1b0*)((char*)p + 0xc) = 0;
        *(u32_18c1b0*)((char*)p + 0x10) = 0x3fc90fdb;
        *(u32_18c1b0*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5aaf014 {

// 0x0018c1f0 fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_2 (43 B): matches/0x0018c1f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5aaf014@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041a844;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f5aaf014
