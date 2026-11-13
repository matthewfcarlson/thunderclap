// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115a30..0x00115ad0 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionBoostTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fc9fa3b6 {
#define TREE_TU_END }
namespace fn_fc9fa3b6 {} using namespace fn_fc9fa3b6;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fc9fa3b6 {
extern int* hulk_at_004e0c5c;
class CCondition_115a50 {
  public:
    virtual int vfunc_0(int);
};
class Track_115a60 {
  public:
    Track_115a60();
    virtual void f();
    char pad[8];
};
class MotionBoostTrack : public Track_115a60 {
  public:
    MotionBoostTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f0;
    float g;
    int h;
};
struct Param_115ab0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115ab0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115a30 FUN_00115a30 (19 B): matches/0x00115a30.cpp
// sym: ?FUN_00115a30@fn_fc9fa3b6@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115a30(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0c5c), ((char*)&DAT_004e0c60));
}

} // namespace fn_fc9fa3b6

// 0x00115a50 hulkfight::ai::MotionBoostTrack::vfunc_0 (16 B): matches/0x00115a50.cpp
// sym: ?vfunc_0@MotionBoostTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionBoostTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0c5c;
    return p[index];
}

namespace fn_fc9fa3b6 {

// 0x00115a60 FUN_00115a60 (52 B): matches/0x00115a60.cpp
// sym: ??0MotionBoostTrack@fn_fc9fa3b6@@QAE@XZ
MotionBoostTrack::MotionBoostTrack() : a(0), c(0), d(0), e(0), f0(0), h(0) {
    b = -1.0f;
    g = 1.0f;
}

} // namespace fn_fc9fa3b6

// 0x00115aa0 hulkfight::ai::MotionBoostTrack::vfunc_6 (4 B): matches/0x00115aa0.cpp
// sym: ?vfunc_6@MotionBoostTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionBoostTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115ab0 hulkfight::ai::MotionBoostTrack::vfunc_7 (7 B): matches/0x00115ab0.cpp
// sym: ?vfunc_7@MotionBoostTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionBoostTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

