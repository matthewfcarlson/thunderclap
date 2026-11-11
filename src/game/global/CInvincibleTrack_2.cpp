// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076d00..0x00076dc0 (kind game, layer game, confidence high), dominant class CInvincibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbdad5cf {
#define TREE_TU_END }
namespace fn_fbdad5cf {} using namespace fn_fbdad5cf;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbdad5cf {
class TrackFactoryTemplate_76d00 {
  public:
    TrackFactoryTemplate_76d00() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
class CInvincibleTrack_76d40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int x;
    int one;
    int zero;
    int neg;
    int tail;
    void Init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fbdc8;
extern int hulk_at_003fe9a4;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a040();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fbdad5cf

// 0x00076d00 fight::TrackFactoryCasterTemplate<CInvincibleTrack>::vfunc_1 (60 B): matches/0x00076d00.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCInvincibleTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CInvincibleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76d00));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76d00* t = new (mem) TrackFactoryTemplate_76d00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000719a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076d40 fight::TrackFactoryTemplate<CInvincibleTrack>::vfunc_5 (66 B): matches/0x00076d40.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCInvincibleTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CInvincibleTrack>::vfunc_5() {
    CInvincibleTrack_76d40* p = (CInvincibleTrack_76d40*)FUN_0008d690((int)sizeof(CInvincibleTrack_76d40));
    CInvincibleTrack_76d40* r;
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_003fbdc8;
        p->zero = 0;
        p->neg = (int)0xbf800000;
        p->tail = 0;
        p->one = 1;
        r = p;
    } else
        r = 0;
    return (void*)(r);
}

namespace fn_fbdad5cf {

// 0x00076d90 fight::TrackFactoryTemplate<CInvincibleTrack>::vfunc_2 (43 B): matches/0x00076d90.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbdad5cf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe9a4;
    base1_dtor_0006a040();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbdad5cf
