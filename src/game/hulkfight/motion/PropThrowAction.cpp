// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00183510..0x00185570 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropThrowAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd95142d {
#define TREE_TU_END }
namespace fn_fd95142d {} using namespace fn_fd95142d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd95142d {
struct Mgr_183510;
struct Actor_183510;
struct Player_183510;
} // namespace fn_fd95142d
namespace fight {
class Params_183510 {
public:
    virtual void v0();
    Mgr_183510 *FUN_000592a0();
};
}
namespace fn_fd95142d {
class CFightParams_183510 : public fight::Params_183510 {
public:
    virtual void v1();
};
struct StateInfo_183510 {
    char pad0[8];
    unsigned int idLo;      // 0x08
    unsigned int idHi;      // 0x0c
};
struct StateTable_183510 {
    char pad0[0x1c];
    StateInfo_183510 **states;     // 0x1c
};
struct Actor_183510 {
    char pad0[0x40];
    int state;              // 0x40
    char pad44[0x98 - 0x44];
    StateTable_183510 *table;      // 0x98
};
struct Player_183510 {
    char pad0[0x128];
    Actor_183510 *self;            // 0x128
};
struct Mgr_183510 {
    Player_183510 *FUN_00059a30();
};
struct Scaler_1837e0 {
    float FUN_001dd190(int lo, int hi);
};
} // namespace fn_fd95142d
struct World {
    char pad0[0xc];
    Scaler_1837e0 *scaler;
};
namespace fight {
class Params_1837e0 {
  public:
    virtual void v0();
    virtual void v1();
};
}
namespace fn_fd95142d {
class CFightParams_1837e0 : public fight::Params_1837e0 {
  public:
    virtual void v2();
};
struct Meter_1837e0 {
    float FUN_001d8160();
};
struct Fighter_1837e0 {
    char pad0[0x128];
    Meter_1837e0 *defaultMeter;
};
void *__fastcall FUN_000592a0(void *owner);
Fighter_1837e0 *__fastcall FUN_00059a30(void *holder);
bool __cdecl FUN_00018960(float a, float b, float eps);
class PropMassCondition {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual bool vfunc_6(void *unused, fight::Params_1837e0 *params, int unused2);
    char pad04[0xc - 4];
    int slot;
    unsigned int mode;
    char pad14[4];
    int keyLo;
    int keyHi;
    float scale;
};
class RefObj_183950 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183950 {
  public:
    Action_183950();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropActorToPropAction_183950 : public Action_183950 {
  public:
    int mTarget;
    RefObj_183950* mObj;
    PropActorToPropAction_183950(int target, RefObj_183950* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00419608[];
class Ref_1839a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1839a0 {
  public:
    void* vptr;
};
class PropActorToPropAction_1839a0 : public Action_1839a0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1839a0* m20;
    ~PropActorToPropAction_1839a0();
};
struct PropActorToPropAction_nv_1839e0 {
    bool helper_00181d30();
};
struct Obj_183a00 {
    char pad[0x15];
    u8 flag;
};
struct PropActorToPropAction_nv_183a00 {
    void FUN_00181d30();
};
class RefObj_183a10 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183a10 {
  public:
    Action_183a10();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropActorThinkingAction_183a10 : public Action_183a10 {
  public:
    int mTarget;
    RefObj_183a10* mObj;
    PropActorThinkingAction_183a10(int target, RefObj_183a10* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00419624[];
class Ref_183a60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183a60 {
  public:
    void* vptr;
};
class PropActorThinkingAction_183a60 : public Action_183a60 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183a60* m20;
    ~PropActorThinkingAction_183a60();
};
class Obj_183aa0 {
  public:
    virtual void A();
    virtual void B();
};
class Action_183aa0 {
  public:
    virtual void FnX_00018b30();
    Action_183aa0();
};
class PropAnimationAction_183aa0 : public Action_183aa0 {
  public:
    virtual void FnA_00018b40();
    virtual int FnB_00188960(char);
    char pad[0x18];
    int m1c;
    Obj_183aa0* m20;
    int m24;
    int m28;
    PropAnimationAction_183aa0(int, Obj_183aa0*);
};
extern void* hulk_at_00419640[];
class Ref_183af0 {
  public:
    virtual void F0();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int);
};
class Action_183af0 {
  public:
    void* vptr;
};
void Free(void*) throw();
class PropAnimationAction_183af0 : public Action_183af0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183af0* m20;
    Ref_183af0* m24;
    Ref_183af0* m28;
    ~PropAnimationAction_183af0() throw();
};
class Ref {
  public:
    virtual void AddRef();
    virtual void release();
    void Release() { release(); }
};
class Anim {
    char pad[0x40];

  public:
    int state;
    void set_0027e650(int, int, int);
};
class RefObj_183b80 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183b80 {
  public:
    Action_183b80();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropAddToMissileCountAction_183b80 : public Action_183b80 {
  public:
    int mTarget;
    RefObj_183b80* mObj;
    PropAddToMissileCountAction_183b80(int target, RefObj_183b80* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_0041965c[];
class Ref_183bd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183bd0 {
  public:
    void* vptr;
};
class PropAddToMissileCountAction_183bd0 : public Action_183bd0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183bd0* m20;
    ~PropAddToMissileCountAction_183bd0();
};
class RefObj_183c10 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183c10 {
  public:
    Action_183c10();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropAddToCollisionAction_183c10 : public Action_183c10 {
  public:
    int mTarget;
    RefObj_183c10* mObj;
    PropAddToCollisionAction_183c10(int target, RefObj_183c10* obj);
    virtual void Execute_00018b40();
};
class Ref_183c60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183c60 {
  public:
    void* vptr;
};
class PropAddToCollisionAction_183c60 : public Action_183c60 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_183c60* m20;
    ~PropAddToCollisionAction_183c60() throw();
};
class RefObj_183ca0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183ca0 {
  public:
    Action_183ca0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropSetStateByIndexAction_183ca0 : public Action_183ca0 {
  public:
    int mTarget;
    RefObj_183ca0* mObj;
    PropSetStateByIndexAction_183ca0(int target, RefObj_183ca0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00419694[];
class Ref_183cf0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183cf0 {
  public:
    void* vptr;
};
class PropSetStateByIndexAction_183cf0 : public Action_183cf0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183cf0* m20;
    ~PropSetStateByIndexAction_183cf0();
};
class RefObj_183db0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183db0 {
  public:
    Action_183db0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropSetStateByNameAction_183db0 : public Action_183db0 {
  public:
    int mTarget;
    RefObj_183db0* mObj;
    PropSetStateByNameAction_183db0(int target, RefObj_183db0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004196b0[];
class Ref_183e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183e00 {
  public:
    void* vptr;
};
class PropSetStateByNameAction_183e00 : public Action_183e00 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183e00* m20;
    ~PropSetStateByNameAction_183e00();
};
class RefObj_183e40 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183e40 {
  public:
    Action_183e40();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropSpawnAction_183e40 : public Action_183e40 {
  public:
    int mTarget;
    RefObj_183e40* mObj;
    PropSpawnAction_183e40(int target, RefObj_183e40* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004196cc[];
class Ref_183e90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183e90 {
  public:
    void* vptr;
};
class PropSpawnAction_183e90 : public Action_183e90 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183e90* m20;
    ~PropSpawnAction_183e90();
};
class RefObj_183ed0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183ed0 {
  public:
    Action_183ed0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropDropAction_183ed0 : public Action_183ed0 {
  public:
    int mTarget;
    RefObj_183ed0* mObj;
    PropDropAction_183ed0(int target, RefObj_183ed0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_004196e8[];
class Ref_183f20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183f20 {
  public:
    void* vptr;
};
class PropDropAction_183f20 : public Action_183f20 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183f20* m20;
    ~PropDropAction_183f20();
};
class RefObj_183f60 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183f60 {
  public:
    Action_183f60();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropDamageAction_183f60 : public Action_183f60 {
  public:
    int mTarget;
    RefObj_183f60* mObj;
    PropDamageAction_183f60(int target, RefObj_183f60* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00419704[];
class Ref_183fb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183fb0 {
  public:
    void* vptr;
};
class PropDamageAction_183fb0 : public Action_183fb0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183fb0* m20;
    ~PropDamageAction_183fb0();
};
class RefObj_183ff0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_183ff0 {
  public:
    Action_183ff0();
    virtual void Update_00018b30();
    char pad[0x18];
};
class GrapplePropDamageAction_183ff0 : public Action_183ff0 {
  public:
    int mTarget;
    RefObj_183ff0* mObj;
    GrapplePropDamageAction_183ff0(int target, RefObj_183ff0* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00419720[];
class Ref_184040 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_184040 {
  public:
    void* vptr;
};
class GrapplePropDamageAction_184040 : public Action_184040 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_184040* m20;
    ~GrapplePropDamageAction_184040();
};
class RefObj_184080 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_184080 {
  public:
    Action_184080();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropDestroyAction_184080 : public Action_184080 {
  public:
    int mTarget;
    RefObj_184080* mObj;
    PropDestroyAction_184080(int target, RefObj_184080* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_0041973c[];
class Ref_1840d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1840d0 {
  public:
    void* vptr;
};
class PropDestroyAction_1840d0 : public Action_1840d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1840d0* m20;
    ~PropDestroyAction_1840d0();
};
class RefObj_184110 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_184110 {
  public:
    Action_184110();
    virtual void Update_00018b30();
    char pad[0x18];
};
class PropThrowAction_184110 : public Action_184110 {
  public:
    int mTarget;
    RefObj_184110* mObj;
    PropThrowAction_184110(int target, RefObj_184110* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00419758[];
class Ref_184160 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_184160 {
  public:
    void* vptr;
};
class PropThrowAction_184160 : public Action_184160 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_184160* m20;
    ~PropThrowAction_184160();
};
class RefObj_184750 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_184750 {
  public:
    Action_184750();
    virtual void Update_00018b30();
    char pad[0x18];
};
class ShieldArcAction_184750 : public Action_184750 {
  public:
    int mTarget;
    RefObj_184750* mObj;
    ShieldArcAction_184750(int target, RefObj_184750* obj);
    virtual void Execute_00018b40();
};
extern "C" char DAT_00419774[];
class Ref_1847a0 {
  public:
    virtual void A();
    virtual void Release();
};
class ShieldArcAction {
  public:
    volatile hulk_intptr vft;
    char pad[0x18];
    int m1c;
    Ref_1847a0* volatile m20;
    void Cleanup();
};
struct Source {
    char pad[0x20];
    int value;
};
class Action_1847e0 {
  public:
    virtual void dummy();
    Action_1847e0();
    char pad[0x18];
};
struct Slot {
    Source* ptr;
    Slot() : ptr(0) {}
};
class BallAndChainSpinAction : public Action_1847e0 {
  public:
    virtual void dummy();
    BallAndChainSpinAction(Source*, Ref*);
    Slot source;
    Ref* ref;
    int val;
};
extern void* hulk_at_00419790[];
class Ref_184840 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_184840 {
  public:
    void* vptr;
};
class BallAndChainSpinAction_184840 : public Action_184840 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_184840* m20;
    ~BallAndChainSpinAction_184840();
};
class Ref_184880 {
  public:
    virtual void Fn();
    virtual void Release();
};
extern int hulk_at_004197ac;
class BallAndChainShootAction : public Ctor_00232660 {
  public:
    BallAndChainShootAction(int, Ref_184880*);
    hulk_intptr vt;
    char pad04[0x18];
    int mA;
    Ref_184880* mRef;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
};
class Ref_184ef0 {
  public:
    virtual void A();
    virtual void B();
};
class Action_184ef0 {
  public:
    Action_184ef0();
    virtual void V0();
    char pad[0x18];
};
class BallAndChainReturnAction_184ef0 : public Action_184ef0 {
  public:
    int mArg;
    Ref_184ef0* mRef;
    int x24, x28, x2c, x30, x34;
    float x38;
    int x3c, x40, x44;
    BallAndChainReturnAction_184ef0(int, Ref_184ef0*);
    virtual void V0();
};
extern "C" char DAT_004197c8[];
class Ref_184f60 {
  public:
    virtual void A();
    virtual void B();
};
class PropThrowAction_184f60 {
  public:
};
class BallAndChainReturnAction {
  public:
    volatile hulk_intptr vptr;
    char pad[0x18];
    void* mOne;
    Ref_184f60* mTwo;
    void Reset();
};
class CStageCondition_184fe0;
class ParamValue_184fe0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_184fe0 : public ParamValue_184fe0 {
  public:
    int pad;
};
class CStageCondition_185030;
class ParamValue_185030 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185030 : public ParamValue_185030 {
  public:
    int pad;
};
class CStageCondition_185080;
class ParamValue_185080 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185080 : public ParamValue_185080 {
  public:
    int pad;
};
struct CAxisArcCondition_1850c0;
class CStageCondition_1850d0 {};
class ParamValue_1850d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1850d0 : public ParamValue_1850d0 {
  public:
    virtual void f();
};
class CStageCondition_185160;
class ParamValue_185160 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185160 : public ParamValue_185160 {
  public:
    int pad;
};
struct CAxisArcCondition_1851a0;
class CStageCondition_1851b0 {};
class ParamValue_1851b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1851b0 : public ParamValue_1851b0 {
  public:
    virtual void f();
};
class CStageCondition_185240;
class ParamValue_185240 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185240 : public ParamValue_185240 {
  public:
    int pad;
};
class CStageCondition_185290;
class ParamValue_185290 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185290 : public ParamValue_185290 {
  public:
    int pad;
};
struct CAxisArcCondition_1852d0;
class CStageCondition_1852e0 {};
class ParamValue_1852e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1852e0 : public ParamValue_1852e0 {
  public:
    virtual void f();
};
class CStageCondition_185370;
class ParamValue_185370 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185370 : public ParamValue_185370 {
  public:
    int pad;
};
class CStageCondition_1853c0;
class ParamValue_1853c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1853c0 : public ParamValue_1853c0 {
  public:
    int pad;
};
class CStageCondition_185410;
class ParamValue_185410 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185410 : public ParamValue_185410 {
  public:
    int pad;
};
class CStageCondition_185460;
class ParamValue_185460 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185460 : public ParamValue_185460 {
  public:
    int pad;
};
class CStageCondition_1854b0;
class ParamValue_1854b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1854b0 : public ParamValue_1854b0 {
  public:
    int pad;
};
struct CAxisArcCondition_1854f0;
class CStageCondition_185500 {};
class ParamValue_185500 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_185500 : public ParamValue_185500 {
  public:
    virtual void f();
};

} // namespace fn_fd95142d

// 0x00183510 hulkfight::motion::PropStateByNameCondition::vfunc_6 (163 B): equivalent/0x00183510.cpp
// sym: ?vfunc_6@PropStateByNameCondition@motion@hulkfight@@UAE_NPAX00@Z @79b417217c12 @w3b540a2b88c6
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 22/22)
// hulkfight::motion::PropStateByNameCondition::vfunc_6 @ 0x00183510
bool hulkfight::motion::PropStateByNameCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_183510 * params = (fight::Params_183510 *)__p1; int c = (int)__p2;

    if (dynamic_cast<CFightParams_183510 *>(params) == 0)
        return false;
    Player_183510 *player = params->FUN_000592a0()->FUN_00059a30();
    if (player == 0)
        return false;
    Actor_183510 *actor;
    if (this->attachmentIndex < 0) {
        actor = player->self;
    } else {
        if (this->attachmentIndex >= 8)
            return false;
        actor = ((Actor_183510 *)((owners::C_35ef0 *)player)->FUN_00035ef0((hulk_intptr)(this->attachmentIndex)));
    }
    if (actor == 0)
        return false;
    StateInfo_183510 *info = actor->table->states[actor->state];
    unsigned int lo = info->idLo;
    unsigned int hi = info->idHi;
    bool same = (lo == (*(unsigned int *)&this->state) && hi == (*(unsigned int *)&this->f_1c));
    if (this->compare == 0)
        return same;
    if (this->compare == 1)
        return !same;
    return false;
}


// 0x001835c0 hulkfight::motion::GrapplePropStateByNameCondition::vfunc_6 (167 B): equivalent/0x001835c0.cpp [wrapped: conflict: CFightParams; fight::Params; hulkfight::motion::GrapplePropStateByNameCondition]
// sym: ?vfunc_6@GrapplePropStateByNameCondition@motion@hulkfight@fn_001835c0@@UAE_NHPAVParams@fight@4@H@Z @da2da5d2ce88 @w6f00928608f8
namespace fn_001835c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 22/22)
// hulkfight::motion::GrapplePropStateByNameCondition::vfunc_6 @ 0x001835c0
struct Mgr_1835c0;
struct Actor_1835c0;
struct Player_1835c0;

namespace fight {
class Params {
public:
    virtual void v0();
    Mgr_1835c0 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

struct StateInfo_1835c0 {
    char pad0[8];
    unsigned int idLo;      // 0x08
    unsigned int idHi;      // 0x0c
};

struct StateTable_1835c0 {
    char pad0[0x1c];
    StateInfo_1835c0 **states;     // 0x1c
};

struct Actor_1835c0 {
    char pad0[0x40];
    int state;              // 0x40
    char pad44[0x98 - 0x44];
    StateTable_1835c0 *table;      // 0x98
};

struct Roster_1835c0 {
    char pad0[0x128];
    Actor_1835c0 *self;            // 0x128
    Actor_1835c0 *FUN_00035ef0(int index);
};

struct Player_1835c0 {
    char pad0[0x338];
    Roster_1835c0 *roster;         // 0x338
};

struct Mgr_1835c0 {
    Player_1835c0 *FUN_00059a30();
};

namespace hulkfight {
namespace motion {
class GrapplePropStateByNameCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x0c - 4];
    int playerIndex;        // 0x0c
    int mode;               // 0x10
    char pad14[4];
    unsigned int wantLo;    // 0x18
    unsigned int wantHi;    // 0x1c
};
}
}

bool hulkfight::motion::GrapplePropStateByNameCondition::vfunc_6(int a, fight::Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;
    Player_1835c0 *player = params->FUN_000592a0()->FUN_00059a30();
    Roster_1835c0 *roster = player->roster;
    if (roster == 0)
        return false;
    Actor_1835c0 *actor;
    if (playerIndex < 0) {
        actor = roster->self;
    } else {
        if (playerIndex >= 8)
            return false;
        actor = roster->FUN_00035ef0(playerIndex);
    }
    if (actor == 0)
        return false;
    StateInfo_1835c0 *info = actor->table->states[actor->state];
    unsigned int lo = info->idLo;
    unsigned int hi = info->idHi;
    bool same = (lo == wantLo && hi == wantHi);
    if (mode == 0)
        return same;
    if (mode == 1)
        return !same;
    return false;
}
} // namespace fn_001835c0


// 0x00183670 hulkfight::motion::SmartPropGrabbableCondition::vfunc_6 (363 B): equivalent/0x00183670.cpp [wrapped: conflict: FUN_000592a0]
// sym: ?vfunc_6@SmartPropGrabbableCondition@fn_00183670@@UAE_NHPAVParams_183670@fight@2@H@Z @95f73904d7a4 @w72c5c53689ca
namespace fn_00183670 {
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 38/40, incomplete)
// hulkfight::motion::SmartPropGrabbableCondition::vfunc_6 @ 0x00183670
struct Entry_183670 {
    int pad0[2];
    int id;
    int pad0c;
};

struct Group_183670 {
    char pad0[0x24];
    int count;
    Entry_183670 *entries;
};

struct Table_183670 {
    char pad0[0x1c];
    Group_183670 **groups;
};

class Listener_183670 {
public:
    int FUN_001d5e80(int x);
    int FUN_001d5dd0(int x);
};

struct Info_183670 {
    char pad0[0x40];
    int index;
    char pad44[0xec - 0x44];
    Listener_183670 *listener;
};

struct Target_183670 {
    char pad0[8];
    Info_183670 *info;
};

struct Stats_183670 {
    char pad0[0x3a4];
    Target_183670 *target;
};

struct Fighter_183670 { char pad[4]; };
Fighter_183670 *__fastcall FUN_000592a0(void *owner);
Stats_183670 *__fastcall FUN_00059a30(Fighter_183670 *f);

namespace fight {
class Params_183670 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    void FUN_00059790(Target_183670 *t);
};
}

class CFightParams_183670 : public fight::Params_183670 {
public:
    virtual void v3();
    virtual void v4();
};

class SmartPropGrabbableCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg1, fight::Params_183670 *params, int arg3);
    char pad04[8];
    char useId;
    char pad0d[3];
    int id;
    char useFlag;
    char flag;
    char useValue;
    char pad17;
    int value;
    char useOther;
    char pad1d[3];
    int other;
    char useIndex;
    char pad25[3];
    int wanted;
};

bool SmartPropGrabbableCondition::vfunc_6(int arg1, fight::Params_183670 *params, int arg3)
{
    if (dynamic_cast<CFightParams_183670 *>(params) == 0)
        return false;

    Stats_183670 *stats = FUN_00059a30(FUN_000592a0(params));
    Target_183670 *target = stats->target;
    if (target == 0)
        return false;

    bool ok = true;
    char useId = this->useId;
    if (useId || this->useFlag || this->useValue || this->useOther) {
        Info_183670 *info = target->info;
        Listener_183670 *listener = info->listener;
        if (useId) {
            int want = this->id;
            ok = ((owners::C_1d4de0 *)listener)->FUN_001d4de0() == want;
        }
        if (this->useFlag) {
            char want = this->flag;
            ok &= ((char)((owners::Obj_1d4e20 *)listener)->FUN_001d4e20()) == want;
        }
        if (this->useValue) {
            int want = this->value;
            ok &= listener->FUN_001d5e80(info->index) == want;
        }
        if (this->useOther) {
            int want = this->other;
            ok &= listener->FUN_001d5dd0(info->index) == want;
        }
        if (this->useIndex) {
            int idx = info->index;
            bool found = false;
            if (idx >= 0) {
                Group_183670 *g = ((Table_183670 *)((owners::C_1d4fc0 *)listener)->FUN_001d4fc0())->groups[idx];
                int n = g->count;
                if (n > 0) {
                    Entry_183670 *e = g->entries;
                    int want = this->wanted;
                    for (int i = 0; i < n; i++) {
                        if (e[i].id == want) {
                            found = true;
                            break;
                        }
                    }
                }
            }
            ok &= found;
        }
    }
    if (ok)
        params->FUN_00059790(target);
    return ok;
}
} // namespace fn_00183670

namespace fn_fd95142d {

// 0x001837e0 hulkfight::motion::PropMassCondition::vfunc_6 (336 B): equivalent/0x001837e0.cpp
// sym: ?vfunc_6@PropMassCondition@fn_fd95142d@@UAE_NPAXPAVParams_1837e0@fight@@H@Z @fbea869bce8a @wf0b2ecaaebd2
// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 26/26)
// hulkfight::motion::PropMassCondition::vfunc_6 @ 0x001837e0
bool PropMassCondition::vfunc_6(void *unused, fight::Params_1837e0 *params, int unused2)
{
    if (dynamic_cast<CFightParams_1837e0 *>(params) == 0)
        return false;
    Fighter_1837e0 *fighter = FUN_00059a30(FUN_000592a0(params));
    if (!fighter)
        return false;

    Meter_1837e0 *meter;
    if (slot < 0) {
        meter = fighter->defaultMeter;
    } else {
        if (slot >= 8)
            return false;
        meter = ((Meter_1837e0 *)((owners::C_35ef0 *)fighter)->FUN_00035ef0((hulk_intptr)slot));
    }
    if (!meter)
        return false;

    float cur = meter->FUN_001d8160();
    float factor = 1.0f;
    if ((keyLo | keyHi) != 0)
        factor = DAT_004dd700->scaler->FUN_001dd190(keyLo, keyHi);
    float thr = factor * scale;
    switch (mode) {
    case 0:
        return cur < thr;
    case 1:
        return cur <= thr;
    case 2:
        return FUN_00018960(cur, thr, 1e-5f);
    case 3:
        return !FUN_00018960(cur, thr, 1e-5f);
    case 4:
        return cur >= thr;
    case 5:
        return cur > thr;
    }
    return false;
}


// 0x00183950 FUN_00183950 (72 B): matches/0x00183950.cpp
// sym: ??0PropActorToPropAction_183950@fn_fd95142d@@QAE@HPAVRefObj_183950@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropActorToPropAction_183950::PropActorToPropAction_183950(int target, RefObj_183950* obj) {
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


// 0x001839a0 FUN_001839a0 (50 B): matches/0x001839a0.cpp
// sym: ??1PropActorToPropAction_1839a0@fn_fd95142d@@QAE@XZ
PropActorToPropAction_1839a0::~PropActorToPropAction_1839a0() {
    vptr = hulk_at_00419608;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1839a0 *)this)->FUN_002326a0();
}

} // namespace fn_fd95142d

// 0x001839e0 hulkfight::motion::PropActorToPropAction::vfunc_3 (23 B): matches/0x001839e0.cpp
// sym: ?vfunc_3@PropActorToPropAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropActorToPropAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) { void * a = (void *)__p0; void * b = (void *)__p1;

    if (*((unsigned char*)(*(void * *)&this->f_1c) + 0x15) == 0)
        return ((PropActorToPropAction_nv_1839e0*)this)->helper_00181d30();
    return true;
}


// 0x00183a00 hulkfight::motion::PropActorToPropAction::vfunc_4 (16 B): matches/0x00183a00.cpp
// sym: ?vfunc_4@PropActorToPropAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::PropActorToPropAction::vfunc_4() {
    if ((*(Obj_183a00 * *)&this->f_1c)->flag)
        ((PropActorToPropAction_nv_183a00*)this)->FUN_00181d30();
}

namespace fn_fd95142d {

// 0x00183a10 FUN_00183a10 (72 B): matches/0x00183a10.cpp
// sym: ??0PropActorThinkingAction_183a10@fn_fd95142d@@QAE@HPAVRefObj_183a10@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropActorThinkingAction_183a10::PropActorThinkingAction_183a10(int target, RefObj_183a10* obj) {
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


// 0x00183a60 FUN_00183a60 (50 B): matches/0x00183a60.cpp
// sym: ??1PropActorThinkingAction_183a60@fn_fd95142d@@QAE@XZ
PropActorThinkingAction_183a60::~PropActorThinkingAction_183a60() {
    vptr = hulk_at_00419624;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183a60 *)this)->FUN_002326a0();
}


// 0x00183aa0 FUN_00183aa0 (74 B): matches/0x00183aa0.cpp
// sym: ??0PropAnimationAction_183aa0@fn_fd95142d@@QAE@HPAVObj_183aa0@1@@Z
// Same code shape as 0x00174c10 (propagated; names are from that function)
PropAnimationAction_183aa0::PropAnimationAction_183aa0(int v, Obj_183aa0* p) : Action_183aa0() {
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


// 0x00183af0 FUN_00183af0 (74 B): matches/0x00183af0.cpp
// sym: ??1PropAnimationAction_183af0@fn_fd95142d@@QAE@XZ
PropAnimationAction_183af0::~PropAnimationAction_183af0() throw() {
    vptr = hulk_at_00419640;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    ((fight::Action *)(Action_183af0 *)this)->FUN_002326a0();
}

} // namespace fn_fd95142d

// 0x00183b40 hulkfight::motion::PropAnimationAction::vfunc_4 (61 B): matches/0x00183b40.cpp
// sym: ?vfunc_4@PropAnimationAction@motion@hulkfight@@UAEXXZ
 // namespace hulkfight
void hulkfight::motion::PropAnimationAction::vfunc_4() {
    if ((*(Anim * *)&this->f_24)) {
        if ((*(Anim * *)&this->f_24)->state == -1 && ((owners::C_27cb70 *)((*(Anim * *)&this->f_24)))->FUN_0027cb70() == (hulk_intptr)(*(Ref * *)&this->f_28))
            (*(Anim * *)&this->f_24)->set_0027e650(0, 0, 0);
        if ((*(Ref * *)&this->f_28)) {
            (*(Ref * *)&this->f_28)->release();
            (*(Ref * *)&this->f_28) = 0;
        }
    }
}

namespace fn_fd95142d {

// 0x00183b80 FUN_00183b80 (72 B): matches/0x00183b80.cpp
// sym: ??0PropAddToMissileCountAction_183b80@fn_fd95142d@@QAE@HPAVRefObj_183b80@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropAddToMissileCountAction_183b80::PropAddToMissileCountAction_183b80(int target, RefObj_183b80* obj) {
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


// 0x00183bd0 FUN_00183bd0 (50 B): matches/0x00183bd0.cpp
// sym: ??1PropAddToMissileCountAction_183bd0@fn_fd95142d@@QAE@XZ
PropAddToMissileCountAction_183bd0::~PropAddToMissileCountAction_183bd0() {
    vptr = hulk_at_0041965c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183bd0 *)this)->FUN_002326a0();
}


// 0x00183c10 FUN_00183c10 (72 B): matches/0x00183c10.cpp
// sym: ??0PropAddToCollisionAction_183c10@fn_fd95142d@@QAE@HPAVRefObj_183c10@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropAddToCollisionAction_183c10::PropAddToCollisionAction_183c10(int target, RefObj_183c10* obj) {
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


// 0x00183c60 FUN_00183c60 (50 B): matches/0x00183c60.cpp
// sym: ??1PropAddToCollisionAction_183c60@fn_fd95142d@@QAE@XZ
PropAddToCollisionAction_183c60::~PropAddToCollisionAction_183c60() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183c60 *)this)->FUN_002326a0();
}


