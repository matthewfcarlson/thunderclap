// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d0f0..0x0010d230 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fda30a1e {
#define TREE_TU_END }
namespace fn_fda30a1e {} using namespace fn_fda30a1e;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fda30a1e {
struct Tail_10d0f0 {
    void Init_0027af50();
};
struct SemaphoreClearTrack {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0040db84;
extern int* hulk_at_004e0b68;
class CCondition_10d130 {
  public:
    virtual int vfunc_0(int);
};
extern void *DAT_0040dbb4[];
struct TokenSupressTrack { void *vptr; char pad4[4]; int enabled; int target; float limit; unsigned char active; char pad15[3]; float value; unsigned char flag1, flag2; void FUN_00236d40(); TokenSupressTrack *FUN_0010d140(); };
extern int* hulk_at_004e0b70;
class CCondition_10d1c0 {
  public:
    virtual int vfunc_0(int);
};
extern void* g_vftable[];
class Track_10d1d0 {
  public:
    Track_10d1d0() throw();
    virtual void F0();
};
class AIHistoryCountTrack : public Track_10d1d0 {
  public:
    AIHistoryCountTrack() throw();
    virtual void F0();
    char pad[8];
    int mField;
};


// 0x0010d0f0 FUN_0010d0f0 (25 B): matches/0x0010d0f0.cpp
// sym: ?Run@SemaphoreClearTrack@fn_fda30a1e@@QAEXXZ
void SemaphoreClearTrack::Run() {
    vptr = &hulk_at_0040db84;
    ((Tail_10d0f0*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x0010d110 FUN_0010d110 (19 B): matches/0x0010d110.cpp
// sym: ?FUN_0010d110@fn_fda30a1e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d110() {
    FUN_00234810(((char*)&DAT_004e0b68), ((char*)&DAT_004e0b6c));
}

} // namespace fn_fda30a1e

// 0x0010d130 hulkfight::ai::TokenSupressTrack::vfunc_0 (16 B): matches/0x0010d130.cpp
// sym: ?vfunc_0@TokenSupressTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TokenSupressTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0b68;
    return p[index];
}

namespace fn_fda30a1e {

// 0x0010d140 FUN_0010d140 (51 B): equivalent/0x0010d140.cpp
// sym: ?FUN_0010d140@TokenSupressTrack@fn_fda30a1e@@QAEPAU12@XZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0010d140 @ 0x0010d140
TokenSupressTrack *TokenSupressTrack::FUN_0010d140() { FUN_00236d40(); target = 0; flag1 = 0; flag2 = 0; vptr = DAT_0040dbb4; limit = -1.0f; active = 1; value = -1.0f; enabled = 1; return this; }

} // namespace fn_fda30a1e

// 0x0010d180 hulkfight::ai::TokenSupressTrack::vfunc_6 (4 B): matches/0x0010d180.cpp
// sym: ?vfunc_6@TokenSupressTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::TokenSupressTrack::vfunc_6() {
    return this->f_0c;
}

namespace fn_fda30a1e {

// 0x0010d1a0 FUN_0010d1a0 (19 B): matches/0x0010d1a0.cpp
// sym: ?FUN_0010d1a0@fn_fda30a1e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d1a0() {
    FUN_00234810(((char*)&DAT_004e0b70), ((char*)&DAT_004e0b74));
}

} // namespace fn_fda30a1e

// 0x0010d1c0 hulkfight::ai::AIHistoryCountTrack::vfunc_0 (16 B): matches/0x0010d1c0.cpp
// sym: ?vfunc_0@AIHistoryCountTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::AIHistoryCountTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0b70;
    return p[index];
}

namespace fn_fda30a1e {

// 0x0010d1d0 FUN_0010d1d0 (25 B): matches/0x0010d1d0.cpp
// sym: ??0AIHistoryCountTrack@fn_fda30a1e@@QAE@XZ
AIHistoryCountTrack::AIHistoryCountTrack() throw() : Track_10d1d0() {
    mField = 0;
}

} // namespace fn_fda30a1e

// 0x0010d1f0 hulkfight::ai::AIHistoryCountTrack::vfunc_6 (7 B): matches/0x0010d1f0.cpp
// sym: ?vfunc_6@AIHistoryCountTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::ai::AIHistoryCountTrack::vfunc_6() {
    return DAT_003f32e0;
}

namespace fn_fda30a1e {

// 0x0010d210 FUN_0010d210 (19 B): matches/0x0010d210.cpp
// sym: ?FUN_0010d210@fn_fda30a1e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d210() {
    FUN_00234810(((char*)&DAT_004e0b78), ((char*)&DAT_004e0b7c));
}

} // namespace fn_fda30a1e
