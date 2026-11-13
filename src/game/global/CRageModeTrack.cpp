// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006aa50..0x0006ab20 (kind game, layer game, confidence high), dominant class CRageModeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fd85930d {
#define TREE_TU_END }
namespace fn_fd85930d {} using namespace fn_fd85930d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd85930d {
class Other_6aaf0 {
  public:
    int call_00020120(hulk_intptr, int);
};
extern "C" Other_6aaf0* __cdecl FUN_0008d690(int);


// 0x0006aa50 FUN_0006aa50 (19 B): matches/0x0006aa50.cpp
// sym: ?FUN_0006aa50@fn_fd85930d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006aa50(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcfe0), ((char*)&DAT_004dcfe4));
}


// 0x0006aa70 CRageModeTrack::vfunc_0 (16 B): matches/0x0006aa70.cpp
// sym: _FUN_0006aa70@4
// data: g_table_6aa70 = DAT_004dcfe0
extern "C" int __stdcall FUN_0006aa70(int index) {
    return (*(int**)&DAT_004dcfe0)[index];
}

} // namespace fn_fd85930d

// 0x0006aa80 FUN_0006aa80 (33 B): matches/0x0006aa80.cpp [wrapped: conflict: CRageModeTrack]
// sym: ??0CRageModeTrack@fn_0006aa80@@QAE@XZ
namespace fn_0006aa80 {
class CTrack_6aa80 {
  public:
    virtual void f0();
    virtual bool f1_00234270(void*);
    CTrack_6aa80();
};
class CRageModeTrack : public ::CRageModeTrack {
  public:
    CRageModeTrack();
};
CRageModeTrack::CRageModeTrack() {
    f_08 = 1;
    f_0c = 0;
    f_10 = 0;
}
} // namespace fn_0006aa80


// 0x0006aab0 CRageModeTrack::vfunc_13 (13 B): matches/0x0006aab0.cpp
// sym: ?vfunc_13@CRageModeTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CRageModeTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006aac0 CRageModeTrack::vfunc_6 (4 B): matches/0x0006aac0.cpp
// sym: ?vfunc_6@CRageModeTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CRageModeTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006aad0 CRageModeTrack::vfunc_7 (7 B): matches/0x0006aad0.cpp
// sym: ?vfunc_7@CRageModeTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CRageModeTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0006aaf0 CRageModeTrack::vfunc_12 (43 B): matches/0x0006aaf0.cpp
// sym: ?vfunc_12@CRageModeTrack@@UAEHH@Z
hulk_intptr CRageModeTrack::vfunc_12(hulk_intptr param) {
    Other_6aaf0* p = FUN_0008d690(0x24);
    if (p)
        return p->call_00020120(param, this->f_10);
    return 0;
}

