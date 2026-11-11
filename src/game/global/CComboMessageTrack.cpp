// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069790..0x00069880 (kind game, layer game, confidence high), dominant class CComboMessageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f8f15a4b {
#define TREE_TU_END }
namespace fn_f8f15a4b {} using namespace fn_f8f15a4b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8f15a4b {
extern int* hulk_at_004dcf40;
extern "C" void __cdecl FUN_00267830(void*, void*, int);
class X {
  public:
    char pad[16];
    char data[64];
    bool Fn(void* p);
};
class R_69850 {
  public:
    int invoke_0001d210(CComboMessageTrack*, hulk_intptr);
};
extern "C" R_69850* FUN_0008d690(int);


// 0x00069790 FUN_00069790 (19 B): matches/0x00069790.cpp
// sym: ?FUN_00069790@fn_f8f15a4b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069790() {
    FUN_00234810(((char*)&DAT_004dcf40), ((char*)&DAT_004dcf44));
}

} // namespace fn_f8f15a4b

// 0x000697b0 CComboMessageTrack::vfunc_0 (16 B): matches/0x000697b0.cpp
// sym: ?vfunc_0@CComboMessageTrack@@UAEHH@Z
hulk_intptr CComboMessageTrack::vfunc_0(int index) {
    return hulk_at_004dcf40[index];
}


// 0x000697c0 FUN_000697c0 (36 B): matches/0x000697c0.cpp [wrapped: conflict: CComboMessageTrack]
// sym: ??0CComboMessageTrack@fn_000697c0@@QAE@XZ
namespace fn_000697c0 {
class CTrack_697c0 {
  public:
    virtual hulk_intptr B0_000697b0(int);
    CTrack_697c0();
};

class CComboMessageTrack : public CTrack_697c0 {
  public:
    virtual bool Fn0_00234270(void*);
    int m4;
    int m8;
    int mC;
    char m10;
    char pad[0x3F];
    int m50;
    CComboMessageTrack();
};

CComboMessageTrack::CComboMessageTrack() {
    mC = 0;
    m50 = 0;
    m10 = 0;
    m8 = 1;
}
} // namespace fn_000697c0


// 0x000697f0 CComboMessageTrack::vfunc_13 (13 B): matches/0x000697f0.cpp
// sym: ?vfunc_13@CComboMessageTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CComboMessageTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00069800 CComboMessageTrack::vfunc_6 (4 B): matches/0x00069800.cpp
// sym: ?vfunc_6@CComboMessageTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CComboMessageTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069810 CComboMessageTrack::vfunc_7 (7 B): matches/0x00069810.cpp
// sym: ?vfunc_7@CComboMessageTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CComboMessageTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f8f15a4b {

// 0x00069830 FUN_00069830 (24 B): matches/0x00069830.cpp
// sym: ?Fn@X@fn_f8f15a4b@@QAE_NPAX@Z
bool X::Fn(void* p) {
    FUN_00267830(data, p, 64);
    return true;
}

} // namespace fn_f8f15a4b

// 0x00069850 CComboMessageTrack::vfunc_12 (40 B): matches/0x00069850.cpp
// sym: ?vfunc_12@CComboMessageTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CComboMessageTrack::vfunc_12(hulk_intptr param) {
    R_69850* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001d210(this, param);
    return 0;
}

