// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00232c40..0x00234090 (kind game, layer engine, confidence high), dominant class fight::Branch
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3f1aadd {
#define TREE_TU_END }
namespace fn_f3f1aadd {} using namespace fn_f3f1aadd;
#include "engine/fight.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f3f1aadd {
class Local_232c40 {
  public:
    char data[8];
    void Init_0027af00();
    void Finish_0027af50();
};
class Helper_232c40 {
  public:
    void Do_0027af70(Local_232c40*);
};
class T_232c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool Run(int, int, Local_232c40*);
    char Target(int a, int b, Helper_232c40* h);
};
class Obj {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void v10(__int64, int);
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual __int64 get();
    virtual void _m_vf15();
    virtual __int64 convert(__int64);
    virtual void finish();
    __int64 run();
    void Fn(int, int);
};
extern "C" __int64 __cdecl helper(hulk_intptr, int, int);
extern "C" char DAT_00427898[];
typedef unsigned int u32_232e90;
struct Branch_232e90 {
    void Init_0027b070();
};
struct Inner_232e90 {
    void Init_00236e00();
};
class Branch {
  public:
    virtual void v0();
    char pad04[12];
    u32_232e90 arg;
    u32_232e90 field14;
    Inner_232e90 inner;
    u32_232e90 field1c;
    u32_232e90 field20;
    Branch* Build(u32_232e90);
};
struct Node {
  public:
    char _m_pad_0[0x10];
    int kind;
    union { Node* next; Node* parent; };
    char _m_pad_18[0x8];
    int value;
    void target();
};
extern int hulk_at_0048e090, hulk_at_004ca2b0;
extern void* FUN_00344e74(owners::Node_232f60*, int, const void*, const void*, int);
extern const int DAT_0048e090;
extern const int DAT_004ca2b0;
typedef unsigned int u32_2331f0;
struct Node_2331f0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    char a[0x10];
    int field14;
    char b[8];
    Node_2331f0* next;
};
struct Helper_2331f0 {
    void go_00236ec0();
};
class Sub_233390 {
  public:
    void helper_00236ee0(fight::Branch*);
};
class Node_233390 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    Node_233390* next;
};
class Node_2333c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[0x1c];
    Node_2333c0* next;
};
struct Helper_2333c0 {
    void Fnf_00236f10(void*);
};
struct Inner_2333f0 {
    int Helper_00236f40(void*, void*, void*);
};
struct Branch_2333f0 {
    char pad[0x18];
    Inner_2333f0 inner;
    int Target(void*, void*);
};
class Lexer {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual char HasToken();
    virtual __int64 TokenType();
    void FUN_00232c90();
};
class Branch_2337c0;
class Handler_2337c0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void Parse(int a0, Lexer *lexer, int index);
    char pad04[0x10];
    Branch_2337c0 *parent;
};
struct NodeCtorA { Handler_2337c0 *FUN_0023c620(); };
struct Node_nv_2337c0 {
    Handler_2337c0 *FUN_00231940();
};
struct Store_nv_2337c0 {
    Handler_2337c0 *FUN_0023c500();
};
struct Reference_nv_2337c0 {
    Handler_2337c0 *FUN_0023c2c0();
};
struct ScopeNode {
    char pad0[0x20];
    ScopeNode *next;
};
extern "C" int FUN_00238190(int mode);
extern "C" int FUN_00266da0(hulk_intptr v);
extern "C" void FUN_00232cc0(Lexer *lexer, const char *msg, ...);
void *__cdecl FUN_00263ea0(unsigned int size);
class Branch_2337c0 {
public:
    char pad0[0x1c];
    ScopeNode *scopes;
    char ParseBlock(hulk_intptr a0, Lexer *lexer, int index);
};
class Branch_233970 {
  public:
    void init_00236fd0();
    void finish_0027afd0();
};
class Thing_233dd0 {
  public:
    int a;
    int b;
    int c;
    Thing_233dd0();
};
class Obj_233ef0 {
  public:
    virtual void A();
    virtual void B();
};
class Holder_233ef0 {
  public:
    Obj_233ef0* p;
    void Set(hulk_intptr unused, Obj_233ef0* x);
};
class Obj_233fa0 {
  public:
    virtual void A();
    virtual void B();
};
void FUN_00267090(int);
class Holder_233fa0 {
  public:
    Obj_233fa0* mObj;
    int mValue;
    bool Set(int dummy, Obj_233fa0* p);
};


