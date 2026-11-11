// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170870..0x00170950 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointPivotTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f30cb024 {
#define TREE_TU_END }
namespace fn_f30cb024 {} using namespace fn_f30cb024;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f30cb024 {
extern int* hulk_at_004e1368;
class CCondition_170890 {
  public:
    virtual int vfunc_0(int);
};
struct Param_170940 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170940 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170870 FUN_00170870 (19 B): matches/0x00170870.cpp
// sym: ?FUN_00170870@fn_f30cb024@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170870() {
    FUN_00234810(((char*)&DAT_004e1368), ((char*)&DAT_004e136c));
}

} // namespace fn_f30cb024

// 0x00170890 hulkfight::motion::JointPivotTrackerTrack::vfunc_0 (16 B): matches/0x00170890.cpp
// sym: ?vfunc_0@JointPivotTrackerTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::JointPivotTrackerTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1368;
    return p[index];
}


// 0x001708a0 FUN_001708a0 (129 B): equivalent/0x001708a0.cpp [wrapped: conflict: hulkfight::motion::JointPivotTrackerTrack]
// sym: ?FUN_001708a0@JointPivotTrackerTrack@motion@hulkfight@fn_001708a0@@QAEPAV1234@XZ @1647db850177 @w6368b6923a7e
inline void *operator new(size_t, void *p) { return p; }
namespace fn_001708a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001708a0 @ 0x001708a0


struct JointPivotTrackerTrack_1708a0 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_1708a0 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class JointPivotTrackerTrack {
public:
    virtual hulk_intptr vfunc_0_00170890(int);
    int f04;
    int f08;
    int f0c;
    float f10;
    char pad14[4];
    Name8_1708a0 n18;
    int f20, f24;
    float f28, f2c;
    int f30, f34;
    float f38, f3c, f40;
    char b44;
    char pad45[3];
    float f48, f4c;
    int f50, f54;
    float f58, f5c;

    JointPivotTrackerTrack() {}
    JointPivotTrackerTrack *FUN_001708a0();
};
}
}

hulkfight::motion::JointPivotTrackerTrack *hulkfight::motion::JointPivotTrackerTrack::FUN_001708a0()
{
    ((JointPivotTrackerTrack_1708a0 *)this)->FUN_00236d40();
    new (this) JointPivotTrackerTrack;
    f0c = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f30 = 0;
    f34 = 0;
    f2c = -1.0f;
    f38 = 3.1415927f;
    f40 = 3.1415927f;
    f58 = 0.1f;
    f5c = 0.1f;
    b44 = 0;
    f50 = 0;
    f3c = -3.1415927f;
    f48 = 1.5707964f;
    f4c = 100.0f;
    f54 = -5;
    f08 = 1;
    return this;
}
} // namespace fn_001708a0


// 0x00170930 hulkfight::motion::JointPivotTrackerTrack::vfunc_6 (4 B): matches/0x00170930.cpp
// sym: ?vfunc_6@JointPivotTrackerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::JointPivotTrackerTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170940 hulkfight::motion::JointPivotTrackerTrack::vfunc_7 (7 B): matches/0x00170940.cpp
// sym: ?vfunc_7@JointPivotTrackerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::JointPivotTrackerTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

