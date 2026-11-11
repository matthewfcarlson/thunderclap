// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002366e0..0x00236940 (kind game, layer engine, confidence medium), dominant class fight::Context
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_feea6610 {
#define TREE_TU_END }
namespace fn_feea6610 {} using namespace fn_feea6610;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_feea6610 {
class Item_2366e0 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_2366e0 {
  public:
};
class Temp_2366e0 {
    char pad[8];

  public:
    void Init_002314a0(Owner_2366e0*);
    Item_2366e0* First_00231640();
    Item_2366e0* Next_002314c0();
};
class Item_236720 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_236720 {
  public:
};
class Temp_236720 {
    char pad[8];

  public:
    void Init_002314a0(Owner_236720*);
    Item_236720* First_00231640();
    Item_236720* Next_002314c0();
};
struct Param {
    virtual void F();
    char pad[4];
    int a;
    int b;
};
struct Helper_236760 {
    void Run_00231590(int, int, Param*);
};
struct Owner_236760 {
    char pad[0x14];
    Helper_236760 helper;
    bool Target(Param* p);
};
class Helper_236790 {
    char pad[0x18];

  public:
    Helper_236790(void*);
    int Run_00231180(int, int);
};
class Source_2367c0 {
  public:
    virtual void V();
    int pad;
    int b;
    int a;
};
class Sub_2367c0 {
  public:
    void FnH_00231590(int, int, Source_2367c0*);
};
class Owner_2367c0 {
  public:
    char pad[0x38];
    Sub_2367c0 sub;
    bool F(Source_2367c0*);
};
struct Inner_2367f0 {};
struct Tmp_2367f0 {
    char pad[0x18];
    Tmp_2367f0(Inner_2367f0*);
    int Fnf_00231180(int, int);
};
struct Obj_2367f0 {
    char pad[0x38];
    Inner_2367f0 inner;
    int target(int, int);
};
class Obj_236820 {
  public:
    void FnA_002366e0();
    void Target();
};
class Obj_236830 {
  public:
    void FnA_00236720();
    void Target();
};
class Obj_2368d0 {
  public:
    virtual void A();
    virtual void B();
};
struct SubB_2368d0 {
    void Init_002366e0();
    void Fini_00231050();
    char pad[0x24];
};
struct SubA_2368d0 {
    void Init_00236720();
    void Fini_00231050();
    char pad[0x20];
};
class Context_2368d0 {
  public:
    void Dtor_0027afd0();
};
class Context {
  public:
    virtual ~Context();
    char pad4[0x0c];
    Obj_2368d0* p10;
    SubB_2368d0 b14;
    SubA_2368d0 a38;
    char pad58[4];
    Obj_2368d0* p5c;
};


// 0x002366e0 FUN_002366e0 (64 B): matches/0x002366e0.cpp
// sym: ?FUN_002366e0@fn_feea6610@@YIXPAVOwner_2366e0@1@@Z
void __fastcall FUN_002366e0(Owner_2366e0* self) {
    Temp_2366e0 t;
    t.Init_002314a0(self);
    Item_2366e0* item = t.First_00231640();
    while (item) {
        item->V1();
        item = t.Next_002314c0();
    }
    ((owners::X_231070 *)self)->FUN_00231070();
}


// 0x00236720 FUN_00236720 (64 B): matches/0x00236720.cpp
// sym: ?FUN_00236720@fn_feea6610@@YIXPAVOwner_236720@1@@Z
// Same code shape as 0x002366e0 (propagated; names are from that function)
void __fastcall FUN_00236720(Owner_236720* self) {
    Temp_236720 t;
    t.Init_002314a0(self);
    Item_236720* item = t.First_00231640();
    while (item) {
        item->V1();
        item = t.Next_002314c0();
    }
    ((owners::X_231070 *)self)->FUN_00231070();
}


// 0x00236760 FUN_00236760 (42 B): matches/0x00236760.cpp
// sym: ?Target@Owner_236760@fn_feea6610@@QAE_NPAUParam@2@@Z
bool Owner_236760::Target(Param* p) {
    int x = p->a;
    int y = p->b;
    p->F();
    helper.Run_00231590(x, y, p);
    return true;
}

} // namespace fn_feea6610

// 0x00236790 FUN_00236790 (41 B): matches/0x00236790.cpp
// sym: ?FUN_00236790@Target_236790@owners@@QAEHHH@Z
int owners::Target_236790::FUN_00236790(int a, int b) {
    Helper_236790 h((char*)this + 0x14);
    return h.Run_00231180(a, b);
}

namespace fn_feea6610 {

// 0x002367c0 FUN_002367c0 (42 B): matches/0x002367c0.cpp
// sym: ?F@Owner_2367c0@fn_feea6610@@QAE_NPAVSource_2367c0@2@@Z
bool Owner_2367c0::F(Source_2367c0* src) {
    int b = src->b;
    int a = src->a;
    src->V();
    sub.FnH_00231590(b, a, src);
    return true;
}


// 0x002367f0 FUN_002367f0 (41 B): matches/0x002367f0.cpp
// sym: ?target@Obj_2367f0@fn_feea6610@@QAEHHH@Z
int Obj_2367f0::target(int a, int b) {
    Tmp_2367f0 t(&inner);
    return t.Fnf_00231180(a, b);
}


// 0x00236820 FUN_00236820 (16 B): matches/0x00236820.cpp
// sym: ?Target@Obj_236820@fn_feea6610@@QAEXXZ
void Obj_236820::Target() {
    FnA_002366e0();
    ((owners::C_231050 *)this)->FUN_00231050();
}


// 0x00236830 FUN_00236830 (16 B): matches/0x00236830.cpp
// sym: ?Target@Obj_236830@fn_feea6610@@QAEXXZ
// Same code shape as 0x00236820 (propagated; names are from that function)
void Obj_236830::Target() {
    FnA_00236720();
    ((owners::C_231050 *)this)->FUN_00231050();
}

} // namespace fn_feea6610

// 0x00236840 FUN_00236840 (135 B): equivalent/0x00236840.cpp [wrapped: conflict: fight::Context; pure3d::Entity]
// sym: ??0Context@fight@fn_00236840@@QAE@XZ
namespace fn_00236840 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00236840 @ 0x00236840
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);
int FUN_00238190(int index);
extern "C" int FUN_00266da0(int value);

