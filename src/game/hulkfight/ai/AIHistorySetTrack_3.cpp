// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114c70..0x00114d30 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistorySetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f38dd81c {
#define TREE_TU_END }
namespace fn_f38dd81c {} using namespace fn_f38dd81c;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f38dd81c {
class TrackFactoryTemplate_114c70 {
  public:
    TrackFactoryTemplate_114c70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112d30();
extern "C" char DAT_0040dca4[];
extern "C" void* FUN_0008d690(hulk_uintptr);
class Sub_114cb0 {
  public:
    void Init_0027af00();
};
class AIHistorySetTrack {
  public:
    int pad0;
    int x1;
    int x2;
    int x3;
    float val;
    unsigned char flag;
    char pad[3];
    Sub_114cb0 sub;
    int tail;
    void BaseInit_00236d40();
};
extern int hulk_at_0040ea2c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010d400();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f38dd81c

// 0x00114c70 fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_1 (60 B): matches/0x00114c70.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114c70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_114c70* t = new (mem) TrackFactoryTemplate_114c70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112d30();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f38dd81c {

// 0x00114cb0 fight::TrackFactoryTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_5 (71 B): matches/0x00114cb0.cpp
// sym: ?Factory@fn_f38dd81c@@YAPAVAIHistorySetTrack@1@XZ
AIHistorySetTrack* Factory() {
    AIHistorySetTrack* p = (AIHistorySetTrack*)FUN_0008d690((int)sizeof(AIHistorySetTrack));
    if (p) {
        p->BaseInit_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040dca4);
        p->x3 = 0;
        p->val = -1.0f;
        p->flag = 0;
        p->sub.Init_0027af00();
        p->x2 = 1;
        return p;
    }
    return 0;
}


// 0x00114d00 fight::TrackFactoryTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_2 (43 B): matches/0x00114d00.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f38dd81c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040ea2c;
    base1_dtor_0010d400();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f38dd81c
