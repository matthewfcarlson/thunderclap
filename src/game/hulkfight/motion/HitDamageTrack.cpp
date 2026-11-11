// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e280..0x0014e300 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f41b62c0 {
#define TREE_TU_END }
namespace fn_f41b62c0 {} using namespace fn_f41b62c0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f41b62c0 {
extern int* gTable_14e2a0;
class CCondition_14e2a0 {
  public:
    virtual int vfunc_0(int);
};
class Track_14e2b0 {
  public:
    Track_14e2b0();
    void* vptr;
};
class HitDamageTrack : public Track_14e2b0 {
  public:
    HitDamageTrack();
    char pad[8];
    int mFieldC;
    float mField10;
};


// 0x0014e280 FUN_0014e280 (19 B): matches/0x0014e280.cpp
// sym: ?FUN_0014e280@fn_f41b62c0@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e280() {
    FUN_00234810(((char*)&DAT_004e1130), ((char*)&DAT_004e1134));
}

} // namespace fn_f41b62c0

// 0x0014e2a0 hulkfight::motion::HitDamageTrack::vfunc_0 (16 B): matches/0x0014e2a0.cpp
// sym: ?vfunc_0@HitDamageTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitDamageTrack::vfunc_0(int index) {
    int* p = gTable_14e2a0;
    return p[index];
}

namespace fn_f41b62c0 {

// 0x0014e2b0 FUN_0014e2b0 (32 B): matches/0x0014e2b0.cpp
// sym: ??0HitDamageTrack@fn_f41b62c0@@QAE@XZ
HitDamageTrack::HitDamageTrack() {
    vptr = g_vftable;
    mFieldC = 0;
    mField10 = 1.0f;
}

} // namespace fn_f41b62c0

// 0x0014e2d0 hulkfight::motion::HitDamageTrack::vfunc_6 (4 B): matches/0x0014e2d0.cpp
// sym: ?vfunc_6@HitDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitDamageTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e2e0 hulkfight::motion::HitDamageTrack::vfunc_7 (7 B): matches/0x0014e2e0.cpp
// sym: ?vfunc_7@HitDamageTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitDamageTrack::vfunc_7() {
    return DAT_003f32e0;
}

