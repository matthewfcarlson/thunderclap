// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023a0f0..0x0023a3f0 (kind game, layer engine, confidence high), dominant class fight::QueuedNodeAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb73e034 {
#define TREE_TU_END }
namespace fn_fb73e034 {} using namespace fn_fb73e034;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fb73e034 {
class Action_23a210 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class QueuedNodeAction : public Action_23a210 {
  public:
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int param1, int param2);

    char pad_4[8];    // 0x4 - 0xc
    int m_flags;      // 0xc
    char pad_c[0x1c]; // 0x10 - 0x2c (28 bytes)
    struct Data {
        void func_22f0_002322f0(int a, int b);
        void func_1f20_00231f20(int a);
        bool func_24b0_002324b0(int a);
        void func_1ee0_00231ee0();
        char pad[0x28]; // size 0x28 to reach 0x54
    } m_data;           // 0x2c
    int m_54;           // 0x54
    char m_58;          // 0x58
};
struct Action_23a290 {
    void target_00232240();
};
extern void* hulk_at_00428558[];
class Ref_23a320 {
  public:
    virtual void F0();
    virtual void Release();
};
class Sub_23a320 {
  public:
    void Fini_002325f0();
};
class Action_23a320 {
  public:
    void* vptr;
};
class QueuedNodeAction_23a320 : public Action_23a320 {
  public:
    char pad[0x18];
    Ref_23a320* m1c;
    char pad2[8];
    Ref_23a320* m28;
    Sub_23a320 m2c;
    ~QueuedNodeAction_23a320();
};

} // namespace fn_fb73e034

// 0x0023a0f0 fight::QueuedNodeAction::vfunc_3 (273 B): equivalent/0x0023a0f0.cpp [wrapped: conflict: fight::QueuedNodeAction]
// sym: ?vfunc_3@QueuedNodeAction@fight@fn_0023a0f0@@UAE_NII@Z
namespace fn_0023a0f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// fight::QueuedNodeAction::vfunc_3 @ 0x0023a0f0
typedef unsigned int uint_23a0f0;
extern "C" uint_23a0f0 __cdecl FUN_00238190(uint_23a0f0);
extern "C" uint_23a0f0 __cdecl FUN_00266da0(hulk_uintptr);
struct Result_23a0f0 { char pad[12]; uint_23a0f0 flags; float first, second; };
struct Owner_23a0f0;
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual float slot6(); virtual float slot7(); virtual uint_23a0f0 slot8(uint_23a0f0,uint_23a0f0); virtual void slot9(); virtual Result_23a0f0* slot10(Owner_23a0f0*,uint_23a0f0,uint_23a0f0);
 Node* next; uint_23a0f0 flags;
};
struct Owner_23a0f0 { char pad[40]; Node* head; };
struct Queue_23a0f0 {
 void FUN_00232290(Result_23a0f0*);
 void FUN_00232030(Owner_23a0f0*);
 void FUN_002322f0(uint_23a0f0,uint_23a0f0);
 bool FUN_00231ee0();
 char pad[40];
};
namespace fight {
struct QueuedNodeAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(uint_23a0f0,uint_23a0f0); virtual void vfunc_4(); virtual void vfunc_5();
 char pad0[8]; uint_23a0f0 flags; char pad1[12]; Owner_23a0f0* owner; uint_23a0f0 query; uint_23a0f0 expected; uint_23a0f0 context; Queue_23a0f0 queue; uint_23a0f0 value; unsigned char active;
};
bool QueuedNodeAction::vfunc_3(uint_23a0f0 arg, uint_23a0f0 arg2) {
 uint_23a0f0 saved = FUN_00266da0(FUN_00238190(3));
 value = arg;
 if (!owner) { FUN_00266da0(saved); return false; }
 uint_23a0f0 status = 1;
 for (Node* node = owner->head; node; node = node->next) {
 uint_23a0f0 f = node->flags;
 uint_23a0f0 match = node->slot8(query,context);
 if (expected == match) {
 Result_23a0f0* r = node->slot10(owner,expected,context);
 if (r) {
 r->first = node->slot6();
 r->second = node->slot7();
 r->flags = (r->flags & ~3u) | (f & 3u);
 queue.FUN_00232290(r);
 }
 if (!f) status = 0;
 }
 }
 queue.FUN_00232030(owner);
 flags = (flags & ~3u) | status;
 queue.FUN_002322f0(value,arg2);
 active = 1;
 bool result = queue.FUN_00231ee0();
 FUN_00266da0(saved);
 return result;
}
}
} // namespace fn_0023a0f0

