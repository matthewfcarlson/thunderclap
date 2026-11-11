// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181280..0x00181360 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainSpinTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f2c9911e {
#define TREE_TU_END }
namespace fn_f2c9911e {} using namespace fn_f2c9911e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2c9911e {
class Helper_181280 {
  public:
    void Init_0027af50();
};
extern char hulk_at_0041947c;
class BallAndChainSpinTrack_181280 {
  public:
    void Finish_00236d60();
};
extern int* hulk_at_004e14b8;
class CCondition_1812d0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1812e0 {
  public:
    Track_1812e0();
    virtual void vf();
    char pad[4];
    int flag;
};
struct Tail {
    int h, i, j;
    Tail() : h(0), i(0), j(0) {}
};
class BallAndChainSpinTrack : public Track_1812e0 {
  public:
    BallAndChainSpinTrack();
    virtual void vf();
    int a;
    float b;
    int c;
    float d, e;
    int x;
    float angle;
    Tail tail;
};
struct Param_181340 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_181340 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

} // namespace fn_f2c9911e

// 0x00181280 FUN_00181280 (33 B): matches/0x00181280.cpp
// sym: ?FUN_00181280@BallAndChainShootTrack@motion@hulkfight@@QAEXXZ
void hulkfight::motion::BallAndChainShootTrack::FUN_00181280() {
    *(void**)this = &hulk_at_0041947c;
    ((Helper_181280*)((char*)this + 0x78))->Init_0027af50();
    ((Helper_181280*)((char*)this + 0x60))->Init_0027af50();
    ((BallAndChainSpinTrack_181280*)this)->Finish_00236d60();
}

namespace fn_f2c9911e {

// 0x001812b0 FUN_001812b0 (19 B): matches/0x001812b0.cpp
// sym: ?FUN_001812b0@fn_f2c9911e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001812b0() {
    FUN_00234810(((char*)&DAT_004e14b8), ((char*)&DAT_004e14bc));
}

} // namespace fn_f2c9911e

// 0x001812d0 hulkfight::motion::BallAndChainSpinTrack::vfunc_0 (16 B): matches/0x001812d0.cpp
// sym: ?vfunc_0@BallAndChainSpinTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::BallAndChainSpinTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14b8;
    return p[index];
}

namespace fn_f2c9911e {

// 0x001812e0 FUN_001812e0 (73 B): matches/0x001812e0.cpp
// sym: ??0BallAndChainSpinTrack@fn_f2c9911e@@QAE@XZ
BallAndChainSpinTrack::BallAndChainSpinTrack()
    : Track_1812e0(), a(0), b(-1.0f), c(0), d(10.0f), e(3.0f), x(0), angle(6.2831855f) {
    flag = 1;
}

} // namespace fn_f2c9911e

// 0x00181330 hulkfight::motion::BallAndChainSpinTrack::vfunc_6 (4 B): matches/0x00181330.cpp
// sym: ?vfunc_6@BallAndChainSpinTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::BallAndChainSpinTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00181340 hulkfight::motion::BallAndChainSpinTrack::vfunc_7 (7 B): matches/0x00181340.cpp
// sym: ?vfunc_7@BallAndChainSpinTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::BallAndChainSpinTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