// 0x00232c40 FUN_00232c40 (80 B): matches/0x00232c40.cpp
// sym: ?Target@T_232c40@fn_f3f1aadd@@QAEDHHPAVHelper_232c40@2@@Z
char T_232c40::Target(int a, int b, Helper_232c40* h) {
    Local_232c40 x;
    x.Init_0027af00();
    bool r = Run(a, b, &x);
    if (r)
        ((Helper_232c40*)((char*)h + 8))->Do_0027af70(&x);
    x.Finish_0027af50();
    return r;
}


// 0x00232c90 FUN_00232c90 (36 B): matches/0x00232c90.cpp
// sym: ?run@Obj@fn_f3f1aadd@@QAE_JXZ
__int64 Obj::run() {
    __int64 y = convert(get());
    finish();
    return y;
}


// 0x00232d70 FUN_00232d70 (20 B): matches/0x00232d70.cpp
// sym: _FUN_00232d70
extern "C" void FUN_00232d70(hulk_intptr a, int b) {
    (*(int*)&DAT_004e5bb0) = a;
    (*(int*)&DAT_004e5bb4) = b;
}


// 0x00232e00 FUN_00232e00 (40 B): matches/0x00232e00.cpp
// sym: ?Fn@Obj@fn_f3f1aadd@@QAEXHH@Z
void Obj::Fn(int a, int b) {
    v10(helper(a, 0, 0), b);
}


// 0x00232e90 FUN_00232e90 (56 B): matches/0x00232e90.cpp
// sym: ?Build@Branch@fn_f3f1aadd@@QAEPAV12@I@Z
Branch* Branch::Build(u32_232e90 param) {
    ((Branch_232e90*)this)->Init_0027b070();
    *((hulk_uintptr*)this) = ((hulk_intptr)DAT_00427898);
    arg = param;
    field14 = 0;
    inner.Init_00236e00();
    field1c = 0;
    field20 = 0;
    return this;
}

} // namespace fn_f3f1aadd

// 0x00232ed0 FUN_00232ed0 (37 B): matches/0x00232ed0.cpp
// sym: ?FUN_00232ed0@Node_232ed0@owners@@QAE_NPAU12@@Z
bool owners::Node_232ed0::FUN_00232ed0(owners::Node_232ed0* other) {
    owners::Node_232ed0* p = next;
    while (p) {
        if (p == other)
            return true;
        p = p->next;
    }
    return false;
}

namespace fn_f3f1aadd {

// 0x00232f00 FUN_00232f00 (84 B): matches/0x00232f00.cpp
// sym: ?target@Node@fn_f3f1aadd@@QAEXXZ
void Node::target() {
    if (kind == 3) {
        __RTDynamicCast((void*)(this), 0, &hulk_at_0048e090, &hulk_at_004ca2b0, 0);
        return;
    }
    Node* q = next;
    while (q && q->kind != 3)
        q = q->next;
    __RTDynamicCast((void*)(q), 0, &hulk_at_0048e090, &hulk_at_004ca2b0, 0);
}

} // namespace fn_f3f1aadd

// 0x00232f60 FUN_00232f60 (84 B): matches/0x00232f60.cpp
// sym: ?FUN_00232f60@Node_232f60@owners@@QAEPAXXZ
void* owners::Node_232f60::FUN_00232f60() {
    if (type == 3)
        return FUN_00344e74(this, 0, &DAT_0048e090, &DAT_004ca2b0, 0);
    owners::Node_232f60* q = next;
    while (q != 0 && q->type != 3)
        q = q->next;
    return FUN_00344e74(q, 0, &DAT_0048e090, &DAT_004ca2b0, 0);
}

namespace fn_f3f1aadd {

// 0x00232fc0 FUN_00232fc0 (21 B): matches/0x00232fc0.cpp
// sym: ?FUN_00232fc0@fn_f3f1aadd@@YIHPAUNode@1@@Z
int __fastcall FUN_00232fc0(Node* p) {
    int v;
    while (p) {
        v = p->value;
        if (v)
            return v;
        p = p->parent;
    }
    return 0;
}

} // namespace fn_f3f1aadd

