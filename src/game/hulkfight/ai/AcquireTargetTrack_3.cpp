// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012af40..0x0012b010 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f92a9ee4 {
#define TREE_TU_END }
namespace fn_f92a9ee4 {} using namespace fn_f92a9ee4;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f92a9ee4 {
class TrackFactoryTemplate_12af40 {
  public:
    TrackFactoryTemplate_12af40() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129310();
class Child {
  public:
    Child();
};
extern char hulk_at_0040ffa4[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int hulk_at_00410b64;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00124370();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f92a9ee4

// 0x0012af40 fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_1 (60 B): matches/0x0012af40.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12af40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12af40* t = new (mem) TrackFactoryTemplate_12af40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129310();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012af80 fight::TrackFactoryTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_5 (87 B): matches/0x0012af80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_5() {
    Child* p = (Child*)FUN_0008d690(0x2c);
    if (p) {
        p->Child::Child();
        *(int*)((char*)p + 0xc) = 0;
        _ReadWriteBarrier();
        *(float*)((char*)p + 0x10) = -1.0f;
        *(char*)((char*)p + 0x1c) = 0;
        *(void**)p = hulk_at_0040ffa4;
        *(float*)((char*)p + 0x14) = 6.2831855f;
        *(float*)((char*)p + 0x18) = 100.0f;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        _ReadWriteBarrier();
        *(float*)((char*)p + 0x28) = -1.0f;
        *(int*)((char*)p + 0x8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f92a9ee4 {

// 0x0012afe0 fight::TrackFactoryTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_2 (43 B): matches/0x0012afe0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f92a9ee4@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00410b64;
    base1_dtor_00124370();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f92a9ee4
