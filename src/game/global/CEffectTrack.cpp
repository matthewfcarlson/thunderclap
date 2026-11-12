// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000604d0..0x00061b40 (kind game, layer game, confidence high), dominant class CEffectTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb6e447b {
#define TREE_TU_END }
namespace fn_fb6e447b {} using namespace fn_fb6e447b;
namespace fn_fb6e447b { extern "C" char DAT_003faab4[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb6e447b {
class T_604d0 {
  public:
    char pad[12];
    int value;
    char SetTimeBegin_000604d0(int v);
};
class Obj_604e0 {
  public:
    char Pad[0x10];
    int Value;
    char SetSlot_000604e0(int a);
};
class Obj_604f0 {
  public:
    char pad[0x14];
    int mVal;
    char SetSlotMax_000604f0(int v);
};
extern int* hulk_at_004dc600;
class CCondition_60520 {
  public:
    virtual int vfunc_0(int);
};
extern void* FUN_0008d690(unsigned int);
struct Helper_605b0 {
    int FUN_0001f640(CMotionTrailTrack*, hulk_intptr);
};
extern "C" hulk_intptr __cdecl FUN_0005a3f0(hulk_intptr value);
struct Obj_605f0 {
    char pad[0x104];
    int value;
};
extern Obj_605f0* FUN_0005a430(int);
struct Alloc_605f0 {
    int invoke_0001f640(CGrappleMotionTrailTrack*, int);
};
extern int* hulk_at_004dc608;
class CCondition_60650 {
  public:
    virtual int vfunc_0(int);
};
struct Angles { float x, y, z; };
struct Object { char pad[0x44]; Angles angles; void FUN_00060770(Angles *out); };
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x44];
    float x, y, z;

  public:
    unsigned char SetAngles(const Vec* v);
};
class Helper_60810 {
  public:
    int Run_0001f6c0(CEffectTrack*, hulk_intptr, hulk_intptr);
};
extern void* Get_0008d690(int);
class Obj_60850 {
  public:
    int run_0001f6c0(void*, int, hulk_intptr);
};
struct Thing_60850 {
    char pad[0x104];
    int value;
};
extern void* Alloc_0008d690(int);
extern Thing_60850* GetThing_0005a430(int);
extern int* hulk_at_004dc610;
class CCondition_608c0 {
  public:
    virtual int vfunc_0(int);
};
class CTrack_608d0 {
  public:
    CTrack_608d0();
    virtual hulk_intptr FnA_000608c0(int);
    virtual bool FnB_00234270(void*);
    int m4;
};
class CEffectStopTrack_608d0 : public CTrack_608d0 {
  public:
    CEffectStopTrack_608d0();
    virtual bool FnC_002342b0(int);
    int m8;
    int mC;
    int m10;
    int m14;
};
class R_60940 {
  public:
    int invoke_0001f780(CEffectStopTrack*, hulk_intptr);
};
extern R_60940* FUN_0008d690(int);
class CStageCondition_60bf0;
class ParamValue_60bf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60bf0 : public ParamValue_60bf0 {
  public:
    int pad;
};
class CStageCondition_60c40;
class ParamValue_60c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60c40 : public ParamValue_60c40 {
  public:
    int pad;
};
class CStageCondition_60c90;
class ParamValue_60c90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60c90 : public ParamValue_60c90 {
  public:
    int pad;
};
class CStageCondition_60ce0;
class ParamValue_60ce0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60ce0 : public ParamValue_60ce0 {
  public:
    int pad;
};
class CStageCondition_60d30;
class ParamValue_60d30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60d30 : public ParamValue_60d30 {
  public:
    int pad;
};
struct CAxisArcCondition_60d70;
class CStageCondition_60d80 {};
class ParamValue_60d80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_60d80 : public ParamValue_60d80 {
  public:
    virtual void f();
};
class CStageCondition_60e10;
class ParamValue_60e10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60e10 : public ParamValue_60e10 {
  public:
    int pad;
};
class CStageCondition_60e60;
class ParamValue_60e60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60e60 : public ParamValue_60e60 {
  public:
    int pad;
};
class CStageCondition_60eb0;
class ParamValue_60eb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60eb0 : public ParamValue_60eb0 {
  public:
    int pad;
};
class CStageCondition_60f00;
class ParamValue_60f00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60f00 : public ParamValue_60f00 {
  public:
    int pad;
};
class CStageCondition_60f50;
class ParamValue_60f50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_60f50 : public ParamValue_60f50 {
  public:
    int pad;
};
void __cdecl SetTimeBegin_000604d0();
void __cdecl SetSlot_000604e0();
void __cdecl SetSlotMax_000604f0();
} // namespace fn_fb6e447b
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fb6e447b {
class CEffectStopTrack_610c0;
struct FloatBase_610c0 { virtual void slot0(); char pad[12]; void (*callback)(); char tail[4];  };
struct IntBase_610c0 { virtual void slot0(); char pad[12]; void (*callback)(); char tail[4]; void FUN_002348e0(const char*); };
} // namespace fn_fb6e447b
namespace fight {
template<class T> struct ParamFloatConstRange_610c0 : FloatBase_610c0 { virtual void slot0(); };
}
namespace fight {
template<class T> struct ParamIntConstRange_610c0 : IntBase_610c0 { virtual void slot0(); };
}
namespace fn_fb6e447b {
extern "C" void __cdecl FUN_002347b0(void*, void**, int);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};