// 0x00232fe0 FUN_00232fe0 (34 B): equivalent/0x00232fe0.cpp
// sym: ?FUN_00232fe0@Node_232fe0@owners@@QAEPAU12@XZ @e09903816921 @w809246f242bd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00232fe0 @ 0x00232fe0
owners::Node_232fe0* owners::Node_232fe0::FUN_00232fe0() { if (boundary) return boundary; owners::Node_232fe0* node = this; while (node) { if (node->value) return node->value; node = node->parent; } return 0; }


// 0x00233050 FUN_00233050 (25 B): matches/0x00233050.cpp [wrapped: conflict: Node]
// sym: ?Count@Obj@fn_00233050@@QAEHXZ
namespace fn_00233050 {
struct Node {
    char pad[0x20];
    Node* next;
};
class Obj {
  public:
    char pad[0x1c];
    Node* head;
    int Count();
};
int Obj::Count() {
    Node* p = head;
    int n = 0;
    while (p) {
        p = p->next;
        ++n;
    }
    return n;
}
} // namespace fn_00233050


// 0x00233160 FUN_00233160 (86 B): matches/0x00233160.cpp [wrapped: conflict: Node]
// sym: ?Append@Container_233160@fn_00233160@@QAEHPAVNode@2@@Z
namespace fn_00233160 {
class Node {
  public:
    virtual void Init();
    char pad04[0x10];
    void* owner;
    char pad18[8];
    Node* next;
};
class Container_233160 {
  public:
    char pad00[0x1c];
    Node* head;
    int Append(Node* node);
};
int Container_233160::Append(Node* node) {
    if (!node)
        return -1;
    int count = 0;
    Node* prev = 0;
    Node* cur = head;
    while (cur) {
        prev = cur;
        ++count;
        cur = cur->next;
    }
    if (prev)
        prev->next = node;
    else
        head = node;
    node->next = cur;
    node->owner = this;
    node->Init();
    return count;
}
} // namespace fn_00233160


// 0x002331c0 FUN_002331c0 (44 B): matches/0x002331c0.cpp [wrapped: conflict: Node]
// sym: ?FUN_002331c0@Owner@fn_002331c0@@QAEXXZ
namespace fn_002331c0 {
struct Node {
    virtual void slot0();
    virtual void release();
    char pad[16];
    Node* prev;
    char pad2[8];
    Node* next;
};
struct Owner {
    char pad[28];
    Node* head;
    void FUN_002331c0();
};
void Owner::FUN_002331c0() {
    for (Node* node = head; node;) {
        Node* old = node;
        node = node->next;
        old->next = 0;
        old->prev = 0;
        old->release();
    }
    head = 0;
}
} // namespace fn_002331c0


// 0x002331f0 fight::Branch::vfunc_7 (50 B): matches/0x002331f0.cpp
// sym: ?vfunc_7@Branch@fight@@UAEXXZ
void fight::Branch::vfunc_7() {
    ((Helper_2331f0*)((char*)this + 0x18))->go_00236ec0();
    Node_2331f0* p = (*(Node_2331f0 * *)&this->f_1c);
    while (p) {
        Node_2331f0* c = p;
        p = c->next;
        c->next = 0;
        c->field14 = 0;
        c->f1();
    }
    (*(Node_2331f0 * *)&this->f_1c) = 0;
}


// 0x00233230 FUN_00233230 (86 B): matches/0x00233230.cpp [wrapped: conflict: Node]
// sym: ?Remove@List@fn_00233230@@QAE_NH@Z
namespace fn_00233230 {
class Node {
  public:
    virtual void A();
    virtual void B();
    char pad[16];
    int value;
    char pad2[8];
    Node* next;
};
class List {
    char pad[28];
    Node* head;

  public:
    bool Remove(int n);
};
bool List::Remove(int n) {
    Node* p = head;
    Node* prev = 0;
    int i = 0;
    while (p) {
        if (i > n)
            break;
        if (i == n) {
            if (prev)
                prev->next = p->next;
            else
                head = p->next;
            p->value = 0;
            p->next = 0;
            p->B();
            return true;
        }
        prev = p;
        p = p->next;
        ++i;
    }
    return false;
}
} // namespace fn_00233230


