// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00258140..0x00258b40 (kind game, layer engine, confidence medium), dominant class om::Type
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"
#include "gen/om.h"
#define TREE_TU_BEGIN namespace fn_ff0fd322 {
#define TREE_TU_END }
namespace fn_ff0fd322 {} using namespace fn_ff0fd322;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_ff0fd322 {
struct Node {
  public:
    union { Node* a; Node* left; Node* next; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_258140 {
    Node* root;
};
struct Tree_258190 {
    Node* root;
    Node head;
};
struct Header {
    int pad;
    Node nil;
};
struct RbNode_258230 {
    RbNode_258230* left;
    RbNode_258230* right;
    RbNode_258230* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_258230 {
    RbNode_258230* root;
    RbNode_258230 nil;
};
class Type {
  public:
    virtual void f();
    unsigned int reserved04;
    OmTypeBody body;
    Type(const OmKey* baseKey, const OmKey* key, int size, int align);
};
void __cdecl FUN_00258140(OmTree* tree, OmTreeNode* n);
void __cdecl FUN_00258190(OmTree* tree, OmTreeNode* n);
static inline const OmKey* KeyOf(const OmTreeNode* n)
{
    return &((const OmType*)((const char*)n - (hulk_intptr) & ((OmType*)0)->body.node))->body.key;
}
OmTreeNode* __cdecl FUN_002581f0(OmTree*, OmTreeNode*);
extern "C" void FUN_00258230(void *, void *);
static inline OmType* entry_of(OmTreeNode* n) {
    return (OmType*)((char*)n - (hulk_intptr) & ((OmType*)0)->body.node);
}
bool __cdecl FUN_00258530(OmTree* tree, OmType* item, const OmKey* key);
void __cdecl FUN_00258730(OmTree* tree, OmType* entry);
typedef unsigned int U_258950;
extern "C" OmType* __cdecl FUN_00258870(OmTree* tree, const OmKey* key);


// 0x00258140 FUN_00258140 (78 B): matches/0x00258140.cpp
// sym: ?insert@fn_ff0fd322@@YAXPAUTree_258140@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_258140* tree, Node* node) {
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


// 0x00258190 FUN_00258190 (81 B): matches/0x00258190.cpp
// sym: ?swap_node@fn_ff0fd322@@YAXPAUTree_258190@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_258190* tree, Node* node) {
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


// 0x002581f0 FUN_002581f0 (55 B): matches/0x002581f0.cpp
// sym: ?next@fn_ff0fd322@@YAPAUNode@1@PAUHeader@1@PAU21@@Z
Node* __cdecl next(Header* root, Node* x) {
    Node* nil = &root->nil;
    Node* y = x->parent;
    if (y != nil) {
        if (y->left == nil)
            return y;
        do {
            y = y->left;
        } while (y->left != nil);
        return y;
    }
    y = x->right;
    if (y != nil) {
        while (y != nil && x == y->parent) {
            x = y;
            y = y->right;
        }
    }
    return y;
}


// 0x00258230 FUN_00258230 (604 B): equivalent/0x00258230.cpp
// sym: _FUN_00258230 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00258230 @ 0x00258230
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00258230(void * tree_, void * x_)
{
    RbTree_258230 * tree = (RbTree_258230 *)tree_;
    RbNode_258230 * x = (RbNode_258230 *)x_;
    RbNode_258230* nil = &tree->nil;
    RbNode_258230* y;
    RbNode_258230* z;
    RbNode_258230* p;
    RbNode_258230* c;

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


// 0x002584d0 FUN_002584d0 (55 B): matches/0x002584d0.cpp
// sym: ??0Type@fn_ff0fd322@@QAE@PBUOmKey@@0HH@Z
// om::Type's constructor: the two type keys, an instance's size and alignment (records.h OmType: the class has the
// record's layout on both builds).
Type::Type(const OmKey* baseKey, const OmKey* key, int size, int align) {
    body.baseKey = *baseKey;
    body.key = *key;
    body.size = size;
    body.align = align;
}


// 0x00258530 FUN_00258530 (504 B): equivalent/0x00258530.cpp
// sym: ?FUN_00258530@fn_ff0fd322@@YA_NPAUOmTree@@PAUOmType@@PBUOmKey@@@Z @cddf20613386 @we0fdcac3f421
// STATUS: equivalent (tools/equiv.py level 3: 1132 inputs, branch coverage 51/52, incomplete)
// FUN_00258530 @ 0x00258530
// The tree of om types by key (records.h OmType: the type's node, keyed by its own key; the tree is the OmTree layout,
// 0x004cd1a8's has no count).
// Unique insert of item (keyed by a 64-bit key) into an intrusive red-black tree.
bool __cdecl FUN_00258530(OmTree* tree, OmType* item, const OmKey* key)
{
    OmTreeNode* nil = &tree->nil;
    OmTreeNode* added = &item->body.node;
    OmTreeNode* x = tree->root;
    OmTreeNode* y = nil;

    if (x != nil) {
        unsigned klo = key->lo;
        unsigned khi = key->hi;
        do {
            const OmKey* nk = KeyOf(x);
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
        const OmKey* yk = KeyOf(y);
        if (key->hi > yk->hi || (key->hi == yk->hi && key->lo >= yk->lo))
            y->right = added;
        else
            y->left = added;
    }
    added->left = nil;
    added->right = nil;
    added->color = 1;

    OmTreeNode* n = added;
    while (n != tree->root && n->parent->color == 1) {
        OmTreeNode* p = n->parent;
        OmTreeNode* g = p->parent;
        if (p == g->left) {
            OmTreeNode* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == p->right) {
                    n = p;
                    FUN_00258140(tree, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                OmTreeNode* gp = n->parent->parent;
                OmTreeNode* pivot = gp->left;
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
            OmTreeNode* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == p->left) {
                    n = p;
                    FUN_00258190(tree, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                OmTreeNode* gp = n->parent->parent;
                OmTreeNode* pivot = gp->right;
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


// 0x00258730 FUN_00258730 (182 B): equivalent/0x00258730.cpp
// sym: ?FUN_00258730@fn_ff0fd322@@YAXPAUOmTree@@PAUOmType@@@Z @b7d30cde48e3 @w1ec424f7e1f7
// STATUS: equivalent (tools/equiv.py level 3: 2941 inputs, branch coverage 24/24)
// FUN_00258730 @ 0x00258730
// The tree of om types by key (records.h OmType's node; 0x004cd1a8 is an OmTree without the count).
void __cdecl FUN_00258730(OmTree* tree, OmType* entry) {
 OmTreeNode* sentinel = &tree->nil;
 OmTreeNode* node = &entry->body.node;
 OmTreeNode* removed = node;
 if (node->left != sentinel && node->right != sentinel)
  removed = FUN_002581f0(tree, node);
 OmTreeNode* child = removed->left;
 if (child == sentinel) child = removed->right;
 child->parent = removed->parent;
 OmTreeNode* parent = removed->parent;
 if (parent == sentinel) tree->root = child;
 else if (parent->left == removed) parent->left = child;
 else parent->right = child;
 bool black = removed->color == 0;
 if (removed != node) {
  removed->parent = node->parent;
  removed->left = node->left;
  removed->right = node->right;
  removed->color = node->color;
  parent = removed->parent;
  if (parent == sentinel) tree->root = removed;
  else if (parent->left == node) parent->left = removed;
  else parent->right = removed;
  if (removed->left != sentinel) removed->left->parent = removed;
  if (removed->right->parent != sentinel) removed->right->parent = removed;
 }
 if (black) FUN_00258230(tree, child);
}


// 0x002587f0 FUN_002587f0 (34 B): matches/0x002587f0.cpp
// sym: ?FUN_002587f0@fn_ff0fd322@@YAPAUNode@1@PAU21@@Z
Node* FUN_002587f0(Node* head) {
    Node* end = (Node*)((char*)head + 4);
    if (head->next == end)
        return 0;
    Node* p = head->next;
    while (p->next != end)
        p = p->next;
    return (Node*)((char*)p - 8);
}

} // namespace fn_ff0fd322

// 0x00258820 FUN_00258820 (74 B): equivalent/0x00258820.cpp [wrapped: conflict: Node]
// sym: ?FUN_00258820@fn_00258820@@YAPAUNode@1@PAUTree@1@PAU21@@Z @f391ea3141c6 @wd0235b4445e7
namespace fn_00258820 {
// STATUS: equivalent (tools/equiv.py level 3: 527 inputs, branch coverage 14/14)
// FUN_00258820 @ 0x00258820
struct Link { Link* left; Link* parent; Link* right; };
struct Tree { char padding[4]; Link sentinel; };
struct Node { char padding[8]; Link links; };

Node* __cdecl FUN_00258820(Tree* tree, Node* node)
{
    Link* sentinel = &tree->sentinel;
    Link* current = &node->links;
    Link* result = current->parent;
    if (result != sentinel) {
        while (result->left != sentinel)
            result = result->left;
    } else {
        result = current->right;
        while (result != sentinel && current == result->parent) {
            current = result;
            result = result->right;
        }
    }
    if (result == sentinel)
        return 0;
    return reinterpret_cast<Node*>(reinterpret_cast<char*>(result) - 8);
}
} // namespace fn_00258820

namespace fn_ff0fd322 {

// 0x00258870 FUN_00258870 (82 B): equivalent/0x00258870.cpp
// sym: _FUN_00258870 @2275fff2b4a1 @w77ce938d083e
// STATUS: equivalent (tools/equiv.py level 3: 641 inputs, branch coverage 15/16, incomplete)
// FUN_00258870 @ 0x00258870
// The tree of om types by key: the type with this key, or 0 (records.h OmType: the type's node, keyed by its own key).
extern "C" OmType* __cdecl FUN_00258870(OmTree* tree, const OmKey* key) {
    OmTreeNode* node = tree->root;
    OmTreeNode* end = &tree->nil;
    while (node != end) {
        const OmKey* k = &entry_of(node)->body.key;
        if (key->hi < k->hi || (key->hi == k->hi && key->lo < k->lo)) {
            node = node->left;
        } else if (key->hi == k->hi && key->lo == k->lo) {
            return entry_of(node);
        } else {
            node = node->right;
        }
    }
    return 0;
}

} // namespace fn_ff0fd322

// 0x002588d0 om::Type::vfunc_0 (19 B): matches/0x002588d0.cpp
// sym: ?vfunc_0@Type@om@@UAEXXZ
// data: TypeName = DAT_004cd1a8 (the tree of types by key)
// the tree insert (records.h OmType: the type's node, keyed by its own key)
void om::Type::vfunc_0() {
    FUN_00258530((OmTree*)((char*)&DAT_004cd1a8), (OmType*)this, &((OmType*)this)->body.key);
}


// 0x002588f0 om::Type::vfunc_1 (15 B): matches/0x002588f0.cpp
// sym: ?vfunc_1@Type@om@@UAEXXZ
// the tree remove (records.h OmType: the type's node in the tree of types by key, 0x004cd1a8)
void om::Type::vfunc_1() {
    FUN_00258730((OmTree*)((char*)&DAT_004cd1a8), (OmType*)this);
}

namespace fn_ff0fd322 {

// 0x00258950 FUN_00258950 (19 B): matches/0x00258950.cpp
// sym: ?FUN_00258950@fn_ff0fd322@@YAHI@Z
// the om type with this key (the tree of types by key, 0x004cd1a8; records.h OmType)
int __cdecl FUN_00258950(U_258950 key) {
    return ((int)(hulk_uintptr)FUN_00258870((OmTree*)((char*)&DAT_004cd1a8), (const OmKey*)(hulk_uintptr)(unsigned int)key));
}

} // namespace fn_ff0fd322
