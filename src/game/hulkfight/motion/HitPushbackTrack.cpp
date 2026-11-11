// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e3b0..0x0014e450 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f2668dc6 {
#define TREE_TU_END }
namespace fn_f2668dc6 {} using namespace fn_f2668dc6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2668dc6 {
extern int* hulk_at_004e1140;
class CCondition_14e3d0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_14e430 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14e430 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014e3b0 FUN_0014e3b0 (19 B): matches/0x0014e3b0.cpp
// sym: ?FUN_0014e3b0@fn_f2668dc6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014e3b0() {
    FUN_00234810(((char*)&DAT_004e1140), ((char*)&DAT_004e1144));
}

} // namespace fn_f2668dc6

// 0x0014e3d0 hulkfight::motion::HitPushbackTrack::vfunc_0 (16 B): matches/0x0014e3d0.cpp
// sym: ?vfunc_0@HitPushbackTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitPushbackTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1140;
    return p[index];
}


// 0x0014e3e0 FUN_0014e3e0 (63 B): equivalent/0x0014e3e0.cpp [wrapped: conflict: hulkfight::motion::HitPushbackTrack]
// sym: ??0HitPushbackTrack@motion@hulkfight@fn_0014e3e0@@QAE@XZ
namespace fn_0014e3e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0014e3e0 @ 0x0014e3e0
namespace hulkfight { namespace motion {
struct FUN_00236d40 { virtual void virtualMethod(); FUN_00236d40(); };
struct HitPushbackTrack : FUN_00236d40 {
    virtual void virtualMethod();
    char padding04[8];
    int value0c;
    float value10;
    float value14;
    float value18;
    unsigned char flag1c;
    char padding1d[3];
    int value20;
    int value24;
    int value28;
    int value2c;
    int value30;
    HitPushbackTrack();
};
HitPushbackTrack::HitPushbackTrack() {
    value0c = 0;
    flag1c = 0;
    value20 = 0;
    value24 = 0;
    value2c = 0;
    value30 = 0;
    value10 = -1.0f;
    value14 = 1.0f;
    value18 = -1.0f;
    value28 = -5;
}
} }
} // namespace fn_0014e3e0


// 0x0014e420 hulkfight::motion::HitPushbackTrack::vfunc_6 (4 B): matches/0x0014e420.cpp
// sym: ?vfunc_6@HitPushbackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitPushbackTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e430 hulkfight::motion::HitPushbackTrack::vfunc_7 (7 B): matches/0x0014e430.cpp
// sym: ?vfunc_7@HitPushbackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitPushbackTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

