// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e160..0x0014e1f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackAddTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f940e47d {
#define TREE_TU_END }
namespace fn_f940e47d {} using namespace fn_f940e47d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f940e47d {
extern int* hulk_at_004e1120;
class CCondition_14e180 {
  public:
    virtual int vfunc_0(int);
};
class Track_14e190 {
  public:
    Track_14e190();
    virtual hulk_intptr Fnf_0014e180(int);
    char pad[4];
};
class HitPushbackAddTrack : public ::hulkfight::motion::HitPushbackAddTrack {
  public:
    HitPushbackAddTrack();
};


// 0x0014e160 FUN_0014e160 (19 B): matches/0x0014e160.cpp
// sym: ?FUN_0014e160@fn_f940e47d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e160() {
    FUN_00234810(((char*)&DAT_004e1120), ((char*)&DAT_004e1124));
}

} // namespace fn_f940e47d

// 0x0014e180 hulkfight::motion::HitPushbackAddTrack::vfunc_0 (16 B): matches/0x0014e180.cpp
// sym: ?vfunc_0@HitPushbackAddTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitPushbackAddTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1120;
    return p[index];
}

namespace fn_f940e47d {

// 0x0014e190 FUN_0014e190 (39 B): matches/0x0014e190.cpp
// sym: ??0HitPushbackAddTrack@fn_f940e47d@@QAE@XZ
HitPushbackAddTrack::HitPushbackAddTrack() {
    f_0c = 0;
    f_10 = 1.0f;
    f_08 = 1;
}

} // namespace fn_f940e47d

// 0x0014e1c0 hulkfight::motion::HitPushbackAddTrack::vfunc_6 (4 B): matches/0x0014e1c0.cpp
// sym: ?vfunc_6@HitPushbackAddTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitPushbackAddTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e1d0 hulkfight::motion::HitPushbackAddTrack::vfunc_7 (7 B): matches/0x0014e1d0.cpp
// sym: ?vfunc_7@HitPushbackAddTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitPushbackAddTrack::vfunc_7() {
    return DAT_003f32e0;
}

