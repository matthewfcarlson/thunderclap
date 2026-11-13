// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115ad0..0x00115b70 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionLocatorTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f3172cab {
#define TREE_TU_END }
namespace fn_f3172cab {} using namespace fn_f3172cab;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f3172cab {
extern int* hulk_at_004e0c64;
class CCondition_115af0 {
  public:
    virtual int vfunc_0(int);
};
class Track_115b00 {
  public:
    Track_115b00();
    virtual void f();
    char pad[4];
};
class Sub {
  public:
    void Init_0027af00();
};
class MotionLocatorTrack : public Track_115b00 {
  public:
    MotionLocatorTrack();
    virtual void f();
    char pad2[4];
    int a;
    float b, c;
    int d, e, f1, g;
    char h, i, j, k;
    char pad3[4];
    Sub sub;
};
struct Param_115b60 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115b60 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115ad0 FUN_00115ad0 (19 B): matches/0x00115ad0.cpp
// sym: ?FUN_00115ad0@fn_f3172cab@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115ad0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0c64), ((char*)&DAT_004e0c68));
}

} // namespace fn_f3172cab

// 0x00115af0 hulkfight::ai::MotionLocatorTrack::vfunc_0 (16 B): matches/0x00115af0.cpp
// sym: ?vfunc_0@MotionLocatorTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionLocatorTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0c64;
    return p[index];
}

namespace fn_f3172cab {

// 0x00115b00 FUN_00115b00 (70 B): matches/0x00115b00.cpp
// sym: ??0MotionLocatorTrack@fn_f3172cab@@QAE@XZ
MotionLocatorTrack::MotionLocatorTrack() : Track_115b00() {
    a = 0;
    b = -1.0f;
    c = 1.0f;
    d = 0;
    e = 0;
    f1 = 0;
    g = 0;
    h = 1;
    i = 0;
    j = 0;
    k = 0;
    sub.Init_0027af00();
}

} // namespace fn_f3172cab

// 0x00115b50 hulkfight::ai::MotionLocatorTrack::vfunc_6 (4 B): matches/0x00115b50.cpp
// sym: ?vfunc_6@MotionLocatorTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionLocatorTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115b60 hulkfight::ai::MotionLocatorTrack::vfunc_7 (7 B): matches/0x00115b60.cpp
// sym: ?vfunc_7@MotionLocatorTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionLocatorTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

