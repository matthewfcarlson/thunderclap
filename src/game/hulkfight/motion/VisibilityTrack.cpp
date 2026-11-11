// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170ed0..0x00170f60 (kind game, layer game, confidence high), dominant class hulkfight::motion::VisibilityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f7c1487f {
#define TREE_TU_END }
namespace fn_f7c1487f {} using namespace fn_f7c1487f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7c1487f {
extern int* hulk_at_004e13b0;
class CCondition_170ef0 {
  public:
    virtual int vfunc_0(int);
};
class Track_170f00 {
  public:
    Track_170f00();
    virtual void f();
    char pad[4];
};
class VisibilityTrack : public Track_170f00 {
  public:
    VisibilityTrack();
    virtual void f();
    int value;
    int other;
    char flag;
};


// 0x00170ed0 FUN_00170ed0 (19 B): matches/0x00170ed0.cpp
// sym: ?FUN_00170ed0@fn_f7c1487f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170ed0() {
    FUN_00234810(((char*)&DAT_004e13b0), ((char*)&DAT_004e13b4));
}

} // namespace fn_f7c1487f

// 0x00170ef0 hulkfight::motion::VisibilityTrack::vfunc_0 (16 B): matches/0x00170ef0.cpp
// sym: ?vfunc_0@VisibilityTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VisibilityTrack::vfunc_0(int index) {
    int* p = hulk_at_004e13b0;
    return p[index];
}

namespace fn_f7c1487f {

// 0x00170f00 FUN_00170f00 (36 B): matches/0x00170f00.cpp
// sym: ??0VisibilityTrack@fn_f7c1487f@@QAE@XZ
VisibilityTrack::VisibilityTrack() : Track_170f00() {
    flag = 1;
    value = 1;
    other = 0;
}

} // namespace fn_f7c1487f

// 0x00170f30 hulkfight::motion::VisibilityTrack::vfunc_6 (4 B): matches/0x00170f30.cpp
// sym: ?vfunc_6@VisibilityTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::VisibilityTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170f40 hulkfight::motion::VisibilityTrack::vfunc_7 (7 B): matches/0x00170f40.cpp
// sym: ?vfunc_7@VisibilityTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::VisibilityTrack::vfunc_7() {
    return DAT_003f32e0;
}

