// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002343b0..0x00234780 (kind game, layer engine, confidence high), dominant class fight::Condition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_fc77ac82 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc77ac82 {} using namespace fn_fc77ac82;
namespace fn_fc77ac82 {
void __cdecl SweepTrack_DeleteThis_00263f30(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_fc77ac82 { extern "C" char DAT_00427990[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fc77ac82 {
class Entity_2343b0 {
  public:
    Entity_2343b0();
    virtual void Fn_00038290();
};
class ConditionFactory : public Entity_2343b0 {
  public:
    ConditionFactory();
};
typedef unsigned int U_2343e0;
typedef unsigned __int64 U64_2343e0;
U_2343e0 __cdecl FUN_00238190(U_2343e0);
U_2343e0 __cdecl FUN_00266da0(U_2343e0);
} // namespace fn_fc77ac82
U64_2343e0 __cdecl FUN_002672f0(U_2343e0,U_2343e0,U_2343e0);
namespace fn_fc77ac82 {
struct Node { U_2343e0 head; char pad[12]; Node* next; U_2343e0 FUN_00236790(U64_2343e0); };
struct List_2343e0 { Node* first; };
struct Visitor { virtual bool accept(U_2343e0)=0; virtual U_2343e0 fallback(U_2343e0)=0; };
class Ref_2344a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner_2344a0 {
  public:
    char pad[4];
    Ref_2344a0* value;
    void Set(Ref_2344a0* p);
};
} // namespace fn_fc77ac82
unsigned __int64 __cdecl FUN_002672f0(unsigned int name, int a, int b);
namespace fn_fc77ac82 {
class Param {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(unsigned __int64 id, int *out);
    virtual void vfunc_11(unsigned __int64 id, char *out);
    virtual void vfunc_12();
    virtual bool vfunc_13();
    virtual unsigned __int64 vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(unsigned __int64 id);
    virtual void vfunc_17();
};
union ParamArg_2344d0 {
    Param *param;
    char flag;
};
namespace fight {
class Condition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(unsigned __int64 id, int extra, ParamArg_2344d0 arg);
    virtual void vfunc_4(int extra, Param *param);
};
}
extern void* hulk_at_00427990[];
class Entity_234560 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class ConditionFactory_234560 : public Entity_234560 {
  public:
    ConditionFactory_234560* vfunc_5(signed char flags);
};
class Condition {
  public:
    virtual void f() HULK_PURE64;
    int b;
    void* c;
    Condition(void*);
};


// 0x002343b0 FUN_002343b0 (18 B): matches/0x002343b0.cpp
// sym: ??0ConditionFactory@fn_fc77ac82@@QAE@XZ
ConditionFactory::ConditionFactory() {}


// 0x002343d0 FUN_002343d0 (11 B): matches/0x002343d0.cpp
// sym: ?FUN_002343d0@fn_fc77ac82@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_002343d0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_00427990);
    FUN_0027afd0(self);
}


// 0x002343e0 FUN_002343e0 (163 B): matches/0x002343e0.cpp
// sym: ?target@fn_fc77ac82@@YAIIPAUVisitor@1@@Z
// FUN_002343e0 @ 0x002343e0
hulk_uintptr __cdecl target(hulk_uintptr arg, Visitor* visitor) {
 U_2343e0 old=FUN_00266da0(FUN_00238190(0));
 List_2343e0* list=(*(List_2343e0**)&DAT_004e5af8);
 if(list) {
 U64_2343e0 key=FUN_002672f0(arg,0,0);
 Node* node=list->first;
 while(node) {
 U_2343e0 result=node->FUN_00236790(key);
 if(visitor->accept(result)) { FUN_00266da0(old); return result; }
 node=node->next;
 }
 }
 U_2343e0 result=visitor->fallback(arg);
 FUN_00266da0(old);
 return result;
}


// 0x002344a0 FUN_002344a0 (39 B): matches/0x002344a0.cpp
// sym: ?Set@Owner_2344a0@fn_fc77ac82@@QAEXPAVRef_2344a0@2@@Z
void Owner_2344a0::Set(Ref_2344a0* p) {
    if (value)
        value->f5(1);
    value = p;
}


// 0x002344d0 fight::Condition::vfunc_3 (131 B): equivalent/0x002344d0.cpp
// sym: ?vfunc_3@Condition@fight@fn_fc77ac82@@UAE_N_KHTParamArg_2344d0@3@@Z @1fea448dc399 @wa4452d5c1ca1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// fight::Condition::vfunc_3 @ 0x002344d0
bool fight::Condition::vfunc_3(unsigned __int64 id, int extra, ParamArg_2344d0 arg)
{
    Param *param = arg.param;

    if (!param->vfunc_13())
        return false;
    unsigned __int64 key = param->vfunc_14();
    if (key != id)
        return false;

    param->vfunc_16(key);
    if (!param->vfunc_3()) {
        arg.flag = 0;
        param->vfunc_11(FUN_002672f0((*(hulk_uintptr*)&DAT_004ca290), 0, 0), &arg.flag);
    }
    vfunc_4(extra, param);
    param->vfunc_17();
    return true;
}


// 0x00234560 fight::ConditionFactory::vfunc_2 (36 B): matches/0x00234560.cpp
// sym: ?vfunc_5@ConditionFactory_234560@fn_fc77ac82@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ConditionFactory_234560* ConditionFactory_234560::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00427990;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis_00263f30(this);
    }
    return this;
}


// 0x00234590 FUN_00234590 (25 B): matches/0x00234590.cpp
// sym: ??0Condition@fn_fc77ac82@@QAE@PAX@Z
Condition::Condition(void* p) {
    b = 0;
    c = p;
}

} // namespace fn_fc77ac82

// 0x002345b0 FUN_002345b0 (38 B): matches/0x002345b0.cpp [wrapped: conflict: Condition]
// sym: ??1Condition@fn_002345b0@@UAE@XZ
namespace fn_002345b0 {
class Ref_2345b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void Release(int);
};
class Param_2345b0 {
  public:
    virtual void p() HULK_PURE64;
};
extern "C" void __fastcall FUN_00234210(void* self);
class Condition : public Param_2345b0 {
  public:
    virtual ~Condition();
    Ref_2345b0* mRef;
};
Condition::~Condition() {
    if (mRef)
        mRef->Release(1);
    mRef = 0;
    FUN_00234210(this);
}
} // namespace fn_002345b0


// 0x002345e0 fight::Condition::vfunc_5 (59 B): matches/0x002345e0.cpp [wrapped: conflict: fight::Condition]
// sym: ?vfunc_5@Condition@fight@fn_002345e0@@QAEPAU123@E@Z
namespace fn_002345e0 {
extern "C" char DAT_004279ac[];
class Obj_2345e0 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int);
    virtual void s6();
};
namespace fight { struct Condition {
    hulk_uintptr vptr;
    Obj_2345e0* mRef;
    Condition* vfunc_5(unsigned char flags);
    void reset_00234210();
}; }
void Destroy_0008d330(fight::Condition*);
fight::Condition* fight::Condition::vfunc_5(unsigned char flags) {
    Obj_2345e0* p = mRef;
    vptr = ((hulk_intptr)DAT_004279ac);
    if (p)
        p->s5(1);
    mRef = 0;
    reset_00234210();
    if (flags & 1)
        Destroy_0008d330(this);
    return this;
}
} // namespace fn_002345e0

