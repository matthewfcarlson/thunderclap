// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00243360..0x00245370 (kind game, layer engine, confidence high), dominant class om::EntityType
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#include "decls/data/game/unknown.h"
#include "gen/audio.h"
#include "gen/om.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7032cca {
#define TREE_TU_END }
namespace fn_f7032cca {} using namespace fn_f7032cca;
namespace fn_f7032cca { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f7032cca {
class Entity {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    char pad[0x20 - 4];
    short count;
    void vfunc_1();
};
extern "C" bool __cdecl Check(const void*, const void*);
extern "C" bool __cdecl FUN_0025abd0(int, int*);
class C_243410 {
  public:
    int value;
    int out;
};
struct RbNode_243760 {
    RbNode_243760* left;
    RbNode_243760* right;
    RbNode_243760* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_243760 {
    RbNode_243760* root;
    RbNode_243760 nil;
};
struct RbNode_243a00 {
    RbNode_243a00* left;
    RbNode_243a00* right;
    RbNode_243a00* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_243a00 {
    RbNode_243a00* root;
    RbNode_243a00 nil;
};
struct RbNode_243d70 {
    RbNode_243d70* left;
    RbNode_243d70* right;
    RbNode_243d70* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_243d70 {
    RbNode_243d70* root;
    RbNode_243d70 nil;
};
struct Range_244080 {
    char pad0[0x30];
    unsigned int lo;
    unsigned int hi;
};
class Bounds_244080 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Range_244080* v8();
    char pad04[0x18 - 4];
    unsigned int lo;
    unsigned int hi;
};
struct Key_244080 {
    unsigned int lo;
    unsigned int hi;
    unsigned int lo2;
    unsigned int hi2;
};
struct Context { char pad[0x24]; int depth; };
struct Handle_244110 { Context* context; };
struct NameSource_244110 { const char* FUN_0023fb00(); };
NameSource_244110* FUN_0024c710();
bool __cdecl FUN_00246f50(Context*, const char*, ...);
struct Properties_244110 { bool FUN_0025b970(Handle_244110*); };
struct Writer_244110 {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual bool write(Handle_244110*);
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void begin();
};
struct Object { Handle_244110* handle; bool FUN_00244110(Writer_244110*, Properties_244110*); };
struct Link {
  public:
    union { Link* left; Link *previous; };
    Link *parent;
    union { Link *next; Link* right; };
};
struct Node {
  public:
    union { Node* a; Node* left; Node* next; };
    union { Node* b; Node* child; Node* parent; };
    union { Node* c; Node* right; Node* sibling; };
    char _m_pad_c[0x3c];
    Link link;
};
struct Tree_2435a0 {
    Node* root;
};
struct Tree_243670 {
    Node* root;
};
struct Tree_243c80 {
    Node* root;
};
struct Boundary { char unknown[4]; Link sentinel; };
struct Collection { char unknown[0x48]; Link header; };
struct Container { int unused; Link header; };
struct Iterator { char unused[8]; Link* link; };
struct Temp_244d10 {
    char x[12];
    void Init_0023fac0();
    unsigned long Get_0023fb00();
};
extern "C" unsigned char __cdecl FUN_0025bce0(int, Temp_244d10*);
} // namespace fn_f7032cca
extern "C" unsigned long long __cdecl FUN_002672f0(unsigned long, int, int);
namespace fn_f7032cca {
extern "C++" __declspec(nothrow) void __cdecl FUN_00244610(void *, void *);
extern void __cdecl FUN_002446d0(void*, void*);
extern void* hulk_at_00429158[];
extern "C++" __declspec(nothrow) void * __cdecl FUN_00244b20(void *, void *);
struct Entity_244f70 {
    void* vf;
    void Dtor() throw();
};
extern "C" int helper(void*, void*);
struct Key_245040 {
    int lo;
    int hi;
};
struct Region_245040 {
    char pad0[0x30];
    int boundsLo;           // 0x30
    int boundsHi;           // 0x34
};
struct Query_245040 {
    int keyLo;
    int keyHi;
    int boundsLo;
    int boundsHi;
};
struct Index;
extern "C++" __declspec(nothrow) void * __cdecl FUN_00244be0(void *, void *);
extern "C++" __declspec(nothrow) bool __cdecl FUN_002448b0(void *, void *, void *);
class Item_245040 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Region_245040 *GetRegion();                    // slot 8
    char pad4[0x14];
    Key_245040 key;                // 0x18

