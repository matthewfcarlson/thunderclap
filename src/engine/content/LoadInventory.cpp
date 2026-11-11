// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00266090..0x00266690 (kind game, layer engine, confidence high), dominant class content::LoadInventory
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa919a6c {
#define TREE_TU_END }
namespace fn_fa919a6c {} using namespace fn_fa919a6c;
#include "engine/content.h"

// ---- declarations shared by the functions below
namespace fn_fa919a6c {
class Item_2660a0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_2660a0 {
  public:
    char pad[0x10];
    Item_2660a0* item;
    void Set(Item_2660a0* p);
};
typedef unsigned __int64 U64;
struct Iter {
    __int64 state;      // 8-byte local (forces the original's 8-byte stack alignment)
    void FUN_002314a0(void* head);
    Node* FUN_00231640();
    U64 FUN_00231530();
    Node* FUN_002314c0();
};
struct Source {
    char pad[0xc];
    void* head;
};
class Listener {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void OnEntry(U64 id, Node* node);
    void FUN_00266220(Source* src);
};
struct Node_266280;
class Matcher {
public:
    virtual int Matches(Node_266280 *node);     // slot 0
};
struct Container;
struct NodeIter {
    char data[0x18];
    void FUN_00231160(Container *c);
    Node_266280 *FUN_00231180(int a, int b);
    Node_266280 *FUN_00231230();
};
class Resolver_266280 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Node_266280 *Resolve(Matcher *m, int a, int b);     // slot 3
};
class Item_266440 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_266440 {
  public:
};
class Temp_266440 {
    char pad[8];

  public:
    void Init(Owner_266440*);
    Item_266440* First();
    Item_266440* Next();
};
class Arg_266510 {
  public:
    virtual void run();
};
class Helper_266510 {
  public:
    void call(void*, void*, Arg_266510*);
};
class Obj_266540 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_266540 {
  public:
};
class C_2665a0 {
  public:
    char pad[12];
    C_2665a0* field;
    void g();
    void f();
};
class Obj_2665b0 {
  public:
    void A();
    void Target();
};
class Thing_2665c0 {
  public:
    void First();
    Thing_2665c0* Target(unsigned char);
};
void __cdecl Third(Thing_2665c0*);
struct Other_2665f0 {
    virtual void f0();
    virtual void f1();
};
struct Helper_2665f0 {
    void f0();
    void f1();
};
struct LoadInventory_2665f0 {
    void* vf;
    char pad[8];
    void* a;
    void* b;
    void run();
};
extern void* vtLoad_2665f0;
extern void* vtRef_2665f0;
extern void thunk(void*);
extern "C" char DAT_0042aec8[];
class Ref_266630 {
  public:
    virtual void f0();
    virtual void f1();
};
class Ops {
  public:
    void a();
    void b();
};
class LoadInventory {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual LoadInventory* vfunc_2(unsigned char);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[8];
    Ops* mA;
    Ref_266630* mB;
};
void thunk_FUN_00267090(void*);
void thunk_FUN_00267090(LoadInventory*);

} // namespace fn_fa919a6c

// 0x00266090 FUN_00266090 (7 B): matches/0x00266090.cpp
// sym: ?FUN_00266090@A_266090@owners@@QAEHXZ
int owners::A_266090::FUN_00266090() {
    return p[1];
}

namespace fn_fa919a6c {

// 0x002660a0 FUN_002660a0 (38 B): matches/0x002660a0.cpp
// sym: ?Set@Owner_2660a0@fn_fa919a6c@@QAEXPAVItem_2660a0@2@@Z
// Same code shape as 0x00059790 (propagated; names are from that function)
void Owner_2660a0::Set(Item_2660a0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}

} // namespace fn_fa919a6c

// 0x00266130 FUN_00266130 (10 B): matches/0x00266130.cpp
// sym: ?FUN_00266130@X_266130@owners@@QAEXE@Z
void owners::X_266130::FUN_00266130(unsigned char value) {
    field = value;
}

namespace fn_fa919a6c {

// 0x00266220 FUN_00266220 (88 B): matches/0x00266220.cpp
// sym: ?FUN_00266220@Listener@fn_fa919a6c@@QAEXPAUSource@2@@Z
void Listener::FUN_00266220(Source* src)
{
    Iter it;
    it.FUN_002314a0(src->head);
    Node* n = it.FUN_00231640();
    if (n) {
        do {
            OnEntry(it.FUN_00231530(), n);
            n = it.FUN_002314c0();
        } while (n);
    }
}

} // namespace fn_fa919a6c

// 0x00266280 content::LoadInventory::vfunc_3 (143 B): equivalent/0x00266280.cpp
// sym: ?vfunc_3@LoadInventory@content@@UAEPAXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// content::LoadInventory::vfunc_3 @ 0x00266280
void* content::LoadInventory::vfunc_3(hulk_intptr __p0, int a, int b) { Matcher * matcher = (Matcher *)__p0;

    if (a == 0 && b == 0)
        return (void*)(0);
    NodeIter it;
    it.FUN_00231160((*(Container * *)&this->f_0c));
    Node_266280 *node = it.FUN_00231180(a, b);
    while (node != 0) {
        if (matcher->Matches(node))
            return (void*)(node);
        node = it.FUN_00231230();
    }
    if ((*(Resolver_266280 * *)&this->f_10) != 0)
        return (void*)((*(Resolver_266280 * *)&this->f_10)->Resolve(matcher, a, b));
    return (void*)(0);
}

