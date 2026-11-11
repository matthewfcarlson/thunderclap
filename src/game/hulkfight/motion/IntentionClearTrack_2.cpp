// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017eb10..0x0017ebc0 (kind game, layer game, confidence high), dominant class hulkfight::motion::IntentionClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd336137 {
#define TREE_TU_END }
namespace fn_fd336137 {} using namespace fn_fd336137;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd336137 {
class TrackFactoryTemplate_17eb10 {
  public:
    TrackFactoryTemplate_17eb10() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0017ac80();
extern "C" char DAT_00417cb8[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class IntentionClearTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int pad;
    int a;
    int b;
    int c;
    void Init_00236d40();
};
extern int hulk_at_00418f84;

} // namespace fn_fd336137

// 0x0017eb10 fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_1 (60 B): matches/0x0017eb10.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VIntentionClearTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_17eb10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_17eb10* t = new (mem) TrackFactoryTemplate_17eb10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0017ac80();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fd336137 {

// 0x0017eb50 fight::TrackFactoryTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_5 (59 B): matches/0x0017eb50.cpp
// sym: ?TrackFactoryTemplate_vfunc_5@fn_fd336137@@YAPAXXZ
void* __cdecl TrackFactoryTemplate_vfunc_5() {
    IntentionClearTrack* p = (IntentionClearTrack*)FUN_0008d690((int)sizeof(IntentionClearTrack));
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00417cb8);
        p->b = 0;
        p->c = 0xbf800000;
        p->a = 1;
        return p;
    }
    return 0;
}


// 0x0017eb90 fight::TrackFactoryTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_2 (43 B): matches/0x0017eb90.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd336137@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00418f84;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fd336137