    bool FUN_00245040(const Key_245040 *newKey);
};
struct Clip_nv_245340 {
    void Finish_00244f70();
};
extern "C" void FUN_0025d300(void*);

} // namespace fn_f7032cca

// 0x00243360 om::Entity::vfunc_0 (5 B): matches/0x00243360.cpp
// sym: ?vfunc_0@Entity@om@@UAEXXZ
void om::Entity::vfunc_0() {
    ++this->f_20;
}

namespace fn_f7032cca {

// 0x00243370 om::Entity::vfunc_1 (24 B): matches/0x00243370.cpp
// sym: ?vfunc_1@Entity@fn_f7032cca@@QAEXXZ
void Entity::vfunc_1() {
    if (count == 1) {
        f2(1);
        return;
    }
    --count;
}

} // namespace fn_f7032cca

// 0x00243390 FUN_00243390 (4 B): matches/0x00243390.cpp
// sym: ?FUN_00243390@CFightParamsCollision_243390@owners@@QAEPAU12@XZ
// Same code shape as 0x00059810 (propagated; names are from that function)
owners::CFightParamsCollision_243390* owners::CFightParamsCollision_243390::FUN_00243390() {
    return (owners::CFightParamsCollision_243390*)((char*)this + 0x18);
}

namespace fn_f7032cca {

// 0x002433b0 FUN_002433b0 (71 B): matches/0x002433b0.cpp
// sym: ?Target@fn_f7032cca@@YAHPBXPBD@Z
int __cdecl Target(const void* a, const char* b) {
    if (Check(a, b) && Check(a, b + 4) && Check(a, b + 8))
        return 1;
    return 0;
}


// 0x00243410 FUN_00243410 (106 B): matches/0x00243410.cpp
// sym: ?Target@fn_f7032cca@@YI_NPAVC_243410@1@@Z
bool __fastcall Target(C_243410* self) {
    int a, b, c;
    int x = self->value;
    if (!FUN_0025abd0(x, &a))
        return false;
    if (!FUN_0025abd0(x, &b))
        return false;
    if (!FUN_0025abd0(x, &c))
        return false;
    if (a != 0xff443350)
        return false;
    if (b != 12)
        return false;
    self->out = c - 12;
    return true;
}


// 0x002435a0 FUN_002435a0 (78 B): matches/0x002435a0.cpp
// sym: ?insert@fn_f7032cca@@YAXPAUTree_2435a0@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_2435a0* tree, Node* node) {
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

} // namespace fn_f7032cca

// 0x002435f0 FUN_002435f0 (81 B): matches/0x002435f0.cpp [wrapped: merged class would differ: Tree_2435f0: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_002435f0@@YAXPAUTree_2435f0@1@PAUNode@1@@Z
namespace fn_002435f0 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_2435f0 {
    Node* root;
    Node head;
};
void swap_node(Tree_2435f0* tree, Node* node) {
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
} // namespace fn_002435f0

namespace fn_f7032cca {

// 0x00243670 FUN_00243670 (78 B): matches/0x00243670.cpp
// sym: ?insert@fn_f7032cca@@YAXPAUTree_2435a0@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_243670* tree, Node* node) {
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

} // namespace fn_f7032cca

// 0x002436c0 FUN_002436c0 (81 B): matches/0x002436c0.cpp [wrapped: merged class would differ: Tree_2436c0: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_002436c0@@YAXPAUTree_2436c0@1@PAUNode@1@@Z
namespace fn_002436c0 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_2436c0 {
    Node* root;
    Node head;
};
void swap_node(Tree_2436c0* tree, Node* node) {
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
} // namespace fn_002436c0

namespace fn_f7032cca {

// 0x00243720 FUN_00243720 (55 B): matches/0x00243720.cpp
// sym: ?find@fn_f7032cca@@YAPAUNode@1@PAU21@0@Z
Node* find(Node* root, Node* p) {
    Node* end = (Node*)((char*)&root->b);
    Node* q = p->child;
    if (q != end) {
        while (q->next != end)
            q = q->next;
    } else {
        q = p->sibling;
        while (q != end && p == q->child) {
            p = q;
            q = q->sibling;
        }
    }
    return q;
}


// 0x00243760 FUN_00243760 (604 B): equivalent/0x00243760.cpp
// sym: _FUN_00243760 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00243760 @ 0x00243760
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00243760(void * tree_, void * x_)
{
    RbTree_243760 * tree = (RbTree_243760 *)tree_;
    RbNode_243760 * x = (RbNode_243760 *)x_;
    RbNode_243760* nil = &tree->nil;
    RbNode_243760* y;
    RbNode_243760* z;
    RbNode_243760* p;
    RbNode_243760* c;

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

} // namespace fn_f7032cca

// 0x002439c0 FUN_002439c0 (55 B): matches/0x002439c0.cpp [wrapped: merged class would differ: Tree: field sentinel: Field(+0x4 Node sentinel) vs Field(+0x4 Node sentinel)]
// sym: ?FUN_002439c0@fn_002439c0@@YAPAUNode@1@PAUTree@1@PAU21@@Z
namespace fn_002439c0 {
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char unused[4];
    Node sentinel;
};
Node* __cdecl FUN_002439c0(Tree* tree, Node* node) {
    Node* nil = &tree->sentinel;
    Node* next = node->parent;
    if (next != nil) {
        while (next->left != nil)
            next = next->left;
    } else {
        next = node->right;
        while (next != nil && node == next->parent) {
            node = next;
            next = next->right;
        }
    }
    return next;
}
} // namespace fn_002439c0

namespace fn_f7032cca {

// 0x00243a00 FUN_00243a00 (604 B): equivalent/0x00243a00.cpp
// sym: _FUN_00243a00 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00243a00 @ 0x00243a00
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00243a00(void * tree_, void * x_)
{
    RbTree_243a00 * tree = (RbTree_243a00 *)tree_;
    RbNode_243a00 * x = (RbNode_243a00 *)x_;
    RbNode_243a00* nil = &tree->nil;
    RbNode_243a00* y;
    RbNode_243a00* z;
    RbNode_243a00* p;
    RbNode_243a00* c;

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


// 0x00243c80 FUN_00243c80 (78 B): matches/0x00243c80.cpp
// sym: _FUN_00243c80
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_00243c80(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_243c80 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_243c80 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_243c80 *)tree)) = child;
        child->a = ((Node *)node);
        ((Node *)node)->c = child;
        return;
    }
    if (((Node *)node) == parent->a) {
        parent->a = child;
        child->a = ((Node *)node);
        ((Node *)node)->c = child;
        return;
    }
    parent->b = child;
    child->a = ((Node *)node);
    ((Node *)node)->c = child;
}

} // namespace fn_f7032cca

// 0x00243cd0 FUN_00243cd0 (81 B): matches/0x00243cd0.cpp [wrapped: merged class would differ: Tree_243cd0: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_00243cd0@@YAXPAUTree_243cd0@1@PAUNode@1@@Z
namespace fn_00243cd0 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_243cd0 {
    Node* root;
    Node head;
};
void swap_node(Tree_243cd0* tree, Node* node) {
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
} // namespace fn_00243cd0