// 0x00233320 FUN_00233320 (59 B): equivalent/0x00233320.cpp
// sym: ?FUN_00233320@Node_233320@owners@@QAEPAU12@HH@Z @99feae2467f5 @w0428d8fd16b7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00233320 @ 0x00233320
owners::Node_233320 *owners::Node_233320::FUN_00233320(int first, int second) {
    if (key1 == first && key2 == second) return this;
    for (owners::Node_233320 *node = child; node != 0; node = node->next) {
        if (node->key1 == first && node->key2 == second) return node;
    }
    return 0;
}


// 0x00233390 fight::Branch::vfunc_5 (35 B): matches/0x00233390.cpp
// sym: ?vfunc_5@Branch@fight@@UAEXXZ
void fight::Branch::vfunc_5() {
    ((Sub_233390*)((char*)this + 0x18))->helper_00236ee0(this);
    for (Node_233390* p = (*(Node_233390 * *)&this->f_1c); p; p = p->next)
        p->f5();
}


// 0x002333c0 fight::Branch::vfunc_6 (42 B): matches/0x002333c0.cpp
// sym: ?vfunc_6@Branch@fight@@UAEXXZ
void fight::Branch::vfunc_6() {
    Node_2333c0* p = (*(Node_2333c0 * *)&this->f_1c);
    while (p) {
        p->f6();
        p = p->next;
    }
    ((Helper_2333c0*)((char*)this + 0x18))->Fnf_00236f10(this);
}

namespace fn_f3f1aadd {

// 0x002333f0 FUN_002333f0 (22 B): matches/0x002333f0.cpp
// sym: ?Target@Branch_2333f0@fn_f3f1aadd@@QAEHPAX0@Z
int Branch_2333f0::Target(void* a, void* b) {
    return inner.Helper_00236f40(this, a, b);
}


// 0x002337c0 FUN_002337c0 (426 B): equivalent/0x002337c0.cpp
// sym: ?ParseBlock@Branch_2337c0@fn_f3f1aadd@@QAEDHPAVLexer@2@H@Z @8086b6c364d4 @waef39cccf69a
// STATUS: equivalent (tools/equiv.py level 3: 13637 inputs, branch coverage 40/40)
// FUN_002337c0 @ 0x002337c0
char Branch_2337c0::ParseBlock(hulk_intptr a0, Lexer *lexer, int index)
{
    int saved = FUN_00266da0(FUN_00238190(2));

    while (lexer->HasToken()) {
        int depth = 0;
        for (ScopeNode *n = scopes; n != 0; n = n->next)
            depth++;

        Handler_2337c0 *h = 0;
        void *mem;
        bool known = true;
        if (lexer->TokenType() == DAT_004e5b30) {
            mem = FUN_00263ea0(0x28);
            if (mem)
                h = ((NodeCtorA *)mem)->FUN_0023c620();
        } else if (lexer->TokenType() == DAT_004e5b70) {
            mem = FUN_00263ea0(0x30);
            if (mem)
                h = ((Node_nv_2337c0*)(((fight::Node*)(((fight::Node *)mem)))))->FUN_00231940();
        } else if (lexer->TokenType() == (*(__int64*)&DAT_004e5ba8)) {
            mem = FUN_00263ea0(0x28);
            if (mem)
                h = ((Store_nv_2337c0*)(((fight::Store*)(((fight::Store *)mem)))))->FUN_0023c500();
        } else if (lexer->TokenType() == (*(__int64*)&DAT_004e5b10)) {
            mem = FUN_00263ea0(0x38);
            if (mem)
                h = ((Reference_nv_2337c0*)(((fight::Reference*)(((fight::Reference *)mem)))))->FUN_0023c2c0();
        } else {
            FUN_00232cc0(lexer, "Unexpected token.");
            lexer->FUN_00232c90();
            known = false;
        }
        if (known) {
            h->AddRef();
            h->parent = this;
            h->Parse(a0, lexer, index);
            h->Release();
        }
        int depth2 = 0;
        for (ScopeNode *n = scopes; n != 0; n = n->next)
            depth2++;
        if (depth2 > depth && index >= 0)
            index++;
    }

    FUN_00266da0(saved);
    return 1;
}

} // namespace fn_f3f1aadd

