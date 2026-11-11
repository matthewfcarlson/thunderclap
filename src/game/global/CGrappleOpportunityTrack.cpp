// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f63372f2 {
#define TREE_TU_END }
namespace fn_f63372f2 {} using namespace fn_f63372f2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f63372f2 {
struct A_5a740 {
};
struct B_5a740 {
    void* second_00059a30();
};
struct Data_5a740 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
extern int* hulk_at_004dc590;
class CCondition_5a820 {
  public:
    virtual int vfunc_0(int);
};
class Track_5a830 {
  public:
    virtual void A();
    virtual void B();
    Track_5a830();
};
class CTrack_5a830 : public Track_5a830 {
  public:
    virtual void A();
    virtual void B();
    CTrack_5a830();
};
struct Param_5a900 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_5a900 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct A_5a910 {
};
struct B_5a910 {
    void* second_00059a30();
};
struct Data_5a910 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
extern int* hulk_at_004dc598;
class CCondition_5a9f0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_003f9944[];
struct S_5aaa0 {
    int a;
    void Fini_0027af50();
};
class CTrack_5aaa0 {
  public:
    void* vptr;
    void Fin_00068c70();
};
class CGrappleAttachTrack_5aaa0 : public CTrack_5aaa0 {
  public:
    char pad0[0x10 - 4];
    S_5aaa0 s10;
    char pad[4];
    S_5aaa0 s18;
    char pad2[0x40 - 0x1c];
    S_5aaa0 s40;
    ~CGrappleAttachTrack_5aaa0();
};
class R_5aad0 {
  public:
    int invoke_0001dcd0(CGrappleAttachTrack*, hulk_intptr);
};
extern R_5aad0* FUN_0008d690(int);
extern int* hulk_at_004dc5a0;
class CCondition_5ab20 {
  public:
    virtual int vfunc_0(int);
};
class CTrack_5ab30 {
  public:
    CTrack_5ab30();
    virtual void V();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class CGrappleSwapTrack_5ab30 : public CTrack_5ab30 {
  public:
    CGrappleSwapTrack_5ab30();
    int a;
    Part p;
    Part q;
    volatile char flag;
    char pad2[3];
    volatile int b, c, d, e;
    int f, g;
    virtual void V();
};
extern "C" char DAT_003f9980[];
class Helper_5abb0 {
  public:
    void Init_0027af50();
    void Finish_00068c70();
};
extern int* hulk_at_004dc5a8;
class CCondition_5ac30 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc5b0;
class CCondition_5acf0 {
  public:
    virtual int vfunc_0(int);
};
extern float hulk_at_003f3388;
extern void* hulk_at_003f99f8[];
struct S1_5ad80 {
    void Fin_00236fd0();
};
struct S2_5ad80 {
    void Fin_00234150();
};
class Track_5ad80 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class CGrappleOpportunityTrack_5ad80 : public Track_5ad80 {
  public:
    char pad0[0x14];
    S2_5ad80 s2;
    char pad[0x28 - 0x19];
    S1_5ad80 s1;
    void f();
};
struct Obj_5adb0 {
    char pad[0x330];
    int* p330;
    int* p334;
};
struct Context_5adb0 {
    Obj_5adb0* second_00059a30();
};
extern int* hulk_at_004dc5b8;
class CCondition_5af20 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_003f9a2c[];
class A_5af80 {
  public:
    void InitA_00236fd0();
};
class B_5af80 {
  public:
    void InitB_00234150();
};
class CGrappleOpportunityTrack_5af80 {
  public:
    void Finish_00236d60();
};
struct Obj_5afb0 {
    char pad[0x330];
    int* p330;
    int* p334;
};
struct Context_5afb0 {
    Obj_5afb0* second_00059a30();
};
extern int* hulk_at_004dc5c0;
class CCondition_5b0d0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_5b160 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_5b160 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Table_5b1a0;
struct FightParamsView_5b1a0 {
};
struct Skeleton_5b1a0 {
    int FUN_0027b200(int a, int b);
};
struct Binding_5b1a0 {
    Skeleton_5b1a0 *FUN_002226b0();
};
struct Table_5b1a0 {
    Binding_5b1a0 *FUN_00059a40();
};
class CGrabAction_5b1a0;
void *FUN_0008d690(unsigned int size);
class CGrabAction_5b1a0 {
public:
    CGrabAction_5b1a0 *FUN_0001de50(hulk_intptr a1, void *track, CFightParams *params, int index);
};
struct A_5b230 {
};
struct B_5b230 {
    void* second_00059a30();
};
struct Data_5b230 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct Weapon;
struct Fighter_5b280 {
    char pad0[0x104];
    Weapon *weapon;
};
struct Body_5b280 {
    char pad0[0x330];
    Fighter_5b280 *primary;
    Fighter_5b280 *secondary;
};
struct Link2_5b280 {
    Body_5b280 *FUN_00059a30();
};
struct Link1_5b280 {
};
struct CInvincibleAction_5b280 {
    void *FUN_0001f4e0(Weapon *weapon, int value);
};
struct A_5b300 {
};
struct B_5b300 {
    void* second_00059a30();
};
struct Data_5b300 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct Fighter_5b350 {
    char pad0[0x104];
    Weapon *weapon;
};
struct Body_5b350 {
    char pad0[0x330];
    Fighter_5b350 *primary;
    Fighter_5b350 *secondary;
};
struct Link2_5b350 {
    Body_5b350 *FUN_00059a30();
};
struct Link1_5b350 {
};
struct CUninterruptibleAction_5b350 {
    void *FUN_00020020(Weapon *weapon, int value);
};
struct A_5b3d0 {
};
struct B_5b3d0 {
    void* second_00059a30();
};
struct Data_5b3d0 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct Fighter_5b420 {
    char pad0[0x104];
    Weapon *weapon;
};
struct Body_5b420 {
    char pad0[0x330];
    Fighter_5b420 *primary;
    Fighter_5b420 *secondary;
};
struct Link2_5b420 {
    Body_5b420 *FUN_00059a30();
};
struct Link1_5b420 {
};
struct CInvulnerableAction_5b420 {
    void *FUN_000200a0(Weapon *weapon, int value);
};
struct A_5b4a0 {
};
struct B_5b4a0 {
    void* second_00059a30();
};
struct Data_5b4a0 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct A_5b560 {
};
struct B_5b560 {
    void* second_00059a30();
};
struct Data_5b560 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct A_5b620 {
};
struct B_5b620 {
    void* second_00059a30();
};
struct Data_5b620 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
extern "C" char hulk_at_003f9a8c[];
struct ThisCall_00234960 {
};
class ParamFloatConstRange_5b900 {
  public:
    void* vptr;
    char pad[12];
    void* m10;
    ParamFloatConstRange_5b900(void* a, void* b);
};
class CStageCondition_5b940;
class ParamValue_5b940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5b940 : public ParamValue_5b940 {
  public:
    int pad;
};
class CStageCondition_5b990;
class ParamValue_5b990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5b990 : public ParamValue_5b990 {
  public:
    int pad;
};
class CStageCondition_5b9e0;
class ParamValue_5b9e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5b9e0 : public ParamValue_5b9e0 {
  public:
    int pad;
};
extern int hulk_at_003f9af0;
class ParamValueBool_5b9f0 {
  public:
    virtual void V();
    ParamValueBool_5b9f0(int);
};
class ParamBool_5b9f0 : public ParamValueBool_5b9f0 {
  public:
    ParamBool_5b9f0(int a, int b);
    char pad[0xc];
    int m10;
};
class CStageCondition_5ba30;
class ParamValue_5ba30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5ba30 : public ParamValue_5ba30 {
  public:
    int pad;
};
class CStageCondition_5ba80;
class ParamValue_5ba80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5ba80 : public ParamValue_5ba80 {
  public:
    int pad;
};
class ParamValueInt_5ba90 {
  public:
    ParamValueInt_5ba90(int a);
    virtual void V0();
    char pad[0xc];
};
class ParamIntConstRange_5ba90 : public ParamValueInt_5ba90 {
  public:
    ParamIntConstRange_5ba90(int a, int b);
    virtual void V0();
    int m10;
};
class CStageCondition_5bad0;
class ParamValue_5bad0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bad0 : public ParamValue_5bad0 {
  public:
    int pad;
};
class CStageCondition_5bb20;
class ParamValue_5bb20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bb20 : public ParamValue_5bb20 {
  public:
    int pad;
};
class CStageCondition_5bb70;
class ParamValue_5bb70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bb70 : public ParamValue_5bb70 {
  public:
    int pad;
};
class CStageCondition_5bbc0;
class ParamValue_5bbc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bbc0 : public ParamValue_5bbc0 {
  public:
    int pad;
};
class CStageCondition_5bc10;
class ParamValue_5bc10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bc10 : public ParamValue_5bc10 {
  public:
    int pad;
};
class CStageCondition_5bc60;
class ParamValue_5bc60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bc60 : public ParamValue_5bc60 {
  public:
    int pad;
};
class CStageCondition_5bcb0;
class ParamValue_5bcb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bcb0 : public ParamValue_5bcb0 {
  public:
    int pad;
};
class ParamValueBranch_5bcc0 {
  public:
    virtual void f();
    ParamValueBranch_5bcc0(int);
};
class ParamBranch_5bcc0 : public ParamValueBranch_5bcc0 {
  public:
    ParamBranch_5bcc0(int, int);
    virtual void f();
    char pad[12];
    int value;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class ParamValueInt_5bcf0 {
  public:
    virtual ~ParamValueInt_5bcf0();
    ParamValueInt_5bcf0(int a);
};
class ParamIntConstRange_5bcf0 : public ParamValueInt_5bcf0 {
  public:
    char pad[12];
    int mVal;
    ParamIntConstRange_5bcf0(int a, int b);
};
class CStageCondition_5bd30;
class ParamValue_5bd30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bd30 : public ParamValue_5bd30 {
  public:
    int pad;
};
class ParamValue_5bd60 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class CStageCondition_5bdf0;
class ParamValue_5bdf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bdf0 : public ParamValue_5bdf0 {
  public:
    int pad;
};
class CStageCondition_5be70;
class ParamValue_5be70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5be70 : public ParamValue_5be70 {
  public:
    int pad;
};
class CStageCondition_5bec0;
class ParamValue_5bec0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bec0 : public ParamValue_5bec0 {
  public:
    int pad;
};
class CStageCondition_5bf10;
class ParamValue_5bf10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bf10 : public ParamValue_5bf10 {
  public:
    int pad;
};
class CStageCondition_5bf60;
class ParamValue_5bf60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5bf60 : public ParamValue_5bf60 {
  public:
    int pad;
};

} // namespace fn_f63372f2

// 0x0005a740 CGrappleAutoTargetTrack::vfunc_11 (70 B): matches/0x0005a740.cpp
// sym: ?vfunc_11@CGrappleAutoTargetTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleAutoTargetTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5a740*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5a740*)a)->second_00059a30();
            if (b) {
                Data_5a740* d = (Data_5a740*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}

namespace fn_f63372f2 {

// 0x0005a800 FUN_0005a800 (19 B): matches/0x0005a800.cpp
// sym: ?FUN_0005a800@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005a800() {
    FUN_00234810(((char*)&DAT_004dc590), ((char*)&DAT_004dc594));
}

} // namespace fn_f63372f2

// 0x0005a820 CGrappleLocoStrafe4Track::vfunc_0 (16 B): matches/0x0005a820.cpp
// sym: ?vfunc_0@CGrappleLocoStrafe4Track@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleLocoStrafe4Track::vfunc_0(int index) {
    int* p = hulk_at_004dc590;
    return p[index];
}

namespace fn_f63372f2 {

// 0x0005a830 FUN_0005a830 (18 B): matches/0x0005a830.cpp
// sym: ??0CTrack_5a830@fn_f63372f2@@QAE@XZ
CTrack_5a830::CTrack_5a830() {}

} // namespace fn_f63372f2

// 0x0005a850 CTrack::vfunc_5 (30 B): matches/0x0005a850.cpp
// sym: ??_GCTrack@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CTrack::~CTrack() {}


// 0x0005a870 FUN_0005a870 (105 B): matches/0x0005a870.cpp [wrapped: conflict: CGrappleLocoStrafe4Track]
// sym: ??1CGrappleLocoStrafe4Track@fn_0005a870@@UAE@XZ
namespace fn_0005a870 {
struct Elem_5a870 {
    ~Elem_5a870() throw();
    int a[2];
};
class CTrack_5a870 {
  public:
    CTrack_5a870();
    virtual ~CTrack_5a870() throw();
    int pad[5];
};
class CGrappleLocoStrafe4Track : public CTrack_5a870 {
  public:
    virtual ~CGrappleLocoStrafe4Track() throw();
    Elem_5a870 e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
};
CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() throw() {}
} // namespace fn_0005a870


// 0x0005a8e0 CGrappleLocoStrafe4Track::vfunc_13 (13 B): matches/0x0005a8e0.cpp
// sym: ?vfunc_13@CGrappleLocoStrafe4Track@@UAEXPAX@Z
void CGrappleLocoStrafe4Track::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff7f0000;
}


