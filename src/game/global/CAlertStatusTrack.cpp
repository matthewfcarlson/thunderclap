// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006ad60..0x0006ae30 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fdd8b6eb {
#define TREE_TU_END }
namespace fn_fdd8b6eb {} using namespace fn_fdd8b6eb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdd8b6eb {
extern int* gTable_6ad80;
class Other_6ae00 {
  public:
    int call(hulk_intptr, int);
};
extern "C" Other_6ae00* __cdecl FUN_0008d690(int);


// 0x0006ad60 FUN_0006ad60 (19 B): matches/0x0006ad60.cpp
// sym: ?FUN_0006ad60@fn_fdd8b6eb@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006ad60() {
    FUN_00234810(((char*)&DAT_004dcff8), ((char*)&DAT_004dcffc));
}

} // namespace fn_fdd8b6eb

// 0x0006ad80 CAlertStatusTrack::vfunc_0 (16 B): matches/0x0006ad80.cpp
// sym: ?vfunc_0@CAlertStatusTrack@@UAEHH@Z
hulk_intptr CAlertStatusTrack::vfunc_0(int i) {
    return gTable_6ad80[i];
}


// 0x0006ad90 FUN_0006ad90 (33 B): matches/0x0006ad90.cpp [wrapped: conflict: CAlertStatusTrack]
// sym: ??0CAlertStatusTrack@fn_0006ad90@@QAE@XZ
namespace fn_0006ad90 {
class CTrack_6ad90 {
  public:
    CTrack_6ad90();
    virtual void B();
};

class CAlertStatusTrack : public CTrack_6ad90 {
  public:
    CAlertStatusTrack();
    virtual void Dummy();
    int pad4;
    int mCount;
    int mX;
    int mY;
};

CAlertStatusTrack::CAlertStatusTrack() {
    mX = 0;
    mY = 0;
    mCount = 1;
}
} // namespace fn_0006ad90


// 0x0006adc0 CAlertStatusTrack::vfunc_13 (13 B): matches/0x0006adc0.cpp
// sym: ?vfunc_13@CAlertStatusTrack@@UAEXPAX@Z
// Same code shape as 0x0005e010 (propagated; names are from that function)
void CAlertStatusTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = -1;
}


// 0x0006add0 CAlertStatusTrack::vfunc_6 (4 B): matches/0x0006add0.cpp
// sym: ?vfunc_6@CAlertStatusTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CAlertStatusTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006ade0 CAlertStatusTrack::vfunc_7 (7 B): matches/0x0006ade0.cpp
// sym: ?vfunc_7@CAlertStatusTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CAlertStatusTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0006ae00 CAlertStatusTrack::vfunc_12 (43 B): matches/0x0006ae00.cpp
// sym: ?vfunc_12@CAlertStatusTrack@@UAEHH@Z
// Same code shape as 0x0006aaf0 (propagated; names are from that function)
hulk_intptr CAlertStatusTrack::vfunc_12(hulk_intptr param) {
    Other_6ae00* p = FUN_0008d690(0x24);
    if (p)
        return p->call(param, this->f_10);
    return 0;
}

