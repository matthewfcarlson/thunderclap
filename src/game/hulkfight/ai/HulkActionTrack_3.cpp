// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114a30..0x00114af0 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4a008a1 {
#define TREE_TU_END }
namespace fn_f4a008a1 {} using namespace fn_f4a008a1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f4a008a1 {
class TrackFactoryTemplate_114a30 {
  public:
    TrackFactoryTemplate_114a30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_001129a0();
typedef unsigned int u32_114a70;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Base_114a70 {
  public:
    void Init_00236d40();
};
class Member_114a70 {
  public:
    void Init_0027af00();
};
class HulkActionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int x[10];
};
extern int hulk_at_0040e9d8;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010d210();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4a008a1

// 0x00114a30 fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_1 (60 B): matches/0x00114a30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VHulkActionTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114a30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114a30* t = new (mem) TrackFactoryTemplate_114a30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_001129a0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f4a008a1 {

// 0x00114a70 fight::TrackFactoryTemplate<hulkfight::ai::HulkActionTrack>::vfunc_5 (74 B): matches/0x00114a70.cpp
// sym: ?target@fn_f4a008a1@@YAPAVHulkActionTrack@1@XZ
HulkActionTrack* target() {
    HulkActionTrack* p = (HulkActionTrack*)FUN_0008d690(0x28);
    if (p) {
        ((Base_114a70*)p)->Init_00236d40();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040dc14);
        *(u32_114a70*)((char*)p + 0xc) = 0;
        *(u32_114a70*)((char*)p + 0x10) = 0xbf800000;
        ((Member_114a70*)((char*)p + 0x18))->Init_0027af00();
        *(u32_114a70*)((char*)p + 0x20) = 0;
        *(u32_114a70*)((char*)p + 8) = 1;
        return p;
    }
    return (HulkActionTrack*)0L;
}


// 0x00114ac0 fight::TrackFactoryTemplate<hulkfight::ai::HulkActionTrack>::vfunc_2 (43 B): matches/0x00114ac0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f4a008a1@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e9d8;
    base1_dtor_0010d210();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4a008a1
