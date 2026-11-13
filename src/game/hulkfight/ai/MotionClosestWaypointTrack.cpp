// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115cd0..0x00115dd0 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fe7c4625 {
#define TREE_TU_END }
namespace fn_fe7c4625 {} using namespace fn_fe7c4625;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fe7c4625 {
extern int* hulk_at_004e0c7c;
class CCondition_115cf0 {
  public:
    virtual int vfunc_0(int);
};
class Track_115d00 {
  public:
    Track_115d00();
    virtual void vf();
    char pad[8];
};
class MotionClosestWaypointTrack : public ::hulkfight::ai::MotionClosestWaypointTrack {
  public:
    MotionClosestWaypointTrack();
};
struct Param_115d60 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115d60 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115cd0 FUN_00115cd0 (19 B): matches/0x00115cd0.cpp
// sym: ?FUN_00115cd0@fn_fe7c4625@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115cd0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0c7c), ((char*)&DAT_004e0c80));
}

} // namespace fn_fe7c4625

// 0x00115cf0 hulkfight::ai::MotionClosestWaypointTrack::vfunc_0 (16 B): matches/0x00115cf0.cpp
// sym: ?vfunc_0@MotionClosestWaypointTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionClosestWaypointTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0c7c;
    return p[index];
}

namespace fn_fe7c4625 {

// 0x00115d00 FUN_00115d00 (69 B): matches/0x00115d00.cpp
// sym: ??0MotionClosestWaypointTrack@fn_fe7c4625@@QAE@XZ
MotionClosestWaypointTrack::MotionClosestWaypointTrack() {
    f_0c = 0;
    f_10 = -1.0f;
    f_14 = 1.0f;
    f_18 = 0;
    f_1c = 0;
    f_20 = 0;
    f_24 = 0;
    f_28 = 0;
    f_29 = 0;
    f_2c = 0.2f;
    f_30 = 3.0f;}

} // namespace fn_fe7c4625

// 0x00115d50 hulkfight::ai::MotionClosestWaypointTrack::vfunc_6 (4 B): matches/0x00115d50.cpp
// sym: ?vfunc_6@MotionClosestWaypointTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionClosestWaypointTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115d60 hulkfight::ai::MotionClosestWaypointTrack::vfunc_7 (7 B): matches/0x00115d60.cpp
// sym: ?vfunc_7@MotionClosestWaypointTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionClosestWaypointTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

