// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115b70..0x00115c30 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f6fbeb49 {
#define TREE_TU_END }
namespace fn_f6fbeb49 {} using namespace fn_f6fbeb49;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f6fbeb49 {
extern char vftable_115b70;
class MotionTargetTrack_115b70 {
  public:
    void Init();
    void Finish();
};
class MotionLocatorTrack {
  public:
    virtual ~MotionLocatorTrack();
    char pad[0x2c];
};
extern int* gTable_115bb0;
class CCondition_115bb0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_115c10 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_115c10 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00115b70 FUN_00115b70 (25 B): matches/0x00115b70.cpp
// sym: ??1MotionLocatorTrack@fn_f6fbeb49@@UAE@XZ
MotionLocatorTrack::~MotionLocatorTrack() {
    *(void**)this = &vftable_115b70;
    ((MotionTargetTrack_115b70*)((char*)this + 0x30))->Init();
    ((MotionTargetTrack_115b70*)this)->Finish();
}


// 0x00115b90 FUN_00115b90 (19 B): matches/0x00115b90.cpp
// sym: ?FUN_00115b90@fn_f6fbeb49@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115b90() {
    FUN_00234810(((char*)&DAT_004e0c6c), ((char*)&DAT_004e0c70));
}

} // namespace fn_f6fbeb49

// 0x00115bb0 hulkfight::ai::MotionTargetTrack::vfunc_0 (16 B): matches/0x00115bb0.cpp
// sym: ?vfunc_0@MotionTargetTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionTargetTrack::vfunc_0(int index) {
    int* p = gTable_115bb0;
    return p[index];
}


// 0x00115bc0 FUN_00115bc0 (50 B): equivalent/0x00115bc0.cpp [wrapped: conflict: hulkfight::ai::MotionTargetTrack]
// sym: ??0MotionTargetTrack@ai@hulkfight@fn_00115bc0@@QAE@XZ
namespace fn_00115bc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00115bc0 @ 0x00115bc0
namespace hulkfight { namespace ai {
struct MotionTargetTrackBase {
    virtual void FUN_00236d40_virtual();
    char unused[8];
    MotionTargetTrackBase();
};
struct MotionTargetTrack : MotionTargetTrackBase {
    float valueC;
    float value10;
    int value14;
    int value18;
    int value1C;
    float value20;
    float value24;
    virtual void FUN_00115bc0_virtual();
    MotionTargetTrack();
};
MotionTargetTrack::MotionTargetTrack() : MotionTargetTrackBase() {
    valueC = 0.0f;
    value14 = 0;
    value10 = -1.0f;
    value18 = 0;
    value1C = 0;
    value20 = -1.0f;
    value24 = 1.0f;
}
} }
} // namespace fn_00115bc0


// 0x00115c00 hulkfight::ai::MotionTargetTrack::vfunc_6 (4 B): matches/0x00115c00.cpp
// sym: ?vfunc_6@MotionTargetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::MotionTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00115c10 hulkfight::ai::MotionTargetTrack::vfunc_7 (7 B): matches/0x00115c10.cpp
// sym: ?vfunc_7@MotionTargetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::MotionTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