// 0x00183ca0 FUN_00183ca0 (72 B): matches/0x00183ca0.cpp
// sym: ??0PropSetStateByIndexAction_183ca0@fn_fd95142d@@QAE@HPAVRefObj_183ca0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropSetStateByIndexAction_183ca0::PropSetStateByIndexAction_183ca0(int target, RefObj_183ca0* obj) {
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


// 0x00183cf0 FUN_00183cf0 (50 B): matches/0x00183cf0.cpp
// sym: ??1PropSetStateByIndexAction_183cf0@fn_fd95142d@@QAE@XZ
PropSetStateByIndexAction_183cf0::~PropSetStateByIndexAction_183cf0() {
    vptr = hulk_at_00419694;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183cf0 *)this)->FUN_002326a0();
}


// 0x00183db0 FUN_00183db0 (72 B): matches/0x00183db0.cpp
// sym: ??0PropSetStateByNameAction_183db0@fn_fd95142d@@QAE@HPAVRefObj_183db0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropSetStateByNameAction_183db0::PropSetStateByNameAction_183db0(int target, RefObj_183db0* obj) {
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


// 0x00183e00 FUN_00183e00 (50 B): matches/0x00183e00.cpp
// sym: ??1PropSetStateByNameAction_183e00@fn_fd95142d@@QAE@XZ
PropSetStateByNameAction_183e00::~PropSetStateByNameAction_183e00() {
    vptr = hulk_at_004196b0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183e00 *)this)->FUN_002326a0();
}


