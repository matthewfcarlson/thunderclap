// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010f0f0..0x00110220 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistoryNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f49cf0cf {
#define TREE_TU_END }
namespace fn_f49cf0cf {} using namespace fn_f49cf0cf;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f49cf0cf {
class RefObj_10f310 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10f310 {
  public:
    Action_10f310();
    virtual void Update();
    char pad[0x18];
};
class HulkAction_10f310 : public Action_10f310 {
  public:
    int mTarget;
    RefObj_10f310* mObj;
    HulkAction_10f310(int target, RefObj_10f310* obj);
    virtual void Execute();
};
extern void* hulk_at_0040dd50[];
class Ref_10f360 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10f360 {
  public:
    void* vptr;
};
class HulkAction_10f360 : public Action_10f360 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f360* m20;
    ~HulkAction_10f360();
};
struct Key_10f480 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027af70(Key_10f480 *src);
    char FUN_0027af90(Key_10f480 *other);
};
extern "C" void FUN_00363ee0();
extern "C" void FUN_00363ed0();
struct Fighter_10f480 {
    char pad0[0x1b98];
    Key_10f480 history;             // 0x1b98
    int count;               // 0x1ba0
};
struct Holder_10f480 {
    Fighter_10f480 *FUN_00059a30();
};
} // namespace fn_f49cf0cf
namespace fight {
class Params_10f480 {
  public:
    virtual void v0();
    virtual void v1();
    Holder_10f480 *FUN_000592a0();
};
}
namespace fn_f49cf0cf {
class CFightParams_10f480 : public fight::Params_10f480 {
  public:
    virtual void v2();
};
class AIHistoryNameCondition {
  public:
    char pad0[0xc];
    unsigned mode;
    int name;
    float threshold;

    char FUN_0010f480(int a1, fight::Params_10f480 *params, int a3);
};
struct Key_10f630 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};
extern "C" void FUN_00363ef0();
struct Fighter_10f630 {
    float FUN_00037290(unsigned lo, unsigned hi);
};
struct Holder_10f630 {
    Fighter_10f630 *FUN_00059a30();
};
} // namespace fn_f49cf0cf
namespace fight {
class Params_10f630 {
  public:
    virtual void v0();
    virtual void v1();
    Holder_10f630 *FUN_000592a0();
};
}
namespace fn_f49cf0cf {
class CFightParams_10f630 : public fight::Params_10f630 {
  public:
    virtual void v2();
};
class KeyWordWaitCondition {
  public:
    char pad0[0xc];
    unsigned mode;
    int keyword;
    float threshold;

