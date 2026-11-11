// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016fe50..0x0016fee0 (kind game, layer game, confidence high), dominant class hulkfight::motion::RestPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f085f4c5 {
#define TREE_TU_END }
namespace fn_f085f4c5 {} using namespace fn_f085f4c5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f085f4c5 {
extern int* gTable_16fe70;
class CCondition_16fe70 {
  public:
    virtual int vfunc_0(int);
};
class Track_16fe80 {
  public:
    Track_16fe80();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class RestPoseTrack : public Track_16fe80 {
  public:
    RestPoseTrack();
    virtual void f();
    int a;
    float b;
    char pad2[4];
    Sub sub;
    int c, d, e;
};
struct Param_16fed0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_16fed0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0016fe50 FUN_0016fe50 (19 B): matches/0x0016fe50.cpp
// sym: ?FUN_0016fe50@fn_f085f4c5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0016fe50() {
    FUN_00234810(((char*)&DAT_004e12f8), ((char*)&DAT_004e12fc));
}

} // namespace fn_f085f4c5

// 0x0016fe70 hulkfight::motion::RestPoseTrack::vfunc_0 (16 B): matches/0x0016fe70.cpp
// sym: ?vfunc_0@RestPoseTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::RestPoseTrack::vfunc_0(int index) {
    int* p = gTable_16fe70;
    return p[index];
}

namespace fn_f085f4c5 {

// 0x0016fe80 FUN_0016fe80 (61 B): matches/0x0016fe80.cpp
// sym: ??0RestPoseTrack@fn_f085f4c5@@QAE@XZ
RestPoseTrack::RestPoseTrack() : Track_16fe80(), a(0), b(-1.0f), sub(), c(-5), d(0), e(0) {}

} // namespace fn_f085f4c5

// 0x0016fec0 hulkfight::motion::RestPoseTrack::vfunc_6 (4 B): matches/0x0016fec0.cpp
// sym: ?vfunc_6@RestPoseTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::RestPoseTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0016fed0 hulkfight::motion::RestPoseTrack::vfunc_7 (7 B): matches/0x0016fed0.cpp
// sym: ?vfunc_7@RestPoseTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::RestPoseTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

