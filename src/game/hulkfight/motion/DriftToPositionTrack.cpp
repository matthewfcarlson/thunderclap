// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001703a0..0x00170460 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToPositionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f6866440 {
#define TREE_TU_END }
namespace fn_f6866440 {} using namespace fn_f6866440;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6866440 {
extern int hulk_at_00417a18;
class Part_1703a0 {
  public:
    int x[2];
    void Init_0027af50();
};
class MoveJointTrack_1703a0 {
  public:
    hulk_intptr vt;
    char pad[0x14];
    Part_1703a0 p18;
    Part_1703a0 p20;
    void Final_00236d60();
    void Run();
};
extern int* hulk_at_004e1330;
class CCondition_1703f0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_170450 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170450 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x001703a0 FUN_001703a0 (33 B): matches/0x001703a0.cpp
// sym: ?Run@MoveJointTrack_1703a0@fn_f6866440@@QAEXXZ
void MoveJointTrack_1703a0::Run() {
    vt = (hulk_intptr)&hulk_at_00417a18;
    p20.Init_0027af50();
    p18.Init_0027af50();
    Final_00236d60();
}


// 0x001703d0 FUN_001703d0 (19 B): matches/0x001703d0.cpp
// sym: ?FUN_001703d0@fn_f6866440@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001703d0() {
    FUN_00234810(((char*)&DAT_004e1330), ((char*)&DAT_004e1334));
}

} // namespace fn_f6866440

// 0x001703f0 hulkfight::motion::DriftToPositionTrack::vfunc_0 (16 B): matches/0x001703f0.cpp
// sym: ?vfunc_0@DriftToPositionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::DriftToPositionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1330;
    return p[index];
}


// 0x00170400 FUN_00170400 (59 B): equivalent/0x00170400.cpp [wrapped: conflict: hulkfight::motion::DriftToPositionTrack]
// sym: ??0DriftToPositionTrack@motion@hulkfight@fn_00170400@@QAE@XZ @6f211d54b0d8 @wfcb01c7746aa
namespace fn_00170400 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170400 @ 0x00170400
namespace hulkfight { namespace motion {
struct FUN_00236d40 {
    virtual void tick();
    FUN_00236d40();
    char padding[4];
    int active;
    int value;
    float factor;
    bool enabled;
    char pad15[3];
    int position;
    int velocity;
    int acceleration;
    bool flag;
    bool flag2;
    char pad26[2];
    int target;
};
struct DriftToPositionTrack : FUN_00236d40 {
    virtual void tick();
    DriftToPositionTrack();
};
DriftToPositionTrack::DriftToPositionTrack() {
    value = 0;
    enabled = false;
    factor = -1.0f;
    position = 0;
    velocity = 0;
    acceleration = 0;
    flag2 = false;
    target = 0;
    flag = true;
    active = 1;
}
} }
} // namespace fn_00170400


// 0x00170440 hulkfight::motion::DriftToPositionTrack::vfunc_6 (4 B): matches/0x00170440.cpp
// sym: ?vfunc_6@DriftToPositionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::DriftToPositionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170450 hulkfight::motion::DriftToPositionTrack::vfunc_7 (7 B): matches/0x00170450.cpp
// sym: ?vfunc_7@DriftToPositionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::DriftToPositionTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