// 0x000604d0 FUN_000604d0 (12 B): matches/0x000604d0.cpp
// sym: ?SetTimeBegin_000604d0@T_604d0@fn_fb6e447b@@QAEDH@Z
char T_604d0::SetTimeBegin_000604d0(int v) {
    value = v;
    return 1;
}


// 0x000604e0 FUN_000604e0 (12 B): matches/0x000604e0.cpp
// sym: ?SetSlot_000604e0@Obj_604e0@fn_fb6e447b@@QAEDH@Z
char Obj_604e0::SetSlot_000604e0(int a) {
    Value = a;
    return 1;
}


// 0x000604f0 FUN_000604f0 (12 B): matches/0x000604f0.cpp
// sym: ?SetSlotMax_000604f0@Obj_604f0@fn_fb6e447b@@QAEDH@Z
char Obj_604f0::SetSlotMax_000604f0(int v) {
    mVal = v;
    return 1;
}


// 0x00060500 FUN_00060500 (19 B): matches/0x00060500.cpp
// sym: ?FUN_00060500@fn_fb6e447b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00060500() {
    FUN_00234810(((char*)&DAT_004dc600), ((char*)&DAT_004dc604));
}

} // namespace fn_fb6e447b

// 0x00060520 CMotionTrailTrack::vfunc_0 (16 B): matches/0x00060520.cpp
// sym: ?vfunc_0@CMotionTrailTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CMotionTrailTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc600;
    return p[index];
}


// 0x00060530 FUN_00060530 (63 B): matches/0x00060530.cpp [wrapped: conflict: CMotionTrailTrack]
// sym: ?Run@CMotionTrailTrack@fn_00060530@@QAEXXZ
namespace fn_00060530 {
extern "C" char DAT_003faa44[];
class Part_60530 {
  public:
    char pad[8];
    void Init_0027af50();
};
class CMotionTrailTrack {
  public:
    virtual void V();
    char a[0x1c];
    Part_60530 p20;
    char b[8];
    Part_60530 p30;
    char c[0x28];
    Part_60530 p60;
    char d[0x40];
    Part_60530 pa8;
    void Finish_00068c70();
    void Run();
};
void CMotionTrailTrack::Run() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003faa44);
    pa8.Init_0027af50();
    Part_60530* p = &p60;
    int i = 6;
    do {
        p = (Part_60530*)((char*)p - 8);
        p->Init_0027af50();
        --i;
    } while (i != 0);
    p20.Init_0027af50();
    Finish_00068c70();
}
} // namespace fn_00060530


// 0x00060570 CMotionTrailTrack::vfunc_13 (13 B): matches/0x00060570.cpp
// sym: ?vfunc_13@CMotionTrailTrack@@UAEXPAX@Z
void CMotionTrailTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffbf00bf;
}


// 0x00060580 CMotionTrailTrack::vfunc_6 (4 B): matches/0x00060580.cpp
// sym: ?vfunc_6@CMotionTrailTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CMotionTrailTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00060590 CMotionTrailTrack::vfunc_7 (24 B): matches/0x00060590.cpp
// sym: ?vfunc_7@CMotionTrailTrack@@UAEMXZ
// data: gZero_60590 = DAT_003f32e0
hulk_freg CMotionTrailTrack::vfunc_7() {
    if (this->f_c8)
        return this->f_10 - this->f_0c;
    return DAT_003f32e0;
}


// 0x000605b0 CMotionTrailTrack::vfunc_12 (40 B): matches/0x000605b0.cpp
// sym: ?vfunc_12@CMotionTrailTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CMotionTrailTrack::vfunc_12(hulk_intptr param) {
    Helper_605b0* p = (Helper_605b0*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001f640(this, param);
    return 0;
}

