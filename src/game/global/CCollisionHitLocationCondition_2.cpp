// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00057870..0x00057920 (kind game, layer game, confidence high), dominant class CCollisionHitLocationCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f52e0250 {
#define TREE_TU_END }
namespace fn_f52e0250 {} using namespace fn_f52e0250;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f52e0250 {
class TrackFactoryTemplate_57870 {
  public:
    TrackFactoryTemplate_57870() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000532e0();
extern "C" char DAT_003f6fa4[];
typedef unsigned int u32_578b0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CCollisionHitLocationCondition_578b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    int pad;
    int x;
    void Init_00234590(int);
};
extern int hulk_at_003f9384;
struct ConditionFactoryTemplate_578f0 {
    void* m_vptr;
    void base1_dtor_00048b40();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f52e0250

// 0x00057870 fight::ConditionFactoryCasterTemplate<CCollisionHitLocationCondition>::vfunc_1 (60 B): matches/0x00057870.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCCollisionHitLocationCondition@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<CCollisionHitLocationCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_57870));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_57870* t = new (mem) TrackFactoryTemplate_57870();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000532e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000578b0 fight::ConditionFactoryTemplate<CCollisionHitLocationCondition>::vfunc_5 (54 B): matches/0x000578b0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCCollisionHitLocationCondition@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<CCollisionHitLocationCondition>::vfunc_5() {
    CCollisionHitLocationCondition_578b0* p = (CCollisionHitLocationCondition_578b0*)FUN_0008d690(0x14);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f6fa4);
        ((u32_578b0*)p)[3] = 2;
        ((u32_578b0*)p)[4] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f52e0250 {

// 0x000578f0 fight::ConditionFactoryTemplate<CCollisionHitLocationCondition>::vfunc_2 (43 B): matches/0x000578f0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_578f0@fn_f52e0250@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_578f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003f9384;
    base1_dtor_00048b40();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f52e0250
