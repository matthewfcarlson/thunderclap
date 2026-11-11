// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181360..0x001813f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ShieldArcTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f6222780 {
#define TREE_TU_END }
namespace fn_f6222780 {} using namespace fn_f6222780;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6222780 {
extern int* gTable_181380;
class CCondition_181380 {
  public:
    virtual int vfunc_0(int);
};
class Track_181390 {
  public:
    virtual void f();
    Track_181390();
};
class ShieldArcTrack : public Track_181390 {
  public:
    ShieldArcTrack();
    char pad[4];
    int a;
    int b;
    int c;
};


// 0x00181360 FUN_00181360 (19 B): matches/0x00181360.cpp
// sym: ?FUN_00181360@fn_f6222780@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00181360() {
    FUN_00234810(((char*)&DAT_004e14c0), ((char*)&DAT_004e14c4));
}

} // namespace fn_f6222780

// 0x00181380 hulkfight::motion::ShieldArcTrack::vfunc_0 (16 B): matches/0x00181380.cpp
// sym: ?vfunc_0@ShieldArcTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ShieldArcTrack::vfunc_0(int index) {
    int* p = gTable_181380;
    return p[index];
}

namespace fn_f6222780 {

// 0x00181390 FUN_00181390 (39 B): matches/0x00181390.cpp
// sym: ??0ShieldArcTrack@fn_f6222780@@QAE@XZ
ShieldArcTrack::ShieldArcTrack() : Track_181390() {
    b = 0;
    c = 0x3fc90fdb;
    a = 1;
}

} // namespace fn_f6222780

// 0x001813c0 hulkfight::motion::ShieldArcTrack::vfunc_6 (4 B): matches/0x001813c0.cpp
// sym: ?vfunc_6@ShieldArcTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::ShieldArcTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001813d0 hulkfight::motion::ShieldArcTrack::vfunc_7 (7 B): matches/0x001813d0.cpp
// sym: ?vfunc_7@ShieldArcTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::ShieldArcTrack::vfunc_7() {
    return DAT_003f32e0;
}