namespace fn_fb6e447b {

// 0x000605e0 CGrappleMotionTrailTrack::vfunc_11 (16 B): matches/0x000605e0.cpp
// sym: _FUN_000605e0@4
// Same code shape as 0x0008db20 (propagated; names are from that function)
extern "C" int __stdcall FUN_000605e0(int x) {
    return FUN_0005a3f0(x);
}

} // namespace fn_fb6e447b

// 0x000605f0 CGrappleMotionTrailTrack::vfunc_12 (60 B): matches/0x000605f0.cpp
// sym: ?vfunc_12@CGrappleMotionTrailTrack@@UAEHH@Z
hulk_intptr CGrappleMotionTrailTrack::vfunc_12(hulk_intptr arg) {
    CGrappleMotionTrailTrack* self = this;
    Alloc_605f0* p = (Alloc_605f0*)FUN_0008d690(0x28);
    if (p) {
        int v = FUN_0005a430(arg)->value;
        return p->invoke_0001f640(self, v);
    }
    return 0;
}

namespace fn_fb6e447b {

// 0x00060630 FUN_00060630 (19 B): matches/0x00060630.cpp
// sym: ?FUN_00060630@fn_fb6e447b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00060630() {
    FUN_00234810(((char*)&DAT_004dc608), ((char*)&DAT_004dc60c));
}

} // namespace fn_fb6e447b

// 0x00060650 CEffectTrack::vfunc_0 (16 B): matches/0x00060650.cpp
// sym: ?vfunc_0@CEffectTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CEffectTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc608;
    return p[index];
}


// 0x00060660 FUN_00060660 (148 B): equivalent/0x00060660.cpp [wrapped: conflict: CEffectTrack]
// sym: ?FUN_00060660@CEffectTrack@fn_00060660@@QAEPAV12@XZ @7979fe47b4b4 @w0fe71ea0d1ad
namespace fn_00060660 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060660 @ 0x00060660


struct CEffectTrack_60660 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_60660 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};

class CEffectTrack {
public:
    virtual hulk_intptr vfunc_0_00060650(int);
    int f04;
    int f08;
    int f0c;
    float f10;
    char pad14[4];
    Name8_60660 n18;
    int f20, f24;
    Name8_60660 n28, n30;
    int f38, f3c, f40, f44, f48, f4c;
    char b50, b51;
    char pad52[2];
    int f54;
    float f58;

    CEffectTrack() {}
    CEffectTrack *FUN_00060660();
};

CEffectTrack *CEffectTrack::FUN_00060660()
{
    ((CEffectTrack_60660 *)this)->FUN_00236d40();
    new (this) CEffectTrack;
    f0c = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    n28.FUN_0027af00();
    n30.FUN_0027af00();
    b50 = 0;
    b51 = 0;
    f54 = 0;
    f58 = 1.0f;
    f08 = 1;
    n18.FUN_0027b040("");
    n30.FUN_0027b040("");
    n28.FUN_0027b040("");
    f40 = 0;
    f3c = 0;
    f38 = 0;
    f4c = 0;
    f48 = 0;
    f44 = 0;
    return this;
}
} // namespace fn_00060660


// 0x00060700 CEffectTrack::vfunc_11 (13 B): matches/0x00060700.cpp
// sym: ?vfunc_11@CEffectTrack@@UAEXPAX@Z
// Same code shape as 0x00060570 (propagated; names are from that function)
void CEffectTrack::vfunc_11(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffbf00bf;
}


// 0x00060710 CEffectTrack::vfunc_6 (4 B): matches/0x00060710.cpp
// sym: ?vfunc_6@CEffectTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CEffectTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00060720 FUN_00060720 (41 B): matches/0x00060720.cpp [wrapped: conflict: CEffectTrack]
// sym: ?FUN_00060720@fn_00060720@@YIXPAUCEffectTrack@1@@Z
namespace fn_00060720 {
extern "C" char DAT_003faa80[];
typedef unsigned int u32_60720;
struct Helper_60720 {
    void Init_0027af50();
};
struct CEffectTrack {
    hulk_uintptr vft;
    char pad[0x30 - 4];
    void Finish_00236d60();
};
void __fastcall FUN_00060720(CEffectTrack* self) {
    self->vft = ((hulk_intptr)DAT_003faa80);
    ((Helper_60720*)((char*)self + 0x30))->Init_0027af50();
    ((Helper_60720*)((char*)self + 0x28))->Init_0027af50();
    ((Helper_60720*)((char*)self + 0x18))->Init_0027af50();
    self->Finish_00236d60();
}
} // namespace fn_00060720


