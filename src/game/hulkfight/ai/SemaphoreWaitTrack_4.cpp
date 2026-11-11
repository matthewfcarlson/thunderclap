// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114de0..0x00114eb0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9e09596 {
#define TREE_TU_END }
namespace fn_f9e09596 {} using namespace fn_f9e09596;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f9e09596 {
class TrackFactoryTemplate_114de0 {
  public:
    TrackFactoryTemplate_114de0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112f10();
extern "C" char DAT_0040dd04[];
class SemaphoreWaitTrack_114e20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl alloc(hulk_uintptr);
struct BaseInit {
    void go();
};
struct MemberInit {
    void go();
};
extern int g_vftable_114e70;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f9e09596

// 0x00114de0 fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_1 (60 B): matches/0x00114de0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114de0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114de0* t = new (mem) TrackFactoryTemplate_114de0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112f10();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114e20 fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_5 (75 B): matches/0x00114e20.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_5() {
    SemaphoreWaitTrack_114e20* p = (SemaphoreWaitTrack_114e20*)alloc(0x28);
    if (p != 0) {
        ((BaseInit*)p)->go();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040dd04);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        ((MemberInit*)((char*)p + 0x18))->go();
        *((char*)p + 0x20) = 1;
        *((char*)p + 0x21) = 1;
        *(unsigned int*)((char*)p + 0x24) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f9e09596 {

// 0x00114e70 fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_2 (43 B): matches/0x00114e70.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f9e09596@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_114e70;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f9e09596