    bool FUN_0010f630(int a1, fight::Params_10f630 *params, int a3);
};
class RefObj_10f780 {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern "C" int __cdecl GetSingleton_000678d0();
extern char hulk_at_0040dd6c[];
class Action_10f780 {
  public:
    void* vptr;
    Action_10f780();
};
class TokenSupressAction : public Action_10f780 {
  public:
    char pad[0x18];
    int m1c;
    RefObj_10f780* m20;
    int m24;
    TokenSupressAction(int a, RefObj_10f780* b);
};
extern void* g_vftable_10f7e0[];
class Ref_10f7e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10f7e0 {
  public:
    void* vptr;
};
class TokenSupressAction_10f7e0 : public Action_10f7e0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f7e0* m20;
    ~TokenSupressAction_10f7e0();
};
class RefObj_10f820 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10f820 {
  public:
    Action_10f820();
    virtual void Update();
    char pad[0x18];
};
class TokenAction_10f820 : public Action_10f820 {
  public:
    int mTarget;
    RefObj_10f820* mObj;
    TokenAction_10f820(int target, RefObj_10f820* obj);
    virtual void Execute();
};
extern void* hulk_at_0040dd88[];
class Ref_10f870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10f870 {
  public:
    void* vptr;
};
class TokenAction_10f870 : public Action_10f870 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f870* m20;
    ~TokenAction_10f870();
};
class RefObj_10f8b0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10f8b0 {
  public:
    Action_10f8b0();
    virtual void Update();
    char pad[0x18];
};
class AIHistorySetAction_10f8b0 : public Action_10f8b0 {
  public:
    int mTarget;
    RefObj_10f8b0* mObj;
    AIHistorySetAction_10f8b0(int target, RefObj_10f8b0* obj);
    virtual void Execute();
};
class Ref_10f900 {
  public:
    virtual void A();
    virtual void Release();
};
class Action_10f900 {
  public:
    virtual void A();
    virtual void B();
    void Finish();
};
extern void* hulk_at_0040dda4[];
struct AIHistorySetAction_nv_10f900 {
    void Finish_002326a0();
};
class RefObj_10f940 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10f940 {
  public:
    Action_10f940();
    virtual void Update();
    char pad[0x18];
};
class SemaphoreWaitAction_10f940 : public Action_10f940 {
  public:
    int mTarget;
    RefObj_10f940* mObj;
    SemaphoreWaitAction_10f940(int target, RefObj_10f940* obj);
    virtual void Execute();
};
extern void* hulk_at_0040ddc0[];
class Ref_10f990 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10f990 {
  public:
    void* vptr;
};
class SemaphoreWaitAction_10f990 : public Action_10f990 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f990* m20;
    ~SemaphoreWaitAction_10f990();
};
class RefObj_10f9d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10f9d0 {
  public:
    Action_10f9d0();
    virtual void Update();
    char pad[0x18];
};
class SemaphoreClearAction_10f9d0 : public Action_10f9d0 {
  public:
    int mTarget;
    RefObj_10f9d0* mObj;
    SemaphoreClearAction_10f9d0(int target, RefObj_10f9d0* obj);
    virtual void Execute();
};
extern void* hulk_at_0040dddc[];
class Ref_10fa20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10fa20 {
  public:
    void* vptr;
};
class SemaphoreClearAction_10fa20 : public Action_10fa20 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10fa20* m20;
    ~SemaphoreClearAction_10fa20();
};
class RefObj_10fa60 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10fa60 {
  public:
    Action_10fa60();
    virtual void Update();
    char pad[0x18];
};
class KeywordWaitAction_10fa60 : public Action_10fa60 {
  public:
    int mTarget;
    RefObj_10fa60* mObj;
    KeywordWaitAction_10fa60(int target, RefObj_10fa60* obj);
    virtual void Execute();
};
extern void* hulk_at_0040ddf8[];
class Ref_10fab0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10fab0 {
  public:
    void* vptr;
};
class KeywordWaitAction_10fab0 : public Action_10fab0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10fab0* m20;
    ~KeywordWaitAction_10fab0();
};
struct CAxisArcCondition_10fb20;
class CStageCondition_10fb30 {};
class ParamValue_10fb30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_10fb30 : public ParamValue_10fb30 {
  public:
    virtual void f();
};
class CStageCondition_10fbc0;
class ParamValue_10fbc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10fbc0 : public ParamValue_10fbc0 {
  public:
    int pad;
};
class CStageCondition_10fc10;
class ParamValue_10fc10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10fc10 : public ParamValue_10fc10 {
  public:
    int pad;
};
class CStageCondition_10fc90;
class ParamValue_10fc90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10fc90 : public ParamValue_10fc90 {
  public:
    int pad;
};
struct CAxisArcCondition_10fcd0;
class CStageCondition_10fce0 {};
class ParamValue_10fce0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_10fce0 : public ParamValue_10fce0 {
  public:
    virtual void f();
};
class CStageCondition_10fd70;
class ParamValue_10fd70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10fd70 : public ParamValue_10fd70 {
  public:
    int pad;
};
class CStageCondition_10fdc0;
class ParamValue_10fdc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10fdc0 : public ParamValue_10fdc0 {
  public:
    int pad;
};
struct CAxisArcCondition_10fe00;
class CStageCondition_10fe10 {};
class ParamValue_10fe10 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_10fe10 : public ParamValue_10fe10 {
  public:
    virtual void f();
};
class CStageCondition_10fea0;
class ParamValue_10fea0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10fea0 : public ParamValue_10fea0 {
  public:
    int pad;
};
struct CAxisArcCondition_10fee0;
class CStageCondition_10fef0 {};
class ParamValue_10fef0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_10fef0 : public ParamValue_10fef0 {
  public:
    virtual void f();
};
class CStageCondition_10ff80;
class ParamValue_10ff80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10ff80 : public ParamValue_10ff80 {
  public:
    int pad;
};
struct CAxisArcCondition_10ffc0;
class CStageCondition_10ffd0 {};
class ParamValue_10ffd0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_10ffd0 : public ParamValue_10ffd0 {
  public:
    virtual void f();
};
class CStageCondition_110060;
class ParamValue_110060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110060 : public ParamValue_110060 {
  public:
    int pad;
};
class CStageCondition_1100b0;
class ParamValue_1100b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1100b0 : public ParamValue_1100b0 {
  public:
    int pad;
};
struct CAxisArcCondition_1100f0;
class CStageCondition_110190;
class ParamValue_110190 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110190 : public ParamValue_110190 {
  public:
    int pad;
};
class CStageCondition_1101e0;
class ParamValue_1101e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1101e0 : public ParamValue_1101e0 {
  public:
    int pad;
};

} // namespace fn_f49cf0cf