// 0x00183e40 FUN_00183e40 (72 B): matches/0x00183e40.cpp
// sym: ??0PropSpawnAction_183e40@fn_fd95142d@@QAE@HPAVRefObj_183e40@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropSpawnAction_183e40::PropSpawnAction_183e40(int target, RefObj_183e40* obj) {
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


// 0x00183e90 FUN_00183e90 (50 B): matches/0x00183e90.cpp
// sym: ??1PropSpawnAction_183e90@fn_fd95142d@@QAE@XZ
PropSpawnAction_183e90::~PropSpawnAction_183e90() {
    vptr = hulk_at_004196cc;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183e90 *)this)->FUN_002326a0();
}


// 0x00183ed0 FUN_00183ed0 (72 B): matches/0x00183ed0.cpp
// sym: ??0PropDropAction_183ed0@fn_fd95142d@@QAE@HPAVRefObj_183ed0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropDropAction_183ed0::PropDropAction_183ed0(int target, RefObj_183ed0* obj) {
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


// 0x00183f20 FUN_00183f20 (50 B): matches/0x00183f20.cpp
// sym: ??1PropDropAction_183f20@fn_fd95142d@@QAE@XZ
PropDropAction_183f20::~PropDropAction_183f20() {
    vptr = hulk_at_004196e8;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183f20 *)this)->FUN_002326a0();
}


