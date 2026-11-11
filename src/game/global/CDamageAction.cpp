// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001d9b0..0x0001db40 (kind game, layer game, confidence medium), dominant class CDamageAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8d08169 {
#define TREE_TU_END }
namespace fn_f8d08169 {} using namespace fn_f8d08169;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8d08169 {
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1d9b0 {
  public:
    Action_1d9b0();
    virtual void f();
};
class CAction : public Action_1d9b0 {
  public:
    CAction(Ref* p, int x) : ref(0) {
        if (p)
            p->AddRef();
        if (ref)
            ref->Release();
        ref = p;
        a = x;
    }
    virtual void f();
    char pad[24];
    Ref* ref;
    int a;
    int b;
};
class CDamageAction : public CAction {
  public:
    CDamageAction(Ref*, int, int);
    virtual void f();
};
extern void* g_vftable_1da00[];
class Ref_1da00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1da00 {
  public:
    void* vptr;
};
class CAction_1da00 : public Action_1da00 {
  public:
    char pad[0x18];
    Ref_1da00* m1c;
    ~CAction_1da00();
};


// 0x0001d9b0 FUN_0001d9b0 (78 B): matches/0x0001d9b0.cpp
// sym: ??0CDamageAction@fn_f8d08169@@QAE@PAVRef@1@HH@Z
CDamageAction::CDamageAction(Ref* p, int x, int y) : CAction(p, x) {
    b = y;
}


// 0x0001da00 FUN_0001da00 (36 B): matches/0x0001da00.cpp
// sym: ??1CAction_1da00@fn_f8d08169@@QAE@XZ
CAction_1da00::~CAction_1da00() {
    vptr = g_vftable_1da00;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1da00 *)this)->FUN_002326a0();
}

} // namespace fn_f8d08169

// 0x0001da30 CDamageAction::vfunc_7 (263 B): equivalent/0x0001da30.cpp [wrapped: conflict: CDamageAction]
// sym: ?vfunc_7@CDamageAction@fn_0001da30@@UAE_NH@Z
namespace fn_0001da30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CDamageAction::vfunc_7 @ 0x0001da30
struct Source_1da30 { char pad[0x12c]; unsigned id; char pad2[0x1e58-0x130]; float factor; };
struct Info_1da30 { char pad[0x4c]; unsigned id; char pad2[0x7c-0x50]; float factor; char pad3[0x91-0x80]; unsigned char flag; };
struct Actor_1da30 { char pad[0x12c]; unsigned id; char pad2[0x334-0x130]; Source_1da30* secondary; Source_1da30* primary; void FUN_00043350(float, unsigned, int, float, int, unsigned); };
struct Intermediate_1da30 { Actor_1da30* FUN_00059a30(); };
struct Owner_1da30 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Info_1da30* v3(); Intermediate_1da30* FUN_000592a0(); };
extern "C" void __cdecl FUN_001eb210();
struct CDamageAction { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual bool vfunc_7(int); char pad[0x1c-4]; Owner_1da30* owner; float low; float high; };
bool CDamageAction::vfunc_7(int) { Actor_1da30* actor=owner->FUN_000592a0()->FUN_00059a30(); unsigned id=0; union { unsigned word; unsigned char byte; } flag; flag.byte=0; float factor=0.0f; if(actor->primary) { id=actor->primary->id; factor=actor->primary->factor; } else if(actor->secondary) { id=actor->secondary->id; factor=actor->secondary->factor; } else { Info_1da30* info=owner->v3(); if(info) { id=info->id; if(id==actor->id) id=0; flag.byte=info->flag; factor=info->factor; } } float result=low; if(high>low) { if(!(factor>=0.0f && factor<=1.0f)) factor=factor>1.0f ? 1.0f:0.0f; result=low+(high-low)*factor; } actor->FUN_00043350(result,id,0,1.0f,0,flag.word); FUN_001eb210(); return false; }
} // namespace fn_0001da30

