// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00168380..0x001692c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f665a2ac {
#define TREE_TU_END }
namespace fn_f665a2ac {} using namespace fn_f665a2ac;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f665a2ac {
extern int DAT_00494b44;
extern int DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" bool __cdecl FUN_00018960(float,float,float);
struct Speed_168380 { hulk_freg FUN_00035700(); };
struct Motion_168380 { Speed_168380* FUN_00059a30(); };
struct Actor_168380 {  };
struct Vec_168480 { float x,y,z; };
struct Motion_168480 {  void FUN_00035550(Vec_168480*); };
struct Controller_168480 { Motion_168480* FUN_00059a30(); };
struct Actor_168480 {  };
extern "C" hulk_freg __cdecl FUN_00224f10(Vec_168480*);
extern "C" hulk_freg __cdecl FUN_00224fc0(float,float);
struct Object {
 char padding[0x1b0c];
 float value;
 float third;
 hulk_freg FUN_000360b0();
 float FUN_00036090();
};
struct Health { char pad[0x1b0c]; float current; float maximum; };
struct Target_168b30 { char pad[8]; Health* health; int kind; };
struct Actor_168b30 { char pad[0x328]; Target_168b30* target; };
struct ContextActor { Actor_168b30* FUN_00059a30(); };
struct Context_168b30 {  };
struct CAxisArcCondition_168ca0;
class CStageCondition_168cb0 {};
class ParamValue_168cb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_168cb0 : public ParamValue_168cb0 {
  public:
    virtual void f();
};
class CStageCondition_168d40;
class ParamValue_168d40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_168d40 : public ParamValue_168d40 {
  public:
    int pad;
};
struct CAxisArcCondition_168d80;
class CStageCondition_168d90 {};
class ParamValue_168d90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_168d90 : public ParamValue_168d90 {
  public:
    virtual void f();
};
class CStageCondition_168e20;
class ParamValue_168e20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_168e20 : public ParamValue_168e20 {
  public:
    int pad;
};
struct CAxisArcCondition_168e60;
class CStageCondition_168e70 {};
class ParamValue_168e70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_168e70 : public ParamValue_168e70 {
  public:
    virtual void f();
};
class CStageCondition_168f00;
class ParamValue_168f00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_168f00 : public ParamValue_168f00 {
  public:
    int pad;
};
struct CAxisArcCondition_168f40;
class CStageCondition_168f50 {};
class ParamValue_168f50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_168f50 : public ParamValue_168f50 {
  public:
    virtual void f();
};
class CStageCondition_168fe0;
class ParamValue_168fe0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_168fe0 : public ParamValue_168fe0 {
  public:
    int pad;
};
struct CAxisArcCondition_169020;
class CStageCondition_169030 {};
class ParamValue_169030 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169030 : public ParamValue_169030 {
  public:
    virtual void f();
};
class CStageCondition_1690c0;
class ParamValue_1690c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1690c0 : public ParamValue_1690c0 {
  public:
    int pad;
};
class CStageCondition_169110;
class ParamValue_169110 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169110 : public ParamValue_169110 {
  public:
    int pad;
};
class CStageCondition_169160;
class ParamValue_169160 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169160 : public ParamValue_169160 {
  public:
    int pad;
};
class CStageCondition_1691b0;
class ParamValue_1691b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1691b0 : public ParamValue_1691b0 {
  public:
    int pad;
};
struct CAxisArcCondition_1691f0;
class CStageCondition_169200 {};
class ParamValue_169200 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169200 : public ParamValue_169200 {
  public:
    virtual void f();
};
class CStageCondition_169290;
class ParamValue_169290 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169290 : public ParamValue_169290 {
  public:
    int pad;
};

} // namespace fn_f665a2ac

// 0x00168380 hulkfight::motion::VelocityAnimatedXZCondition::vfunc_6 (232 B): equivalent/0x00168380.cpp
// sym: ?vfunc_6@VelocityAnimatedXZCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityAnimatedXZCondition::vfunc_6 @ 0x00168380
bool hulkfight::motion::VelocityAnimatedXZCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_168380 * actor = (Actor_168380 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float speed=((Motion_168380 *)((owners::Object_592a0 *)actor)->FUN_000592a0())->FUN_00059a30()->FUN_00035700();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0:return speed<this->f_10;
 case 1:return speed<=this->f_10;
 case 2:return FUN_00018960(speed,this->f_10,0.00001f);
 case 3:return !FUN_00018960(speed,this->f_10,0.00001f);
 case 4:return speed>=this->f_10;
 case 5:return speed>this->f_10;
 }
 return false;
}


