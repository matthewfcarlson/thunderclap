// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000703e0..0x00070470 (kind game, layer game, confidence high), dominant class CSmartPropUpdateAttachmentTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcb33e3a {
#define TREE_TU_END }
namespace fn_fcb33e3a {} using namespace fn_fcb33e3a;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fcb33e3a {
class TrackFactoryTemplate_703e0 {
  public:
    TrackFactoryTemplate_703e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00065430();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_70420 {
    void* Init();
};
extern int g_vftable_70440;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcb33e3a

// 0x000703e0 fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_1 (60 B): matches/0x000703e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_703e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_703e0* t = new (mem) TrackFactoryTemplate_703e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00065430();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00070420 fight::TrackFactoryTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_5 (24 B): matches/0x00070420.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_70420*)p)->Init());
    return (void*)(0);
}

namespace fn_fcb33e3a {

// 0x00070440 fight::TrackFactoryTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_2 (43 B): matches/0x00070440.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fcb33e3a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_70440;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fcb33e3a