// 0x00183f60 FUN_00183f60 (72 B): matches/0x00183f60.cpp
// sym: ??0PropDamageAction_183f60@fn_fd95142d@@QAE@HPAVRefObj_183f60@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropDamageAction_183f60::PropDamageAction_183f60(int target, RefObj_183f60* obj) {
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


// 0x00183fb0 FUN_00183fb0 (50 B): matches/0x00183fb0.cpp
// sym: ??1PropDamageAction_183fb0@fn_fd95142d@@QAE@XZ
PropDamageAction_183fb0::~PropDamageAction_183fb0() {
    vptr = hulk_at_00419704;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_183fb0 *)this)->FUN_002326a0();
}


// 0x00183ff0 FUN_00183ff0 (72 B): matches/0x00183ff0.cpp
// sym: ??0GrapplePropDamageAction_183ff0@fn_fd95142d@@QAE@HPAVRefObj_183ff0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
GrapplePropDamageAction_183ff0::GrapplePropDamageAction_183ff0(int target, RefObj_183ff0* obj) {
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


// 0x00184040 FUN_00184040 (50 B): matches/0x00184040.cpp
// sym: ??1GrapplePropDamageAction_184040@fn_fd95142d@@QAE@XZ
GrapplePropDamageAction_184040::~GrapplePropDamageAction_184040() {
    vptr = hulk_at_00419720;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_184040 *)this)->FUN_002326a0();
}


