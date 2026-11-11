// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180d80..0x00180e20 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAnimationTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff3ae2d4 {
#define TREE_TU_END }
namespace fn_ff3ae2d4 {} using namespace fn_ff3ae2d4;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff3ae2d4 {
extern int* hulk_at_004e1488;
class CCondition_180da0 {
  public:
    virtual int vfunc_0(int);
};
class Track_180db0 {
  public:
    Track_180db0();
    virtual void f();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class PropAnimationTrack : public Track_180db0 {
  public:
    PropAnimationTrack();
    virtual void f();
    int a;
    float b;
    int c;
    Part part;
    float e;
    int d;
    float h;
    int g;
};
struct Param_180e10 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_180e10 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00180d80 FUN_00180d80 (19 B): matches/0x00180d80.cpp
// sym: ?FUN_00180d80@fn_ff3ae2d4@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180d80() {
    FUN_00234810(((char*)&DAT_004e1488), ((char*)&DAT_004e148c));
}

} // namespace fn_ff3ae2d4

// 0x00180da0 hulkfight::motion::PropAnimationTrack::vfunc_0 (16 B): matches/0x00180da0.cpp
// sym: ?vfunc_0@PropAnimationTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropAnimationTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1488;
    return p[index];
}

namespace fn_ff3ae2d4 {

// 0x00180db0 FUN_00180db0 (70 B): matches/0x00180db0.cpp
// sym: ??0PropAnimationTrack@fn_ff3ae2d4@@QAE@XZ
PropAnimationTrack::PropAnimationTrack()
    : Track_180db0(), a(0), b(-1.0f), c(0), part(), e(1.0f), d(0), h(-1.0f), g(0) {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_ff3ae2d4

// 0x00180e00 hulkfight::motion::PropAnimationTrack::vfunc_6 (4 B): matches/0x00180e00.cpp
// sym: ?vfunc_6@PropAnimationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropAnimationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00180e10 hulkfight::motion::PropAnimationTrack::vfunc_7 (7 B): matches/0x00180e10.cpp
// sym: ?vfunc_7@PropAnimationTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropAnimationTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

