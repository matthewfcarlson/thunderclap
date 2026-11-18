// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005d850..0x000604d0 (kind game, layer game, confidence high), merged by D32: global/CCollisionTrack.cpp
// piece 0x0005d850..0x0005fa10 (kind game, layer game, confidence high, dominant class CCollisionTrack)
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/unknown.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd61af26 {
#define TREE_TU_END }
namespace fn_fd61af26 {} using namespace fn_fd61af26;
namespace fn_fd61af26 { extern "C" char DAT_003fa284[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f133b0a3 { struct Point; } 
namespace fn_f133b0a3 { struct Vec3; } 
namespace fn_f133b0a3 { struct Vec3_5d4e0; } 
namespace fn_f133b0a3 { struct Obj { bool Set(struct fn_f133b0a3::Point *); bool Set(struct fn_f133b0a3::Vec3 const *); }; }   // (gx3, D18) setters, as defined in unk_05d370.cpp
namespace fn_f133b0a3 { struct Obj_5d4e0 { char Set(struct fn_f133b0a3::Vec3_5d4e0 const *); }; }   // (gx3, D18) setters, as defined in unk_05d370.cpp

// ---- declarations shared by the functions below
namespace fn_fd61af26 {
const float rad_5d870 = 0.017453292f;
struct S_5d890 {
    int a;
    int b;
    int c;
};
class O_5d890 {
  public:
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    bool Set(const S_5d890* p);
};
class Obj_5d8d0 {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x28];
    int mValue;
    bool Set(int v);
};
extern int* hulk_at_004dc5d0;
class CCondition_5d920 {
  public:
    virtual int vfunc_0(int);
};
struct Param_5da80 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_5da80 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void __cdecl FUN_00267760(void* p, int n, const char* fmt, ...);
extern char DAT_00494b44[];
extern char DAT_00494b60[];
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Index_5daf0 { int FUN_0027b200(unsigned lo, unsigned hi); };
struct Lookup_5daf0 { Index_5daf0* FUN_002226b0(); };
struct Owner_5daf0 { Lookup_5daf0* FUN_00059a40(); };
struct Holder_5daf0 {  };
struct CCollisionAction_5daf0 { CCollisionAction_5daf0* FUN_00019380(void* a, void* self, Holder_5daf0* h, int index); };
extern int* hulk_at_004dc5d8;
class CCondition_5dba0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_003fa248[];
struct S_5dbb0 {
    int a;
    void Fini_0027af50();
};
struct T_5dbb0 {
    int a;
    void Fini_00234150();
};
class CTrack_5dbb0 {
  public:
    void* vptr;
    void Fin_00068c70();
};
class COpportunityBallTrack_5dbb0 : public CTrack_5dbb0 {
  public:
    char pad[0x18 - 4];
    S_5dbb0 s18;
    char pad2[0x34 - 0x1c];
    T_5dbb0 t34;
    char pad3[0x40 - 0x38];
    T_5dbb0 t40;
    ~COpportunityBallTrack_5dbb0();
};
struct Param_5dc00 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_5dc00 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class A_5dc10;
class Arg_5dc10 {
  public:
};
class A_5dc10 {
  public:
    A_5dc10* FnB_00059a40();
    void* FnD_002226b0();
};
class R_5dc10 {
  public:
    unsigned int FnE_0027b200(void*, void*);
};
class Q_5dc10 {
  public:
    int FnF_0001adb0(void*, void*, unsigned int);
};
extern int* hulk_at_004dc5e0;
class CCondition_5dca0 {
  public:
    virtual int vfunc_0(int);
};
extern float hulk_at_003f3388;
extern void* hulk_at_003fa284[];
struct S_5dd40 {
    int a;
    void Fini_0027af50();
};
class CTrack_5dd40 {
  public:
    void* vptr;
    void Fin_00068c70();
};
class CProceduralDurationAnimationTrack_5dd40 : public CTrack_5dd40 {
  public:
    char pad[0x18 - 4];
    S_5dd40 s18;
    char pad2[0x38 - 0x1c];
    S_5dd40 s38;
    ~CProceduralDurationAnimationTrack_5dd40();
};
struct Helper_5dd70 {
    int FUN_0001cfd0(CHitAnimationTrack*, hulk_intptr);
};
struct Helper_5dda0 {
    int FUN_0001d020(CPushBackAnimationTrack*, hulk_intptr);
};
extern int* hulk_at_004dc5e8;
class CCondition_5ddf0 {
  public:
    virtual int vfunc_0(int);
};
struct Helper_5deb0 {
    int FUN_0001d070(CStunAnimationTrack*, hulk_intptr);
};
extern int* hulk_at_004dc5f0;
class CCondition_5df00 {
  public:
    virtual int vfunc_0(int);
};
struct Param_5df70 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_5df70 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Helper_5df90 {
    int FUN_00020c40(CSnapToWallTrack*, hulk_intptr);
};
extern int* hulk_at_004dc5f8;
class CCondition_5dfe0 {
  public:
    virtual int vfunc_0(int);
};
class Helper_5e050 {
  public:
    int go_000215d0(hulk_intptr);
};
class CStageCondition_5e280;
class ParamValue_5e280 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e280 : public ParamValue_5e280 {
  public:
    int pad;
};
class CStageCondition_5e2d0;
class ParamValue_5e2d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e2d0 : public ParamValue_5e2d0 {
  public:
    int pad;
};
class CStageCondition_5e320;
class ParamValue_5e320 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e320 : public ParamValue_5e320 {
  public:
    int pad;
};
class CStageCondition_5e370;
class ParamValue_5e370 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e370 : public ParamValue_5e370 {
  public:
    int pad;
};
struct CAxisArcCondition_5e3b0;
class CStageCondition_5e3c0 {};
class ParamValue_5e3c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_5e3c0 : public ParamValue_5e3c0 {
  public:
    virtual void f();
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_5e480;
class ParamValue_5e480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e480 : public ParamValue_5e480 {
  public:
    int pad;
};
class ParamValue_5e4b0 {
  public:
    char pad[12];
};
class ParamValueBool_5e4b0 : public ParamValue_5e4b0 {};
class CCollisionTrack_5e4b0;
class CStageCondition_5e550;
class ParamValue_5e550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e550 : public ParamValue_5e550 {
  public:
    int pad;
};
class CStageCondition_5e5a0;
class ParamValue_5e5a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e5a0 : public ParamValue_5e5a0 {
  public:
    int pad;
};
class CStageCondition_5e5f0;
class ParamValue_5e5f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e5f0 : public ParamValue_5e5f0 {
  public:
    int pad;
};
class CStageCondition_5e670;
class ParamValue_5e670 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e670 : public ParamValue_5e670 {
  public:
    int pad;
};
struct CAxisArcCondition_5e6b0;
class CStageCondition_5e6c0 {};
class ParamValue_5e6c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_5e6c0 : public ParamValue_5e6c0 {
  public:
    virtual void f();
};
class CStageCondition_5e750;
class ParamValue_5e750 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e750 : public ParamValue_5e750 {
  public:
    int pad;
};
class CStageCondition_5e7a0;
class ParamValue_5e7a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e7a0 : public ParamValue_5e7a0 {
  public:
    int pad;
};
class CStageCondition_5e7f0;
class ParamValue_5e7f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e7f0 : public ParamValue_5e7f0 {
  public:
    int pad;
};
struct CAxisArcCondition_5e830;
class CStageCondition_5e840 {};
class ParamValue_5e840 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_5e840 : public ParamValue_5e840 {
  public:
    virtual void f();
};
class CStageCondition_5e8d0;
class ParamValue_5e8d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e8d0 : public ParamValue_5e8d0 {
  public:
    int pad;
};
class CStageCondition_5e920;
class ParamValue_5e920 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e920 : public ParamValue_5e920 {
  public:
    int pad;
};
class CStageCondition_5e970;
class ParamValue_5e970 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e970 : public ParamValue_5e970 {
  public:
    int pad;
};
class CStageCondition_5e9c0;
class ParamValue_5e9c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e9c0 : public ParamValue_5e9c0 {
  public:
    int pad;
};
class CStageCondition_5ea10;
class ParamValue_5ea10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5ea10 : public ParamValue_5ea10 {
  public:
    int pad;
};
class CStageCondition_5ea60;
class ParamValue_5ea60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5ea60 : public ParamValue_5ea60 {
  public:
    int pad;
};
} // namespace fn_fd61af26
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fd61af26 {
class CSnapToWallTrack_5ed90 {
public:
    void FUN_0005d850();
    void FUN_0005d860();
    void FUN_0005d870();
    void FUN_0005d890();
    void FUN_0005d8b0();
    void FUN_0005d8c0();
    void FUN_0005d8d0();
    void FUN_0005d8e0();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
extern void* hulk_at_003fa758[];
struct Base_5f080 {  };
class ParamName_5f080 {
  public:
    void* vptr;
    char pad[12];
    int m10;
    ParamName_5f080(int a, int b) throw();
};

} // namespace fn_fd61af26

// 0x0005d850 FUN_0005d850 (12 B): matches/0x0005d850.cpp
// sym: ?FUN_0005d850@Obj_5d850@owners@@QAE_NH@Z
bool owners::Obj_5d850::FUN_0005d850(int v) {
    value = v;
    return true;
}


// 0x0005d860 FUN_0005d860 (12 B): matches/0x0005d860.cpp
// sym: ?FUN_0005d860@Obj_5d860@owners@@QAEEI@Z
unsigned char owners::Obj_5d860::FUN_0005d860(unsigned int x) {
    m = x;
    return 1;
}


// 0x0005d870 FUN_0005d870 (18 B): matches/0x0005d870.cpp
// sym: ?FUN_0005d870@Obj_5d870@owners@@QAEDM@Z
char owners::Obj_5d870::FUN_0005d870(float a) {
    mAngle = a * rad_5d870;
    return 1;
}

namespace fn_fd61af26 {

// 0x0005d890 FUN_0005d890 (26 B): matches/0x0005d890.cpp
// sym: ?Set@O_5d890@fn_fd61af26@@QAE_NPBUS_5d890@2@@Z
bool O_5d890::Set(const S_5d890* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return true;
}

} // namespace fn_fd61af26

// 0x0005d8b0 FUN_0005d8b0 (12 B): matches/0x0005d8b0.cpp
// sym: ?FUN_0005d8b0@Obj_5d8b0@owners@@QAEEE@Z
unsigned char owners::Obj_5d8b0::FUN_0005d8b0(unsigned char x) {
    m24 = x;
    return 1;
}


// 0x0005d8c0 FUN_0005d8c0 (12 B): matches/0x0005d8c0.cpp
// sym: ?FUN_0005d8c0@Obj_5d8c0@owners@@QAE_NH@Z
bool owners::Obj_5d8c0::FUN_0005d8c0(int value) {
    *(int*)((char*)this + 0x28) = value;
    return true;
}

namespace fn_fd61af26 {

// 0x0005d8d0 FUN_0005d8d0 (12 B): matches/0x0005d8d0.cpp
// sym: ?Set@Obj_5d8d0@fn_fd61af26@@QAE_NH@Z
bool Obj_5d8d0::Set(int v) {
    mValue = v;
    return true;
}

} // namespace fn_fd61af26

// 0x0005d8e0 FUN_0005d8e0 (12 B): matches/0x0005d8e0.cpp
// sym: ?FUN_0005d8e0@Obj_5d8e0@owners@@QAEDH@Z
char owners::Obj_5d8e0::FUN_0005d8e0(int v) {
    m30 = v;
    return 1;
}


// 0x0005d8f0 FUN_0005d8f0 (12 B): matches/0x0005d8f0.cpp
// sym: ?FUN_0005d8f0@Obj_5d8f0@owners@@QAEDH@Z
char owners::Obj_5d8f0::FUN_0005d8f0(int a) {
    mVal = a;
    return 1;
}

namespace fn_fd61af26 {

// 0x0005d900 FUN_0005d900 (19 B): matches/0x0005d900.cpp
// sym: ?FUN_0005d900@fn_fd61af26@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005d900(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5d0), ((char*)&DAT_004dc5d4));
}

} // namespace fn_fd61af26

// 0x0005d920 CCollisionTrack::vfunc_0 (16 B): matches/0x0005d920.cpp
// sym: ?vfunc_0@CCollisionTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5d0;
    return p[index];
}


// 0x0005da60 CCollisionTrack::vfunc_11 (13 B): matches/0x0005da60.cpp
// sym: ?vfunc_11@CCollisionTrack@@UAEXPAX@Z
// Same code shape as 0x0005b140 (propagated; names are from that function)
void CCollisionTrack::vfunc_11(void* __p0) { int * out = (int *)__p0;

    *out = 0xffffff00;
}


// 0x0005da70 CCollisionTrack::vfunc_6 (4 B): matches/0x0005da70.cpp
// sym: ?vfunc_6@CCollisionTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CCollisionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005da80 CCollisionTrack::vfunc_7 (7 B): matches/0x0005da80.cpp
// sym: ?vfunc_7@CCollisionTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CCollisionTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0005da90 FUN_0005da90 (57 B): matches/0x0005da90.cpp [wrapped: conflict: CCollisionTrack]
// sym: ?Fini@CCollisionTrack@fn_0005da90@@QAEXXZ
namespace fn_0005da90 {
extern "C" char DAT_003fa214[];
class CCollisionTrack_5da90 {
  public:
    void Done_00236d60();
};
class TypeA {
  public:
    void Done_0027af50();
};
class TypeB {
  public:
    void Done_00234150();
};
class CCollisionTrack {
  public:
    virtual void Dummy();
    char pad[0x14];
    char a18[0x34];
    char a4c[0xc];
    char a58[0x10];
    char a68[8];
    char a70[4];
    void Fini();
};
void CCollisionTrack::Fini() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003fa214);
    ((TypeA*)a70)->Done_0027af50();
    ((TypeA*)a68)->Done_0027af50();
    ((TypeB*)a58)->Done_00234150();
    ((TypeB*)a4c)->Done_00234150();
    ((TypeA*)a18)->Done_0027af50();
    ((CCollisionTrack_5da90*)this)->Done_00236d60();
}
} // namespace fn_0005da90