namespace fn_fa919a6c {

// 0x00266440 FUN_00266440 (64 B): matches/0x00266440.cpp
// sym: ?FUN_00266440@fn_fa919a6c@@YIXPAVOwner_266440@1@@Z
// Same code shape as 0x002366e0 (propagated; names are from that function)
void __fastcall FUN_00266440(Owner_266440* self) {
    Temp_266440 t;
    t.Init(self);
    Item_266440* item = t.First();
    while (item) {
        item->V1();
        item = t.Next();
    }
    ((owners::X_231070 *)self)->FUN_00231070();
}

} // namespace fn_fa919a6c

// 0x00266480 FUN_00266480 (139 B): equivalent/0x00266480.cpp [wrapped: conflict: content::LoadInventory]
// sym: ??0LoadInventory@content@fn_00266480@@QAE@I@Z
namespace fn_00266480 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00266480 @ 0x00266480
class Pool_266480 {
  public:
    void FUN_00231550(unsigned int size, int a, int b);
    void FUN_00231690();
    char pad0[8];
    unsigned int used;
    char flag;
    char pad1[3];
    unsigned int limit;
    char pad2[0x24 - 0x14];
};
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" unsigned int __cdecl FUN_00356c30(unsigned int n);

extern "C" char DAT_0042aec8[];  // content::LoadInventory's vftable (stored by address: a local class's own vftable
                                  // would be the 64-bit link's stub)
namespace content {
class LoadInventory {
  public:
    void* vftable;
    LoadInventory(unsigned int capacity);
    int field4;
    char flag8;
    char flag9;
    char pad[2];
    Pool_266480* pool;
    int field10;
};
}

content::LoadInventory::LoadInventory(unsigned int capacity) {
    vftable = (void*)DAT_0042aec8;
    field4 = 0;
    flag8 = 1;
    flag9 = 1;
    Pool_266480* p = (Pool_266480*)FUN_0008d690((int)sizeof(Pool_266480));
    if (p != 0) {
        if (capacity == 0 || (capacity & (capacity - 1)) != 0)
            capacity = 1u << (FUN_00356c30(capacity) + 1);
        p->FUN_00231550(capacity, 0x50, 0x64);
    }
    pool = p;
    p->flag = flag8;
    if (flag8 && p->limit < p->used)
        p->FUN_00231690();
    field10 = 0;
}
} // namespace fn_00266480


// 0x00266510 content::LoadInventory::vfunc_4 (38 B): matches/0x00266510.cpp
// sym: ?vfunc_4@LoadInventory@content@@UAEXPAX00@Z
void content::LoadInventory::vfunc_4(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; Arg_266510 * arg = (Arg_266510 *)__p2;

    Helper_266510* h = (*(Helper_266510 * *)&this->f_0c);
    arg->run();
    h->call(a, b, arg);
}


// 0x00266540 content::LoadInventory::vfunc_5 (36 B): matches/0x00266540.cpp
// sym: ?vfunc_5@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00265560 (propagated; names are from that function)
void content::LoadInventory::vfunc_5(void* __p0) { Obj_266540 * p = (Obj_266540 *)__p0;

    int n = ((owners::Obj_231770 *)((*(Holder_266540 * *)&this->f_0c)))->FUN_00231770((hulk_uintptr)(Obj_266540 *)p);
    while (n > 0) {
        p->g();
        --n;
    }
}

namespace fn_fa919a6c {

// 0x002665a0 FUN_002665a0 (8 B): matches/0x002665a0.cpp
// sym: ?f@C_2665a0@fn_fa919a6c@@QAEXXZ
void C_2665a0::f() {
    field->g();
}


// 0x002665b0 FUN_002665b0 (16 B): matches/0x002665b0.cpp
// sym: ?Target@Obj_2665b0@fn_fa919a6c@@QAEXXZ
// Same code shape as 0x00236820 (propagated; names are from that function)
void Obj_2665b0::Target() {
    A();
    ((owners::C_231050 *)this)->FUN_00231050();
}


// 0x002665c0 FUN_002665c0 (37 B): matches/0x002665c0.cpp
// sym: ?Target@Thing_2665c0@fn_fa919a6c@@QAEPAV12@E@Z
Thing_2665c0* Thing_2665c0::Target(unsigned char flags) {
    First();
    ((owners::C_231050 *)this)->FUN_00231050();
    if (flags & 1)
        Third(this);
    return this;
}


// 0x002665f0 FUN_002665f0 (61 B): matches/0x002665f0.cpp
// sym: ?run@LoadInventory_2665f0@fn_fa919a6c@@QAEXXZ
void LoadInventory_2665f0::run() {
    void* x = a;
    vf = &vtLoad_2665f0;
    if (x) {
        ((Helper_2665f0*)x)->f0();
        ((Helper_2665f0*)x)->f1();
        thunk(x);
    }
    if (b)
        ((Other_2665f0*)b)->f1();
    vf = &vtRef_2665f0;
}


// 0x00266630 content::LoadInventory::vfunc_2 (81 B): matches/0x00266630.cpp
// sym: ?vfunc_2@LoadInventory@fn_fa919a6c@@UAEPAV12@E@Z
LoadInventory* LoadInventory::vfunc_2(unsigned char b) {
    Ops* p = mA;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042aec8);
    if (p) {
        p->a();
        p->b();
        thunk_FUN_00267090((void*)p);
    }
    if (mB)
        mB->f1();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
    if (b & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fa919a6c
