// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001815a0..0x00181640 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSpawnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f21d28b8 {
#define TREE_TU_END }
namespace fn_f21d28b8 {} using namespace fn_f21d28b8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f21d28b8 {
extern int* gTable_1815c0;
class CCondition_1815c0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1815d0 {
  public:
    Track_1815d0();
    virtual void f();
    int x;
    int flag;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class PropSpawnTrack : public Track_1815d0 {
  public:
    PropSpawnTrack();
    virtual void f();
    int a, b;
    char gap[4];
    Sub s;
    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
};


// 0x001815a0 FUN_001815a0 (19 B): matches/0x001815a0.cpp
// sym: ?FUN_001815a0@fn_f21d28b8@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001815a0() {
    FUN_00234810(((char*)&DAT_004e14e0), ((char*)&DAT_004e14e4));
}

} // namespace fn_f21d28b8

// 0x001815c0 hulkfight::motion::PropSpawnTrack::vfunc_0 (16 B): matches/0x001815c0.cpp
// sym: ?vfunc_0@PropSpawnTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropSpawnTrack::vfunc_0(int index) {
    int* p = gTable_1815c0;
    return p[index];
}

namespace fn_f21d28b8 {

// 0x001815d0 FUN_001815d0 (79 B): matches/0x001815d0.cpp
// sym: ??0PropSpawnTrack@fn_f21d28b8@@QAE@XZ
PropSpawnTrack::PropSpawnTrack()
    : a(0), b(0), d0(0), d1(0), d2(0), d3(0), d4(0), d5(0), d6(0), d7(0), d8(0), d9(0), d10(0), d11(0) {
    flag = 1;
}

} // namespace fn_f21d28b8

// 0x00181620 hulkfight::motion::PropSpawnTrack::vfunc_6 (4 B): matches/0x00181620.cpp
// sym: ?vfunc_6@PropSpawnTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropSpawnTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00181630 hulkfight::motion::PropSpawnTrack::vfunc_7 (7 B): matches/0x00181630.cpp
// sym: ?vfunc_7@PropSpawnTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropSpawnTrack::vfunc_7() {
    return DAT_003f32e0;
}

