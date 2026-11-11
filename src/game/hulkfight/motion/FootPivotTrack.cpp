// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170f60..0x00171010 (kind game, layer game, confidence high), dominant class hulkfight::motion::FootPivotTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f3dda925 {
#define TREE_TU_END }
namespace fn_f3dda925 {} using namespace fn_f3dda925;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3dda925 {
extern int* hulk_at_004e13b8;
class CCondition_170f80 {
  public:
    virtual int vfunc_0(int);
};
struct Param_171000 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_171000 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170f60 FUN_00170f60 (19 B): matches/0x00170f60.cpp
// sym: ?FUN_00170f60@fn_f3dda925@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170f60() {
    FUN_00234810(((char*)&DAT_004e13b8), ((char*)&DAT_004e13bc));
}

} // namespace fn_f3dda925

// 0x00170f80 hulkfight::motion::FootPivotTrack::vfunc_0 (16 B): matches/0x00170f80.cpp
// sym: ?vfunc_0@FootPivotTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FootPivotTrack::vfunc_0(int index) {
    int* p = hulk_at_004e13b8;
    return p[index];
}


// 0x00170f90 FUN_00170f90 (87 B): equivalent/0x00170f90.cpp [wrapped: conflict: hulkfight::motion::FootPivotTrack]
// sym: ??0FootPivotTrack@motion@hulkfight@fn_00170f90@@QAE@XZ
namespace fn_00170f90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170f90 @ 0x00170f90
namespace hulkfight { namespace motion {
struct Base {
    virtual void virtualMethod();
    char pad04[4];
    int field08;
    int field0c;
    float field10;
    char pad14[4];
    Base();
};
struct PivotPart {
    void FUN_0027af00();
};
struct FootPivotTrack : Base {
    PivotPart pivot;
    char pad19[7];
    int field20, field24, field28, field2c;
    float field30;
    char field34;
    char pad35[3];
    int field38;
    float field3c, field40;
    virtual void virtualMethod();
    FootPivotTrack();
};
FootPivotTrack::FootPivotTrack() : Base() {
    field0c = 0;
    field10 = -1.0f;
    pivot.FUN_0027af00();
    field20 = 0;
    field24 = 0;
    field28 = 0;
    field3c = .1f;
    field40 = .1f;
    field2c = 0;
    field34 = 0;
    field30 = 3.1415927f;
    field38 = -5;
    field08 = 1;
}
}}
} // namespace fn_00170f90


// 0x00170ff0 hulkfight::motion::FootPivotTrack::vfunc_6 (4 B): matches/0x00170ff0.cpp
// sym: ?vfunc_6@FootPivotTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FootPivotTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00171000 hulkfight::motion::FootPivotTrack::vfunc_7 (7 B): matches/0x00171000.cpp
// sym: ?vfunc_7@FootPivotTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FootPivotTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

