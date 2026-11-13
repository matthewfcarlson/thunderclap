// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076c50..0x00076d00 (kind game, layer game, confidence high), dominant class CIntangibleToActorsTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1b1ed82 {
#define TREE_TU_END }
namespace fn_f1b1ed82 {} using namespace fn_f1b1ed82;
namespace fn_f1b1ed82 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f1b1ed82 {
class TrackFactoryTemplate_76c50 {
  public:
    TrackFactoryTemplate_76c50() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00071b20();
class CIntangibleToActorsTrack_76c90 {
  public:
    void Init_00236d40();
    int* vptr;
    char pad[4];
    int one;
    int zero;
    float minus;
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fbe40;
extern int hulk_at_003fe988;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a1e0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f1b1ed82

// 0x00076c50 fight::TrackFactoryCasterTemplate<CIntangibleToActorsTrack>::vfunc_1 (60 B): matches/0x00076c50.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCIntangibleToActorsTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CIntangibleToActorsTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76c50));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_76c50* t = new (mem) TrackFactoryTemplate_76c50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071b20();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076c90 fight::TrackFactoryTemplate<CIntangibleToActorsTrack>::vfunc_5 (59 B): matches/0x00076c90.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCIntangibleToActorsTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CIntangibleToActorsTrack>::vfunc_5() {
    CIntangibleToActorsTrack_76c90* p = (CIntangibleToActorsTrack_76c90*)FUN_0008d690((int)sizeof(CIntangibleToActorsTrack_76c90));
    if (p) {
        p->Init_00236d40();
        p->vptr = &hulk_at_003fbe40;
        p->zero = 0;
        p->minus = -1.0f;
        p->one = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f1b1ed82 {

// 0x00076cd0 fight::TrackFactoryTemplate<CIntangibleToActorsTrack>::vfunc_2 (43 B): matches/0x00076cd0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f1b1ed82@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe988;
    base1_dtor_0006a1e0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f1b1ed82
