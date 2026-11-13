// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069da0..0x00069e70 (kind game, layer game, confidence high), dominant class CDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fabeda8f {
#define TREE_TU_END }
namespace fn_fabeda8f {} using namespace fn_fabeda8f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fabeda8f {
extern int* hulk_at_004dcf70;
class CCondition_69dc0 {
  public:
    virtual int vfunc_0(int);
};
struct Helper_69e40 {
    int run_0001d9b0(hulk_intptr, int, int);
};
extern "C" void* FUN_0008d690(int);


// 0x00069da0 FUN_00069da0 (19 B): matches/0x00069da0.cpp
// sym: ?FUN_00069da0@fn_fabeda8f@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069da0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf70), ((char*)&DAT_004dcf74));
}

} // namespace fn_fabeda8f

// 0x00069dc0 CDamageTrack::vfunc_0 (16 B): matches/0x00069dc0.cpp
// sym: ?vfunc_0@CDamageTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CDamageTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf70;
    return p[index];
}


// 0x00069dd0 FUN_00069dd0 (36 B): matches/0x00069dd0.cpp [wrapped: conflict: CDamageTrack]
// sym: ??0CDamageTrack@fn_00069dd0@@QAE@XZ
namespace fn_00069dd0 {
class CTrack_69dd0 {
  public:
    CTrack_69dd0();
    virtual hulk_intptr f0_00069dc0(int);
    virtual bool f1_00234270(void*);
    int m4;
};

class CDamageTrack : public ::CDamageTrack {
  public:
    CDamageTrack();
};

CDamageTrack::CDamageTrack() {
    timeBegin = 0;
    damage = 0;
    damageMax = 0;
    f_08 = 1;
}
} // namespace fn_00069dd0


// 0x00069e00 CDamageTrack::vfunc_13 (13 B): matches/0x00069e00.cpp
// sym: ?vfunc_13@CDamageTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CDamageTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00069e10 CDamageTrack::vfunc_6 (4 B): matches/0x00069e10.cpp
// sym: ?vfunc_6@CDamageTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CDamageTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00069e20 CDamageTrack::vfunc_7 (7 B): matches/0x00069e20.cpp
// sym: ?vfunc_7@CDamageTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CDamageTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00069e40 CDamageTrack::vfunc_12 (47 B): matches/0x00069e40.cpp
// sym: ?vfunc_12@CDamageTrack@@UAEHH@Z
hulk_intptr CDamageTrack::vfunc_12(hulk_intptr x) {
    Helper_69e40* p = (Helper_69e40*)FUN_0008d690(0x28);
    if (p)
        return p->run_0001d9b0(x, this->damage, this->damageMax);
    return 0;
}

