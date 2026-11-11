// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a890..0x0006a970 (kind game, layer game, confidence high), dominant class CUninterruptibleTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ff910add {
#define TREE_TU_END }
namespace fn_ff910add {} using namespace fn_ff910add;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff910add {
extern int* gTable_6a8b0;
class CCondition_6a8b0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6a910 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a910 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void* __cdecl FUN_0008d690(int);
struct CUninterruptibleAction_6a930 { void* FUN_00020020(hulk_intptr arg, int value); };


// 0x0006a890 FUN_0006a890 (19 B): matches/0x0006a890.cpp
// sym: ?FUN_0006a890@fn_ff910add@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a890() {
    FUN_00234810(((char*)&DAT_004dcfd0), ((char*)&DAT_004dcfd4));
}

} // namespace fn_ff910add

// 0x0006a8b0 CUninterruptibleTrack::vfunc_0 (16 B): matches/0x0006a8b0.cpp
// sym: ?vfunc_0@CUninterruptibleTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CUninterruptibleTrack::vfunc_0(int index) {
    int* p = gTable_6a8b0;
    return p[index];
}


// 0x0006a8c0 FUN_0006a8c0 (40 B): matches/0x0006a8c0.cpp [wrapped: conflict: CUninterruptibleTrack]
// sym: ??0CUninterruptibleTrack@fn_0006a8c0@@QAE@XZ
namespace fn_0006a8c0 {
class CTrack_6a8c0 {
  public:
    CTrack_6a8c0();
    virtual void BaseFn();
};

class CUninterruptibleTrack : public CTrack_6a8c0 {
  public:
    CUninterruptibleTrack();
    virtual void Fn();
    char pad4[4];
    int m8;
    int m_c;
    float m_10;
    int m_14;
};

CUninterruptibleTrack::CUninterruptibleTrack() {
    m_c = 0;
    m_14 = 0;
    m_10 = -1.0f;
    m8 = 1;
}
} // namespace fn_0006a8c0


// 0x0006a8f0 CUninterruptibleTrack::vfunc_13 (13 B): matches/0x0006a8f0.cpp
// sym: ?vfunc_13@CUninterruptibleTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CUninterruptibleTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a900 CUninterruptibleTrack::vfunc_6 (4 B): matches/0x0006a900.cpp
// sym: ?vfunc_6@CUninterruptibleTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CUninterruptibleTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0006a910 CUninterruptibleTrack::vfunc_7 (7 B): matches/0x0006a910.cpp
// sym: ?vfunc_7@CUninterruptibleTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CUninterruptibleTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0006a930 CUninterruptibleTrack::vfunc_12 (52 B): equivalent/0x0006a930.cpp
// sym: ?vfunc_12@CUninterruptibleTrack@@UAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CUninterruptibleTrack::vfunc_12 @ 0x0006a930
hulk_intptr CUninterruptibleTrack::vfunc_12(hulk_intptr arg) { CUninterruptibleAction_6a930* item = (CUninterruptibleAction_6a930*)FUN_0008d690(0x24); if (!item) return (int)(0); return (hulk_intptr)(item->FUN_00020020(arg, this->extensionTime)); }

