// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002634c0..0x00263f30 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f551a4d0 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f551a4d0 {} using namespace fn_f551a4d0;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f551a4d0 {
struct X_2634c0 {
    char pad[0x10];
    int a;
    char pad14[4];
    int b;
    int c;
};
struct Obj_263500 {
    int pad[6];
    int a;
    int b;
};
extern bool8 __cdecl Check(int, const char*, ...);
extern "C" bool8 __cdecl FUN_0025ac30(int*, int, int);
struct Node {
  public:
    union { Node* a; Node* left; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_2635a0 {
    Node* root;
};
struct Tree_2635f0 {
    Node* root;
    Node head;
};
struct Header {
    int pad;
    Node node;
};
struct RbNode_263690 {
    RbNode_263690* left;
    RbNode_263690* right;
    RbNode_263690* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_263690 {
    RbNode_263690* root;
    RbNode_263690 nil;
};
struct Stamp {
    unsigned char b[7];
};
struct Id_263c90 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" void __cdecl FUN_00267ad0(Stamp *out);
extern "C" unsigned int __cdecl FUN_00267f00();
extern "C++" __declspec(nothrow) void * __cdecl FUN_00263970(void *, const void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00263bb0(void *, void *);
struct Pair {
    int a, b;
};
extern "C" char __cdecl lookup(int, Pair*);
struct Obj {
    void use(int, int);
};
typedef unsigned int u32_263df0;
struct Item_263df0 {
    char pad[0x10];
    u32_263df0 value;
};
__int64 __cdecl F2();
void __cdecl F3(char*, void*, __int64*);
class C_263e30 {
  public:
    char pad[0x10];
    int m10;
    int pad2;
    __int64 m18;
    void Set(int a, __int64* p);
};
class A_263e90 {
  public:
    virtual void f();
    virtual void g();
};
typedef unsigned int U_263ed0;
extern "C" U_263ed0 __cdecl FUN_00266da0(U_263ed0);
extern "C" U_263ed0 __cdecl FUN_0008d690(U_263ed0);


// 0x002634c0 FUN_002634c0 (14 B): matches/0x002634c0.cpp
// sym: ?FUN_002634c0@fn_f551a4d0@@YIPAUX_2634c0@1@PAU21@@Z
X_2634c0* __fastcall FUN_002634c0(X_2634c0* self) {
    X_2634c0* p = self;
    p->a = 0;
    p->b = 0;
    p->c = 0;
    return p;
}


// 0x00263500 FUN_00263500 (77 B): matches/0x00263500.cpp
// sym: _FUN_00263500
extern "C" int __cdecl FUN_00263500(int* p, Obj_263500* o) {
    int a;
    int b;
    if (o) {
        a = o->a;
        b = o->b;
    } else {
        a = 0;
        b = 0;
    }
    if (Check(*p, DAT_0042ae80) && FUN_0025ac30(p, a, b))
        return 1;
    return 0;
}


// 0x002635a0 FUN_002635a0 (78 B): matches/0x002635a0.cpp
// sym: ?insert@fn_f551a4d0@@YAXPAUTree_2635a0@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_2635a0* tree, Node* node) {
    Node* child = node->b;
    node->b = child->a;
    if (child->a != (Node*)(tree + 1)) {
        child->a->c = node;
    }
    child->c = node->c;
    Node* parent = node->c;
    if (parent == (Node*)(tree + 1)) {
        *reinterpret_cast<Node**>(tree) = child;
        child->a = node;
        node->c = child;
        return;
    }
    if (node == parent->a) {
        parent->a = child;
        child->a = node;
        node->c = child;
        return;
    }
    parent->b = child;
    child->a = node;
    node->c = child;
}


// 0x002635f0 FUN_002635f0 (81 B): matches/0x002635f0.cpp
// sym: ?swap_node@fn_f551a4d0@@YAXPAUTree_2635f0@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_2635f0* tree, Node* node) {
    Node* child = node->left;
    node->left = child->parent;
    if (child->parent != &tree->head)
        child->parent->right = node;
    child->right = node->right;
    Node* p = node->right;
    if (p == &tree->head) {
        tree->root = child;
        child->parent = node;
        node->right = child;
        return;
    }
    if (node == p->left) {
        p->left = child;
        child->parent = node;
        node->right = child;
        return;
    }
    p->parent = child;
    child->parent = node;
    node->right = child;
}


// 0x00263650 FUN_00263650 (55 B): matches/0x00263650.cpp
// sym: ?findNext@fn_f551a4d0@@YAPAUNode@1@PAUHeader@1@PAU21@@Z
Node* __cdecl findNext(Header* h, Node* x) {
    Node* end = &h->node;
    Node* p = x->parent;
    if (p != end) {
        while (p->left != end)
            p = p->left;
    } else {
        p = x->right;
        while (p != end && x == p->parent) {
            x = p;
            p = p->right;
        }
    }
    return p;
}


// 0x00263690 FUN_00263690 (604 B): equivalent/0x00263690.cpp
// sym: _FUN_00263690
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00263690 @ 0x00263690
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00263690(void * tree_, void * x_)
{
    RbTree_263690 * tree = (RbTree_263690 *)tree_;
    RbNode_263690 * x = (RbNode_263690 *)x_;
    RbNode_263690* nil = &tree->nil;
    RbNode_263690* y;
    RbNode_263690* z;
    RbNode_263690* p;
    RbNode_263690* c;

    if (x == tree->root) {
        x->color = 0;
        return;
    }
    while (x->color == 0 /* black */) {
        if (x == x->parent->left) {
            y = x->parent->right;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                y = x->parent->right;
            }
            if (y->left->color == 0 && y->right->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->right->color == 0) {
                    y->left->color = 0;
                    z = y->left;
                    y->color = 1;
                    y->left = z->right;
                    if (z->right != nil)
                        z->right->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->right = y;
                    y->parent = z;
                    y = x->parent->right;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->right->color = 0;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                x = tree->root;
            }
        } else {
            y = x->parent->left;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                y = x->parent->left;
            }
            if (y->right->color == 0 && y->left->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->left->color == 0) {
                    y->right->color = 0;
                    z = y->right;
                    y->color = 1;
                    y->right = z->left;
                    if (z->left != nil)
                        z->left->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->left = y;
                    y->parent = z;
                    y = x->parent->left;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->left->color = 0;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                x = tree->root;
            }
        }
        if (x == tree->root)
            break;
    }
    x->color = 0;
}

} // namespace fn_f551a4d0