// 0x00060750 CEffectTrack::vfunc_7 (21 B): matches/0x00060750.cpp
// sym: ?vfunc_7@CEffectTrack@@UAEMXZ
// data: zeroValue_60750 = DAT_003f32e0
hulk_freg CEffectTrack::vfunc_7() {
    if (this->f_50)
        return this->f_10 - this->f_0c;
    return (*(float*)&DAT_003f32e0);
}

namespace fn_fb6e447b {

// 0x00060770 FUN_00060770 (96 B): equivalent/0x00060770.cpp
// sym: ?FUN_00060770@Object@fn_fb6e447b@@QAEXPAUAngles@2@@Z @6c499787af27 @w34b6842f3428
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060770 @ 0x00060770
void Object::FUN_00060770(Angles *out) { Angles source = angles; out->x = source.x * (*(float*)&DAT_003f3ef4); out->y = source.y * (*(float*)&DAT_003f3ef4); out->z = source.z * (*(float*)&DAT_003f3ef4); }


// 0x000607d0 FUN_000607d0 (62 B): matches/0x000607d0.cpp
// sym: ?SetAngles@Obj@fn_fb6e447b@@QAEEPBUVec@2@@Z
unsigned char Obj::SetAngles(const Vec* v) {
    x = v->x;
    y = v->y;
    z = v->z;
    _ReadWriteBarrier();
    x *= 0.017453292f;
    y *= 0.017453292f;
    z *= 0.017453292f;
    return 1;
}

} // namespace fn_fb6e447b

// 0x00060810 CEffectTrack::vfunc_10 (45 B): matches/0x00060810.cpp
// sym: ?vfunc_10@CEffectTrack@@UAEHHHH@Z
hulk_intptr CEffectTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* p = Get_0008d690(0x2c);
    if (p)
        return ((Helper_60810*)p)->Run_0001f6c0(this, c, a);
    return 0;
}


// 0x00060840 CGrappleEffectTrack::vfunc_8 (16 B): equivalent/0x00060840.cpp
// sym: ?vfunc_8@CGrappleEffectTrack@@UAEPAXPAX0@Z @5e7e5e474090 @w36f8b99ce836
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// CGrappleEffectTrack::vfunc_8 @ 0x00060840
void* CGrappleEffectTrack::vfunc_8(void* __p0, void* __p1) { hulk_intptr unused = (hulk_intptr)__p0; hulk_intptr value = (hulk_intptr)__p1;

    return (void*)(FUN_0005a3f0(value));
}


// 0x00060850 CGrappleEffectTrack::vfunc_10 (65 B): matches/0x00060850.cpp
// sym: ?vfunc_10@CGrappleEffectTrack@@UAEHHHH@Z
hulk_intptr CGrappleEffectTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* p = Alloc_0008d690(0x2c);
    if (p) {
        Thing_60850* q = GetThing_0005a430(c);
        int value = q->value;
        return ((Obj_60850*)p)->run_0001f6c0(this, value, a);
    }
    return 0;
}

namespace fn_fb6e447b {

// 0x000608a0 FUN_000608a0 (19 B): matches/0x000608a0.cpp
// sym: ?FUN_000608a0@fn_fb6e447b@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000608a0() {
    FUN_00234810(((char*)&DAT_004dc610), ((char*)&DAT_004dc614));
}

} // namespace fn_fb6e447b

// 0x000608c0 CEffectStopTrack::vfunc_0 (16 B): matches/0x000608c0.cpp
// sym: ?vfunc_0@CEffectStopTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CEffectStopTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc610;
    return p[index];
}

namespace fn_fb6e447b {

// 0x000608d0 FUN_000608d0 (40 B): matches/0x000608d0.cpp
// sym: ??0CEffectStopTrack_608d0@fn_fb6e447b@@QAE@XZ
CEffectStopTrack_608d0::CEffectStopTrack_608d0() : CTrack_608d0() {
    mC = 0;
    m10 = 0;
    m14 = -1;
    m8 = 1;
}

} // namespace fn_fb6e447b

// 0x00060900 CEffectStopTrack::vfunc_13 (13 B): matches/0x00060900.cpp
// sym: ?vfunc_13@CEffectStopTrack@@UAEXPAX@Z
// Same code shape as 0x00060570 (propagated; names are from that function)
void CEffectStopTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffbf00bf;
}