// 0x0010f0f0 hulkfight::ai::HulkActionLargestCondition::vfunc_6 (295 B): equivalent/0x0010f0f0.cpp [wrapped: conflict: hulkfight::ai::HulkActionLargestCondition]
// sym: ?vfunc_6@HulkActionLargestCondition@ai@hulkfight@fn_0010f0f0@@QAE_NIPAUActor_10f0f0@4@I@Z @5e3a47756c94 @w2f10a09b77ac
namespace fn_0010f0f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 12/12)
// hulkfight::ai::HulkActionLargestCondition::vfunc_6 @ 0x0010f0f0

struct Key_10f0f0 { unsigned first, second; void FUN_0027af00(); void FUN_0027b040(unsigned); };
extern unsigned DAT_00494b44, DAT_00494b60;
extern "C" void __cdecl FUN_00363e80(); extern "C" void __cdecl FUN_00363e90();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (__cdecl *)());
#endif

void* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct State_10f0f0 { int FUN_00059a30(); };
struct Actor_10f0f0 { State_10f0f0* FUN_000592a0(); };
struct Manager_10f0f0 { char pad[0x388]; unsigned first,second; void FUN_00067730(); hulk_freg FUN_00067110(Key_10f0f0*); };
Manager_10f0f0* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {
struct HulkActionLargestCondition { void* vptr; char pad[12]; unsigned parameter; bool vfunc_6(unsigned,Actor_10f0f0*,unsigned); };
bool HulkActionLargestCondition::vfunc_6(unsigned,Actor_10f0f0* actor,unsigned) {
 if (!((*(unsigned*)&DAT_004e0bd0) & 1)) { (*(unsigned*)&DAT_004e0bd0) |= 1; (*(Key_10f0f0*)&DAT_004e0bc8).FUN_0027af00(); atexit(FUN_00363e90); }
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 if (!actor->FUN_000592a0()->FUN_00059a30()) return false;
 FUN_000678d0()->FUN_00067730();
 (*(Key_10f0f0*)&DAT_004e0bc8).FUN_0027b040(parameter);
 Key_10f0f0 key = (*(Key_10f0f0*)&DAT_004e0bc8);
 FUN_000678d0()->FUN_00067110(&key);
 if (!((*(unsigned*)&DAT_004e0bd0) & 2)) { (*(unsigned*)&DAT_004e0bd0) |= 2; (*(Key_10f0f0*)&DAT_004e0bc0).FUN_0027af00(); atexit(FUN_00363e80); }
 (*(Key_10f0f0*)&DAT_004e0bc0).FUN_0027b040(parameter);
 unsigned first=(*(Key_10f0f0*)&DAT_004e0bc0).first, second=(*(Key_10f0f0*)&DAT_004e0bc0).second;
 Manager_10f0f0* m=FUN_000678d0();
 return first==m->first && second==m->second;
}
} }
} // namespace fn_0010f0f0


// 0x0010f220 hulkfight::ai::HulkActionRecentCondition::vfunc_6 (229 B): equivalent/0x0010f220.cpp [wrapped: conflict: FUN_000678d0; hulkfight::ai::HulkActionRecentCondition]
// sym: ?vfunc_6@HulkActionRecentCondition@ai@hulkfight@fn_0010f220@@UAE_NPAXPAUActor_10f220@4@0@Z @cf33af37ee36 @wc9a8ae01b2b0
namespace fn_0010f220 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::ai::HulkActionRecentCondition::vfunc_6 @ 0x0010f220

struct Token_10f220 { unsigned int low, high; void FUN_0027af00(); void FUN_0027b040(unsigned int); };
extern unsigned int DAT_00494b44, DAT_00494b60;
extern "C" void __cdecl FUN_00363ea0();
extern "C" void __cdecl FUN_00363eb0();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int __cdecl _atexit(void (__cdecl *)());
#endif