// 0x0005a8f0 CGrappleLocoStrafe4Track::vfunc_6 (4 B): matches/0x0005a8f0.cpp
// sym: ?vfunc_6@CGrappleLocoStrafe4Track@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CGrappleLocoStrafe4Track::vfunc_6() {
    return this->f_0c;
}


// 0x0005a900 CGrappleLocoStrafe4Track::vfunc_7 (7 B): matches/0x0005a900.cpp
// sym: ?vfunc_7@CGrappleLocoStrafe4Track@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CGrappleLocoStrafe4Track::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0005a910 CGrappleLocoStrafe4Track::vfunc_11 (70 B): matches/0x0005a910.cpp
// sym: ?vfunc_11@CGrappleLocoStrafe4Track@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleLocoStrafe4Track::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5a910*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5a910*)a)->second_00059a30();
            if (b) {
                Data_5a910* d = (Data_5a910*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}

namespace fn_f63372f2 {

// 0x0005a9d0 FUN_0005a9d0 (19 B): matches/0x0005a9d0.cpp
// sym: ?FUN_0005a9d0@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005a9d0() {
    FUN_00234810(((char*)&DAT_004dc598), ((char*)&DAT_004dc59c));
}

} // namespace fn_f63372f2

// 0x0005a9f0 CGrappleAttachTrack::vfunc_0 (16 B): matches/0x0005a9f0.cpp
// sym: ?vfunc_0@CGrappleAttachTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleAttachTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc598;
    return p[index];
}


// 0x0005aa00 FUN_0005aa00 (102 B): equivalent/0x0005aa00.cpp [wrapped: conflict: CGrappleAttachTrack]
// sym: ??0CGrappleAttachTrack@fn_0005aa00@@QAE@XZ @62e6e7b3972e @w863d70cbf9d4
namespace fn_0005aa00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0005aa00 @ 0x0005aa00
struct Sub8_5aa00 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) CTrack_5aa00 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_5aa00() { FUN_00236d40(); }
};

class CGrappleAttachTrack : public CTrack_5aa00 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5_0005aa80();
    virtual void vfunc_6_0005aa90();
    virtual void vfunc_7();

    int f0c;
    Sub8_5aa00 s10;
    Sub8_5aa00 s18;
    char f20;
    char pad21[3];
    int f24, f28, f2c, f30, f34, f38, f3c;
    Sub8_5aa00 s40;
    int f48, f4c, f50, f54, f58;
    char f5c;
    char pad5d[3];
    int f60;
    int f64;

    CGrappleAttachTrack();
};

CGrappleAttachTrack::CGrappleAttachTrack() {
    f0c = 0;
    s10.FUN_0027af00();
    s18.FUN_0027af00();
    f20 = 1;
    f24 = 0; f28 = 0; f2c = 0; f30 = 0; f34 = 0; f38 = 0; f3c = 0;
    s40.FUN_0027af00();
    f48 = 0; f4c = 0; f50 = 0; f54 = 0; f58 = 0;
    f5c = 0;
    f64 = 0;
    f60 = -10;
}
} // namespace fn_0005aa00


// 0x0005aa70 CGrappleAttachTrack::vfunc_13 (13 B): matches/0x0005aa70.cpp
// sym: ?vfunc_13@CGrappleAttachTrack@@UAEXPAX@Z
void CGrappleAttachTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0005aa80 CGrappleAttachTrack::vfunc_6 (4 B): matches/0x0005aa80.cpp
// sym: ?vfunc_6@CGrappleAttachTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CGrappleAttachTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005aa90 CGrappleAttachTrack::vfunc_7 (7 B): matches/0x0005aa90.cpp
// sym: ?vfunc_7@CGrappleAttachTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CGrappleAttachTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f63372f2 {

// 0x0005aaa0 FUN_0005aaa0 (41 B): matches/0x0005aaa0.cpp
// sym: ??1CGrappleAttachTrack_5aaa0@fn_f63372f2@@QAE@XZ
CGrappleAttachTrack_5aaa0::~CGrappleAttachTrack_5aaa0() {
    vptr = hulk_at_003f9944;
    s40.Fini_0027af50();
    s18.Fini_0027af50();
    s10.Fini_0027af50();
    Fin_00068c70();
}

} // namespace fn_f63372f2

// 0x0005aad0 CGrappleAttachTrack::vfunc_12 (40 B): matches/0x0005aad0.cpp
// sym: ?vfunc_12@CGrappleAttachTrack@@UAEHH@Z
hulk_intptr CGrappleAttachTrack::vfunc_12(hulk_intptr param) {
    R_5aad0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001dcd0(this, param);
    return 0;
}

namespace fn_f63372f2 {

// 0x0005ab00 FUN_0005ab00 (19 B): matches/0x0005ab00.cpp
// sym: ?FUN_0005ab00@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005ab00() {
    FUN_00234810(((char*)&DAT_004dc5a0), ((char*)&DAT_004dc5a4));
}

} // namespace fn_f63372f2

