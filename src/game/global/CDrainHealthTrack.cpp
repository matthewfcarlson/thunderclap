// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069e70..0x00069f70 (kind game, layer game, confidence high), dominant class CDrainHealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fa8c69cd {
#define TREE_TU_END }
namespace fn_fa8c69cd {} using namespace fn_fa8c69cd;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa8c69cd {
extern int* hulk_at_004dcf78;
class CCondition_69e90 {
  public:
    virtual int vfunc_0(int);
};
struct Param_69ef0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_69ef0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern const float hulk_at_003f32e0;
class Helper_69f10 {
  public:
    int Apply_0001db40(hulk_intptr, float);
};
extern "C" int __cdecl FUN_0008d690(int);


// 0x00069e70 FUN_00069e70 (19 B): matches/0x00069e70.cpp
// sym: ?FUN_00069e70@fn_fa8c69cd@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069e70() {
    FUN_00234810(((char*)&DAT_004dcf78), ((char*)&DAT_004dcf7c));
}

} // namespace fn_fa8c69cd

// 0x00069e90 CDrainHealthTrack::vfunc_0 (16 B): matches/0x00069e90.cpp
// sym: ?vfunc_0@CDrainHealthTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CDrainHealthTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf78;
    return p[index];
}


// 0x00069ea0 FUN_00069ea0 (40 B): matches/0x00069ea0.cpp [wrapped: conflict: CDrainHealthTrack]
// sym: ??0CDrainHealthTrack@fn_00069ea0@@QAE@XZ
namespace fn_00069ea0 {
class CTrack_69ea0 {
  public:
    virtual hulk_intptr g0_00069e90(int);
    virtual bool g1_00234270(void*);
    virtual bool g2_002342b0(int);
    virtual bool g3_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool g4_00234350(int, int);
    virtual void* g5_0006b870(char);
    virtual void g6_00069ee0();
    virtual void g7_00069ef0();
    virtual int g8_00068c80(int, int);
    virtual int g9_00236bb0(hulk_intptr, hulk_intptr, hulk_intptr);
    CTrack_69ea0();
    int m4;
};

class CDrainHealthTrack : public CTrack_69ea0 {
  public:
    virtual int f0_00068cb0(int, int, int);
    virtual int f1_00068ca0(int);
    virtual hulk_intptr f2_00069f10(hulk_intptr);
    virtual void f3_00069ed0(void*);
    virtual void f4();
    virtual hulk_intptr f5_00069f90(int);
    virtual bool f6_00234270(void*);
    virtual bool f7_002342b0(int);
    virtual bool f8_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool f9_00234350(int, int);
    virtual void* fA_0006b8a0(char);
    virtual void fB_00069fe0();
    virtual void fC_00069ff0();
    virtual int fD_00068c80(int, int);
    virtual int fE_00236bb0(hulk_intptr, hulk_intptr, hulk_intptr);
    virtual int fF_00068cb0(int, int, int);
    int m8;
    int mC;
    float m10;
    int m14;
    CDrainHealthTrack();
};

CDrainHealthTrack::CDrainHealthTrack() {
    mC = 0;
    m14 = 0;
    m10 = 1.0f;
    m8 = 1;
}
} // namespace fn_00069ea0


// 0x00069ed0 CDrainHealthTrack::vfunc_13 (13 B): matches/0x00069ed0.cpp
// sym: ?vfunc_13@CDrainHealthTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CDrainHealthTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x00069ee0 CDrainHealthTrack::vfunc_6 (4 B): matches/0x00069ee0.cpp
// sym: ?vfunc_6@CDrainHealthTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CDrainHealthTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069ef0 CDrainHealthTrack::vfunc_7 (7 B): matches/0x00069ef0.cpp
// sym: ?vfunc_7@CDrainHealthTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CDrainHealthTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x00069f10 CDrainHealthTrack::vfunc_12 (89 B): matches/0x00069f10.cpp
// sym: ?vfunc_12@CDrainHealthTrack@@UAEHH@Z
hulk_intptr CDrainHealthTrack::vfunc_12(hulk_intptr arg) {
    float value = vfunc_7();
    if (!(value <= hulk_at_003f32e0)) {
        float a = this->f_14;
        hulk_intptr obj = FUN_0008d690(0x24);
        if (obj)
            return ((Helper_69f10*)obj)->Apply_0001db40(arg, a / value);
    }
    return 0;
}

