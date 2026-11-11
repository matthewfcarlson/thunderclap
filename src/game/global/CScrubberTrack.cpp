// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00068df0..0x00068ed0 (kind game, layer game, confidence high), dominant class CScrubberTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f88b40b1 {
#define TREE_TU_END }
namespace fn_f88b40b1 {} using namespace fn_f88b40b1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f88b40b1 {
extern float hulk_at_003f3388;


// 0x00068df0 FUN_00068df0 (19 B): matches/0x00068df0.cpp
// sym: ?FUN_00068df0@fn_f88b40b1@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00068df0() {
    FUN_00234810(((char*)&DAT_004dcf10), ((char*)&DAT_004dcf14));
}

} // namespace fn_f88b40b1

// 0x00068e10 CScrubberTrack::vfunc_0 (16 B): matches/0x00068e10.cpp
// sym: ?vfunc_0@CScrubberTrack@@UAEHH@Z
hulk_intptr CScrubberTrack::vfunc_0(int i) {
    return gTable[i];
}


// 0x00068e20 FUN_00068e20 (18 B): matches/0x00068e20.cpp [wrapped: conflict: CScrubberTrack]
// sym: ??0CScrubberTrack@fn_00068e20@@QAE@XZ
namespace fn_00068e20 {
class CTrack_68e20 {
  public:
    CTrack_68e20();
    virtual hulk_intptr VFn_00068e10(int);
};

class CScrubberTrack : public CTrack_68e20 {
  public:
    CScrubberTrack();
    virtual bool VFn2_00234270(void*);
};

CScrubberTrack::CScrubberTrack() : CTrack_68e20() {}
} // namespace fn_00068e20


// 0x00068e40 CScrubberTrack::vfunc_6 (7 B): matches/0x00068e40.cpp
// sym: ?vfunc_6@CScrubberTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CScrubberTrack::vfunc_6() {
    return DAT_003f32e0;
}


// 0x00068e50 CScrubberTrack::vfunc_7 (7 B): matches/0x00068e50.cpp
// sym: ?vfunc_7@CScrubberTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CScrubberTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_f88b40b1 {

// 0x00068e70 FUN_00068e70 (3 B): matches/0x00068e70.cpp
// sym: ?FUN_00068e70@fn_f88b40b1@@YAHXZ
int __cdecl FUN_00068e70() {
    return 0;
}


// 0x00068eb0 FUN_00068eb0 (5 B): matches/0x00068eb0.cpp
// sym: _FUN_00068eb0@4
extern "C" bool __stdcall FUN_00068eb0(hulk_intptr x) {
    return true;
}

} // namespace fn_f88b40b1

// 0x00068ec0 CScrubberTrack::vfunc_12 (5 B): matches/0x00068ec0.cpp [wrapped: conflict: fight::Condition; fight::Param]
// sym: ?vfunc_0@CScrubberTrack_68ec0@fn_00068ec0@@UAEHH@Z
namespace fn_00068ec0 {
// Same code shape as 0x00049c80 (propagated; names are from that function)
class CTrack_68ec0 {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class CScrubberTrack_68ec0 : public CTrack_68ec0, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int CScrubberTrack_68ec0::vfunc_0(int) {
    return 0;
}
} // namespace fn_00068ec0

