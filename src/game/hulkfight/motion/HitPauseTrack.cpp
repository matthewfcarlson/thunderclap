// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014dd20..0x0014ddd0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPauseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f1dc0121 {
#define TREE_TU_END }
namespace fn_f1dc0121 {} using namespace fn_f1dc0121;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1dc0121 {
struct Tail_14dd20 {
    void Init_0027af50();
};
struct HitReactionFloatTrack_14dd20 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_00414270;
extern int* hulk_at_004e10e8;
class CCondition_14dd60 {
  public:
    virtual int vfunc_0(int);
};
class Track_14dd70 {
  public:
    Track_14dd70();
    char pad[8];
};
class HitPauseTrack : public Track_14dd70 {
  public:
    HitPauseTrack();
    int m8;
    int mC;
    int m10;
    int m14;
};


// 0x0014dd20 FUN_0014dd20 (25 B): matches/0x0014dd20.cpp
// sym: ?Run@HitReactionFloatTrack_14dd20@fn_f1dc0121@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void HitReactionFloatTrack_14dd20::Run() {
    vptr = &hulk_at_00414270;
    ((Tail_14dd20*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0014dd40 FUN_0014dd40 (19 B): matches/0x0014dd40.cpp
// sym: ?FUN_0014dd40@fn_f1dc0121@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014dd40() {
    FUN_00234810(((char*)&DAT_004e10e8), ((char*)&DAT_004e10ec));
}

} // namespace fn_f1dc0121

// 0x0014dd60 hulkfight::motion::HitPauseTrack::vfunc_0 (16 B): matches/0x0014dd60.cpp
// sym: ?vfunc_0@HitPauseTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitPauseTrack::vfunc_0(int index) {
    int* p = hulk_at_004e10e8;
    return p[index];
}

namespace fn_f1dc0121 {

// 0x0014dd70 FUN_0014dd70 (36 B): matches/0x0014dd70.cpp
// sym: ??0HitPauseTrack@fn_f1dc0121@@QAE@XZ
HitPauseTrack::HitPauseTrack() : Track_14dd70() {
    mC = 0;
    m10 = 0;
    m14 = 0;
    *(hulk_intptr*)this = (hulk_intptr)vt;
    m8 = 1;
}

} // namespace fn_f1dc0121

// 0x0014dda0 hulkfight::motion::HitPauseTrack::vfunc_6 (4 B): matches/0x0014dda0.cpp
// sym: ?vfunc_6@HitPauseTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitPauseTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0014ddb0 hulkfight::motion::HitPauseTrack::vfunc_7 (7 B): matches/0x0014ddb0.cpp
// sym: ?vfunc_7@HitPauseTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitPauseTrack::vfunc_7() {
    return DAT_003f32e0;
}