namespace fn_fb73e034 {

// 0x0023a210 fight::QueuedNodeAction::vfunc_5 (120 B): matches/0x0023a210.cpp
// sym: ?vfunc_5@QueuedNodeAction@fn_fb73e034@@UAEXHH@Z
void QueuedNodeAction::vfunc_5(int param1, int param2) {
    if (param1 == 0 && m_58 == 0) {
        m_data.func_22f0_002322f0(m_54, param2);
    }
    m_58 = 0;
    m_data.func_1f20_00231f20(param1);
    if (param1 == m_54 - 1) {
        if (m_data.func_24b0_002324b0(0)) {
            m_flags &= 0xfffffffc;
            m_data.func_1ee0_00231ee0();
            return;
        }
        m_flags = (m_flags & 0xfffffffd) | 1;
    }
    m_data.func_1ee0_00231ee0();
}

} // namespace fn_fb73e034

// 0x0023a290 fight::QueuedNodeAction::vfunc_4 (8 B): matches/0x0023a290.cpp
// sym: ?vfunc_4@QueuedNodeAction@fight@@UAEXXZ
void fight::QueuedNodeAction::vfunc_4() {
    ((Action_23a290*)((char*)this + 0x2c))->target_00232240();
}


// 0x0023a2a0 FUN_0023a2a0 (128 B): matches/0x0023a2a0.cpp [wrapped: conflict: QueuedNodeAction]
// sym: ??0QueuedNodeAction@fn_0023a2a0@@QAE@PAURef_23a2a0@1@HH0@Z
namespace fn_0023a2a0 {
struct Ref_23a2a0 {
    virtual void AddRef();
    virtual void Release();
};
struct Sub_23a2a0 {
    Sub_23a2a0();
    char p[0x28];
};
struct Action_23a2a0 {
    Action_23a2a0();
    virtual void f();
    char pad[0xc];
    int a;
    int b;
    int c;
};
struct QueuedNodeAction : Action_23a2a0 {
    Ref_23a2a0* mNode;
    int mA;
    int mB;
    Ref_23a2a0* mOther;
    Sub_23a2a0 mSub;
    int m54;
    char m58;
    QueuedNodeAction(Ref_23a2a0* n, int a, int b, Ref_23a2a0* o);
    virtual void f();
};
QueuedNodeAction::QueuedNodeAction(Ref_23a2a0* n, int x, int y, Ref_23a2a0* o) : mNode(0), mA(x), mB(y), mOther(0) {
    m54 = 0;
    m58 = 0;
    if (n)
        n->AddRef();
    if (mNode)
        mNode->Release();
    mNode = n;
    if (o)
        o->AddRef();
    if (mOther)
        mOther->Release();
    mOther = o;
    a = 0;
    b = 0xbf800000;
}
} // namespace fn_0023a2a0

namespace fn_fb73e034 {

// 0x0023a320 FUN_0023a320 (63 B): matches/0x0023a320.cpp
// sym: ??1QueuedNodeAction_23a320@fn_fb73e034@@QAE@XZ
QueuedNodeAction_23a320::~QueuedNodeAction_23a320() {
    vptr = hulk_at_00428558;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    m2c.Fini_002325f0();
    ((fight::Action *)(Action_23a320 *)this)->FUN_002326a0();
}

} // namespace fn_fb73e034
