// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016ff70..0x00170030 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointRelativeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f43bdd9b {
#define TREE_TU_END }
namespace fn_f43bdd9b {} using namespace fn_f43bdd9b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f43bdd9b {
class Track_16ff70 {
  public:
    virtual void f();
    virtual ~Track_16ff70();
};
class SnapToGroundTrack : public Track_16ff70 {
  public:
    virtual ~SnapToGroundTrack();
};
extern int* hulk_at_004e1308;
class CCondition_16ffa0 {
  public:
    virtual int vfunc_0(int);
};
class Track_16ffb0 {
  public:
    Track_16ffb0();
    virtual void f();
    char pad[4];
    int count;
};
class Sub_16ffb0 {
  public:
    Sub_16ffb0();
    char pad[8];
};
class JointRelativeTrack : public Track_16ffb0 {
  public:
    JointRelativeTrack();
    virtual void f();
    int a;
    float b;
    char gap[4];
    Sub_16ffb0 sub;
    char flag0;
    char flag1;
    char gap2[2];
    int x24, x28, x2c;
    char flag30;
    char gap3[3];
    int x34, x38, x3c, x40;
    float x44, x48;
};
struct Param_170020 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170020 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0016ff70 FUN_0016ff70 (11 B): matches/0x0016ff70.cpp
// sym: ??1SnapToGroundTrack@fn_f43bdd9b@@UAE@XZ
SnapToGroundTrack::~SnapToGroundTrack() {}


// 0x0016ff80 FUN_0016ff80 (19 B): matches/0x0016ff80.cpp
// sym: ?FUN_0016ff80@fn_f43bdd9b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0016ff80() {
    FUN_00234810(((char*)&DAT_004e1308), ((char*)&DAT_004e130c));
}

} // namespace fn_f43bdd9b

// 0x0016ffa0 hulkfight::motion::JointRelativeTrack::vfunc_0 (16 B): matches/0x0016ffa0.cpp
// sym: ?vfunc_0@JointRelativeTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::JointRelativeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1308;
    return p[index];
}

namespace fn_f43bdd9b {

// 0x0016ffb0 FUN_0016ffb0 (92 B): matches/0x0016ffb0.cpp
// sym: ??0JointRelativeTrack@fn_f43bdd9b@@QAE@XZ
JointRelativeTrack::JointRelativeTrack()
    : Track_16ffb0(), a(0), b(-1.0f), sub(), flag0(0), flag1(0), x24(0), x28(0), x2c(0), flag30(0), x34(0), x38(0),
      x3c(0) {
    _ReadWriteBarrier();
    x44 = 0.1f;
    x48 = 0.1f;
    x40 = -5;
    count = 1;
}

} // namespace fn_f43bdd9b

// 0x00170010 hulkfight::motion::JointRelativeTrack::vfunc_6 (4 B): matches/0x00170010.cpp
// sym: ?vfunc_6@JointRelativeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::JointRelativeTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170020 hulkfight::motion::JointRelativeTrack::vfunc_7 (7 B): matches/0x00170020.cpp
// sym: ?vfunc_7@JointRelativeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::JointRelativeTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

