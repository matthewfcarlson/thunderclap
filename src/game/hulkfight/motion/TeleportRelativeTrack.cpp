// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170c10..0x00170cb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportRelativeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f29ef6f2 {
#define TREE_TU_END }
namespace fn_f29ef6f2 {} using namespace fn_f29ef6f2;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f29ef6f2 {
extern int* hulk_at_004e1390;
class CCondition_170c30 {
  public:
    virtual int vfunc_0(int);
};
class Track_170c40 {
  public:
    Track_170c40();
    virtual void f();
    int b;
    int a;
};
struct First {
    int x1, x2;
    float x3;
    First() : x1(0), x2(0), x3(-1.0f) {}
};
struct Second {
    int x4, x5, x6;
    float x7;
    Second() : x4(0), x5(0), x6(0), x7(2.0f) {}
};
class TeleportRelativeTrack : public Track_170c40 {
  public:
    TeleportRelativeTrack();
    virtual void f();
    int x0;
    First first;
    Second second;
};


// 0x00170c10 FUN_00170c10 (19 B): matches/0x00170c10.cpp
// sym: ?FUN_00170c10@fn_f29ef6f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170c10() {
    FUN_00234810(((char*)&DAT_004e1390), ((char*)&DAT_004e1394));
}

} // namespace fn_f29ef6f2

// 0x00170c30 hulkfight::motion::TeleportRelativeTrack::vfunc_0 (16 B): matches/0x00170c30.cpp
// sym: ?vfunc_0@TeleportRelativeTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TeleportRelativeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1390;
    return p[index];
}

namespace fn_f29ef6f2 {

// 0x00170c40 FUN_00170c40 (59 B): matches/0x00170c40.cpp
// sym: ??0TeleportRelativeTrack@fn_f29ef6f2@@QAE@XZ
TeleportRelativeTrack::TeleportRelativeTrack() : x0(0) {
    a = 1;
}

} // namespace fn_f29ef6f2

// 0x00170c80 hulkfight::motion::TeleportRelativeTrack::vfunc_6 (4 B): matches/0x00170c80.cpp
// sym: ?vfunc_6@TeleportRelativeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TeleportRelativeTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00170c90 hulkfight::motion::TeleportRelativeTrack::vfunc_7 (7 B): matches/0x00170c90.cpp
// sym: ?vfunc_7@TeleportRelativeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::TeleportRelativeTrack::vfunc_7() {
    return DAT_003f32e0;
}

