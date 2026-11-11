// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00239d50..0x0023a0f0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f6f801d4 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6f801d4 {} using namespace fn_f6f801d4;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f6f801d4 {
class A_239d50 {
  public:
    int x;
    A_239d50();
};
class Ref_239e10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Release(int);
};
class Holder_239e10 {
  public:
    Ref_239e10* p;
    void Clear();
};
class Ref_239e90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Release(int);
};
class Holder_239e90 {
  public:
    Ref_239e90* p;
    void Clear();
};
struct Factory_239f10;
class Node {
  public:
    virtual void _m_vf0();
    virtual void f1(void*);
    virtual void Call(void*);
    virtual bool initialize(unsigned __int64 id, Factory_239f10* factory, Reader* reader);
    virtual void _m_vf4();
    virtual Node* clone();
    union { Node* link; Node* next; };
    void Set_00236b70(Node*);
    void FUN_00236b70(Node* nextNode);
};
class Owner_239e30 {
  public:
    Node* head;
    void run(void*);
};
class Owner_239e60 {
  public:
    Node* head;
    void Walk(void*);
};
class List {
  public:
    Node* head;
    int Add(Node* p);
};
struct Reader {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
 virtual bool more(); virtual unsigned __int64 readId();
 void FUN_00232c90();
};
struct Factory_239f10 { Node* FUN_002367f0(unsigned __int64 id); };
extern void __cdecl FUN_00232cc0(Reader*, const char*, ...);
extern unsigned int __cdecl FUN_00238190(int);
extern "C" unsigned int __cdecl FUN_00266da0(unsigned int);
struct List_239f10 { Node* head; bool FUN_00239f10(Factory_239f10*, Reader*, int); };
class Obj_23a020 {
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
    virtual bool Check();
    virtual long long Pair();
    virtual void v15();
    virtual void Act(int, int);
    virtual void Done();
};
class Owner_23a020 {
  public:
    bool Target(int a, int b, int c, Obj_23a020* obj);
    void Work_00239f10(int, Obj_23a020*, int);
};


// 0x00239d50 FUN_00239d50 (9 B): matches/0x00239d50.cpp
// sym: ??0A_239d50@fn_f6f801d4@@QAE@XZ
A_239d50::A_239d50() {
    x = 0;
}


// 0x00239e10 FUN_00239e10 (24 B): matches/0x00239e10.cpp
// sym: ?Clear@Holder_239e10@fn_f6f801d4@@QAEXXZ
// Same code shape as 0x00236ec0 (propagated; names are from that function)
void Holder_239e10::Clear() {
    if (p)
        p->Release(1);
    p = 0;
}


// 0x00239e30 FUN_00239e30 (36 B): matches/0x00239e30.cpp
// sym: ?run@Owner_239e30@fn_f6f801d4@@QAEXPAX@Z
// Same code shape as 0x00236ee0 (propagated; names are from that function)
void Owner_239e30::run(void* arg) {
    for (Node* p = head; p != 0; p = p->next)
        p->f1(arg);
}


// 0x00239e60 FUN_00239e60 (36 B): matches/0x00239e60.cpp
// sym: ?Walk@Owner_239e60@fn_f6f801d4@@QAEXPAX@Z
// Same code shape as 0x00236f10 (propagated; names are from that function)
void Owner_239e60::Walk(void* arg) {
    for (Node* p = head; p; p = p->next)
        p->Call(arg);
}


// 0x00239e90 FUN_00239e90 (24 B): matches/0x00239e90.cpp
// sym: ?Clear@Holder_239e90@fn_f6f801d4@@QAEXXZ
// Same code shape as 0x00236ec0 (propagated; names are from that function)
void Holder_239e90::Clear() {
    if (p)
        p->Release(1);
    p = 0;
}


// 0x00239eb0 FUN_00239eb0 (84 B): matches/0x00239eb0.cpp
// sym: ?Add@List@fn_f6f801d4@@QAEHPAVNode@2@@Z
int List::Add(Node* p) {
    if (!p)
        return -1;
    Node* n = head;
    Node* last = 0;
    int i = 0;
    while (n) {
        last = n;
        n = n->link;
        ++i;
    }
    p->Set_00236b70(n);
    if (last)
        last->Set_00236b70(p);
    else
        head = p;
    return i;
}


// 0x00239f10 FUN_00239f10 (267 B): equivalent/0x00239f10.cpp
// sym: ?FUN_00239f10@List_239f10@fn_f6f801d4@@QAE_NPAUFactory_239f10@2@PAUReader@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 21/22, incomplete)
// FUN_00239f10 @ 0x00239f10
bool List_239f10::FUN_00239f10(Factory_239f10* factory, Reader* reader, int index) {
 Node* current = head;
 Node* previous = 0;
 int position = 0;
 while (current && index >= 0 && position < index) {
  previous = current;
  current = current->next;
  ++position;
 }
 while (reader->more()) {
  unsigned __int64 id = reader->readId();
  Node* prototype = factory ? factory->FUN_002367f0(id) : 0;
  if (!prototype) {
   FUN_00232cc0(reader, "Unrecognized track.");
   reader->FUN_00232c90();
  } else {
   unsigned int state = FUN_00266da0(FUN_00238190(2));
   Node* node = prototype->clone();
   if (node->initialize(id, factory, reader)) {
    node->FUN_00236b70(current);
    if (previous) previous->FUN_00236b70(node);
    else head = node;
    previous = node;
   }
   FUN_00266da0(state);
  }
 }
 return true;
}


// 0x0023a020 FUN_0023a020 (87 B): matches/0x0023a020.cpp
// sym: ?Target@Owner_23a020@fn_f6f801d4@@QAE_NHHHPAVObj_23a020@2@@Z
// Same code shape as 0x00237160 (propagated; names are from that function)
bool Owner_23a020::Target(int a, int b, int c, Obj_23a020* obj) {
    if (!obj->Check())
        return false;
    unsigned long long v = (unsigned long long)obj->Pair();
    if ((unsigned int)v != (unsigned int)a)
        return false;
    if ((unsigned int)(v >> 32) != (unsigned int)b)
        return false;
    obj->Act(a, b);
    Work_00239f10(c, obj, -1);
    obj->Done();
    return true;
}

} // namespace fn_f6f801d4
