// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001702d0..0x001703a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::MoveJointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fe3bb521 {
#define TREE_TU_END }
namespace fn_fe3bb521 {} using namespace fn_fe3bb521;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fe3bb521 {
extern int* hulk_at_004e1328;
class CCondition_1702f0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_170390 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170390 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x001702d0 FUN_001702d0 (19 B): matches/0x001702d0.cpp
// sym: ?FUN_001702d0@fn_fe3bb521@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001702d0() {
    FUN_00234810(((char*)&DAT_004e1328), ((char*)&DAT_004e132c));
}

} // namespace fn_fe3bb521

// 0x001702f0 hulkfight::motion::MoveJointTrack::vfunc_0 (16 B): matches/0x001702f0.cpp
// sym: ?vfunc_0@MoveJointTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MoveJointTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1328;
    return p[index];
}


// 0x00170300 FUN_00170300 (128 B): equivalent/0x00170300.cpp [wrapped: conflict: hulkfight::motion::MoveJointTrack]
// sym: ??0MoveJointTrack@motion@hulkfight@fn_00170300@@QAE@XZ @1bd867199375 @w1bcb0025cc76
namespace fn_00170300 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170300 @ 0x00170300
struct Name_170300 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_170300 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_170300() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class MoveJointTrack : public Track_170300 {
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
    int f14;
    Name_170300 joint;
    Name_170300 target;
    int f28, f2c, f30, f34, f38;
    float f3c;
    int f40;
    float f44;
    int f48;
    float f4c, f50;
    char f54;
    char pad55[3];
    int f58, f5c, f60;

    MoveJointTrack();
};
}
}

hulkfight::motion::MoveJointTrack::MoveJointTrack() {
    f0c = 0;
    f10 = -1.0f;
    f14 = -1;
    joint.FUN_0027af00();
    target.FUN_0027af00();
    f28 = 0; f2c = 0; f30 = 0; f34 = 0; f38 = 0;
    f3c = -1.0f;
    f40 = 0;
    f48 = 0;
    f5c = 0;
    f60 = 0;
    f54 = 1;
    pad08 = 1;
    f44 = 10.0f;
    f4c = 40.0f;
    f50 = 100.0f;
    f58 = -5;
}
} // namespace fn_00170300


// 0x00170380 hulkfight::motion::MoveJointTrack::vfunc_6 (4 B): matches/0x00170380.cpp
// sym: ?vfunc_6@MoveJointTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::MoveJointTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170390 hulkfight::motion::MoveJointTrack::vfunc_7 (7 B): matches/0x00170390.cpp
// sym: ?vfunc_7@MoveJointTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::MoveJointTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

