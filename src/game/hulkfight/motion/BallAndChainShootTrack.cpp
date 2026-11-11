// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181180..0x00181280 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainShootTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff891032 {
#define TREE_TU_END }
namespace fn_ff891032 {} using namespace fn_ff891032;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff891032 {
extern int* hulk_at_004e14b0;
class CCondition_1811a0 {
  public:
    virtual int vfunc_0(int);
};


// 0x00181180 FUN_00181180 (19 B): matches/0x00181180.cpp
// sym: ?FUN_00181180@fn_ff891032@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00181180() {
    FUN_00234810(((char*)&DAT_004e14b0), ((char*)&DAT_004e14b4));
}

} // namespace fn_ff891032

// 0x001811a0 hulkfight::motion::BallAndChainShootTrack::vfunc_0 (16 B): matches/0x001811a0.cpp
// sym: ?vfunc_0@BallAndChainShootTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::BallAndChainShootTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14b0;
    return p[index];
}


// 0x001811b0 FUN_001811b0 (164 B): equivalent/0x001811b0.cpp [wrapped: conflict: hulkfight::motion::BallAndChainShootTrack]
// sym: ??0BallAndChainShootTrack@motion@hulkfight@fn_001811b0@@QAE@XZ @c0bcf6e45c31 @w0248eb0b272a
namespace fn_001811b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001811b0 @ 0x001811b0
struct Name_1811b0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_1811b0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_1811b0() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class BallAndChainShootTrack : public Track_1811b0 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10;
    int f14, f18, f1c, f20, f24, f28;
    float f2c, f30;
    int f34, f38;
    float f3c, f40, f44, f48, f4c, f50;
    int f54, f58;
    char pad5c[4];
    Name_1811b0 nameA;                     // 0x60
    int f68, f6c, f70;
    char pad74[4];
    Name_1811b0 nameB;                     // 0x78
    int f80, f84, f88, f8c;
    float f90;

    BallAndChainShootTrack();
};
} }

hulkfight::motion::BallAndChainShootTrack::BallAndChainShootTrack()
{
    f0c = 0;
    f14 = 0;
    f10 = -1.0f;
    f18 = 0; f1c = 0; f20 = 0;
    f2c = -1.0f;
    f24 = 0; f28 = 0;
    f30 = -1.0f;
    f34 = 0; f38 = 0;
    f3c = 10.0f;
    f44 = 10.0f;
    f40 = 100.0f;
    f48 = 100.0f;
    f4c = 0.5235987901687622f;
    f50 = 1.0471975803375244f;
    f54 = 0; f58 = 0;
    nameA.FUN_0027af00();
    f68 = 0; f6c = 0; f70 = 0;
    nameB.FUN_0027af00();
    f80 = 0; f84 = 0; f88 = 0; f8c = 0;
    f90 = 1.0f;
}
} // namespace fn_001811b0


// 0x00181260 hulkfight::motion::BallAndChainShootTrack::vfunc_6 (4 B): matches/0x00181260.cpp
// sym: ?vfunc_6@BallAndChainShootTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::BallAndChainShootTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00181270 hulkfight::motion::BallAndChainShootTrack::vfunc_7 (7 B): matches/0x00181270.cpp
// sym: ?vfunc_7@BallAndChainShootTrack@motion@hulkfight@@UAEMXZ
hulk_freg hulkfight::motion::BallAndChainShootTrack::vfunc_7() {
    return this->f_10 - this->f_0c;
}