// 0x00184080 FUN_00184080 (72 B): matches/0x00184080.cpp
// sym: ??0PropDestroyAction_184080@fn_fd95142d@@QAE@HPAVRefObj_184080@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropDestroyAction_184080::PropDestroyAction_184080(int target, RefObj_184080* obj) {
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


// 0x001840d0 FUN_001840d0 (50 B): matches/0x001840d0.cpp
// sym: ??1PropDestroyAction_1840d0@fn_fd95142d@@QAE@XZ
PropDestroyAction_1840d0::~PropDestroyAction_1840d0() {
    vptr = hulk_at_0041973c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1840d0 *)this)->FUN_002326a0();
}


// 0x00184110 FUN_00184110 (72 B): matches/0x00184110.cpp
// sym: ??0PropThrowAction_184110@fn_fd95142d@@QAE@HPAVRefObj_184110@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
PropThrowAction_184110::PropThrowAction_184110(int target, RefObj_184110* obj) {
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


// 0x00184160 FUN_00184160 (50 B): matches/0x00184160.cpp
// sym: ??1PropThrowAction_184160@fn_fd95142d@@QAE@XZ
PropThrowAction_184160::~PropThrowAction_184160() {
    vptr = hulk_at_00419758;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_184160 *)this)->FUN_002326a0();
}


// 0x00184750 FUN_00184750 (72 B): matches/0x00184750.cpp
// sym: ??0ShieldArcAction_184750@fn_fd95142d@@QAE@HPAVRefObj_184750@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ShieldArcAction_184750::ShieldArcAction_184750(int target, RefObj_184750* obj) {
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