// 0x00263970 FUN_00263970 (75 B): equivalent/0x00263970.cpp [wrapped: conflict: Node]
// sym: _FUN_00263970
namespace fn_00263970 {
// STATUS: equivalent (tools/equiv.py level 3: 615 inputs, branch coverage 15/16, incomplete)
// FUN_00263970 @ 0x00263970
struct Node { Node* left; Node* right; char pad[16]; unsigned int low; unsigned int high; };
struct Tree { Node* root; Node sentinel; };
struct Key { unsigned int low; unsigned int high; };
extern "C" void * __cdecl FUN_00263970(void * tree_, const void * key) {
    Tree * tree = (Tree *)tree_;
    Node* node = tree->root;
    Node* end = &tree->sentinel;
    while (node != end) {
        if (((const Key *)key)->high < node->high || (((const Key *)key)->high == node->high && ((const Key *)key)->low < node->low)) {
            node = node->left;
        } else if (((const Key *)key)->high == node->high && ((const Key *)key)->low <= node->low) {
            return (Node *)node;
        } else {
            node = node->right;
        }
    }
    return (Node *)0;
}
} // namespace fn_00263970


// 0x002639c0 FUN_002639c0 (489 B): equivalent/0x002639c0.cpp [wrapped: conflict: Node; Tree]
// sym: ?FUN_002639c0@fn_002639c0@@YADPAUTree@1@PAUNode@1@PAUKey@1@@Z
namespace fn_002639c0 {
// STATUS: equivalent (tools/equiv.py level 3: 1180 inputs, branch coverage 39/52, incomplete)
// FUN_002639c0 @ 0x002639c0
struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int color;
    char pad10[8];
    unsigned keyLo;
    unsigned keyHi;
};

struct Tree {
    Node *root;
    Node nil;
};

struct Key {
    unsigned lo;
    unsigned hi;
};

void FUN_002635a0(Tree *t, Node *x);
void FUN_002635f0(Tree *t, Node *x);

