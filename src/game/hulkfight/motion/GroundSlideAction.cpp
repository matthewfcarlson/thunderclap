// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001508d0..0x00152930 (kind game, layer game, confidence high), dominant class hulkfight::motion::GroundSlideAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f20ed7e3 {
#define TREE_TU_END }
namespace fn_f20ed7e3 {} using namespace fn_f20ed7e3;
namespace fn_f20ed7e3 { extern "C" char DAT_00414580[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f20ed7e3 {
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" bool __cdecl FUN_00018960(float,float,float);
struct Force { char pad[0x38]; float x,y,z; };
struct Source_150a10 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Force* slot3(); };
struct Member_150d80;
} // namespace fn_f20ed7e3
namespace fight {
class Params_150d80 {
public:
    virtual void vfunc_0();
    virtual Params_150d80 *vfunc_1();
    virtual Params_150d80 *vfunc_2();
    virtual Member_150d80 *vfunc_3();
};
}
namespace fn_f20ed7e3 {
class CFightParams_150d80 : public fight::Params_150d80 {
public:
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct Member_150d80 {
    char pad0[0x78];
    float value;
};
struct Context_150d80 {
    char pad[4];
};
struct Actor_150d80 {
    char pad0[0x1b0c];
    float maxValue;
    float scale;
};
Context_150d80 *__fastcall FUN_000592a0(void *obj);
Actor_150d80 *__fastcall FUN_00059a30(Context_150d80 *ctx);
class RefObj_150fd0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_150fd0 {
  public:
    Action_150fd0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class InterruptAccumulatorSetAction_150fd0 : public Action_150fd0 {
  public:
    int mTarget;
    RefObj_150fd0* mObj;
    InterruptAccumulatorSetAction_150fd0(int target, RefObj_150fd0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00414510[];
class Ref_151020 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151020 {
  public:
    void* vptr;
};
class InterruptAccumulatorSetAction_151020 : public Action_151020 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151020* m20;
    ~InterruptAccumulatorSetAction_151020();
};
class RefObj_151060 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_151060 {
  public:
    Action_151060();
    virtual void Update_00018b30();
    char pad[0x18];
};
class InterruptPriorityAction_151060 : public Action_151060 {
  public:
    int mTarget;
    RefObj_151060* mObj;
    InterruptPriorityAction_151060(int target, RefObj_151060* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_0041452c[];
class Ref_1510b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1510b0 {
  public:
    void* vptr;
};
class InterruptPriorityAction_1510b0 : public Action_1510b0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1510b0* m20;
    ~InterruptPriorityAction_1510b0();
};
class RefCounted_1510f0 {
  public:
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};
class Action_1510f0 {
  public:
    Action_1510f0();
    virtual void BaseVirtual_00018b30();
    char pad[0x18];
};
class HitWaitAction : public Action_1510f0 {
  public:
    HitWaitAction(void* a, RefCounted_1510f0* b);
    virtual void V1_00018b40();
    void* mA;
    RefCounted_1510f0* mB;
    int mC;
};
extern void* hulk_at_00414548[];
class Ref_151140 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151140 {
  public:
    void* vptr;
};
class HitWaitAction_151140 : public Action_151140 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151140* m20;
    ~HitWaitAction_151140();
};
class Obj_151180 {
  public:
    virtual void A();
    virtual void B();
};
class Action_151180 {
  public:
    virtual void FnX_00018b30();
    Action_151180();
};
class GroundSlideAction_151180 : public Action_151180 {
  public:
    virtual void FnA_00018b40();
    virtual void* FnB_00156e80(char);
    char pad[0x18];
    int m1c;
    Obj_151180* m20;
    int m24;
    int m28;
    GroundSlideAction_151180(int, Obj_151180*);
};
extern void* hulk_at_00414564[];
class Ref_1511d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1511d0 {
  public:
    void* vptr;
};
class GroundSlideAction_1511d0 : public Action_1511d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1511d0* m20;
    Ref_1511d0* m24;
    ~GroundSlideAction_1511d0();
};
struct V3_151220 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Name_151220 {
    unsigned int lo, hi;
};
struct Xform_151220 {
    char data[0x54];
    void FUN_00221d20(float a);
};
hulk_freg FUN_00224f10(V3_151220* v);
class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_151220 name;
    char pad10[8];
    Xform_151220 xform;
    JointDriver* FUN_002248f0(int a);
};
struct Timing_151220 {
};
struct Skeleton {
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock_151220 {
    Timing_151220* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target_151220 {
};
struct Config_151220 {
    char pad0[0x14];
    float angleOffset;
    char pad18[0x20 - 0x18];
    float minSpeed;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
};
class GroundSlideAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_151220* cfg;
    Target_151220* target;
    JointDriver* driver;
    float speed;
};
class RefObj_151720 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_151720 {
  public:
    Action_151720();
    virtual void Update_00018b30();
    char pad[0x18];
};
class HitPauseAction_151720 : public Action_151720 {
  public:
    int mTarget;
    RefObj_151720* mObj;
    HitPauseAction_151720(int target, RefObj_151720* obj);
    virtual void Execute_00018b40();
};
class Ref_151770 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151770 {
  public:
    void* vptr;
};
class HitPauseAction_151770 : public Action_151770 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_151770* m20;
    ~HitPauseAction_151770();
};
class Ref_1517b0 {
  public:
    virtual void F();
    virtual void G();
};
class Action_1517b0 {
  public:
    virtual void FnV_00018b30();
    Action_1517b0();
};
class Sub_1517b0 {
  public:
    Sub_1517b0();
    char pad[0x28];
};
class HitReactionAction_1517b0 : public Action_1517b0 {
  public:
    char pad[0x18];
    int* mA;
    Ref_1517b0* mB;
    Sub_1517b0 sub;
    int x;
    int y;
    unsigned char z;
    HitReactionAction_1517b0(int* a, Ref_1517b0* b);
};
extern void* hulk_at_0041459c[];
class Ref_151810 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_151810 {
  public:
    void Fn_002325f0();
};
struct GroundSlideAction_nv_151810 {
    void Fn_002326a0();
};
class HitReactionAction_151810 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_151810* m20;
    Sub_151810 m24;
    char p28[0x24];
    Ref_151810* m4c;
    void f();
};
struct Obj_151860 {
    virtual void V0();
    virtual void V1();
};
struct Sub_151860 {
    Obj_151860* obj;
    void Init_002322f0(int, int);
    void Set_00231f20(int);
    void Stop();
    void Start_002324b0(int);
    int End_00231ee0();
};
struct C3_151860 {
    void f();
};
struct C2_151860 {
    C3_151860* Fnf_00035cd0();
};
struct C1_151860 {
    C2_151860* Fnf_00059a30();
};
struct C0_151860 {
    C1_151860* Fnf_000592a0();
};
struct HitReactionAction {
    char p0[0x20];
    C0_151860* m20;
    Sub_151860 sub;
    char p28[0x24];
    Obj_151860* m4c;
    int m50;
    char m54;
    int vfunc_5(int b, int a);
};
class Ref_1518f0 {
  public:
    virtual void F();
    virtual void G();
};
class Action_1518f0 {
  public:
    virtual void FnV_00018b30();
    Action_1518f0();
};
class Sub_1518f0 {
  public:
    Sub_1518f0();
    char pad[0x28];
};
class HitReactionFloatAction_1518f0 : public Action_1518f0 {
  public:
    char pad[0x18];
    int* mA;
    Ref_1518f0* mB;
    Sub_1518f0 sub;
    int x;
    int y;
    unsigned char z;
    HitReactionFloatAction_1518f0(int* a, Ref_1518f0* b);
};
struct VObj_151950 {
    virtual void v0();
    virtual void v1();
};
struct Sub_151950 {
    void release_002325f0();
};
extern int hulk_at_004145b8;
class HitReactionFloatAction_151950 {
  public:
    void destroy();
    char pad0[0x1c];
    void* m1c;
    VObj_151950* m20;
    char pad1[0x28];
    VObj_151950* m4c;
};
class Ref_1519a0 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Fighter_1519a0 {
public:
    void FUN_00035cd0();
};
class FighterRef_1519a0 {
public:
    Fighter_1519a0* FUN_00059a30();
};
class Owner_1519a0 {
public:
    FighterRef_1519a0* FUN_000592a0();
};
class Track {
public:
    Ref_1519a0* current;
    char pad4[0x24];