// 0x0005dad0 FUN_0005dad0 (29 B): matches/0x0005dad0.cpp
// sym: ?FUN_0005dad0@C_5dad0@owners@@QAEDH@Z
char owners::C_5dad0::FUN_0005dad0(int x) {
    char r = 1;
    void* q = (char*)this + 0x78;
    FUN_00267760(q, 0x40, "%s", x);
    return r;
}


// 0x0005daf0 CCollisionTrack::vfunc_10 (138 B): equivalent/0x0005daf0.cpp
// sym: ?vfunc_10@CCollisionTrack@@UAEHHHH@Z @315e25010566 @w255c1eb27779 @vb7e3d558168d
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// CCollisionTrack::vfunc_10 @ 0x0005daf0
hulk_intptr CCollisionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * c = (void *)__p2;

    Holder_5daf0* h = (Holder_5daf0*)FUN_00344e74(c, 0, DAT_00494b44, DAT_00494b60, 0);
    Lookup_5daf0* lk = h ? ((Owner_5daf0 *)((owners::Object_592a0 *)h)->FUN_000592a0())->FUN_00059a40() : 0;
    if (!lk) return (int)(0);
    unsigned arg1_ = (*(unsigned int *)&this->f_1c);
    unsigned arg2_ = (*(unsigned int *)&this->f_18);
    int index = lk->FUN_002226b0()->FUN_0027b200(arg2_, arg1_);
    if (index == 0xffff) return (int)(0);
    CCollisionAction_5daf0* item = (CCollisionAction_5daf0*)FUN_0008d690(sizeof(::CCollisionAction));
    if (!item) return (int)(0);
    return (hulk_intptr)(item->FUN_00019380(a, this, h, index));
}