namespace fn_f7032cca {

// 0x00243d30 FUN_00243d30 (55 B): matches/0x00243d30.cpp
// sym: ?fn@fn_f7032cca@@YAPAUNode@1@PAU21@0@Z
Node* __cdecl fn(Node* n, Node* sentinel) {
    Node* nil = (Node*)&n->parent;
    Node* x = sentinel->parent;
    if (x != nil) {
        while (x->left != nil) {
            x = x->left;
        }
    } else {
        x = sentinel->right;
        while (x != nil && sentinel == x->parent) {
            sentinel = x;
            x = x->right;
        }
    }
    return x;
}


// 0x00243d70 FUN_00243d70 (604 B): equivalent/0x00243d70.cpp
// sym: ?FUN_00243d70@fn_f7032cca@@YAXPAURbTree_243d70@1@PAURbNode_243d70@1@@Z @394c7c009b90 @wb8331f7a823d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00243d70 @ 0x00243d70
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
void FUN_00243d70(RbTree_243d70* tree, RbNode_243d70* x)
{
    RbNode_243d70* nil = &tree->nil;
    RbNode_243d70* y;
    RbNode_243d70* z;
    RbNode_243d70* p;
    RbNode_243d70* c;

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


// 0x00244080 FUN_00244080 (104 B): equivalent/0x00244080.cpp
// sym: _FUN_00244080 @f9c5375fbdf1 @we03dd05b253e
// STATUS: equivalent (tools/equiv.py level 3: 3072 inputs, branch coverage 20/24, incomplete)
// FUN_00244080 @ 0x00244080
extern "C" int __cdecl FUN_00244080(const void * key, void * bounds_) {
    Bounds_244080 * bounds = (Bounds_244080 *)bounds_;
    if (((const Key_244080 *)key)->hi < bounds->hi)
        return -1;
    if (((const Key_244080 *)key)->hi == bounds->hi && ((const Key_244080 *)key)->lo < bounds->lo)
        return -1;
    if (((const Key_244080 *)key)->hi > bounds->hi)
        return 1;
    if (((const Key_244080 *)key)->lo > bounds->lo)
        return 1;
    Range_244080* r = bounds->v8();
    if (((const Key_244080 *)key)->hi2 > r->hi)
        return 1;
    if (((const Key_244080 *)key)->hi2 < r->hi)
        return -1;
    if (((const Key_244080 *)key)->lo2 < r->lo)
        return -1;
    if (((const Key_244080 *)key)->lo2 > r->lo)
        return 1;
    return 0;
}


// 0x00244110 FUN_00244110 (190 B): equivalent/0x00244110.cpp
// sym: ?FUN_00244110@Object@fn_f7032cca@@QAE_NPAUWriter_244110@2@PAUProperties_244110@2@@Z @64094f4bafc0 @w0e3964e316ec
// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 16/16)
// FUN_00244110 @ 0x00244110
bool Object::FUN_00244110(Writer_244110* writer, Properties_244110* properties) {
 const char* first = FUN_0024c710()->FUN_0023fb00();
 writer->begin();
 const char* second = FUN_0024c710()->FUN_0023fb00();
 bool ok = FUN_00246f50(handle->context, "BeginObject %s \"%s\"\n", second, first);
 if (ok) ++handle->context->depth;
 if (properties) {
  if (!ok) return false;
  if (!FUN_00246f50(handle->context, "Properties:\n")) return false;
  if (!properties->FUN_0025b970(handle)) return false;
 } else if (!ok) return false;
 if (!writer->write(handle)) return false;
 --handle->context->depth;
 return FUN_00246f50(handle->context, "EndObject\n\n") ? true : false;
}

} // namespace fn_f7032cca

// 0x00244230 FUN_00244230 (504 B): equivalent/0x00244230.cpp [wrapped: conflict: Node]
// sym: ?FUN_00244230@fn_00244230@@YA_NPAUTree_244230@1@PAUItem_244230@1@PBUKey_244230@1@@Z @73e692255a6a @wbc48db87ff62
namespace fn_00244230 {
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 51/52, incomplete)
// FUN_00244230 @ 0x00244230
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;  // 0 = black, 1 = red
};

struct Key_244230 {
    unsigned lo;
    unsigned hi;
};

struct Item_244230 {
    char pad0[0x30];
    Key_244230 key;
    char pad38[0x48 - 0x38];
    Node node;
};

struct Tree_244230 {
    Node* root;
    Node nil;
};

void __cdecl FUN_002435a0(Tree_244230* tree, Node* n);  // rotate left
void __cdecl FUN_002435f0(Tree_244230* tree, Node* n);  // rotate right

static inline const Key_244230* KeyOf(const Node* n)
{
    return (const Key_244230*)((const char*)n - 0x18);
}

// Unique insert of item (keyed by a 64-bit key) into an intrusive red-black tree.
bool __cdecl FUN_00244230(Tree_244230* tree, Item_244230* item, const Key_244230* key)
{
    Node* nil = &tree->nil;
    Node* added = &item->node;
    Node* x = tree->root;
    Node* y = nil;

    if (x != nil) {
        unsigned klo = key->lo;
        unsigned khi = key->hi;
        do {
            const Key_244230* nk = KeyOf(x);
            y = x;
            if (khi < nk->hi || (khi == nk->hi && klo < nk->lo)) {
                x = x->left;
            } else {
                if (khi == nk->hi && klo == nk->lo)
                    return false;
                x = x->right;
            }
        } while (x != nil);
    }

    added->parent = y;
    if (y == nil) {
        tree->root = added;
    } else {
        const Key_244230* yk = KeyOf(y);
        if (key->hi > yk->hi || (key->hi == yk->hi && key->lo >= yk->lo))
            y->right = added;
        else
            y->left = added;
    }
    added->left = nil;
    added->right = nil;
    added->color = 1;

    Node* n = added;
    while (n != tree->root && n->parent->color == 1) {
        Node* p = n->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == p->right) {
                    n = p;
                    FUN_002435a0(tree, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                Node* gp = n->parent->parent;
                Node* pivot = gp->left;
                gp->left = pivot->right;
                if (pivot->right != nil)
                    pivot->right->parent = gp;
                pivot->parent = gp->parent;
                if (gp->parent == nil)
                    tree->root = pivot;
                else if (gp == gp->parent->left)
                    gp->parent->left = pivot;
                else
                    gp->parent->right = pivot;
                pivot->right = gp;
                gp->parent = pivot;
            }
        } else {
            Node* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == p->left) {
                    n = p;
                    FUN_002435f0(tree, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                Node* gp = n->parent->parent;
                Node* pivot = gp->right;
                gp->right = pivot->left;
                if (pivot->left != nil)
                    pivot->left->parent = gp;
                pivot->parent = gp->parent;
                if (gp->parent == nil)
                    tree->root = pivot;
                else if (gp == gp->parent->left)
                    gp->parent->left = pivot;
                else
                    gp->parent->right = pivot;
                pivot->left = gp;
                gp->parent = pivot;
            }
        }
    }
    tree->root->color = 0;
    return true;
}
} // namespace fn_00244230


// 0x00244430 FUN_00244430 (470 B): equivalent/0x00244430.cpp [wrapped: conflict: Node]
// sym: _FUN_00244430 @fad261faa7cf @w48b45eb4f3ad
namespace fn_00244430 {
// STATUS: equivalent (tools/equiv.py level 3: 169 inputs, branch coverage 39/40, incomplete)
// FUN_00244430 @ 0x00244430
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    int key;
};

