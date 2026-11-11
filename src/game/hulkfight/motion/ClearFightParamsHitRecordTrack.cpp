// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e0e0..0x0014e160 (kind game, layer game, confidence high), dominant class hulkfight::motion::ClearFightParamsHitRecordTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fd616d75 {
#define TREE_TU_END }
namespace fn_fd616d75 {} using namespace fn_fd616d75;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd616d75 {
extern int* hulk_at_004e1118;
class CCondition_14e100 {
  public:
    virtual int vfunc_0(int);
};
class Track_14e110 {
  public:
    Track_14e110();
    void* vptr;
};
class ClearFightParamsHitRecordTrack_14e110 : public Track_14e110 {
  public:
    ClearFightParamsHitRecordTrack_14e110();
    char pad[4];
    int mA;
    int mB;
};


// 0x0014e0e0 FUN_0014e0e0 (19 B): matches/0x0014e0e0.cpp
// sym: ?FUN_0014e0e0@fn_fd616d75@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e0e0() {
    FUN_00234810(((char*)&DAT_004e1118), ((char*)&DAT_004e111c));
}

} // namespace fn_fd616d75

// 0x0014e100 hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_0 (16 B): matches/0x0014e100.cpp
// sym: ?vfunc_0@ClearFightParamsHitRecordTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1118;
    return p[index];
}

namespace fn_fd616d75 {

// 0x0014e110 FUN_0014e110 (32 B): matches/0x0014e110.cpp
// sym: ??0ClearFightParamsHitRecordTrack_14e110@fn_fd616d75@@QAE@XZ
ClearFightParamsHitRecordTrack_14e110::ClearFightParamsHitRecordTrack_14e110() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    mB = 0;
    mA = 1;
}

} // namespace fn_fd616d75

// 0x0014e130 hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_6 (4 B): matches/0x0014e130.cpp
// sym: ?vfunc_6@ClearFightParamsHitRecordTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e140 hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_7 (7 B): matches/0x0014e140.cpp
// sym: ?vfunc_7@ClearFightParamsHitRecordTrack@motion@hulkfight@@UAEMXZ
// data: gZero_14e140 = DAT_003f32e0
hulk_freg hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_7() {
    return DAT_003f32e0;
}

