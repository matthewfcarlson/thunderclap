// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170570..0x00170600 (kind game, layer game, confidence high), dominant class hulkfight::motion::MotionStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f46464ee {
#define TREE_TU_END }
namespace fn_f46464ee {} using namespace fn_f46464ee;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f46464ee {
extern int* gTable_170590;
class CCondition_170590 {
  public:
    virtual int vfunc_0(int);
};
class Track_1705a0 {
  public:
    virtual void f();
    Track_1705a0();
    char pad[4];
};
class MotionStateTrack : public Track_1705a0 {
  public:
    virtual void f();
    MotionStateTrack();
    int a;
    int b;
    float c;
    int d;
};
struct Param_1705e0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1705e0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170570 FUN_00170570 (19 B): matches/0x00170570.cpp
// sym: ?FUN_00170570@fn_f46464ee@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170570() {
    FUN_00234810(((char*)&DAT_004e1340), ((char*)&DAT_004e1344));
}

} // namespace fn_f46464ee

// 0x00170590 hulkfight::motion::MotionStateTrack::vfunc_0 (16 B): matches/0x00170590.cpp
// sym: ?vfunc_0@MotionStateTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MotionStateTrack::vfunc_0(int index) {
    int* p = gTable_170590;
    return p[index];
}

namespace fn_f46464ee {

// 0x001705a0 FUN_001705a0 (40 B): matches/0x001705a0.cpp
// sym: ??0MotionStateTrack@fn_f46464ee@@QAE@XZ
MotionStateTrack::MotionStateTrack() {
    b = 0;
    d = 0;
    c = -1.0f;
    a = 1;
}

} // namespace fn_f46464ee

// 0x001705d0 hulkfight::motion::MotionStateTrack::vfunc_6 (4 B): matches/0x001705d0.cpp
// sym: ?vfunc_6@MotionStateTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::MotionStateTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x001705e0 hulkfight::motion::MotionStateTrack::vfunc_7 (7 B): matches/0x001705e0.cpp
// sym: ?vfunc_7@MotionStateTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::MotionStateTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

