// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070230..0x000702c0 (kind game, layer game, confidence high), dominant class CSmartPropSpawnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe34659b {
#define TREE_TU_END }
namespace fn_fe34659b {} using namespace fn_fe34659b;
namespace fn_fe34659b {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe34659b {
class TrackFactoryTemplate_70230 {
  public:
    TrackFactoryTemplate_70230() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00065630();
typedef unsigned int u32_70270;
extern "C" void* __cdecl Allocate(unsigned int);
class Created_70270 {
  public:
    hulk_uintptr Initialize_00062510();
};
extern int hulk_at_003fd3dc;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_000624e0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe34659b

// 0x00070230 fight::TrackFactoryCasterTemplate<CSmartPropSpawnTrack>::vfunc_1 (60 B): matches/0x00070230.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropSpawnTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropSpawnTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_70230));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_70230* t = new (mem) TrackFactoryTemplate_70230();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00065630();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070270 fight::TrackFactoryTemplate<CSmartPropSpawnTrack>::vfunc_5 (27 B): matches/0x00070270.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropSpawnTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fc10 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CSmartPropSpawnTrack>::vfunc_5() {
    Created_70270* p = (Created_70270*)Allocate(0xd0);
    if (p)
        return (void*)(p->Initialize_00062510());
    return (void*)(0);
}

namespace fn_fe34659b {

// 0x00070290 fight::TrackFactoryTemplate<CSmartPropSpawnTrack>::vfunc_2 (43 B): matches/0x00070290.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fe34659b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd3dc;
    base1_dtor_000624e0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe34659b