// 0x00233970 FUN_00233970 (30 B): matches/0x00233970.cpp
// sym: ?FUN_00233970@Branch@fight@@QAEXXZ
void fight::Branch::FUN_00233970() {
    *(void**)this = (void*)((hulk_intptr)DAT_00427898);
    fight::Branch::vfunc_7();
    ((Branch_233970*)((char*)this + 0x18))->init_00236fd0();
    ((Branch_233970*)this)->finish_0027afd0();
}


// 0x00233990 FUN_00233990 (115 B): equivalent/0x00233990.cpp [wrapped: conflict: Node]
// sym: ?FUN_00233990@Node@fn_00233990@@QAEPAU12@XZ @574d0a266de2 @w23aac7e998bf
namespace fn_00233990 {
// STATUS: equivalent (tools/equiv.py level 3: 3052 inputs, branch coverage 22/28, incomplete)
// FUN_00233990 @ 0x00233990
struct Node {
    char pad0[0x14];
    Node *parent;
    char pad18[4];
    Node *firstChild;
    Node *next;
    Node *FUN_00233990();
};

// Walks down from this: at each level, picks the last child (counting from the end of the
// child list) whose parent pointer is the current node. Returns the current node when it has
// no such child, or the chosen child when that child is a leaf.
Node *Node::FUN_00233990()
{
    Node *cur = this;
    for (;;) {
        Node *head = cur->firstChild;
        int count = 0;
        for (Node *c = head; c != 0; c = c->next)
            count++;
        Node *found = 0;
        for (int i = count - 1; i >= 0 && found == 0; i--) {
            Node *c = head;
            for (int k = 0; c != 0 && k < i; k++)
                c = c->next;
            if (c != 0 && c->parent == cur)
                found = c;
        }
        if (found == 0)
            return cur;
        if (found->firstChild == 0)
            return found;
        cur = found;
    }
}
} // namespace fn_00233990


// 0x00233b30 FUN_00233b30 (114 B): equivalent/0x00233b30.cpp [wrapped: conflict: Node]
// sym: ?FUN_00233b30@List_233b30@fn_00233b30@@QAEHHPAVNode@2@@Z @b9f201bf880e @w74d0c906ee44
namespace fn_00233b30 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 13/14, incomplete)
// FUN_00233b30 @ 0x00233b30
class Node;

class Node {
public:
    virtual void OnAttached();
    char pad04[0x14 - 4];
    class List_233b30* owner;      // 0x14
    char pad18[0x20 - 0x18];
    Node* next;             // 0x20
};

class List_233b30 {
public:
    char pad0[0x1c];
    Node* head;             // 0x1c
    int FUN_00233160(Node* node);
    int FUN_00233b30(int index, Node* node);
};

// Inserts node at the given position (end if past the last); negative index appends via FUN_00233160.
int List_233b30::FUN_00233b30(int index, Node* node)
{
    if (node == 0)
        return -1;
    if (index < 0)
        return FUN_00233160(node);
    Node* cur = head;
    Node* prev = 0;
    int i = 0;
    while (cur != 0 && i < index) {
        prev = cur;
        cur = cur->next;
        i++;
    }
    if (prev != 0)
        prev->next = node;
    else
        head = node;
    node->owner = this;
    node->next = cur;
    node->OnAttached();
    return i;
}
} // namespace fn_00233b30


// 0x00233bb0 FUN_00233bb0 (94 B): matches/0x00233bb0.cpp [wrapped: conflict: Node]
// sym: ?H@Owner_233bb0@fn_00233bb0@@QAEDHH@Z
namespace fn_00233bb0 {
class Node {
  public:
    virtual void A();
    virtual void B();
    char pad[0x1c];
    Node* next;
};
class Owner_233bb0 {
    char pad[0x1c];
    Node* head;