struct NameHolder_236840 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct Ring_236840 {
    char data[0x24];
    Ring_236840 *FUN_00231550(int capacity, int a, int b);
};

class Node {
public:
    virtual void AddRef();
    char pad04[4];
    NameHolder_236840 name;
    Node *FUN_0023c620();
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

namespace fight {
class Context : public pure3d::Entity {
public:
    Context();
    virtual void v1();
    int f10;
    Ring_236840 ringA;
    Ring_236840 ringB;
    Node *node;
};

Context::Context()
{
    f10 = 0;
    ringA.FUN_00231550(0x200, 0x50, 100);
    ringB.FUN_00231550(0x200, 0x50, 100);
    int saved = FUN_00266da0(FUN_00238190(0));
    Node *n = (Node *)thunk_FUN_0008d690(0x28);
    if (n)
        n = n->FUN_0023c620();
    node = n;
    n->AddRef();
    node->name.FUN_0027b040("");
    FUN_00266da0(saved);
}
}
} // namespace fn_00236840

namespace fn_feea6610 {

// 0x002368d0 FUN_002368d0 (80 B): matches/0x002368d0.cpp
// sym: ??1Context@fn_feea6610@@UAE@XZ
Context::~Context() {
    p5c->B();
    if (p10) {
        p10->B();
        p10 = 0;
    }
    a38.Init_00236720();
    a38.Fini_00231050();
    b14.Init_002366e0();
    b14.Fini_00231050();
    Context_2368d0* b = (Context_2368d0*)this;
    b->Dtor_0027afd0();
}

} // namespace fn_feea6610

// 0x00236920 fight::Context::vfunc_2 (30 B): matches/0x00236920.cpp
// sym: ??_GContext@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
fight::Context::~Context() {}