namespace fn_fd61af26 {

// 0x0005db80 FUN_0005db80 (19 B): matches/0x0005db80.cpp
// sym: ?FUN_0005db80@fn_fd61af26@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005db80(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5d8), ((char*)&DAT_004dc5dc));
}

} // namespace fn_fd61af26

// 0x0005dba0 COpportunityBallTrack::vfunc_0 (16 B): matches/0x0005dba0.cpp
// sym: ?vfunc_0@COpportunityBallTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr COpportunityBallTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5d8;
    return p[index];
}

namespace fn_fd61af26 {

// 0x0005dbb0 FUN_0005dbb0 (41 B): matches/0x0005dbb0.cpp
// sym: ??1COpportunityBallTrack_5dbb0@fn_fd61af26@@QAE@XZ
COpportunityBallTrack_5dbb0::~COpportunityBallTrack_5dbb0() {
    vptr = hulk_at_003fa248;
    t40.Fini_00234150();
    t34.Fini_00234150();
    s18.Fini_0027af50();
    Fin_00068c70();
}

} // namespace fn_fd61af26

// 0x0005dbe0 COpportunityBallTrack::vfunc_13 (13 B): matches/0x0005dbe0.cpp
// sym: ?vfunc_13@COpportunityBallTrack@@UAEXPAX@Z
// Same code shape as 0x0005ad60 (propagated; names are from that function)
void COpportunityBallTrack::vfunc_13(void* __p0) { unsigned long * out = (unsigned long *)__p0;

    *out = 0xff00ff00UL;
}


// 0x0005dbf0 COpportunityBallTrack::vfunc_6 (4 B): matches/0x0005dbf0.cpp
// sym: ?vfunc_6@COpportunityBallTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg COpportunityBallTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005dc00 COpportunityBallTrack::vfunc_7 (7 B): matches/0x0005dc00.cpp
// sym: ?vfunc_7@COpportunityBallTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg COpportunityBallTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0005dc10 COpportunityBallTrack::vfunc_12 (102 B): matches/0x0005dc10.cpp
// sym: ?vfunc_12@COpportunityBallTrack@@UAEHH@Z
hulk_intptr COpportunityBallTrack::vfunc_12(hulk_intptr __p0) { void * arg = (void *)__p0;

    A_5dc10* a = ((A_5dc10 *)((owners::Object_592a0 *)(((Arg_5dc10*)arg)))->FUN_000592a0());
    a = a->FnB_00059a40();
    if (!a)
        return 0;
    void* m = (*(void * *)&this->f_18);
    void* n = (*(void * *)&this->f_1c);
    unsigned int r = ((R_5dc10*)a->FnD_002226b0())->FnE_0027b200(m, n);
    if (r != 0xffff) {
        Q_5dc10* q = (Q_5dc10*)FUN_0008d690(sizeof(::COpportunityBallAction));
        if (q)
            return q->FnF_0001adb0(this, arg, r);
    }
    return 0;
}

namespace fn_fd61af26 {

// 0x0005dc80 FUN_0005dc80 (19 B): matches/0x0005dc80.cpp
// sym: ?FUN_0005dc80@fn_fd61af26@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005dc80(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5e0), ((char*)&DAT_004dc5e4));
}

} // namespace fn_fd61af26

// 0x0005dca0 CProceduralDurationAnimationTrack::vfunc_0 (16 B): matches/0x0005dca0.cpp
// sym: ?vfunc_0@CProceduralDurationAnimationTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CProceduralDurationAnimationTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5e0;
    return p[index];
}


// 0x0005dcb0 FUN_0005dcb0 (86 B): matches/0x0005dcb0.cpp [wrapped: conflict: CProceduralDurationAnimationTrack]
// sym: ??0CProceduralDurationAnimationTrack@fn_0005dcb0@@QAE@XZ
namespace fn_0005dcb0 {
class CTrack_5dcb0 {
  public:
    CTrack_5dcb0();
    virtual hulk_intptr Fnf_0005dca0(int);
    char pad[4];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class CProceduralDurationAnimationTrack : public CTrack_5dcb0 {
  public:
    CProceduralDurationAnimationTrack();
    char p0[4];
    int a;
    float b;
    int c;
    Sub s1;
    float d;
    int e, f;
    float g;
    int h;
    char p1[4];
    Sub s2;
    int i, j, k;
    char l;
};
CProceduralDurationAnimationTrack::CProceduralDurationAnimationTrack()
    : CTrack_5dcb0(), a(0), b(1.0f), c(0), s1(), d(1.0f), e(0), f(0), g(-1.0f), h(0), s2(), i(0), j(0), k(0), l(0) {}
} // namespace fn_0005dcb0


// 0x0005dd10 CProceduralDurationAnimationTrack::vfunc_13 (13 B): matches/0x0005dd10.cpp
// sym: ?vfunc_13@CProceduralDurationAnimationTrack@@UAEXPAX@Z
void CProceduralDurationAnimationTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffff0000;
}


// 0x0005dd20 CProceduralDurationAnimationTrack::vfunc_6 (4 B): matches/0x0005dd20.cpp
// sym: ?vfunc_6@CProceduralDurationAnimationTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CProceduralDurationAnimationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005dd30 CProceduralDurationAnimationTrack::vfunc_7 (7 B): matches/0x0005dd30.cpp
// sym: ?vfunc_7@CProceduralDurationAnimationTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CProceduralDurationAnimationTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_fd61af26 {

// 0x0005dd40 FUN_0005dd40 (33 B): matches/0x0005dd40.cpp
// sym: ??1CProceduralDurationAnimationTrack_5dd40@fn_fd61af26@@QAE@XZ
CProceduralDurationAnimationTrack_5dd40::~CProceduralDurationAnimationTrack_5dd40() {
    vptr = hulk_at_003fa284;
    s38.Fini_0027af50();
    s18.Fini_0027af50();
    Fin_00068c70();
}

} // namespace fn_fd61af26

// 0x0005dd70 CHitAnimationTrack::vfunc_12 (40 B): matches/0x0005dd70.cpp
// sym: ?vfunc_12@CHitAnimationTrack@@UAEHH@Z
hulk_intptr CHitAnimationTrack::vfunc_12(hulk_intptr param) {
    Helper_5dd70* p = (Helper_5dd70*)FUN_0008d690(sizeof(::CHitAnimationAction));
    if (p)
        return p->FUN_0001cfd0(this, param);
    return 0;
}


// 0x0005dda0 CPushBackAnimationTrack::vfunc_12 (40 B): matches/0x0005dda0.cpp
// sym: ?vfunc_12@CPushBackAnimationTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CPushBackAnimationTrack::vfunc_12(hulk_intptr param) {
    Helper_5dda0* p = (Helper_5dda0*)FUN_0008d690(sizeof(::CPushBackAnimationAction));
    if (p)
        return p->FUN_0001d020(this, param);
    return 0;
}

namespace fn_fd61af26 {

// 0x0005ddd0 FUN_0005ddd0 (19 B): matches/0x0005ddd0.cpp
// sym: ?FUN_0005ddd0@fn_fd61af26@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005ddd0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5e8), ((char*)&DAT_004dc5ec));
}

} // namespace fn_fd61af26

// 0x0005ddf0 CStunAnimationTrack::vfunc_0 (16 B): matches/0x0005ddf0.cpp
// sym: ?vfunc_0@CStunAnimationTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CStunAnimationTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5e8;
    return p[index];
}


// 0x0005de00 FUN_0005de00 (73 B): matches/0x0005de00.cpp [wrapped: conflict: CStunAnimationTrack]
// sym: ??0CStunAnimationTrack@fn_0005de00@@QAE@XZ
namespace fn_0005de00 {
class CTrack_5de00 {
  public:
    CTrack_5de00();
    virtual void f();
    char pad[8];
};
class Elem {
  public:
    Elem();
    char pad[8];
};
class CStunAnimationTrack : public CTrack_5de00 {
  public:
    CStunAnimationTrack();
    virtual void f();
    int z;
    Elem a;
    float x;
    int y, z2;
    float neg;
    int q;
    char pad2[4];
    Elem b;
    int i, j, k;
};
CStunAnimationTrack::CStunAnimationTrack()
    : CTrack_5de00(), z(0), a(), x(1.0f), y(0), z2(0), neg(-1.0f), q(0), b(), i(0), j(0), k(0) {}
} // namespace fn_0005de00