    void FUN_002322f0(int count, int arg);
    void FUN_00231f20(int step);
    void FUN_002324b0(int flag);
    int FUN_00231ee0();
};
class HitReactionFloatAction {
public:
    char pad0[0x20];
    Owner_1519a0* owner;
    Track track;
    Ref_1519a0* previous;
    int stepCount;
    char started;

    int FUN_001519a0(int step, int arg);
};
class RefObj_151a30 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_151a30 {
  public:
    Action_151a30();
    virtual void Update_00018b30();
    char pad[0x18];
};
class HitPushbackAddAction_151a30 : public Action_151a30 {
  public:
    int mTarget;
    RefObj_151a30* mObj;
    HitPushbackAddAction_151a30(int target, RefObj_151a30* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004145d4[];
class Ref_151a80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151a80 {
  public:
    void* vptr;
};
class HitPushbackAddAction_151a80 : public Action_151a80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151a80* m20;
    ~HitPushbackAddAction_151a80();
};
class Obj_151ac0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Obj_151ac0* get();
    void* helper1_000592a0();
    Obj_151ac0* helper2_00059a30();
    void send_00035810(void*, float*);
};
class RefObj_151b30 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_151b30 {
  public:
    Action_151b30();
    virtual void Update_00018b30();
    char pad[0x18];
};
class NoHitPushbackAction_151b30 : public Action_151b30 {
  public:
    int mTarget;
    RefObj_151b30* mObj;
    NoHitPushbackAction_151b30(int target, RefObj_151b30* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004145f0[];
class Ref_151b80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151b80 {
  public:
    void* vptr;
};
class NoHitPushbackAction_151b80 : public Action_151b80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151b80* m20;
    ~NoHitPushbackAction_151b80();
};
extern "C" char DAT_0041460c[];
class Obj_151bc0 {
  public:
    virtual void F();
    virtual void G();
};
class HitPushbackAction_151bc0 : public Ctor_00232660 {
  public:
    volatile hulk_intptr v;
    char pad[0x18];
    volatile int a;
    Obj_151bc0* b;
    char gap[0x1c];
    HitPushbackAction_151bc0(int p, Obj_151bc0* q);
};
extern void* hulk_at_0041460c[];
class Ref_151c20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151c20 {
  public:
    void* vptr;
};
class HitPushbackAction_151c20 : public Action_151c20 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_151c20* m20;
    Ref_151c20* m24;
    ~HitPushbackAction_151c20();
};
struct V3_151c70 { float x, y, z; };
struct Mover_151c70 {
    char pad[0x24];
    float scale24;
};
struct Sub18_151c70 {
    hulk_freg FUN_002220d0();
    void FUN_00221d20(float f);
};
struct Target24 {
    char pad[0x18];
    Sub18_151c70 sub;
};
struct Q_151c70 {  };
struct P_151c70 {
    Q_151c70* FUN_00059a30();
    bool FUN_00059a50(V3_151c70* out);
};
struct Obj20_151c70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
class HitPushbackAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Mover_151c70* owner;
    Obj20_151c70* obj;
    Target24* target;
    float timer;
    V3_151c70 dir;
    float speed;
    float accel;
    float spd40;
};
class Action_151de0 {
  public:
    Action_151de0();
    virtual void f();
    char pad[24];
};
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
struct Value {
    volatile int v;
    Value() : v(0) {}
    void Set(int x) { v = x; }
};
class HitFloatAction : public Action_151de0 {
  public:
    HitFloatAction(int, Ref*);
    virtual void f();
    Value a;
    Ref* b;
    int c, d, e, f0, g;
};
extern void* hulk_at_00414628[];
class Ref_151e40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151e40 {
  public:
    void* vptr;
};
class HitFloatAction_151e40 : public Action_151e40 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151e40* m20;
    Ref_151e40* m24;
    ~HitFloatAction_151e40();
};
class RefObj_151e90 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_151e90 {
  public:
    Action_151e90();
    virtual void Update_00018b30();
    char pad[0x18];
};
class HitDamageAction_151e90 : public Action_151e90 {
  public:
    int mTarget;
    RefObj_151e90* mObj;
    HitDamageAction_151e90(int target, RefObj_151e90* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00414644[];
class Ref_151ee0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151ee0 {
  public:
    void* vptr;
};
class HitDamageAction_151ee0 : public Action_151ee0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151ee0* m20;
    ~HitDamageAction_151ee0();
};
class Thing_151f20 {
  public:
    virtual void A();
    virtual void B();
};
class Action_151f20 {
  public:
    Action_151f20();
    virtual void FnX_00018b30();
    virtual void FnY_00018b40();
};
class HitThrowAction_151f20 : public Action_151f20 {
  public:
    HitThrowAction_151f20(void* p, Thing_151f20* t);
    char pad[0x1c - 4];
    int mF[9];
};
extern void* hulk_at_00414660[];
class Ref_151f80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151f80 {
  public:
    void* vptr;
};
class HitThrowAction_151f80 : public Action_151f80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151f80* m20;
    Ref_151f80* m24;
    Ref_151f80* m28;
    ~HitThrowAction_151f80();
};
struct Tail_1521b0 {
    char pad[0x12c];
    int field;
};
struct Mid_1521b0 {
    Tail_1521b0* GetTail_00059a30();
};
struct Obj_1521b0 {
};
struct Inner_1521b0 {
    virtual void f0();
    virtual void f1();
    int pad;
    P8* p8;
    int kind;
};
class Target_1521b0 {
  public:
    char pad[0x20];
    Obj_1521b0* mA;
    int spare;
    Inner_1521b0* mItem;
    void Run();
};
struct H {
    void* next_00059a40();
    void invoke_00222970(int, int);
};
struct HitThrowAction_nv_152450 {
    void finish_001521b0();
};
extern void* hulk_at_0041467c[];
class Ref_1524d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1524d0 {
  public:
    void* vptr;
};
class HitOrientToPushbackAction_1524d0 : public Action_1524d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1524d0* m20;
    Ref_1524d0* m24;
    ~HitOrientToPushbackAction_1524d0();
};
class RefObj_152630 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_152630 {
  public:
    Action_152630();
    virtual void Update_00018b30();
    char pad[0x18];
};
class HealthAction_152630 : public Action_152630 {
  public:
    int mTarget;
    RefObj_152630* mObj;
    HealthAction_152630(int target, RefObj_152630* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00414698[];
class Ref_152680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_152680 {
  public:
    void* vptr;
};
class HealthAction_152680 : public Action_152680 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_152680* m20;
    ~HealthAction_152680();
};
class RefObj_1526c0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1526c0 {
  public:
    Action_1526c0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class ClearFightParamsHitRecordAction_1526c0 : public Action_1526c0 {
  public:
    int mTarget;
    RefObj_1526c0* mObj;
    ClearFightParamsHitRecordAction_1526c0(int target, RefObj_1526c0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004146b4[];
class Ref_152710 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_152710 {
  public:
    void* vptr;
};
class ClearFightParamsHitRecordAction_152710 : public Action_152710 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_152710* m20;
    ~ClearFightParamsHitRecordAction_152710();
};
struct CAxisArcCondition_152780;
class CStageCondition_152790 {};
class ParamValue_152790 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152790 : public ParamValue_152790 {
  public:
    virtual void f();
};
class CStageCondition_152820;
class ParamValue_152820 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152820 : public ParamValue_152820 {
  public:
    int pad;
};
struct CAxisArcCondition_152860;
class CStageCondition_152870 {};
class ParamValue_152870 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152870 : public ParamValue_152870 {
  public:
    virtual void f();
};
class CStageCondition_152900;
class ParamValue_152900 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152900 : public ParamValue_152900 {
  public:
    int pad;
};

} // namespace fn_f20ed7e3

// 0x001508d0 hulkfight::motion::InterruptAccumulatorCondition::vfunc_6 (286 B): equivalent/0x001508d0.cpp [wrapped: conflict: DAT_00494b44; hulkfight::motion::InterruptAccumulatorCondition]
// sym: ?vfunc_6@InterruptAccumulatorCondition@motion@hulkfight@fn_001508d0@@UAE_NPAXPAUContext@4@0@Z @d1dcab197433 @w452b50edce25
namespace fn_001508d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 20/20)
// hulkfight::motion::InterruptAccumulatorCondition::vfunc_6 @ 0x001508d0
extern char DAT_00494b44, DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern bool __cdecl FUN_00018960(float,float,float);
struct Accumulator_1508d0 { char pad[0x1a8]; float maximum; };
struct State_1508d0 { char pad[0x11c]; Accumulator_1508d0* accumulator; char pad2[0x200]; float current; };
struct Actor_1508d0 { State_1508d0* FUN_00059a30(); };
struct Context { Actor_1508d0* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct InterruptAccumulatorCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Context*,void*);
 char pad[8]; unsigned operation; float threshold;
};
bool InterruptAccumulatorCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_1508d0* state = context->FUN_000592a0()->FUN_00059a30();
 if (!state->accumulator) return false;
 float value = 0.0f;
 if (state->accumulator->maximum > 0.0f) value = state->current / state->accumulator->maximum * 100.0f;
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
} // namespace fn_001508d0