struct Entry_244430 {
    char pad[0x58];
    Node link;
};

struct Tree_244430 {
    Node* root;
    Node nil;
};

extern "C" void FUN_00243670(Tree_244430* tree, Node* node);
extern "C" void FUN_002436c0(Tree_244430* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_00244430(void * tree_, void * entry_, const int* keyPtr)
{
    Tree_244430 * tree = (Tree_244430 *)tree_;
    Entry_244430 * entry = (Entry_244430 *)entry_;
    Node* nil = &tree->nil;
    Node* node = &entry->link;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        int diff = *keyPtr - cur->key;
        parent = cur;
        if (diff < 0) {
            cur = cur->left;
        } else if (diff <= 0) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (*keyPtr - parent->key < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != tree->root && node->parent->color == 1) {
        Node* p = node->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_00243670(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->left;
                gg->left = pv->right;
                if (pv->right != nil)
                    pv->right->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->right = gg;
                gg->parent = pv;
            }
        } else {
            Node* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_002436c0(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->right;
                gg->right = pv->left;
                if (pv->left != nil)
                    pv->left->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->left = gg;
                gg->parent = pv;
            }
        }
    }
    tree->root->color = 0;
    return 1;
}
} // namespace fn_00244430


// 0x00244610 FUN_00244610 (182 B): equivalent/0x00244610.cpp [wrapped: conflict: Node]
// sym: _FUN_00244610 @1e5f4f78f06c @w517b8dd2ffe1
namespace fn_00244610 {
// STATUS: equivalent (tools/equiv.py level 3: 1043 inputs, branch coverage 24/24)
// FUN_00244610 @ 0x00244610
struct Node { Node *left; Node *right; Node *parent; unsigned color; };
struct Tree_244610 { Node *root; Node sentinel; };
struct Object { char padding[0x48]; Node node; };
Node *__cdecl FUN_00243720(Tree_244610 *, Node *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00243760(void *, void *);
extern "C" void __cdecl FUN_00244610(void * tree_, void * object_)
{
    Tree_244610 * tree = (Tree_244610 *)tree_;
    Object * object = (Object *)object_;
    Node *nil = &tree->sentinel;
    Node *removed = &object->node;
    Node *replacement = removed;
    if (removed->left != nil && removed->right != nil)
        replacement = FUN_00243720(tree, removed);
    Node *child = replacement->left;
    if (child == nil)
        child = replacement->right;
    child->parent = replacement->parent;
    Node *parent = replacement->parent;
    if (parent == nil)
        tree->root = child;
    else if (parent->left == replacement)
        parent->left = child;
    else
        parent->right = child;
    bool fix = replacement->color == 0;
    if (replacement != removed) {
        replacement->parent = removed->parent;
        replacement->left = removed->left;
        replacement->right = removed->right;
        replacement->color = removed->color;
        parent = replacement->parent;
        if (parent == nil)
            tree->root = replacement;
        else if (parent->left == removed)
            parent->left = replacement;
        else
            parent->right = replacement;
        if (replacement->left != nil)
            replacement->left->parent = replacement;
        if (replacement->right->parent != nil)
            replacement->right->parent = replacement;
    }
    if (fix)
        FUN_00243760((Tree_244610 *)tree, (Node *)child);
}
} // namespace fn_00244610


// 0x002446d0 FUN_002446d0 (182 B): matches/0x002446d0.cpp [wrapped: conflict: Node]
// sym: ?FUN_002446d0@fn_002446d0@@YAXPAUNode@1@0@Z
namespace fn_002446d0 {
struct Node {
    Node *a, *b, *parent;
    int color;
};
Node* FUN_002439c0(Node*, Node*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00243a00(void *, void *);
void FUN_002446d0(Node* n, Node* tree) {
    Node *s = (Node*)((char*)&n->b), *base = (Node*)((char*)tree + 0x58), *x;
    if (base->a != s && base->b != s)
        x = FUN_002439c0(n, base);
    else
        x = base;
    Node* l = x->a;
    Node* ed;
    if (l != s)
        ed = l;
    else
        ed = x->b;
    ed->parent = x->parent;
    Node* ec = x->parent;
    if (ec == s)
        *(Node**)n = ed;
    else if (x == ec->a)
        ec->a = ed;
    else
        ec->b = ed;
    int flag = x->color == 0;
    if (x != base) {
        x->parent = base->parent;
        x->a = base->a;
        x->b = base->b;
        x->color = base->color;
        ec = x->parent;
        if (ec != s) {
            if (ec->a == base)
                ec->a = x;
            else
                ec->b = x;
        } else
            *(Node**)n = x;
        ec = x->a;
        if (ec != s)
            ec->parent = x;
        ec = x->b;
        if (ec->parent != s)
            ec->parent = x;
    }
    if (flag)
        FUN_00243a00((Node *)n, (Node *)ed);
}
} // namespace fn_002446d0

namespace fn_f7032cca {

// 0x002447c0 FUN_002447c0 (74 B): equivalent/0x002447c0.cpp
// sym: ?FUN_002447c0@fn_f7032cca@@YAPAUNode@1@PAUBoundary@1@PAUCollection@1@@Z @0ef663a46c28 @webc26cfe7249
// STATUS: equivalent (tools/equiv.py level 3: 534 inputs, branch coverage 14/14)
// FUN_002447c0 @ 0x002447c0
Node *__cdecl FUN_002447c0(Boundary *boundary, Collection *collection) { Link *end = &boundary->sentinel; Link *prior = &collection->header; Link *current = prior->parent; if (current != end) { Link *previous = current->previous; while (previous != end) { current = previous; previous = current->previous; } } else { current = prior->next; while (current != end && current->parent == prior) { prior = current; current = current->next; } } if (current == end) return 0; return (Node *)((char *)current - 0x48); }

} // namespace fn_f7032cca

// 0x00244810 FUN_00244810 (82 B): equivalent/0x00244810.cpp [wrapped: conflict: Node]
// sym: ?FUN_00244810@fn_00244810@@YAPAUNode@1@PAUList@1@PBUKey@1@@Z @e93550922d29 @wee7a984be2ce
namespace fn_00244810 {
// STATUS: equivalent (tools/equiv.py level 3: 490 inputs, branch coverage 15/16, incomplete)
// FUN_00244810 @ 0x00244810
struct Link { Link* first; Link* second; };
struct Node { char reserved[0x30]; unsigned low; unsigned high; char reserved2[0x10]; Link link; };
struct List { Link* first; Link sentinel; };
struct Key { unsigned low; unsigned high; };
Node* __cdecl FUN_00244810(List* list, const Key* key)
{
    Link* current = list->first;
    while (current != &list->sentinel) {
        Node* node = (Node*)((char*)current - 0x48);
        if (key->high < node->high || (key->high == node->high && key->low < node->low)) {
            current = current->first;
        } else if (key->high == node->high && key->low == node->low) {
            return node;
        } else {
            current = current->second;
        }
    }
    return 0;
}
} // namespace fn_00244810


// 0x00244870 FUN_00244870 (56 B): matches/0x00244870.cpp [wrapped: conflict: Node]
// sym: _FUN_00244870
namespace fn_00244870 {
struct Node {
    Node* left;
    Node* right;
    int pad[2];
    int key;
};
struct Tree_244870 {
    Node* root;
    Node sentinel;
};
extern "C" int* FUN_00244870(void * tree, int* key) {
    Node* p = ((Tree_244870 *)tree)->root;
    Node* end = (Node*)((char*)&((Tree_244870 *)tree)->sentinel.left);
    while (p != end) {
        int k = *key;
        int d = k - p->key;
        if (d < 0)
            p = p->left;
        else if (d <= 0)
            return (int*)((char*)p - 0x58);
        else
            p = p->right;
    }
    return 0;
}
} // namespace fn_00244870


// 0x002448b0 FUN_002448b0 (609 B): equivalent/0x002448b0.cpp [wrapped: conflict: Node]
// sym: _FUN_002448b0 @746f19e1c0c3 @w25854181b595
namespace fn_002448b0 {
// STATUS: equivalent (tools/equiv.py level 3: 314 inputs, branch coverage 51/64, incomplete)
// FUN_002448b0 @ 0x002448b0
struct Info_2448b0 {
    char pad0[0x30];
    unsigned int lo;
    unsigned int hi;
};

struct Key_2448b0 {
    unsigned int lo;
    unsigned int hi;
    unsigned int lo2;
    unsigned int hi2;
};

struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int color; // 0 = black, 1 = red
    int pad10;
    unsigned int lo;
    unsigned int hi;
};

// Object that embeds a tree node right after its vptr.
struct Obj_2448b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Info_2448b0 *getInfo();
    Node node;
};

struct Tree_2448b0 {
    Node *root;
    Node nil;
};

extern "C++" __declspec(nothrow) int __cdecl FUN_00244080(const void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00243c80(void *, void *);
void __cdecl FUN_00243cd0(Tree_2448b0 *tree, Node *node);

extern "C" bool __cdecl FUN_002448b0(void * tree_, void * obj_, void *key)
{
    Tree_2448b0 * tree = (Tree_2448b0 *)tree_;
    Obj_2448b0 * obj = (Obj_2448b0 *)obj_;
    Node *nil = &tree->nil;
    Node *n = &obj->node;
    Node *cur = tree->root;
    Node *last = nil;
    Node *x;
    Node *p;
    Node *g;
    Node *y;

    while (cur != nil) {
        int c;
        last = cur;
        if (((Key_2448b0 *)key)->hi > cur->hi) {
            c = 1;
        } else if (((Key_2448b0 *)key)->hi < cur->hi) {
            c = -1;
        } else if (((Key_2448b0 *)key)->lo < cur->lo) {
            c = -1;
        } else if (((Key_2448b0 *)key)->lo > cur->lo) {
            c = 1;
        } else {
            Info_2448b0 *info = ((Obj_2448b0 *)((char *)cur - 4))->getInfo();
            if (((Key_2448b0 *)key)->hi2 > info->hi)
                c = 1;
            else if (((Key_2448b0 *)key)->hi2 < info->hi)
                c = -1;
            else if (((Key_2448b0 *)key)->lo2 < info->lo)
                c = -1;
            else if (((Key_2448b0 *)key)->lo2 > info->lo)
                c = 1;
            else
                c = 0;
        }
        if (c < 0)
            cur = cur->left;
        else if (c > 0)
            cur = cur->right;
        else
            return false;
    }

    n->parent = last;
    if (last == nil) {
        tree->root = n;
    } else {
        if (FUN_00244080((Key_2448b0 *)((Key_2448b0 *)key), (Obj_2448b0 *)((Obj_2448b0 *)((char *)last - 4))) < 0)
            last->left = n;
        else
            last->right = n;
    }
    n->left = nil;
    n->right = nil;
    n->color = 1;

    x = n;
    while (x != tree->root && x->parent->color == 1) {
        p = x->parent;
        g = p->parent;
        if (p == g->left) {
            y = g->right;
            if (y->color == 1) {
                p->color = 0;
                y->color = 0;
                g->color = 1;
                x = g;
            } else {
                if (x == p->right) {
                    x = p;
                    FUN_00243c80((Tree_2448b0 *)tree, (Node *)x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                g = x->parent->parent;
                y = g->left;
                g->left = y->right;
                if (y->right != nil)
                    y->right->parent = g;
                y->parent = g->parent;
                if (g->parent == nil)
                    tree->root = y;
                else if (g == g->parent->left)
                    g->parent->left = y;
                else
                    g->parent->right = y;
                y->right = g;
                g->parent = y;
            }
        } else {
            y = g->left;
            if (y->color == 1) {
                p->color = 0;
                y->color = 0;
                g->color = 1;
                x = g;
            } else {
                if (x == p->left) {
                    x = p;
                    FUN_00243cd0(tree, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                g = x->parent->parent;
                y = g->right;
                g->right = y->left;
                if (y->left != nil)
                    y->left->parent = g;
                y->parent = g->parent;
                if (g->parent == nil)
                    tree->root = y;
                else if (g == g->parent->left)
                    g->parent->left = y;
                else
                    g->parent->right = y;
                y->left = g;
                g->parent = y;
            }
        }
    }
    tree->root->color = 0;
    return true;
}
} // namespace fn_002448b0


// 0x00244b20 FUN_00244b20 (182 B): equivalent/0x00244b20.cpp [wrapped: conflict: Node]
// sym: _FUN_00244b20 @db67bc0cf2db @wdc2691924aac
namespace fn_00244b20 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_00244b20 @ 0x00244b20
struct Node { Node* left; Node* right; Node* parent; unsigned color; };
struct Tree_244b20 { Node* root; Node sentinel; };
struct Entry_244b20 { unsigned data; Node links; };
Node* __cdecl FUN_00243d30(Tree_244b20*, Node*);
Node* __cdecl FUN_00243d70(Tree_244b20*, Node*);
extern "C" void * __cdecl FUN_00244b20(void * tree_, void * entry_) {
    Tree_244b20 * tree = (Tree_244b20 *)tree_;
    Entry_244b20 * entry = (Entry_244b20 *)entry_;
 Node* sentinel = &tree->sentinel;
 Node* removed = &entry->links;
 Node* node = removed;
 if (removed->left != sentinel && removed->right != sentinel) node = FUN_00243d30(tree, removed);
 Node* child = node->left;
 if (child == sentinel) child = node->right;
 child->parent = node->parent;
 Node* parent = node->parent;
 if (parent == sentinel) tree->root = child;
 else if (parent->left == node) parent->left = child;
 else parent->right = child;
 bool black = node->color == 0;
 if (node != removed) {
  node->parent = removed->parent;
  node->left = removed->left;
  node->right = removed->right;
  node->color = removed->color;
  parent = node->parent;
  if (parent == sentinel) tree->root = node;
  else if (parent->left == removed) parent->left = node;
  else parent->right = node;
  if (node->left != sentinel) node->left->parent = node;
  if (node->right->parent != sentinel) node->right->parent = node;
 }
 if (black) return (Node *)(FUN_00243d70(tree, child));
 return (Node *)node;
}
} // namespace fn_00244b20


// 0x00244be0 FUN_00244be0 (167 B): equivalent/0x00244be0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_00244be0 @f1907dfe8209 @wf348ca223ae9
namespace fn_00244be0 {
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 28/32, incomplete)
// FUN_00244be0 @ 0x00244be0
struct Key2_244be0 {
    unsigned int lo, hi;
};

struct Node {
    Node *left;                // 0x00
    Node *right;               // 0x04
    char pad08[0x14 - 8];
    Key2_244be0 key;                  // 0x14
};

struct Info_244be0 {
    char pad0[0x30];
    Key2_244be0 key;                  // 0x30
};

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Info_244be0 *v8();
    Node node;                 // 0x04
};

struct Tree_244be0 {
    Node *first;               // 0x00
    Node sentinel;             // 0x04
};

struct Query_244be0 {
    Key2_244be0 primary;              // 0x00
    Key2_244be0 secondary;            // 0x08
};

static int Compare(const Key2_244be0 &a, const Key2_244be0 &b)
{
    if (a.hi < b.hi || (a.hi == b.hi && a.lo < b.lo))
        return -1;
    if (b.hi < a.hi || (b.hi == a.hi && b.lo < a.lo))
        return 1;
    return 0;
}

extern "C" void *__cdecl FUN_00244be0(void * tree_, void *query)
{
    Tree_244be0 * tree = (Tree_244be0 *)tree_;
    Node *end = &tree->sentinel;
    Node *node = tree->first;
    while (node != end) {
        int c = Compare(((Query_244be0 *)query)->primary, node->key);
        Object *obj = (Object *)((char *)node - 4);
        if (c == 0)
            c = Compare(((Query_244be0 *)query)->secondary, obj->v8()->key);
        if (c < 0)
            node = node->left;
        else if (c == 0)
            return (Object *)obj;
        else
            node = node->right;
    }
    return (Object *)0;
}
} // namespace fn_00244be0

namespace fn_f7032cca {

// 0x00244cc0 FUN_00244cc0 (74 B): equivalent/0x00244cc0.cpp
// sym: ?FUN_00244cc0@fn_f7032cca@@YAPAXPAUContainer@1@PAUIterator@1@@Z @e7a09e8c2dcd @wdd47ce1d4469
// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_00244cc0 @ 0x00244cc0
void* __cdecl FUN_00244cc0(Container* container, Iterator* iterator)
{
    Link* const end = &container->header;
    Link* node = reinterpret_cast<Link*>(reinterpret_cast<char*>(iterator) + 4);
    Link* next = iterator->link;
    if (next != end) {
        while (next->left != end)
            next = next->left;
    } else {
        next = node->right;
        while (next != end && node == next->parent) {
            node = next;
            next = next->right;
        }
    }
    return next == end ? 0 : reinterpret_cast<char*>(next) - 4;
}


// 0x00244d10 FUN_00244d10 (86 B): matches/0x00244d10.cpp
// sym: ?Target@fn_f7032cca@@YAEHPAK@Z
unsigned char __cdecl Target(hulk_intptr a, unsigned long* out) {
    Temp_244d10 t;
    t.Init_0023fac0();
    unsigned char r = FUN_0025bce0(a, &t);
    if (out) {
        unsigned long g = t.Get_0023fb00();
        unsigned long long v = FUN_002672f0(g, 0, 0);
        ((unsigned long long*)out)[0] = v;
    }
    ((owners::Str_240060 *)&t)->FUN_00240060();
    return r;
}

} // namespace fn_f7032cca

// 0x00244d70 om::EntityType::vfunc_0 (105 B): equivalent/0x00244d70.cpp [wrapped: conflict: om::EntityType]
// sym: ?vfunc_0@EntityType@om@fn_00244d70@@UAEXXZ @89ed12358803 @wa8bb89d13f45
namespace fn_00244d70 {
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 6/6)
// om::EntityType::vfunc_0 @ 0x00244d70

struct ListNode {
    ListNode *self;
    ListNode *link1;
    ListNode *link2;
    int count;
};

struct ListHead_244d70 {
    ListNode *first;
    ListNode node;
};


namespace om {
class EntityType {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();

    char pad0[0x30 - 4];
    char blockA[0x38];
    char blockB[1];
};
}

void FUN_00244230(ListHead_244d70 *head, om::EntityType *type, void *block);
extern "C++" __declspec(nothrow) char __cdecl FUN_00244430(void *, void *, const int *);

void om::EntityType::vfunc_0()
{
    ListHead_244d70 *a = (*(ListHead_244d70**)&DAT_004cc084);
    ListHead_244d70 *b = (*(ListHead_244d70**)&DAT_004cc088);

    if ((*(int*)&DAT_004e5f10) == 0) {
        if (a) {
            ListNode *n = &a->node;
            n->self = n;
            a->node.link1 = n;
            a->node.link2 = n;
            a->node.count = 0;
            a->first = n;
        }
        if (b) {
            ListNode *n = &b->node;
            n->self = n;
            b->node.link1 = n;
            b->node.link2 = n;
            b->node.count = 0;
            b->first = n;
        }
    }

    FUN_00244230(a, this, blockA);
    FUN_00244430((ListHead_244d70 *)b, (om :: EntityType *)this, (const int *)(void *)blockB);
    (*(int*)&DAT_004e5f10)++;
}
} // namespace fn_00244d70


// 0x00244de0 om::EntityType::vfunc_1 (44 B): matches/0x00244de0.cpp
// sym: ?vfunc_1@EntityType@om@@UAEXXZ
void om::EntityType::vfunc_1() {
    FUN_00244610(*(void**)((hulk_intptr)((char*)&DAT_004cc084)), this);
    FUN_002446d0(*(void**)((hulk_intptr)((char*)&DAT_004cc088)), this);
    int x = *(volatile int*)((hulk_intptr)DAT_004e5f10);
    --x;
    *(volatile int*)((hulk_intptr)DAT_004e5f10) = x;
}


// 0x00244ea0 FUN_00244ea0 (152 B): equivalent/0x00244ea0.cpp [wrapped: conflict: om::Entity]
// sym: ??0Entity@om@fn_00244ea0@@QAE@PAURegion_244ea0@2@@Z @fbc2112f7a99 @we83d317c336e
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00244ea0 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_00244ea0 @ 0x00244ea0
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

struct Region_244ea0 {
    char pad0[0x30];
    int boundsLo;           // 0x30
    int boundsHi;           // 0x34
};

struct Query_244ea0 {
    int keyLo;
    int keyHi;
    int boundsLo;
    int boundsHi;
};

// Spatial index: a sentinel node followed by the tree links.
struct Index_244ea0 {
    Index_244ea0 *root;
    Index_244ea0 *left;
    Index_244ea0 *right;
    Index_244ea0 *parent;
    int color;
};

extern "C++" __declspec(nothrow) bool __cdecl FUN_002448b0(void *, void *, void *);

namespace om {
class Entity {
public:
    virtual void v0_00243360();
    virtual void v1_00243370();
    virtual void* v2_00245270(char);
    virtual void v3() HULK_PURE64;
    virtual bool v4_00244f40(int);
    virtual void v5() HULK_PURE64;
    virtual void v6();
    virtual bool v7_00244f60(void*);
    virtual Region_244ea0 *GetRegion() HULK_PURE64;
    char pad4[0x14];
    unsigned int keyLo;     // 0x18
    unsigned int keyHi;     // 0x1c
    unsigned short s20;
    unsigned short s22;