// 0x001847a0 FUN_001847a0 (50 B): matches/0x001847a0.cpp
// sym: ?Cleanup@ShieldArcAction@fn_fd95142d@@QAEXXZ
void ShieldArcAction::Cleanup() {
    vft = ((hulk_intptr)DAT_00419774);
    Ref_1847a0* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)this)->FUN_002326a0();
}


// 0x001847e0 FUN_001847e0 (81 B): matches/0x001847e0.cpp
// sym: ??0BallAndChainSpinAction@fn_fd95142d@@QAE@PAUSource@1@PAVRef@1@@Z
BallAndChainSpinAction::BallAndChainSpinAction(Source* s, Ref* r) : Action_1847e0(), source(), ref(0) {
    source.ptr = s;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    Source* volatile& q = source.ptr;
    val = q->value;
}


// 0x00184840 FUN_00184840 (50 B): matches/0x00184840.cpp
// sym: ??1BallAndChainSpinAction_184840@fn_fd95142d@@QAE@XZ
BallAndChainSpinAction_184840::~BallAndChainSpinAction_184840() {
    vptr = hulk_at_00419790;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_184840 *)this)->FUN_002326a0();
}


// 0x00184880 FUN_00184880 (108 B): matches/0x00184880.cpp
// sym: ??0BallAndChainShootAction@fn_fd95142d@@QAE@HPAVRef_184880@1@@Z
BallAndChainShootAction::BallAndChainShootAction(int a, Ref_184880* b) : Ctor_00232660() {
    vt = (hulk_intptr)&hulk_at_004197ac;
    int* q = &mA;
    *q = 0;
    mRef = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = (int)0xbf800000;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    mA = a;
    if (b)
        b->Fn();
    if (mRef)
        mRef->Release();
    mRef = b;
}

} // namespace fn_fd95142d

// 0x001848f0 FUN_001848f0 (69 B): matches/0x001848f0.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?Destroy@AnimationAction@motion@hulkfight@fn_001848f0@@QAEXXZ
namespace fn_001848f0 {
// Same code shape as 0x0013ad70 (propagated; names are from that function)
extern char AnimAction_vt;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base_1848f0 {
  public:
    virtual void vf();
    void Cleanup_002326a0();
    char pad[0x18];
};

class AnimationAction : public Base_1848f0 {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (hulk_intptr)&AnimAction_vt;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base_1848f0::Cleanup_002326a0();
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_001848f0


// 0x00184940 hulkfight::motion::BallAndChainShootAction::vfunc_3 (436 B): equivalent/0x00184940.cpp [wrapped: conflict: BallAndChainShootAction; World]
// sym: ?vfunc_3@BallAndChainShootAction@fn_00184940@@UAE_NHH@Z @2e37713b4f54 @w1dfe9b0bc97e
namespace fn_00184940 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 20/20)
// hulkfight::motion::BallAndChainShootAction::vfunc_3 @ 0x00184940
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

struct V3_184940 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

class Obj_184940 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Xform_184940 {
    char data[0x54];
    Xform_184940 *FUN_00221c40();
};

struct Skeleton {
    char pad0[0x10];
    Xform_184940 xform;
};

class Weapon_184940 {
public:
    void FUN_001d8c70(Obj_184940 *attached);
};

class Fighter_184940 {
public:
    char pad0[0x328];
    Obj_184940 *held;
    hulk_freg FUN_000354c0();
};

struct Holder_184940 {
    Fighter_184940 *FUN_00059a30();
    Skeleton *FUN_00059a40();
};

class Params {
public:
};

struct Manager_184940 {
    char pad0[0x124];
    Fighter_184940 *active;
    void FUN_00029b50(int a, Obj_184940 *b, float c);
};

struct World {
    char pad0[0x20];
    Manager_184940 *manager;
};

struct ShootConfig {
    char pad0[0x14];
    int slot;           // 0x14
    V3_184940 origin;          // 0x18
    V3_184940 direction;       // 0x24
    char pad30[0x3c - 0x30];
    float lerp[3][2];   // 0x3c
    float arg54;        // 0x54
    float arg58;        // 0x58
};


void __cdecl FUN_00224d70(float angle, V3_184940 *v);
int __cdecl FUN_00097a30(float a, float b, float c, Obj_184940 *obj, float d, V3_184940 *pos, float e, V3_184940 *dir,
                         int f, int g, int h, int i);

class BallAndChainShootAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    ShootConfig *cfg;    // 0x1c
    Params *owner;       // 0x20
    Obj_184940 *attached;       // 0x24
    V3_184940 pos;              // 0x28
    V3_184940 dir;              // 0x34
    float cur[3];        // 0x40
};

bool BallAndChainShootAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;

    Holder_184940 *holder = ((Holder_184940 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Fighter_184940 *fighter = holder->FUN_00059a30();
    Weapon_184940 *weapon = ((Weapon_184940 *)((owners::C_35ef0 *)fighter)->FUN_00035ef0((hulk_intptr)(cfg->slot)));
    if (weapon == 0)
        return true;

    float t = ((owners::Progress_3ec00 *)fighter)->FUN_0003ec00(2);
    ShootConfig *c = cfg;
    cur[0] = (c->lerp[0][1] - c->lerp[0][0]) * t + c->lerp[0][0];
    cur[1] = (c->lerp[1][1] - c->lerp[1][0]) * t + c->lerp[1][0];
    cur[2] = (c->lerp[2][1] - c->lerp[2][0]) * t + c->lerp[2][0];

    Obj_184940 *held = fighter->held;
    if (held != 0)
        held->AddRef();
    if (attached != 0)
        attached->Release();
    attached = held;

    V3_184940 origin = cfg->origin;
    ((owners::Mat_22c2b0 *)(holder->FUN_00059a40()->xform.FUN_00221c40()))->FUN_0022c2b0((float *)(const V3_184940 *)(&origin), (float *)(V3_184940 *)(&pos));

    origin = cfg->direction;
    dir = origin;
    FUN_00224d70(fighter->FUN_000354c0(), &dir);
    dir.FUN_0022d110();

    if (FUN_00097a30(cur[1], cur[2], -1.0f, attached, cfg->arg58, &pos, cfg->arg54, &dir, 0, 0, 0, 1) != 0)
        weapon->FUN_001d8c70(attached);

    if (attached != 0) {
        World *w = DAT_004dd700;
        if (w != 0) {
            Manager_184940 *m = w->manager;
            if (m != 0) {
                if (m->active != 0 && m->active == fighter)
                    m->FUN_00029b50(((int)((owners::C_1d72e0 *)weapon)->FUN_001d72e0()), attached, cur[0]);
            }
        }
    }
    return true;
}
} // namespace fn_00184940
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00184b00 hulkfight::motion::BallAndChainShootAction::vfunc_5 (1007 B): equivalent/0x00184b00.cpp [wrapped: conflict: World; hulkfight::motion::BallAndChainShootAction]
// sym: ?vfunc_5@BallAndChainShootAction@motion@hulkfight@fn_00184b00@@UAE_NHM@Z @cbc47d39dfcb @w2e68bd444be2
namespace fn_00184b00 {
// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 32/32)
// hulkfight::motion::BallAndChainShootAction::vfunc_5 @ 0x00184b00
// hulkfight::motion::BallAndChainShootAction::vfunc_5 @ 0x00184b00
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

struct V3_184b00 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_184b00 *other, float eps);
};