// 0x0005ab20 CGrappleSwapTrack::vfunc_0 (16 B): matches/0x0005ab20.cpp
// sym: ?vfunc_0@CGrappleSwapTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleSwapTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5a0;
    return p[index];
}

namespace fn_f63372f2 {

// 0x0005ab30 FUN_0005ab30 (67 B): matches/0x0005ab30.cpp
// sym: ??0CGrappleSwapTrack_5ab30@fn_f63372f2@@QAE@XZ
CGrappleSwapTrack_5ab30::CGrappleSwapTrack_5ab30() : a(0), flag(1), b(0), c(0), d(0), e(0), f(-10), g(0) {}

} // namespace fn_f63372f2

// 0x0005ab80 CGrappleSwapTrack::vfunc_13 (13 B): matches/0x0005ab80.cpp
// sym: ?vfunc_13@CGrappleSwapTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CGrappleSwapTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0005ab90 CGrappleSwapTrack::vfunc_6 (4 B): matches/0x0005ab90.cpp
// sym: ?vfunc_6@CGrappleSwapTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CGrappleSwapTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005aba0 CGrappleSwapTrack::vfunc_7 (7 B): matches/0x0005aba0.cpp
// sym: ?vfunc_7@CGrappleSwapTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CGrappleSwapTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0005abb0 FUN_0005abb0 (33 B): matches/0x0005abb0.cpp
// sym: ?FUN_0005abb0@CGrappleSwapTrack@@QAEXXZ
void CGrappleSwapTrack::FUN_0005abb0() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f9980);
    ((Helper_5abb0*)((char*)this + 0x18))->Init_0027af50();
    ((Helper_5abb0*)((char*)this + 0x10))->Init_0027af50();
    ((Helper_5abb0*)this)->Finish_00068c70();
}

namespace fn_f63372f2 {

// 0x0005ac10 FUN_0005ac10 (19 B): matches/0x0005ac10.cpp
// sym: ?FUN_0005ac10@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005ac10() {
    FUN_00234810(((char*)&DAT_004dc5a8), ((char*)&DAT_004dc5ac));
}

} // namespace fn_f63372f2

// 0x0005ac30 CGrappleDetachTrack::vfunc_0 (16 B): matches/0x0005ac30.cpp
// sym: ?vfunc_0@CGrappleDetachTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleDetachTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5a8;
    return p[index];
}


// 0x0005ac40 FUN_0005ac40 (26 B): matches/0x0005ac40.cpp [wrapped: conflict: CGrappleDetachTrack]
// sym: ??0CGrappleDetachTrack@fn_0005ac40@@QAE@XZ
namespace fn_0005ac40 {
class CTrack_5ac40 {
  public:
    virtual ~CTrack_5ac40();
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    CTrack_5ac40();
    char pad[8];
};
class CGrappleDetachTrack : public CTrack_5ac40 {
  public:
    virtual ~CGrappleDetachTrack();
    int m0xc;
    int m0x10;
    CGrappleDetachTrack();
};
CGrappleDetachTrack::CGrappleDetachTrack() {
    m0xc = 0;
    m0x10 = 0;
}
} // namespace fn_0005ac40


// 0x0005ac60 CGrappleDetachTrack::vfunc_13 (13 B): matches/0x0005ac60.cpp
// sym: ?vfunc_13@CGrappleDetachTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CGrappleDetachTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0005ac70 CGrappleDetachTrack::vfunc_6 (4 B): matches/0x0005ac70.cpp
// sym: ?vfunc_6@CGrappleDetachTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CGrappleDetachTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005ac80 CGrappleDetachTrack::vfunc_7 (7 B): matches/0x0005ac80.cpp
// sym: ?vfunc_7@CGrappleDetachTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CGrappleDetachTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f63372f2 {

// 0x0005acd0 FUN_0005acd0 (19 B): matches/0x0005acd0.cpp
// sym: ?FUN_0005acd0@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005acd0() {
    FUN_00234810(((char*)&DAT_004dc5b0), ((char*)&DAT_004dc5b4));
}

} // namespace fn_f63372f2

// 0x0005acf0 CGrappleOpportunityTrack::vfunc_0 (16 B): matches/0x0005acf0.cpp
// sym: ?vfunc_0@CGrappleOpportunityTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleOpportunityTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5b0;
    return p[index];
}


// 0x0005ad00 FUN_0005ad00 (66 B): matches/0x0005ad00.cpp [wrapped: conflict: CGrappleOpportunityTrack]
// sym: ??0CGrappleOpportunityTrack@fn_0005ad00@@QAE@XZ
namespace fn_0005ad00 {
class Track_5ad00 {
  public:
    virtual void B0();
    Track_5ad00();
};

class Sub1_5ad00 {
  public:
    void Init_00233dd0();
    char m[0xc];
};

class Sub2_5ad00 {
  public:
    void Init_00236e00();
    char m[0x100];
};

class CGrappleOpportunityTrack : public Track_5ad00 {
  public:
    virtual void Fn();
    char pad4[4];
    int m8;
    int m0c;
    float m10;
    float m14;
    Sub1_5ad00 s1;
    int m24;
    Sub2_5ad00 s2;
    CGrappleOpportunityTrack();
};

CGrappleOpportunityTrack::CGrappleOpportunityTrack() {
    m0c = 0;
    m10 = -1.0f;
    m14 = -1.0f;
    s1.Init_00233dd0();
    m24 = 0;
    s2.Init_00236e00();
    m8 = 1;
}
} // namespace fn_0005ad00


// 0x0005ad50 CGrappleOpportunityTrack::vfunc_6 (4 B): matches/0x0005ad50.cpp
// sym: ?vfunc_6@CGrappleOpportunityTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CGrappleOpportunityTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005ad60 CGrappleOpportunityTrack::vfunc_11 (13 B): matches/0x0005ad60.cpp
// sym: ?vfunc_11@CGrappleOpportunityTrack@@UAEXPAX@Z
void CGrappleOpportunityTrack::vfunc_11(void* __p0) { unsigned long * out = (unsigned long *)__p0;

    *out = 0xff00ff00UL;
}


// 0x0005ad70 CGrappleOpportunityTrack::vfunc_7 (7 B): matches/0x0005ad70.cpp
// sym: ?vfunc_7@CGrappleOpportunityTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CGrappleOpportunityTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_f63372f2 {

// 0x0005ad80 FUN_0005ad80 (33 B): matches/0x0005ad80.cpp
// sym: ?f@CGrappleOpportunityTrack_5ad80@fn_f63372f2@@QAEXXZ
void CGrappleOpportunityTrack_5ad80::f() {
    vptr = hulk_at_003f99f8;
    s1.Fin_00236fd0();
    s2.Fin_00234150();
    Fin_00236d60();
}

} // namespace fn_f63372f2

// 0x0005adb0 CGrappleOpportunityTrack::vfunc_8 (70 B): matches/0x0005adb0.cpp
// sym: ?vfunc_8@CGrappleOpportunityTrack@@UAEPAXPAX0@Z
void* CGrappleOpportunityTrack::vfunc_8(void* __p0, void* __p1) { void * p = (void *)__p1;

    if (!p)
        return (void*)(0);
    Obj_5adb0* a = ((Obj_5adb0 *)((owners::Object_592a0 *)(((Context_5adb0*)p)))->FUN_000592a0());
    if (!a)
        return (void*)(0);
    Obj_5adb0* b = ((Context_5adb0*)a)->second_00059a30();
    if (!b)
        return (void*)(0);
    if (b->p334)
        return (void*)((int*)((char*)b->p334 + 0xdc));
    if (b->p330)
        return (void*)((int*)((char*)b->p330 + 0xdc));
    return (void*)(0);
}


