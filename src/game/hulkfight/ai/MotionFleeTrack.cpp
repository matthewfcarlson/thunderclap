// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001158a0..0x00115910 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionFleeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fa5c6731 {
#define TREE_TU_END }
namespace fn_fa5c6731 {} using namespace fn_fa5c6731;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fa5c6731 {
extern int* hulk_at_004e0c44;
class CCondition_1158a0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1158b0 {
  public:
    Track_1158b0();
    virtual void f();
    int a, b;
};
class MotionFleeTrack : public ::hulkfight::ai::MotionFleeTrack {
  public:
    MotionFleeTrack();
};
struct Param_1158f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1158f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

} // namespace fn_fa5c6731

// 0x001158a0 hulkfight::ai::MotionFleeTrack::vfunc_0 (16 B): matches/0x001158a0.cpp
// sym: ?vfunc_0@MotionFleeTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionFleeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0c44;
    return p[index];
}

namespace fn_fa5c6731 {

// 0x001158b0 FUN_001158b0 (39 B): matches/0x001158b0.cpp
// sym: ??0MotionFleeTrack@fn_fa5c6731@@QAE@XZ
MotionFleeTrack::MotionFleeTrack() {
    timeBegin = 0;
    timeEnd = -1.0f;
    speed = 1.0f;}

} // namespace fn_fa5c6731

// 0x001158e0 hulkfight::ai::MotionFleeTrack::vfunc_6 (4 B): matches/0x001158e0.cpp
// sym: ?vfunc_6@MotionFleeTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionFleeTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x001158f0 hulkfight::ai::MotionFleeTrack::vfunc_7 (7 B): matches/0x001158f0.cpp
// sym: ?vfunc_7@MotionFleeTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionFleeTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