struct Mat_184b00 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c120();
    void FUN_0022c2b0(V3_184b00 *in, V3_184b00 *out);
    void FUN_0022ca90(Mat_184b00 *a, Mat_184b00 *b);
};

class Obj_184b00 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Weapon_184b00 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat_184b00 *v15();
    unsigned FUN_001d72e0();
    void FUN_001d8100();
};

struct Xform_184b00 {
    Mat_184b00 *FUN_00221c40();
};

struct Skeleton_184b00 {
    char pad0[0x10];
    Xform_184b00 xform;
};

struct Table_184b00 {
    char pad0[0x1c];
    Mat_184b00 *xforms;     // 0x1c
    unsigned FUN_002843a0(unsigned lo, unsigned hi);
};

struct Holder_184b00 {
    char pad0[0x120];
    Table_184b00 *table;    // 0x120
    Weapon_184b00 *FUN_00035ef0(unsigned slot);
    void FUN_0003acf0(unsigned id, Weapon_184b00 *w, int a, int b, int c, Mat_184b00 *m);
};

struct Owner_184b00 {
    Holder_184b00 *FUN_00059a30();
    Skeleton_184b00 *FUN_00059a40();
};

struct Source_184b00 {
    Owner_184b00 *FUN_000592a0();
};

struct Config_184b00 {
    char pad0[0x14];
    unsigned slot;          // 0x14
    char pad18[0x30 - 0x18];
    V3_184b00 v30;          // 0x30
    char pad3c[0x58 - 0x3c];
    unsigned f58;           // 0x58
    char pad5c[0x60 - 0x5c];
    char f60[8];            // 0x60
    V3_184b00 v68;          // 0x68
    char pad74[0x78 - 0x74];
    unsigned f78;           // 0x78
    unsigned f7c;           // 0x7c
    V3_184b00 v80;          // 0x80
    unsigned f8c;           // 0x8c
    unsigned f90;           // 0x90
};

struct Ray_184b00 {
    bool FUN_00201e00(V3_184b00 *a, V3_184b00 *b, int c, V3_184b00 *d, V3_184b00 *e, int *o1, int *o2);
};

struct Spawn_184b00 {
    void FUN_001f6cd0(int a, int b, V3_184b00 *hitA, V3_184b00 *hitB, V3_184b00 *dir, int c, unsigned d, unsigned e, int *out, int z);
};

struct Sink_184b00 {
    void FUN_001ecd00(int v, Holder_184b00 *h);
};

struct Player_184b00 {
    void FUN_00029bb0(unsigned a, Obj_184b00 *b, float c);
};

struct World {
    char pad0[0x20];
    Player_184b00 *player;  // 0x20
    Ray_184b00 *ray;        // 0x24
    char pad28[0x34 - 0x28];
    Sink_184b00 *sink;      // 0x34
    Spawn_184b00 *spawn;    // 0x38
};

struct Decal_184b00 {
    unsigned FUN_00283ca0(void *a, V3_184b00 *b, V3_184b00 *c, float d);
    void FUN_00283450(unsigned h, V3_184b00 *b, V3_184b00 *c, float d);
};
extern "C" Decal_184b00 *FUN_0027f250();

extern "C" void __cdecl FUN_00224db0(Mat_184b00 *m, V3_184b00 *up, V3_184b00 *fwd);
extern "C" int __cdecl FUN_00098190(float dt, float f44, float f48, int zero0, Obj_184b00 *attached, unsigned f58, V3_184b00 *pos, V3_184b00 *dir, int z1, int z2, int z3, int one);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
#endif


struct Frame_184b00 {
    char pad10[3];
    bool hit;               // 0x13
    union { float t; int outv; };   // 0x14
    V3_184b00 in;           // 0x18
    Weapon_184b00 *weapon;  // 0x24
    unsigned sp28;          // 0x28
    int obj;                // 0x2c
    int objb;               // 0x30
    Holder_184b00 *holder;  // 0x34
    unsigned slot;          // 0x38
    Owner_184b00 *owner;    // 0x3c
    V3_184b00 end;          // 0x40
    V3_184b00 start;        // 0x4c
    V3_184b00 hitA;         // 0x58
    V3_184b00 hitB;         // 0x64
    Mat_184b00 rot;         // 0x70
    Mat_184b00 wmat;        // 0xb0
    Mat_184b00 inv;         // 0xf0
};

namespace hulkfight { namespace motion {

class BallAndChainShootAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int state, float dt);
    char pad04[0x1c - 4];
    Config_184b00 *cfg;     // 0x1c
    Source_184b00 *source;  // 0x20
    Obj_184b00 *attached;   // 0x24
    V3_184b00 pos;          // 0x28
    V3_184b00 dir;          // 0x34
    float timeLeft;         // 0x40
    float speed;            // 0x44
    float f48;              // 0x48
    char pad4c[4];
    unsigned decal;         // 0x50
};

bool BallAndChainShootAction::vfunc_5(int state, float dt)
{
    if (state != 1)
        return true;
    if (source == 0)
        return false;

    Frame_184b00 f;
    f.owner = source->FUN_000592a0();
    f.holder = f.owner->FUN_00059a30();
    f.slot = cfg->slot;
    f.weapon = f.holder->FUN_00035ef0(f.slot);
    f.t = dt * speed;
    timeLeft = timeLeft - f.t;

    if (attached != 0) {
        f.sp28 = cfg->f58;
        if (FUN_00098190(dt, speed, f48, 0, attached, f.sp28, &pos, &dir, 0, 0, 0, 1) != 0) {
            if (f.weapon != 0) {
                Player_184b00 *player = DAT_004dd700->player;
                player->FUN_00029bb0(f.weapon->FUN_001d72e0(), attached, timeLeft);
            }
        } else {
            if (f.weapon != 0)
                f.weapon->FUN_001d8100();
            if (attached != 0) {
                attached->Release();
                attached = 0;
            }
        }
    }

    pos.x = f.t * dir.x + pos.x;
    pos.y = f.t * dir.y + pos.y;
    pos.z = f.t * dir.z + pos.z;

    Table_184b00 *table = f.holder->table;
    unsigned idx = table->FUN_002843a0(cfg->f78, cfg->f7c);
    if (idx == 0xffff)
        idx = 0;
    f.in = cfg->v80;
    table->xforms[idx].FUN_0022c2b0(&f.in, &f.start);

    f.hit = false;
    f.obj = 0;
    f.objb = 0;
    if (DAT_004dd700->ray->FUN_00201e00(&f.start, &pos, 1, &f.hitB, &f.hitA, &f.obj, &f.objb)) {
        f.hit = true;
        if (f.obj != 0) {
            f.sp28 = cfg->f90;
            f.t = 0;
            DAT_004dd700->spawn->FUN_001f6cd0(f.obj, f.objb, &f.hitB, &f.hitA, &dir, cfg->f8c - 1, f.sp28, f.sp28, &f.outv, 0);
            DAT_004dd700->sink->FUN_001ecd00(f.outv, f.holder);
        }
    }

    if (f.weapon != 0) {
        memcpy(&f.wmat, f.weapon->v15(), sizeof(Mat_184b00));
        f.in = cfg->v68;
        f.wmat.FUN_0022c2b0(&f.in, &f.end);
    } else {
        f.end = pos;
    }

    Decal_184b00 *dm = FUN_0027f250();
    if (decal == 0)
        decal = dm->FUN_00283ca0(&cfg->f60, &f.end, &f.start, 1000.0f);
    else
        dm->FUN_00283450(decal, &f.end, &f.start, 1000.0f);

    if (f.weapon != 0) {
        memcpy(&f.inv, f.owner->FUN_00059a40()->xform.FUN_00221c40(), sizeof(Mat_184b00));
        f.inv.FUN_0022c120();
        f.rot.FUN_0022b980();
        f.in = cfg->v30;
        if (!f.in.FUN_0022d2b0(&dir, 9.99999974737875e-06f))
            FUN_00224db0(&f.rot, &f.in, &dir);
        f.rot.m[12] = pos.x;
        f.rot.m[13] = pos.y;
        f.rot.m[14] = pos.z;
        f.wmat.FUN_0022b980();
        f.wmat.FUN_0022ca90(&f.rot, &f.inv);
        f.holder->FUN_0003acf0(f.slot, f.weapon, 0, 0, 0, &f.wmat);
    }

    if (!f.hit && timeLeft > (*(float*)&DAT_003f32e0))
        return true;
    return false;
}

} }
} // namespace fn_00184b00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fd95142d {