// 0x00168480 hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_6 (254 B): equivalent/0x00168480.cpp
// sym: ?vfunc_6@VelocityAnimatedXZAngleCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_6 @ 0x00168480
bool hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_168480 * actor = (Actor_168480 *)__p1;

if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Motion_168480* m=((Controller_168480 *)((owners::Object_592a0 *)actor)->FUN_000592a0())->FUN_00059a30();
Vec_168480 a; a.x=a.y=a.z=0.0f; ((owners::Thing_356c0 *)m)->FUN_000356c0((unsigned int *)(Vec_168480 *)(&a));
float first=FUN_00224f10(&a);
Vec_168480 b; b.x=b.y=b.z=0.0f; m->FUN_00035550(&b);
float second=FUN_00224f10(&b);
float delta=FUN_00224fc0(second,first);
float difference=FUN_00224fc0(delta,this->f_0c);
union { float f; unsigned int u; } absval; absval.f=difference; absval.u &= 0x7fffffff;
return this->f_10*0.5f > absval.f;
}


// 0x00168580 hulkfight::motion::ChargeCondition::vfunc_6 (250 B): equivalent/0x00168580.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::motion::ChargeCondition]
// sym: ?vfunc_6@ChargeCondition@motion@hulkfight@fn_00168580@@UAE_NPAXPAUActor_168580@4@0@Z
namespace fn_00168580 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::ChargeCondition::vfunc_6 @ 0x00168580
extern "C" { extern "C++" { extern char DAT_00494b44; } extern "C++" { extern char DAT_00494b60; } void* __cdecl FUN_00344e74(void*, int, void*, void*, int); bool __cdecl FUN_00018960(float,float,float); }
struct State_168580 { char pad[0x1e58]; float charge; int kind; };
struct Intermediate_168580 { State_168580* FUN_00059a30(); };
struct Actor_168580 { Intermediate_168580* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct ChargeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_168580*, void*);
 char pad[8]; unsigned operation; float threshold; int kind;
};
bool ChargeCondition::vfunc_6(void*, Actor_168580* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_168580* state=actor->FUN_000592a0()->FUN_00059a30();
 float value=state->charge;
 if (kind!=state->kind) value=0.0f;
 switch(operation) {
 case 0: return value<threshold;
 case 1: return value<=threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value>=threshold;
 case 5: return value>threshold;
 default: return false;
 }
}
} }
} // namespace fn_00168580


// 0x001686a0 hulkfight::motion::TurningVelocityCondition::vfunc_6 (231 B): equivalent/0x001686a0.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::motion::TurningVelocityCondition]
// sym: ?vfunc_6@TurningVelocityCondition@motion@hulkfight@fn_001686a0@@UAE_NPAXPAUActor_1686a0@4@0@Z
namespace fn_001686a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::TurningVelocityCondition::vfunc_6 @ 0x001686a0
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" bool __cdecl FUN_00018960(float, float, float);
struct Velocity_1686a0 { char pad[0x8c]; float turning; };
struct State_1686a0 { Velocity_1686a0* FUN_00059a30(); };
struct Actor_1686a0 { State_1686a0* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct TurningVelocityCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Actor_1686a0*, void*);
 char pad[8]; unsigned operation; float threshold;
};
bool TurningVelocityCondition::vfunc_6(void*, Actor_1686a0* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float value = actor->FUN_000592a0()->FUN_00059a30()->turning;
 switch(operation) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value,threshold,0.00001f);
 case 3: return !FUN_00018960(value,threshold,0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}
}}
} // namespace fn_001686a0

namespace fn_f665a2ac {

// 0x001687a0 FUN_001687a0 (228 B): equivalent/0x001687a0.cpp
// sym: ?target@fn_f665a2ac@@YA_NPAUObject@1@IHM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_001687a0 @ 0x001687a0
// equiv-conv: target ecx esi stack stack
bool __cdecl target(Object* object, unsigned comparison, int source, float scale) {
 if (!object) return false;
 float value = object->value;
 float base;
 switch(source) {
 case 1: base = object->FUN_00036090(); break;
 case 2: base = object->FUN_000360b0(); break;
 case 3: base = object->third; break;
 default: base = 1.0f; break;
 }
 float threshold = base * scale;
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value, threshold, 0.00001f);
 case 3: return !FUN_00018960(value, threshold, 0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}

} // namespace fn_f665a2ac

