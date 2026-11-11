// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069f70..0x0006a040 (kind game, layer game, confidence high), dominant class CComboTimerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f976a5d0 {
#define TREE_TU_END }
namespace fn_f976a5d0 {} using namespace fn_f976a5d0;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f976a5d0 {
extern int* hulk_at_004dcf80;
struct Param_69ff0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_69ff0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void* __cdecl FUN_0008d690(int);
struct Worker_6a010 {
    int go_0001dbc0(unsigned int, unsigned int);
};


// 0x00069f70 FUN_00069f70 (19 B): matches/0x00069f70.cpp
// sym: ?FUN_00069f70@fn_f976a5d0@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069f70() {
    FUN_00234810(((char*)&DAT_004dcf80), ((char*)&DAT_004dcf84));
}

} // namespace fn_f976a5d0

// 0x00069f90 CComboTimerTrack::vfunc_0 (16 B): matches/0x00069f90.cpp
// sym: ?vfunc_0@CComboTimerTrack@@UAEHH@Z
hulk_intptr CComboTimerTrack::vfunc_0(int index) {
    return hulk_at_004dcf80[index];
}


// 0x00069fa0 FUN_00069fa0 (40 B): matches/0x00069fa0.cpp [wrapped: conflict: CComboTimerTrack]
// sym: ??0CComboTimerTrack@fn_00069fa0@@QAE@XZ
namespace fn_00069fa0 {
class CTrack_69fa0 {
  public:
    CTrack_69fa0();
    virtual ~CTrack_69fa0();
};

class CComboTimerTrack : public CTrack_69fa0 {
  public:
    virtual ~CComboTimerTrack();
    CComboTimerTrack();
    char pad4[4];
    int m8;
    int mC;
    float m10;
    int m14;
};

CComboTimerTrack::CComboTimerTrack() {
    mC = 0;
    m14 = 0;
    m10 = -1.0f;
    m8 = 1;
}
} // namespace fn_00069fa0


// 0x00069fd0 CComboTimerTrack::vfunc_13 (13 B): matches/0x00069fd0.cpp
// sym: ?vfunc_13@CComboTimerTrack@@UAEXPAX@Z
void CComboTimerTrack::vfunc_13(void* __p0) { unsigned long * p = (unsigned long *)__p0;

    *p = 0xffff7f40UL;
}


// 0x00069fe0 CComboTimerTrack::vfunc_6 (4 B): matches/0x00069fe0.cpp
// sym: ?vfunc_6@CComboTimerTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CComboTimerTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00069ff0 CComboTimerTrack::vfunc_7 (7 B): matches/0x00069ff0.cpp
// sym: ?vfunc_7@CComboTimerTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CComboTimerTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0006a010 CComboTimerTrack::vfunc_12 (43 B): matches/0x0006a010.cpp
// sym: ?vfunc_12@CComboTimerTrack@@UAEHH@Z
hulk_intptr CComboTimerTrack::vfunc_12(hulk_intptr __p0) { unsigned int param = (unsigned int)__p0;

    void* p = FUN_0008d690(0x24);
    if (p)
        return ((Worker_6a010*)p)->go_0001dbc0(param, this->comboTimer);
    return 0;
}

