// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001aace0..0x001acb90 (kind game, layer game, confidence high), dominant class hulkfight::scenario::Event_PathNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc09f66d {
#define TREE_TU_END }
namespace fn_fc09f66d {} using namespace fn_fc09f66d;
#include "game/hulkfight/scenario.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fc09f66d {
class X_1aacf0 {
  public:
    char m0;
    int m4;
    char m8;
    int mC;
    char Set(int v);
};
class Obj_1aad30 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};
class A_1aad50 {
  public:
    char pad[0x18];
    void* m18;
};
class Obj_1aad60 {
  public:
    char mPad[0xc];
    int mField;
    char SetObjectIndex_001aad60(int x);
};
class Obj_1aad70 {
  public:
    char pad[0x10];
    int value;
    bool SetCompare_001aad70(int v);
};
class Obj_1aad80 {
  public:
    char m[0x18];
    char* GetCharacterTemplate_001aad80();
};
extern int* hulk_at_004e1780;
class CCondition_1aade0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_0041d3cc[];
class Sub_1aae10 {
  public:
    void Init_0027af50();
};
class Condition_1aae10 {
  public:
    void Tail_002345b0();
};
class Event_TriggerVolumeNameCondition : public Condition_1aae10 {
  public:
    void* vptr;
    char pad[0x0c];
    Sub_1aae10 sub;
    void Fn();
};
extern int* hulk_at_004e1788;
class CCondition_1aae50 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1790;
class CCondition_1aaeb0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1798;
class CCondition_1aaf10 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e17a0;
class CCondition_1aaf80 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_1aafc0 {
    void Init_0027af50();
};
struct Event_CharacterTemplateCondition_1aafc0 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_0041d44c;
extern int* hulk_at_004e17a8;
class CCondition_1ab000 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_1ab040 {
    void Init_0027af50();
};
struct Event_CharacterTemplateVariationCondition_1ab040 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_0041d46c;
extern int* hulk_at_004e17b0;
class CCondition_1ab080 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041d48c[];
class Str_1ab0c0 {
  public:
    void Init_0027af50();
};
class Condition_1ab0c0 {
  public:
    void* vptr;
    char pad[12];
    Str_1ab0c0 s;
    void Fin_002345b0();
};
class Event_PathNameCondition_1ab0c0 : public Condition_1ab0c0 {
  public:
    ~Event_PathNameCondition_1ab0c0();
};
typedef unsigned int U_1ab0e0;
typedef unsigned __int64 U64_1ab0e0;
} // namespace fn_fc09f66d
extern U64_1ab0e0 __cdecl FUN_0027b020(U_1ab0e0);
namespace fight {
class Params_1ab330 {
public:
    virtual void v0();
};
}
namespace fn_fc09f66d {
struct Id64_1ab330 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af50();
};
struct VolumeInfo {
    char pad00[4];
    int type;               // 0x4
    char pad08[0xc];
    char name[1];           // 0x14
};
class CScenarioParams_1ab330 : public fight::Params_1ab330 {
public:
    virtual void v1();
    VolumeInfo *FUN_001d03c0();
};
struct Result {
    char pad[4];
    int id;
};
class Obj {
  public:
    char _m_pad_0[0x10];
    int value;
    bool Set(int x);
    Result* get_001d03c0();
    void apply_00236760(void*);
    void set_00236760(void*);
};
extern char hulk_at_0041d3cc;
struct Event_PathNameCondition_nv_1ab640 {
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(hulkfight::scenario::Event_PathNameCondition*);
class Event_TriggerVolumeNameCondition_1ab640 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_TriggerVolumeNameCondition_1ab640* vfunc_5(unsigned char);
};
extern void* hulk_at_0041d3ec[];
class Condition_1ab670 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class EventCondition_1ab670 : public Condition_1ab670 {
  public:
    EventCondition_1ab670* vfunc_5(signed char flags);
};
extern void* hulk_at_0041d40c[];
class Condition_1ab6a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class Event_FirstTimeCondition_1ab6a0 : public Condition_1ab6a0 {
  public:
    Event_FirstTimeCondition_1ab6a0* vfunc_5(signed char flags);
};
extern void* hulk_at_0041d42c[];
class Condition_1ab6d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class Event_WaypointCondition_1ab6d0 : public Condition_1ab6d0 {
  public:
    Event_WaypointCondition_1ab6d0* vfunc_5(signed char flags);
};
extern void* g_vftable_1ab700[];
class Sub_1ab700 {
  public:
    void Fini_0027af50();
};
class Condition_1ab700 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class Event_CharacterTemplateCondition_1ab700 : public Condition_1ab700 {
  public:
    char pad[0x14];
    Sub_1ab700 m18;
    Event_CharacterTemplateCondition_1ab700* f2(unsigned char flags);
};
class Sub_1ab730 {
  public:
    void Init_0027af50();
};
class Event_CharacterTemplateVariationCondition {
  public:
    virtual hulk_intptr vfunc_0_001ab000(int);
    virtual bool vfunc_1_00234270(void*);
    virtual bool vfunc_2_002342b0(int);
    virtual bool vfunc_3_002344d0(hulk_intptr, int, hulk_intptr);
    virtual bool vfunc_4_00234350(int, int);
    virtual void vfunc_5_001ab730(int);
    virtual bool vfunc_6_001ab270(void*, void*, void*);
    char pad[0x14];
    Sub_1ab730 sub;
    Event_CharacterTemplateVariationCondition(int);
    void Finish_002345b0();
};
void __cdecl FUN_0008d330(Event_CharacterTemplateVariationCondition*);
extern char threat_vftable_1ab760;
struct Event_PathNameCondition_nv_1ab760 {
    void f1_0027af50();
    void f2_002345b0();
};
class Event_PathNameCondition_1ab760 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_PathNameCondition_1ab760* vfunc_5(unsigned char);
};
struct CAxisArcCondition_1ab7c0;
class CStageCondition_1ab7d0 {};
class ParamValue_1ab7d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1ab7d0 : public ParamValue_1ab7d0 {
  public:
    virtual void f();
};
class CStageCondition_1ab860;
class ParamValue_1ab860 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1ab860 : public ParamValue_1ab860 {
  public:
    int pad;
};
struct CAxisArcCondition_1ab8a0;
class CStageCondition_1ab8b0 {};
class ParamValue_1ab8b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1ab8b0 : public ParamValue_1ab8b0 {
  public:
    virtual void f();
};
class CStageCondition_1ab940;
class ParamValue_1ab940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1ab940 : public ParamValue_1ab940 {
  public:
    int pad;
};
class CStageCondition_1ab990;
class ParamValue_1ab990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1ab990 : public ParamValue_1ab990 {
  public:
    int pad;
};
struct CAxisArcCondition_1ab9d0;
class CStageCondition_1ab9e0 {};
class ParamValue_1ab9e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1ab9e0 : public ParamValue_1ab9e0 {
  public:
    virtual void f();
};
class CStageCondition_1aba70;
class ParamValue_1aba70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1aba70 : public ParamValue_1aba70 {
  public:
    int pad;
};
struct CAxisArcCondition_1abab0;
class CStageCondition_1abac0 {};
class ParamValue_1abac0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1abac0 : public ParamValue_1abac0 {
  public:
    virtual void f();
};
struct CAxisArcCondition_1abb40;
class CStageCondition_1abb50 {};
class ParamValue_1abb50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1abb50 : public ParamValue_1abb50 {
  public:
    virtual void f();
};
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_00491ca8;
extern char DAT_004c30f8;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fc09f66d
namespace fight {
class ConditionFactoryCaster_1abbf0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class EventCondition_1abbf0 {};
} }
namespace fight {
class ConditionFactoryCaster_1abc50 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace scenario {
class Event_FirstTimeCondition_1abc50 {};
} }
namespace fn_fc09f66d {
extern char DAT_004c31b8;
extern char DAT_004c3280;
} // namespace fn_fc09f66d
namespace fight {
class ConditionFactoryCaster_1abcb0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class Event_WaypointCondition_1abcb0;
} }
namespace fn_fc09f66d {
class ConditionFactoryCaster_1abd30 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class Event_CharacterTemplateCondition_1abd30;
extern char DAT_004c3350;
class ConditionFactoryCaster_1abdb0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern char DAT_004c3430;
extern "C" void __cdecl FUN_001aacf0();
extern "C" char DAT_0041d4ac[];
extern void* Alloc_0008d690(unsigned int);
struct Obj_1abe80 {
    hulk_intptr v;
    char pad4[12];
    hulk_intptr a;
    int b;
    hulk_intptr c;
    void Init_00234cc0(const char*);
};
extern void Register_002347b0(int*, Obj_1abe80**, int);
extern "C" char DAT_0041d5f4[];
extern void __cdecl Init_002343e0(void*, void*);
class ConditionFactoryCasterTemplate_1ac220 {
  public:
    virtual bool Cast_001abbb0(void*);
};
class Owner {
  public:
    void Apply_00236760(void*);
    void Apply_00236760(int);
};
void* __cdecl FUN_002343e0(const char*, ConditionFactoryCasterTemplate_1ac220*);
class ConditionFactoryCasterTemplate_1ac2b0 {
  public:
    virtual bool Cast_001abbf0(void*);
};
class Arg {
  public:
    void Do_00236760(void*);
};
extern void* Search_002343e0(void*, ConditionFactoryCasterTemplate_1ac2b0*);
class ConditionFactoryCasterTemplate_1ac2e0 {
  public:
    virtual bool Fnf_001abc50(void*);
};
int __cdecl FUN_002343e0(int, ConditionFactoryCasterTemplate_1ac2e0*);
class ConditionFactoryCasterTemplate_1ac310 {
  public:
    virtual bool cast_001abcb0(void*);
};
extern "C" void* __cdecl find(void*, ConditionFactoryCasterTemplate_1ac310*);
class ConditionFactoryCasterTemplate_1ac460 {
  public:
    virtual bool cast_001abdb0(void*);
};
void* __cdecl lookup_002343e0(const char*, ConditionFactoryCasterTemplate_1ac460*);
class ConditionFactoryCasterTemplate_1ac580 {
  public:
    virtual int Cast_001abe30(void*);
};
class Target {
  public:
    void Apply_00236760(void*);
};
void* __cdecl Resolve_002343e0(const char*, ConditionFactoryCasterTemplate_1ac580*);
extern "C" char DAT_0041d3ec[];
struct Obj_1ac6a0 {
    hulk_uintptr vt;
    char pad[8];
    int value;
    void Init_00234590(int);
};
extern int hulk_at_0041d710;
struct ConditionFactoryTemplate_1ac6d0 {
    void* m_vptr;
    void base1_dtor_001aae30();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_0041d40c[];
class Event_1ac740 {
  public:
    void Init_00234590(int);
};
extern int hulk_at_0041d72c;
struct ConditionFactoryTemplate_1ac770 {
    void* m_vptr;
    void base1_dtor_001aae90();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class Base_1ac7e0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class WaypointCondition : public Base_1ac7e0 {
  public:
    void Init_00234590(int);
    char pad[8];
    int m0;
    int m1;
};
extern char VT_1ac7e0[];
extern void* __cdecl Allocate(unsigned int);
extern int hulk_at_0041d748;
struct ConditionFactoryTemplate_1ac820 {
    void* m_vptr;
    void base1_dtor_001aaef0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class Condition_1ac890 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Sub_1ac890 {
  public:
    void Init_0027af00();
};
class Event_TriggerVolumeNameCondition_1ac890 : public Condition_1ac890 {
  public:
    void Init_00234590(int);
    char pad[0x0c];
    Sub_1ac890 sub;
};
extern void* __cdecl Allocate_0008d690(int);
extern int hulk_at_0041d764;
struct ConditionFactoryTemplate_1ac8c0 {
    void* m_vptr;
    void base1_dtor_001aadc0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_0041d44c[];
typedef unsigned int u32_1ac930;
class Initializer_1ac930 {
  public:
    void Init_00234590(int);
};
class OffsetInitializer {
  public:
    void Init_0027af00();
};
class Condition_1ac930 {
  public:
    hulk_uintptr vf;
    char pad4[8];
    int x;
    int y;
    char pad14[4];
};
extern int hulk_at_0041d780;
struct ConditionFactoryTemplate_1ac970 {
    void* m_vptr;
    void base1_dtor_001aaf60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
struct Base {
    char data[8];
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
struct Elem {
    char data[8];
    Elem() throw();
};
struct Cond : Base {
    int type;
    int value;
    char pad[4];
    Elem elem;
    Cond() throw() : Base(0), type(2), value(0), elem() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern int hulk_at_0041d79c;
struct ConditionFactoryTemplate_1aca20 {
    void* m_vptr;
    void base1_dtor_001aafe0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_0041d48c[];
class Thing_1aca90 {
  public:
    void Init_00234590(int);
};
class Sub_1aca90 {
  public:
    void Finish_0027af00();
};
extern int hulk_at_0041d7b8;
struct ConditionFactoryTemplate_1acad0 {
    void* m_vptr;
    void base1_dtor_001ab060();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fc09f66d

// 0x001aace0 FUN_001aace0 (4 B): matches/0x001aace0.cpp
// sym: ?FUN_001aace0@Obj_1aace0@owners@@QAEPAHXZ
int* owners::Obj_1aace0::FUN_001aace0() {
    return (int*)((char*)this + 0x10);
}

namespace fn_fc09f66d {

// 0x001aacf0 FUN_001aacf0 (12 B): matches/0x001aacf0.cpp
// sym: ?Set@X_1aacf0@fn_fc09f66d@@QAEDH@Z
char X_1aacf0::Set(int v) {
    mC = v;
    return 1;
}

} // namespace fn_fc09f66d

// 0x001aad00 FUN_001aad00 (12 B): matches/0x001aad00.cpp
// sym: ?FUN_001aad00@O_1aad00@owners@@QAEDD@Z
char owners::O_1aad00::FUN_001aad00(char c) {
    m = c;
    return 1;
}


// 0x001aad10 FUN_001aad10 (12 B): matches/0x001aad10.cpp
// sym: ?FUN_001aad10@Obj_1aad10@owners@@QAE_NH@Z
bool owners::Obj_1aad10::FUN_001aad10(int x) {
    value = x;
    return true;
}


// 0x001aad20 FUN_001aad20 (12 B): matches/0x001aad20.cpp
// sym: ?FUN_001aad20@Obj_1aad20@owners@@QAE_NH@Z
bool owners::Obj_1aad20::FUN_001aad20(int value) {
    mValue = value;
    return true;
}

namespace fn_fc09f66d {

// 0x001aad30 FUN_001aad30 (12 B): matches/0x001aad30.cpp
// sym: ?Set@Obj_1aad30@fn_fc09f66d@@QAE_NH@Z
bool Obj_1aad30::Set(int v) {
    mValue = v;
    return true;
}


// 0x001aad40 FUN_001aad40 (12 B): matches/0x001aad40.cpp
// sym: ?Set@Obj@fn_fc09f66d@@QAE_NH@Z
bool Obj::Set(int x) {
    value = x;
    return true;
}


// 0x001aad50 FUN_001aad50 (4 B): matches/0x001aad50.cpp
// sym: ?FUN_001aad50@fn_fc09f66d@@YIPAXPAVA_1aad50@1@@Z
void* __fastcall FUN_001aad50(A_1aad50* self) {
    return &self->m18;
}


// 0x001aad60 FUN_001aad60 (12 B): matches/0x001aad60.cpp
// sym: ?SetObjectIndex_001aad60@Obj_1aad60@fn_fc09f66d@@QAEDH@Z
char Obj_1aad60::SetObjectIndex_001aad60(int x) {
    mField = x;
    return 1;
}


// 0x001aad70 FUN_001aad70 (12 B): matches/0x001aad70.cpp
// sym: ?SetCompare_001aad70@Obj_1aad70@fn_fc09f66d@@QAE_NH@Z
bool Obj_1aad70::SetCompare_001aad70(int v) {
    value = v;
    return true;
}


// 0x001aad80 FUN_001aad80 (4 B): matches/0x001aad80.cpp
// sym: ?GetCharacterTemplate_001aad80@Obj_1aad80@fn_fc09f66d@@QAEPADXZ
char* Obj_1aad80::GetCharacterTemplate_001aad80() {
    return m + 0x18;
}

} // namespace fn_fc09f66d

// 0x001aada0 FUN_001aada0 (12 B): matches/0x001aada0.cpp
// sym: ?FUN_001aada0@Obj_1aada0@owners@@QAE_NH@Z
bool owners::Obj_1aada0::FUN_001aada0(int x) {
    value = x;
    return true;
}


// 0x001aadb0 FUN_001aadb0 (4 B): matches/0x001aadb0.cpp
// sym: ?FUN_001aadb0@A_1aadb0@owners@@QAEPAHXZ
int* owners::A_1aadb0::FUN_001aadb0() {
    return (int*)((char*)this + 0x10);
}

namespace fn_fc09f66d {

// 0x001aadc0 FUN_001aadc0 (19 B): matches/0x001aadc0.cpp
// sym: ?FUN_001aadc0@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001aadc0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1780), ((char*)&DAT_004e1784));
}

} // namespace fn_fc09f66d

// 0x001aade0 hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_0 (16 B): matches/0x001aade0.cpp
// sym: ?vfunc_0@Event_TriggerVolumeNameCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1780;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001aae10 FUN_001aae10 (25 B): matches/0x001aae10.cpp
// sym: ?Fn@Event_TriggerVolumeNameCondition@fn_fc09f66d@@QAEXXZ
void Event_TriggerVolumeNameCondition::Fn() {
    vptr = (void*)((hulk_intptr)DAT_0041d3cc);
    sub.Init_0027af50();
    Tail_002345b0();
}


// 0x001aae30 FUN_001aae30 (19 B): matches/0x001aae30.cpp
// sym: ?FUN_001aae30@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001aae30(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1788), ((char*)&DAT_004e178c));
}

} // namespace fn_fc09f66d

// 0x001aae50 hulkfight::scenario::EventCondition::vfunc_0 (16 B): matches/0x001aae50.cpp
// sym: ?vfunc_0@EventCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::EventCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1788;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001aae90 FUN_001aae90 (19 B): matches/0x001aae90.cpp
// sym: ?FUN_001aae90@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001aae90(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1790), ((char*)&DAT_004e1794));
}

} // namespace fn_fc09f66d

// 0x001aaeb0 hulkfight::scenario::Event_FirstTimeCondition::vfunc_0 (16 B): matches/0x001aaeb0.cpp
// sym: ?vfunc_0@Event_FirstTimeCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_FirstTimeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1790;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001aaef0 FUN_001aaef0 (19 B): matches/0x001aaef0.cpp
// sym: ?FUN_001aaef0@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001aaef0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1798), ((char*)&DAT_004e179c));
}

} // namespace fn_fc09f66d

// 0x001aaf10 hulkfight::scenario::Event_WaypointCondition::vfunc_0 (16 B): matches/0x001aaf10.cpp
// sym: ?vfunc_0@Event_WaypointCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_WaypointCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1798;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001aaf60 FUN_001aaf60 (19 B): matches/0x001aaf60.cpp
// sym: ?FUN_001aaf60@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001aaf60(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e17a0), ((char*)&DAT_004e17a4));
}

} // namespace fn_fc09f66d

// 0x001aaf80 hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_0 (16 B): matches/0x001aaf80.cpp
// sym: ?vfunc_0@Event_CharacterTemplateCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e17a0;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001aafc0 FUN_001aafc0 (25 B): matches/0x001aafc0.cpp
// sym: ?Run@Event_CharacterTemplateCondition_1aafc0@fn_fc09f66d@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void Event_CharacterTemplateCondition_1aafc0::Run() {
    vptr = &hulk_at_0041d44c;
    ((Tail_1aafc0*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x001aafe0 FUN_001aafe0 (19 B): matches/0x001aafe0.cpp
// sym: ?FUN_001aafe0@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001aafe0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e17a8), ((char*)&DAT_004e17ac));
}

} // namespace fn_fc09f66d

// 0x001ab000 hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_0 (16 B): matches/0x001ab000.cpp
// sym: ?vfunc_0@Event_CharacterTemplateVariationCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_0(int index) {
    int* p = hulk_at_004e17a8;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001ab040 FUN_001ab040 (25 B): matches/0x001ab040.cpp
// sym: ?Run@Event_CharacterTemplateVariationCondition_1ab040@fn_fc09f66d@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void Event_CharacterTemplateVariationCondition_1ab040::Run() {
    vptr = &hulk_at_0041d46c;
    ((Tail_1ab040*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x001ab060 FUN_001ab060 (19 B): matches/0x001ab060.cpp
// sym: ?FUN_001ab060@fn_fc09f66d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001ab060(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e17b0), ((char*)&DAT_004e17b4));
}

} // namespace fn_fc09f66d

// 0x001ab080 hulkfight::scenario::Event_PathNameCondition::vfunc_0 (16 B): matches/0x001ab080.cpp
// sym: ?vfunc_0@Event_PathNameCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_PathNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e17b0;
    return p[index];
}