void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct ActorState_10f220 { int FUN_00059a30(); };
struct Actor_10f220 { ActorState_10f220* FUN_000592a0(); };
struct Manager_10f220 { char pad[0x388]; unsigned int low, high; void FUN_00067730(); };
Manager_10f220* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {
struct HulkActionRecentCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_10f220*, void*);
 char pad[12]; unsigned int action;
};
bool HulkActionRecentCondition::vfunc_6(void*, Actor_10f220* actor, void*) {
 if (!((*(unsigned int*)&DAT_004e0be8) & 1)) { (*(unsigned int*)&DAT_004e0be8) |= 1; (*(Token_10f220*)&DAT_004e0be0).FUN_0027af00(); _atexit(FUN_00363eb0); }
 if (!FUN_00344e74(actor, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
 if (!actor->FUN_000592a0()->FUN_00059a30()) return false;
 FUN_000678d0()->FUN_00067730();
 if (!((*(unsigned int*)&DAT_004e0be8) & 2)) { (*(unsigned int*)&DAT_004e0be8) |= 2; (*(Token_10f220*)&DAT_004e0bd8).FUN_0027af00(); _atexit(FUN_00363ea0); }
 (*(Token_10f220*)&DAT_004e0bd8).FUN_0027b040(action);
 unsigned int low = (*(Token_10f220*)&DAT_004e0bd8).low, high = (*(Token_10f220*)&DAT_004e0bd8).high;
 Manager_10f220* manager = FUN_000678d0();
 return low == manager->low && high == manager->high;
}
}}
} // namespace fn_0010f220

namespace fn_f49cf0cf {

// 0x0010f310 FUN_0010f310 (72 B): matches/0x0010f310.cpp
// sym: ??0HulkAction_10f310@fn_f49cf0cf@@QAE@HPAVRefObj_10f310@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
HulkAction_10f310::HulkAction_10f310(int target, RefObj_10f310* obj) {
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


// 0x0010f360 FUN_0010f360 (50 B): matches/0x0010f360.cpp
// sym: ??1HulkAction_10f360@fn_f49cf0cf@@QAE@XZ
HulkAction_10f360::~HulkAction_10f360() {
    vptr = hulk_at_0040dd50;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10f360 *)this)->FUN_002326a0();
}


// 0x0010f480 hulkfight::ai::AIHistoryNameCondition::vfunc_6 (394 B): equivalent/0x0010f480.cpp
// sym: ?FUN_0010f480@AIHistoryNameCondition@fn_f49cf0cf@@QAEDHPAVParams_10f480@fight@@H@Z @f501419946f7 @w814085068346
// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 38/38)
// hulkfight::ai::AIHistoryNameCondition::vfunc_6 @ 0x0010f480
char AIHistoryNameCondition::FUN_0010f480(int a1, fight::Params_10f480 *params, int a3)
{
    if (dynamic_cast<CFightParams_10f480 *>(params) == 0)
        return 0;

    Fighter_10f480 *fighter = params->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return 0;

    if (((*(unsigned*)&DAT_004e0c10) & 1) == 0) {
        (*(unsigned*)&DAT_004e0c10) |= 1;
        (*(Key_10f480*)&DAT_004e0c08).FUN_0027af00();
        atexit(FUN_00363ee0);
    }
    if (((*(unsigned*)&DAT_004e0c10) & 2) == 0) {
        (*(unsigned*)&DAT_004e0c10) |= 2;
        (*(Key_10f480*)&DAT_004e0c00).FUN_0027af00();
        atexit(FUN_00363ed0);
    }

    (*(Key_10f480*)&DAT_004e0c00).FUN_0027af70(&fighter->history);
    ((owners::Target_27b040 *)&((*(Key_10f480*)&DAT_004e0c08)))->FUN_0027b040((hulk_uintptr)name);

    int limit = (int)(__int64)threshold;
    int count = fighter->count;
    Key_10f480 *hist = &fighter->history;

    if (limit < 0) {
        if (mode == 3)
            return !hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
        return hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
    }
    if (limit == 0) {
        if (mode == 3)
            return hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
        return !hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
    }
    if (!hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08)))
        return 0;
    switch (mode) {
    case 0:
        return count < limit;
    case 1:
        return count <= limit;
    case 2:
        return count == limit;
    case 3:
        return count != limit;
    case 4:
        return count >= limit;
    case 5:
        return count > limit;
    }
    return 0;
}