// 0x0005ae00 CGrappleOpportunityTrack::vfunc_10 (247 B): equivalent/0x0005ae00.cpp [wrapped: conflict: CGrappleOpportunityTrack; FUN_0008d690]
// sym: ?vfunc_10@CGrappleOpportunityTrack@fn_0005ae00@@UAEIIIPAUOwner_5ae00@2@@Z @8bfb299ed83c @w1f285531c9cc
namespace fn_0005ae00 {
// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 17/18, incomplete)
// CGrappleOpportunityTrack::vfunc_10 @ 0x0005ae00
struct Context { char pad[8]; unsigned value; };
struct Owner_5ae00;
struct Link_5ae00 { char pad[16]; unsigned* data; };
struct State_5ae00 { char pad[0x330]; Link_5ae00* fallback; Link_5ae00* primary; };
struct Intermediate_5ae00 { State_5ae00* FUN_00059a30(); };
struct Owner_5ae00 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual Context* s4(); Intermediate_5ae00* FUN_000592a0(); };
struct CGrappleOpportunityTrack;
struct OpportunityAction_5ae00 { unsigned FUN_00237470(unsigned,CGrappleOpportunityTrack*,float,float,unsigned,unsigned,void*,unsigned,Context*); };
OpportunityAction_5ae00* __cdecl FUN_0008d690(unsigned);
struct CGrappleOpportunityTrack {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual unsigned vfunc_8(unsigned,Owner_5ae00*); virtual void vfunc_9(); virtual unsigned vfunc_10(unsigned,unsigned,Owner_5ae00*); virtual void vfunc_11();
 char pad[8]; float start; float first; float second; unsigned field18; char pad1c[8]; unsigned field24; char payload[4];
};
unsigned CGrappleOpportunityTrack::vfunc_10(unsigned a,unsigned b,Owner_5ae00* owner) {
 if (!owner) return 0;
 Intermediate_5ae00* i=owner->FUN_000592a0(); if(!i) return 0;
 State_5ae00* state=i->FUN_00059a30(); if(!state) return 0;
 Link_5ae00* link=state->primary; if(!link) link=state->fallback; if(!link) return 0;
 float d1=first-start; float d2=second-start;
 if(d2<0.0f && second>=0.0f) d2=0.0f;
 Context* context=owner->s4(); context->value=*link->data;
 OpportunityAction_5ae00* result=FUN_0008d690(0x50); if(!result) return 0;
 unsigned saved=field18;
 unsigned v=vfunc_8(b,owner);
 return result->FUN_00237470(a,this,d1,d2,saved,field24,payload,v,context);
}
} // namespace fn_0005ae00

namespace fn_f63372f2 {

// 0x0005af00 FUN_0005af00 (19 B): matches/0x0005af00.cpp
// sym: ?FUN_0005af00@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005af00() {
    FUN_00234810(((char*)&DAT_004dc5b8), ((char*)&DAT_004dc5bc));
}

} // namespace fn_f63372f2

// 0x0005af20 CGrappleSequenceTrack::vfunc_0 (16 B): matches/0x0005af20.cpp
// sym: ?vfunc_0@CGrappleSequenceTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleSequenceTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5b8;
    return p[index];
}


// 0x0005af30 FUN_0005af30 (48 B): matches/0x0005af30.cpp [wrapped: conflict: CGrappleSequenceTrack]
// sym: ??0CGrappleSequenceTrack@fn_0005af30@@QAE@XZ
namespace fn_0005af30 {
class Track_5af30 {
  public:
    Track_5af30();
    virtual void f0();
};
class SubC_5af30 {
  public:
    SubC_5af30();

  private:
    char pad[12];
};
class Sub1C {
  public:
    Sub1C();
};
class CGrappleSequenceTrack : public Track_5af30 {
  public:
    CGrappleSequenceTrack();
    virtual void g0();

  private:
    char pad[4];
    int m8;
    SubC_5af30 mC;
    int m18;
    Sub1C m1C;
};
CGrappleSequenceTrack::CGrappleSequenceTrack() : Track_5af30(), mC(), m18(1), m1C() {
    m8 = 1;
}
} // namespace fn_0005af30


// 0x0005af60 CGrappleSequenceTrack::vfunc_6 (7 B): matches/0x0005af60.cpp
// sym: ?vfunc_6@CGrappleSequenceTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CGrappleSequenceTrack::vfunc_6() {
    return DAT_003f32e0;
}


// 0x0005af70 CGrappleSequenceTrack::vfunc_7 (7 B): matches/0x0005af70.cpp
// sym: ?vfunc_7@CGrappleSequenceTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CGrappleSequenceTrack::vfunc_7() {
    return hulk_at_003f3388;
}


// 0x0005af80 FUN_0005af80 (33 B): matches/0x0005af80.cpp
// sym: ?FUN_0005af80@CGrappleSequenceTrack@@QAEXXZ
void CGrappleSequenceTrack::FUN_0005af80() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f9a2c);
    ((A_5af80*)((char*)this + 0x1c))->InitA_00236fd0();
    ((B_5af80*)((char*)this + 0x0c))->InitB_00234150();
    ((CGrappleOpportunityTrack_5af80*)this)->Finish_00236d60();
}


// 0x0005afb0 CGrappleSequenceTrack::vfunc_8 (70 B): matches/0x0005afb0.cpp
// sym: ?vfunc_8@CGrappleSequenceTrack@@UAEPAXPAX0@Z
// Same code shape as 0x0005adb0 (propagated; names are from that function)
void* CGrappleSequenceTrack::vfunc_8(void* __p0, void* __p1) { void * p = (void *)__p1;

    if (!p)
        return (void*)(0);
    Obj_5afb0* a = ((Obj_5afb0 *)((owners::Object_592a0 *)(((Context_5afb0*)p)))->FUN_000592a0());
    if (!a)
        return (void*)(0);
    Obj_5afb0* b = ((Context_5afb0*)a)->second_00059a30();
    if (!b)
        return (void*)(0);
    if (b->p334)
        return (void*)((int*)((char*)b->p334 + 0xdc));
    if (b->p330)
        return (void*)((int*)((char*)b->p330 + 0xdc));
    return (void*)(0);
}


// 0x0005b000 CGrappleSequenceTrack::vfunc_10 (168 B): equivalent/0x0005b000.cpp [wrapped: conflict: CGrappleSequenceTrack]
// sym: ?vfunc_10@CGrappleSequenceTrack@fn_0005b000@@UAEPAUObject@2@IIPAUInput_5b000@2@@Z @cbcd45dcb23d @w25fba6a70843
namespace fn_0005b000 {
// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 13/14, incomplete)
// CGrappleSequenceTrack::vfunc_10 @ 0x0005b000
struct Result_5b000 { char pad[8]; unsigned int value; };
struct Link_5b000 { unsigned int value; };
struct Holder_5b000 { char pad[16]; Link_5b000* link; };
struct Actor_5b000 { char pad[0x330]; Holder_5b000* fallback; Holder_5b000* preferred; };
struct Mid_5b000 { Actor_5b000* FUN_00059a30(); };
struct Input_5b000 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual Result_5b000* s4(); Mid_5b000* FUN_000592a0(); };
struct CGrappleSequenceTrack;
struct Object { Object* FUN_00237c90(unsigned int, CGrappleSequenceTrack*, unsigned int, unsigned int, void*, unsigned int, Result_5b000*); };
extern void* __cdecl FUN_0008d690(unsigned int);
struct CGrappleSequenceTrack {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual unsigned int s8(unsigned int, Input_5b000*); virtual void s9(); virtual Object* vfunc_10(unsigned int, unsigned int, Input_5b000*);
char pad[8]; unsigned int fieldC; char pad10[8]; unsigned int field18; char field1c[4];
};
Object* CGrappleSequenceTrack::vfunc_10(unsigned int a, unsigned int b, Input_5b000* input) {
if (!input) return 0;
Mid_5b000* mid = input->FUN_000592a0(); if (!mid) return 0;
Actor_5b000* actor = mid->FUN_00059a30(); if (!actor) return 0;
Holder_5b000* holder = actor->preferred; if (!holder) holder = actor->fallback; if (!holder) return 0;
Result_5b000* result = input->s4(); result->value = holder->link->value;
Object* obj = (Object*)FUN_0008d690(0x3c); if (!obj) return 0;
unsigned int saved = fieldC;
unsigned int value = s8(b, input);
return obj->FUN_00237c90(a, this, saved, field18, field1c, value, result);
}
} // namespace fn_0005b000

namespace fn_f63372f2 {

// 0x0005b0b0 FUN_0005b0b0 (19 B): matches/0x0005b0b0.cpp
// sym: ?FUN_0005b0b0@fn_f63372f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005b0b0() {
    FUN_00234810(((char*)&DAT_004dc5c0), ((char*)&DAT_004dc5c4));
}

} // namespace fn_f63372f2

// 0x0005b0d0 CGrabTrack::vfunc_0 (16 B): matches/0x0005b0d0.cpp
// sym: ?vfunc_0@CGrabTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrabTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5c0;
    return p[index];
}


// 0x0005b0e0 FUN_0005b0e0 (85 B): matches/0x0005b0e0.cpp [wrapped: conflict: CGrabTrack]
// sym: ??0CGrabTrack@fn_0005b0e0@@QAE@XZ
namespace fn_0005b0e0 {
class Track_5b0e0 {
  public:
    Track_5b0e0();
    virtual void f();
    char pad[8];
};
class A {
  public:
    A();
    char pad[8];
};
class B {
  public:
    B();
    char pad[12];
};
struct Triple {
    int u, v, w;
    Triple() : u(0), v(0), w(0) {}
};
class CGrabTrack : public Track_5b0e0 {
  public:
    CGrabTrack();
    virtual void f();
    int x;
    float y;
    char pad0[4];
    A a;
    Triple triple;
    float z;
    int t;
    char flag;
    char pad1[3];
    B b, c;
};
CGrabTrack::CGrabTrack() : Track_5b0e0(), x(0), y(-1.0f), a(), triple(), z(0.25f), t(0), flag(0), b(), c() {
    *(int*)((char*)this + 8) = 1;
}
} // namespace fn_0005b0e0