namespace fn_fc09f66d {

// 0x001ab0c0 FUN_001ab0c0 (25 B): matches/0x001ab0c0.cpp
// sym: ??1Event_PathNameCondition_1ab0c0@fn_fc09f66d@@QAE@XZ
Event_PathNameCondition_1ab0c0::~Event_PathNameCondition_1ab0c0() {
    vptr = hulk_at_0041d48c;
    s.Init_0027af50();
    Fin_002345b0();
}

} // namespace fn_fc09f66d

// 0x001ab0e0 FUN_001ab0e0 (29 B): matches/0x001ab0e0.cpp
// sym: ?FUN_001ab0e0@Obj_1ab0e0@owners@@QAEHI@Z
// Same code shape as 0x000238b0 (propagated; names are from that function)
hulk_intptr owners::Obj_1ab0e0::FUN_001ab0e0(hulk_uintptr param) {
    U64_1ab0e0 a = FUN_0027b020(((U_1ab0e0)param));
    return Second(a);
}


// 0x001ab1b0 hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_6 (189 B): equivalent/0x001ab1b0.cpp [wrapped: conflict: DAT_00494b44; hulkfight::scenario::Event_CharacterTemplateCondition]
// sym: ?vfunc_6@Event_CharacterTemplateCondition@scenario@hulkfight@fn_001ab1b0@@UAE_NIPAXI@Z @4623ba2e75eb @wcf1213c9ac1e
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001ab1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 24/24)
// hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_6 @ 0x001ab1b0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