// 0x0005de50 CStunAnimationTrack::vfunc_13 (13 B): matches/0x0005de50.cpp
// sym: ?vfunc_13@CStunAnimationTrack@@UAEXPAX@Z
// Same code shape as 0x0005dd10 (propagated; names are from that function)
void CStunAnimationTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xffff0000;
}


// 0x0005de60 CStunAnimationTrack::vfunc_6 (4 B): matches/0x0005de60.cpp
// sym: ?vfunc_6@CStunAnimationTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CStunAnimationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005de70 CStunAnimationTrack::vfunc_7 (7 B): matches/0x0005de70.cpp
// sym: ?vfunc_7@CStunAnimationTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CStunAnimationTrack::vfunc_7() {
    return hulk_at_003f3388;
}


// 0x0005de80 FUN_0005de80 (33 B): matches/0x0005de80.cpp [wrapped: conflict: CStunAnimationTrack]
// sym: ??1CStunAnimationTrack@fn_0005de80@@QAE@XZ
namespace fn_0005de80 {
class Part_5de80 {
  public:
    void Close_0027af50();
    char pad[0x20];
};
class CStunAnimationTrack {
  public:
    virtual hulk_intptr FnV_0005ddf0(int);
    char pad[0xC];
    Part_5de80 p10;
    Part_5de80 p30;
    ~CStunAnimationTrack();
    void Finish_00068c70();
};
CStunAnimationTrack::~CStunAnimationTrack() {
    p30.Close_0027af50();
    p10.Close_0027af50();
    Finish_00068c70();
}
} // namespace fn_0005de80


// 0x0005deb0 CStunAnimationTrack::vfunc_12 (40 B): matches/0x0005deb0.cpp
// sym: ?vfunc_12@CStunAnimationTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CStunAnimationTrack::vfunc_12(hulk_intptr param) {
    Helper_5deb0* p = (Helper_5deb0*)FUN_0008d690(sizeof(::CStunAnimationAction));
    if (p)
        return p->FUN_0001d070(this, param);
    return 0;
}

namespace fn_fd61af26 {

// 0x0005dee0 FUN_0005dee0 (19 B): matches/0x0005dee0.cpp
// sym: ?FUN_0005dee0@fn_fd61af26@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005dee0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5f0), ((char*)&DAT_004dc5f4));
}

} // namespace fn_fd61af26

// 0x0005df00 CSnapToWallTrack::vfunc_0 (16 B): matches/0x0005df00.cpp
// sym: ?vfunc_0@CSnapToWallTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSnapToWallTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5f0;
    return p[index];
}


// 0x0005df10 FUN_0005df10 (54 B): matches/0x0005df10.cpp [wrapped: conflict: CSnapToWallTrack]
// sym: ??0CSnapToWallTrack@fn_0005df10@@QAE@XZ
namespace fn_0005df10 {
extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class CTrack_5df10 : public Base {
  public:
    int a, b, c;
    CTrack_5df10() : Base(), a(0), b(0), c(0) {}
};
class CSnapToWallTrack : public CTrack_5df10 {
  public:
    CSnapToWallTrack();
    int d, e, f2;
    char flag;
    char pad2[3];
    int g, h, i;
    virtual void f();
};
CSnapToWallTrack::CSnapToWallTrack() : CTrack_5df10() {
    _ReadWriteBarrier();
    d = 0;
    e = 0;
    f2 = 0;
    flag = 0;
    h = 0;
    i = 0;
    g = -10;
}
} // namespace fn_0005df10


// 0x0005df50 CSnapToWallTrack::vfunc_13 (13 B): matches/0x0005df50.cpp
// sym: ?vfunc_13@CSnapToWallTrack@@UAEXPAX@Z
void CSnapToWallTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff007fff;
}


// 0x0005df60 CSnapToWallTrack::vfunc_6 (4 B): matches/0x0005df60.cpp
// sym: ?vfunc_6@CSnapToWallTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSnapToWallTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005df70 CSnapToWallTrack::vfunc_7 (7 B): matches/0x0005df70.cpp
// sym: ?vfunc_7@CSnapToWallTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CSnapToWallTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0005df90 CSnapToWallTrack::vfunc_12 (40 B): matches/0x0005df90.cpp
// sym: ?vfunc_12@CSnapToWallTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CSnapToWallTrack::vfunc_12(hulk_intptr param) {
    Helper_5df90* p = (Helper_5df90*)FUN_0008d690(sizeof(::CSnapToWallAction));
    if (p)
        return p->FUN_00020c40(this, param);
    return 0;
}

namespace fn_fd61af26 {

// 0x0005dfc0 FUN_0005dfc0 (19 B): matches/0x0005dfc0.cpp
// sym: ?FUN_0005dfc0@fn_fd61af26@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005dfc0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5f8), ((char*)&DAT_004dc5fc));
}

} // namespace fn_fd61af26

// 0x0005dfe0 CClearHitRecordsTrack::vfunc_0 (16 B): matches/0x0005dfe0.cpp
// sym: ?vfunc_0@CClearHitRecordsTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CClearHitRecordsTrack::vfunc_0(int index) {
    int* p = hulk_at_004dc5f8;
    return p[index];
}


// 0x0005dff0 FUN_0005dff0 (32 B): matches/0x0005dff0.cpp [wrapped: conflict: CClearHitRecordsTrack]
// sym: ??0CClearHitRecordsTrack@fn_0005dff0@@QAE@XZ
namespace fn_0005dff0 {
class CTrack_5dff0 {
  public:
    virtual void f();
    CTrack_5dff0();
};

class CClearHitRecordsTrack : public ::CClearHitRecordsTrack {
  public:
    CClearHitRecordsTrack();
};

CClearHitRecordsTrack::CClearHitRecordsTrack() {
    f_0c = 0;
    f_08 = 1;
}
} // namespace fn_0005dff0


// 0x0005e010 CClearHitRecordsTrack::vfunc_13 (13 B): matches/0x0005e010.cpp
// sym: ?vfunc_13@CClearHitRecordsTrack@@UAEXPAX@Z
void CClearHitRecordsTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = -1;
}


// 0x0005e020 CClearHitRecordsTrack::vfunc_6 (4 B): matches/0x0005e020.cpp
// sym: ?vfunc_6@CClearHitRecordsTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CClearHitRecordsTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0005e030 CClearHitRecordsTrack::vfunc_7 (7 B): matches/0x0005e030.cpp
// sym: ?vfunc_7@CClearHitRecordsTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CClearHitRecordsTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0005e050 CClearHitRecordsTrack::vfunc_12 (26 B): matches/0x0005e050.cpp
// sym: ?vfunc_12@CClearHitRecordsTrack@@UAEHH@Z
hulk_intptr CClearHitRecordsTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_5e050*)p)->go_000215d0(a);
    return 0;
}


// 0x0005e070 CCollisionTrack::vfunc_5 (78 B): matches/0x0005e070.cpp [wrapped: conflict: CCollisionTrack]
// sym: ?vfunc_5@CCollisionTrack@fn_0005e070@@UAEPAU12@H@Z
namespace fn_0005e070 {
extern "C" char DAT_003fa214[];
struct H1 {
    void Fnf_0027af50();
};
struct H2_5e070 {
    void Fnf_00234150();
};
struct CCollisionTrack_5e070 {
    void Fnf_00236d60();
};
struct CCollisionTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCollisionTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    char pad[0x14];
};
void thunk_FUN_00267090(CCollisionTrack*);
CCollisionTrack* CCollisionTrack::vfunc_5(int flag) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003fa214);
    ((H1*)((char*)this + 0x70))->Fnf_0027af50();
    ((H1*)((char*)this + 0x68))->Fnf_0027af50();
    ((H2_5e070*)((char*)this + 0x58))->Fnf_00234150();
    ((H2_5e070*)((char*)this + 0x4c))->Fnf_00234150();
    ((H1*)((char*)this + 0x18))->Fnf_0027af50();
    ((CCollisionTrack_5e070*)this)->Fnf_00236d60();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0005e070


