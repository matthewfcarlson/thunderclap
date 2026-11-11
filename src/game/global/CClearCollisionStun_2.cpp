// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00075ee0..0x00075f90 (kind game, layer game, confidence high), dominant class CClearCollisionStun
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbb24f68 {
#define TREE_TU_END }
namespace fn_fbb24f68 {} using namespace fn_fbb24f68;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbb24f68 {
class TrackFactoryTemplate_75ee0 {
  public:
    TrackFactoryTemplate_75ee0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000726a0();
extern "C" char DAT_003fc1c0[];
} // namespace fn_fbb24f68
void* operator new(size_t);
namespace fn_fbb24f68 {
class CClearCollisionStun_75f20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[4];
    int a1;
    int a2;
    int a3;
    void Init_00236d40();
};
extern int hulk_at_003fe5b0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006afc0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbb24f68

// 0x00075ee0 fight::TrackFactoryCasterTemplate<CClearCollisionStun>::vfunc_1 (60 B): matches/0x00075ee0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCClearCollisionStun@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CClearCollisionStun>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_75ee0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_75ee0* t = new (mem) TrackFactoryTemplate_75ee0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000726a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00075f20 fight::TrackFactoryTemplate<CClearCollisionStun>::vfunc_5 (59 B): matches/0x00075f20.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCClearCollisionStun@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CClearCollisionStun>::vfunc_5() {
    CClearCollisionStun_75f20* p = (CClearCollisionStun_75f20*)operator new(sizeof(CClearCollisionStun_75f20));
    if (p) {
        p->Init_00236d40();
        *(volatile hulk_intptr*)p = ((hulk_intptr)DAT_003fc1c0);
        p->a2 = 0;
        p->a3 = 0xbf800000;
        p->a1 = 1;
        return (void*)((hulk_intptr)p);
    }
    return (void*)(0);
}

namespace fn_fbb24f68 {

// 0x00075f60 fight::TrackFactoryTemplate<CClearCollisionStun>::vfunc_2 (43 B): matches/0x00075f60.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbb24f68@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe5b0;
    base1_dtor_0006afc0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbb24f68