// 0x00150a10 hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_6 (259 B): equivalent/0x00150a10.cpp
// sym: ?vfunc_6@CollisionSourceForceMagnitudeCondition@motion@hulkfight@@UAE_NPAX00@Z @0dd23e090ef0 @wbd99aab9196e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_6 @ 0x00150a10
bool hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Source_150a10 * source = (Source_150a10 *)__p1;

if (!FUN_00344e74(source,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Force* force=source->slot3();
if (!force) return false;
float magnitude=(float)sqrt(force->x*force->x+force->y*force->y+force->z*force->z);
switch((*(unsigned int *)&this->f_0c)) {
case 0: return magnitude<this->f_10;
case 1: return magnitude<=this->f_10;
case 2: return FUN_00018960(magnitude,this->f_10,0.00001f);
case 3: return !FUN_00018960(magnitude,this->f_10,0.00001f);
case 4: return magnitude>=this->f_10;
case 5: return magnitude>this->f_10;
default: return false;
}
}


// 0x00150b30 hulkfight::motion::HitPushbackVelocityCondition::vfunc_6 (231 B): equivalent/0x00150b30.cpp [wrapped: conflict: hulkfight::motion::HitPushbackVelocityCondition]
// sym: ?vfunc_6@HitPushbackVelocityCondition@motion@hulkfight@fn_00150b30@@UAE_NPAXPAUActor_150b30@4@0@Z @c31892b4e6ac @wef89c511e8a9
namespace fn_00150b30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::HitPushbackVelocityCondition::vfunc_6 @ 0x00150b30
extern "C" {
extern "C++" { extern char DAT_00494b44; }
extern "C++" { extern char DAT_00494b60; }
extern "C++" { void* __cdecl FUN_00344e74(void*, int, void*, void*, int); }
bool __cdecl FUN_00018960(float, float, float);
}
struct VelocityData { char padding[0x1f4]; float velocity; };
struct ActorState_150b30 { VelocityData* FUN_00059a30(); };
struct Actor_150b30 { ActorState_150b30* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct HitPushbackVelocityCondition {
virtual void vfunc_0();
virtual void vfunc_1();
virtual void vfunc_2();
virtual void vfunc_3();
virtual void vfunc_4();
virtual void vfunc_5();
virtual bool vfunc_6(void*, Actor_150b30*, void*);
char padding[8];
unsigned operation;
float threshold;
};
bool HitPushbackVelocityCondition::vfunc_6(void*, Actor_150b30* actor, void*) {
if (!FUN_00344e74(actor, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
float value = actor->FUN_000592a0()->FUN_00059a30()->velocity;
switch (operation) {
case 0: return value < threshold;
case 1: return value <= threshold;
case 2: return FUN_00018960(value, threshold, 0.00001f);
case 3: return !FUN_00018960(value, threshold, 0.00001f);
case 4: return value >= threshold;
case 5: return value > threshold;
default: return false;
}
}
}}
} // namespace fn_00150b30


// 0x00150c30 hulkfight::motion::CollisionChargeCondition::vfunc_6 (305 B): equivalent/0x00150c30.cpp [wrapped: conflict: CFightParams; FUN_00018960; fight::Condition; fight::Params (+1)]
// sym: ?vfunc_6@CollisionChargeCondition@motion@hulkfight@fn_00150c30@@UAEDHPAVParams@fight@4@H@Z @7aaed9d8d1e9 @w7b4aa6d20d21
namespace fn_00150c30 {
// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 21/22, incomplete)
// hulkfight::motion::CollisionChargeCondition::vfunc_6 @ 0x00150c30
struct Fighter_150c30 {
    char pad0[0x213c];
    float value;
};

struct Holder_150c30 {
    Fighter_150c30 *FUN_00059a30();
};

struct Target_150c30 {
    char pad0[0x7c];
    float value;
};

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Target_150c30 *v3();
    Holder_150c30 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v4();
};

char FUN_00018960(float a, float b, float eps);

namespace fight {
class Condition {
  public:
    virtual void c0();
};
}

namespace hulkfight {
namespace motion {

class CollisionChargeCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a1, fight::Params *params, int a3);
    char pad04[8];
    unsigned int mode;
    float threshold;
    unsigned char useFighter;
};

char CollisionChargeCondition::vfunc_6(int a1, fight::Params *params, int a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Target_150c30 *target = params->v3();
    if (target == 0)
        return false;

    Fighter_150c30 *fighter = params->FUN_000592a0()->FUN_00059a30();

    float a = target->value;
    float b = threshold;
    if (useFighter && fighter)
        b = fighter->value;

    switch (mode) {
    case 0:
        return a < b;
    case 1:
        return a <= b;
    case 2:
        return FUN_00018960(a, b, 1e-5f);
    case 3:
        return FUN_00018960(a, b, 1e-5f) == 0;
    case 4:
        return a >= b;
    case 5:
        return a > b;
    }
    return false;
}

}
}
} // namespace fn_00150c30


// 0x00150d80 hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_6 (539 B): equivalent/0x00150d80.cpp
// sym: ?vfunc_6@CollisionDamageHealthCompareCondition@motion@hulkfight@@UAE_NPAX00@Z @9e7e172b5c04 @we0298156a55c
// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 33/40, incomplete)
// hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_6 @ 0x00150d80
bool hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int arg0 = (int)__p0; fight::Params_150d80 * params = (fight::Params_150d80 *)__p1; int arg2 = (int)__p2;

    if (dynamic_cast<CFightParams_150d80 *>(params) == 0)
        return false;
    Member_150d80 *m = params->vfunc_3();
    if (m == 0)
        return false;
    Actor_150d80 *actor = FUN_00059a30(FUN_000592a0(params));
    float value = m->value;
    float limit = this->f_10;

    if (!this->f_18) {
        switch ((*(unsigned int *)&this->f_0c)) {
        case 0:
            return value < limit;
        case 1:
            return value <= limit;
        case 2:
            return FUN_00018960(value, limit, 1e-5f);
        case 3:
            return !FUN_00018960(value, limit, 1e-5f);
        case 4:
            return value >= limit;
        case 5:
            return value > limit;
        }
        return false;
    }

    double diff = (double)actor->maxValue - value;
    float scale = actor->scale;
    union {
        float f;
        unsigned u;
    } mag;
    mag.f = scale;
    mag.u &= 0x7fffffff;
    if (!(mag.f <= 1e-5f))
        value = (float)(diff / scale * 100.0f);
    else
        value = 0.0f;

    switch ((*(unsigned int *)&this->f_0c)) {
    case 0:
        return value < this->f_14;
    case 1:
        return value <= this->f_14;
    case 2:
        return FUN_00018960(value, this->f_14, 1e-5f);
    case 3:
        return !FUN_00018960(value, this->f_14, 1e-5f);
    case 4:
        return value >= this->f_14;
    case 5:
        return value > this->f_14;
    }
    return false;
}