// 0x0005e0c0 FUN_0005e0c0 (83 B): matches/0x0005e0c0.cpp [wrapped: conflict: COpportunityBallTrack]
// sym: ??0COpportunityBallTrack@fn_0005e0c0@@QAE@XZ
namespace fn_0005e0c0 {
class CTrack_5e0c0 {
  public:
    CTrack_5e0c0();
    virtual void v0();
    char pad[4];
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
struct Fields {
    int x, y, z;
    float f;
    int one;
    Fields() : x(0), y(0), z(0), f(0.1f), one(1) {}
};
class COpportunityBallTrack : public CTrack_5e0c0 {
  public:
    COpportunityBallTrack();
    virtual void v0();
    int m8;
    int mc;
    float m10;
    char pad14[4];
    A a;
    Fields fields;
    B b;
    B c;
};
COpportunityBallTrack::COpportunityBallTrack() : CTrack_5e0c0(), mc(0), m10(-1.0f), a(), fields(), b(), c() {
    m8 = 1;
}
} // namespace fn_0005e0c0


// 0x0005e120 COpportunityBallTrack::vfunc_5 (62 B): matches/0x0005e120.cpp [wrapped: conflict: COpportunityBallTrack]
// sym: ?vfunc_5@COpportunityBallTrack@fn_0005e120@@QAEPAU12@E@Z
namespace fn_0005e120 {
extern "C" char DAT_003fa248[];
struct A_5e120 {
    int x;
    void init_0027af50();
};
struct B_5e120 {
    int x;
    void init_00234150();
};
struct C_5e120 {
    int x;
    void init_00234150();
};
void __cdecl FreeTrack_0008d330(void* p);

struct COpportunityBallTrack {
    hulk_intptr vptr;
    char p0[0x14];
    A_5e120 a;
    char p1[0x18];
    B_5e120 b;
    char p2[8];
    C_5e120 c;
    void baseInit_00068c70();
    COpportunityBallTrack* vfunc_5(unsigned char param);
};

COpportunityBallTrack* COpportunityBallTrack::vfunc_5(unsigned char param) {
    vptr = ((hulk_intptr)DAT_003fa248);
    c.init_00234150();
    b.init_00234150();
    a.init_0027af50();
    baseInit_00068c70();
    if (param & 1) {
        FreeTrack_0008d330(this);
    }
    return this;
}
} // namespace fn_0005e120


// 0x0005e160 CProceduralDurationAnimationTrack::vfunc_5 (54 B): matches/0x0005e160.cpp [wrapped: conflict: CProceduralDurationAnimationTrack]
// sym: ?vfunc_5@CProceduralDurationAnimationTrack@fn_0005e160@@UAEPAU12@H@Z
namespace fn_0005e160 {
struct CProceduralDurationAnimationTrack {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CProceduralDurationAnimationTrack* vfunc_5(int);
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct H {
    void Fnf_0027af50();
};
struct G_5e160 {
    void Fng_00068c70();
};
extern void __cdecl thunk_FUN_00267090(CProceduralDurationAnimationTrack*);
extern int vftable_5e160;
CProceduralDurationAnimationTrack* CProceduralDurationAnimationTrack::vfunc_5(int param) {
    *(hulk_intptr*)this = (hulk_intptr)((int*)DAT_003fa284);
    ((H*)((char*)this + 0x38))->Fnf_0027af50();
    ((H*)((char*)this + 0x18))->Fnf_0027af50();
    ((G_5e160*)this)->Fng_00068c70();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0005e160


// 0x0005e1a0 CStunAnimationTrack::vfunc_5 (54 B): matches/0x0005e1a0.cpp [wrapped: conflict: CStunAnimationTrack]
// sym: ?vfunc_5@CStunAnimationTrack@fn_0005e1a0@@UAEPAU12@E@Z
namespace fn_0005e1a0 {
extern "C" char DAT_003fa2c0[];
typedef unsigned char BYTE;
struct SubObj_5e1a0 {
    void Fnf_0027af50();
};
void destroy_0008d330(void* p);
struct CStunAnimationTrack {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual CStunAnimationTrack* vfunc_5(BYTE);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    void core_00068c70();
    char pad[0x30 - 4];
};
CStunAnimationTrack* CStunAnimationTrack::vfunc_5(BYTE param) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003fa2c0);
    ((SubObj_5e1a0*)((char*)this + 0x30))->Fnf_0027af50();
    ((SubObj_5e1a0*)((char*)this + 0x10))->Fnf_0027af50();
    this->core_00068c70();
    if (param & 1)
        destroy_0008d330(this);
    return this;
}
} // namespace fn_0005e1a0


// 0x0005e1e0 CSnapToWallTrack::vfunc_5 (36 B): matches/0x0005e1e0.cpp [wrapped: conflict: CSnapToWallTrack; CTrack]
// sym: ?vfunc_5@CSnapToWallTrack@fn_0005e1e0@@QAEPAV12@C@Z
namespace fn_0005e1e0 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fa2fc[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CSnapToWallTrack : public CTrack {
  public:
    CSnapToWallTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CSnapToWallTrack* CSnapToWallTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fa2fc;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_0005e1e0


// 0x0005e210 CClearHitRecordsTrack::vfunc_5 (36 B): matches/0x0005e210.cpp [wrapped: conflict: CClearHitRecordsTrack; CTrack]
// sym: ?vfunc_5@CClearHitRecordsTrack@fn_0005e210@@QAEPAV12@C@Z
namespace fn_0005e210 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* hulk_at_003fa338[];

class CTrack {
  public:
    void Destroy_00068c70(); // FUN_00236d60, __thiscall, this in ecx
};

class CClearHitRecordsTrack : public CTrack {
  public:
    CClearHitRecordsTrack* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CClearHitRecordsTrack* CClearHitRecordsTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003fa338;
    Destroy_00068c70();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_0005e210


// 0x0005e260 fight::ParamFloatConstRange<CCollisionTrack>::vfunc_6 (26 B): matches/0x0005e260.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e280 fight::ParamFloatConstRange<CCollisionTrack>::vfunc_2 (11 B): matches/0x0005e280.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e2b0 fight::ParamVector<CCollisionTrack>::vfunc_6 (26 B): matches/0x0005e2b0.cpp
// sym: ?vfunc_6@?$ParamVector@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CCollisionTrack>*)a)->*(*(bool (fight::ParamVector<CCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e2d0 fight::ParamVector<CCollisionTrack>::vfunc_2 (11 B): matches/0x0005e2d0.cpp
// sym: ?vfunc_2@?$ParamVector@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e300 fight::ParamIntConstRange<CCollisionTrack>::vfunc_6 (26 B): matches/0x0005e300.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CCollisionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e320 fight::ParamIntConstRange<CCollisionTrack>::vfunc_2 (11 B): matches/0x0005e320.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e350 fight::ParamBool<CCollisionTrack>::vfunc_6 (26 B): matches/0x0005e350.cpp
// sym: ?vfunc_6@?$ParamBool@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CCollisionTrack>*)a)->*(*(bool (fight::ParamBool<CCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e370 fight::ParamBool<CCollisionTrack>::vfunc_2 (11 B): matches/0x0005e370.cpp
// sym: ?vfunc_2@?$ParamBool@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e3b0 fight::ParamEnumConstList<CCollisionTrack>::vfunc_7 (6 B): matches/0x0005e3b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0005e3c0 fight::ParamEnumConstList<CCollisionTrack>::vfunc_6 (30 B): matches/0x0005e3c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_5e3c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_5e3c0*)&DAT_003f335c));
}


// 0x0005e3e0 fight::ParamEnumConstList<CCollisionTrack>::vfunc_8 (26 B): matches/0x0005e3e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionTrack>::**)(int))&this->f_18))(b);
}


// 0x0005e400 fight::ParamEnumConstList<CCollisionTrack>::vfunc_2 (11 B): matches/0x0005e400.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionTrack>::vfunc_2() {
    return this->f_18 == 0;
}

namespace fn_fd61af26 {

// 0x0005e430 fight::ParamBranch<CCollisionTrack>::vfunc_6 (12 B): matches/0x0005e430.cpp
// sym: ?vfunc_6@ParamBranch@fn_fd61af26@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fd61af26

// 0x0005e460 fight::ParamString<CCollisionTrack>::vfunc_6 (26 B): matches/0x0005e460.cpp
// sym: ?vfunc_6@?$ParamString@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<CCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CCollisionTrack>*)a)->*(*(bool (fight::ParamString<CCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e480 fight::ParamString<CCollisionTrack>::vfunc_2 (11 B): matches/0x0005e480.cpp
// sym: ?vfunc_2@?$ParamString@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<CCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e4b0 fight::ParamBoolPtr<CCollisionTrack>::vfunc_6 (19 B): matches/0x0005e4b0.cpp
// sym: ?vfunc_6@?$ParamBoolPtr@VCCollisionTrack@@@fight@@UAE_NHH@Z
template <> bool fight::ParamBoolPtr<CCollisionTrack>::vfunc_6(hulk_intptr __p0, int __p1) { unsigned char * p = (unsigned char *)__p0; unsigned char v = (unsigned char)__p1;

    p[this->f_10] = v;
    return true;
}

namespace fn_fd61af26 {

// 0x0005e4f0 fight::ParamFloatPtrConstRange<CCollisionTrack>::vfunc_6 (19 B): matches/0x0005e4f0.cpp
// sym: ?v6@ParamFloatPtrConstRange@fn_fd61af26@@UAE_NPAXM@Z
bool ParamFloatPtrConstRange::v6(void* p, float value) {
    *(float*)((char*)p + offset) = value;
    return true;
}

} // namespace fn_fd61af26

// 0x0005e530 fight::ParamFloatConstRange<COpportunityBallTrack>::vfunc_6 (26 B): matches/0x0005e530.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<COpportunityBallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<COpportunityBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<COpportunityBallTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<COpportunityBallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e550 fight::ParamFloatConstRange<COpportunityBallTrack>::vfunc_2 (11 B): matches/0x0005e550.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<COpportunityBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e580 fight::ParamVector<COpportunityBallTrack>::vfunc_6 (26 B): matches/0x0005e580.cpp
// sym: ?vfunc_6@?$ParamVector@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<COpportunityBallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<COpportunityBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<COpportunityBallTrack>*)a)->*(*(bool (fight::ParamVector<COpportunityBallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e5a0 fight::ParamVector<COpportunityBallTrack>::vfunc_2 (11 B): matches/0x0005e5a0.cpp
// sym: ?vfunc_2@?$ParamVector@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<COpportunityBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e5d0 fight::ParamIntConstRange<COpportunityBallTrack>::vfunc_6 (26 B): matches/0x0005e5d0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<COpportunityBallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<COpportunityBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<COpportunityBallTrack>*)a)->*(*(bool (fight::ParamIntConstRange<COpportunityBallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e5f0 fight::ParamIntConstRange<COpportunityBallTrack>::vfunc_2 (11 B): matches/0x0005e5f0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<COpportunityBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e620 fight::ParamBranch<COpportunityBallTrack>::vfunc_6 (12 B): matches/0x0005e620.cpp [wrapped: same definition as 0x0005e430 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005e620@@UAEXPAX@Z
namespace fn_0005e620 {
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
} // namespace fn_0005e620


// 0x0005e650 fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::vfunc_6 (26 B): matches/0x0005e650.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e670 fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::vfunc_2 (11 B): matches/0x0005e670.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e6b0 fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_7 (6 B): matches/0x0005e6b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0005e6c0 fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_6 (30 B): matches/0x0005e6c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_5e6c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_5e6c0*)&DAT_003f335c));
}


// 0x0005e6e0 fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_8 (26 B): matches/0x0005e6e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CProceduralDurationAnimationTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::**)(int))&this->f_18))(b);
}


// 0x0005e700 fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_2 (11 B): matches/0x0005e700.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0005e730 fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::vfunc_6 (26 B): matches/0x0005e730.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CProceduralDurationAnimationTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e750 fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::vfunc_2 (11 B): matches/0x0005e750.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e780 fight::ParamBool<CProceduralDurationAnimationTrack>::vfunc_6 (26 B): matches/0x0005e780.cpp
// sym: ?vfunc_6@?$ParamBool@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CProceduralDurationAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CProceduralDurationAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CProceduralDurationAnimationTrack>*)a)->*(*(bool (fight::ParamBool<CProceduralDurationAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e7a0 fight::ParamBool<CProceduralDurationAnimationTrack>::vfunc_2 (11 B): matches/0x0005e7a0.cpp
// sym: ?vfunc_2@?$ParamBool@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CProceduralDurationAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e7d0 fight::ParamFloatConstRange<CStunAnimationTrack>::vfunc_6 (26 B): matches/0x0005e7d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CStunAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CStunAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CStunAnimationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CStunAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e7f0 fight::ParamFloatConstRange<CStunAnimationTrack>::vfunc_2 (11 B): matches/0x0005e7f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CStunAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e800 FUN_0005e800 (46 B): matches/0x0005e800.cpp [wrapped: conflict: fight::ParamEnumConstList]
// sym: ??0?$ParamEnumConstList@VCStunAnimationTrack@fn_0005e800@@@fight@fn_0005e800@@QAE@HHHH@Z
namespace fn_0005e800 {
class Base {
  public:
    Base(int);
    virtual void* Fnf_0005ecb0(int);
    char pad[12];
};
class CStunAnimationTrack;
namespace fight {
template <class T> class ParamEnumConstList : public Base {
  public:
    ParamEnumConstList(int, int, int, int);
    int a, b, c;
    virtual void g();
};
} // namespace fight
template <>
fight::ParamEnumConstList<CStunAnimationTrack>::ParamEnumConstList(int x, int y, int z, int w)
    : Base(x), a(y), b(z), c(w) {}
} // namespace fn_0005e800


// 0x0005e830 fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_7 (6 B): matches/0x0005e830.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0005e840 fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_6 (30 B): matches/0x0005e840.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_5e840 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_5e840*)&DAT_003f335c));
}


