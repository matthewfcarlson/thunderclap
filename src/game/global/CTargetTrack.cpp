// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b220..0x0006b300 (kind game, layer game, confidence high), dominant class CTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f6d21a01 {
#define TREE_TU_END }
namespace fn_f6d21a01 {} using namespace fn_f6d21a01;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6d21a01 {
struct Param_6b2a0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6b2a0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class R_6b2c0 {
  public:
    int invoke(CTargetTrack*, hulk_intptr);
};
extern "C" R_6b2c0* FUN_0008d690(int);


// 0x0006b220 FUN_0006b220 (19 B): matches/0x0006b220.cpp
// sym: ?FUN_0006b220@fn_f6d21a01@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006b220() {
    FUN_00234810(((char*)&DAT_004dd028), ((char*)&DAT_004dd02c));
}

} // namespace fn_f6d21a01

// 0x0006b240 CTargetTrack::vfunc_0 (16 B): matches/0x0006b240.cpp
// sym: ?vfunc_0@CTargetTrack@@UAEHH@Z
hulk_intptr CTargetTrack::vfunc_0(int i) {
    return gTable[i];
}


// 0x0006b250 FUN_0006b250 (39 B): matches/0x0006b250.cpp [wrapped: conflict: CTargetTrack]
// sym: ??0CTargetTrack@fn_0006b250@@QAE@XZ
namespace fn_0006b250 {
class CTrack_6b250 {
  public:
    CTrack_6b250();
    virtual void f();
    char pad[4];
};
class CTargetTrack : public CTrack_6b250 {
  public:
    CTargetTrack();
    virtual void f();
    int n;
    float x;
    float y;
};
CTargetTrack::CTargetTrack() {
    x = 0.0f;
    y = -1.0f;
    n = 1;
}
} // namespace fn_0006b250


// 0x0006b280 CTargetTrack::vfunc_13 (13 B): matches/0x0006b280.cpp
// sym: ?vfunc_13@CTargetTrack@@UAEXPAX@Z
void CTargetTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff1f1fff;
}


// 0x0006b290 CTargetTrack::vfunc_6 (4 B): matches/0x0006b290.cpp
// sym: ?vfunc_6@CTargetTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006b2a0 CTargetTrack::vfunc_7 (7 B): matches/0x0006b2a0.cpp
// sym: ?vfunc_7@CTargetTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006b2c0 CTargetTrack::vfunc_12 (40 B): matches/0x0006b2c0.cpp
// sym: ?vfunc_12@CTargetTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CTargetTrack::vfunc_12(hulk_intptr param) {
    R_6b2c0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}

