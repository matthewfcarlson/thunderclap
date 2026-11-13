// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000703e0..0x00070470 (kind game, layer game, confidence high), dominant class CSmartPropUpdateAttachmentTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcb33e3a {
#define TREE_TU_END }
namespace fn_fcb33e3a {} using namespace fn_fcb33e3a;
namespace fn_fcb33e3a {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
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
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00065430();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_70420 {
    void* Init_00062360();
};
extern int hulk_at_003fd430;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00062330();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fcb33e3a

// 0x000703e0 fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_1 (60 B): matches/0x000703e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSmartPropUpdateAttachmentTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_703e0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
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
        return (void*)(((Track_70420*)p)->Init_00062360());
    return (void*)(0);
}

namespace fn_fcb33e3a {

// 0x00070440 fight::TrackFactoryTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_2 (43 B): matches/0x00070440.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fcb33e3a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fd430;
    base1_dtor_00062330();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fcb33e3a
