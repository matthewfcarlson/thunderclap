// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012ae90..0x0012af40 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f06dc002 {
#define TREE_TU_END }
namespace fn_f06dc002 {} using namespace fn_f06dc002;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f06dc002 {
class TrackFactoryTemplate_12ae90 {
  public:
    TrackFactoryTemplate_12ae90() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00129270();
extern "C" void* __cdecl alloc(hulk_uintptr);
extern "C" void* g_TargetClearTrackVtable;
struct Obj_12aed0 {
    void* vptr;
    int pad;
    int x;
    int y;
    unsigned char z;
    void initBase();
};
extern int g_vftable_12af10;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f06dc002

// 0x0012ae90 fight::TrackFactoryCasterTemplate<hulkfight::ai::TargetClearTrack>::vfunc_1 (60 B): matches/0x0012ae90.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTargetClearTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::TargetClearTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12ae90));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12ae90* t = new (mem) TrackFactoryTemplate_12ae90();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00129270();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f06dc002 {

// 0x0012aed0 fight::TrackFactoryTemplate<hulkfight::ai::TargetClearTrack>::vfunc_5 (56 B): matches/0x0012aed0.cpp
// sym: ?factory@fn_f06dc002@@YAPAUObj_12aed0@1@XZ
Obj_12aed0* factory() {
    Obj_12aed0* p = (Obj_12aed0*)alloc(0x14);
    if (p) {
        p->initBase();
        p->vptr = &g_TargetClearTrackVtable;
        p->y = 0;
        p->z = 0;
        p->x = 1;
        return p;
    }
    return 0;
}


// 0x0012af10 fight::TrackFactoryTemplate<hulkfight::ai::TargetClearTrack>::vfunc_2 (43 B): matches/0x0012af10.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f06dc002@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12af10;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f06dc002
