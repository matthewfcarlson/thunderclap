// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016fcd0..0x0016fd90 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f0083b8f {
#define TREE_TU_END }
namespace fn_f0083b8f {} using namespace fn_f0083b8f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0083b8f {
extern int* hulk_at_004e12e8;
class CCondition_16fcd0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_16fd80 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_16fd80 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

} // namespace fn_f0083b8f

// 0x0016fcd0 hulkfight::motion::JointTrackerTrack::vfunc_0 (16 B): matches/0x0016fcd0.cpp
// sym: ?vfunc_0@JointTrackerTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::JointTrackerTrack::vfunc_0(int index) {
    int* p = hulk_at_004e12e8;
    return p[index];
}


// 0x0016fce0 FUN_0016fce0 (140 B): equivalent/0x0016fce0.cpp [wrapped: conflict: hulkfight::motion::JointTrackerTrack]
// sym: ??0JointTrackerTrack@motion@hulkfight@fn_0016fce0@@QAE@XZ @de611c9254c1 @w05ad81d2d943
namespace fn_0016fce0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0016fce0 @ 0x0016fce0
struct Name_16fce0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_16fce0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_16fce0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class JointTrackerTrack : public Track_16fce0 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c;
    float f10;
    int pad14;
    Name_16fce0 joint;
    int f20, f24;
    float f28, f2c;
    int f30, f34;
    float f38, f3c, f40, f44, f48;
    char f4c;
    char pad4d[3];
    float f50, f54;
    int f58;
    int f5c;
    float f60, f64;

    JointTrackerTrack();
};
}
}

hulkfight::motion::JointTrackerTrack::JointTrackerTrack() {
    f0c = 0;
    f10 = -1.0f;
    joint.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f30 = 0;
    f34 = 0;
    f2c = -1.0f;
    f40 = 0.7853981852531433f;
    f48 = 0.7853981852531433f;
    f60 = 0.10000000149011612f;
    f64 = 0.10000000149011612f;
    f4c = 0;
    f58 = 0;
    f38 = 3.1415927410125732f;
    f3c = -0.7853981852531433f;
    f44 = -0.7853981852531433f;
    f50 = 1.5707963705062866f;
    f54 = 100.0f;
    f5c = -5;
    pad08 = 1;
}
} // namespace fn_0016fce0


// 0x0016fd70 hulkfight::motion::JointTrackerTrack::vfunc_6 (4 B): matches/0x0016fd70.cpp
// sym: ?vfunc_6@JointTrackerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::JointTrackerTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0016fd80 hulkfight::motion::JointTrackerTrack::vfunc_7 (7 B): matches/0x0016fd80.cpp
// sym: ?vfunc_7@JointTrackerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::JointTrackerTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

