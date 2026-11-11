// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014dbd0..0x0014dc70 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8d81090 {
#define TREE_TU_END }
namespace fn_f8d81090 {} using namespace fn_f8d81090;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8d81090 {
extern int* hulk_at_004e10d8;
class CCondition_14dbf0 {
  public:
    virtual int vfunc_0(int);
};
class Track_14dc00 {
  public:
    Track_14dc00();
    virtual void a();
    char pad[8];
    int a0;
    char pad2[8];
    int a1;
    char pad3[8];
    int a2;
    int a3;
};
class HitThrowTrack : public Track_14dc00 {
  public:
    HitThrowTrack();
    virtual void a();
};
struct Param_14dc50 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14dc50 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014dbd0 FUN_0014dbd0 (19 B): matches/0x0014dbd0.cpp
// sym: ?FUN_0014dbd0@fn_f8d81090@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014dbd0() {
    FUN_00234810(((char*)&DAT_004e10d8), ((char*)&DAT_004e10dc));
}

} // namespace fn_f8d81090

// 0x0014dbf0 hulkfight::motion::HitThrowTrack::vfunc_0 (16 B): matches/0x0014dbf0.cpp
// sym: ?vfunc_0@HitThrowTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitThrowTrack::vfunc_0(int index) {
    int* p = hulk_at_004e10d8;
    return p[index];
}

namespace fn_f8d81090 {

// 0x0014dc00 FUN_0014dc00 (57 B): matches/0x0014dc00.cpp
// sym: ??0HitThrowTrack@fn_f8d81090@@QAE@XZ
HitThrowTrack::HitThrowTrack() : Track_14dc00() {
    a0 = 0;
    a1 = 0;
    a2 = 0;
    a3 = 0;
    *(float*)((char*)this + 0x10) = -1.0f;
    *((char*)this + 0x14) = 1;
    *(float*)((char*)this + 0x1c) = 30.0f;
    *(int*)((char*)this + 0x20) = -5;
}

} // namespace fn_f8d81090

// 0x0014dc40 hulkfight::motion::HitThrowTrack::vfunc_6 (4 B): matches/0x0014dc40.cpp
// sym: ?vfunc_6@HitThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitThrowTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014dc50 hulkfight::motion::HitThrowTrack::vfunc_7 (7 B): matches/0x0014dc50.cpp
// sym: ?vfunc_7@HitThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitThrowTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