// 0x0005e860 fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_8 (26 B): matches/0x0005e860.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CStunAnimationTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CStunAnimationTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CStunAnimationTrack>::**)(int))&this->f_18))(b);
}


// 0x0005e880 fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_2 (11 B): matches/0x0005e880.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0005e8b0 fight::ParamIntConstRange<CStunAnimationTrack>::vfunc_6 (26 B): matches/0x0005e8b0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CStunAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CStunAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CStunAnimationTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CStunAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e8d0 fight::ParamIntConstRange<CStunAnimationTrack>::vfunc_2 (11 B): matches/0x0005e8d0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CStunAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e900 fight::ParamFloatConstRange<CSnapToWallTrack>::vfunc_6 (26 B): matches/0x0005e900.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSnapToWallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSnapToWallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSnapToWallTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSnapToWallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e920 fight::ParamFloatConstRange<CSnapToWallTrack>::vfunc_2 (11 B): matches/0x0005e920.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSnapToWallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e950 fight::ParamVector<CSnapToWallTrack>::vfunc_6 (26 B): matches/0x0005e950.cpp
// sym: ?vfunc_6@?$ParamVector@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSnapToWallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CSnapToWallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CSnapToWallTrack>*)a)->*(*(bool (fight::ParamVector<CSnapToWallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e970 fight::ParamVector<CSnapToWallTrack>::vfunc_2 (11 B): matches/0x0005e970.cpp
// sym: ?vfunc_2@?$ParamVector@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSnapToWallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e9a0 fight::ParamBool<CSnapToWallTrack>::vfunc_6 (26 B): matches/0x0005e9a0.cpp
// sym: ?vfunc_6@?$ParamBool@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSnapToWallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSnapToWallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSnapToWallTrack>*)a)->*(*(bool (fight::ParamBool<CSnapToWallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005e9c0 fight::ParamBool<CSnapToWallTrack>::vfunc_2 (11 B): matches/0x0005e9c0.cpp
// sym: ?vfunc_2@?$ParamBool@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSnapToWallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005e9f0 fight::ParamIntConstRange<CSnapToWallTrack>::vfunc_6 (26 B): matches/0x0005e9f0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSnapToWallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSnapToWallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSnapToWallTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSnapToWallTrack>::**)(int))&this->f_10))(b);
}


