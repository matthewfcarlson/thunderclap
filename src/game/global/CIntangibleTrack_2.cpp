// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076ba0..0x00076c50 (kind game, layer game, confidence high), dominant class CIntangibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8f62026 {
#define TREE_TU_END }
namespace fn_f8f62026 {} using namespace fn_f8f62026;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8f62026 {
class TrackFactoryTemplate_76ba0 {
  public:
    TrackFactoryTemplate_76ba0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_003fbe04[];
class CIntangibleTrack_76be0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad;
    int c;
    int d;
    int e;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vftable_76c20;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f8f62026

// 0x00076ba0 fight::TrackFactoryCasterTemplate<CIntangibleTrack>::vfunc_1 (60 B): matches/0x00076ba0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCIntangibleTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CIntangibleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76ba0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76ba0* t = new (mem) TrackFactoryTemplate_76ba0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071a80();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076be0 fight::TrackFactoryTemplate<CIntangibleTrack>::vfunc_5 (59 B): matches/0x00076be0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCIntangibleTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CIntangibleTrack>::vfunc_5() {
    CIntangibleTrack_76be0* p = (CIntangibleTrack_76be0*)FUN_0008d690((int)sizeof(CIntangibleTrack_76be0));
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fbe04);
        p->d = 0;
        p->e = (int)0xbf800000;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f8f62026 {

// 0x00076c20 fight::TrackFactoryTemplate<CIntangibleTrack>::vfunc_2 (43 B): matches/0x00076c20.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f8f62026@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_76c20;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8f62026
