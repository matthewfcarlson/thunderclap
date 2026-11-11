// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00241660..0x00242070 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f58f7e9f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f58f7e9f {} using namespace fn_f58f7e9f;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f58f7e9f {
typedef unsigned int u32_2416c0;
struct Obj_2416c0 {
    char pad0[0x28];
    u32_2416c0 value;
    char pad2[8];
    int state;
};
typedef unsigned int u32_2416f0;
struct Obj_2416f0 {
    char pad[0x34];
    u32_2416f0 field;
};
struct Obj_241700 {
    char pad[0x20];
    float value;
};
struct Node {
  public:
    union { Node* a; Node* left; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_241880 {
    Node* root;
};
struct Tree_2418d0 {
    Node* root;
    Node head;
};
struct Tree {
    char padding[4];
    Node sentinel;
};
struct RbNode_241970 {
    RbNode_241970* left;
    RbNode_241970* right;
    RbNode_241970* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_241970 {
    RbNode_241970* root;
    RbNode_241970 nil;
};
struct Tree_241c00 {
    Node* root;
};
struct Tree_241c50 {
    Node* root;
    Node head;
};
struct RbNode_241cf0 {
    RbNode_241cf0* left;
    RbNode_241cf0* right;
    RbNode_241cf0* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_241cf0 {
    RbNode_241cf0* root;
    RbNode_241cf0 nil;
};
class FUN_00243310 {
  public:
    virtual void f();
    FUN_00243310(const unsigned __int64*, const unsigned __int64*, int, int, int);
};
class MixType_242010 : public FUN_00243310 {
  public:
    MixType_242010();
    virtual void f();
};


// 0x00241660 FUN_00241660 (6 B): matches/0x00241660.cpp
// sym: _FUN_00241660
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00241660() {
    return &(*(int*)&DAT_004e5cf8);
}


// 0x00241670 FUN_00241670 (6 B): matches/0x00241670.cpp
// sym: _FUN_00241670
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e5d68: a static om type (records.h)
extern "C" int* FUN_00241670() {
    return &(*(int*)&DAT_004e5d68);
}


// 0x002416c0 FUN_002416c0 (26 B): matches/0x002416c0.cpp
// sym: _FUN_002416c0
extern "C" void __cdecl FUN_002416c0(hulk_uintptr a, Obj_2416c0* obj, u32_2416c0 value) {
    if (obj->state != 0) {
        obj->state = 3;
        obj->value = value;
    }
}


// 0x002416f0 FUN_002416f0 (8 B): matches/0x002416f0.cpp
// sym: _FUN_002416f0
extern "C" u32_2416f0 FUN_002416f0(void* unused, Obj_2416f0* obj) {
    return obj->field;
}


// 0x00241700 FUN_00241700 (8 B): matches/0x00241700.cpp
// sym: _FUN_00241700
extern "C" float __cdecl FUN_00241700(void*, Obj_241700* p) {
    return p->value;
}


// 0x00241710 FUN_00241710 (8 B): matches/0x00241710.cpp
// sym: _FUN_00241710
extern "C" float FUN_00241710(int a, const void* p) {
    return *(const float*)((const char*)p + 0x24);
}


// 0x00241880 FUN_00241880 (78 B): matches/0x00241880.cpp
// sym: _FUN_00241880
extern "C" void FUN_00241880(Tree_241880* tree, Node* node) {
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


// 0x002418d0 FUN_002418d0 (81 B): matches/0x002418d0.cpp
// sym: _FUN_002418d0
extern "C" void FUN_002418d0(Tree_2418d0* tree, Node* node) {
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


// 0x00241930 FUN_00241930 (55 B): matches/0x00241930.cpp
// sym: _FUN_00241930
extern "C" Node* __cdecl FUN_00241930(Tree* tree, Node* node) {
    Node* end = &tree->sentinel;
    Node* next = node->parent;
    if (next != end) {
        while (next->left != end)
            next = next->left;
        return next;
    }
    next = node->right;
    while (next != end && node == next->parent) {
        node = next;
        next = next->right;
    }
    return next;
}


// 0x00241970 FUN_00241970 (604 B): equivalent/0x00241970.cpp
// sym: _FUN_00241970
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00241970 @ 0x00241970
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00241970(RbTree_241970* tree, RbNode_241970* x)
{
    RbNode_241970* nil = &tree->nil;
    RbNode_241970* y;
    RbNode_241970* z;
    RbNode_241970* p;
    RbNode_241970* c;

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


// 0x00241c00 FUN_00241c00 (78 B): matches/0x00241c00.cpp
// sym: _FUN_00241c00
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_00241c00(Tree_241c00* tree, Node* node) {
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


// 0x00241c50 FUN_00241c50 (81 B): matches/0x00241c50.cpp
// sym: _FUN_00241c50
// Same code shape as 0x002418d0 (propagated; names are from that function)
extern "C" void FUN_00241c50(Tree_241c50* tree, Node* node) {
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

} // namespace fn_f58f7e9f

// 0x00241cb0 FUN_00241cb0 (55 B): matches/0x00241cb0.cpp [wrapped: conflict: Node]
// sym: _FUN_00241cb0
namespace fn_00241cb0 {
struct Node {
    Node* left;
    Node* right;
    Node* parent;
};
extern "C" Node* __cdecl FUN_00241cb0(Node* n, Node* h) {
    Node* end = (Node*)((char*)n + 4);
    Node* p = h->right;
    if (p != end) {
        while (p->left != end)
            p = p->left;
    } else {
        p = h->parent;
        while (p != end && h == p->right) {
            h = p;
            p = p->parent;
        }
    }
    return p;
}
} // namespace fn_00241cb0

namespace fn_f58f7e9f {

// 0x00241cf0 FUN_00241cf0 (604 B): equivalent/0x00241cf0.cpp
// sym: _FUN_00241cf0
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00241cf0 @ 0x00241cf0
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00241cf0(RbTree_241cf0* tree, RbNode_241cf0* x)
{
    RbNode_241cf0* nil = &tree->nil;
    RbNode_241cf0* y;
    RbNode_241cf0* z;
    RbNode_241cf0* p;
    RbNode_241cf0* c;

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


// 0x00242010 FUN_00242010 (92 B): matches/0x00242010.cpp
// sym: ??0MixType_242010@fn_f58f7e9f@@QAE@XZ
// data: mixName = DAT_0042422c, otherName = DAT_004290c4
// The base constructor is om::EntityType's (0x00243310), named by its address for the native links.
MixType_242010::MixType_242010() : FUN_00243310(&(const unsigned __int64&)FUN_002672f0(((char*)&DAT_004290c4), 0, 0), &(const unsigned __int64&)FUN_002672f0(((char*)&DAT_0042422c), 0, 0), 0x1000002, (int)sizeof(AudioMix), 8) { HULK_SIZE32(AudioMix, 0x50); }

} // namespace fn_f58f7e9f