// 0x001688a0 hulkfight::motion::HealthCondition::vfunc_6 (82 B): equivalent/0x001688a0.cpp [wrapped: conflict: hulkfight::motion::HealthCondition]
// sym: ?vfunc_6@HealthCondition@motion@hulkfight@fn_001688a0@@QAEHHPAUFightObject@4@H@Z
namespace fn_001688a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// hulkfight::motion::HealthCondition::vfunc_6 @ 0x001688a0
struct FightObject { void* FUN_000592a0(); }; 
struct Fighter { void* FUN_00059a30(); };
extern int DAT_00494b44;
extern int DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, int*, int*, int);
// equiv-conv: FUN_001687a0 ecx esi stack stack
extern int __cdecl FUN_001687a0(void*, void*, int, int);
namespace hulkfight { namespace motion {
struct HealthCondition {
    char pad[12];
    void* context;
    int first;
    int second;
    int vfunc_6(int, FightObject*, int);
};
int HealthCondition::vfunc_6(int unused, FightObject* object, int unused2) {
    if (!FUN_00344e74(object, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 0;
    Fighter* fighter = (Fighter*)object->FUN_000592a0();
    void* value = fighter->FUN_00059a30();
    return FUN_001687a0(value, context, second, first);
}
}}
} // namespace fn_001688a0


// 0x00168900 hulkfight::motion::GrappleHealthCondition::vfunc_6 (38 B): equivalent/0x00168900.cpp [wrapped: conflict: hulkfight::motion::GrappleHealthCondition]
// sym: ?vfunc_6@GrappleHealthCondition@motion@hulkfight@fn_00168900@@UAEHPAX00@Z
namespace fn_00168900 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// hulkfight::motion::GrappleHealthCondition::vfunc_6 @ 0x00168900
// hulkfight::motion::GrappleHealthCondition::vfunc_6 @ 0x00168900
namespace hulkfight { namespace motion {
struct GrappleHealthCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6(void*, void*, void*);
    char padding[8];
    int field_c;
    int field_10;
    int field_14;
};
}}
struct GrappleTarget;
extern "C" GrappleTarget* __cdecl FUN_00048260(void*);
// equiv-conv: FUN_001687a0 ecx esi stack stack
int __cdecl FUN_001687a0(GrappleTarget*, int, int, int);
int hulkfight::motion::GrappleHealthCondition::vfunc_6(void* arg1, void* arg2, void* arg3) {
    GrappleTarget* target = FUN_00048260(arg2);
    return FUN_001687a0(target, field_c, field_14, field_10);
}
} // namespace fn_00168900


// 0x00168930 hulkfight::motion::HealthPercentCondition::vfunc_6 (290 B): equivalent/0x00168930.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::motion::HealthPercentCondition]
// sym: ?vfunc_6@HealthPercentCondition@motion@hulkfight@fn_00168930@@UAE_NPAXPAUActor_168930@4@0@Z
namespace fn_00168930 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::HealthPercentCondition::vfunc_6 @ 0x00168930
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" bool __cdecl FUN_00018960(float, float, float);
struct Health { char pad[0x1b0c]; float current; float maximum; };
struct Component_168930 { Health* FUN_00059a30(); };
struct Actor_168930 { Component_168930* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct HealthPercentCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_168930*, void*);
char pad[8]; unsigned comparison; float threshold;
};
bool HealthPercentCondition::vfunc_6(void*, Actor_168930* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Health* health = actor->FUN_000592a0()->FUN_00059a30();
 union { float f; unsigned bits; } magnitude;
 magnitude.f = health->maximum; magnitude.bits &= 0x7fffffff;
 float percent = 0.0f;
 if (!(magnitude.f < 1e-5f)) percent = (health->current / health->maximum) * 100.0f;
 switch(comparison) {
 case 0: return percent < threshold;
 case 1: return percent <= threshold;
 case 2: return FUN_00018960(percent,threshold,1e-5f);
 case 3: return !FUN_00018960(percent,threshold,1e-5f);
 case 4: return percent >= threshold;
 case 5: return percent > threshold;
 default: return false;
 }
}
}}
} // namespace fn_00168930


// 0x00168b30 hulkfight::motion::TargetHealthPercentCondition::vfunc_6 (285 B): equivalent/0x00168b30.cpp
// sym: ?vfunc_6@TargetHealthPercentCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 19/22, incomplete)
// hulkfight::motion::TargetHealthPercentCondition::vfunc_6 @ 0x00168b30
bool hulkfight::motion::TargetHealthPercentCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Context_168b30 * context = (Context_168b30 *)__p1;

 Target_168b30* target = ((ContextActor *)((owners::Object_592a0 *)context)->FUN_000592a0())->FUN_00059a30()->target;
 if (!target || !target->health || target->kind != 1) return false;
 float maximum = target->health->maximum;
 union { float f; unsigned u; } magnitude;
 magnitude.f = maximum; magnitude.u &= 0x7fffffff;
 float percent;
 if (magnitude.f < 1e-05f) percent = 0.0f;
 else percent = (target->health->current / maximum) * 100.0f;
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return percent < this->f_10;
 case 1: return percent <= this->f_10;
 case 2: return FUN_00018960(percent, this->f_10, 1e-05f);
 case 3: return !FUN_00018960(percent, this->f_10, 1e-05f);
 case 4: return percent >= this->f_10;
 case 5: return percent > this->f_10;
 default: return false;
 }
}