typedef unsigned int uint_1ab1b0;
struct TypeDescriptor_1ab1b0 { uint_1ab1b0 value; }; extern TypeDescriptor_1ab1b0 DAT_00494b44, DAT_004c13d0;
struct Template_1ab1b0;
struct Params { Template_1ab1b0* FUN_001d03c0(); };
extern "C++" __declspec(nothrow) Params* __cdecl FUN_00344e74(void*,int,TypeDescriptor_1ab1b0*,TypeDescriptor_1ab1b0*,int);
struct Key_1ab1b0 { char data[4]; };
struct Template_1ab1b0 { uint_1ab1b0 unused; int kind; char pad[0x4c]; Key_1ab1b0 key; uint_1ab1b0 FUN_001c96e0(uint_1ab1b0); };
struct Character_1ab1b0 { unsigned __int64 FUN_000443c0(); };
struct Entry_1ab1b0 { char pad[0x11c]; Character_1ab1b0* character; };
struct Registry_1ab1b0 { Entry_1ab1b0* FUN_00059c10(uint_1ab1b0); };
struct Lookup_1ab1b0 { Character_1ab1b0* FUN_001ab0e0(Key_1ab1b0*); };
struct Holder_1ab1b0 { uint_1ab1b0 unused; Lookup_1ab1b0* lookup; };
struct World { char pad0[0x20]; Holder_1ab1b0* holder; char pad1[0x20]; Registry_1ab1b0* registry; }; 
namespace hulkfight { namespace scenario {
struct Event_CharacterTemplateCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(uint_1ab1b0,void*,uint_1ab1b0);
char pad[8]; uint_1ab1b0 templateId; int operation; uint_1ab1b0 unused; uint_1ab1b0 low; uint_1ab1b0 high;
};
bool Event_CharacterTemplateCondition::vfunc_6(uint_1ab1b0,void* params,uint_1ab1b0) {
Params* p=FUN_00344e74(params,0,&DAT_00494b44,&DAT_004c13d0,0);
if(!p) return false;
Template_1ab1b0* t=p->FUN_001d03c0();
uint_1ab1b0 id=t->FUN_001c96e0(templateId);
World* world=DAT_004dd700;
if(!world) return false;
Entry_1ab1b0* entry=world->registry->FUN_00059c10(id);
Character_1ab1b0* character;
if(entry) character=entry->character;
else {
if(t->kind<=0 || t->kind>3) return false;
character=world->holder->lookup->FUN_001ab0e0(&t->key);
if(!character) return false;
}
unsigned __int64 value=character->FUN_000443c0();
if(operation==0) return (uint_1ab1b0)value==low && (uint_1ab1b0)(value>>32)==high;
if(operation==1) return (uint_1ab1b0)value!=low || (uint_1ab1b0)(value>>32)!=high;
return false;
}
}}
} // namespace fn_001ab1b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ab270 hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_6 (189 B): equivalent/0x001ab270.cpp [wrapped: conflict: FUN_00344e74; World; hulkfight::scenario::Event_CharacterTemplateVariationCondition]
// sym: ?vfunc_6@Event_CharacterTemplateVariationCondition@scenario@hulkfight@fn_001ab270@@UAE_NPAX00@Z @79ed70475a8c @w40af16b65df3
namespace fn_001ab270 {
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 24/24)
// hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_6 @ 0x001ab270
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern "C" { extern char DAT_00494b44; extern char DAT_004c13d0; extern "C++" { __declspec(nothrow) void* __cdecl FUN_00344e74(void*,int,void*,void*,int); } }
struct Key_1ab270 { char bytes[1]; };
struct Variation { unsigned __int64 FUN_00044370(); };
struct Found_1ab270 { char pad[0x11c]; Variation* variation; };
struct Lookup_1ab270 { Found_1ab270* FUN_00059c10(int); };
struct Registry_1ab270 { Variation* FUN_000238b0(Key_1ab270*); };
struct Group_1ab270 { char pad[4]; Registry_1ab270* registry; };
struct World { char pad[0x20]; Group_1ab270* group; char pad2[0x20]; Lookup_1ab270* lookup; };
struct Character_1ab270 { char pad[4]; int kind; char pad2[0x4c]; Key_1ab270 key; int FUN_001c96e0(int); };
struct Event_1ab270 { Character_1ab270* FUN_001d03c0(); };
namespace hulkfight { namespace scenario {
struct Event_CharacterTemplateVariationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,void*,void*);
 char pad[8]; int selector; int mode; int unused; unsigned int expectedLow; unsigned int expectedHigh;
};
bool Event_CharacterTemplateVariationCondition::vfunc_6(void*,void* arg,void*) {
 Event_1ab270* e=(Event_1ab270*)FUN_00344e74(arg,0,&DAT_00494b44,&DAT_004c13d0,0);
 if(!e) return false;
 Character_1ab270* c=e->FUN_001d03c0();
 int id=c->FUN_001c96e0(selector);
 World* w=DAT_004dd700;
 if(!w) return false;
 Found_1ab270* f=w->lookup->FUN_00059c10(id);
 Variation* v;
 if(f) v=f->variation;
 else { if(c->kind<=0 || c->kind>3) return false; v=w->group->registry->FUN_000238b0(&c->key); if(!v) return false; }
 unsigned __int64 value=v->FUN_00044370();
 bool equal=(unsigned int)value==expectedLow && (unsigned int)(value>>32)==expectedHigh;
 if(mode==0) return equal;
 if(mode==1) return !equal;
 return false;
}
}}
} // namespace fn_001ab270
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ab330 hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6 (131 B): equivalent/0x001ab330.cpp
// sym: ?vfunc_6@Event_TriggerVolumeNameCondition@scenario@hulkfight@@UAE_NPAX00@Z @5c535df6f066 @w4dbd3b5bc23a
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6 @ 0x001ab330
bool hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_1ab330 * params = (fight::Params_1ab330 *)__p1; int c = (int)__p2;

    Id64_1ab330 name;
    name.FUN_0027af00();

    CScenarioParams_1ab330 *sp = dynamic_cast<CScenarioParams_1ab330 *>(params);
    if (sp != 0) {
        VolumeInfo *info = sp->FUN_001d03c0();
        if (info->type == 0x1d || info->type == 0x1e) {
            ((owners::Target_27b040 *)&name)->FUN_0027b040((hulk_uintptr)(info->name));
            if (name.lo == (*(unsigned int *)&this->f_10) && name.hi == (*(unsigned int *)&this->f_14)) {
                name.FUN_0027af50();
                return true;
            }
        }
    }
    name.FUN_0027af50();
    return false;
}