    Entity(Region_244ea0 *region);
};
}

om::Entity::Entity(Region_244ea0 *region)
{
    unsigned __int64 key = FUN_002672f0("MyEntity", 0, 0);
    keyLo = (unsigned int)key;
    keyHi = (unsigned int)(key >> 32);
    s20 = 0;
    s22 = 0;
    int count = DAT_004e5f0c;
    Index_244ea0 *n = (*(Index_244ea0**)&DAT_004cc08c);
    if (count == 0 && n) {
        Index_244ea0 *sentinel = (Index_244ea0 *)&n->left;
        n->left = sentinel;
        n->right = sentinel;
        n->parent = sentinel;
        n->color = 0;
        n->root = sentinel;
    }
    Query_244ea0 q;
    q.keyLo = keyLo;
    q.keyHi = keyHi;
    q.boundsLo = region->boundsLo;
    q.boundsHi = region->boundsHi;
    FUN_002448b0((Index_244ea0 *)n, this, (Query_244ea0 *)(&q));
    DAT_004e5f0c++;
}
} // namespace fn_00244ea0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00244f40 om::Entity::vfunc_4 (5 B): matches/0x00244f40.cpp
// sym: ?vfunc_4@Entity@om@@UAE_NH@Z
bool om::Entity::vfunc_4(int a) {
    return false;
}