// 0x00168ca0 fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_7 (6 B): matches/0x00168ca0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00168cb0 fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_6 (30 B): matches/0x00168cb0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_168cb0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_168cb0*)&DAT_003f335c));
}


// 0x00168cd0 fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_8 (26 B): matches/0x00168cd0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::**)(int))&this->f_18))(b);
}


// 0x00168cf0 fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_2 (11 B): matches/0x00168cf0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00168d20 fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::vfunc_6 (26 B): matches/0x00168d20.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::**)(int))&this->f_10))(b);
}


// 0x00168d40 fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::vfunc_2 (11 B): matches/0x00168d40.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00168d80 fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_7 (6 B): matches/0x00168d80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00168d90 fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_6 (30 B): matches/0x00168d90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_168d90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_168d90*)&DAT_003f335c));
}


// 0x00168db0 fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_8 (26 B): matches/0x00168db0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::**)(int))&this->f_18))(b);
}


// 0x00168dd0 fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_2 (11 B): matches/0x00168dd0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00168e00 fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_6 (26 B): matches/0x00168e00.cpp
// sym: ?vfunc_6@?$ParamBool@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::**)(int))&this->f_10))(b);
}


// 0x00168e20 fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_2 (11 B): matches/0x00168e20.cpp
// sym: ?vfunc_2@?$ParamBool@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00168e60 fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_7 (6 B): matches/0x00168e60.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00168e70 fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_6 (30 B): matches/0x00168e70.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_168e70 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_168e70*)&DAT_003f335c));
}


// 0x00168e90 fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_8 (26 B): matches/0x00168e90.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::**)(int))&this->f_18))(b);
}


// 0x00168eb0 fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_2 (11 B): matches/0x00168eb0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00168ee0 fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::vfunc_6 (26 B): matches/0x00168ee0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::**)(int))&this->f_10))(b);
}


// 0x00168f00 fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::vfunc_2 (11 B): matches/0x00168f00.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00168f40 fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_7 (6 B): matches/0x00168f40.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00168f50 fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_6 (30 B): matches/0x00168f50.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_168f50 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_168f50*)&DAT_003f335c));
}


// 0x00168f70 fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_8 (26 B): matches/0x00168f70.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::**)(int))&this->f_18))(b);
}


// 0x00168f90 fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_2 (11 B): matches/0x00168f90.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00168fc0 fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::vfunc_6 (26 B): matches/0x00168fc0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::**)(int))&this->f_10))(b);
}


// 0x00168fe0 fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::vfunc_2 (11 B): matches/0x00168fe0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169020 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_7 (6 B): matches/0x00169020.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169030 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_6 (30 B): matches/0x00169030.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169030 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169030*)&DAT_003f335c));
}


// 0x00169050 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_8 (26 B): matches/0x00169050.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::**)(int))&this->f_18))(b);
}


// 0x00169070 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_2 (11 B): matches/0x00169070.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001690a0 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_6 (26 B): matches/0x001690a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::**)(int))&this->f_10))(b);
}


// 0x001690c0 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_2 (11 B): matches/0x001690c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001690f0 fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::vfunc_6 (26 B): matches/0x001690f0.cpp
// sym: ?vfunc_6@?$ParamVector@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::RayCastTargetCondition>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x00169110 fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::vfunc_2 (11 B): matches/0x00169110.cpp
// sym: ?vfunc_2@?$ParamVector@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169140 fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_6 (26 B): matches/0x00169140.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x00169160 fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_2 (11 B): matches/0x00169160.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169190 fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::vfunc_6 (26 B): matches/0x00169190.cpp
// sym: ?vfunc_6@?$ParamBool@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::RayCastTargetCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x001691b0 fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::vfunc_2 (11 B): matches/0x001691b0.cpp
// sym: ?vfunc_2@?$ParamBool@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001691f0 fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_7 (6 B): matches/0x001691f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169200 fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_6 (30 B): matches/0x00169200.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169200 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169200*)&DAT_003f335c));
}


// 0x00169220 fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_8 (26 B): matches/0x00169220.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::**)(int))&this->f_18))(b);
}


// 0x00169240 fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_2 (11 B): matches/0x00169240.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169270 fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::vfunc_6 (26 B): matches/0x00169270.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::**)(int))&this->f_10))(b);
}


// 0x00169290 fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::vfunc_2 (11 B): matches/0x00169290.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::vfunc_2() {
    return this->f_10 == 0;
}