// 0x001ab3c0 hulkfight::scenario::EventCondition::vfunc_6 (60 B): matches/0x001ab3c0.cpp
// sym: ?vfunc_6@EventCondition@scenario@hulkfight@@UAE_NPAX00@Z
 // namespace hulkfight
bool hulkfight::scenario::EventCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; void * b = (void *)__p1; int c = (int)__p2;

    Obj* p = ((Obj *)__RTDynamicCast(b, 0, &desc1, &desc2, 0));
    if (!p)
        return (bool)(false);
    return (bool)(p->get_001d03c0()->id == this->f_0c);
}


// 0x001ab400 hulkfight::scenario::Event_PathNameCondition::vfunc_6 (278 B): equivalent/0x001ab400.cpp [wrapped: conflict: hulkfight::scenario::Event_PathNameCondition]
// sym: ?vfunc_6@Event_PathNameCondition@scenario@hulkfight@fn_001ab400@@UAE_NPAX00@Z @19a6e427c8b7 @w4c270516b437
namespace fn_001ab400 {
// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 18/18)
// hulkfight::scenario::Event_PathNameCondition::vfunc_6 @ 0x001ab400
extern char DAT_00494b44;
extern char DAT_004c13d0;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Name_1ab400 {
 unsigned first, second;
 void FUN_0027af00();
 void FUN_0027af50();
 void FUN_0027b0e0(void*);
 void FUN_0027af70(Name_1ab400*);
};
struct EventData_1ab400 { char pad[4]; int type; char pad2[12]; unsigned payload[2]; };
struct Event_1ab400 { EventData_1ab400* FUN_001d03c0(); };
namespace hulkfight { namespace scenario {
struct Event_PathNameCondition {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual bool vfunc_6(void*,void*,void*);
 char pad[8]; int operation; unsigned first,second;
};
bool Event_PathNameCondition::vfunc_6(void*, void* input, void*) {
 Event_1ab400* event = (Event_1ab400*)FUN_00344e74(input,0,&DAT_00494b44,&DAT_004c13d0,0);
 if (!event) return false;
 EventData_1ab400* data = event->FUN_001d03c0();
 Name_1ab400 name; name.FUN_0027af00();
 if(data->type == 17) {
 Name_1ab400 temp; temp.FUN_0027b0e0(data->payload); name.FUN_0027af70(&temp); temp.FUN_0027af50();
 } else if(data->type == 16) {
 Name_1ab400 temp; temp.FUN_0027b0e0(data->payload); name.FUN_0027af70(&temp); temp.FUN_0027af50();
 } else { name.FUN_0027af50(); return false; }
 bool result = false;
 if(operation==0) result = name.first == first && name.second == second;
 else if(operation==1) result = name.first != first || name.second != second;
 name.FUN_0027af50();
 return result;
}
}}
} // namespace fn_001ab400