namespace fn_f7032cca {

// 0x00244f50 om::Entity::vfunc_6 (1 B): matches/0x00244f50.cpp
// sym: ?FUN_00244f50@fn_f7032cca@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00244f50() {}

} // namespace fn_f7032cca

// 0x00244f60 om::Entity::vfunc_7 (5 B): matches/0x00244f60.cpp
// sym: ?vfunc_7@Entity@om@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool om::Entity::vfunc_7(void* __p0) {
    return true;
}

namespace fn_f7032cca {

// 0x00244f70 FUN_00244f70 (43 B): matches/0x00244f70.cpp
// sym: ?Dtor@Entity_244f70@fn_f7032cca@@QAEXXZ
void Entity_244f70::Dtor() throw() {
    void* g = (*(void**)&DAT_004cc08c);
    vf = hulk_at_00429158;
    FUN_00244b20(g, this);
    DAT_004e5f0c = DAT_004e5f0c - 1;
    vf = (void**)DAT_003f6098;
}


// 0x00244fa0 FUN_00244fa0 (74 B): matches/0x00244fa0.cpp
// sym: _FUN_00244fa0
// data: g_context = DAT_004cc08c, g_enabled = DAT_004e5f0c
extern "C" hulk_intptr FUN_00244fa0(unsigned int* a, unsigned int* b) {
    if (!DAT_004e5f0c)
        return 0;
    unsigned int local[4];
    local[0] = a[0];
    local[1] = a[1];
    local[2] = b[0];
    local[3] = b[1];
    return helper((*(void**)&DAT_004cc08c), local);
}


// 0x00245040 FUN_00245040 (145 B): equivalent/0x00245040.cpp
// sym: ?FUN_00245040@Item_245040@fn_f7032cca@@QAE_NPBUKey_245040@2@@Z @d51fb71263e8 @wc610e6aec54f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00245040 @ 0x00245040
bool Item_245040::FUN_00245040(const Key_245040 *newKey)
{
    if (newKey->lo == key.lo && newKey->hi == key.hi)
        return true;

    Region_245040 *r = GetRegion();
    Query_245040 q;
    q.keyLo = newKey->lo;
    q.keyHi = newKey->hi;
    q.boundsLo = r->boundsLo;
    q.boundsHi = r->boundsHi;
    if (((int)(hulk_uintptr)FUN_00244be0((Index *)((*(Index**)&DAT_004cc08c)), (Query_245040 *)(&q))))
        return false;

    Index *idx = (*(Index**)&DAT_004cc08c);
    FUN_00244b20((Index *)idx, this);
    key.lo = newKey->lo;
    key.hi = newKey->hi;
    FUN_002448b0((Index *)idx, this, (Query_245040 *)(&q));
    return true;
}

} // namespace fn_f7032cca

