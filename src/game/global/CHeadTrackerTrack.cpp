// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006abf0..0x0006ad60 (kind game, layer game, confidence high), dominant class CHeadTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc9b775c {
#define TREE_TU_END }
namespace fn_fc9b775c {} using namespace fn_fc9b775c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc9b775c {
extern int* hulk_at_004dcff0;
class CCondition_6ac10 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6ace0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6ace0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_003fc0d0[];
extern void* hulk_at_003f98d0[];
struct Sub_6acf0 {
    void Fin_0027af50();
};
class CTrack_6acf0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class CHeadTrackerTrack_6acf0 : public CTrack_6acf0 {
  public:
    char pad[0x14];
    Sub_6acf0 sub;
    void f();
};
extern const float kRadiansToDegrees = 0.017453292f;
class Helper_6ad30 {
  public:
    int run_00020220(CHeadTrackerTrack*, hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);


// 0x0006abf0 FUN_0006abf0 (19 B): matches/0x0006abf0.cpp
// sym: ?FUN_0006abf0@fn_fc9b775c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006abf0() {
    FUN_00234810(((char*)&DAT_004dcff0), ((char*)&DAT_004dcff4));
}

} // namespace fn_fc9b775c

// 0x0006ac10 CHeadTrackerTrack::vfunc_0 (16 B): matches/0x0006ac10.cpp
// sym: ?vfunc_0@CHeadTrackerTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CHeadTrackerTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcff0;
    return p[index];
}


// 0x0006ac20 FUN_0006ac20 (151 B): equivalent/0x0006ac20.cpp [wrapped: conflict: CHeadTrackerTrack]
// sym: ??0CHeadTrackerTrack@fn_0006ac20@@QAE@XZ
namespace fn_0006ac20 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0006ac20 @ 0x0006ac20
struct Name_6ac20 {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) CTrack_6ac20 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_6ac20() { FUN_00236d40(); }
};

class CHeadTrackerTrack : public CTrack_6ac20 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c;
    float f10;
    int pad14;
    Name_6ac20 bone;
    float f20, f24;
    int f28, f2c, f30;
    float f34, f38, f3c, f40, f44, f48, f4c, f50;
    int f54;
    float f58, f5c;

    CHeadTrackerTrack();
};

CHeadTrackerTrack::CHeadTrackerTrack() {
    f0c = 0;
    f10 = -1.0f;
    bone.FUN_0027af00();
    f20 = 0.5f;
    f24 = -1.0f;
    f28 = 0; f2c = 0; f30 = 0;
    f34 = 1.0f;
    f40 = 0.7853981852531433f;
    f48 = 0.7853981852531433f;
    f3c = -0.7853981852531433f;
    f44 = -0.7853981852531433f;
    f38 = 3.1415927410125732f;
    f4c = 3.1415927410125732f;
    f50 = 10.0f;
    f54 = -5;
    f58 = 0.25f;
    f5c = 0.25f;
    bone.FUN_0027b040("Head");
    pad08 = 1;
}
} // namespace fn_0006ac20


// 0x0006acc0 CHeadTrackerTrack::vfunc_13 (13 B): matches/0x0006acc0.cpp
// sym: ?vfunc_13@CHeadTrackerTrack@@UAEXPAX@Z
// Same code shape as 0x00068d10 (propagated; names are from that function)
void CHeadTrackerTrack::vfunc_13(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    *out = 0xffff7f7f;
}


// 0x0006acd0 CHeadTrackerTrack::vfunc_6 (4 B): matches/0x0006acd0.cpp
// sym: ?vfunc_6@CHeadTrackerTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CHeadTrackerTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006ace0 CHeadTrackerTrack::vfunc_7 (7 B): matches/0x0006ace0.cpp
// sym: ?vfunc_7@CHeadTrackerTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CHeadTrackerTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fc9b775c {

// 0x0006acf0 FUN_0006acf0 (31 B): matches/0x0006acf0.cpp
// sym: ?f@CHeadTrackerTrack_6acf0@fn_fc9b775c@@QAEXXZ
void CHeadTrackerTrack_6acf0::f() {
    vptr = hulk_at_003fc0d0;
    sub.Fin_0027af50();
    vptr = hulk_at_003f98d0;
    Fin_00236d60();
}

} // namespace fn_fc9b775c

// 0x0006ad10 FUN_0006ad10 (18 B): matches/0x0006ad10.cpp
// sym: ?FUN_0006ad10@Thing_6ad10@owners@@QAE_NM@Z
bool owners::Thing_6ad10::FUN_0006ad10(float degrees) {
    value = degrees * kRadiansToDegrees;
    return true;
}


// 0x0006ad30 CHeadTrackerTrack::vfunc_12 (43 B): matches/0x0006ad30.cpp
// sym: ?vfunc_12@CHeadTrackerTrack@@UAEHH@Z
hulk_intptr CHeadTrackerTrack::vfunc_12(hulk_intptr param) {
    Helper_6ad30* p = (Helper_6ad30*)FUN_0008d690(0x90);
    if (p)
        return p->run_00020220(this, param);
    return 0;
}