namespace fn_f20ed7e3 {

// 0x00150fd0 FUN_00150fd0 (72 B): matches/0x00150fd0.cpp
// sym: ??0InterruptAccumulatorSetAction_150fd0@fn_f20ed7e3@@QAE@HPAVRefObj_150fd0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
InterruptAccumulatorSetAction_150fd0::InterruptAccumulatorSetAction_150fd0(int target, RefObj_150fd0* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00151020 FUN_00151020 (50 B): matches/0x00151020.cpp
// sym: ??1InterruptAccumulatorSetAction_151020@fn_f20ed7e3@@QAE@XZ
InterruptAccumulatorSetAction_151020::~InterruptAccumulatorSetAction_151020() {
    vptr = hulk_at_00414510;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151020 *)this)->FUN_002326a0();
}


// 0x00151060 FUN_00151060 (72 B): matches/0x00151060.cpp
// sym: ??0InterruptPriorityAction_151060@fn_f20ed7e3@@QAE@HPAVRefObj_151060@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
InterruptPriorityAction_151060::InterruptPriorityAction_151060(int target, RefObj_151060* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x001510b0 FUN_001510b0 (50 B): matches/0x001510b0.cpp
// sym: ??1InterruptPriorityAction_1510b0@fn_f20ed7e3@@QAE@XZ
InterruptPriorityAction_1510b0::~InterruptPriorityAction_1510b0() {
    vptr = hulk_at_0041452c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1510b0 *)this)->FUN_002326a0();
}


// 0x001510f0 FUN_001510f0 (79 B): matches/0x001510f0.cpp
// sym: ??0HitWaitAction@fn_f20ed7e3@@QAE@PAXPAVRefCounted_1510f0@1@@Z
HitWaitAction::HitWaitAction(void* a, RefCounted_1510f0* b) {
    void** q = &mA;
    *q = 0;
    mB = 0;
    mC = 0;
    mA = a;
    if (b)
        b->AddRef();
    if (mB)
        mB->Release();
    mB = b;
}


// 0x00151140 FUN_00151140 (50 B): matches/0x00151140.cpp
// sym: ??1HitWaitAction_151140@fn_f20ed7e3@@QAE@XZ
HitWaitAction_151140::~HitWaitAction_151140() {
    vptr = hulk_at_00414548;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151140 *)this)->FUN_002326a0();
}


// 0x00151180 FUN_00151180 (74 B): matches/0x00151180.cpp
// sym: ??0GroundSlideAction_151180@fn_f20ed7e3@@QAE@HPAVObj_151180@1@@Z
// Same code shape as 0x00174c10 (propagated; names are from that function)
GroundSlideAction_151180::GroundSlideAction_151180(int v, Obj_151180* p) : Action_151180() {
    volatile int* q = &m1c;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    m1c = v;
    if (p)
        p->A();
    if (m20)
        m20->B();
    m20 = p;
}


// 0x001511d0 FUN_001511d0 (69 B): matches/0x001511d0.cpp
// sym: ??1GroundSlideAction_1511d0@fn_f20ed7e3@@QAE@XZ
GroundSlideAction_1511d0::~GroundSlideAction_1511d0() {
    vptr = hulk_at_00414564;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1511d0 *)this)->FUN_002326a0();
}


// 0x00151220 hulkfight::motion::GroundSlideAction::vfunc_3 (429 B): equivalent/0x00151220.cpp
// sym: ?vfunc_3@GroundSlideAction@fn_f20ed7e3@@UAE_NHH@Z @0b4673825485 @wa3f79913eeee
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 20/20)
// hulkfight::motion::GroundSlideAction::vfunc_3 @ 0x00151220
bool GroundSlideAction::vfunc_3(int a, int b)
{
    Clock_151220* clock = ((Clock_151220 *)((owners::Object_592a0 *)target)->FUN_000592a0());
    Timing_151220* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    V3_151220 dir;
    dir.x = 0.0f; dir.y = 0.0f; dir.z = 0.0f;
    if (!((owners::Thing_356c0 *)timing)->FUN_000356c0((unsigned int *)(V3_151220 *)(&dir)))
        return false;
    speed = (float)sqrt(dir.z * dir.z + dir.x * dir.x + dir.y * dir.y);
    dir.y = 0.0f;
    dir.FUN_0022d110();
    Config_151220* c = cfg;
    if (c->minSpeed > 0.0f && c->minSpeed > speed)
        speed = c->minSpeed;
    float lim24 = c->f24;
    if (lim24 > 0.0f && speed <= lim24)
        return false;
    float lim28 = c->f28;
    if (lim28 > 0.0f && lim28 > lim24 && speed > lim28)
        speed = lim28;
    float c2c = c->f2c;
    float c30 = c->f30;
    float c34 = c->f34;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    ((owners::Target_27b040 *)&(d->name))->FUN_0027b040((hulk_uintptr)"groundSlide");
    driver->AddRef();
    skel->FUN_00222890(driver, -1.0f, c2c, 1.0f, c30, c34, -1.0f);
    hulk_freg ang = FUN_00224f10(&dir);     // st0, added to angleOffset unrounded
    driver->xform.FUN_00221d20(ang + cfg->angleOffset);
    return true;
}

} // namespace fn_f20ed7e3

// 0x001513d0 hulkfight::motion::GroundSlideAction::vfunc_5 (844 B): equivalent/0x001513d0.cpp [wrapped: conflict: GroundSlideAction]
// sym: ?vfunc_5@GroundSlideAction@fn_001513d0@@UAE_NHM@Z @331572cc8a6e @w047d10b4998f
namespace fn_001513d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::GroundSlideAction::vfunc_5 @ 0x001513d0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

struct V3_1513d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat4_1513d0 {
    float m[16];
};

struct Timing_1513d0 {
    char pad0[0x2064];
    V3_1513d0 fp2064;
    float f2070;
    hulk_freg FUN_000354c0();
    char FUN_00035660(V3_1513d0 *out);
};

struct Clock_1513d0 {
    Timing_1513d0 *FUN_00059a30();
    char FUN_00059a50(V3_1513d0 *out);
};

struct Target_1513d0 {
};

struct Config_1513d0 {
    char pad0[0x14];
    float angleOffset;     // 0x14
    float f18;
    float f1c;
    char pad20[4];
    float limit;           // 0x24
};

struct Driver {
    char pad0[0x18];
    Mat4_1513d0 xform;
};

void __cdecl FUN_00224d70(float angle, V3_1513d0 *v);

class GroundSlideAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x1c - 4];
    Config_1513d0 *cfg;           // 0x1c
    Target_1513d0 *target;        // 0x20
    Driver *driver;        // 0x24
    float speed;           // 0x28
};

struct Frame_1513d0 {
    float speed;           // 0x10
    float t;               // 0x14
    float limit;           // 0x18
    V3_1513d0 d;                  // 0x1c
    V3_1513d0 e;                  // 0x28
    V3_1513d0 fwd;                // 0x34
    V3_1513d0 w;                  // 0x40
    V3_1513d0 o;                  // 0x4c
    V3_1513d0 r;                  // 0x58
};