// 0x0005b140 CGrabTrack::vfunc_11 (13 B): matches/0x0005b140.cpp
// sym: ?vfunc_11@CGrabTrack@@UAEXPAX@Z
void CGrabTrack::vfunc_11(void* __p0) { int * out = (int *)__p0;

    *out = 0xffffff00;
}


// 0x0005b150 CGrabTrack::vfunc_6 (4 B): matches/0x0005b150.cpp
// sym: ?vfunc_6@CGrabTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CGrabTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005b160 CGrabTrack::vfunc_7 (7 B): matches/0x0005b160.cpp
// sym: ?vfunc_7@CGrabTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CGrabTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0005b170 FUN_0005b170 (41 B): matches/0x0005b170.cpp [wrapped: conflict: CGrabTrack]
// sym: ??1CGrabTrack@fn_0005b170@@QAE@XZ
namespace fn_0005b170 {
class CGrabTrack {
  public:
    virtual void v();
    ~CGrabTrack();
    char pad[0x14];
    char a[0x20];
    char b[0xc];
    char c[4];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern "C" void __fastcall FUN_00234150(void*);
extern "C" void __fastcall FUN_00234150(void*);
void __fastcall FD_00236d60(void*);
CGrabTrack::~CGrabTrack() {
    FUN_00234150((char*)this + 0x44);
    FUN_00234150((char*)this + 0x38);
    FUN_0027af50((char*)this + 0x18);
    FD_00236d60(this);
}
} // namespace fn_0005b170


// 0x0005b1a0 CGrabTrack::vfunc_10 (134 B): equivalent/0x0005b1a0.cpp
// sym: ?vfunc_10@CGrabTrack@@UAEHHHH@Z @014ee7513341 @web37f65bd86b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8; --wine 600 inputs)
// CGrabTrack::vfunc_10 @ 0x0005b1a0
hulk_intptr CGrabTrack::vfunc_10(hulk_intptr a1, hulk_intptr a2, hulk_intptr __p2) { fight::Params * params = (fight::Params *)__p2;

    CFightParams *fp = dynamic_cast<CFightParams *>(params);
    if (fp == 0)
        return (hulk_intptr)(0);
    Table_5b1a0 *table = ((Table_5b1a0 *)((owners::Object_592a0 *)(((FightParamsView_5b1a0 *)fp)))->FUN_000592a0());
    Binding_5b1a0 *binding = table->FUN_00059a40();
    if (binding == 0)
        return (hulk_intptr)(0);
    int arg1_ = this->f_1c;
    int arg2_ = this->f_18;
    int index = binding->FUN_002226b0()->FUN_0027b200(arg2_, arg1_);
    if (index < 0)
        return (hulk_intptr)(0);
    CGrabAction_5b1a0 *mem = (CGrabAction_5b1a0 *)FUN_0008d690(0x40);
    if (mem == 0)
        return (hulk_intptr)(0);
    return (hulk_intptr)(mem->FUN_0001de50(a1, this, fp, index));
}


// 0x0005b230 CGrappleInvincibleTrack::vfunc_11 (70 B): matches/0x0005b230.cpp
// sym: ?vfunc_11@CGrappleInvincibleTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleInvincibleTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b230*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b230*)a)->second_00059a30();
            if (b) {
                Data_5b230* d = (Data_5b230*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005b280 CGrappleInvincibleTrack::vfunc_12 (114 B): equivalent/0x0005b280.cpp
// sym: ?vfunc_12@CGrappleInvincibleTrack@@UAEHH@Z @345a800937bb @we6e64d8e5169
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleInvincibleTrack::vfunc_12 @ 0x0005b280
hulk_intptr CGrappleInvincibleTrack::vfunc_12(hulk_intptr __p0) { Link1_5b280 * owner = (Link1_5b280 *)__p0;

    if (owner == 0)
        return (int)(0);
    Link2_5b280 *l2 = ((Link2_5b280 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    if (l2 == 0)
        return (int)(0);
    Body_5b280 *body = l2->FUN_00059a30();
    if (body == 0)
        return (int)(0);
    Fighter_5b280 *fighter = body->secondary;
    if (fighter == 0) {
        fighter = body->primary;
        if (fighter == 0)
            return (int)(0);
    }
    Weapon *weapon = fighter->weapon;
    if (weapon == 0)
        return (int)(0);
    CInvincibleAction_5b280 *effect = (CInvincibleAction_5b280 *)FUN_0008d690(0x24);
    if (effect == 0)
        return (int)(0);
    return (hulk_intptr)(effect->FUN_0001f4e0(weapon, this->f_14));
}


// 0x0005b300 CGrappleUninterruptibleTrack::vfunc_11 (70 B): matches/0x0005b300.cpp
// sym: ?vfunc_11@CGrappleUninterruptibleTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleUninterruptibleTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b300*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b300*)a)->second_00059a30();
            if (b) {
                Data_5b300* d = (Data_5b300*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005b350 CGrappleUninterruptibleTrack::vfunc_12 (114 B): equivalent/0x0005b350.cpp
// sym: ?vfunc_12@CGrappleUninterruptibleTrack@@UAEHH@Z @2f4610e4972e @w62a3ddc58af7
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleUninterruptibleTrack::vfunc_12 @ 0x0005b350
hulk_intptr CGrappleUninterruptibleTrack::vfunc_12(hulk_intptr __p0) { Link1_5b350 * owner = (Link1_5b350 *)__p0;

    if (owner == 0)
        return (int)(0);
    Link2_5b350 *l2 = ((Link2_5b350 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    if (l2 == 0)
        return (int)(0);
    Body_5b350 *body = l2->FUN_00059a30();
    if (body == 0)
        return (int)(0);
    Fighter_5b350 *fighter = body->secondary;
    if (fighter == 0) {
        fighter = body->primary;
        if (fighter == 0)
            return (int)(0);
    }
    Weapon *weapon = fighter->weapon;
    if (weapon == 0)
        return (int)(0);
    CUninterruptibleAction_5b350 *effect = (CUninterruptibleAction_5b350 *)FUN_0008d690(0x24);
    if (effect == 0)
        return (int)(0);
    return (hulk_intptr)(effect->FUN_00020020(weapon, this->extensionTime));
}


// 0x0005b3d0 CGrappleInvulnerableTrack::vfunc_11 (70 B): matches/0x0005b3d0.cpp
// sym: ?vfunc_11@CGrappleInvulnerableTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleInvulnerableTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b3d0*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b3d0*)a)->second_00059a30();
            if (b) {
                Data_5b3d0* d = (Data_5b3d0*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005b420 CGrappleInvulnerableTrack::vfunc_12 (114 B): equivalent/0x0005b420.cpp
// sym: ?vfunc_12@CGrappleInvulnerableTrack@@UAEHH@Z @8e68a8ba79d8 @w961fdb9db305
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleInvulnerableTrack::vfunc_12 @ 0x0005b420
hulk_intptr CGrappleInvulnerableTrack::vfunc_12(hulk_intptr __p0) { Link1_5b420 * owner = (Link1_5b420 *)__p0;

    if (owner == 0)
        return (int)(0);
    Link2_5b420 *l2 = ((Link2_5b420 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    if (l2 == 0)
        return (int)(0);
    Body_5b420 *body = l2->FUN_00059a30();
    if (body == 0)
        return (int)(0);
    Fighter_5b420 *fighter = body->secondary;
    if (fighter == 0) {
        fighter = body->primary;
        if (fighter == 0)
            return (int)(0);
    }
    Weapon *weapon = fighter->weapon;
    if (weapon == 0)
        return (int)(0);
    CInvulnerableAction_5b420 *effect = (CInvulnerableAction_5b420 *)FUN_0008d690(0x24);
    if (effect == 0)
        return (int)(0);
    return (hulk_intptr)(effect->FUN_000200a0(weapon, this->f_14));
}


// 0x0005b4a0 CGrappleIntangibleTrack::vfunc_11 (70 B): matches/0x0005b4a0.cpp
// sym: ?vfunc_11@CGrappleIntangibleTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleIntangibleTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b4a0*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b4a0*)a)->second_00059a30();
            if (b) {
                Data_5b4a0* d = (Data_5b4a0*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005b560 CGrappleSoundTrack::vfunc_11 (70 B): matches/0x0005b560.cpp
// sym: ?vfunc_11@CGrappleSoundTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleSoundTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b560*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b560*)a)->second_00059a30();
            if (b) {
                Data_5b560* d = (Data_5b560*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005b620 CGrappleSmartPropDropTrack::vfunc_11 (70 B): matches/0x0005b620.cpp
// sym: ?vfunc_11@CGrappleSmartPropDropTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleSmartPropDropTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5b620*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5b620*)a)->second_00059a30();
            if (b) {
                Data_5b620* d = (Data_5b620*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005b6f0 FUN_0005b6f0 (125 B): equivalent/0x0005b6f0.cpp [wrapped: conflict: CGrappleLocoStrafe4Track]
// sym: ?FUN_0005b6f0@CGrappleLocoStrafe4Track@fn_0005b6f0@@QAEPAV12@XZ @1663bdacc4a5 @w1d64a6e42532
inline void *operator new(size_t, void *p) { return p; }
namespace fn_0005b6f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0005b6f0 @ 0x0005b6f0


struct CGrappleOpportunityTrack_5b6f0 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_5b6f0 {
    int lo, hi;
    void FUN_0027af00();
};

class CGrappleLocoStrafe4Track {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    int f10;
    char pad14[4];
    Name8_5b6f0 n18, n20, n28, n30, n38, n40, n48, n50, n58, n60, n68;
    int f70, f74, f78;

    CGrappleLocoStrafe4Track() {}
    CGrappleLocoStrafe4Track *FUN_0005b6f0();
};

CGrappleLocoStrafe4Track *CGrappleLocoStrafe4Track::FUN_0005b6f0()
{
    ((CGrappleOpportunityTrack_5b6f0 *)this)->FUN_00236d40();
    new (this) CGrappleLocoStrafe4Track;
    f0c = 0;
    f10 = 0;
    n18.FUN_0027af00();
    n20.FUN_0027af00();
    n28.FUN_0027af00();
    n30.FUN_0027af00();
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    n48.FUN_0027af00();
    n50.FUN_0027af00();
    n58.FUN_0027af00();
    n60.FUN_0027af00();
    n68.FUN_0027af00();
    f70 = 0;
    f74 = 0;
    f78 = 0;
    return this;
}
} // namespace fn_0005b6f0


// 0x0005b790 CGrappleAttachTrack::vfunc_5 (62 B): matches/0x0005b790.cpp [wrapped: conflict: CGrappleAttachTrack]
// sym: ?vfunc_5@CGrappleAttachTrack@fn_0005b790@@UAEPAV12@E@Z
namespace fn_0005b790 {
extern "C" char DAT_003f9944[];
class CGrappleAttachTrack;
class Helper_5b790 {
  public:
    void Fnf_0027af50();
    void init_00068c70();
};
class CGrappleAttachTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CGrappleAttachTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x3c];
};
extern void FUN_0008d330(CGrappleAttachTrack*);
CGrappleAttachTrack* CGrappleAttachTrack::vfunc_5(unsigned char param) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f9944);
    ((Helper_5b790*)((char*)this + 0x40))->Fnf_0027af50();
    ((Helper_5b790*)((char*)this + 0x18))->Fnf_0027af50();
    ((Helper_5b790*)((char*)this + 0x10))->Fnf_0027af50();
    ((Helper_5b790*)this)->init_00068c70();
    if (param & 1)
        FUN_0008d330(this);
    return this;
}
} // namespace fn_0005b790


// 0x0005b7d0 CGrappleSwapTrack::vfunc_5 (54 B): matches/0x0005b7d0.cpp [wrapped: conflict: CGrappleSwapTrack]
// sym: ?vfunc_5@CGrappleSwapTrack@fn_0005b7d0@@UAEPAV12@E@Z
namespace fn_0005b7d0 {
typedef unsigned char byte_5b7d0;
extern int hulk_at_003f9980;
void __cdecl FreeMem_0008d330(void*);
struct Sub_5b7d0 {
    void Clean_0027af50();
    char pad[8];
};
class CGrappleSwapTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CGrappleSwapTrack* vfunc_5(byte_5b7d0);
    void BaseClean_00068c70();
    char pad[0xc];
    Sub_5b7d0 a;
    Sub_5b7d0 b;
};
CGrappleSwapTrack* CGrappleSwapTrack::vfunc_5(byte_5b7d0 flags) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f9980;
    this->b.Clean_0027af50();
    this->a.Clean_0027af50();
    this->BaseClean_00068c70();
    if (flags & 1)
        FreeMem_0008d330(this);
    return this;
}
} // namespace fn_0005b7d0


// 0x0005b810 CGrappleDetachTrack::vfunc_5 (36 B): matches/0x0005b810.cpp [wrapped: conflict: CGrappleDetachTrack; CTrack]
// sym: ?vfunc_5@CGrappleDetachTrack@fn_0005b810@@QAEPAV12@C@Z
namespace fn_0005b810 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003f99bc[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CGrappleDetachTrack : public CTrack {
  public:
    CGrappleDetachTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CGrappleDetachTrack* CGrappleDetachTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f99bc;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_0005b810


// 0x0005b840 CGrappleOpportunityTrack::vfunc_5 (54 B): matches/0x0005b840.cpp [wrapped: conflict: CGrappleOpportunityTrack]
// sym: ?vfunc_5@CGrappleOpportunityTrack@fn_0005b840@@QAEPAV12@E@Z
void operator delete(void*);
namespace fn_0005b840 {
extern void* g_vftable_5b840[];

struct T1 {
    void Fini_00236fd0();
};
struct T2 {
    void Fini_00234150();
};
class Track_5b840 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class CGrappleOpportunityTrack : public Track_5b840 {
  public:
    char pad4[0x14];
    T2 a18;
    char pad19[0x28 - 0x19];
    T1 a28;
    CGrappleOpportunityTrack* vfunc_5(unsigned char flags);
};
CGrappleOpportunityTrack* CGrappleOpportunityTrack::vfunc_5(unsigned char flags) {
    vptr = g_vftable_5b840;
    a28.Fini_00236fd0();
    a18.Fini_00234150();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0005b840


// 0x0005b880 CGrappleSequenceTrack::vfunc_5 (54 B): matches/0x0005b880.cpp [wrapped: conflict: CGrappleSequenceTrack]
// sym: ?vfunc_5@CGrappleSequenceTrack@fn_0005b880@@UAEPAV12@E@Z
namespace fn_0005b880 {
extern "C" char DAT_003f9a2c[];
class CGrappleSequenceTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual CGrappleSequenceTrack* vfunc_5(unsigned char);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad[0x1c - 4];
};
void __fastcall FUN_00236fd0(void*);
extern "C" void __fastcall FUN_00234150(void*);
void __fastcall FUN_00236d60(CGrappleSequenceTrack*);
void __cdecl thunk_FUN_00267090(CGrappleSequenceTrack*);
CGrappleSequenceTrack* CGrappleSequenceTrack::vfunc_5(unsigned char p) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f9a2c);
    FUN_00236fd0((char*)this + 0x1c);
    FUN_00234150((char*)this + 0xc);
    FUN_00236d60(this);
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0005b880


// 0x0005b8c0 CGrabTrack::vfunc_5 (62 B): matches/0x0005b8c0.cpp [wrapped: conflict: CGrabTrack]
// sym: ?vfunc_5@CGrabTrack@fn_0005b8c0@@QAEPAV12@I@Z
namespace fn_0005b8c0 {
extern "C" char DAT_003f9a5c[];
class CGrabTrack {
  public:
    unsigned int* vptr;
    char pad[0x44 - 4];
    CGrabTrack* vfunc_5(unsigned int);
    void FUN_00236d60();
};
class H1 {
  public:
    void FUN_00234150();
};
class H2_5b8c0 {
  public:
    void FUN_0027af50();
};
void thunk_FUN_00267090(CGrabTrack*);
CGrabTrack* CGrabTrack::vfunc_5(unsigned int flag) {
    vptr = (unsigned int*)((hulk_intptr)DAT_003f9a5c);
    ((H1*)((char*)this + 0x44))->FUN_00234150();
    ((H1*)((char*)this + 0x38))->FUN_00234150();
    ((H2_5b8c0*)((char*)this + 0x18))->FUN_0027af50();
    FUN_00236d60();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0005b8c0

namespace fn_f63372f2 {

// 0x0005b900 FUN_0005b900 (32 B): matches/0x0005b900.cpp
// sym: ??0ParamFloatConstRange_5b900@fn_f63372f2@@QAE@PAX0@Z
ParamFloatConstRange_5b900::ParamFloatConstRange_5b900(void* a, void* b) {
    ((fight::ParamValueFloat *)(((ThisCall_00234960*)(this))))->FUN_00234960((const char *)a);
    vptr = (void*)((hulk_intptr)(hulk_at_003f9a8c + 0x4));
    m10 = b;
}

} // namespace fn_f63372f2

// 0x0005b920 fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::vfunc_6 (26 B): matches/0x0005b920.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::**)(int))&this->f_10))(b);
}


// 0x0005b940 fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::vfunc_2 (11 B): matches/0x0005b940.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005b970 fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::vfunc_6 (26 B): matches/0x0005b970.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrappleLocoStrafe4Track>*)a)->*(*(bool (fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::**)(int))&this->f_10))(b);
}


// 0x0005b990 fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::vfunc_2 (11 B): matches/0x0005b990.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005b9c0 fight::ParamFloatConstRange<CGrappleAttachTrack>::vfunc_6 (26 B): matches/0x0005b9c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x0005b9e0 fight::ParamFloatConstRange<CGrappleAttachTrack>::vfunc_2 (11 B): matches/0x0005b9e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f63372f2 {

// 0x0005b9f0 FUN_0005b9f0 (32 B): matches/0x0005b9f0.cpp
// sym: ??0ParamBool_5b9f0@fn_f63372f2@@QAE@HH@Z
ParamBool_5b9f0::ParamBool_5b9f0(int a, int b) : ParamValueBool_5b9f0(a) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f9af0;
    m10 = b;
}

} // namespace fn_f63372f2

// 0x0005ba10 fight::ParamBool<CGrappleAttachTrack>::vfunc_6 (26 B): matches/0x0005ba10.cpp
// sym: ?vfunc_6@?$ParamBool@VCGrappleAttachTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrappleAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamBool<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x0005ba30 fight::ParamBool<CGrappleAttachTrack>::vfunc_2 (11 B): matches/0x0005ba30.cpp
// sym: ?vfunc_2@?$ParamBool@VCGrappleAttachTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrappleAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005ba60 fight::ParamVector<CGrappleAttachTrack>::vfunc_6 (26 B): matches/0x0005ba60.cpp
// sym: ?vfunc_6@?$ParamVector@VCGrappleAttachTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CGrappleAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamVector<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x0005ba80 fight::ParamVector<CGrappleAttachTrack>::vfunc_2 (11 B): matches/0x0005ba80.cpp
// sym: ?vfunc_2@?$ParamVector@VCGrappleAttachTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CGrappleAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f63372f2 {

// 0x0005ba90 FUN_0005ba90 (32 B): matches/0x0005ba90.cpp
// sym: ??0ParamIntConstRange_5ba90@fn_f63372f2@@QAE@HH@Z
ParamIntConstRange_5ba90::ParamIntConstRange_5ba90(int a, int b) : ParamValueInt_5ba90(a), m10(b) {}

} // namespace fn_f63372f2

// 0x0005bab0 fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_6 (26 B): matches/0x0005bab0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bad0 fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_2 (11 B): matches/0x0005bad0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bb00 fight::ParamFloatConstRange<CGrappleSwapTrack>::vfunc_6 (26 B): matches/0x0005bb00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleSwapTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrappleSwapTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrappleSwapTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrappleSwapTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bb20 fight::ParamFloatConstRange<CGrappleSwapTrack>::vfunc_2 (11 B): matches/0x0005bb20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleSwapTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bb50 fight::ParamBool<CGrappleSwapTrack>::vfunc_6 (26 B): matches/0x0005bb50.cpp
// sym: ?vfunc_6@?$ParamBool@VCGrappleAttachTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrappleSwapTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CGrappleSwapTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CGrappleSwapTrack>*)a)->*(*(bool (fight::ParamBool<CGrappleSwapTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bb70 fight::ParamBool<CGrappleSwapTrack>::vfunc_2 (11 B): matches/0x0005bb70.cpp
// sym: ?vfunc_2@?$ParamBool@VCGrappleAttachTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrappleSwapTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bba0 fight::ParamVector<CGrappleSwapTrack>::vfunc_6 (26 B): matches/0x0005bba0.cpp
// sym: ?vfunc_6@?$ParamVector@VCGrappleAttachTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CGrappleSwapTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CGrappleSwapTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CGrappleSwapTrack>*)a)->*(*(bool (fight::ParamVector<CGrappleSwapTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bbc0 fight::ParamVector<CGrappleSwapTrack>::vfunc_2 (11 B): matches/0x0005bbc0.cpp
// sym: ?vfunc_2@?$ParamVector@VCGrappleAttachTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CGrappleSwapTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bbf0 fight::ParamIntConstRange<CGrappleSwapTrack>::vfunc_6 (26 B): matches/0x0005bbf0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleSwapTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrappleSwapTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrappleSwapTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrappleSwapTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bc10 fight::ParamIntConstRange<CGrappleSwapTrack>::vfunc_2 (11 B): matches/0x0005bc10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleSwapTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bc40 fight::ParamFloatConstRange<CGrappleDetachTrack>::vfunc_6 (26 B): matches/0x0005bc40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleDetachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrappleDetachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrappleDetachTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrappleDetachTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bc60 fight::ParamFloatConstRange<CGrappleDetachTrack>::vfunc_2 (11 B): matches/0x0005bc60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleDetachTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bc90 fight::ParamFloatConstRange<CGrappleOpportunityTrack>::vfunc_6 (26 B): matches/0x0005bc90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleOpportunityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrappleOpportunityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrappleOpportunityTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrappleOpportunityTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bcb0 fight::ParamFloatConstRange<CGrappleOpportunityTrack>::vfunc_2 (11 B): matches/0x0005bcb0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleOpportunityTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f63372f2 {

// 0x0005bcc0 FUN_0005bcc0 (32 B): matches/0x0005bcc0.cpp
// sym: ??0ParamBranch_5bcc0@fn_f63372f2@@QAE@HH@Z
ParamBranch_5bcc0::ParamBranch_5bcc0(int a, int b) : ParamValueBranch_5bcc0(a), value(b) {}


// 0x0005bce0 fight::ParamBranch<CGrappleOpportunityTrack>::vfunc_6 (12 B): matches/0x0005bce0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f63372f2@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}


// 0x0005bcf0 FUN_0005bcf0 (32 B): matches/0x0005bcf0.cpp
// sym: ??0ParamIntConstRange_5bcf0@fn_f63372f2@@QAE@HH@Z
ParamIntConstRange_5bcf0::ParamIntConstRange_5bcf0(int a, int b) : ParamValueInt_5bcf0(a) {
    mVal = b;
}

} // namespace fn_f63372f2

// 0x0005bd10 fight::ParamIntConstRange<CGrappleOpportunityTrack>::vfunc_6 (26 B): matches/0x0005bd10.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleOpportunityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrappleOpportunityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrappleOpportunityTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrappleOpportunityTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bd30 fight::ParamIntConstRange<CGrappleOpportunityTrack>::vfunc_2 (11 B): matches/0x0005bd30.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleOpportunityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bd60 fight::ParamValueConditionGroup::vfunc_1 (6 B): matches/0x0005bd60.cpp
// sym: ?vfunc_1@ParamValueConditionGroup@fight@@UAEHXZ
int fight::ParamValueConditionGroup::vfunc_1() {
    return 11;
}


// 0x0005bd70 fight::ParamConditionGroup<CGrappleOpportunityTrack>::vfunc_6 (12 B): matches/0x0005bd70.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005bd70@@UAEXPAX@Z
namespace fn_0005bd70 {
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
} // namespace fn_0005bd70


// 0x0005bda0 fight::ParamBranch<CGrappleSequenceTrack>::vfunc_6 (12 B): matches/0x0005bda0.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005bda0@@UAEXPAX@Z
namespace fn_0005bda0 {
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
} // namespace fn_0005bda0


// 0x0005bdd0 fight::ParamIntConstRange<CGrappleSequenceTrack>::vfunc_6 (26 B): matches/0x0005bdd0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleSequenceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrappleSequenceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrappleSequenceTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrappleSequenceTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bdf0 fight::ParamIntConstRange<CGrappleSequenceTrack>::vfunc_2 (11 B): matches/0x0005bdf0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrappleSequenceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005be20 fight::ParamConditionGroup<CGrappleSequenceTrack>::vfunc_6 (12 B): matches/0x0005be20.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005be20@@UAEXPAX@Z
namespace fn_0005be20 {
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
} // namespace fn_0005be20


// 0x0005be50 fight::ParamFloatConstRange<CGrabTrack>::vfunc_6 (26 B): matches/0x0005be50.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrabTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrabTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrabTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrabTrack>::**)(int))&this->f_10))(b);
}


// 0x0005be70 fight::ParamFloatConstRange<CGrabTrack>::vfunc_2 (11 B): matches/0x0005be70.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrabTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bea0 fight::ParamVector<CGrabTrack>::vfunc_6 (26 B): matches/0x0005bea0.cpp
// sym: ?vfunc_6@?$ParamVector@VCGrappleAttachTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CGrabTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CGrabTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CGrabTrack>*)a)->*(*(bool (fight::ParamVector<CGrabTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bec0 fight::ParamVector<CGrabTrack>::vfunc_2 (11 B): matches/0x0005bec0.cpp
// sym: ?vfunc_2@?$ParamVector@VCGrappleAttachTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CGrabTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bef0 fight::ParamIntConstRange<CGrabTrack>::vfunc_6 (26 B): matches/0x0005bef0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrabTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrabTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrabTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrabTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bf10 fight::ParamIntConstRange<CGrabTrack>::vfunc_2 (11 B): matches/0x0005bf10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CGrabTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bf40 fight::ParamBool<CGrabTrack>::vfunc_6 (26 B): matches/0x0005bf40.cpp
// sym: ?vfunc_6@?$ParamBool@VCGrappleAttachTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrabTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CGrabTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CGrabTrack>*)a)->*(*(bool (fight::ParamBool<CGrabTrack>::**)(int))&this->f_10))(b);
}


// 0x0005bf60 fight::ParamBool<CGrabTrack>::vfunc_2 (11 B): matches/0x0005bf60.cpp
// sym: ?vfunc_2@?$ParamBool@VCGrappleAttachTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrabTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005bf90 fight::ParamBranch<CGrabTrack>::vfunc_6 (12 B): matches/0x0005bf90.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005bf90@@UAEXPAX@Z
namespace fn_0005bf90 {
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
} // namespace fn_0005bf90


// 0x0005bfa0 fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::vfunc_0 (30 B): matches/0x0005bfa0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5bfa0)
#endif


// 0x0005bfc0 fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::vfunc_0 (30 B): matches/0x0005bfc0.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CGrappleLocoStrafe4Track>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5bfc0)
#endif


// 0x0005bfe0 fight::ParamFloatConstRange<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005bfe0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrappleAttachTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrappleAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5bfe0)
#endif


// 0x0005c000 fight::ParamBool<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c000.cpp
// sym: ??_G?$ParamBool@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CGrappleAttachTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CGrappleAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c000)
#endif


// 0x0005c020 fight::ParamVector<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c020.cpp
// sym: ??_G?$ParamVector@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CGrappleAttachTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CGrappleAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c020)
#endif


// 0x0005c040 fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c040.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CGrappleAttachTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CGrappleAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c040)
#endif


// 0x0005c060 fight::ParamFloatConstRange<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c060.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrappleSwapTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrappleSwapTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c060)
#endif


// 0x0005c080 fight::ParamBool<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c080.cpp
// sym: ??_G?$ParamBool@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CGrappleSwapTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CGrappleSwapTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c080)
#endif


// 0x0005c0a0 fight::ParamVector<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c0a0.cpp
// sym: ??_G?$ParamVector@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CGrappleSwapTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CGrappleSwapTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c0a0)
#endif


// 0x0005c0c0 fight::ParamIntConstRange<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c0c0.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CGrappleSwapTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CGrappleSwapTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c0c0)
#endif


// 0x0005c0e0 fight::ParamFloatConstRange<CGrappleDetachTrack>::vfunc_0 (30 B): matches/0x0005c0e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleDetachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrappleDetachTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrappleDetachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c0e0)
#endif


// 0x0005c100 fight::ParamFloatConstRange<CGrappleOpportunityTrack>::vfunc_0 (30 B): matches/0x0005c100.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleOpportunityTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrappleOpportunityTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrappleOpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c100)
#endif


// 0x0005c120 fight::ParamBranch<CGrappleOpportunityTrack>::vfunc_0 (30 B): matches/0x0005c120.cpp
// sym: ??_G?$ParamBranch@VCGrappleOpportunityTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<CGrappleOpportunityTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<CGrappleOpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c120)
#endif


// 0x0005c140 fight::ParamIntConstRange<CGrappleOpportunityTrack>::vfunc_0 (30 B): matches/0x0005c140.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleOpportunityTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CGrappleOpportunityTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CGrappleOpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c140)
#endif


// 0x0005c160 fight::ParamConditionGroup<CGrappleOpportunityTrack>::vfunc_0 (30 B): matches/0x0005c160.cpp
// sym: ??_G?$ParamConditionGroup@VCGrappleOpportunityTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<CGrappleOpportunityTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<CGrappleOpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c160)
#endif


// 0x0005c180 fight::ParamBranch<CGrappleSequenceTrack>::vfunc_0 (30 B): matches/0x0005c180.cpp
// sym: ??_G?$ParamBranch@VCGrappleSequenceTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<CGrappleSequenceTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<CGrappleSequenceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c180)
#endif


// 0x0005c1a0 fight::ParamIntConstRange<CGrappleSequenceTrack>::vfunc_0 (30 B): matches/0x0005c1a0.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleSequenceTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CGrappleSequenceTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CGrappleSequenceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c1a0)
#endif


// 0x0005c1c0 fight::ParamConditionGroup<CGrappleSequenceTrack>::vfunc_0 (30 B): matches/0x0005c1c0.cpp
// sym: ??_G?$ParamConditionGroup@VCGrappleSequenceTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<CGrappleSequenceTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<CGrappleSequenceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c1c0)
#endif


// 0x0005c1e0 fight::ParamFloatConstRange<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c1e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrabTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrabTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrabTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c1e0)
#endif


// 0x0005c200 fight::ParamVector<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c200.cpp
// sym: ??_G?$ParamVector@VCGrabTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CGrabTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CGrabTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c200)
#endif


// 0x0005c220 fight::ParamIntConstRange<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c220.cpp
// sym: ??_G?$ParamIntConstRange@VCGrabTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CGrabTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CGrabTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c220)
#endif


// 0x0005c240 fight::ParamBool<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c240.cpp
// sym: ??_G?$ParamBool@VCGrabTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CGrabTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CGrabTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c240)
#endif


// 0x0005c260 fight::ParamBranch<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c260.cpp
// sym: ??_G?$ParamBranch@VCGrabTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<CGrabTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<CGrabTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c260)
#endif


// 0x0005c490 FUN_0005c490 (213 B): equivalent/0x0005c490.cpp [wrapped: conflict: fight::ParamBranch; fight::ParamConditionGroup; fight::ParamIntConstRange]
// sym: _FUN_0005c490 @0c9100c8edb9 @w0c9fbaef24d1
namespace fn_0005c490 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0005c490 @ 0x0005c490

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0005a330();
void __cdecl FUN_0005a340();
void __cdecl FUN_0005a350();

class CGrappleSequenceTrack;
struct FUN_00235170 {
 FUN_00235170(const char* = "branch");
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
struct FUN_002348e0 {
 FUN_002348e0(const char* = "priority");
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
struct FUN_00235220 {
 FUN_00235220(const char* = "conditionGroup");
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
namespace fight {
 template<class T> struct ParamBranch : FUN_00235170 { virtual void slot0(); };
 template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); };
 template<class T> struct ParamConditionGroup : FUN_00235220 { virtual void slot0(); };
}
extern "C" void __cdecl FUN_002347b0(void**,void**,int);
extern "C" void __cdecl FUN_0005c490() {
 if (!DAT_004dc5bc) {
  void* entries[3];
  void* mem = FUN_0008d690((int)sizeof(fight::ParamBranch<CGrappleSequenceTrack>));
  fight::ParamBranch<CGrappleSequenceTrack>* a = mem ? new(mem) fight::ParamBranch<CGrappleSequenceTrack> : 0;
  if(a) a->callback = FUN_0005a330;
  entries[0]=a;
  mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<CGrappleSequenceTrack>));
  fight::ParamIntConstRange<CGrappleSequenceTrack>* b = mem ? new(mem) fight::ParamIntConstRange<CGrappleSequenceTrack> : 0;
  if(b) b->callback = FUN_0005a340;
  entries[1]=b;
  mem = FUN_0008d690((int)sizeof(fight::ParamConditionGroup<CGrappleSequenceTrack>));
  fight::ParamConditionGroup<CGrappleSequenceTrack>* c = mem ? new(mem) fight::ParamConditionGroup<CGrappleSequenceTrack> : 0;
  if(c) c->callback = FUN_0005a350;
  entries[2]=c;
  FUN_002347b0(((void**)&DAT_004dc5b8),entries,3);
 }
 ++DAT_004dc5bc;
}
} // namespace fn_0005c490


// 0x0005c590 fight::ParamName<CGrappleLocoStrafe4Track>::vfunc_7 (12 B): matches/0x0005c590.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005c590@@UAEXPAX@Z
namespace fn_0005c590 {
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
} // namespace fn_0005c590


// 0x0005c5c0 fight::ParamNameConstList<CGrappleAttachTrack>::vfunc_7 (12 B): matches/0x0005c5c0.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005c5c0@@UAEXPAX@Z
namespace fn_0005c5c0 {
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
} // namespace fn_0005c5c0


// 0x0005c5f0 fight::ParamNameConstList<CGrappleSwapTrack>::vfunc_7 (12 B): matches/0x0005c5f0.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005c5f0@@UAEXPAX@Z
namespace fn_0005c5f0 {
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
} // namespace fn_0005c5f0


// 0x0005c620 fight::ParamNameConstList<CGrabTrack>::vfunc_7 (12 B): matches/0x0005c620.cpp [wrapped: same definition as 0x0005bce0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005c620@@UAEXPAX@Z
namespace fn_0005c620 {
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
} // namespace fn_0005c620


// 0x0005c630 fight::ParamName<CGrappleLocoStrafe4Track>::vfunc_0 (30 B): matches/0x0005c630.cpp
// sym: ??_G?$ParamName@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CGrappleLocoStrafe4Track>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CGrappleLocoStrafe4Track>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c630)
#endif


// 0x0005c650 fight::ParamNameConstList<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c650.cpp
// sym: ??_G?$ParamNameConstList@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CGrappleAttachTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CGrappleAttachTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c650)
#endif


// 0x0005c670 fight::ParamNameConstList<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c670.cpp
// sym: ??_G?$ParamNameConstList@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CGrappleSwapTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CGrappleSwapTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c670)
#endif


// 0x0005c690 fight::ParamNameConstList<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c690.cpp
// sym: ??_G?$ParamNameConstList@VCGrabTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CGrabTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CGrabTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x5c690)
#endif

