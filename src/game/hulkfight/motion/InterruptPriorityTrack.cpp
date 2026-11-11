// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014df20..0x0014dfb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff8bbe1b {
#define TREE_TU_END }
namespace fn_ff8bbe1b {} using namespace fn_ff8bbe1b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff8bbe1b {
extern int* hulk_at_004e1100;
class CCondition_14df40 {
  public:
    virtual int vfunc_0(int);
};
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Zero {
  public:
    int x;
    Zero() : x(0) {}
};
class Track_14df50 : public Base {
  public:
    Zero a;
    float val;
    Zero b;
    Track_14df50() : a(), b() {}
};
class InterruptPriorityTrack_14df50 : public Track_14df50 {
  public:
    InterruptPriorityTrack_14df50();
    virtual void f();
};
struct Param_14df90 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14df90 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014df20 FUN_0014df20 (19 B): matches/0x0014df20.cpp
// sym: ?FUN_0014df20@fn_ff8bbe1b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014df20() {
    FUN_00234810(((char*)&DAT_004e1100), ((char*)&DAT_004e1104));
}

} // namespace fn_ff8bbe1b

// 0x0014df40 hulkfight::motion::InterruptPriorityTrack::vfunc_0 (16 B): matches/0x0014df40.cpp
// sym: ?vfunc_0@InterruptPriorityTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::InterruptPriorityTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1100;
    return p[index];
}

namespace fn_ff8bbe1b {

// 0x0014df50 FUN_0014df50 (40 B): matches/0x0014df50.cpp
// sym: ??0InterruptPriorityTrack_14df50@fn_ff8bbe1b@@QAE@XZ
InterruptPriorityTrack_14df50::InterruptPriorityTrack_14df50() {
    val = -1.0f;
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_ff8bbe1b

// 0x0014df80 hulkfight::motion::InterruptPriorityTrack::vfunc_6 (4 B): matches/0x0014df80.cpp
// sym: ?vfunc_6@InterruptPriorityTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::InterruptPriorityTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0014df90 hulkfight::motion::InterruptPriorityTrack::vfunc_7 (7 B): matches/0x0014df90.cpp
// sym: ?vfunc_7@InterruptPriorityTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::InterruptPriorityTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