// 0x001ab520 hulkfight::scenario::Event_WaypointCondition::vfunc_6 (181 B): equivalent/0x001ab520.cpp [wrapped: conflict: FUN_00344e74; hulkfight::scenario::Event_WaypointCondition]
// sym: ?vfunc_6@Event_WaypointCondition@scenario@hulkfight@fn_001ab520@@UAE_NPAX00@Z @9dc20b8cc2d3 @w8971c5e4e8d1
namespace fn_001ab520 {
// STATUS: equivalent (tools/equiv.py level 3: 3056 inputs, branch coverage 26/26)
// hulkfight::scenario::Event_WaypointCondition::vfunc_6 @ 0x001ab520
struct State_1ab520 { char pad0[4]; int type; char pad8[0x4c]; int count17; char pad58[8]; int count16; };
struct Object { State_1ab520* FUN_001d03c0(); };
extern char DAT_00494b44;
extern char DAT_004c13d0;
extern "C++" __declspec(nothrow) Object* __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace hulkfight { namespace scenario {
struct Event_WaypointCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,void*,void*);
 char pad4[8]; unsigned operation; int threshold;
};
bool Event_WaypointCondition::vfunc_6(void*, void* object, void*) {
 Object* found=FUN_00344e74(object,0,&DAT_00494b44,&DAT_004c13d0,0);
 if (!found) return false;
 State_1ab520* state=found->FUN_001d03c0();
 int value;
 if(state->type==16) value=state->count16;
 else if(state->type==17) value=state->count17;
 else return false;
 switch(operation) {
 case 0:return value<threshold;
 case 1:return value<=threshold;
 case 2:return value==threshold;
 case 3:return value!=threshold;
 case 4:return value>=threshold;
 case 5:return value>threshold;
 default:return false;
 }
}
}}
} // namespace fn_001ab520


