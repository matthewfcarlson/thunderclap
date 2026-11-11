// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077480..0x00077530 (kind game, layer game, confidence high), dominant class CRageModeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f702c0e2 {
#define TREE_TU_END }
namespace fn_f702c0e2 {} using namespace fn_f702c0e2;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f702c0e2 {
class TrackFactoryTemplate_77480 {
  public:
    TrackFactoryTemplate_77480() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072440();
extern "C" char DAT_003fc058[];
extern "C" void* __cdecl FUN_0008d690(int);
struct Obj_774c0 {
    hulk_intptr vptr;
    int x4;
    int m8;
    int mc;
    int m10;
    void Init();
};
extern int g_vftable_77500;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f702c0e2

// 0x00077480 fight::TrackFactoryCasterTemplate<CRageModeTrack>::vfunc_1 (60 B): matches/0x00077480.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCRageModeTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CRageModeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77480));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77480* t = new (mem) TrackFactoryTemplate_77480();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072440();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x000774c0 fight::TrackFactoryTemplate<CRageModeTrack>::vfunc_5 (59 B): matches/0x000774c0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCRageModeTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CRageModeTrack>::vfunc_5() {
    Obj_774c0* p = (Obj_774c0*)FUN_0008d690((int)sizeof(Obj_774c0));
    if (p) {
        p->Init();
        p->vptr = ((hulk_intptr)DAT_003fc058);
        p->mc = 0;
        p->m10 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f702c0e2 {

// 0x00077500 fight::TrackFactoryTemplate<CRageModeTrack>::vfunc_2 (43 B): matches/0x00077500.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f702c0e2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_77500;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f702c0e2
