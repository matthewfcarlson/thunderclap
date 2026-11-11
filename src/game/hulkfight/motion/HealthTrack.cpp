// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e1f0..0x0014e280 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f5de4086 {
#define TREE_TU_END }
namespace fn_f5de4086 {} using namespace fn_f5de4086;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5de4086 {
extern int* hulk_at_004e1128;
class CCondition_14e210 {
  public:
    virtual int vfunc_0(int);
};
extern char DAT_00414420;
struct Track_14e220 {
    hulk_intptr vptr;
    Track_14e220();
};
struct HealthTrack_14e220 : Track_14e220 {
    char pad[8];
    int m0c;
    int m10;
    char m14, m15, m16;
    HealthTrack_14e220();
};


// 0x0014e1f0 FUN_0014e1f0 (19 B): matches/0x0014e1f0.cpp
// sym: ?FUN_0014e1f0@fn_f5de4086@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e1f0() {
    FUN_00234810(((char*)&DAT_004e1128), ((char*)&DAT_004e112c));
}

} // namespace fn_f5de4086

// 0x0014e210 hulkfight::motion::HealthTrack::vfunc_0 (16 B): matches/0x0014e210.cpp
// sym: ?vfunc_0@HealthTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HealthTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1128;
    return p[index];
}

namespace fn_f5de4086 {

// 0x0014e220 FUN_0014e220 (35 B): matches/0x0014e220.cpp
// sym: ??0HealthTrack_14e220@fn_f5de4086@@QAE@XZ
HealthTrack_14e220::HealthTrack_14e220() : Track_14e220() {
    m0c = 0;
    m10 = 0;
    m14 = 0;
    m15 = 0;
    m16 = 0;
    vptr = (hulk_intptr)&DAT_00414420;
}

} // namespace fn_f5de4086

// 0x0014e250 hulkfight::motion::HealthTrack::vfunc_6 (4 B): matches/0x0014e250.cpp
// sym: ?vfunc_6@HealthTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HealthTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e260 hulkfight::motion::HealthTrack::vfunc_7 (7 B): matches/0x0014e260.cpp
// sym: ?vfunc_7@HealthTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::HealthTrack::vfunc_7() {
    return DAT_003f32e0;
}

