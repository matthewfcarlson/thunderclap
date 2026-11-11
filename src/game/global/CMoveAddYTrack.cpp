// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069a50..0x00069b30 (kind game, layer game, confidence high), dominant class CMoveAddYTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f6b1b8f2 {
#define TREE_TU_END }
namespace fn_f6b1b8f2 {} using namespace fn_f6b1b8f2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6b1b8f2 {
extern float hulk_at_003f32e0;
class R_69b00 {
  public:
    int invoke_0001d3a0(CMoveAddYTrack*, hulk_intptr);
};
extern "C" R_69b00* FUN_0008d690(int);


// 0x00069a50 FUN_00069a50 (19 B): matches/0x00069a50.cpp
// sym: ?FUN_00069a50@fn_f6b1b8f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069a50() {
    FUN_00234810(((char*)&DAT_004dcf58), ((char*)&DAT_004dcf5c));
}


// 0x00069a70 CMoveAddYTrack::vfunc_0 (16 B): matches/0x00069a70.cpp
// sym: ?vfunc_0@fn_f6b1b8f2@@YGHH@Z
// data: gTable_69a70 = DAT_004dcf58
int __stdcall vfunc_0(int index) {
    return (*(int**)&DAT_004dcf58)[index];
}

} // namespace fn_f6b1b8f2

// 0x00069a80 FUN_00069a80 (44 B): equivalent/0x00069a80.cpp [wrapped: conflict: CMoveAddYTrack]
// sym: ??0CMoveAddYTrack@fn_00069a80@@QAE@XZ
namespace fn_00069a80 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00069a80 @ 0x00069a80
struct CTrack_69a80 {
    virtual void update();
    char reserved[4];
    CTrack_69a80();
};

struct CMoveAddYTrack : CTrack_69a80 {
    int enabled;
    int other;
    float scale;
    float weight;
    int state;
    CMoveAddYTrack();
};

CMoveAddYTrack::CMoveAddYTrack() {
    scale = 1.0f;
    weight = 1.0f;
    other = 0;
    state = 0;
    enabled = 1;
}
} // namespace fn_00069a80


// 0x00069ab0 CMoveAddYTrack::vfunc_13 (13 B): matches/0x00069ab0.cpp
// sym: ?vfunc_13@CMoveAddYTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CMoveAddYTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x00069ac0 CMoveAddYTrack::vfunc_6 (4 B): matches/0x00069ac0.cpp
// sym: ?vfunc_6@CMoveAddYTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CMoveAddYTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00069ae0 CMoveAddYTrack::vfunc_7 (28 B): matches/0x00069ae0.cpp
// sym: ?vfunc_7@CMoveAddYTrack@@UAEMXZ
// Same code shape as 0x00069920 (propagated; names are from that function)
hulk_freg CMoveAddYTrack::vfunc_7() {
    hulk_freg d = this->timeEnd - this->timeBegin;
    if (d < hulk_at_003f32e0)
        d = hulk_at_003f32e0;
    return d;
}


// 0x00069b00 CMoveAddYTrack::vfunc_12 (40 B): matches/0x00069b00.cpp
// sym: ?vfunc_12@CMoveAddYTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CMoveAddYTrack::vfunc_12(hulk_intptr param) {
    R_69b00* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001d3a0(this, param);
    return 0;
}