bool GroundSlideAction::vfunc_5(int a, float dt)
{
    if (driver == 0)
        return false;
    Frame_1513d0 f;
    Clock_1513d0 *clock = ((Clock_1513d0 *)((owners::Object_592a0 *)target)->FUN_000592a0());
    Timing_1513d0 *timing = clock->FUN_00059a30();
    f.fwd.x = (*(float*)&DAT_004afa08);
    f.fwd.y = (*(float*)((char*)&DAT_004afa08 + 4));
    f.fwd.z = (*(float*)((char*)&DAT_004afa08 + 8));
    f.limit = cfg->angleOffset;
    FUN_00224d70(timing->FUN_000354c0() - f.limit, &f.fwd);

    f.speed = speed;
    double x1 = f.fwd.x * f.speed;
    double y1 = f.fwd.y * f.speed;
    f.d.z = f.fwd.z * f.speed;
    f.limit = cfg->limit;
    double tt = f.speed * cfg->f18 * dt;
    f.t = tt;
    if (tt > f.speed) {
        f.d.x = 0.0f;
        f.d.y = 0.0f;
        f.d.z = 0.0f;
    } else {
        f.w = timing->fp2064;
        f.w.FUN_0022d110();
        double dot = f.fwd.z * f.w.z + f.fwd.y * f.w.y + f.fwd.x * f.w.x;
        double xt = f.fwd.x * f.t;
        double yt = f.fwd.y * f.t;
        volatile float zt = f.fwd.z * f.t;
        f.d.x = x1 - xt;
        f.d.y = y1 - yt;
        f.d.z = f.d.z - zt;
        double val;
        if (dot < -0.5f)
            val = (0.5f - (dot + 1.0f)) * 2.0 * timing->f2070 * cfg->f1c * dt;
        else
            val = 0.0f;
        if (f.t + val > f.speed) {
            f.d.x = 0.0f;
            f.d.y = 0.0f;
            f.d.z = 0.0f;
        } else {
            f.d.x = f.d.x - f.fwd.x * val;
            f.d.y = f.d.y - f.fwd.y * val;
            f.d.z = f.d.z - f.fwd.z * val;
        }
    }
    f.e.x = f.d.x * dt;
    f.e.y = f.d.y * dt;
    f.e.z = f.d.z * dt;
    f.o.x = 0.0f;
    f.o.y = 0.0f;
    f.o.z = 0.0f;
    clock->FUN_00059a50(&f.o);
    f.e.x = f.o.x + f.e.x;
    f.e.y = f.o.y + f.e.y;
    f.e.z = f.o.z + f.e.z;
    ((owners::Target_22be40 *)&(driver->xform))->FUN_0022be40((const int *)(const V3_1513d0 *)(&f.e));
    if (f.limit < 0.0f)
        return true;
    speed = sqrt(f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x);
    timing->FUN_00035660(&f.r);
    float len = sqrt(f.r.z * f.r.z + f.r.y * f.r.y + f.r.x * f.r.x);
    if (len < speed)
        speed = len;
    return speed > f.limit;
}
} // namespace fn_001513d0

namespace fn_f20ed7e3 {

// 0x00151720 FUN_00151720 (72 B): matches/0x00151720.cpp
// sym: ??0HitPauseAction_151720@fn_f20ed7e3@@QAE@HPAVRefObj_151720@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
HitPauseAction_151720::HitPauseAction_151720(int target, RefObj_151720* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00151770 FUN_00151770 (50 B): matches/0x00151770.cpp
// sym: ??1HitPauseAction_151770@fn_f20ed7e3@@QAE@XZ
HitPauseAction_151770::~HitPauseAction_151770() {
    vptr = (void**)DAT_00414580;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151770 *)this)->FUN_002326a0();
}


// 0x001517b0 FUN_001517b0 (85 B): matches/0x001517b0.cpp
// sym: ??0HitReactionAction_1517b0@fn_f20ed7e3@@QAE@PAHPAVRef_1517b0@1@@Z
// Same code shape as 0x00148840 (propagated; names are from that function)
HitReactionAction_1517b0::HitReactionAction_1517b0(int* a, Ref_1517b0* b) : mA(0), mB(0), sub() {
    x = 0;
    y = 0;
    z = 0;
    mA = a;
    if (b)
        b->F();
    if (mB)
        mB->G();
    mB = b;
}


// 0x00151810 FUN_00151810 (77 B): matches/0x00151810.cpp
// sym: ?f@HitReactionAction_151810@fn_f20ed7e3@@QAEXXZ
void HitReactionAction_151810::f() {
    vptr = hulk_at_0041459c;
    _ReadWriteBarrier();
    if (m4c) {
        m4c->f1();
        m4c = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn_002325f0();
    ((GroundSlideAction_nv_151810*)(((hulkfight::motion::GroundSlideAction*)(((hulkfight::motion::GroundSlideAction*)this)))))->Fn_002326a0();
}


// 0x00151860 hulkfight::motion::HitReactionAction::vfunc_5 (141 B): matches/0x00151860.cpp
// sym: ?vfunc_5@HitReactionAction@fn_f20ed7e3@@QAEHHH@Z
int HitReactionAction::vfunc_5(int b, int a) {
    if (!b && !m54)
        sub.Init_002322f0(m50, a);
    Obj_151860* old = m4c;
    m54 = 0;
    if (old != sub.obj) {
        m20->Fnf_000592a0()->Fnf_00059a30()->Fnf_00035cd0();
    }
    sub.Set_00231f20(b);
    if (b == m50 - 1)
        sub.Start_002324b0(1);
    Obj_151860* q = sub.obj;
    if (q)
        q->V0();
    if (m4c)
        m4c->V1();
    m4c = q;
    return sub.End_00231ee0();
}


// 0x001518f0 FUN_001518f0 (85 B): matches/0x001518f0.cpp
// sym: ??0HitReactionFloatAction_1518f0@fn_f20ed7e3@@QAE@PAHPAVRef_1518f0@1@@Z
// Same code shape as 0x00148840 (propagated; names are from that function)
HitReactionFloatAction_1518f0::HitReactionFloatAction_1518f0(int* a, Ref_1518f0* b) : mA(0), mB(0), sub() {
    x = 0;
    y = 0;
    z = 0;
    mA = a;
    if (b)
        b->F();
    if (mB)
        mB->G();
    mB = b;
}


// 0x00151950 FUN_00151950 (77 B): matches/0x00151950.cpp
// sym: ?destroy@HitReactionFloatAction_151950@fn_f20ed7e3@@QAEXXZ
void HitReactionFloatAction_151950::destroy() {
    *(int**)this = &hulk_at_004145b8;
    _ReadWriteBarrier();
    if (m4c) {
        m4c->v1();
        m4c = 0;
    }
    if (m20) {
        m20->v1();
        m20 = 0;
    }
    if (m1c) {
        m1c = 0;
    }
    ((Sub_151950*)((char*)this + 0x24))->release_002325f0();
    ((fight::Action *)this)->FUN_002326a0();
}


// 0x001519a0 hulkfight::motion::HitReactionFloatAction::vfunc_5 (141 B): matches/0x001519a0.cpp
// sym: ?FUN_001519a0@HitReactionFloatAction@fn_f20ed7e3@@QAEHHH@Z
// hulkfight::motion::HitReactionFloatAction::vfunc_5 @ 0x001519a0
// Hit reaction "float" action: advance to step `step`, switching the active animation reference.
int HitReactionFloatAction::FUN_001519a0(int step, int arg)
{
    if (step == 0 && !started) {
        track.FUN_002322f0(stepCount, arg);
    }
    started = 0;
    if (previous != track.current) {
        owner->FUN_000592a0()->FUN_00059a30()->FUN_00035cd0();
    }
    track.FUN_00231f20(step);
    if (step == stepCount - 1) {
        track.FUN_002324b0(1);
    }
    Ref_1519a0* now = track.current;
    if (now) {
        now->AddRef();
    }
    if (previous) {
        previous->Release();
    }
    previous = now;
    return track.FUN_00231ee0();
}


// 0x00151a30 FUN_00151a30 (72 B): matches/0x00151a30.cpp
// sym: ??0HitPushbackAddAction_151a30@fn_f20ed7e3@@QAE@HPAVRefObj_151a30@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
HitPushbackAddAction_151a30::HitPushbackAddAction_151a30(int target, RefObj_151a30* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00151a80 FUN_00151a80 (50 B): matches/0x00151a80.cpp
// sym: ??1HitPushbackAddAction_151a80@fn_f20ed7e3@@QAE@XZ
HitPushbackAddAction_151a80::~HitPushbackAddAction_151a80() {
    vptr = hulk_at_004145d4;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151a80 *)this)->FUN_002326a0();
}

} // namespace fn_f20ed7e3