// 0x00060910 CEffectStopTrack::vfunc_6 (4 B): matches/0x00060910.cpp
// sym: ?vfunc_6@CEffectStopTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CEffectStopTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00060920 FUN_00060920 (11 B): matches/0x00060920.cpp [wrapped: conflict: CEffectStopTrack]
// sym: ?FUN_00060920@fn_00060920@@YIXPAVCEffectStopTrack@1@@Z
namespace fn_00060920 {
extern int hulk_at_003faab4;
class CEffectStopTrack {
  public:
};
extern "C" void __fastcall FUN_00068c70(CEffectStopTrack*);
void __fastcall FUN_00060920(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&hulk_at_003faab4;
    FUN_00068c70(self);
}
} // namespace fn_00060920


// 0x00060930 CEffectStopTrack::vfunc_7 (7 B): matches/0x00060930.cpp
// sym: ?vfunc_7@CEffectStopTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CEffectStopTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00060940 CEffectStopTrack::vfunc_12 (40 B): matches/0x00060940.cpp
// sym: ?vfunc_12@CEffectStopTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CEffectStopTrack::vfunc_12(hulk_intptr param) {
    R_60940* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001f780(this, param);
    return 0;
}

namespace fn_fb6e447b {

// 0x00060970 CGrappleEffectStopTrack::vfunc_11 (16 B): matches/0x00060970.cpp
// sym: _FUN_00060970@4
// Same code shape as 0x0008db20 (propagated; names are from that function)
extern "C" int __stdcall FUN_00060970(int x) {
    return FUN_0005a3f0(x);
}

} // namespace fn_fb6e447b

// 0x00060a00 FUN_00060a00 (239 B): equivalent/0x00060a00.cpp [wrapped: conflict: CMotionTrailTrack]
// sym: ?FUN_00060a00@CMotionTrailTrack@fn_00060a00@@QAEPAV12@XZ @ec643aea3425 @wbc45ea44ca4b
namespace fn_00060a00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00060a00 @ 0x00060a00


struct CEffectTrack_60a00 {
    char data[12];
    void FUN_00236d40();
};

struct Name8_60a00 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};

struct Trio_60a00 {
    int a, b, c;
};

class CMotionTrailTrack {
public:
    virtual hulk_intptr vfunc_0_00060520(int);
    char pad04[4];
    int f08;
    int f0c;
    float f10;
    int f14;
    int f18;
    char pad1c[4];
    Name8_60a00 n20;
    int f28;
    char pad2c[4];
    Name8_60a00 names[6];
    Trio_60a00 trios[6];
    Name8_60a00 nA8;
    int fB0, fB4, fB8, fBC, fC0, fC4;
    char bC8, bC9;
    char padCA[2];
    int fCC;

    CMotionTrailTrack() {}
    CMotionTrailTrack *FUN_00060a00();
};

CMotionTrailTrack *CMotionTrailTrack::FUN_00060a00()
{
    ((CEffectTrack_60a00 *)this)->FUN_00236d40();
    new (this) CMotionTrailTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = 0;
    f18 = 0;
    n20.FUN_0027af00();
    f28 = 0;
    for (int i = 0; i < 6; i++)
        names[i].FUN_0027af00();
    nA8.FUN_0027af00();
    fBC = 0;
    fC0 = 0;
    fC4 = 0;
    bC8 = 0;
    bC9 = 0;
    fCC = 0;
    f08 = 1;
    for (int i = 0; i < 6; i++) {
        names[i].FUN_0027b040("");
        trios[i].c = 0;
        trios[i].b = 0;
        trios[i].a = 0;
    }
    nA8.FUN_0027b040("");
    fB8 = 0;
    fB4 = 0;
    fB0 = 0;
    return this;
}
} // namespace fn_00060a00


// 0x00060af0 CMotionTrailTrack::vfunc_5 (30 B): matches/0x00060af0.cpp
// sym: ??_GCMotionTrailTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CMotionTrailTrack::~CMotionTrailTrack() {}


// 0x00060b10 FUN_00060b10 (38 B): matches/0x00060b10.cpp
// sym: ?FUN_00060b10@Obj_60b10@owners@@QAEDH@Z
char owners::Obj_60b10::FUN_00060b10(int n) {
    value = n;
    if (n > 6)
        n = 6;
    value = n;
    if (n <= 2)
        n = 2;
    value = n;
    return 1;
}


