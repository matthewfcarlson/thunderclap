// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069880..0x00069970 (kind game, layer game, confidence high), dominant class CMoveTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f28944fe {
#define TREE_TU_END }
namespace fn_f28944fe {} using namespace fn_f28944fe;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f28944fe {
extern "C" int* hulk_at_004dcf48;
extern float hulk_at_003f32e0;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_69940 {
    int FUN_0001d290(CMoveTrack*, hulk_intptr);
};


// 0x00069880 FUN_00069880 (19 B): matches/0x00069880.cpp
// sym: ?FUN_00069880@fn_f28944fe@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069880() {
    FUN_00234810(((char*)&DAT_004dcf48), ((char*)&DAT_004dcf4c));
}

} // namespace fn_f28944fe

// 0x000698a0 CMoveTrack::vfunc_0 (16 B): matches/0x000698a0.cpp
// sym: ?vfunc_0@CMoveTrack@@UAEHH@Z
hulk_intptr CMoveTrack::vfunc_0(int index) {
    return hulk_at_004dcf48[index];
}


// 0x000698b0 FUN_000698b0 (57 B): matches/0x000698b0.cpp [wrapped: conflict: CMoveTrack]
// sym: ??0CMoveTrack@fn_000698b0@@QAE@XZ
namespace fn_000698b0 {
struct FUN_00236d40 {
    FUN_00236d40();
    virtual void virtual0();
    int field4;
};
struct CMoveTrack : FUN_00236d40 {
    virtual void virtual0();
    CMoveTrack();
    int field8;
    int fieldC;
    float field10;
    float field14;
    int field18;
    int field1C;
    int field20;
    int field24;
};
CMoveTrack::CMoveTrack()
    : FUN_00236d40(), fieldC(0), field10(1.0f), field14(1.0f), field18(0), field1C(-1), field20(0),
      field24(0) {
    field8 = 1;
}
} // namespace fn_000698b0


// 0x000698f0 CMoveTrack::vfunc_13 (13 B): matches/0x000698f0.cpp
// sym: ?vfunc_13@CMoveTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CMoveTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x00069900 CMoveTrack::vfunc_6 (4 B): matches/0x00069900.cpp
// sym: ?vfunc_6@CMoveTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CMoveTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069920 CMoveTrack::vfunc_7 (28 B): matches/0x00069920.cpp
// sym: ?vfunc_7@CMoveTrack@@UAEMXZ
hulk_freg CMoveTrack::vfunc_7() {
    hulk_freg d = this->f_10 - this->f_0c;
    if (d < hulk_at_003f32e0)
        d = hulk_at_003f32e0;
    return d;
}


// 0x00069940 CMoveTrack::vfunc_12 (40 B): matches/0x00069940.cpp
// sym: ?vfunc_12@CMoveTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CMoveTrack::vfunc_12(hulk_intptr param) {
    Helper_69940* p = (Helper_69940*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001d290(this, param);
    return 0;
}

