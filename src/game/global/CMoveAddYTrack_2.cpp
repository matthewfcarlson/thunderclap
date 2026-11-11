// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077220..0x000772e0 (kind game, layer game, confidence high), dominant class CMoveAddYTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd7365db {
#define TREE_TU_END }
namespace fn_fd7365db {} using namespace fn_fd7365db;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd7365db {
class TrackFactoryTemplate_77220 {
  public:
    TrackFactoryTemplate_77220() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_000711c0();
} // namespace fn_fd7365db
class CMoveAddYTrack {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int pad4;
    int m8;
    int mc;
    float m10;
    float m14;
    int m18;
    void Init_00236d40();
};
namespace fn_fd7365db {
extern "C" void* __cdecl FUN_0008d690(int);
extern int hulk_at_003fbc60;
extern int hulk_at_003fea68;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069a50();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fd7365db

// 0x00077220 fight::TrackFactoryCasterTemplate<CMoveAddYTrack>::vfunc_1 (60 B): matches/0x00077220.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCMoveAddYTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CMoveAddYTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77220));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77220* t = new (mem) TrackFactoryTemplate_77220();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_000711c0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fd7365db {

// 0x00077260 fight::TrackFactoryTemplate<CMoveAddYTrack>::vfunc_5 (70 B): matches/0x00077260.cpp
// sym: ?target@fn_fd7365db@@YIPAVCMoveAddYTrack@@PAX@Z
CMoveAddYTrack* __fastcall target(void* self) {
    CMoveAddYTrack* p = (CMoveAddYTrack*)FUN_0008d690((int)sizeof(CMoveAddYTrack));
    if (p) {
        p->Init_00236d40();
        p->m10 = 1.0f;
        p->m14 = 1.0f;
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_003fbc60;
        p->mc = 0;
        p->m18 = 0;
        p->m8 = 1;
        return p;
    }
    return 0;
}


// 0x000772b0 fight::TrackFactoryTemplate<CMoveAddYTrack>::vfunc_2 (43 B): matches/0x000772b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd7365db@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fea68;
    base1_dtor_00069a50();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd7365db