// 0x00060b40 CEffectTrack::vfunc_5 (62 B): matches/0x00060b40.cpp [wrapped: conflict: CEffectTrack]
// sym: ?vfunc_5@CEffectTrack@fn_00060b40@@QAEPAU12@E@Z
namespace fn_00060b40 {
extern "C" char DAT_003faa80[];
typedef unsigned char byte_60b40;
struct Part_60b40 {
    void init_0027af50();
};
struct CEffectTrack {
    hulk_ulongptr vf;
    char p4[20];
    Part_60b40 a18;
    char p1c[15];
    Part_60b40 a28;
    char p2c[7];
    Part_60b40 a30;
    CEffectTrack* vfunc_5(byte_60b40);
    void helper_00236d60();
};
extern void cleanup_0008d330(CEffectTrack*);
CEffectTrack* CEffectTrack::vfunc_5(byte_60b40 flags) {
    vf = ((hulk_intptr)DAT_003faa80);
    a30.init_0027af50();
    a28.init_0027af50();
    a18.init_0027af50();
    helper_00236d60();
    if (flags & 1)
        cleanup_0008d330(this);
    return this;
}
} // namespace fn_00060b40


// 0x00060b80 CEffectStopTrack::vfunc_5 (36 B): matches/0x00060b80.cpp [wrapped: conflict: CEffectStopTrack; CTrack]
// sym: ?vfunc_5@CEffectStopTrack@fn_00060b80@@QAEPAV12@C@Z
namespace fn_00060b80 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CTrack_vftable[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CEffectStopTrack : public CTrack {
  public:
    CEffectStopTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CEffectStopTrack* CEffectStopTrack::vfunc_5(signed char flags) {
    *(void***)this = (void**)DAT_003faab4;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00060b80


// 0x00060bd0 fight::ParamFloatConstRange<CMotionTrailTrack>::vfunc_6 (26 B): matches/0x00060bd0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMotionTrailTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMotionTrailTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMotionTrailTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMotionTrailTrack>::**)(int))&this->f_10))(b);
}


// 0x00060bf0 fight::ParamFloatConstRange<CMotionTrailTrack>::vfunc_2 (11 B): matches/0x00060bf0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMotionTrailTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060c20 fight::ParamIntConstRange<CMotionTrailTrack>::vfunc_6 (26 B): matches/0x00060c20.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CMotionTrailTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CMotionTrailTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CMotionTrailTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CMotionTrailTrack>::**)(int))&this->f_10))(b);
}


// 0x00060c40 fight::ParamIntConstRange<CMotionTrailTrack>::vfunc_2 (11 B): matches/0x00060c40.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CMotionTrailTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060c70 fight::ParamVector<CMotionTrailTrack>::vfunc_6 (26 B): matches/0x00060c70.cpp
// sym: ?vfunc_6@?$ParamVector@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CMotionTrailTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CMotionTrailTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CMotionTrailTrack>*)a)->*(*(bool (fight::ParamVector<CMotionTrailTrack>::**)(int))&this->f_10))(b);
}


// 0x00060c90 fight::ParamVector<CMotionTrailTrack>::vfunc_2 (11 B): matches/0x00060c90.cpp
// sym: ?vfunc_2@?$ParamVector@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CMotionTrailTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060cc0 fight::ParamBool<CMotionTrailTrack>::vfunc_6 (26 B): matches/0x00060cc0.cpp
// sym: ?vfunc_6@?$ParamBool@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CMotionTrailTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CMotionTrailTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CMotionTrailTrack>*)a)->*(*(bool (fight::ParamBool<CMotionTrailTrack>::**)(int))&this->f_10))(b);
}


// 0x00060ce0 fight::ParamBool<CMotionTrailTrack>::vfunc_2 (11 B): matches/0x00060ce0.cpp
// sym: ?vfunc_2@?$ParamBool@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CMotionTrailTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060d10 fight::ParamFloatConstRange<CEffectTrack>::vfunc_6 (26 B): matches/0x00060d10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CEffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CEffectTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CEffectTrack>::**)(int))&this->f_10))(b);
}


// 0x00060d30 fight::ParamFloatConstRange<CEffectTrack>::vfunc_2 (11 B): matches/0x00060d30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CEffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060d70 fight::ParamEnumConstList<CEffectTrack>::vfunc_7 (6 B): matches/0x00060d70.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCEffectTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CEffectTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00060d80 fight::ParamEnumConstList<CEffectTrack>::vfunc_6 (30 B): matches/0x00060d80.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCEffectTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CEffectTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_60d80 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_60d80*)&DAT_003f335c));
}


// 0x00060da0 fight::ParamEnumConstList<CEffectTrack>::vfunc_8 (26 B): matches/0x00060da0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCEffectTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CEffectTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CEffectTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CEffectTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CEffectTrack>::**)(int))&this->f_18))(b);
}


