// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a040..0x0006a120 (kind game, layer game, confidence high), dominant class CInvincibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fc4ebd1a {
#define TREE_TU_END }
namespace fn_fc4ebd1a {} using namespace fn_fc4ebd1a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc4ebd1a {
extern int* hulk_at_004dcf88;
class CCondition_6a060 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6a0c0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a0c0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Object_6a0e0 { int FUN_0001f4e0(hulk_intptr, int); };
extern "C" Object_6a0e0* __cdecl FUN_0008d690(int);


// 0x0006a040 FUN_0006a040 (19 B): matches/0x0006a040.cpp
// sym: ?FUN_0006a040@fn_fc4ebd1a@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a040(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf88), ((char*)&DAT_004dcf8c));
}

} // namespace fn_fc4ebd1a

// 0x0006a060 CInvincibleTrack::vfunc_0 (16 B): matches/0x0006a060.cpp
// sym: ?vfunc_0@CInvincibleTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CInvincibleTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf88;
    return p[index];
}


// 0x0006a070 FUN_0006a070 (40 B): matches/0x0006a070.cpp [wrapped: conflict: CInvincibleTrack]
// sym: ??0CInvincibleTrack@fn_0006a070@@QAE@XZ
namespace fn_0006a070 {
class CTrack_6a070 {
  public:
    CTrack_6a070();
    virtual hulk_intptr B0_0006a060(int);
    int m_base;
};

class CInvincibleTrack : public CTrack_6a070 {
  public:
    CInvincibleTrack();
    virtual bool Fn0_00234270(void*);
    virtual bool Fn1_002342b0(int);
    virtual bool Fn2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool Fn3_00234350(int, int);
    int m_n;
    int m_a;
    float m_f;
    int m_b;
};

CInvincibleTrack::CInvincibleTrack() : CTrack_6a070() {
    m_a = 0;
    m_b = 0;
    m_f = -1.0f;
    m_n = 1;
}
} // namespace fn_0006a070


// 0x0006a0a0 CInvincibleTrack::vfunc_13 (13 B): matches/0x0006a0a0.cpp
// sym: ?vfunc_13@CInvincibleTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CInvincibleTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a0b0 CInvincibleTrack::vfunc_6 (4 B): matches/0x0006a0b0.cpp
// sym: ?vfunc_6@CInvincibleTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CInvincibleTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a0c0 CInvincibleTrack::vfunc_7 (7 B): matches/0x0006a0c0.cpp
// sym: ?vfunc_7@CInvincibleTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CInvincibleTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006a0e0 CInvincibleTrack::vfunc_12 (52 B): equivalent/0x0006a0e0.cpp
// sym: ?vfunc_12@CInvincibleTrack@@UAEHH@Z @c8d490d559d3 @wb2df52196c5d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CInvincibleTrack::vfunc_12 @ 0x0006a0e0
hulk_intptr CInvincibleTrack::vfunc_12(hulk_intptr arg) { Object_6a0e0* p = FUN_0008d690(0x24); if (p) return p->FUN_0001f4e0(arg, this->f_14); return 0; }