// 0x0005ea10 fight::ParamIntConstRange<CSnapToWallTrack>::vfunc_2 (11 B): matches/0x0005ea10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSnapToWallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005ea40 fight::ParamFloatConstRange<CClearHitRecordsTrack>::vfunc_6 (26 B): matches/0x0005ea40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClearHitRecordsTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CClearHitRecordsTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CClearHitRecordsTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CClearHitRecordsTrack>::**)(int))&this->f_10))(b);
}


// 0x0005ea60 fight::ParamFloatConstRange<CClearHitRecordsTrack>::vfunc_2 (11 B): matches/0x0005ea60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClearHitRecordsTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0005ea70 fight::ParamFloatConstRange<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005ea70.cpp
// sym: ??_G?$ParamFloatConstRange@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ea90 fight::ParamVector<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005ea90.cpp
// sym: ??_G?$ParamVector@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005eab0 fight::ParamIntConstRange<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005eab0.cpp
// sym: ??_G?$ParamIntConstRange@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ead0 fight::ParamBool<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005ead0.cpp
// sym: ??_G?$ParamBool@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005eaf0 fight::ParamEnumConstList<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005eaf0.cpp
// sym: ??_G?$ParamEnumConstList@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005eb10 fight::ParamBranch<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005eb10.cpp
// sym: ??_G?$ParamBranch@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005eb30 fight::ParamString<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005eb30.cpp
// sym: ??_G?$ParamString@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005eb50 fight::ParamBoolPtr<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005eb50.cpp
// sym: ??_G?$ParamBoolPtr@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005eb70 fight::ParamFloatPtrConstRange<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005eb70.cpp
// sym: ??_G?$ParamFloatPtrConstRange@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ecf0 fight::ParamFloatConstRange<CSnapToWallTrack>::vfunc_0 (30 B): matches/0x0005ecf0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSnapToWallTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ed10 fight::ParamVector<CSnapToWallTrack>::vfunc_0 (30 B): matches/0x0005ed10.cpp
// sym: ??_G?$ParamVector@VCSnapToWallTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ed30 fight::ParamBool<CSnapToWallTrack>::vfunc_0 (30 B): matches/0x0005ed30.cpp
// sym: ??_G?$ParamBool@VCSnapToWallTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ed50 fight::ParamIntConstRange<CSnapToWallTrack>::vfunc_0 (30 B): matches/0x0005ed50.cpp
// sym: ??_G?$ParamIntConstRange@VCSnapToWallTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005ed70 fight::ParamFloatConstRange<CClearHitRecordsTrack>::vfunc_0 (30 B): matches/0x0005ed70.cpp
// sym: ??_G?$ParamFloatConstRange@VCClearHitRecordsTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_fd61af26 {

} // namespace fn_fd61af26

// 0x0005ed90 FUN_0005ed90 (460 B): matches/0x0005ed90.cpp
// sym: _FUN_0005ed90
// (gx2, D18) rewritten; constructs the real ParamBool<CSnapToWallTrack>, ParamFloatConstRange<CSnapToWallTrack>, ParamIntConstRange<CSnapToWallTrack>, ParamVector<CSnapToWallTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005ed90()
{
    if (DAT_004dc5f4 == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::CSnapToWallTrack>("timeBegin", &owners::Obj_5d850::FUN_0005d850);
        params[1] = new ::fight::ParamFloatConstRange< ::CSnapToWallTrack>("timeEnd", &owners::Obj_5d860::FUN_0005d860);
        params[2] = new ::fight::ParamFloatConstRange< ::CSnapToWallTrack>("orientation", &owners::Obj_5d870::FUN_0005d870);
        params[3] = new ::fight::ParamVector< ::CSnapToWallTrack>("offset", &fn_fd61af26::O_5d890::Set);
        params[4] = new ::fight::ParamBool< ::CSnapToWallTrack>("snapToGround", &owners::Obj_5d8b0::FUN_0005d8b0);
        params[5] = new ::fight::ParamIntConstRange< ::CSnapToWallTrack>("priority", &owners::Obj_5d8c0::FUN_0005d8c0);
        params[6] = new ::fight::ParamFloatConstRange< ::CSnapToWallTrack>("rootBlendInTime", &fn_fd61af26::Obj_5d8d0::Set);
        params[7] = new ::fight::ParamFloatConstRange< ::CSnapToWallTrack>("rootBlendOutTime", &owners::Obj_5d8e0::FUN_0005d8e0);
        FUN_002347b0(&DAT_004dc5f0, params, 8);
    }
    DAT_004dc5f4++;
}



// 0x0005ef60 FUN_0005ef60 (95 B): matches/0x0005ef60.cpp
// sym: _FUN_0005ef60
// (gx2, D18) from CCollisionTrack.iso_0005ef60.cpp; constructs the real ParamFloatConstRange<CClearHitRecordsTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005ef60()
{
    if (DAT_004dc5fc == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamFloatConstRange< ::CClearHitRecordsTrack>("timeBegin", &owners::Obj_5d8f0::FUN_0005d8f0);
        FUN_002347b0(&DAT_004dc5f8, params, 1);
    }
    DAT_004dc5fc++;
}



// 0x0005efe0 fight::ParamNameConstList<CCollisionTrack>::vfunc_7 (12 B): matches/0x0005efe0.cpp [wrapped: same definition as 0x0005e430 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005efe0@@UAEXPAX@Z
namespace fn_0005efe0 {
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
} // namespace fn_0005efe0


// 0x0005f010 fight::ParamName<CCollisionTrack>::vfunc_7 (12 B): matches/0x0005f010.cpp [wrapped: same definition as 0x0005e430 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005f010@@UAEXPAX@Z
namespace fn_0005f010 {
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
} // namespace fn_0005f010


// 0x0005f020 FUN_0005f020 (32 B): matches/0x0005f020.cpp [wrapped: conflict: fight::ParamNameConstList]
// sym: ??0?$ParamNameConstList@VCOpportunityBallTrack@fn_0005f020@@@fight@fn_0005f020@@QAE@HH@Z
namespace fn_0005f020 {
class Base {
  public:
    Base(int);
    virtual void f();
};
class COpportunityBallTrack;
namespace fight {
template <class T> class ParamNameConstList : public Base {
  public:
    ParamNameConstList(int, int);
    virtual void f();
    char pad[12];
    int value;
};
} // namespace fight
template <class T> fight::ParamNameConstList<T>::ParamNameConstList(int a, int b) : Base(a) {
    value = b;
}
template fight::ParamNameConstList<COpportunityBallTrack>::ParamNameConstList(int, int);
} // namespace fn_0005f020


// 0x0005f040 fight::ParamNameConstList<COpportunityBallTrack>::vfunc_7 (12 B): matches/0x0005f040.cpp [wrapped: same definition as 0x0005e430 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005f040@@UAEXPAX@Z
namespace fn_0005f040 {
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
} // namespace fn_0005f040


