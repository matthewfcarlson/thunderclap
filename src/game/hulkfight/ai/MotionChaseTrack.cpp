// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115c30..0x00115cd0 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionChaseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fe369724 {
#define TREE_TU_END }
namespace fn_fe369724 {} using namespace fn_fe369724;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fe369724 {
extern int* gTable_115c50;
class CCondition_115c50 {
  public:
    virtual int vfunc_0(int);
};
class Track_115c60 {
  public:
    Track_115c60();
    virtual void vf();
    char pad[8];
};
class MotionChaseTrack : public Track_115c60 {
  public:
    MotionChaseTrack();
    virtual void vf();
    int a;
    float b;
    int c, d, e, f;
    float h;
    int i;
};
struct Param_115cb0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115cb0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115c30 FUN_00115c30 (19 B): matches/0x00115c30.cpp
// sym: ?FUN_00115c30@fn_fe369724@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115c30() {
    FUN_00234810(((char*)&DAT_004e0c74), ((char*)&DAT_004e0c78));
}

} // namespace fn_fe369724

// 0x00115c50 hulkfight::ai::MotionChaseTrack::vfunc_0 (16 B): matches/0x00115c50.cpp
// sym: ?vfunc_0@MotionChaseTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionChaseTrack::vfunc_0(int index) {
    int* p = gTable_115c50;
    return p[index];
}

namespace fn_fe369724 {

// 0x00115c60 FUN_00115c60 (52 B): matches/0x00115c60.cpp
// sym: ??0MotionChaseTrack@fn_fe369724@@QAE@XZ
MotionChaseTrack::MotionChaseTrack() : Track_115c60() {
    a = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    i = 0;
    b = -1.0f;
    h = 1.0f;
}

} // namespace fn_fe369724

// 0x00115ca0 hulkfight::ai::MotionChaseTrack::vfunc_6 (4 B): matches/0x00115ca0.cpp
// sym: ?vfunc_6@MotionChaseTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionChaseTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115cb0 hulkfight::ai::MotionChaseTrack::vfunc_7 (7 B): matches/0x00115cb0.cpp
// sym: ?vfunc_7@MotionChaseTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionChaseTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

