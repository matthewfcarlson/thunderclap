// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069970..0x00069a50 (kind game, layer game, confidence high), dominant class CMoveAddTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_feedf6bd {
#define TREE_TU_END }
namespace fn_feedf6bd {} using namespace fn_feedf6bd;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_feedf6bd {
extern float hulk_at_003f32e0;
class R_69a20 {
  public:
    int invoke_0001d320(CMoveAddTrack*, hulk_intptr);
};
extern "C" R_69a20* FUN_0008d690(int);


// 0x00069970 FUN_00069970 (19 B): matches/0x00069970.cpp
// sym: ?FUN_00069970@fn_feedf6bd@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069970(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf50), ((char*)&DAT_004dcf54));
}


// 0x00069990 CMoveAddTrack::vfunc_0 (16 B): matches/0x00069990.cpp
// sym: ?CMoveAddTrack_vfunc_0@fn_feedf6bd@@YGHH@Z
// data: g_table_69990 = DAT_004dcf50
int __stdcall CMoveAddTrack_vfunc_0(int index) {
    return (*(int**)&DAT_004dcf50)[index];
}

} // namespace fn_feedf6bd

// 0x000699a0 FUN_000699a0 (44 B): matches/0x000699a0.cpp [wrapped: conflict: CMoveAddTrack]
// sym: ??0CMoveAddTrack@fn_000699a0@@QAE@XZ
namespace fn_000699a0 {
class CTrack_699a0 {
  public:
    CTrack_699a0();
    virtual void f();
    char pad[4];
    int a;
};
class CMoveAddTrack : public ::CMoveAddTrack {
  public:
    CMoveAddTrack();
};
CMoveAddTrack::CMoveAddTrack() {
    f_0c = 0;
    f_10 = 1.0f;
    f_14 = 1.0f;
    f_18 = 0;
    f_08 = 1;
}
} // namespace fn_000699a0


// 0x000699d0 CMoveAddTrack::vfunc_13 (13 B): matches/0x000699d0.cpp
// sym: ?vfunc_13@CMoveAddTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CMoveAddTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x000699e0 CMoveAddTrack::vfunc_6 (4 B): matches/0x000699e0.cpp
// sym: ?vfunc_6@CMoveAddTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CMoveAddTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069a00 CMoveAddTrack::vfunc_7 (28 B): matches/0x00069a00.cpp
// sym: ?vfunc_7@CMoveAddTrack@@UAEMXZ
// Same code shape as 0x00069920 (propagated; names are from that function)
hulk_freg CMoveAddTrack::vfunc_7() {
    hulk_freg d = this->f_10 - this->f_0c;
    if (d < hulk_at_003f32e0)
        d = hulk_at_003f32e0;
    return d;
}


// 0x00069a20 CMoveAddTrack::vfunc_12 (40 B): matches/0x00069a20.cpp
// sym: ?vfunc_12@CMoveAddTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CMoveAddTrack::vfunc_12(hulk_intptr param) {
    R_69a20* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001d320(this, param);
    return 0;
}