// 0x0010f630 hulkfight::ai::KeyWordWaitCondition::vfunc_6 (300 B): equivalent/0x0010f630.cpp
// sym: ?FUN_0010f630@KeyWordWaitCondition@fn_f49cf0cf@@QAE_NHPAVParams_10f630@fight@@H@Z @d83561011bfa @w3ee0892168b2
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 22/24, incomplete)
// hulkfight::ai::KeyWordWaitCondition::vfunc_6 @ 0x0010f630
bool KeyWordWaitCondition::FUN_0010f630(int a1, fight::Params_10f630 *params, int a3)
{
    if (dynamic_cast<CFightParams_10f630 *>(params) == 0)
        return false;

    Fighter_10f630 *fighter = params->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;

    if ((DAT_004e0c20 & 1) == 0) {
        DAT_004e0c20 |= 1;
        (*(Key_10f630*)&DAT_004e0c18).FUN_0027af00();
        atexit(FUN_00363ef0);
    }
    ((owners::Target_27b040 *)&((*(Key_10f630*)&DAT_004e0c18)))->FUN_0027b040((hulk_uintptr)keyword);

    float limit = threshold;
    float value = fighter->FUN_00037290((*(Key_10f630*)&DAT_004e0c18).lo, (*(Key_10f630*)&DAT_004e0c18).hi);

    switch (mode) {
    case 0:
        return value < limit;
    case 1:
        return value <= limit;
    case 2:
        return value == limit;
    case 3:
        return value != limit;
    case 4:
        return value >= limit;
    case 5:
        return value > limit;
    }
    return false;
}


// 0x0010f780 FUN_0010f780 (86 B): matches/0x0010f780.cpp
// sym: ??0TokenSupressAction@fn_f49cf0cf@@QAE@HPAVRefObj_10f780@1@@Z
TokenSupressAction::TokenSupressAction(int a, RefObj_10f780* b) {
    vptr = hulk_at_0040dd6c;
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m1c = a;
    if (b != 0)
        b->AddRef();
    if (m20 != 0)
        m20->Release();
    m20 = b;
    hulk_intptr mgr = GetSingleton_000678d0();
    m24 = *(int*)(mgr + 0x368);
}


// 0x0010f7e0 FUN_0010f7e0 (50 B): matches/0x0010f7e0.cpp
// sym: ??1TokenSupressAction_10f7e0@fn_f49cf0cf@@QAE@XZ
TokenSupressAction_10f7e0::~TokenSupressAction_10f7e0() {
    vptr = g_vftable_10f7e0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10f7e0 *)this)->FUN_002326a0();
}


// 0x0010f820 FUN_0010f820 (72 B): matches/0x0010f820.cpp
// sym: ??0TokenAction_10f820@fn_f49cf0cf@@QAE@HPAVRefObj_10f820@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
TokenAction_10f820::TokenAction_10f820(int target, RefObj_10f820* obj) {
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


// 0x0010f870 FUN_0010f870 (50 B): matches/0x0010f870.cpp
// sym: ??1TokenAction_10f870@fn_f49cf0cf@@QAE@XZ
TokenAction_10f870::~TokenAction_10f870() {
    vptr = hulk_at_0040dd88;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10f870 *)this)->FUN_002326a0();
}


// 0x0010f8b0 FUN_0010f8b0 (72 B): matches/0x0010f8b0.cpp
// sym: ??0AIHistorySetAction_10f8b0@fn_f49cf0cf@@QAE@HPAVRefObj_10f8b0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
AIHistorySetAction_10f8b0::AIHistorySetAction_10f8b0(int target, RefObj_10f8b0* obj) {
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

} // namespace fn_f49cf0cf

// 0x0010f900 FUN_0010f900 (50 B): matches/0x0010f900.cpp
// sym: ?FUN_0010f900@AIHistorySetAction@ai@hulkfight@@QAEXXZ
void hulkfight::ai::AIHistorySetAction::FUN_0010f900() {
    *(void**)this = hulk_at_0040dda4;
    _ReadWriteBarrier();
    if ((*(Ref_10f900 * *)&this->f_20)) {
        (*(Ref_10f900 * *)&this->f_20)->Release();
        (*(Ref_10f900 * *)&this->f_20) = 0;
    }
    if ((*(Ref_10f900 * *)&this->f_1c))
        (*(Ref_10f900 * *)&this->f_1c) = 0;
    ((AIHistorySetAction_nv_10f900*)(((Action_10f900*)this)))->Finish_002326a0();
}

