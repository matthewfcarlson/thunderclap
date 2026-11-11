// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114810..0x001148d0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7e6d7b9 {
#define TREE_TU_END }
namespace fn_f7e6d7b9 {} using namespace fn_f7e6d7b9;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f7e6d7b9 {
class TrackFactoryTemplate_114810 {
  public:
    TrackFactoryTemplate_114810() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112690();
extern "C" char DAT_0040db84[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TrackBase_114850 {
  public:
    void Init_00236d40();
};
class TrackTail {
  public:
    void Init_0027af00();
};
extern int hulk_at_0040e984;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010d060();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f7e6d7b9

// 0x00114810 fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_1 (60 B): matches/0x00114810.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114810));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114810* t = new (mem) TrackFactoryTemplate_114810();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112690();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114850 fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_5 (75 B): matches/0x00114850.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x28);
    if (p) {
        ((TrackBase_114850*)p)->Init_00236d40();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040db84);
        *(unsigned int*)(p + 0xc) = 0;
        *(unsigned int*)(p + 0x10) = 0xbf800000;
        ((TrackTail*)(p + 0x18))->Init_0027af00();
        p[0x20] = 0;
        p[0x21] = 0;
        *(unsigned int*)(p + 8) = 1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}

namespace fn_f7e6d7b9 {

// 0x001148a0 fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_2 (43 B): matches/0x001148a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f7e6d7b9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040e984;
    base1_dtor_0010d060();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f7e6d7b9