// 0x00060dc0 fight::ParamEnumConstList<CEffectTrack>::vfunc_2 (11 B): matches/0x00060dc0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCEffectTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CEffectTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00060df0 fight::ParamVector<CEffectTrack>::vfunc_6 (26 B): matches/0x00060df0.cpp
// sym: ?vfunc_6@?$ParamVector@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CEffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CEffectTrack>*)a)->*(*(bool (fight::ParamVector<CEffectTrack>::**)(int))&this->f_10))(b);
}


// 0x00060e10 fight::ParamVector<CEffectTrack>::vfunc_2 (11 B): matches/0x00060e10.cpp
// sym: ?vfunc_2@?$ParamVector@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CEffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060e40 fight::ParamBool<CEffectTrack>::vfunc_6 (26 B): matches/0x00060e40.cpp
// sym: ?vfunc_6@?$ParamBool@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CEffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CEffectTrack>*)a)->*(*(bool (fight::ParamBool<CEffectTrack>::**)(int))&this->f_10))(b);
}


// 0x00060e60 fight::ParamBool<CEffectTrack>::vfunc_2 (11 B): matches/0x00060e60.cpp
// sym: ?vfunc_2@?$ParamBool@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CEffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060e90 fight::ParamIntConstRange<CEffectTrack>::vfunc_6 (26 B): matches/0x00060e90.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CEffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CEffectTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CEffectTrack>::**)(int))&this->f_10))(b);
}


// 0x00060eb0 fight::ParamIntConstRange<CEffectTrack>::vfunc_2 (11 B): matches/0x00060eb0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CEffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060ee0 fight::ParamFloatConstRange<CEffectStopTrack>::vfunc_6 (26 B): matches/0x00060ee0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CEffectStopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CEffectStopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CEffectStopTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CEffectStopTrack>::**)(int))&this->f_10))(b);
}


// 0x00060f00 fight::ParamFloatConstRange<CEffectStopTrack>::vfunc_2 (11 B): matches/0x00060f00.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CEffectStopTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060f30 fight::ParamIntConstRange<CEffectStopTrack>::vfunc_6 (26 B): matches/0x00060f30.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CEffectStopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CEffectStopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CEffectStopTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CEffectStopTrack>::**)(int))&this->f_10))(b);
}


// 0x00060f50 fight::ParamIntConstRange<CEffectStopTrack>::vfunc_2 (11 B): matches/0x00060f50.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CEffectStopTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00060f60 fight::ParamFloatConstRange<CMotionTrailTrack>::vfunc_0 (30 B): matches/0x00060f60.cpp
// sym: ??_G?$ParamFloatConstRange@VCMotionTrailTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CMotionTrailTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CMotionTrailTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x60f60)
#endif


// 0x00060f80 fight::ParamIntConstRange<CMotionTrailTrack>::vfunc_0 (30 B): matches/0x00060f80.cpp
// sym: ??_G?$ParamIntConstRange@VCMotionTrailTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CMotionTrailTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CMotionTrailTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x60f80)
#endif


// 0x00060fa0 fight::ParamVector<CMotionTrailTrack>::vfunc_0 (30 B): matches/0x00060fa0.cpp
// sym: ??_G?$ParamVector@VCMotionTrailTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CMotionTrailTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CMotionTrailTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x60fa0)
#endif


// 0x00060fc0 fight::ParamBool<CMotionTrailTrack>::vfunc_0 (30 B): matches/0x00060fc0.cpp
// sym: ??_G?$ParamBool@VCMotionTrailTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CMotionTrailTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CMotionTrailTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x60fc0)
#endif


// 0x00060fe0 fight::ParamFloatConstRange<CEffectTrack>::vfunc_0 (30 B): matches/0x00060fe0.cpp
// sym: ??_G?$ParamFloatConstRange@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CEffectTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x60fe0)
#endif


// 0x00061000 fight::ParamEnumConstList<CEffectTrack>::vfunc_0 (30 B): matches/0x00061000.cpp
// sym: ??_G?$ParamEnumConstList@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CEffectTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61000)
#endif


// 0x00061020 fight::ParamVector<CEffectTrack>::vfunc_0 (30 B): matches/0x00061020.cpp
// sym: ??_G?$ParamVector@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CEffectTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61020)
#endif


// 0x00061040 fight::ParamBool<CEffectTrack>::vfunc_0 (30 B): matches/0x00061040.cpp
// sym: ??_G?$ParamBool@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CEffectTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61040)
#endif


// 0x00061060 fight::ParamIntConstRange<CEffectTrack>::vfunc_0 (30 B): matches/0x00061060.cpp
// sym: ??_G?$ParamIntConstRange@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CEffectTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61060)
#endif