namespace fn_f49cf0cf {

// 0x0010f940 FUN_0010f940 (72 B): matches/0x0010f940.cpp
// sym: ??0SemaphoreWaitAction_10f940@fn_f49cf0cf@@QAE@HPAVRefObj_10f940@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
SemaphoreWaitAction_10f940::SemaphoreWaitAction_10f940(int target, RefObj_10f940* obj) {
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


// 0x0010f990 FUN_0010f990 (50 B): matches/0x0010f990.cpp
// sym: ??1SemaphoreWaitAction_10f990@fn_f49cf0cf@@QAE@XZ
SemaphoreWaitAction_10f990::~SemaphoreWaitAction_10f990() {
    vptr = hulk_at_0040ddc0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10f990 *)this)->FUN_002326a0();
}


// 0x0010f9d0 FUN_0010f9d0 (72 B): matches/0x0010f9d0.cpp
// sym: ??0SemaphoreClearAction_10f9d0@fn_f49cf0cf@@QAE@HPAVRefObj_10f9d0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
SemaphoreClearAction_10f9d0::SemaphoreClearAction_10f9d0(int target, RefObj_10f9d0* obj) {
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


// 0x0010fa20 FUN_0010fa20 (50 B): matches/0x0010fa20.cpp
// sym: ??1SemaphoreClearAction_10fa20@fn_f49cf0cf@@QAE@XZ
SemaphoreClearAction_10fa20::~SemaphoreClearAction_10fa20() {
    vptr = hulk_at_0040dddc;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10fa20 *)this)->FUN_002326a0();
}


// 0x0010fa60 FUN_0010fa60 (72 B): matches/0x0010fa60.cpp
// sym: ??0KeywordWaitAction_10fa60@fn_f49cf0cf@@QAE@HPAVRefObj_10fa60@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
KeywordWaitAction_10fa60::KeywordWaitAction_10fa60(int target, RefObj_10fa60* obj) {
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


// 0x0010fab0 FUN_0010fab0 (50 B): matches/0x0010fab0.cpp
// sym: ??1KeywordWaitAction_10fab0@fn_f49cf0cf@@QAE@XZ
KeywordWaitAction_10fab0::~KeywordWaitAction_10fab0() {
    vptr = hulk_at_0040ddf8;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10fab0 *)this)->FUN_002326a0();
}

} // namespace fn_f49cf0cf

// 0x0010fb20 fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_7 (6 B): matches/0x0010fb20.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0010fb30 fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_6 (30 B): matches/0x0010fb30.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_10fb30 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_10fb30*)&DAT_003f335c));
}


// 0x0010fb50 fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_8 (26 B): matches/0x0010fb50.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_18))(b);
}


// 0x0010fb70 fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2 (11 B): matches/0x0010fb70.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0010fba0 fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_6 (26 B): matches/0x0010fba0.cpp
// sym: ?vfunc_6@?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_10))(b);
}


// 0x0010fbc0 fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2 (11 B): matches/0x0010fbc0.cpp
// sym: ?vfunc_2@?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010fbf0 fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_6 (26 B): matches/0x0010fbf0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_10))(b);
}


// 0x0010fc10 fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2 (11 B): matches/0x0010fc10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f49cf0cf {

// 0x0010fc40 fight::ParamBranch<hulkfight::ai::AIFightNodeCondition>::vfunc_6 (12 B): matches/0x0010fc40.cpp
// sym: ?vfunc_6@ParamBranch@fn_f49cf0cf@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f49cf0cf

// 0x0010fc70 fight::ParamBool<hulkfight::ai::DefendingCondition>::vfunc_6 (26 B): matches/0x0010fc70.cpp
// sym: ?vfunc_6@?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::DefendingCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::DefendingCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::DefendingCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::DefendingCondition>::**)(int))&this->f_10))(b);
}


// 0x0010fc90 fight::ParamBool<hulkfight::ai::DefendingCondition>::vfunc_2 (11 B): matches/0x0010fc90.cpp
// sym: ?vfunc_2@?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::DefendingCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010fcd0 fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_7 (6 B): matches/0x0010fcd0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0010fce0 fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_6 (30 B): matches/0x0010fce0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_10fce0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_10fce0*)&DAT_003f335c));
}