// 0x001ab5f0 hulkfight::scenario::Event_FirstTimeCondition::vfunc_6 (71 B): equivalent/0x001ab5f0.cpp [wrapped: conflict: DAT_00494b44; DAT_004c13d0; Params; hulkfight::scenario::Event_FirstTimeCondition]
// sym: ?vfunc_6@Event_FirstTimeCondition@scenario@hulkfight@fn_001ab5f0@@QAE_NPAX00@Z @35fd34425045 @w669060e55e12
namespace fn_001ab5f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// hulkfight::scenario::Event_FirstTimeCondition::vfunc_6 @ 0x001ab5f0
struct Descriptor { int value; }; extern Descriptor DAT_00494b44; extern Descriptor DAT_004c13d0;
struct EventData { char pad[4]; int kind; char gap[0x50]; unsigned char flag; };
struct Params { EventData* FUN_001d03c0(); };
extern Params* __cdecl FUN_00344e74(void*, int, Descriptor*, Descriptor*, int);
namespace hulkfight { namespace scenario {
struct Event_FirstTimeCondition { char pad[12]; unsigned char flag; bool vfunc_6(void*, void*, void*); };
bool Event_FirstTimeCondition::vfunc_6(void* unused, void* params, void* extra) {
    Params* p = FUN_00344e74(params, 0, &DAT_00494b44, &DAT_004c13d0, 0);
    if (!p) return false;
    EventData* data = p->FUN_001d03c0();
    return data->kind == 0x11 && data->flag == flag;
}
}}
} // namespace fn_001ab5f0

namespace fn_fc09f66d {

// 0x001ab640 hulkfight::scenario::Event_TriggerVolumeNameCondition::vfunc_5 (46 B): matches/0x001ab640.cpp
// sym: ?vfunc_5@Event_TriggerVolumeNameCondition_1ab640@fn_fc09f66d@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
Event_TriggerVolumeNameCondition_1ab640* Event_TriggerVolumeNameCondition_1ab640::vfunc_5(unsigned char param) {
    Event_TriggerVolumeNameCondition_1ab640* p = this;
    *(char**)p = &hulk_at_0041d3cc;
    ((Event_PathNameCondition_nv_1ab640*)(((hulkfight::scenario::Event_PathNameCondition*)(((hulkfight::scenario::Event_PathNameCondition*)((char*)p + 0x10))))))->f1_0027af50();
    ((Event_PathNameCondition_nv_1ab640*)(((hulkfight::scenario::Event_PathNameCondition*)(((hulkfight::scenario::Event_PathNameCondition*)p)))))->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::scenario::Event_PathNameCondition*)p);
    return p;
}


// 0x001ab670 hulkfight::scenario::EventCondition::vfunc_5 (36 B): matches/0x001ab670.cpp
// sym: ?vfunc_5@EventCondition_1ab670@fn_fc09f66d@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
EventCondition_1ab670* EventCondition_1ab670::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041d3ec;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001ab6a0 hulkfight::scenario::Event_FirstTimeCondition::vfunc_5 (36 B): matches/0x001ab6a0.cpp
// sym: ?vfunc_5@Event_FirstTimeCondition_1ab6a0@fn_fc09f66d@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Event_FirstTimeCondition_1ab6a0* Event_FirstTimeCondition_1ab6a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041d40c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001ab6d0 hulkfight::scenario::Event_WaypointCondition::vfunc_5 (36 B): matches/0x001ab6d0.cpp
// sym: ?vfunc_5@Event_WaypointCondition_1ab6d0@fn_fc09f66d@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Event_WaypointCondition_1ab6d0* Event_WaypointCondition_1ab6d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041d42c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001ab700 hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_5 (46 B): matches/0x001ab700.cpp
// sym: ?f2@Event_CharacterTemplateCondition_1ab700@fn_fc09f66d@@QAEPAV12@E@Z
Event_CharacterTemplateCondition_1ab700* Event_CharacterTemplateCondition_1ab700::f2(unsigned char flags) {
    vptr = ((void**)DAT_0041d44c);
    m18.Fini_0027af50();
    Fin_002345b0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x001ab730 hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_5 (46 B): matches/0x001ab730.cpp
// sym: ??0Event_CharacterTemplateVariationCondition@fn_fc09f66d@@QAE@H@Z
Event_CharacterTemplateVariationCondition::Event_CharacterTemplateVariationCondition(int flag) {
    sub.Init_0027af50();
    Finish_002345b0();
    if (flag & 1)
        FUN_0008d330(this);
}


// 0x001ab760 hulkfight::scenario::Event_PathNameCondition::vfunc_5 (46 B): matches/0x001ab760.cpp
// sym: ?vfunc_5@Event_PathNameCondition_1ab760@fn_fc09f66d@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
Event_PathNameCondition_1ab760* Event_PathNameCondition_1ab760::vfunc_5(unsigned char param) {
    Event_PathNameCondition_1ab760* p = this;
    *(char**)p = ((char*)DAT_0041d48c);
    ((Event_PathNameCondition_nv_1ab760*)(((hulkfight::scenario::Event_PathNameCondition*)((char*)p + 0x10))))->f1_0027af50();
    ((Event_PathNameCondition_nv_1ab760*)(((hulkfight::scenario::Event_PathNameCondition*)p)))->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::scenario::Event_PathNameCondition*)p);
    return p;
}

} // namespace fn_fc09f66d

// 0x001ab7c0 fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_7 (6 B): matches/0x001ab7c0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001ab7d0 fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_6 (30 B): matches/0x001ab7d0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1ab7d0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1ab7d0*)&DAT_003f335c));
}


// 0x001ab7f0 fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_8 (26 B): matches/0x001ab7f0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::EventCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::**)(int))&this->f_18))(b);
}


// 0x001ab810 fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_2 (11 B): matches/0x001ab810.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001ab840 fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_6 (26 B): matches/0x001ab840.cpp
// sym: ?vfunc_6@?$ParamBool@VEvent_FirstTimeCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::**)(int))&this->f_10))(b);
}


// 0x001ab860 fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_2 (11 B): matches/0x001ab860.cpp
// sym: ?vfunc_2@?$ParamBool@VEvent_FirstTimeCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001ab8a0 fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_7 (6 B): matches/0x001ab8a0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001ab8b0 fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_6 (30 B): matches/0x001ab8b0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1ab8b0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1ab8b0*)&DAT_003f335c));
}


// 0x001ab8d0 fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_8 (26 B): matches/0x001ab8d0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::**)(int))&this->f_18))(b);
}


// 0x001ab8f0 fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_2 (11 B): matches/0x001ab8f0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001ab920 fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::vfunc_6 (26 B): matches/0x001ab920.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::**)(int))&this->f_10))(b);
}


// 0x001ab940 fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::vfunc_2 (11 B): matches/0x001ab940.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001ab970 fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_6 (26 B): matches/0x001ab970.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::**)(int))&this->f_10))(b);
}


// 0x001ab990 fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_2 (11 B): matches/0x001ab990.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001ab9d0 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_7 (6 B): matches/0x001ab9d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001ab9e0 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_6 (30 B): matches/0x001ab9e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1ab9e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1ab9e0*)&DAT_003f335c));
}


// 0x001aba00 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_8 (26 B): matches/0x001aba00.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::**)(int))&this->f_18))(b);
}


// 0x001aba20 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_2 (11 B): matches/0x001aba20.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001aba50 fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_6 (26 B): matches/0x001aba50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::**)(int))&this->f_10))(b);
}


