// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00174660..0x00174940 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2f1fd83 {
#define TREE_TU_END }
namespace fn_f2f1fd83 {} using namespace fn_f2f1fd83;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f2f1fd83 {
class Ref {
  public:
    virtual void retain();
    virtual void release();
    void Add() { retain(); }
    void Release() { release(); }
};
struct Action_174660 { virtual void slot0(); void FUN_00232660(); };
extern void *DAT_00417e30[];
struct JointRelativeAction : Action_174660 {
    char gap[0x18];
    unsigned int joint;
    Ref *reference;
    unsigned int field24;
    char gap28[0x38];
    unsigned int field60;
    JointRelativeAction * FUN_00174660(unsigned int value, Ref *ref);
};
extern void* g_vftable_1746b0[];
class Ref_1746b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1746b0 {
  public:
    void* vptr;
};
class JointRelativeAction_1746b0 : public Action_1746b0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1746b0* m20;
    Ref_1746b0* m24;
    ~JointRelativeAction_1746b0();
};
class RefObj_174700 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_174700 {
  public:
    Action_174700();
    virtual void Update();
    char pad[0x18];
};
class IntentionClearAction_174700 : public Action_174700 {
  public:
    int mTarget;
    RefObj_174700* mObj;
    IntentionClearAction_174700(int target, RefObj_174700* obj);
    virtual void Execute();
};
extern void* g_vftable_174750[];
class Ref_174750 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_174750 {
  public:
    void* vptr;
};
class IntentionClearAction_174750 : public Action_174750 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_174750* m20;
    ~IntentionClearAction_174750();
};
class RefCounted_174790 {
  public:
    virtual void AddRef() throw() = 0;
    virtual void Release() throw() = 0;
};
class Action_174790 {
  public:
    Action_174790() throw();
    virtual void BaseVirtual() throw();
    char pad[0x18];
};
class ChargeAction : public Action_174790 {
  public:
    ChargeAction(void* a, RefCounted_174790* b) throw();
    virtual void V1() throw();
    void* mA;
    RefCounted_174790* mB;
    int mC;
};
extern void* g_vftable_1747e0[];
class Ref_1747e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1747e0 {
  public:
    void* vptr;
};
class ChargeAction_1747e0 : public Action_1747e0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1747e0* m20;
    ~ChargeAction_1747e0();
};
class RefObj_174820 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_174820 {
  public:
    Action_174820();
    virtual void Update();
    char pad[0x18];
};
class ChargeClearAction_174820 : public Action_174820 {
  public:
    int mTarget;
    RefObj_174820* mObj;
    ChargeClearAction_174820(int target, RefObj_174820* obj);
    virtual void Execute();
};
extern void* g_vftable_174870[];
class Ref_174870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_174870 {
  public:
    void* vptr;
};
class ChargeClearAction_174870 : public Action_174870 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_174870* m20;
    ~ChargeClearAction_174870();
};
class Action_1748b0 {
  public:
    virtual void dummy();
    char pad[24];
    Action_1748b0();
};
struct Group {
    Ref* a;
    Ref* b;
    Ref* c;
    Group() : a(0), b(0), c(0) {}
};
class PushOutAction : public Action_1748b0 {
  public:
    Group g;
    PushOutAction(int, Ref*);
    virtual void dummy();
};


// 0x00174660 FUN_00174660 (74 B): equivalent/0x00174660.cpp
// sym: ?FUN_00174660@JointRelativeAction@fn_f2f1fd83@@QAEPAU12@IPAVRef@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00174660 @ 0x00174660
JointRelativeAction * JointRelativeAction::FUN_00174660(unsigned int value, Ref *ref) {
    FUN_00232660();
    *(void ***)this = DAT_00417e30;
    joint = value;
    reference = 0;
    field24 = 0;
    field60 = 0;
    if (ref) ref->retain();
    if (reference) reference->release();
    reference = ref;
    return this;
}


// 0x001746b0 FUN_001746b0 (69 B): matches/0x001746b0.cpp
// sym: ??1JointRelativeAction_1746b0@fn_f2f1fd83@@QAE@XZ
JointRelativeAction_1746b0::~JointRelativeAction_1746b0() {
    vptr = g_vftable_1746b0;
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
    ((fight::Action *)(Action_1746b0 *)this)->FUN_002326a0();
}


// 0x00174700 FUN_00174700 (72 B): matches/0x00174700.cpp
// sym: ??0IntentionClearAction_174700@fn_f2f1fd83@@QAE@HPAVRefObj_174700@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
IntentionClearAction_174700::IntentionClearAction_174700(int target, RefObj_174700* obj) {
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


// 0x00174750 FUN_00174750 (50 B): matches/0x00174750.cpp
// sym: ??1IntentionClearAction_174750@fn_f2f1fd83@@QAE@XZ
IntentionClearAction_174750::~IntentionClearAction_174750() {
    vptr = g_vftable_174750;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_174750 *)this)->FUN_002326a0();
}


// 0x00174790 FUN_00174790 (79 B): matches/0x00174790.cpp
// sym: ??0ChargeAction@fn_f2f1fd83@@QAE@PAXPAVRefCounted_174790@1@@Z
ChargeAction::ChargeAction(void* a, RefCounted_174790* b) throw() {
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


// 0x001747e0 FUN_001747e0 (50 B): matches/0x001747e0.cpp
// sym: ??1ChargeAction_1747e0@fn_f2f1fd83@@QAE@XZ
ChargeAction_1747e0::~ChargeAction_1747e0() {
    vptr = g_vftable_1747e0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1747e0 *)this)->FUN_002326a0();
}


// 0x00174820 FUN_00174820 (72 B): matches/0x00174820.cpp
// sym: ??0ChargeClearAction_174820@fn_f2f1fd83@@QAE@HPAVRefObj_174820@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ChargeClearAction_174820::ChargeClearAction_174820(int target, RefObj_174820* obj) {
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


// 0x00174870 FUN_00174870 (50 B): matches/0x00174870.cpp
// sym: ??1ChargeClearAction_174870@fn_f2f1fd83@@QAE@XZ
ChargeClearAction_174870::~ChargeClearAction_174870() {
    vptr = g_vftable_174870;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_174870 *)this)->FUN_002326a0();
}


// 0x001748b0 FUN_001748b0 (79 B): matches/0x001748b0.cpp
// sym: ??0PushOutAction@fn_f2f1fd83@@QAE@HPAVRef@1@@Z
PushOutAction::PushOutAction(int x, Ref* p) {
    g.a = (Ref*)x;
    if (p)
        p->Add();
    if (g.b)
        g.b->Release();
    g.b = p;
}

} // namespace fn_f2f1fd83