// 0x00151ac0 hulkfight::motion::HitPushbackAddAction::vfunc_3 (108 B): matches/0x00151ac0.cpp
// sym: ?vfunc_3@HitPushbackAddAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::HitPushbackAddAction::vfunc_3(hulk_intptr __p0, hulk_intptr x) { Obj_151ac0 * arg = (Obj_151ac0 *)__p0;

    if ((*(Obj_151ac0 * *)&this->f_20)) {
        Obj_151ac0* p = (*(Obj_151ac0 * *)&this->f_20)->get();
        if (p) {
            Obj_151ac0* a = (Obj_151ac0*)(*(Obj_151ac0 * *)&this->f_20)->helper1_000592a0();
            Obj_151ac0* b = a->helper2_00059a30();
            float t = *(float*)((char*)(*(Obj_151ac0 * *)&this->f_1c) + 0x10);
            float* v = (float*)((char*)p + 0x28);
            float out[3];
            out[0] = t * v[0];
            out[1] = t * v[1];
            out[2] = t * v[2];
            b->send_00035810(*(void**)((char*)p + 0x5c), out);
        }
    }
    return false;
}

namespace fn_f20ed7e3 {

// 0x00151b30 FUN_00151b30 (72 B): matches/0x00151b30.cpp
// sym: ??0NoHitPushbackAction_151b30@fn_f20ed7e3@@QAE@HPAVRefObj_151b30@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
NoHitPushbackAction_151b30::NoHitPushbackAction_151b30(int target, RefObj_151b30* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00151b80 FUN_00151b80 (50 B): matches/0x00151b80.cpp
// sym: ??1NoHitPushbackAction_151b80@fn_f20ed7e3@@QAE@XZ
NoHitPushbackAction_151b80::~NoHitPushbackAction_151b80() {
    vptr = hulk_at_004145f0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151b80 *)this)->FUN_002326a0();
}


// 0x00151bc0 FUN_00151bc0 (89 B): matches/0x00151bc0.cpp
// sym: ??0HitPushbackAction_151bc0@fn_f20ed7e3@@QAE@HPAVObj_151bc0@1@@Z
HitPushbackAction_151bc0::HitPushbackAction_151bc0(int p, Obj_151bc0* q) : Ctor_00232660() {
    v = ((hulk_intptr)DAT_0041460c);
    a = 0;
    b = 0;
    *(int*)((char*)&this->gap) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x40) = 0;
    a = p;
    if (q)
        q->F();
    if (b)
        b->G();
    b = q;
}


// 0x00151c20 FUN_00151c20 (69 B): matches/0x00151c20.cpp
// sym: ??1HitPushbackAction_151c20@fn_f20ed7e3@@QAE@XZ
HitPushbackAction_151c20::~HitPushbackAction_151c20() {
    vptr = hulk_at_0041460c;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151c20 *)this)->FUN_002326a0();
}


// 0x00151c70 hulkfight::motion::HitPushbackAction::vfunc_5 (366 B): equivalent/0x00151c70.cpp
// sym: ?vfunc_5@HitPushbackAction@fn_f20ed7e3@@UAE_NHM@Z @f90e59130e03 @w4c873d8d7fe2
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 12/12)
// hulkfight::motion::HitPushbackAction::vfunc_5 @ 0x00151c70
bool HitPushbackAction::vfunc_5(int a, float dt) {
    if (a != 0)
        return true;
    if (target == 0)
        return false;
    P_151c70* p = ((P_151c70 *)((owners::Object_592a0 *)obj)->FUN_000592a0());
    ((owners::C_359c0 *)(p->FUN_00059a30()))->FUN_000359c0(1);
    if (obj->v3() == 0)
        return false;
    hulk_freg left = timer - dt;
    timer = left;
    if (left < 0.0f) {
        hulk_freg sum = left + dt;
        dt = sum;
        if (sum <= 0.0f)
            return false;
    }
    hulk_freg s = dt * speed;
    V3_151c70 tmp;
    tmp.x = dir.x * s;
    tmp.y = dir.y;
    tmp.z = dir.z * s;
    V3_151c70 cur;
    p->FUN_00059a50(&cur);
    tmp.x = cur.x + tmp.x;
    tmp.y = cur.y + tmp.y;
    tmp.z = cur.z + tmp.z;
    ((owners::Target_22be40 *)&(target->sub))->FUN_0022be40((const int *)(V3_151c70 *)(&tmp));
    float x = dt * accel + speed;
    speed = x;
    hulk_freg v = FUN_00083d90(&spd40);
    spd40 = v * owner->scale24 * x;
    hulk_freg r = target->sub.FUN_002220d0();
    target->sub.FUN_00221d20(dt * spd40 + r);
    return timer > 0.0f;
}


// 0x00151de0 FUN_00151de0 (83 B): matches/0x00151de0.cpp
// sym: ??0HitFloatAction@fn_f20ed7e3@@QAE@HPAVRef@1@@Z
HitFloatAction::HitFloatAction(int x, Ref* r) : Action_151de0(), b(0), c(0), d(0), e(0), f0(0), g(0) {
    a.Set(x);
    if (r)
        r->Add();
    if (b)
        b->Release();
    b = r;
}


// 0x00151e40 FUN_00151e40 (69 B): matches/0x00151e40.cpp
// sym: ??1HitFloatAction_151e40@fn_f20ed7e3@@QAE@XZ
HitFloatAction_151e40::~HitFloatAction_151e40() {
    vptr = hulk_at_00414628;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151e40 *)this)->FUN_002326a0();
}


// 0x00151e90 FUN_00151e90 (72 B): matches/0x00151e90.cpp
// sym: ??0HitDamageAction_151e90@fn_f20ed7e3@@QAE@HPAVRefObj_151e90@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
HitDamageAction_151e90::HitDamageAction_151e90(int target, RefObj_151e90* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00151ee0 FUN_00151ee0 (50 B): matches/0x00151ee0.cpp
// sym: ??1HitDamageAction_151ee0@fn_f20ed7e3@@QAE@XZ
HitDamageAction_151ee0::~HitDamageAction_151ee0() {
    vptr = hulk_at_00414644;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151ee0 *)this)->FUN_002326a0();
}


// 0x00151f20 FUN_00151f20 (89 B): matches/0x00151f20.cpp
// sym: ??0HitThrowAction_151f20@fn_f20ed7e3@@QAE@PAXPAVThing_151f20@1@@Z
// Same code shape as 0x001353c0 (propagated; names are from that function)
HitThrowAction_151f20::HitThrowAction_151f20(void* p, Thing_151f20* t) : Action_151f20() {
    int i;
    for (i = 0; i < 9; i++)
        mF[i] = 0;
    mF[0] = (hulk_intptr)p;
    if (t)
        t->A();
    if (mF[1])
        ((Thing_151f20*)mF[1])->B();
    mF[1] = (hulk_intptr)t;
}


// 0x00151f80 FUN_00151f80 (74 B): matches/0x00151f80.cpp
// sym: ??1HitThrowAction_151f80@fn_f20ed7e3@@QAE@XZ
HitThrowAction_151f80::~HitThrowAction_151f80() {
    vptr = hulk_at_00414660;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_151f80 *)this)->FUN_002326a0();
}

} // namespace fn_f20ed7e3

// 0x00151fd0 hulkfight::motion::HitThrowAction::vfunc_3 (480 B): equivalent/0x00151fd0.cpp [wrapped: conflict: FUN_000592a0; JointDriver]
// sym: ?vfunc_3@HitThrowAction@fn_00151fd0@@UAE_NHH@Z @ff3c77f86572 @w103d163e02be
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00151fd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 28/28)
// hulkfight::motion::HitThrowAction::vfunc_3 @ 0x00151fd0
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

struct V3_151fd0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Name_151fd0 {
    unsigned int lo, hi;
};

struct Xform_151fd0 {
    char data[0x54];
    void FUN_00221d20(float v);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_151fd0 name;
    char pad10[4];
    int mode;
    Xform_151fd0 xform;
    JointDriver *FUN_002248f0(int a);
};

struct Linked_151fd0 {
    void FUN_0003ee70(int handle);
};

class RefObj_151fd0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Linked_151fd0 *linked;
    int kind;
};