// 0x001aba70 fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_2 (11 B): matches/0x001aba70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001abab0 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_7 (6 B): matches/0x001abab0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001abac0 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_6 (30 B): matches/0x001abac0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1abac0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1abac0*)&DAT_003f335c));
}


// 0x001abae0 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_8 (26 B): matches/0x001abae0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::**)(int))&this->f_18))(b);
}


// 0x001abb00 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_2 (11 B): matches/0x001abb00.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001abb40 fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_7 (6 B): matches/0x001abb40.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001abb50 fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_6 (30 B): matches/0x001abb50.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1abb50 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1abb50*)&DAT_003f335c));
}


// 0x001abb70 fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_8 (26 B): matches/0x001abb70.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::**)(int))&this->f_18))(b);
}


// 0x001abb90 fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_2 (11 B): matches/0x001abb90.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001abbb0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_0 (36 B): matches/0x001abbb0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_TriggerVolumeNameCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x001abbf0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::EventCondition>::vfunc_0 (36 B): matches/0x001abbf0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEventCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::EventCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c30f8, 0) != 0;
}


// 0x001abc20 fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::vfunc_0 (30 B): matches/0x001abc20.cpp
// sym: ??_G?$ParamEnumConstList@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::EventCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::EventCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abc20)
#endif


// 0x001abc50 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_0 (36 B): matches/0x001abc50.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_FirstTimeCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c31b8, 0) != 0;
}


// 0x001abc80 fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_0 (30 B): matches/0x001abc80.cpp
// sym: ??_G?$ParamBool@VEvent_FirstTimeCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::scenario::Event_FirstTimeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abc80)
#endif


// 0x001abcb0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_0 (36 B): matches/0x001abcb0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3280, 0) != 0;
}


// 0x001abce0 fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::vfunc_0 (30 B): matches/0x001abce0.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abce0)
#endif


// 0x001abd00 fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::vfunc_0 (30 B): matches/0x001abd00.cpp
// sym: ??_G?$ParamIntConstRange@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abd00)
#endif


// 0x001abd30 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_0 (36 B): matches/0x001abd30.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_CharacterTemplateCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3350, 0) != 0;
}


// 0x001abd60 fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_0 (30 B): matches/0x001abd60.cpp
// sym: ??_G?$ParamIntConstRange@VEvent_CharacterTemplateCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abd60)
#endif


// 0x001abd80 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_0 (30 B): matches/0x001abd80.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_CharacterTemplateCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abd80)
#endif


// 0x001abdb0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_0 (36 B): matches/0x001abdb0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_CharacterTemplateVariationCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3430, 0) != 0;
}


// 0x001abde0 fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x001abde0.cpp
// sym: ??_G?$ParamIntConstRange@VEvent_CharacterTemplateVariationCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::scenario::Event_CharacterTemplateVariationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abde0)
#endif


// 0x001abe00 fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x001abe00.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_CharacterTemplateVariationCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_CharacterTemplateVariationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abe00)
#endif


// 0x001abe30 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_0 (36 B): matches/0x001abe30.cpp [wrapped: conflict: DAT_00491ca8; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate; hulkfight::scenario::Event_PathNameCondition]
// sym: ?test@?$ConditionFactoryCasterTemplate@VEvent_PathNameCondition@scenario@hulkfight@fn_001abe30@@@fight@fn_001abe30@@UAEHPAX@Z
namespace fn_001abe30 {
struct Info {
    int DAT_00491ca8;
};
extern Info DAT_00491ca8, DAT_004c3508;
extern int __cdecl FUN_00344e74(void*, int, Info*, Info*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int test(void*);
    virtual void other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int test(void*);
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_PathNameCondition {};
} // namespace scenario
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PathNameCondition>::test(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3508, 0) != 0;
}
} // namespace fn_001abe30


// 0x001abe60 fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::vfunc_0 (30 B): matches/0x001abe60.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_PathNameCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_PathNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1abe60)
#endif

