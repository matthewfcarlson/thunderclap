// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00068f90..0x00069400 (kind game, layer game, confidence high), dominant class CJumpTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3ca8e6b {
#define TREE_TU_END }
namespace fn_f3ca8e6b {} using namespace fn_f3ca8e6b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3ca8e6b {
extern int* hulk_at_004dcf20;
class CTrack_69130 {
  public:
    virtual void v0();
    char pad[0x4c - 4];
    float value;
};
struct Param_69160 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_69160 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Curve_69210 {
 char pad0[0x14];
 float startScale;
 float endScale;
 char pad1[8];
 float startValue;
 float endValue;
 hulk_freg FUN_00069210(float t);
};
struct Curve_692c0 {
 char pad[0x14];
 float a0, a1, b0, b1;
 hulk_freg FUN_000692c0(float t);
};
class Obj_69370 {
  public:
    char pad[0x30];
    int a;
    int b;
    int c;
    int d;
    hulk_freg f(int);
};
float callee_000963c0(int, int, int, int, int);
class Alloc_693d0 {
  public:
    int call_00018ca0(CJumpTrack*, hulk_intptr);
};
extern "C" int __cdecl FUN_0008d690(int);


// 0x00068f90 FUN_00068f90 (19 B): matches/0x00068f90.cpp
// sym: ?FUN_00068f90@fn_f3ca8e6b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00068f90(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf20), ((char*)&DAT_004dcf24));
}

} // namespace fn_f3ca8e6b

// 0x00068fb0 CJumpTrack::vfunc_0 (16 B): matches/0x00068fb0.cpp
// sym: ?vfunc_0@CJumpTrack@@UAEHH@Z
hulk_intptr CJumpTrack::vfunc_0(int index) {
    return hulk_at_004dcf20[index];
}


// 0x00068fc0 FUN_00068fc0 (83 B): matches/0x00068fc0.cpp [wrapped: conflict: CJumpTrack]
// sym: ??0CJumpTrack@fn_00068fc0@@QAE@XZ
namespace fn_00068fc0 {
class CTrack_68fc0 {
  public:
    virtual hulk_intptr F0_00068fb0(int);
    virtual bool F1_00234270(void*);
    CTrack_68fc0();
    int mBase0;
    int mBase1;
};

class CJumpTrack : public ::CJumpTrack {
  public:
    CJumpTrack();
};

CJumpTrack::CJumpTrack() {
    f_0c = 0;
    f_14 = 0;
    f_18 = 0;
    f_1c = 0;
    f_20 = 0;
    f_24 = 0;
    f_28 = 0;
    f_30 = 0;
    f_34 = 0;
    f_38 = 0;
    f_3c = 0;
    f_40 = 0;
    f_48 = 0;
    f_4c = 0;
    f_51 = 0;
    f_10 = -1.0f;
    f_2c = 7.0f;
    f_50 = 1;
}
} // namespace fn_00068fc0


// 0x00069020 CJumpTrack::vfunc_13 (13 B): matches/0x00069020.cpp
// sym: ?vfunc_13@CJumpTrack@@UAEXPAX@Z
void CJumpTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x00069030 CJumpTrack::vfunc_6 (4 B): matches/0x00069030.cpp
// sym: ?vfunc_6@CJumpTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CJumpTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069040 CJumpTrack::vfunc_14 (4 B): matches/0x00069040.cpp
// sym: ?vfunc_14@CJumpTrack@@UAEMXZ
// Same code shape as 0x0005d1d0 (propagated; names are from that function)
hulk_freg CJumpTrack::vfunc_14() {
    return this->f_10;
}


// 0x00069050 CJumpTrack::vfunc_15 (4 B): matches/0x00069050.cpp
// sym: ?vfunc_15@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_15() {
    return this->f_14;
}


// 0x00069060 CJumpTrack::vfunc_16 (4 B): matches/0x00069060.cpp
// sym: ?vfunc_16@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_16() {
    return this->f_18;
}


// 0x00069070 CJumpTrack::vfunc_17 (4 B): matches/0x00069070.cpp
// sym: ?vfunc_17@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_17() {
    return this->f_1c;
}


// 0x00069080 CJumpTrack::vfunc_18 (4 B): matches/0x00069080.cpp
// sym: ?vfunc_18@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_18() {
    return this->f_20;
}


// 0x00069090 CJumpTrack::vfunc_19 (4 B): matches/0x00069090.cpp
// sym: ?vfunc_19@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_19() {
    return this->f_24;
}


// 0x000690a0 CJumpTrack::vfunc_20 (4 B): matches/0x000690a0.cpp
// sym: ?vfunc_20@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_20() {
    return this->f_28;
}


// 0x000690b0 CJumpTrack::vfunc_21 (4 B): matches/0x000690b0.cpp
// sym: ?vfunc_21@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_21() {
    return *(float*)((char*)&this->f_2c);
}


// 0x000690c0 CJumpTrack::vfunc_22 (4 B): matches/0x000690c0.cpp
// sym: ?vfunc_22@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_22() {
    return this->f_30;
}


