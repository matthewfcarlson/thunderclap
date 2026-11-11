// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076f10..0x00076fe0 (kind game, layer game, confidence high), dominant class CJumpAttackTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f18f8171 {
#define TREE_TU_END }
namespace fn_f18f8171 {} using namespace fn_f18f8171;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f18f8171 {
class TrackFactoryTemplate_76f10 {
  public:
    TrackFactoryTemplate_76f10() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00071db0();
class Root_76f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    Root_76f50() throw();
};
class Mid_76f50 : public Root_76f50 {
  public:
    int a;
    float b;
    Mid_76f50() throw() {
        b = -1.0f;
        a = 0;
    }
};
class CJumpAttackTrack_76f50 : public Mid_76f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int zero;
    float d, e;
    float pi;
    float g, h;
    int j, k, l;
    CJumpAttackTrack_76f50() throw() {
        _ReadWriteBarrier();
        d = -1.0f;
        e = -1.0f;
        zero = 0;
        _ReadWriteBarrier();
        j = 0;
        k = 0;
        l = 0;
        g = 10.0f;
        h = 10.0f;
        pi = 1.5707964f;
    }
};
extern int hulk_at_003fe9f8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a5a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f18f8171

// 0x00076f10 fight::TrackFactoryCasterTemplate<CJumpAttackTrack>::vfunc_1 (60 B): matches/0x00076f10.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCJumpAttackTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CJumpAttackTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76f10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76f10* t = new (mem) TrackFactoryTemplate_76f10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071db0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076f50 fight::TrackFactoryTemplate<CJumpAttackTrack>::vfunc_5 (90 B): matches/0x00076f50.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCJumpAttackTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CJumpAttackTrack>::vfunc_5() {
    return (void*)(new CJumpAttackTrack_76f50);
}

namespace fn_f18f8171 {

// 0x00076fb0 fight::TrackFactoryTemplate<CJumpAttackTrack>::vfunc_2 (43 B): matches/0x00076fb0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f18f8171@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe9f8;
    base1_dtor_0006a5a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f18f8171
