// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115990..0x00115a30 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionFacingTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f941eb10 {
#define TREE_TU_END }
namespace fn_f941eb10 {} using namespace fn_f941eb10;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f941eb10 {
extern int* hulk_at_004e0c54;
class CCondition_1159b0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_115a10 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115a10 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115990 FUN_00115990 (19 B): matches/0x00115990.cpp
// sym: ?FUN_00115990@fn_f941eb10@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115990() {
    FUN_00234810(((char*)&DAT_004e0c54), ((char*)&DAT_004e0c58));
}

} // namespace fn_f941eb10

// 0x001159b0 hulkfight::ai::MotionFacingTrack::vfunc_0 (16 B): matches/0x001159b0.cpp
// sym: ?vfunc_0@MotionFacingTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionFacingTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0c54;
    return p[index];
}


// 0x001159c0 FUN_001159c0 (50 B): equivalent/0x001159c0.cpp [wrapped: conflict: hulkfight::ai::MotionFacingTrack]
// sym: ??0MotionFacingTrack@ai@hulkfight@fn_001159c0@@QAE@XZ
namespace fn_001159c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001159c0 @ 0x001159c0
namespace hulkfight { namespace ai {
struct FUN_00236d40 {
    virtual void unused();
    FUN_00236d40();
    char pad[8];
};
struct MotionFacingTrack : FUN_00236d40 {
    float valueC;
    float value10;
    float value14;
    float value18;
    float value1C;
    float value20;
    float value24;
    MotionFacingTrack();
    virtual void unused();
};
MotionFacingTrack::MotionFacingTrack() {
    valueC = 0.0f;
    value14 = 0.0f;
    value10 = -1.0f;
    value18 = 0.0f;
    value1C = 0.0f;
    value20 = -1.0f;
    value24 = 1.0f;
}
} }
} // namespace fn_001159c0


// 0x00115a00 hulkfight::ai::MotionFacingTrack::vfunc_6 (4 B): matches/0x00115a00.cpp
// sym: ?vfunc_6@MotionFacingTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionFacingTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115a10 hulkfight::ai::MotionFacingTrack::vfunc_7 (7 B): matches/0x00115a10.cpp
// sym: ?vfunc_7@MotionFacingTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionFacingTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