// 0x0010fd00 fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_8 (26 B): matches/0x0010fd00.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::**)(int))&this->f_18))(b);
}


// 0x0010fd20 fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_2 (11 B): matches/0x0010fd20.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0010fd50 fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::vfunc_6 (26 B): matches/0x0010fd50.cpp
// sym: ?vfunc_6@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::AIHistoryNameCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::**)(int))&this->f_10))(b);
}


// 0x0010fd70 fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::vfunc_2 (11 B): matches/0x0010fd70.cpp
// sym: ?vfunc_2@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010fda0 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::vfunc_6 (26 B): matches/0x0010fda0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::**)(int))&this->f_10))(b);
}


// 0x0010fdc0 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::vfunc_2 (11 B): matches/0x0010fdc0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010fe00 fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_7 (6 B): matches/0x0010fe00.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0010fe10 fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_6 (30 B): matches/0x0010fe10.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_10fe10 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_10fe10*)&DAT_003f335c));
}


// 0x0010fe30 fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_8 (26 B): matches/0x0010fe30.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::**)(int))&this->f_18))(b);
}


// 0x0010fe50 fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_2 (11 B): matches/0x0010fe50.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0010fe80 fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::vfunc_6 (26 B): matches/0x0010fe80.cpp
// sym: ?vfunc_6@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::HulkActionLargestCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::**)(int))&this->f_10))(b);
}


// 0x0010fea0 fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::vfunc_2 (11 B): matches/0x0010fea0.cpp
// sym: ?vfunc_2@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010fee0 fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_7 (6 B): matches/0x0010fee0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0010fef0 fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_6 (30 B): matches/0x0010fef0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_10fef0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_10fef0*)&DAT_003f335c));
}


// 0x0010ff10 fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_8 (26 B): matches/0x0010ff10.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::**)(int))&this->f_18))(b);
}


// 0x0010ff30 fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_2 (11 B): matches/0x0010ff30.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0010ff60 fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::vfunc_6 (26 B): matches/0x0010ff60.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::**)(int))&this->f_10))(b);
}


// 0x0010ff80 fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::vfunc_2 (11 B): matches/0x0010ff80.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010ffc0 fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_7 (6 B): matches/0x0010ffc0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0010ffd0 fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_6 (30 B): matches/0x0010ffd0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_10ffd0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_10ffd0*)&DAT_003f335c));
}


// 0x0010fff0 fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_8 (26 B): matches/0x0010fff0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::**)(int))&this->f_18))(b);
}


// 0x00110010 fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_2 (11 B): matches/0x00110010.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00110040 fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::vfunc_6 (26 B): matches/0x00110040.cpp
// sym: ?vfunc_6@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::HulkActionRecentCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::**)(int))&this->f_10))(b);
}


// 0x00110060 fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::vfunc_2 (11 B): matches/0x00110060.cpp
// sym: ?vfunc_2@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110090 fight::ParamBool<hulkfight::ai::LeashedCondition>::vfunc_6 (26 B): matches/0x00110090.cpp
// sym: ?vfunc_6@?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::LeashedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::LeashedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::LeashedCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::LeashedCondition>::**)(int))&this->f_10))(b);
}


// 0x001100b0 fight::ParamBool<hulkfight::ai::LeashedCondition>::vfunc_2 (11 B): matches/0x001100b0.cpp
// sym: ?vfunc_2@?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::LeashedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001100f0 fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_7 (6 B): matches/0x001100f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00110100 fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_6 (30 B): matches/0x00110100.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
 // namespace fight
template <> void* fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_6(int unused, int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(const char ** *)&this->f_10)[index]);
    return (void*)(((char*)&DAT_003f335c));
}


// 0x00110120 fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_8 (26 B): matches/0x00110120.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::**)(int))&this->f_18))(b);
}


// 0x00110140 fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_2 (11 B): matches/0x00110140.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00110170 fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::vfunc_6 (26 B): matches/0x00110170.cpp
// sym: ?vfunc_6@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::KeyWordWaitCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::**)(int))&this->f_10))(b);
}


// 0x00110190 fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::vfunc_2 (11 B): matches/0x00110190.cpp
// sym: ?vfunc_2@?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001101c0 fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::vfunc_6 (26 B): matches/0x001101c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::**)(int))&this->f_10))(b);
}


// 0x001101e0 fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::vfunc_2 (11 B): matches/0x001101e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::vfunc_2() {
    return this->f_10 == 0;
}