// 0x00184ef0 FUN_00184ef0 (99 B): matches/0x00184ef0.cpp
// sym: ??0BallAndChainReturnAction_184ef0@fn_fd95142d@@QAE@HPAVRef_184ef0@1@@Z
BallAndChainReturnAction_184ef0::BallAndChainReturnAction_184ef0(int a, Ref_184ef0* b) : Action_184ef0() {
    int* q = &mArg;
    *q = 0;
    mRef = 0;
    x24 = 0;
    x28 = 0;
    x2c = 0;
    x30 = 0;
    x34 = 0;
    x38 = -1.0f;
    x3c = 0;
    x40 = 0;
    x44 = 0;
    mArg = a;
    if (b)
        b->A();
    if (mRef)
        mRef->B();
    mRef = b;
}


// 0x00184f60 FUN_00184f60 (50 B): matches/0x00184f60.cpp
// sym: ?Reset@BallAndChainReturnAction@fn_fd95142d@@QAEXXZ
void BallAndChainReturnAction::Reset() {
    vptr = ((hulk_intptr)DAT_004197c8);
    _ReadWriteBarrier();
    if (mTwo) {
        mTwo->B();
        mTwo = 0;
    }
    if (mOne)
        mOne = 0;
    ((fight::Action *)(((PropThrowAction_184f60*)this)))->FUN_002326a0();
}

} // namespace fn_fd95142d

// 0x00184fc0 fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::vfunc_6 (26 B): matches/0x00184fc0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::**)(int))&this->f_10))(b);
}


// 0x00184fe0 fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::vfunc_2 (11 B): matches/0x00184fe0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185010 fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::vfunc_6 (26 B): matches/0x00185010.cpp
// sym: ?vfunc_6@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::**)(int))&this->f_10))(b);
}


// 0x00185030 fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::vfunc_2 (11 B): matches/0x00185030.cpp
// sym: ?vfunc_2@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185060 fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_6 (26 B): matches/0x00185060.cpp
// sym: ?vfunc_6@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::**)(int))&this->f_10))(b);
}


// 0x00185080 fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_2 (11 B): matches/0x00185080.cpp
// sym: ?vfunc_2@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001850c0 fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_7 (6 B): matches/0x001850c0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001850d0 fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_6 (30 B): matches/0x001850d0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1850d0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1850d0*)&DAT_003f335c));
}


// 0x001850f0 fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_8 (26 B): matches/0x001850f0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::**)(int))&this->f_18))(b);
}


// 0x00185110 fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_2 (11 B): matches/0x00185110.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00185140 fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_6 (26 B): matches/0x00185140.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::**)(int))&this->f_10))(b);
}


// 0x00185160 fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_2 (11 B): matches/0x00185160.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001851a0 fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_7 (6 B): matches/0x001851a0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001851b0 fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_6 (30 B): matches/0x001851b0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1851b0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1851b0*)&DAT_003f335c));
}


// 0x001851d0 fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_8 (26 B): matches/0x001851d0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::**)(int))&this->f_18))(b);
}


// 0x001851f0 fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_2 (11 B): matches/0x001851f0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00185220 fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_6 (26 B): matches/0x00185220.cpp
// sym: ?vfunc_6@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::**)(int))&this->f_10))(b);
}


// 0x00185240 fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_2 (11 B): matches/0x00185240.cpp
// sym: ?vfunc_2@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185270 fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::vfunc_6 (26 B): matches/0x00185270.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::**)(int))&this->f_10))(b);
}


// 0x00185290 fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::vfunc_2 (11 B): matches/0x00185290.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001852d0 fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_7 (6 B): matches/0x001852d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001852e0 fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_6 (30 B): matches/0x001852e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1852e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1852e0*)&DAT_003f335c));
}


// 0x00185300 fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_8 (26 B): matches/0x00185300.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::**)(int))&this->f_18))(b);
}


// 0x00185320 fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_2 (11 B): matches/0x00185320.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00185350 fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::vfunc_6 (26 B): matches/0x00185350.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropMassCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::**)(int))&this->f_10))(b);
}


// 0x00185370 fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::vfunc_2 (11 B): matches/0x00185370.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropMassCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001853a0 fight::ParamBool<hulkfight::motion::PropAtRestCondition>::vfunc_6 (26 B): matches/0x001853a0.cpp
// sym: ?vfunc_6@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropAtRestCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropAtRestCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropAtRestCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropAtRestCondition>::**)(int))&this->f_10))(b);
}


// 0x001853c0 fight::ParamBool<hulkfight::motion::PropAtRestCondition>::vfunc_2 (11 B): matches/0x001853c0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropAtRestCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001853f0 fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::vfunc_6 (26 B): matches/0x001853f0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::**)(int))&this->f_10))(b);
}


// 0x00185410 fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::vfunc_2 (11 B): matches/0x00185410.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185440 fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::vfunc_6 (26 B): matches/0x00185440.cpp
// sym: ?vfunc_6@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::**)(int))&this->f_10))(b);
}


// 0x00185460 fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::vfunc_2 (11 B): matches/0x00185460.cpp
// sym: ?vfunc_2@?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185490 fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::vfunc_6 (26 B): matches/0x00185490.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::**)(int))&this->f_10))(b);
}


// 0x001854b0 fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::vfunc_2 (11 B): matches/0x001854b0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001854f0 fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_7 (6 B): matches/0x001854f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00185500 fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_6 (30 B): matches/0x00185500.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_185500 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_185500*)&DAT_003f335c));
}


// 0x00185520 fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_8 (26 B): matches/0x00185520.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::**)(int))&this->f_18))(b);
}


// 0x00185540 fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_2 (11 B): matches/0x00185540.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}