struct TargetInfo {
    char pad0[0x28];
    V3_151fd0 pos;
    char pad34[0x84 - 0x34];
    RefObj_151fd0 *ref;
    int handle;
};

class OwnerObj_151fd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TargetInfo *v3();
};

struct Body_151fd0 {
    void FUN_00222890(JointDriver *d, float a, float b, float c, float e, float f, float g);
};

struct Stats_151fd0 {
    char pad0[0x12c];
    int handle;
};

struct Fighter_151fd0 {
    void FUN_00059a50(V3_151fd0 *out);
};

struct Config_151fd0 {
    char pad0[0x14];
    char flag14;
    char pad15[3];
    float f18;
    char pad1c[4];
    float f20;
    float f24;
    float f28;
};

struct Hook_151fd0 {
    char pad0[0x124];
    int enabled;
    void FUN_00029b50(int a, RefObj_151fd0 *b, int c);
};

struct World {
    char pad0[0x20];
    Hook_151fd0 *hook;
};


void *__cdecl FUN_00263ea0(unsigned int size);
Fighter_151fd0 *__fastcall FUN_000592a0(void *owner);
Stats_151fd0 *__fastcall FUN_00059a30(Fighter_151fd0 *f);
extern "C" Body_151fd0 *__fastcall FUN_00059a40(Fighter_151fd0 *f);
hulk_freg __cdecl FUN_00224f10(V3_151fd0 *v);

class HitThrowAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_151fd0 *cfg;
    OwnerObj_151fd0 *owner;
    JointDriver *driver;
    RefObj_151fd0 *ref;
    int handle;
    float length;
    V3_151fd0 dir;
};

bool HitThrowAction::vfunc_3(int a, int b)
{
    if (!owner)
        return false;
    Fighter_151fd0 *fighter = FUN_000592a0(owner);
    Stats_151fd0 *stats = FUN_00059a30(fighter);
    Body_151fd0 *body = FUN_00059a40(fighter);
    if (!body)
        return false;
    TargetInfo *t = owner->v3();
    if (!t)
        return false;

    V3_151fd0 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    fighter->FUN_00059a50(&origin);

    Config_151fd0 *c = cfg;
    float c20 = c->f20;
    float c24 = c->f24;
    float c28 = c->f28;
    void *mem = FUN_00263ea0(0x70);
    JointDriver *d;
    if (mem != 0)
        d = ((JointDriver *)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    ((owners::Target_27b040 *)&(d->name))->FUN_0027b040((hulk_uintptr)"hitThrow");
    int mode = 1;
    if (cfg->flag14) {
        mode = 3;
        hulk_freg r = FUN_00224f10(&t->pos);  // st0, added to f18 unrounded
        driver->xform.FUN_00221d20(r + cfg->f18);
    }
    driver->mode = mode;
    driver->AddRef();
    ((owners::Target_22be40 *)&(driver->xform))->FUN_0022be40((const int *)(const V3_151fd0 *)(&origin));
    body->FUN_00222890(driver, -1.0f, c20, 1.0f, c24, c28, -1.0f);

    handle = t->handle;
    dir = t->pos;
    length = dir.FUN_0022d110();

    RefObj_151fd0 *r = t->ref;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    if (r && r->kind == 1 && r->linked)
        r->linked->FUN_0003ee70(stats->handle);
    if (ref && DAT_004dd700 && DAT_004dd700->hook && DAT_004dd700->hook->enabled)
        DAT_004dd700->hook->FUN_00029b50(stats->handle, ref, handle);
    return true;
}
} // namespace fn_00151fd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f20ed7e3 {

// 0x001521b0 FUN_001521b0 (92 B): matches/0x001521b0.cpp
// sym: ?Run@Target_1521b0@fn_f20ed7e3@@QAEXXZ
// Same code shape as 0x00135700 (propagated; names are from that function)
void Target_1521b0::Run() {
    if (mItem != 0 && mItem->kind == 1) {
        Tail_1521b0* t = ((Mid_1521b0 *)((owners::Object_592a0 *)mA)->FUN_000592a0())->GetTail_00059a30();
        P8* p = mItem->p8;
        if (p != 0) {
            int v = t->field;
            if (p->Get() == v)
                p->Set(0);
        }
    }
    if (mItem != 0) {
        mItem->f1();
        mItem = 0;
    }
}

} // namespace fn_f20ed7e3

// 0x00152210 hulkfight::motion::HitThrowAction::vfunc_5 (571 B): equivalent/0x00152210.cpp [wrapped: conflict: HitThrowAction; World]
// sym: ?vfunc_5@HitThrowAction@fn_00152210@@QAE_NHM@Z @dceeda686d75 @w050629dec778
namespace fn_00152210 {
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 16/16)
// hulkfight::motion::HitThrowAction::vfunc_5 @ 0x00152210
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

struct Vec3_152210 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Transform_152210 {
    void FUN_00221d20(float angle);
};

struct Target_152210 {
    char pad00[0x18];
    Transform_152210 xform;
};

struct Config_152210 {
    char pad00[0x14];
    char flag14;
    char pad15[3];
    float f18;
    float f1c;
};

struct Fighter_152210 {
    char pad00[0x11c];
    struct Inner_152210* inner;
    char pad120[0xc];
    int f12c;
};

struct Inner_152210 {
    char pad00[0x2c];
    int f2c;
};

struct Anchor_152210 {
    Fighter_152210* FUN_00059a30();
    void FUN_00059a50(Vec3_152210* out);
};

struct Pool_152210 {
    void FUN_00029bb0(int a, int b, float c);
};

struct World {
    char pad0[0x20];
    Pool_152210* pool;
};

struct Probe_152210 {
    char pad00[0x8c];
    int f8c;
};

struct Holder_152210 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Probe_152210* vfunc_3();
};


Anchor_152210* __fastcall FUN_000592a0(Holder_152210* h);
Fighter_152210* __fastcall FUN_00059a30(Anchor_152210* a);
hulk_freg FUN_00224f10(Vec3_152210* v);
extern "C" int FUN_00098190(float dt, float speed, int probe, int zero0, int f28, int x, Vec3_152210* out, Vec3_152210* io, int z1, int z2, int z3, int one);

struct Frame_152210 {
    Vec3_152210 s;
    Vec3_152210 t;
    Vec3_152210 v;
};

class HitThrowAction {
public:
    char pad00[0x1c];
    Config_152210* cfg;
    Holder_152210* holder;
    Target_152210* target;
    int f28;
    float f2c;
    float f30;
    Vec3_152210 vel;
    void FUN_001521b0();
    bool vfunc_5(int skip, float dt);
};

