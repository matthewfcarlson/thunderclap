// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170690..0x00170710 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetBreakTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f947dfa3 {
#define TREE_TU_END }
namespace fn_f947dfa3 {} using namespace fn_f947dfa3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f947dfa3 {
extern int* hulk_at_004e1350;
class CCondition_1706b0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1706c0 {
  public:
    Track_1706c0();
    virtual void v();
};
class TargetBreakTrack : public ::hulkfight::motion::TargetBreakTrack {
  public:
    TargetBreakTrack();
};


// 0x00170690 FUN_00170690 (19 B): matches/0x00170690.cpp
// sym: ?FUN_00170690@fn_f947dfa3@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170690() {
    FUN_00234810(((char*)&DAT_004e1350), ((char*)&DAT_004e1354));
}

} // namespace fn_f947dfa3

// 0x001706b0 hulkfight::motion::TargetBreakTrack::vfunc_0 (16 B): matches/0x001706b0.cpp
// sym: ?vfunc_0@TargetBreakTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetBreakTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1350;
    return p[index];
}

namespace fn_f947dfa3 {

// 0x001706c0 FUN_001706c0 (32 B): matches/0x001706c0.cpp
// sym: ??0TargetBreakTrack@fn_f947dfa3@@QAE@XZ
TargetBreakTrack::TargetBreakTrack() {
    f_0c = 0;
    f_08 = 1;
}

} // namespace fn_f947dfa3

// 0x001706e0 hulkfight::motion::TargetBreakTrack::vfunc_6 (4 B): matches/0x001706e0.cpp
// sym: ?vfunc_6@TargetBreakTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TargetBreakTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001706f0 hulkfight::motion::TargetBreakTrack::vfunc_7 (7 B): matches/0x001706f0.cpp
// sym: ?vfunc_7@TargetBreakTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::TargetBreakTrack::vfunc_7() {
    return DAT_003f32e0;
}

