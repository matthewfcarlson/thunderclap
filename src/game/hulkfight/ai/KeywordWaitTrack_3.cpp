// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114af0..0x00114bb0 (kind game, layer game, confidence high), dominant class hulkfight::ai::KeywordWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f01c5110 {
#define TREE_TU_END }
namespace fn_f01c5110 {} using namespace fn_f01c5110;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f01c5110 {
class TrackFactoryTemplate_114af0 {
  public:
    TrackFactoryTemplate_114af0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112aa0();
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int hulk_at_0040dc44;
class Helper_114b30 {
  public:
    void Init_00236d40();
};
class SetupObj_114b30 {
  public:
    void Setup_0027af00();
};
struct KeywordWaitTrack {
    hulk_uintptr vptr;
    unsigned int pad04;
    int field08;
    int field0c;
    float field10;
    char pad14[4];
    char field18[8];
    char field20;
};
extern int hulk_at_0040e9f4;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010d2c0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f01c5110

// 0x00114af0 fight::TrackFactoryCasterTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_1 (60 B): matches/0x00114af0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114af0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114af0* t = new (mem) TrackFactoryTemplate_114af0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112aa0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f01c5110 {

// 0x00114b30 fight::TrackFactoryTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_5 (71 B): matches/0x00114b30.cpp
// sym: ?target@fn_f01c5110@@YAPAUKeywordWaitTrack@1@XZ
KeywordWaitTrack* __cdecl target() {
    KeywordWaitTrack* p = (KeywordWaitTrack*)FUN_0008d690(0x28);
    if (p) {
        ((Helper_114b30*)p)->Init_00236d40();
        p->vptr = (hulk_uintptr)&hulk_at_0040dc44;
        p->field0c = 0;
        p->field10 = -1.0f;
        ((SetupObj_114b30*)((char*)p + 0x18))->Setup_0027af00();
        p->field20 = 0;
        p->field08 = 1;
        return p;
    }
    return 0;
}


// 0x00114b80 fight::TrackFactoryTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_2 (43 B): matches/0x00114b80.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f01c5110@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e9f4;
    base1_dtor_0010d2c0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f01c5110
