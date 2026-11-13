// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076dc0..0x00076e80 (kind game, layer game, confidence high), dominant class CInvulnerableTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5010e76 {
#define TREE_TU_END }
namespace fn_f5010e76 {} using namespace fn_f5010e76;
namespace fn_f5010e76 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5010e76 {
class TrackFactoryTemplate_76dc0 {
  public:
    TrackFactoryTemplate_76dc0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_003fe9c0;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a970();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5010e76

// 0x00076dc0 fight::TrackFactoryCasterTemplate<CInvulnerableTrack>::vfunc_1 (60 B): matches/0x00076dc0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCInvulnerableTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CInvulnerableTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_76dc0));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_76dc0* t = new (mem) TrackFactoryTemplate_76dc0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072360();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f5010e76 {

// 0x00076e50 fight::TrackFactoryTemplate<CInvulnerableTrack>::vfunc_2 (43 B): matches/0x00076e50.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5010e76@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe9c0;
    base1_dtor_0006a970();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f5010e76