char FUN_002639c0(Tree *t, Node *n, Key *k)
{
    Node *nil = &t->nil;
    Node *x = t->root;
    Node *p = nil;
    unsigned lo = k->lo;
    unsigned hi = k->hi;

    while (x != nil) {
        p = x;
        if (hi < x->keyHi || (hi == x->keyHi && lo < x->keyLo)) {
            x = x->left;
        } else if (hi > x->keyHi || lo > x->keyLo) {
            x = x->right;
        } else {
            return 0;
        }
    }

    n->parent = p;
    if (p == nil) {
        t->root = n;
    } else if (k->hi > p->keyHi || (k->hi == p->keyHi && k->lo >= p->keyLo)) {
        p->right = n;
    } else {
        p->left = n;
    }

    n->left = nil;
    n->right = nil;
    n->color = 1;

    while (n != t->root && n->parent->color == 1) {
        Node *par = n->parent;
        Node *gp = par->parent;
        if (par == gp->left) {
            Node *u = gp->right;
            if (u->color == 1) {
                par->color = 0;
                u->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == par->right) {
                    n = par;
                    FUN_002635a0(t, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                Node *g = n->parent->parent;
                Node *y = g->left;
                g->left = y->right;
                if (y->right != nil)
                    y->right->parent = g;
                y->parent = g->parent;
                Node *gg = g->parent;
                if (gg == nil)
                    t->root = y;
                else if (g == gg->left)
                    gg->left = y;
                else
                    gg->right = y;
                y->right = g;
                g->parent = y;
            }
        } else {
            Node *u = gp->left;
            if (u->color == 1) {
                par->color = 0;
                u->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == par->left) {
                    n = par;
                    FUN_002635f0(t, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                Node *g = n->parent->parent;
                Node *y = g->right;
                g->right = y->left;
                if (y->left != nil)
                    y->left->parent = g;
                y->parent = g->parent;
                Node *gg = g->parent;
                if (gg == nil)
                    t->root = y;
                else if (g == gg->left)
                    gg->left = y;
                else
                    gg->right = y;
                y->left = g;
                g->parent = y;
            }
        }
    }
    t->root->color = 0;
    return 1;
}
} // namespace fn_002639c0


// 0x00263bb0 FUN_00263bb0 (178 B): matches/0x00263bb0.cpp [wrapped: conflict: Node]
// sym: _FUN_00263bb0
namespace fn_00263bb0 {
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
void* FUN_00263650(void*, void*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00263690(void *, void *);
extern "C" void FUN_00263bb0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00263650(((Node *)tree), ((Node *)node));
    Node* y;
    if (x->left != nil)
        y = x->left;
    else
        y = x->right;
    y->parent = x->parent;
    if (x->parent == nil)
        ((Node *)tree)->left = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    int flag = (x->data == 0);
    if (x != ((Node *)node)) {
        x->parent = ((Node *)node)->parent;
        x->left = ((Node *)node)->left;
        x->right = ((Node *)node)->right;
        x->data = ((Node *)node)->data;
        if (x->parent != nil) {
            if (x->parent->left == ((Node *)node))
                x->parent->left = x;
            else
                x->parent->right = x;
        } else
            ((Node *)tree)->left = x;
        if (x->left != nil)
            x->left->parent = x;
        if (x->right->parent != nil)
            x->right->parent = x;
    }
    if (flag)
        FUN_00263690(((Node *)tree), y);
}
} // namespace fn_00263bb0

namespace fn_f551a4d0 {

// 0x00263c90 FUN_00263c90 (158 B): equivalent/0x00263c90.cpp
// sym: ?FUN_00263c90@fn_f551a4d0@@YA_KXZ
// STATUS: equivalent (tools/equiv.py level 3: 16731 inputs, branch coverage 4/4)
// FUN_00263c90 @ 0x00263c90
// FUN_00263c90 @ 0x00263c90: build a unique 64-bit id from the clock and bump it until it is not in the id set
    // find
unsigned __int64 __cdecl FUN_00263c90()
{
    Id_263c90 id;
    Stamp now;

    FUN_00267ad0(&now);
    unsigned int hi = ((unsigned int)now.b[2] << 28) | ((unsigned int)now.b[3] << 23) |
                      ((unsigned int)now.b[4] << 18) | ((unsigned int)now.b[5] << 12) |
                      ((unsigned int)now.b[6] << 6);
    unsigned int lo = FUN_00267f00();
    id.lo = lo;
    id.hi = hi;
    while (((int)(hulk_uintptr)FUN_00263970(((int*)&DAT_004cd4cc), (Id_263c90 *)(&id)))) {
        // 64-bit increment kept in registers: the find call overwrites the local
        lo++;
        if (lo == 0)
            hi++;
        id.lo = lo;
        id.hi = hi;
    }
    return ((unsigned __int64)hi << 32) | lo;
}

} // namespace fn_f551a4d0

// 0x00263d30 FUN_00263d30 (15 B): matches/0x00263d30.cpp
// sym: ?FUN_00263d30@X_263d30@owners@@QAEXXZ
void owners::X_263d30::FUN_00263d30() {
    FUN_00263bb0((void*)((hulk_intptr)((char*)&DAT_004cd4cc)), this);
}


// 0x00263d40 FUN_00263d40 (98 B): matches/0x00263d40.cpp [wrapped: conflict: FUN_00263c90]
// sym: ?Fn@Obj_263d40@fn_00263d40@@QAEXHH@Z
namespace fn_00263d40 {

struct Pair_263d40 {
    int a, b;
};
extern "C++" __declspec(nothrow) void * __cdecl FUN_00263970(void *, const void *);
extern Pair_263d40 __cdecl FUN_00263c90();
extern "C++" __declspec(nothrow) void __cdecl FUN_00263bb0(void *, void *);
extern void __cdecl FUN_002639c0(void*, void*, Pair_263d40*);
class Obj_263d40 {
    char pad[0x18];
    Pair_263d40 value;

  public:
    void Fn(int a, int b);
};
void Obj_263d40::Fn(int a, int b) {
    Pair_263d40 local;
    local.a = a;
    local.b = b;
    Pair_263d40 result = local;
    if (((int)(hulk_uintptr)FUN_00263970(((int*)&DAT_004cd4cc), (Pair_263d40 *)(&local))))
        result = FUN_00263c90();
    FUN_00263bb0(((int*)&DAT_004cd4cc), this);
    value = result;
    FUN_002639c0(((int*)&DAT_004cd4cc), this, &value);
}
} // namespace fn_00263d40

namespace fn_f551a4d0 {

// 0x00263db0 FUN_00263db0 (58 B): matches/0x00263db0.cpp
// sym: _FUN_00263db0
extern "C" char __cdecl FUN_00263db0(int x, Obj* flag) {
    Pair p;
    if (lookup(x, &p)) {
        if (flag)
            flag->use(p.a, p.b);
        return 1;
    }
    return 0;
}


// 0x00263df0 FUN_00263df0 (53 B): matches/0x00263df0.cpp
// sym: ?FUN_00263df0@fn_f551a4d0@@YAIII@Z
u32_263df0 FUN_00263df0(u32_263df0 a, u32_263df0 b) {
    u32_263df0 key[2];
    key[0] = a;
    key[1] = b;
    Item_263df0* p = ((Item_263df0 *)FUN_00263970(((u32_263df0**)&DAT_004cd4cc), (unsigned int *)key));
    if (p)
        return p->value;
    return 0;
}


// 0x00263e30 FUN_00263e30 (95 B): matches/0x00263e30.cpp
// sym: ?Set@C_263e30@fn_f551a4d0@@QAEXHPA_J@Z
void C_263e30::Set(int a, __int64* p) {
    m10 = a;
    __int64 v = *p;
    __int64 t = v;
    if (((int)(hulk_uintptr)FUN_00263970((char *)(((char*)&DAT_004cd4cc)), (__int64 *)(&t))))
        v = F2();
    m18 = v;
    F3(((char*)&DAT_004cd4cc), this, &m18);
}


// 0x00263e90 FUN_00263e90 (5 B): matches/0x00263e90.cpp
// sym: ?FUN_00263e90@fn_f551a4d0@@YIXPAVA_263e90@1@@Z
void __fastcall FUN_00263e90(A_263e90* p) {
    p->g();
}

// 0x00263ea0 thunk_FUN_0008d690 (5 B): not yet verified
// 0x00263ec0 thunk_FUN_0008d690 (5 B): not yet verified

// 0x00263ed0 FUN_00263ed0 (40 B): matches/0x00263ed0.cpp
// sym: _FUN_00263ed0
extern "C" hulk_uintptr __cdecl FUN_00263ed0(U_263ed0 size, U_263ed0 heap) {
    U_263ed0 a = FUN_00266da0(heap);
    U_263ed0 b = FUN_0008d690(size);
    FUN_00266da0(a);
    return b;
}

} // namespace fn_f551a4d0
