// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e450..0x0014e550 (kind game, layer game, confidence high), dominant class hulkfight::motion::NoHitPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f85c9a68 {
#define TREE_TU_END }
namespace fn_f85c9a68 {} using namespace fn_f85c9a68;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f85c9a68 {
extern int* hulk_at_004e1148;
class CCondition_14e470 {
  public:
    virtual int vfunc_0(int);
};
class Track_14e480 {
  public:
    Track_14e480();
    virtual void f();
};
class NoHitPushbackTrack : public ::hulkfight::motion::NoHitPushbackTrack {
  public:
    NoHitPushbackTrack();
};
struct Param_14e4c0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14e4c0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014e450 FUN_0014e450 (19 B): matches/0x0014e450.cpp
// sym: ?FUN_0014e450@fn_f85c9a68@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e450() {
    FUN_00234810(((char*)&DAT_004e1148), ((char*)&DAT_004e114c));
}

} // namespace fn_f85c9a68

// 0x0014e470 hulkfight::motion::NoHitPushbackTrack::vfunc_0 (16 B): matches/0x0014e470.cpp
// sym: ?vfunc_0@NoHitPushbackTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::NoHitPushbackTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1148;
    return p[index];
}

namespace fn_f85c9a68 {

// 0x0014e480 FUN_0014e480 (39 B): matches/0x0014e480.cpp
// sym: ??0NoHitPushbackTrack@fn_f85c9a68@@QAE@XZ
NoHitPushbackTrack::NoHitPushbackTrack() {
    f_0c = 0;
    f_10 = -1.0f;
    f_08 = 1;
}

} // namespace fn_f85c9a68

// 0x0014e4b0 hulkfight::motion::NoHitPushbackTrack::vfunc_6 (4 B): matches/0x0014e4b0.cpp
// sym: ?vfunc_6@NoHitPushbackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::NoHitPushbackTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e4c0 hulkfight::motion::NoHitPushbackTrack::vfunc_7 (7 B): matches/0x0014e4c0.cpp
// sym: ?vfunc_7@NoHitPushbackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::NoHitPushbackTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

