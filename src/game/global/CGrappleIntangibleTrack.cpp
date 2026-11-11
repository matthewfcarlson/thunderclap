// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076790..0x00076860 (kind game, layer game, confidence high), dominant class CGrappleIntangibleTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbe768a4 {
#define TREE_TU_END }
namespace fn_fbe768a4 {} using namespace fn_fbe768a4;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fbe768a4 {
class TrackFactoryTemplate_76790 {
  public:
    TrackFactoryTemplate_76790() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern int g_vftable_767d0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
struct CFightNodeTimeCondition_76800 {
    virtual ~CFightNodeTimeCondition_76800();
    char pad[0x10];
    void Initialize();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* CIntangibleTrack_76830_vftable[];
class CIntangibleTrack_76830 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fbe768a4
class CGrappleIntangibleTrack : public CIntangibleTrack_76830 {
  public:
    CGrappleIntangibleTrack* vfunc_5(signed char flags);
};


// 0x00076790 fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::vfunc_1 (60 B): matches/0x00076790.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCGrappleIntangibleTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76790));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_76790* t = new (mem) TrackFactoryTemplate_76790();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071a80();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fbe768a4 {

// 0x000767d0 fight::TrackFactoryTemplate<CGrappleIntangibleTrack>::vfunc_2 (43 B): matches/0x000767d0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbe768a4@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_767d0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fbe768a4

// 0x00076800 fight::TrackFactoryTemplate<CGrappleIntangibleTrack>::vfunc_5 (38 B): matches/0x00076800.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCGrappleIntangibleTrack@@@fight@@UAEPAXXZ
// Same code shape as 0x000521a0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<CGrappleIntangibleTrack>::vfunc_5() {
    CFightNodeTimeCondition_76800* p = (CFightNodeTimeCondition_76800*)FUN_0008d690((int)sizeof(CFightNodeTimeCondition_76800));
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00076830 CGrappleIntangibleTrack::vfunc_5 (36 B): matches/0x00076830.cpp
// sym: ?vfunc_5@CGrappleIntangibleTrack@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleIntangibleTrack* CGrappleIntangibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CIntangibleTrack_76830_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