// 0x00061080 fight::ParamFloatConstRange<CEffectStopTrack>::vfunc_0 (30 B): matches/0x00061080.cpp
// sym: ??_G?$ParamFloatConstRange@VCEffectStopTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CEffectStopTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CEffectStopTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61080)
#endif


// 0x000610a0 fight::ParamIntConstRange<CEffectStopTrack>::vfunc_0 (30 B): matches/0x000610a0.cpp
// sym: ??_G?$ParamIntConstRange@VCEffectStopTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CEffectStopTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CEffectStopTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x610a0)
#endif

namespace fn_fb6e447b {

// 0x000610c0 FUN_000610c0 (213 B): equivalent/0x000610c0.cpp
// sym: _FUN_000610c0 @d529af485e94 @w90b4ee62fbfb
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_000610c0 @ 0x000610c0
extern "C" void __cdecl FUN_000610c0() {
 if (!DAT_004dc614) {
  void* items[3];
  void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_610c0<CEffectStopTrack_610c0>));
  if(p) { ((fight::ParamValueFloat *)(FloatBase_610c0 *)(((FloatBase_610c0*)p)))->FUN_00234960("timeBegin"); fight::ParamFloatConstRange_610c0<CEffectStopTrack_610c0>* obj = new(p) fight::ParamFloatConstRange_610c0<CEffectStopTrack_610c0>; obj->callback=SetTimeBegin_000604d0; }
  items[0]=p;
  p=FUN_0008d690((int)sizeof(fight::ParamIntConstRange_610c0<CEffectStopTrack_610c0>));
  if(p) { ((IntBase_610c0*)p)->FUN_002348e0("slot"); fight::ParamIntConstRange_610c0<CEffectStopTrack_610c0>* obj = new(p) fight::ParamIntConstRange_610c0<CEffectStopTrack_610c0>; obj->callback=SetSlot_000604e0; }
  items[1]=p;
  p=FUN_0008d690((int)sizeof(fight::ParamIntConstRange_610c0<CEffectStopTrack_610c0>));
  if(p) { ((IntBase_610c0*)p)->FUN_002348e0("slotMax"); fight::ParamIntConstRange_610c0<CEffectStopTrack_610c0>* obj = new(p) fight::ParamIntConstRange_610c0<CEffectStopTrack_610c0>; obj->callback=SetSlotMax_000604f0; }
  items[2]=p;
  FUN_002347b0(&DAT_004dc610,items,3);
 }
 ++DAT_004dc614;
}


// 0x000611c0 fight::ParamName<CMotionTrailTrack>::vfunc_7 (12 B): matches/0x000611c0.cpp
// sym: ?vfunc_6@ParamBranch@fn_fb6e447b@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fb6e447b

// 0x000611f0 fight::ParamNameConstList<CMotionTrailTrack>::vfunc_7 (12 B): matches/0x000611f0.cpp [wrapped: same definition as 0x000611c0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000611f0@@UAEXPAX@Z
namespace fn_000611f0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_000611f0


// 0x00061220 fight::ParamName<CEffectTrack>::vfunc_7 (12 B): matches/0x00061220.cpp [wrapped: same definition as 0x000611c0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00061220@@UAEXPAX@Z
namespace fn_00061220 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00061220


// 0x00061250 fight::ParamNameConstList<CEffectTrack>::vfunc_7 (12 B): matches/0x00061250.cpp [wrapped: same definition as 0x000611c0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00061250@@UAEXPAX@Z
namespace fn_00061250 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00061250


// 0x00061260 fight::ParamName<CMotionTrailTrack>::vfunc_0 (30 B): matches/0x00061260.cpp
// sym: ??_G?$ParamName@VCMotionTrailTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CMotionTrailTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CMotionTrailTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61260)
#endif


// 0x00061280 fight::ParamNameConstList<CMotionTrailTrack>::vfunc_0 (30 B): matches/0x00061280.cpp
// sym: ??_G?$ParamNameConstList@VCMotionTrailTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CMotionTrailTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CMotionTrailTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x61280)
#endif


// 0x000612a0 fight::ParamName<CEffectTrack>::vfunc_0 (30 B): matches/0x000612a0.cpp
// sym: ??_G?$ParamName@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CEffectTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x612a0)
#endif


// 0x000612c0 fight::ParamNameConstList<CEffectTrack>::vfunc_0 (30 B): matches/0x000612c0.cpp
// sym: ??_G?$ParamNameConstList@VCEffectTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CEffectTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CEffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x612c0)
#endif

