// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180fc0..0x001810c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainReturnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fa165829 {
#define TREE_TU_END }
namespace fn_fa165829 {} using namespace fn_fa165829;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa165829 {
extern "C" char DAT_004193ec[];
struct Sub_180fc0 {
    void FnA_0027af50();
    void FnB_00234150();
};
struct PropThrowTrack_180fc0 {
    int* v;
    char pad[0x64];
    void f();
    void FnC_00236d60();
};
extern int* hulk_at_004e14a0;
class CCondition_181010 {
  public:
    virtual int vfunc_0(int);
};
struct Param_1810b0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1810b0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00180fc0 FUN_00180fc0 (33 B): matches/0x00180fc0.cpp
// sym: ?f@PropThrowTrack_180fc0@fn_fa165829@@QAEXXZ
void PropThrowTrack_180fc0::f() {
    v = (int*)((hulk_intptr)DAT_004193ec);
    ((Sub_180fc0*)((char*)this + 0x78))->FnA_0027af50();
    ((Sub_180fc0*)((char*)this + 0x68))->FnB_00234150();
    FnC_00236d60();
}


// 0x00180ff0 FUN_00180ff0 (19 B): matches/0x00180ff0.cpp
// sym: ?FUN_00180ff0@fn_fa165829@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180ff0() {
    FUN_00234810(((char*)&DAT_004e14a0), ((char*)&DAT_004e14a4));
}

} // namespace fn_fa165829

// 0x00181010 hulkfight::motion::BallAndChainReturnTrack::vfunc_0 (16 B): matches/0x00181010.cpp
// sym: ?vfunc_0@BallAndChainReturnTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::BallAndChainReturnTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14a0;
    return p[index];
}


// 0x00181020 FUN_00181020 (115 B): equivalent/0x00181020.cpp [wrapped: conflict: hulkfight::motion::BallAndChainReturnTrack]
// sym: ?FUN_00181020@BallAndChainReturnTrack@motion@hulkfight@fn_00181020@@QAEPAV1234@XZ @d897b7f16516 @w2a376bfa0bf9
inline void *operator new(size_t, void *p) { return p; }
namespace fn_00181020 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00181020 @ 0x00181020


struct BallAndChainReturnTrack_181020 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_181020 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class BallAndChainReturnTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    int f14, f18;
    float f1c, f20;
    int f24;
    float f28;
    int f2c, f30, f34;
    float f38;
    int f3c, f40;
    char pad44[4];
    Name8_181020 n48;
    int f50, f54, f58;
    char pad5c[4];
    Name8_181020 n60;
    int f68, f6c, f70;

    BallAndChainReturnTrack() {}
    BallAndChainReturnTrack *FUN_00181020();
};
}
}

hulkfight::motion::BallAndChainReturnTrack *hulkfight::motion::BallAndChainReturnTrack::FUN_00181020()
{
    ((BallAndChainReturnTrack_181020 *)this)->FUN_00236d40();
    new (this) BallAndChainReturnTrack;
    f0c = 0;
    f14 = 0;
    f18 = 0;
    f1c = 100.0f;
    f20 = 1.0471975803375244f;
    f24 = 0;
    f28 = 1.0f;
    f10 = -1.0f;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    f38 = -1.0f;
    f3c = 0;
    f40 = 0;
    n48.FUN_0027af00();
    f50 = 0;
    f54 = 0;
    f58 = 0;
    n60.FUN_0027af00();
    f68 = 0;
    f6c = 0;
    f70 = 0;
    return this;
}
} // namespace fn_00181020


// 0x001810a0 hulkfight::motion::BallAndChainReturnTrack::vfunc_6 (4 B): matches/0x001810a0.cpp
// sym: ?vfunc_6@BallAndChainReturnTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::BallAndChainReturnTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001810b0 hulkfight::motion::BallAndChainReturnTrack::vfunc_7 (7 B): matches/0x001810b0.cpp
// sym: ?vfunc_7@BallAndChainReturnTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::BallAndChainReturnTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