// 0x000690d0 CJumpTrack::vfunc_23 (4 B): matches/0x000690d0.cpp
// sym: ?vfunc_23@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_23() {
    return this->f_34;
}


// 0x000690e0 CJumpTrack::vfunc_24 (4 B): matches/0x000690e0.cpp
// sym: ?vfunc_24@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_24() {
    return this->f_38;
}


// 0x000690f0 CJumpTrack::vfunc_25 (4 B): matches/0x000690f0.cpp
// sym: ?vfunc_25@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_25() {
    return this->f_3c;
}


// 0x00069100 CJumpTrack::vfunc_26 (4 B): matches/0x00069100.cpp
// sym: ?vfunc_26@CJumpTrack@@UAEIXZ
unsigned int CJumpTrack::vfunc_26() {
    return this->f_40;
}


// 0x00069110 CJumpTrack::vfunc_27 (4 B): matches/0x00069110.cpp
// sym: ?vfunc_27@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_27() {
    return *(float*)((char*)this + 0x44);
}


// 0x00069120 CJumpTrack::vfunc_28 (4 B): matches/0x00069120.cpp
// sym: ?vfunc_28@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_28() {
    return this->f_48;
}


// 0x00069130 CJumpTrack::vfunc_29 (4 B): matches/0x00069130.cpp
// sym: ?vfunc_29@CJumpTrack@@UAEMXZ
hulk_freg CJumpTrack::vfunc_29() {
    return this->f_4c;
}


// 0x00069140 CJumpTrack::vfunc_30 (4 B): matches/0x00069140.cpp
// sym: ?vfunc_30@CJumpTrack@@UAEEXZ
unsigned char CJumpTrack::vfunc_30() {
    return *((char*)&this->f_50);
}


// 0x00069150 CJumpTrack::vfunc_31 (4 B): matches/0x00069150.cpp
// sym: ?vfunc_31@CJumpTrack@@UAEEXZ
unsigned char CJumpTrack::vfunc_31() {
    return (*(char (*)[77])&this->f_04)[0x4d];
}


// 0x00069160 CJumpTrack::vfunc_7 (7 B): matches/0x00069160.cpp
// sym: ?vfunc_7@CJumpTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CJumpTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f3ca8e6b {

// 0x00069210 FUN_00069210 (173 B): equivalent/0x00069210.cpp
// sym: ?FUN_00069210@Curve_69210@fn_f3ca8e6b@@QAEMM@Z @8777d06539c4 @w253041b25953
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 11/12, incomplete)
// FUN_00069210 @ 0x00069210
hulk_freg Curve_69210::FUN_00069210(float t) {
 volatile float scale = startScale;
 volatile float delta = endScale - startScale;
 if (!(scale > 0.0f)) return 0.0f;
 if (delta >= 0.0f && t >= 0.0f && t <= 1.0f) scale = delta * t + startScale;
 if (!(scale > 0.0f)) return 0.0f;
 if (endValue - startValue >= 0.0f) return ((endValue - startValue) * t + startValue) / scale;
 return startValue / scale;
}


// 0x000692c0 FUN_000692c0 (169 B): equivalent/0x000692c0.cpp
// sym: ?FUN_000692c0@Curve_692c0@fn_f3ca8e6b@@QAEMM@Z @8ae024cd445a @we69af9e5290d
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_000692c0 @ 0x000692c0
hulk_freg Curve_692c0::FUN_000692c0(float t) {
 float db = b1-b0;
 float da = a1-a0;
 double b=b0, a=a0;
 if (db >= 0.0f && da >= 0.0f && t >= 0.0f && t <= 1.0f) {
  b=(double)db*t+b0;
  a=(double)da*t+a0;
 }
 if (a <= 0.0) return 0.0f;
 return (hulk_freg)((b+b)/(a*a));
}


// 0x00069370 FUN_00069370 (32 B): matches/0x00069370.cpp
// sym: ?f@Obj_69370@fn_f3ca8e6b@@QAEMH@Z
hulk_freg Obj_69370::f(int x) {
    return callee_000963c0(b, a, d, c, x);
}


// 0x00069390 FUN_00069390 (39 B): matches/0x00069390.cpp
// sym: ?target@fn_f3ca8e6b@@YGNMM@Z
// data: zero_69390 = DAT_003f32e0
double __stdcall target(float a, float b) {
    if (a <= DAT_003f32e0)
        return DAT_003f32e0;
    return b / a + b / a;
}

} // namespace fn_f3ca8e6b

// 0x000693d0 CJumpTrack::vfunc_12 (40 B): matches/0x000693d0.cpp
// sym: ?vfunc_12@CJumpTrack@@UAEHH@Z
hulk_intptr CJumpTrack::vfunc_12(hulk_intptr param) {
    hulk_intptr x = FUN_0008d690(0x3c);
    if (x)
        return ((Alloc_693d0*)x)->call_00018ca0(this, param);
    return 0;
}

