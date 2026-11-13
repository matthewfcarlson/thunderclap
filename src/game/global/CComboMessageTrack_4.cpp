// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076040..0x000760f0 (kind game, layer game, confidence high), dominant class CComboMessageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb2f54bd {
#define TREE_TU_END }
namespace fn_fb2f54bd {} using namespace fn_fb2f54bd;
namespace fn_fb2f54bd {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb2f54bd {
class TrackFactoryTemplate_76040 {
  public:
    TrackFactoryTemplate_76040() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00070e30();
typedef unsigned int u32_76080;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_003fbbac;
class CComboMessageTrack_76080 {
  public:
    void Init_00236d40();
};
extern int hulk_at_003fe5e8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069790();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb2f54bd

// 0x00076040 fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_1 (60 B): matches/0x00076040.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCComboMessageTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76040));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_76040* t = new (mem) TrackFactoryTemplate_76040();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00070e30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00076080 fight::TrackFactoryTemplate<CComboMessageTrack>::vfunc_5 (63 B): matches/0x00076080.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCComboMessageTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CComboMessageTrack>::vfunc_5() {
    CComboMessageTrack_76080* p = (CComboMessageTrack_76080*)FUN_0008d690(0x54);
    if (p) {
        p->Init_00236d40();
        *(hulk_uintptr*)p = (hulk_uintptr)&hulk_at_003fbbac;
        *(u32_76080*)((char*)p + 0xc) = 0;
        *(u32_76080*)((char*)p + 0x50) = 0;
        *((char*)p + 0x10) = 0;
        *(u32_76080*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fb2f54bd {

// 0x000760c0 fight::TrackFactoryTemplate<CComboMessageTrack>::vfunc_2 (43 B): matches/0x000760c0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fb2f54bd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe5e8;
    base1_dtor_00069790();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fb2f54bd