namespace fn_fc09f66d {

// 0x001abe80 FUN_001abe80 (109 B): matches/0x001abe80.cpp
// sym: ?FUN_001abe80@fn_fc09f66d@@YAXXZ
// data: gCount_1abe80 = DAT_004e178c, gSlot_1abe80 = DAT_004e1788, name_1abe80 = DAT_003f8778
void FUN_001abe80() {
    if ((*(int*)&DAT_004e178c) == 0) {
        Obj_1abe80* p;
        Obj_1abe80* q = (Obj_1abe80*)Alloc_0008d690(0x20);
        if (q != 0) {
            q->Init_00234cc0(DAT_003f8778);
            q->v = ((hulk_intptr)DAT_0041d4ac);
            q->a = ((hulk_intptr)((char*)&DAT_004c2a28));
            q->b = 0x1f;
            q->c = ((hulk_intptr)(void (__cdecl*)())&FUN_001aacf0);
            p = q;
        } else {
            p = 0;
        }
        Register_002347b0(((int*)&DAT_004e1788), &p, 1);
    }
    ++(*(int*)&DAT_004e178c);
}


// 0x001ac000 FUN_001ac000 (27 B): matches/0x001ac000.cpp
// sym: ?target@fn_fc09f66d@@YAXPAX@Z
void __cdecl target(void* a) {
    hulk_intptr v = ((hulk_intptr)DAT_0041d5f4);
    Init_002343e0(a, &v);
}


// 0x001ac040 fight::ParamName<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_7 (12 B): matches/0x001ac040.cpp
// sym: ?vfunc_6@ParamBranch@fn_fc09f66d@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fc09f66d

// 0x001ac0f0 fight::ParamName<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_7 (12 B): matches/0x001ac0f0.cpp [wrapped: same definition as 0x001ac040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001ac0f0@@UAEXPAX@Z
namespace fn_001ac0f0 {
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
} // namespace fn_001ac0f0


// 0x001ac140 fight::ParamName<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_7 (12 B): matches/0x001ac140.cpp [wrapped: same definition as 0x001ac040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001ac140@@UAEXPAX@Z
namespace fn_001ac140 {
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
} // namespace fn_001ac140


// 0x001ac190 fight::ParamName<hulkfight::scenario::Event_PathNameCondition>::vfunc_7 (12 B): matches/0x001ac190.cpp [wrapped: same definition as 0x001ac040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001ac190@@UAEXPAX@Z
namespace fn_001ac190 {
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
} // namespace fn_001ac190


// 0x001ac1a0 fight::ParamName<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_0 (30 B): matches/0x001ac1a0.cpp
// sym: ??_G?$ParamName@VEvent_TriggerVolumeNameCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_TriggerVolumeNameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_TriggerVolumeNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ac1a0)
#endif


// 0x001ac1c0 fight::ParamName<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_0 (30 B): matches/0x001ac1c0.cpp
// sym: ??_G?$ParamName@VEvent_CharacterTemplateCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_CharacterTemplateCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_CharacterTemplateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ac1c0)
#endif


// 0x001ac1e0 fight::ParamName<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x001ac1e0.cpp
// sym: ??_G?$ParamName@VEvent_CharacterTemplateVariationCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_CharacterTemplateVariationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ac1e0)
#endif


// 0x001ac200 fight::ParamName<hulkfight::scenario::Event_PathNameCondition>::vfunc_0 (30 B): matches/0x001ac200.cpp
// sym: ??_G?$ParamName@VEvent_PathNameCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_PathNameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_PathNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ac200)
#endif

namespace fn_fc09f66d {

// 0x001ac220 FUN_001ac220 (38 B): matches/0x001ac220.cpp
// sym: _FUN_001ac220
extern "C" void FUN_001ac220(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_1ac220 c;
    owner->Apply_00236760(FUN_002343e0(name, &c));
}


// 0x001ac2b0 FUN_001ac2b0 (38 B): matches/0x001ac2b0.cpp
// sym: _FUN_001ac2b0
extern "C" void FUN_001ac2b0(Arg* obj, void* key) {
    ConditionFactoryCasterTemplate_1ac2b0 caster;
    void* result = Search_002343e0(key, &caster);
    obj->Do_00236760(result);
}


// 0x001ac2e0 FUN_001ac2e0 (38 B): matches/0x001ac2e0.cpp
// sym: _FUN_001ac2e0
extern "C" void FUN_001ac2e0(Owner* owner, int id) {
    ConditionFactoryCasterTemplate_1ac2e0 c;
    owner->Apply_00236760(FUN_002343e0(id, &c));
}


// 0x001ac310 FUN_001ac310 (38 B): matches/0x001ac310.cpp
// sym: _FUN_001ac310
extern "C" void FUN_001ac310(Obj* obj, void* arg) {
    ConditionFactoryCasterTemplate_1ac310 c;
    obj->apply_00236760(find(arg, &c));
}

} // namespace fn_fc09f66d

// 0x001ac340 FUN_001ac340 (38 B): matches/0x001ac340.cpp [wrapped: conflict: find]
// sym: _FUN_001ac340
namespace fn_001ac340 {
class ConditionFactoryCasterTemplate_1ac340 {
  public:
    virtual bool cast_001abd30(void*);
};
class Factory {
  public:
    void apply_00236760(void*);
};
void* __cdecl find_002343e0(void*, ConditionFactoryCasterTemplate_1ac340*);
extern "C" void __cdecl FUN_001ac340(Factory* f, void* name) {
    ConditionFactoryCasterTemplate_1ac340 caster;
    f->apply_00236760(find_002343e0(name, &caster));
}
} // namespace fn_001ac340

namespace fn_fc09f66d {

// 0x001ac460 FUN_001ac460 (38 B): matches/0x001ac460.cpp
// sym: _FUN_001ac460
extern "C" void __cdecl FUN_001ac460(Obj* obj, const char* name) {
    ConditionFactoryCasterTemplate_1ac460 caster;
    obj->set_00236760(lookup_002343e0(name, &caster));
}


// 0x001ac580 FUN_001ac580 (38 B): matches/0x001ac580.cpp
// sym: _FUN_001ac580
extern "C" void __cdecl FUN_001ac580(Target* obj, const char* name) {
    ConditionFactoryCasterTemplate_1ac580 caster;
    obj->Apply_00236760(Resolve_002343e0(name, &caster));
}

} // namespace fn_fc09f66d

// 0x001ac6a0 fight::ConditionFactoryTemplate<hulkfight::scenario::EventCondition>::vfunc_5 (47 B): matches/0x001ac6a0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEventCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::EventCondition>::vfunc_5() {
    Obj_1ac6a0* p = (Obj_1ac6a0*)Alloc_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        p->vt = ((hulk_intptr)DAT_0041d3ec);
        p->value = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc09f66d {

// 0x001ac6d0 fight::ConditionFactoryTemplate<hulkfight::scenario::EventCondition>::vfunc_2 (43 B): matches/0x001ac6d0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1ac6d0@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1ac6d0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d710;
    base1_dtor_001aae30();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d

// 0x001ac740 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_5 (44 B): matches/0x001ac740.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_FirstTimeCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_5() {
    Event_1ac740* p = (Event_1ac740*)Alloc_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        *(void**)p = (void*)((hulk_intptr)DAT_0041d40c);
        *((unsigned char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc09f66d {

// 0x001ac770 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_FirstTimeCondition>::vfunc_2 (43 B): matches/0x001ac770.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1ac770@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1ac770::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d72c;
    base1_dtor_001aae90();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d

// 0x001ac7e0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_5 (54 B): matches/0x001ac7e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_WaypointCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_5() {
    WaypointCondition* p = (WaypointCondition*)Allocate_0008d690(0x14);
    if (p) {
        p->Init_00234590(0);
        *(void**)p = VT_1ac7e0;
        p->m0 = 0;
        p->m1 = -1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc09f66d {

// 0x001ac820 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_2 (43 B): matches/0x001ac820.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1ac820@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1ac820::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d748;
    base1_dtor_001aaef0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d

// 0x001ac890 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_5 (48 B): matches/0x001ac890.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_TriggerVolumeNameCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_5() {
    Event_TriggerVolumeNameCondition_1ac890* p = (Event_TriggerVolumeNameCondition_1ac890*)Allocate_0008d690(0x18);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041d3cc);
        p->sub.Init_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc09f66d {

// 0x001ac8c0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_2 (43 B): matches/0x001ac8c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1ac8c0@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1ac8c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d764;
    base1_dtor_001aadc0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d

// 0x001ac930 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_5 (62 B): matches/0x001ac930.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_CharacterTemplateCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_5() {
    Condition_1ac930* p = (Condition_1ac930*)Allocate_0008d690(0x20);
    if (p) {
        ((Initializer_1ac930*)p)->Init_00234590(0);
        p->vf = ((hulk_intptr)DAT_0041d44c);
        p->x = 2;
        p->y = 0;
        ((OffsetInitializer*)((char*)p + 0x18))->Init_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc09f66d {

// 0x001ac970 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_2 (43 B): matches/0x001ac970.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1ac970@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1ac970::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d780;
    base1_dtor_001aaf60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d

// 0x001ac9e0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_5 (62 B): matches/0x001ac9e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_CharacterTemplateVariationCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_5() {
    return (void*)(new Cond);
}

namespace fn_fc09f66d {

// 0x001aca20 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateVariationCondition>::vfunc_2 (43 B): matches/0x001aca20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aca20@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aca20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d79c;
    base1_dtor_001aafe0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d

// 0x001aca90 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_5 (55 B): matches/0x001aca90.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_PathNameCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_5() {
    Thing_1aca90* p = (Thing_1aca90*)Allocate_0008d690(24);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041d48c);
        *(unsigned int*)((char*)p + 12) = 0;
        ((Sub_1aca90*)((char*)p + 16))->Finish_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc09f66d {

// 0x001acad0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PathNameCondition>::vfunc_2 (43 B): matches/0x001acad0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1acad0@fn_fc09f66d@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1acad0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d7b8;
    base1_dtor_001ab060();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc09f66d
