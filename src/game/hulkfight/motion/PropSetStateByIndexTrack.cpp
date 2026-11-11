// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001810c0..0x00181180 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByIndexTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f579a2c4 {
#define TREE_TU_END }
namespace fn_f579a2c4 {} using namespace fn_f579a2c4;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f579a2c4 {
extern int hulk_at_0041941c;
struct PropSetStateByIndexTrack_1810c0 {
    void Init_0027af50();
    void Finish_00236d60();
};
extern int* hulk_at_004e14a8;
class CCondition_181110 {
  public:
    virtual int vfunc_0(int);
};
class Track_181120 {
  public:
    Track_181120();
    virtual void f();
    int x;
    int y;
    int z;
};
class PropSetStateByIndexTrack : public Track_181120 {
  public:
    PropSetStateByIndexTrack();
    virtual void f();
    int w;
    int v;
};

} // namespace fn_f579a2c4

// 0x001810c0 FUN_001810c0 (33 B): matches/0x001810c0.cpp
// sym: ?FUN_001810c0@BallAndChainReturnTrack@motion@hulkfight@@QAEXXZ
void hulkfight::motion::BallAndChainReturnTrack::FUN_001810c0() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0041941c;
    ((PropSetStateByIndexTrack_1810c0*)((char*)this + 0x60))->Init_0027af50();
    ((PropSetStateByIndexTrack_1810c0*)((char*)this + 0x48))->Init_0027af50();
    ((PropSetStateByIndexTrack_1810c0*)this)->Finish_00236d60();
}

namespace fn_f579a2c4 {

// 0x001810f0 FUN_001810f0 (19 B): matches/0x001810f0.cpp
// sym: ?FUN_001810f0@fn_f579a2c4@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001810f0() {
    FUN_00234810(((char*)&DAT_004e14a8), ((char*)&DAT_004e14ac));
}

} // namespace fn_f579a2c4

// 0x00181110 hulkfight::motion::PropSetStateByIndexTrack::vfunc_0 (16 B): matches/0x00181110.cpp
// sym: ?vfunc_0@PropSetStateByIndexTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropSetStateByIndexTrack::vfunc_0(int index) {
    int* p = hulk_at_004e14a8;
    return p[index];
}

namespace fn_f579a2c4 {

// 0x00181120 FUN_00181120 (40 B): matches/0x00181120.cpp
// sym: ??0PropSetStateByIndexTrack@fn_f579a2c4@@QAE@XZ
PropSetStateByIndexTrack::PropSetStateByIndexTrack() {
    z = 0;
    v = 0;
    w = -1;
    y = 1;
}

} // namespace fn_f579a2c4

// 0x00181150 hulkfight::motion::PropSetStateByIndexTrack::vfunc_6 (4 B): matches/0x00181150.cpp
// sym: ?vfunc_6@PropSetStateByIndexTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropSetStateByIndexTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00181160 hulkfight::motion::PropSetStateByIndexTrack::vfunc_7 (7 B): matches/0x00181160.cpp
// sym: ?vfunc_7@PropSetStateByIndexTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropSetStateByIndexTrack::vfunc_7() {
    return DAT_003f32e0;
}