// 0x002450e0 FUN_002450e0 (395 B): equivalent/0x002450e0.cpp [wrapped: conflict: FUN_00244fa0]
// sym: ?FUN_002450e0@Source_2450e0@fn_002450e0@@QAEDPAPAVResource_2450e0@2@@Z @cee6ae0c71b5 @wbc2bd609c448
namespace fn_002450e0 {
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 21/22, incomplete)
// FUN_002450e0 @ 0x002450e0

struct Reader;

// C-style interface: the first word of the stream's first word points at a table of functions.
struct IoTable {
    void *slot0;
    void *slot1;
    void *slot2;
    void *slot3;
    char (*read)(IoTable *self, unsigned *out);       // 0x10
    char (*seek)(IoTable *self, unsigned pos);         // 0x14
};
struct IoHandle {
    IoTable *table;
};
struct Stream {
    IoHandle *handle;
};

struct Pair_2450e0 {
    unsigned a;
    unsigned b;
};
struct Header_2450e0 {
    unsigned key;
    unsigned unused;
    unsigned size;
};

class Resource_2450e0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char Load(Stream *s);
    char FUN_00245040(Pair_2450e0 *p);
};
class Entry_2450e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual Resource_2450e0 *Get();
    char pad4[0x2c];
    char data30[1];                                    // 0x30
};
struct Registry;

