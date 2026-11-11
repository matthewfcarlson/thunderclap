// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014dc70..0x0014dd20 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionFloatTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f54c50a4 {
#define TREE_TU_END }
namespace fn_f54c50a4 {} using namespace fn_f54c50a4;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f54c50a4 {
extern int* gTable_14dc90;
class CCondition_14dc90 {
  public:
    virtual int vfunc_0(int);
};
class Track_14dca0 {
  public:
    Track_14dca0();
    virtual void f();
    char pad[8];
};
class Part_14dca0 {
  public:
    Part_14dca0();
    char pad[8];
};
class HitReactionFloatTrack : public Track_14dca0 {
  public:
    HitReactionFloatTrack();
    virtual void f();
    int a, b, c;
    Part_14dca0 part;
    int x20, x24;
    float x28, x2c;
    int x30, x34, x38, x3c, x40, x44, x48, x4c;
    char x50;
};
extern float gNegOne;


// 0x0014dc70 FUN_0014dc70 (19 B): matches/0x0014dc70.cpp
// sym: ?FUN_0014dc70@fn_f54c50a4@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014dc70() {
    FUN_00234810(((char*)&DAT_004e10e0), ((char*)&DAT_004e10e4));
}

} // namespace fn_f54c50a4

// 0x0014dc90 hulkfight::motion::HitReactionFloatTrack::vfunc_0 (16 B): matches/0x0014dc90.cpp
// sym: ?vfunc_0@HitReactionFloatTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitReactionFloatTrack::vfunc_0(int index) {
    int* p = gTable_14dc90;
    return p[index];
}

namespace fn_f54c50a4 {

// 0x0014dca0 FUN_0014dca0 (90 B): matches/0x0014dca0.cpp
// sym: ??0HitReactionFloatTrack@fn_f54c50a4@@QAE@XZ
HitReactionFloatTrack::HitReactionFloatTrack()
    : a(0), b(0), c(0), part(), x20(0), x24(0), x28(-1.0f), x2c(-1.0f), x30(0), x34(0), x38(0), x3c(0),
      x40(0), x44(0), x48(0), x4c(0), x50(0) {
    *(int*)((char*)this + 8) = 3;
}

} // namespace fn_f54c50a4

// 0x0014dd00 hulkfight::motion::HitReactionFloatTrack::vfunc_6 (4 B): matches/0x0014dd00.cpp
// sym: ?vfunc_6@HitReactionFloatTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitReactionFloatTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014dd10 hulkfight::motion::HitReactionFloatTrack::vfunc_7 (7 B): matches/0x0014dd10.cpp
// sym: ?vfunc_7@HitReactionFloatTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitReactionFloatTrack::vfunc_7() {
    return gNegOne;
}