  public:
    void FnF_00233230(int);
    void FnG_00233b30(int, Node*);
    char H(int i, int v);
};
char Owner_233bb0::H(int i, int v) {
    Node* n = head;
    int k = 0;
    while (n) {
        if (i < k)
            return 0;
        if (i == k)
            break;
        n = n->next;
        ++k;
    }
    if (!n)
        return 0;
    n->A();
    FnF_00233230(i);
    FnG_00233b30(v, n);
    n->B();
    return 1;
}
} // namespace fn_00233bb0


// 0x00233d90 fight::Branch::vfunc_2 (51 B): matches/0x00233d90.cpp [wrapped: conflict: fight::Branch]
// sym: ?vfunc_2@Branch@fight@fn_00233d90@@UAEPAV123@E@Z
namespace fn_00233d90 {
typedef unsigned char u8_233d90;
namespace fight {
class Other_233d90 {
  public:
    void f1_00236fd0();
};
class Branch {
  public:
    virtual void v0();
    virtual void v1();
    virtual Branch* vfunc_2(u8_233d90);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7x();
    char pad[0x14];
    Other_233d90 sub;
    void vfunc_7_002331f0();
    void base_fn_0027afd0();
};
extern "C++" { extern char hulk_at_00427898[]; }
void __cdecl thunk_FUN_00267090(Branch*);
Branch* Branch::vfunc_2(u8_233d90 param) {
    *(void**)this = (void*)hulk_at_00427898;
    vfunc_7_002331f0();
    sub.f1_00236fd0();
    base_fn_0027afd0();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fight
} // namespace fn_00233d90

namespace fn_f3f1aadd {

// 0x00233dd0 FUN_00233dd0 (23 B): matches/0x00233dd0.cpp
// sym: ??0Thing_233dd0@fn_f3f1aadd@@QAE@XZ
Thing_233dd0::Thing_233dd0() : a(0), b(0), c(-1) {}


// 0x00233ef0 FUN_00233ef0 (36 B): matches/0x00233ef0.cpp
// sym: ?Set@Holder_233ef0@fn_f3f1aadd@@QAEXHPAVObj_233ef0@2@@Z
void Holder_233ef0::Set(hulk_intptr unused, Obj_233ef0* x) {
    if (x)
        x->A();
    if (p)
        p->B();
    p = x;
}

} // namespace fn_f3f1aadd

// 0x00233f20 FUN_00233f20 (123 B): equivalent/0x00233f20.cpp [wrapped: conflict: FUN_00238190]
// sym: ?FUN_00233f20@NameHolder_233f20@fn_00233f20@@QAE_NPBD@Z @3560526a3702 @w57b80b327b1a
namespace fn_00233f20 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 12/12)
// FUN_00233f20 @ 0x00233f20
class Owned_233f20 {
public:
    virtual void v0();
    virtual void Release();
};

void FUN_00267090(char *p);
void *FUN_00238190(int kind);
extern "C" char *FUN_00266e00(void *pool, int size);

class NameHolder_233f20 {
public:
    bool FUN_00233f20(const char *name);

    Owned_233f20 *owner;
    char *text;
};

bool NameHolder_233f20::FUN_00233f20(const char *name) {
    if (text != name) {
        FUN_00267090(text);
        int len = 0;
        if (name != 0) {
            const char *p = name;
            while (*p++) {
            }
            len = (int)(p - name) - 1;
        }
        if (len > 0) {
            text = FUN_00266e00(FUN_00238190(2), len + 1);
            const char *src = name;
            char *dst = text;
            char c;
            do {
                c = *src++;
                *dst++ = c;
            } while (c);
        } else {
            text = 0;
        }
        if (owner != 0) {
            owner->Release();
        }
        owner = 0;
    }
    return true;
}
} // namespace fn_00233f20

namespace fn_f3f1aadd {

// 0x00233fa0 FUN_00233fa0 (63 B): matches/0x00233fa0.cpp
// sym: ?Set@Holder_233fa0@fn_f3f1aadd@@QAE_NHPAVObj_233fa0@2@@Z
bool Holder_233fa0::Set(int dummy, Obj_233fa0* p) {
    if (p != mObj) {
        FUN_00267090(mValue);
        mValue = 0;
        if (p)
            p->A();
        if (mObj)
            mObj->B();
        mObj = p;
    }
    return true;
}

} // namespace fn_f3f1aadd
