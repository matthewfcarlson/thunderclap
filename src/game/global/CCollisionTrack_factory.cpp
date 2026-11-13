// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006f150..0x0006f1e0 (kind game, layer game, confidence high), dominant class CCollisionTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc3acc0d {
#define TREE_TU_END }
namespace fn_fc3acc0d {} using namespace fn_fc3acc0d;
namespace fn_fc3acc0d {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc3acc0d {
class TrackFactoryTemplate_6f150 {
  public:
    TrackFactoryTemplate_6f150() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0005f150();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Obj_6f190 {
  public:
    void* Initialize_0005d930();
};
extern int hulk_at_003fcf64;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0005d900();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc3acc0d

// 0x0006f150 fight::TrackFactoryCasterTemplate<CCollisionTrack>::vfunc_1 (60 B): matches/0x0006f150.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCCollisionTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CCollisionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_6f150));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_6f150* t = new (mem) TrackFactoryTemplate_6f150();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0005f150();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0006f190 fight::TrackFactoryTemplate<CCollisionTrack>::vfunc_5 (27 B): matches/0x0006f190.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCCollisionTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CCollisionTrack>::vfunc_5() {
    Obj_6f190* p = (Obj_6f190*)FUN_0008d690(0x120);
    if (p)
        return (void*)(p->Initialize_0005d930());
    return (void*)(0);
}

namespace fn_fc3acc0d {

// 0x0006f1b0 fight::TrackFactoryTemplate<CCollisionTrack>::vfunc_2 (43 B): matches/0x0006f1b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc3acc0d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fcf64;
    base1_dtor_0005d900();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fc3acc0d
