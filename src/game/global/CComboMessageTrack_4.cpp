// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076040..0x000760f0 (kind game, layer game, confidence high), dominant class CComboMessageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb2f54bd {
#define TREE_TU_END }
namespace fn_fb2f54bd {} using namespace fn_fb2f54bd;
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
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00070e30();
typedef unsigned int u32_76080;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int ComboVtable;
class CComboMessageTrack_76080 {
  public:
    void Init();
};
extern int g_vftable_760c0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb2f54bd

// 0x00076040 fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_1 (60 B): matches/0x00076040.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCComboMessageTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76040));
    if (mem) {
        ((InitHelper*)mem)->init();
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
        p->Init();
        *(hulk_uintptr*)p = (hulk_uintptr)&ComboVtable;
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
    m_vptr = (void*)&g_vftable_760c0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb2f54bd
