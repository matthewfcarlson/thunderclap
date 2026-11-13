// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e300..0x0014e3b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GroundSlideTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f126326a {
#define TREE_TU_END }
namespace fn_f126326a {} using namespace fn_f126326a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f126326a {
extern int* hulk_at_004e1138;
class CCondition_14e320 {
  public:
    virtual int vfunc_0(int);
};
class Track_14e330 {
  public:
    Track_14e330();
    virtual void func();
};
class GroundSlideTrack : public ::hulkfight::motion::GroundSlideTrack {
  public:
    GroundSlideTrack();
};
struct Param_14e390 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14e390 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014e300 FUN_0014e300 (19 B): matches/0x0014e300.cpp
// sym: ?FUN_0014e300@fn_f126326a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e300() {
    FUN_00234810(((char*)&DAT_004e1138), ((char*)&DAT_004e113c));
}

} // namespace fn_f126326a

// 0x0014e320 hulkfight::motion::GroundSlideTrack::vfunc_0 (16 B): matches/0x0014e320.cpp
// sym: ?vfunc_0@GroundSlideTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GroundSlideTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1138;
    return p[index];
}

namespace fn_f126326a {

// 0x0014e330 FUN_0014e330 (77 B): matches/0x0014e330.cpp
// sym: ??0GroundSlideTrack@fn_f126326a@@QAE@XZ
GroundSlideTrack::GroundSlideTrack() {
    f_0c = 0;
    f_14 = 0;
    f_20 = 0;
    f_30 = 0;
    f_34 = 0;
    f_10 = -1.0f;
    f_18 = 0.5f;
    f_1c = 20.0f;
    f_24 = 10.0f;
    f_28 = 100.0f;
    f_2c = -5;
}

} // namespace fn_f126326a

// 0x0014e380 hulkfight::motion::GroundSlideTrack::vfunc_6 (4 B): matches/0x0014e380.cpp
// sym: ?vfunc_6@GroundSlideTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GroundSlideTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e390 hulkfight::motion::GroundSlideTrack::vfunc_7 (7 B): matches/0x0014e390.cpp
// sym: ?vfunc_7@GroundSlideTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::GroundSlideTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

