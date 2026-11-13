// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076310..0x000763d0 (kind game, layer game, confidence high), dominant class CDrainHealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f56f53b0 {
#define TREE_TU_END }
namespace fn_f56f53b0 {} using namespace fn_f56f53b0;
namespace fn_f56f53b0 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f56f53b0 {
class TrackFactoryTemplate_76310 {
  public:
    TrackFactoryTemplate_76310() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_003fbd50[];
class CDrainHealthTrack_76350 {
  public:
    hulk_intptr a;
    int b, c, d, e, f;
    void init_00236d40();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TrackFactory_76350 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class Entity_76350 {
  public:
    virtual void v3();
    virtual void v4();
};
class LoadObject_76350 {
  public:
    virtual void v0();
    virtual void v1();
};
class IRefCount_76350 {
  public:
    virtual void r0();
};
extern int hulk_at_003fe658;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069e70();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f56f53b0

// 0x00076310 fight::TrackFactoryCasterTemplate<CDrainHealthTrack>::vfunc_1 (60 B): matches/0x00076310.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCDrainHealthTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CDrainHealthTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76310));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_76310* t = new (mem) TrackFactoryTemplate_76310();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000717e0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076350 fight::TrackFactoryTemplate<CDrainHealthTrack>::vfunc_5 (66 B): matches/0x00076350.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCDrainHealthTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CDrainHealthTrack>::vfunc_5() {
    CDrainHealthTrack_76350* p = (CDrainHealthTrack_76350*)FUN_0008d690((int)sizeof(CDrainHealthTrack_76350));
    if (p) {
        p->init_00236d40();
        p->a = ((hulk_intptr)DAT_003fbd50);
        p->d = 0;
        p->e = 0x3f800000;
        p->f = 0;
        p->c = 1;
    } else
        return (void*)(0);
    return (void*)(p);
}

namespace fn_f56f53b0 {

// 0x000763a0 fight::TrackFactoryTemplate<CDrainHealthTrack>::vfunc_2 (43 B): matches/0x000763a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f56f53b0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe658;
    base1_dtor_00069e70();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f56f53b0
