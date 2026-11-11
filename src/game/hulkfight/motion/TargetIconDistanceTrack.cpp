// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170a40..0x00170ae0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetIconDistanceTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff5a0fb8 {
#define TREE_TU_END }
namespace fn_ff5a0fb8 {} using namespace fn_ff5a0fb8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff5a0fb8 {
extern int* gTable_170a60;
class CCondition_170a60 {
  public:
    virtual int vfunc_0(int);
};
class Track_170a70 {
  public:
    Track_170a70();
    virtual void fn();
    int a;
    int flag;
    void* p;
    float x;
    void* q;
    float y;
    void* r;
};
class TargetIconDistanceTrack_170a70 : public Track_170a70 {
  public:
    TargetIconDistanceTrack_170a70();
    virtual void fn();
};
struct Param_170ac0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170ac0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170a40 FUN_00170a40 (19 B): matches/0x00170a40.cpp
// sym: ?FUN_00170a40@fn_ff5a0fb8@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170a40() {
    FUN_00234810(((char*)&DAT_004e1378), ((char*)&DAT_004e137c));
}

} // namespace fn_ff5a0fb8

// 0x00170a60 hulkfight::motion::TargetIconDistanceTrack::vfunc_0 (16 B): matches/0x00170a60.cpp
// sym: ?vfunc_0@TargetIconDistanceTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetIconDistanceTrack::vfunc_0(int index) {
    int* p = gTable_170a60;
    return p[index];
}

namespace fn_ff5a0fb8 {

// 0x00170a70 FUN_00170a70 (50 B): matches/0x00170a70.cpp
// sym: ??0TargetIconDistanceTrack_170a70@fn_ff5a0fb8@@QAE@XZ
TargetIconDistanceTrack_170a70::TargetIconDistanceTrack_170a70() {
    p = 0;
    q = 0;
    r = 0;
    x = -1.0f;
    y = 100.0f;
    flag = 1;
}

} // namespace fn_ff5a0fb8

// 0x00170ab0 hulkfight::motion::TargetIconDistanceTrack::vfunc_6 (4 B): matches/0x00170ab0.cpp
// sym: ?vfunc_6@TargetIconDistanceTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::TargetIconDistanceTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170ac0 hulkfight::motion::TargetIconDistanceTrack::vfunc_7 (7 B): matches/0x00170ac0.cpp
// sym: ?vfunc_7@TargetIconDistanceTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::TargetIconDistanceTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