bool HitThrowAction::vfunc_5(int skip, float dt)
{
    Frame_152210 fr;

    if (skip)
        return true;
    if (target == 0)
        return false;
    Probe_152210* probe = holder->vfunc_3();
    if (probe == 0)
        return false;

    Anchor_152210* anchor = FUN_000592a0(holder);
    Fighter_152210* fighter = FUN_00059a30(anchor);
    fr.v.x = 0.0f;
    fr.v.y = 0.0f;
    fr.v.z = 0.0f;
    anchor->FUN_00059a50(&fr.v);
    ((owners::C_359c0 *)fighter)->FUN_000359c0(3);

    f2c = f2c - dt * f30;
    if (f28) {
        skip = fighter->inner->f2c;
        if (FUN_00098190(dt, f30, probe->f8c, 0, f28, skip, &fr.v, &vel, 0, 0, 0, 1))
            DAT_004dd700->pool->FUN_00029bb0(fighter->f12c, f28, f2c);
        else
            FUN_001521b0();
    }

    fr.s.x = vel.x * f30;
    fr.s.y = vel.y * f30;
    fr.s.z = vel.z * f30;
    if (f28 == 0) {
        fr.s.x = fr.s.x + dt * 0.0f;
        vel.x = fr.s.x;
        fr.s.y = fr.s.y + (-cfg->f1c) * dt;
        vel.y = fr.s.y;
        fr.s.z = fr.s.z + dt * 0.0f;
        vel.z = fr.s.z;
        f30 = vel.FUN_0022d110();
    }

#if defined(__clang__)
    // MSVC 7.1 keeps the x and y products in st0 (one rounding each) and spills the z product (fstp, then adds: two
    // roundings); clang rounds every store, so it is spelled out
    fr.t.z = fr.s.z * dt;
    fr.t.x = fr.s.x * dt + fr.v.x;
    fr.t.y = fr.s.y * dt + fr.v.y;
    fr.t.z = fr.t.z + fr.v.z;
#else
    fr.t.x = fr.s.x * dt;
    fr.t.y = fr.s.y * dt;
    fr.t.z = fr.s.z * dt;
    fr.t.x = fr.t.x + fr.v.x;
    fr.t.y = fr.t.y + fr.v.y;
    fr.t.z = fr.t.z + fr.v.z;
#endif
    ((owners::Target_22be40 *)&(target->xform))->FUN_0022be40((const int *)(Vec3_152210 *)(&fr.t));

    if (cfg->flag14) {
        hulk_freg ang = FUN_00224f10(&vel);     // st0, added to f18 unrounded
        target->xform.FUN_00221d20(ang + cfg->f18);
    }
    return f2c > 0.0f;
}
} // namespace fn_00152210
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00152450 hulkfight::motion::HitThrowAction::vfunc_4 (45 B): matches/0x00152450.cpp
// sym: ?vfunc_4@HitThrowAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::HitThrowAction::vfunc_4() {
    H* x = (*(H * *)&this->f_20);
    void* p = ((void *)((owners::Object_592a0 *)x)->FUN_000592a0());
    H* q = (H*)p;
    p = q->next_00059a40();
    if (p) {
        ((H*)p)->invoke_00222970(this->f_24, 0);
        ((HitThrowAction_nv_152450*)this)->finish_001521b0();
    }
}


// 0x00152480 FUN_00152480 (79 B): matches/0x00152480.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0HitOrientToPushbackAction_152480@fn_00152480@@QAE@HPAVOther_152480@1@@Z
namespace fn_00152480 {
class Action_152480 {
  public:
    virtual void X();
    Action_152480();
};
class Other_152480 {
  public:
    virtual void Fn();
    virtual void Fn2();
};
extern int vt_152480;
class HitOrientToPushbackAction_152480 : public Action_152480 {
  public:
    HitOrientToPushbackAction_152480(int a, Other_152480* b);
    virtual void V0();
    char pad[0x18];
    int mValue;
    Other_152480* mOther;
    int mUnused;
};
void HitOrientToPushbackAction_152480::V0() {}
HitOrientToPushbackAction_152480::HitOrientToPushbackAction_152480(int a, Other_152480* b) : Action_152480() {
    *(hulk_intptr*)this = (hulk_intptr)&vt_152480;
    volatile int* p = &mValue;
    *p = 0;
    mOther = 0;
    mUnused = 0;
    mValue = a;
    if (b)
        b->Fn();
    if (mOther)
        mOther->Fn2();
    mOther = b;
}
} // namespace fn_00152480

namespace fn_f20ed7e3 {

// 0x001524d0 FUN_001524d0 (69 B): matches/0x001524d0.cpp
// sym: ??1HitOrientToPushbackAction_1524d0@fn_f20ed7e3@@QAE@XZ
HitOrientToPushbackAction_1524d0::~HitOrientToPushbackAction_1524d0() {
    vptr = hulk_at_0041467c;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1524d0 *)this)->FUN_002326a0();
}

} // namespace fn_f20ed7e3

// 0x00152520 hulkfight::motion::HitOrientToPushbackAction::vfunc_5 (264 B): equivalent/0x00152520.cpp [wrapped: conflict: hulkfight::motion::HitOrientToPushbackAction]
// sym: ?vfunc_5@HitOrientToPushbackAction@motion@hulkfight@fn_00152520@@UAE_NHM@Z @6fe0e2c2318e @w14dd605cecc8
namespace fn_00152520 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::HitOrientToPushbackAction::vfunc_5 @ 0x00152520
struct Vec_152520 { float x,y,z; };
struct Rotation_152520 { void FUN_00221d20(float); };
struct PushObject { char pad[0x18]; Rotation_152520 rotation; };
struct Settings_152520 { char pad[0x14]; float rate; };
struct Transform_152520 { char pad[0x28]; Vec_152520 direction; };
struct Motion_152520 { hulk_freg FUN_000354c0(); };
struct Intermediate_152520 { Motion_152520* FUN_00059a30(); };
struct Actor_152520 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Transform_152520* slot3(); Intermediate_152520* FUN_000592a0(); };
extern hulk_freg __cdecl FUN_00224f10(Vec_152520*);
extern hulk_freg __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {
struct HitOrientToPushbackAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,float);
 char pad[0x18]; Settings_152520* settings; Actor_152520* actor; PushObject* push;
};
bool HitOrientToPushbackAction::vfunc_5(int flag,float dt) {
 if(flag) return true;
 if(!push) return false;
 Motion_152520* m=actor->FUN_000592a0()->FUN_00059a30();
 Transform_152520* t=actor->slot3();
 if(!t) return false;
 float current=m->FUN_000354c0();
 float target=FUN_00224f10(&t->direction);
 float rate=settings->rate;
 if(!(rate<=0.0f)) {
 float diff=FUN_00224fc0(current,target);
 float step=rate*dt;
 union { float f; unsigned int u; } mag;
 mag.f=diff; mag.u &= 0x7fffffff;
 if(!(mag.f<=step)) {
 if(diff<0.0f) current=current-step; else current=current+step;
 } else current=target;
 } else current=target;
 push->rotation.FUN_00221d20(current);
 return true;
}
}}
} // namespace fn_00152520

namespace fn_f20ed7e3 {

// 0x00152630 FUN_00152630 (72 B): matches/0x00152630.cpp
// sym: ??0HealthAction_152630@fn_f20ed7e3@@QAE@HPAVRefObj_152630@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
HealthAction_152630::HealthAction_152630(int target, RefObj_152630* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00152680 FUN_00152680 (50 B): matches/0x00152680.cpp
// sym: ??1HealthAction_152680@fn_f20ed7e3@@QAE@XZ
HealthAction_152680::~HealthAction_152680() {
    vptr = hulk_at_00414698;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_152680 *)this)->FUN_002326a0();
}


// 0x001526c0 FUN_001526c0 (72 B): matches/0x001526c0.cpp
// sym: ??0ClearFightParamsHitRecordAction_1526c0@fn_f20ed7e3@@QAE@HPAVRefObj_1526c0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ClearFightParamsHitRecordAction_1526c0::ClearFightParamsHitRecordAction_1526c0(int target, RefObj_1526c0* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00152710 FUN_00152710 (50 B): matches/0x00152710.cpp
// sym: ??1ClearFightParamsHitRecordAction_152710@fn_f20ed7e3@@QAE@XZ
ClearFightParamsHitRecordAction_152710::~ClearFightParamsHitRecordAction_152710() {
    vptr = hulk_at_004146b4;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_152710 *)this)->FUN_002326a0();
}

} // namespace fn_f20ed7e3

// 0x00152780 fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_7 (6 B): matches/0x00152780.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152790 fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_6 (30 B): matches/0x00152790.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152790 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152790*)&DAT_003f335c));
}


// 0x001527b0 fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_8 (26 B): matches/0x001527b0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::**)(int))&this->f_18))(b);
}


// 0x001527d0 fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_2 (11 B): matches/0x001527d0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00152800 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_6 (26 B): matches/0x00152800.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::**)(int))&this->f_10))(b);
}


// 0x00152820 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_2 (11 B): matches/0x00152820.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152860 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_7 (6 B): matches/0x00152860.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152870 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_6 (30 B): matches/0x00152870.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152870 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152870*)&DAT_003f335c));
}


// 0x00152890 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_8 (26 B): matches/0x00152890.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::**)(int))&this->f_18))(b);
}


// 0x001528b0 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_2 (11 B): matches/0x001528b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001528e0 fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_6 (26 B): matches/0x001528e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::**)(int))&this->f_10))(b);
}


// 0x00152900 fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_2 (11 B): matches/0x00152900.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