// 0x0005f070 fight::ParamName<CProceduralDurationAnimationTrack>::vfunc_7 (12 B): matches/0x0005f070.cpp [wrapped: same definition as 0x0005e430 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005f070@@UAEXPAX@Z
namespace fn_0005f070 {
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
} // namespace fn_0005f070

namespace fn_fd61af26 {

// 0x0005f080 FUN_0005f080 (32 B): matches/0x0005f080.cpp
// sym: ??0ParamName_5f080@fn_fd61af26@@QAE@HH@Z
ParamName_5f080::ParamName_5f080(int a, int b) throw() {
    ((fight::ParamValueName *)(((Base_5f080*)this)))->FUN_00234a90((const char *)(hulk_uintptr)(int)a);
    vptr = hulk_at_003fa758;
    m10 = b;
}

} // namespace fn_fd61af26

// 0x0005f0a0 fight::ParamName<CStunAnimationTrack>::vfunc_7 (12 B): matches/0x0005f0a0.cpp [wrapped: same definition as 0x0005e430 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0005f0a0@@UAEXPAX@Z
namespace fn_0005f0a0 {
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
} // namespace fn_0005f0a0


// 0x0005f0b0 fight::ParamNameConstList<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005f0b0.cpp
// sym: ??_G?$ParamNameConstList@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005f0d0 fight::ParamName<CCollisionTrack>::vfunc_0 (30 B): matches/0x0005f0d0.cpp
// sym: ??_G?$ParamName@VCCollisionTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0005f150 FUN_0005f150 (2229 B): matches/0x0005f150.cpp
// sym: _FUN_0005f150
// (gx2, D18) from CCollisionTrack.iso_0005f150.cpp; constructs the real ParamBool<CCollisionTrack>, ParamBoolPtr<CCollisionTrack>, ParamBranch<CCollisionTrack>, ParamEnumConstList<CCollisionTrack>, ParamFloatConstRange<CCollisionTrack>, ParamFloatPtrConstRange<CCollisionTrack>, ParamIntConstRange<CCollisionTrack>, ParamName<CCollisionTrack>, ParamNameConstList<CCollisionTrack>, ParamString<CCollisionTrack>, ParamVector<CCollisionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005f150()
{
    if (DAT_004dc5d4 == 0) {
        ::fight::ParamValue* params[40];
        params[0] = new ::fight::ParamFloatConstRange< ::CCollisionTrack>("timeBegin", &owners::T_5d4b0::FUN_0005d4b0);
        params[1] = new ::fight::ParamFloatConstRange< ::CCollisionTrack>("timeEnd", &owners::X_5d4c0::FUN_0005d4c0);
        params[2] = new ::fight::ParamNameConstList< ::CCollisionTrack>("joint", &owners::X_5d4d0::FUN_0005d4d0);
        params[3] = new ::fight::ParamVector< ::CCollisionTrack>("offset", &fn_f133b0a3::Obj_5d4e0::Set);
        params[4] = new ::fight::ParamFloatConstRange< ::CCollisionTrack>("radius", &owners::Obj_5d500::FUN_0005d500);
        params[5] = new ::fight::ParamIntConstRange< ::CCollisionTrack>("smallMaxHitCount", &owners::O_5d510::FUN_0005d510);
        params[6] = new ::fight::ParamIntConstRange< ::CCollisionTrack>("largeMaxHitCount", &owners::X_5d520::FUN_0005d520);
        params[7] = new ::fight::ParamBool< ::CCollisionTrack>("projectile", &owners::Obj_5d530::FUN_0005d530);
        params[8] = new ::fight::ParamBool< ::CCollisionTrack>("missilePunch", &owners::Obj_5d540::FUN_0005d540);
        params[9] = new ::fight::ParamBool< ::CCollisionTrack>("bumper", &owners::Obj_5d550::FUN_0005d550);
        params[10] = new ::fight::ParamBool< ::CCollisionTrack>("devastator", &owners::X_5d560::FUN_0005d560);
        params[11] = new ::fight::ParamBool< ::CCollisionTrack>("overrideArmor", &owners::C_5d570::FUN_0005d570);
        params[12] = new ::fight::ParamEnumConstList< ::CCollisionTrack>("steelFists", (void*)&DAT_00495470, 4, &owners::C_5d580::FUN_0005d580);
        params[13] = new ::fight::ParamEnumConstList< ::CCollisionTrack>("hitTypes", (void*)&DAT_00495480, 3, &owners::X_5d590::FUN_0005d590);
        params[14] = new ::fight::ParamEnumConstList< ::CCollisionTrack>("crusher", (void*)&DAT_0049548c, 10, &owners::C_5d5a0::FUN_0005d5a0);
        params[15] = new ::fight::ParamBranch< ::CCollisionTrack>("receiver", &owners::Obj_12ee0::FUN_00012ee0);
        params[16] = new ::fight::ParamBranch< ::CCollisionTrack>("giver", &owners::Obj_12ef0::FUN_00012ef0);
        params[17] = new ::fight::ParamName< ::CCollisionTrack>("flag", &owners::Obj_12f00::FUN_00012f00);
        params[18] = new ::fight::ParamName< ::CCollisionTrack>("entityOffset", &owners::Obj_12f10::FUN_00012f10);
        params[19] = new ::fight::ParamString< ::CCollisionTrack>("sound", &owners::C_5dad0::FUN_0005dad0);
        params[20] = new ::fight::ParamFloatConstRange< ::CCollisionTrack>("damage", &owners::Obj_5d5b0::FUN_0005d5b0);
        params[21] = new ::fight::ParamFloatConstRange< ::CCollisionTrack>("damageMax", &owners::C_5d5c0::FUN_0005d5c0);
        params[22] = new ::fight::ParamVector< ::CCollisionTrack>("force", &owners::Obj_5d5d0::FUN_0005d5d0);
        params[23] = new ::fight::ParamVector< ::CCollisionTrack>("forceMax", static_cast<bool (fn_f133b0a3::Obj::*)(struct fn_f133b0a3::Vec3 const *)>(&fn_f133b0a3::Obj::Set));
        params[24] = new ::fight::ParamEnumConstList< ::CCollisionTrack>("direction", (void*)&DAT_004954b4, 3, &owners::Obj_5d630::FUN_0005d630);
        params[25] = new ::fight::ParamIntConstRange< ::CCollisionTrack>("interruptPriority", &owners::O_5d640::FUN_0005d640);
        params[26] = new ::fight::ParamVector< ::CCollisionTrack>("hitFreezeTime", static_cast<bool (fn_f133b0a3::Obj::*)(struct fn_f133b0a3::Point *)>(&fn_f133b0a3::Obj::Set));
        params[27] = new ::fight::ParamEnumConstList< ::CCollisionTrack>("location", (void*)&DAT_0048f6cc, DAT_003f5ed0, &owners::Obj_5d680::FUN_0005d680);
        params[28] = new ::fight::ParamBoolPtr< ::CCollisionTrack>("smallInterrupt", &::CCollisionTrack::f_f0);
        params[29] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("smallHitReactionTime", &::CCollisionTrack::f_f4);
        params[30] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("smallPushbackDistance", &::CCollisionTrack::f_f8);
        params[31] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("smallPushbackTime", &::CCollisionTrack::f_fc);
        params[32] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("smallHeight", &::CCollisionTrack::f_100);
        params[33] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("smallStunTime", &::CCollisionTrack::f_104);
        params[34] = new ::fight::ParamBoolPtr< ::CCollisionTrack>("largeInterrupt", &::CCollisionTrack::f_108);
        params[35] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("largeHitReactionTime", &::CCollisionTrack::f_10c);
        params[36] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("largePushbackDistance", &::CCollisionTrack::f_110);
        params[37] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("largePushbackTime", &::CCollisionTrack::f_114);
        params[38] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("largeHeight", &::CCollisionTrack::f_118);
        params[39] = new ::fight::ParamFloatPtrConstRange< ::CCollisionTrack>("largeStunTime", &::CCollisionTrack::f_11c);
        FUN_002347b0(&DAT_004dc5d0, params, 40);
    }
    DAT_004dc5d4++;
}