char __cdecl FUN_002433b0(Stream *s, Header_2450e0 *h);
char __cdecl FUN_00244d10(Stream *s, Pair_2450e0 *p);
extern "C++" __declspec(nothrow) int * __cdecl FUN_00244870(void *, int *);
Resource_2450e0 *__cdecl FUN_00244fa0(Pair_2450e0 *p, char *src);

struct Source_2450e0 {
    Stream *stream;          // 0x00
    unsigned remaining;      // 0x04

    char FUN_002450e0(Resource_2450e0 **out);
};

// The original keeps all its locals in one 0x18-byte frame and reuses the dead argument slot.
struct Frame_2450e0 {
    unsigned base;           // E+0x0c
    Pair_2450e0 pair;               // E+0x10
    Header_2450e0 hdr;              // E+0x18
};

char Source_2450e0::FUN_002450e0(Resource_2450e0 **out)
{
    Frame_2450e0 f;
    *out = 0;
    if (remaining == 0)
        return 1;

    f.base = 0;
    if (!stream->handle->table->read(stream->handle->table, &f.base))
        return 0;

    if (!FUN_002433b0(stream, &f.hdr))
        return 0;

    f.pair.a = 0;
    f.pair.b = 0;
    if (!FUN_00244d10(stream, &f.pair))
        return 0;

    f.hdr.unused = f.hdr.key;
    Entry_2450e0 *entry = ((Entry_2450e0 *)FUN_00244870((Registry *)((*(Registry**)&DAT_004cc088)), (int *)(unsigned *)(&f.hdr.unused)));
    if (entry == 0)
        return 0;

    *out = entry->Get();
    (*out)->AddRef();

    char ok = (*out)->Load(stream);
    if (ok) {
        if (!(*out)->FUN_00245040(&f.pair)) {
            (*out)->Release();
            *out = FUN_00244fa0(&f.pair, entry->data30);
            (*out)->AddRef();
        }
        f.hdr.unused = 0;
        ok = stream->handle->table->read(stream->handle->table, &f.hdr.unused);
        if (ok) {
            unsigned room = f.hdr.unused - f.base;
            unsigned size = f.hdr.size;
            ok = size >= room;
            if (ok) {
                unsigned pos = size + f.base;
                ok = stream->handle->table->seek(stream->handle->table, pos);
                if (ok) {
                    remaining -= f.hdr.size;
                    return ok;
                }
            }
        }
    }
    if (*out) {
        (*out)->Release();
        *out = 0;
    }
    return ok;
}
} // namespace fn_002450e0


// 0x00245270 om::Entity::vfunc_2 (66 B): matches/0x00245270.cpp [wrapped: conflict: om::Entity]
// sym: ?vfunc_2@Entity@om@fn_00245270@@QAEPAV123@E@Z
namespace fn_00245270 {
// data: gCount_245270 = DAT_004e5f0c

extern "C" char DAT_003f6098[];
extern "C" char DAT_00429158[];
namespace om {
class Entity {
  public:
    unsigned long* mVptr;
    Entity* vfunc_2(unsigned char);
};
} // namespace om
extern "C++" __declspec(nothrow) void * __cdecl FUN_00244b20(void *, void *);
void thunk_FUN_00267090(om::Entity*);
om::Entity* om::Entity::vfunc_2(unsigned char param) {
    void* p = (*(void**)&DAT_004cc08c);
    mVptr = (unsigned long*)((hulk_intptr)DAT_00429158);
    FUN_00244b20(p, (om :: Entity *)this);
    --DAT_004e5f0c;
    mVptr = (unsigned long*)((hulk_intptr)DAT_003f6098);
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00245270

namespace fn_f7032cca {

// 0x00245330 FUN_00245330 (6 B): matches/0x00245330.cpp
// sym: _FUN_00245330
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00245330() {
    return &(*(int*)&DAT_004e5f18);
}

} // namespace fn_f7032cca

// 0x00245340 FUN_00245340 (33 B): matches/0x00245340.cpp
// sym: ?FUN_00245340@Clip@audio@@QAEXXZ
void audio::Clip::FUN_00245340() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042918c);
    if ((*(void * *)&this->f_28))
        FUN_0025d300((*(void * *)&this->f_28));
    ((Clip_nv_245340*)this)->Finish_00244f70();
}

