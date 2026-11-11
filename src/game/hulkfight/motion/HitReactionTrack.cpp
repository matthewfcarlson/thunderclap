// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ddd0..0x0014de80 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f4b86578 {
#define TREE_TU_END }
namespace fn_f4b86578 {} using namespace fn_f4b86578;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4b86578 {
extern int* hulk_at_004e10f0;
class CCondition_14ddf0 {
  public:
    virtual int vfunc_0(int);
};
class Track_14de00 {
  public:
    virtual void f();
    char pad[4];
    int kind;
    Track_14de00();
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class HitReactionTrack : public Track_14de00 {
  public:
    int a, b, c;
    Sub sub;
    float value;
    int x;
    bool enabled;
    int p, q, r, s, t, u;
    bool flag;
    HitReactionTrack();
    virtual void f();
};
extern float hulk_at_003f3388;


// 0x0014ddd0 FUN_0014ddd0 (19 B): matches/0x0014ddd0.cpp
// sym: ?FUN_0014ddd0@fn_f4b86578@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014ddd0() {
    FUN_00234810(((char*)&DAT_004e10f0), ((char*)&DAT_004e10f4));
}

} // namespace fn_f4b86578

// 0x0014ddf0 hulkfight::motion::HitReactionTrack::vfunc_0 (16 B): matches/0x0014ddf0.cpp
// sym: ?vfunc_0@HitReactionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitReactionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e10f0;
    return p[index];
}

namespace fn_f4b86578 {

// 0x0014de00 FUN_0014de00 (81 B): matches/0x0014de00.cpp
// sym: ??0HitReactionTrack@fn_f4b86578@@QAE@XZ
HitReactionTrack::HitReactionTrack()
    : Track_14de00(), a(0), b(0), c(0), sub(), x(0), p(0), q(0), r(0), s(0), t(0), u(0), flag(false) {
    value = -1.0f;
    enabled = true;
    kind = 3;
}

} // namespace fn_f4b86578

// 0x0014de60 hulkfight::motion::HitReactionTrack::vfunc_6 (4 B): matches/0x0014de60.cpp
// sym: ?vfunc_6@HitReactionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitReactionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014de70 hulkfight::motion::HitReactionTrack::vfunc_7 (7 B): matches/0x0014de70.cpp
// sym: ?vfunc_7@HitReactionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitReactionTrack::vfunc_7() {
    return hulk_at_003f3388;
}

