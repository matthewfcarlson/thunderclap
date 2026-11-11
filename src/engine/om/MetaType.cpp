// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0025e900..0x0025fca0 (kind game, layer engine, confidence high), dominant class om::MetaType
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f98b1434 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f98b1434 {} using namespace fn_f98b1434;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f98b1434 {
struct Node {
  public:
    union { Node* a; Node* left; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
    char _m_pad_c[0x8];
    char item[0x1c];
    Node* next;
    void FUN_0025fad0(hulk_intptr value);
};
struct Tree_25e900 {
    Node* root;
};
struct RbNode_25e9f0 {
    RbNode_25e9f0* left;
    RbNode_25e9f0* right;
    RbNode_25e9f0* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_25e9f0 {
    RbNode_25e9f0* root;
    RbNode_25e9f0 nil;
};
struct Tree_25ec50 {
    Node* root;
};
struct RbNode_25ed40 {
    RbNode_25ed40* left;
    RbNode_25ed40* right;
    RbNode_25ed40* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_25ed40 {
    RbNode_25ed40* root;
    RbNode_25ed40 nil;
};
struct Link {
  public:
    union { Link *left; Link *next; };
    union { Link *owner; Link *parent; };
    union { Link *right; Link *up; };
};
struct Head { int unused; Link sentinel; };
struct Range { int unused; Link sentinel; };
struct Link_25f080 {
    Link_25f080* left;
    Link_25f080* right;
    char pad08[0x20];
    const char* key;      // 0x28
};
struct Entry_25f080 {
    int header;
    Link_25f080 link;            // tree links start at +4
};
struct Tree_25f080 {
    Link_25f080* root;
    Link_25f080 end;             // sentinel at +4
};
struct Key_25f080 { const char* text; };
struct Entry { int value; Link links; };
struct Iterator { char pad[4]; Link links; };
static inline const char *key_of(OmTreeNode *n)
{
    return ((OmMetaType *)((char *)n - (hulk_intptr)&((OmMetaType *)0)->node))->name;
}
void __cdecl FUN_0025e900(OmTree *t, OmTreeNode *n);
void __cdecl FUN_0025e950(OmTree *t, OmTreeNode *n);
struct Output_25f7e0 { char pad[0x24]; unsigned depth; };
bool __cdecl FUN_00246f50(Output_25f7e0*, const char*, ...);
namespace om {
struct Link_25f7e0 { Link_25f7e0* left; Link_25f7e0* right; Link_25f7e0* parent; };
}
namespace om {
class MetaType {
  public:
    virtual MetaType* vfunc_0(unsigned char);
    virtual bool vfunc_1(Output_25f7e0** out, void* context);
    virtual void _m_vf2();
    Link_25f7e0 links;
    char _m_pad_10[0x4];
    Link_25f7e0* root;
    Link_25f7e0 sentinel;
};
}
extern "C" char DAT_0042aa40[];
struct MetaTypeTree_25fa00 {
    static bool FUN_0025f170(OmTree*, OmMetaType*, const char**);
};
struct MetaType : OmMetaType {
    MetaType* FUN_0025fa00(const char*, int);
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0025f390(void *, void *);
struct MetaType_25fa80 : OmMetaType {
    void run();
};
extern "C++" __declspec(nothrow) void * __cdecl FUN_0025f670(void *, const char **);
extern "C" char DAT_00429420[];
typedef unsigned int U_25fba0;
struct MetaTypeAttribBase {
    void* vptr;
    char pad[0x10];
    U_25fba0 a;
    U_25fba0 b;
    MetaTypeAttribBase* init(void*, hulk_uintptr, hulk_uintptr);
};
extern "C++" __declspec(nothrow) bool __cdecl FUN_0025f450(void *, void *, const char **);
extern "C" void FUN_00247550(void* p, om::MetaType* self);
typedef unsigned int u32_25fc80;
extern "C++" __declspec(nothrow) void __cdecl FUN_0025fbe0(void *);
struct Obj_25fc80 {
    char pad[0x14];
};


// 0x0025e900 FUN_0025e900 (78 B): matches/0x0025e900.cpp
// sym: ?insert@fn_f98b1434@@YAXPAUTree_25e900@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_25e900* tree, Node* node) {
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

} // namespace fn_f98b1434

// 0x0025e950 FUN_0025e950 (81 B): matches/0x0025e950.cpp [wrapped: merged class would differ: Tree_25e950: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_0025e950@@YAXPAUTree_25e950@1@PAUNode@1@@Z
namespace fn_0025e950 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_25e950 {
    Node* root;
    Node head;
};
void swap_node(Tree_25e950* tree, Node* node) {
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
} // namespace fn_0025e950

namespace fn_f98b1434 {

// 0x0025e9b0 FUN_0025e9b0 (55 B): matches/0x0025e9b0.cpp
// sym: _FUN_0025e9b0
extern "C" Node* __cdecl FUN_0025e9b0(Node* x, Node* head) {
    Node* nil = (Node*)((char*)x + 4);
    Node* y = head->parent;
    if (y != nil) {
        while (y->left != nil)
            y = y->left;
        return y;
    }
    y = head->right;
    if (y != nil) {
        do {
            if (head != y->parent)
                break;
            head = y;
            y = y->right;
        } while (y != nil);
    }
    return y;
}


// 0x0025e9f0 FUN_0025e9f0 (604 B): equivalent/0x0025e9f0.cpp
// sym: _FUN_0025e9f0 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_0025e9f0 @ 0x0025e9f0
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_0025e9f0(void * tree_, void * x_)
{
    RbTree_25e9f0 * tree = (RbTree_25e9f0 *)tree_;
    RbNode_25e9f0 * x = (RbNode_25e9f0 *)x_;
    RbNode_25e9f0* nil = &tree->nil;
    RbNode_25e9f0* y;
    RbNode_25e9f0* z;
    RbNode_25e9f0* p;
    RbNode_25e9f0* c;

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


// 0x0025ec50 FUN_0025ec50 (78 B): matches/0x0025ec50.cpp
// sym: _FUN_0025ec50
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_0025ec50(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_25ec50 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_25ec50 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_25ec50 *)tree)) = child;
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

} // namespace fn_f98b1434

// 0x0025eca0 FUN_0025eca0 (81 B): matches/0x0025eca0.cpp [wrapped: merged class would differ: Tree_25eca0: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_0025eca0@@YAXPAUTree_25eca0@1@PAUNode@1@@Z
namespace fn_0025eca0 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_25eca0 {
    Node* root;
    Node head;
};
void swap_node(Tree_25eca0* tree, Node* node) {
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
} // namespace fn_0025eca0

namespace fn_f98b1434 {

// 0x0025ed00 FUN_0025ed00 (55 B): matches/0x0025ed00.cpp
// sym: ?f@fn_f98b1434@@YAPAUNode@1@PAU21@0@Z
Node* __cdecl f(Node* head, Node* x) {
    Node* sentinel = (Node*)((char*)head + 4);
    Node* y = x->parent;
    if (y != sentinel) {
        while (y->left != sentinel)
            y = y->left;
        return y;
    }
    y = x->right;
    while (y != sentinel && x == y->parent) {
        x = y;
        y = y->right;
    }
    return y;
}


// 0x0025ed40 FUN_0025ed40 (604 B): equivalent/0x0025ed40.cpp
// sym: _FUN_0025ed40 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_0025ed40 @ 0x0025ed40
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_0025ed40(void * tree_, void * x_)
{
    RbTree_25ed40 * tree = (RbTree_25ed40 *)tree_;
    RbNode_25ed40 * x = (RbNode_25ed40 *)x_;
    RbNode_25ed40* nil = &tree->nil;
    RbNode_25ed40* y;
    RbNode_25ed40* z;
    RbNode_25ed40* p;
    RbNode_25ed40* c;

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


// 0x0025f030 FUN_0025f030 (74 B): equivalent/0x0025f030.cpp
// sym: ?FUN_0025f030@fn_f98b1434@@YAPAXPAUHead@1@PAURange@1@@Z @423c22cef9ca @w7915036d4138
// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_0025f030 @ 0x0025f030
void * __cdecl FUN_0025f030(Head *head, Range *range)
{
    Link *stop = &head->sentinel;
    Link *node = range->sentinel.owner;
    if (node != stop) {
        while (node->next != stop)
            node = node->next;
    } else {
        node = range->sentinel.up;
        while (node != stop && node->owner == &range->sentinel)
            node = node->up;
    }
    return node == stop ? 0 : (char *)node - 4;
}


// 0x0025f080 FUN_0025f080 (105 B): equivalent/0x0025f080.cpp
// sym: ?FUN_0025f080@fn_f98b1434@@YAPAUEntry_25f080@1@PAUTree_25f080@1@PAUKey_25f080@1@@Z @1e8822d436d4 @w1f653c587ce5
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 15/16, incomplete)
// FUN_0025f080 @ 0x0025f080
// Looks a name up in a string-keyed ordered map; returns the entry or null.
Entry_25f080* FUN_0025f080(Tree_25f080* tree, Key_25f080* name)
{
    Link_25f080* node = tree->root;
    Link_25f080* end = &tree->end;
    if (node == end)
        return 0;
    const char* text = name->text;
    do {
        const char* a = text;
        const char* b = node->key;
        int cmp;
        for (;;) {
            unsigned char ca = *a;
            unsigned char cb = *b;
            if (ca != cb) {
                cmp = ca < cb ? -1 : 1;
                break;
            }
            if (ca == 0) {
                cmp = 0;
                break;
            }
            a++;
            b++;
        }
        if (cmp < 0)
            node = node->left;
        else if (cmp > 0)
            node = node->right;
        else
            return reinterpret_cast<Entry_25f080*>(reinterpret_cast<char*>(node) - 4);
    } while (node != end);
    return 0;
}


// 0x0025f120 FUN_0025f120 (74 B): equivalent/0x0025f120.cpp
// sym: ?FUN_0025f120@fn_f98b1434@@YAPAUEntry@1@PAU21@PAUIterator@1@@Z @dab976b38ac3 @wa66716d02a3e
// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_0025f120 @ 0x0025f120
Entry* __cdecl FUN_0025f120(Entry *end, Iterator *it)
{
    Link *sentinel = &end->links;
    Link *node = it->links.parent;
    if (node != sentinel) {
        while (node->left != sentinel)
            node = node->left;
    } else {
        Link *previous = &it->links;
        node = it->links.right;
        if (node != sentinel) {
            while (node->parent == previous) {
                previous = node;
                node = node->right;
                if (node == sentinel)
                    break;
            }
        }
    }
    if (node == sentinel)
        return 0;
    return reinterpret_cast<Entry*>(reinterpret_cast<char*>(node) - 4);
}


// 0x0025f170 FUN_0025f170 (530 B): equivalent/0x0025f170.cpp
// sym: ?FUN_0025f170@fn_f98b1434@@YA_NPAUOmTree@@PAUOmMetaType@@PAPBD@Z @76e6b2efd79e @w27ee6be65869
// STATUS: equivalent (tools/equiv.py level 3: 822 inputs, branch coverage 54/56, incomplete)
// FUN_0025f170 @ 0x0025f170
bool FUN_0025f170(OmTree *t, OmMetaType *item, const char **pkey)
{
    OmTreeNode *z = &item->node;
    OmTreeNode *y = &t->nil;
    OmTreeNode *x = t->root;
    if (x != &t->nil) {
        const char *key = *pkey;
        do {
            y = x;
            int c = strcmp(key, key_of(x));
            if (c < 0)
                x = x->left;
            else if (c == 0)
                return false;
            else
                x = x->right;
        } while (x != &t->nil);
    }
    z->parent = y;
    if (y == &t->nil) {
        t->root = z;
    } else {
        if (strcmp(*pkey, key_of(y)) < 0)
            y->left = z;
        else
            y->right = z;
    }
    z->left = &t->nil;
    z->right = &t->nil;
    z->color = 1;

    while (z != t->root) {
        OmTreeNode *p = z->parent;
        if (p->color != 1)
            break;
        OmTreeNode *g = p->parent;
        OmTreeNode *u;
        if (p == g->left) {
            u = g->right;
            if (u->color != 1) {
                if (z == p->right) {
                    z = p;
                    FUN_0025e900(t, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                OmTreeNode *gp = z->parent->parent;
                OmTreeNode *pp = gp->left;
                gp->left = pp->right;
                if (pp->right != &t->nil)
                    pp->right->parent = gp;
                pp->parent = gp->parent;
                OmTreeNode *ggp = gp->parent;
                if (ggp == &t->nil) {
                    t->root = pp;
                    pp->right = gp;
                } else if (gp == ggp->left) {
                    ggp->left = pp;
                    pp->right = gp;
                } else {
                    ggp->right = pp;
                    pp->right = gp;
                }
                gp->parent = pp;
                        continue;
            }
        } else {
            u = g->left;
            if (u->color != 1) {
                if (z == p->left) {
                    z = p;
                    FUN_0025e950(t, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                OmTreeNode *gp = z->parent->parent;
                OmTreeNode *pp = gp->right;
                gp->right = pp->left;
                if (pp->left != &t->nil)
                    pp->left->parent = gp;
                pp->parent = gp->parent;
                OmTreeNode *ggp = gp->parent;
                if (ggp == &t->nil)
                    t->root = pp;
                else if (gp == ggp->left)
                    ggp->left = pp;
                else
                    ggp->right = pp;
                pp->left = gp;
                gp->parent = pp;
                        continue;
            }
        }
        z->parent->color = 0;
        u->color = 0;
        z->parent->parent->color = 1;
        z = z->parent->parent;
    }
    t->root->color = 0;
    return true;
}

} // namespace fn_f98b1434

// 0x0025f390 FUN_0025f390 (182 B): equivalent/0x0025f390.cpp [wrapped: conflict: FUN_0025e9b0; Node]
// sym: _FUN_0025f390 @2e9ac7a2dde4 @w0d5af692a892
namespace fn_0025f390 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0025f390 @ 0x0025f390
struct Node { Node* left; Node* right; Node* parent; int color; };
struct Tree_25f390 { Node* root; Node sentinel; };
struct Entry_25f390 { int value; Node node; };
Node* __cdecl FUN_0025e9b0(Tree_25f390*, Node*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025e9f0(void *, void *);
extern "C" void __cdecl FUN_0025f390(void * tree_, void * entry_) {
    Tree_25f390 * tree = (Tree_25f390 *)tree_;
    Entry_25f390 * entry = (Entry_25f390 *)entry_;
    Node* target = &entry->node;
    Node* nil = &tree->sentinel;
    Node* removed;
    if (target->left == nil || target->right == nil) removed = target;
    else removed = FUN_0025e9b0(tree, target);
    Node* child = removed->left;
    if (child == nil) child = removed->right;
    child->parent = removed->parent;
    Node* parent = removed->parent;
    if (parent == nil) tree->root = child;
    else if (parent->left == removed) parent->left = child;
    else parent->right = child;
    bool black = removed->color == 0;
    if (removed != target) {
        removed->parent = target->parent;
        removed->left = target->left;
        removed->right = target->right;
        removed->color = target->color;
        parent = removed->parent;
        if (parent == nil) tree->root = removed;
        else if (parent->left == target) parent->left = removed;
        else parent->right = removed;
        Node* left = removed->left;
        if (left != nil) left->parent = removed;
        Node* right = removed->right;
        if (right->parent != nil) right->parent = removed;
    }
    if (black) FUN_0025e9f0((Tree_25f390 *)tree, (Node *)child);
}
} // namespace fn_0025f390


// 0x0025f450 FUN_0025f450 (530 B): equivalent/0x0025f450.cpp [wrapped: conflict: Node]
// sym: _FUN_0025f450 @5558e777f593 @w27c879a6ae1e
namespace fn_0025f450 {
// STATUS: equivalent (tools/equiv.py level 3: 2578 inputs, branch coverage 55/56, incomplete)
// FUN_0025f450 @ 0x0025f450

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strcmp(const char *a, const char *b);
#endif


struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int color;
    char pad10[4];
    const char *key;
};

struct Item {
    void *vptr;
    Node node;
};

struct Tree {
    Node *root;
    Node nil;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_0025ec50(void *, void *);
void __cdecl FUN_0025eca0(Tree *t, Node *n);

extern "C" bool FUN_0025f450(void * t_, void * item_, const char **pkey)
{
    Tree * t = (Tree *)t_;
    Item * item = (Item *)item_;
    Node *z = &item->node;
    Node *y = &t->nil;
    Node *x = t->root;
    if (x != &t->nil) {
        const char *key = *pkey;
        do {
            y = x;
            int c = strcmp(key, x->key);
            if (c < 0)
                x = x->left;
            else if (c == 0)
                return false;
            else
                x = x->right;
        } while (x != &t->nil);
    }
    z->parent = y;
    if (y == &t->nil) {
        t->root = z;
    } else {
        if (strcmp(*pkey, y->key) < 0)
            y->left = z;
        else
            y->right = z;
    }
    z->left = &t->nil;
    z->right = &t->nil;
    z->color = 1;

    while (z != t->root) {
        Node *p = z->parent;
        if (p->color != 1)
            break;
        Node *g = p->parent;
        Node *u;
        if (p == g->left) {
            u = g->right;
            if (u->color != 1) {
                if (z == p->right) {
                    z = p;
                    FUN_0025ec50((Tree *)t, (Node *)z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                Node *gp = z->parent->parent;
                Node *pp = gp->left;
                gp->left = pp->right;
                if (pp->right != &t->nil)
                    pp->right->parent = gp;
                pp->parent = gp->parent;
                Node *ggp = gp->parent;
                if (ggp == &t->nil) {
                    t->root = pp;
                    pp->right = gp;
                } else if (gp == ggp->left) {
                    ggp->left = pp;
                    pp->right = gp;
                } else {
                    ggp->right = pp;
                    pp->right = gp;
                }
                gp->parent = pp;
                        continue;
            }
        } else {
            u = g->left;
            if (u->color != 1) {
                if (z == p->left) {
                    z = p;
                    FUN_0025eca0(t, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                Node *gp = z->parent->parent;
                Node *pp = gp->right;
                gp->right = pp->left;
                if (pp->left != &t->nil)
                    pp->left->parent = gp;
                pp->parent = gp->parent;
                Node *ggp = gp->parent;
                if (ggp == &t->nil)
                    t->root = pp;
                else if (gp == ggp->left)
                    ggp->left = pp;
                else
                    ggp->right = pp;
                pp->left = gp;
                gp->parent = pp;
                        continue;
            }
        }
        z->parent->color = 0;
        u->color = 0;
        z->parent->parent->color = 1;
        z = z->parent->parent;
    }
    t->root->color = 0;
    return true;
}
} // namespace fn_0025f450


// 0x0025f670 FUN_0025f670 (105 B): matches/0x0025f670.cpp [wrapped: conflict: Node]
// sym: _FUN_0025f670
namespace fn_0025f670 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char*, const char*);
#endif

struct Node {
    Node* left;
    Node* right;
    int pad[3];
    const char* key;
};
struct Tree_25f670 {
    Node* root;
};
extern "C" void * FUN_0025f670(void * t, const char** key) {
    Node* n = ((Tree_25f670 *)t)->root;
    Node* end = (Node*)((char*)((Tree_25f670 *)t) + 4);
    while (n != end) {
        int c = strcmp(*key, n->key);
        if (c < 0)
            n = n->left;
        else if (c <= 0)
            return (Node *)((Node*)((char*)n - 4));
        else
            n = n->right;
    }
    return (Node *)0;
}
} // namespace fn_0025f670


// 0x0025f6e0 FUN_0025f6e0 (182 B): equivalent/0x0025f6e0.cpp [wrapped: conflict: Node]
// sym: _FUN_0025f6e0 @d8448d83e17b @we0a563299998
namespace fn_0025f6e0 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0025f6e0 @ 0x0025f6e0
struct Node { Node* left; Node* right; Node* parent; unsigned color; };
struct Tree_25f6e0 { Node* root; Node sentinel; };
struct Entry_25f6e0 { unsigned data; Node node; };
extern Node* __cdecl FUN_0025ed00(Tree_25f6e0*,Node*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025ed40(void *, void *);
extern "C" void __cdecl FUN_0025f6e0(void * tree_, void * entry_) {
    Tree_25f6e0 * tree = (Tree_25f6e0 *)tree_;
    Entry_25f6e0 * entry = (Entry_25f6e0 *)entry_;
 Node* z=&entry->node; Node* nil=&tree->sentinel;
 Node* y;
 if(z->left!=nil && z->right!=nil) y=FUN_0025ed00(tree,z); else y=z;
 Node* x=y->left;
 if(x==nil) x=y->right;
 x->parent=y->parent;
 Node* p=y->parent;
 if(p==nil) tree->root=x;
 else if(p->left==y) p->left=x;
 else p->right=x;
 bool black=y->color==0;
 if(y!=z) {
 y->parent=z->parent;
 y->left=z->left;
 y->right=z->right;
 y->color=z->color;
 p=y->parent;
 if(p==nil) tree->root=y;
 else if(p->left==z) p->left=y;
 else p->right=y;
 if(y->left!=nil) y->left->parent=y;
 if(y->right->parent!=nil) y->right->parent=y;
 }
 if(black) FUN_0025ed40((Tree_25f6e0 *)tree,(Node *)x);
}
} // namespace fn_0025f6e0

namespace fn_f98b1434 {

// 0x0025f7e0 om::MetaType::vfunc_1 (272 B): equivalent/0x0025f7e0.cpp
// sym: ?vfunc_1@MetaType@om@fn_f98b1434@@UAE_NPAPAUOutput_25f7e0@3@PAX@Z @1cfe7347851e @w0d43788b2cd1
// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 30/34, incomplete)
// om::MetaType::vfunc_1 @ 0x0025f7e0
bool om::MetaType::vfunc_1(Output_25f7e0** out, void* context) {
 Link_25f7e0* end = &sentinel;
 Link_25f7e0* node = root;
 MetaType* item = 0;
 if (node != end) {
  while (node->left != end) node = node->left;
  item = reinterpret_cast<MetaType*>(reinterpret_cast<char*>(node)-4);
 }
 if (!FUN_00246f50(*out, "[\n")) return false;
 ++(*out)->depth;
 while (item) {
  if (!FUN_00246f50(*out, "%s ", item->sentinel.left)) return false;
  if (!item->vfunc_1(out, context)) return false;
  if (!FUN_00246f50(*out, "\n")) return false;
  Link_25f7e0* current = &item->links;
  Link_25f7e0* next = current->right;
  if (next != end) {
   while (next->left != end) next = next->left;
  } else {
   next = current->parent;
   while (next != end && current == next->right) {
    current = next;
    next = next->parent;
   }
  }
  item = next == end ? 0 : reinterpret_cast<MetaType*>(reinterpret_cast<char*>(next)-4);
 }
 --(*out)->depth;
 return FUN_00246f50(*out, "\n]\n") != 0;
}

} // namespace fn_f98b1434

// 0x0025f8f0 om::MetaType::vfunc_2 (151 B): equivalent/0x0025f8f0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_2@MetaType@om@fn_0025f8f0@@UAE_NHH@Z @274ab731bbd6 @w960d3327d992
namespace fn_0025f8f0 {
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 26/26)
// om::MetaType::vfunc_2 @ 0x0025f8f0
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

class Item_25f8f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual bool Visit(int a, int b);
    Node node;          // 4
};

namespace om {

class MetaType {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual bool vfunc_2(int a, int b);
    char pad04[0x10];
    Node *root;         // 0x14
    Node nil;           // 0x18
};

static Item_25f8f0 *ItemOf(Node *n, Node *nil)
{
    return n == nil ? 0 : (Item_25f8f0 *)((char *)n - 4);
}

bool MetaType::vfunc_2(int a, int b)
{
    // in-order walk over the item tree
    Node *n = root;
    Item_25f8f0 *it;
    if (n == &nil) {
        it = 0;
    } else {
        while (n->left != &nil)
            n = n->left;
        it = (Item_25f8f0 *)((char *)n - 4);
    }
    while (it != 0) {
        if (!it->Visit(a, b))
            return false;
        Node *cur = &it->node;
        Node *next = cur->right;
        if (next != &nil) {
            while (next->left != &nil)
                next = next->left;
        } else {
            Node *p = cur->parent;
            while (p != &nil && cur == p->right) {
                cur = p;
                p = p->parent;
            }
            next = p;
        }
        it = ItemOf(next, &nil);
    }
    return true;
}

}
} // namespace fn_0025f8f0

namespace fn_f98b1434 {

// 0x0025fa00 FUN_0025fa00 (121 B): matches/0x0025fa00.cpp
// sym: ?FUN_0025fa00@MetaType@fn_f98b1434@@QAEPAU12@PBDH@Z
// om::MetaType's constructor: the vftable, an empty tree of its own, the key (the name), then the insertion into the
// tree of meta types (0x004e79b8, set up on the first construction; 0x004cd360 points at it). records.h's OmMetaType.
MetaType* MetaType::FUN_0025fa00(const char* n, int f) {
    OmTreeNode* nil = &children.nil;
    vftable = DAT_0042aa40;
    nil->left = nil;
    children.nil.right = nil;
    children.nil.parent = nil;
    children.root = nil;
    children.nil.color = 0;
    const char** k = &name;
    *k = n;
    flags = f;
    if (DAT_004e79b8.count == 0) {
        DAT_004e79b8.nil.left = &DAT_004e79b8.nil;
        DAT_004e79b8.nil.right = &DAT_004e79b8.nil;
        DAT_004e79b8.nil.parent = &DAT_004e79b8.nil;
        DAT_004e79b8.nil.color = 0;
        DAT_004e79b8.root = &DAT_004e79b8.nil;
    }
    MetaTypeTree_25fa00::FUN_0025f170((OmTree*)DAT_004cd360, this, k);
    ++DAT_004e79b8.count;
    return this;
}


// 0x0025fa80 FUN_0025fa80 (33 B): matches/0x0025fa80.cpp
// sym: ?run@MetaType_25fa80@fn_f98b1434@@QAEXXZ
// om::MetaType_25fa80's destructor body: the vftable, the removal from the tree of meta types (0x004e79b8, records.h).
void MetaType_25fa80::run() {
    void* p = (*(void**)&DAT_004cd360);
    vftable = DAT_0042aa40;
    FUN_0025f390(p, this);
    --DAT_004e79b8.count;
}


// 0x0025fad0 FUN_0025fad0 (41 B): equivalent/0x0025fad0.cpp
// sym: ?FUN_0025fad0@Node@fn_f98b1434@@QAEXH@Z @53a0ca6f3a57 @wc0cc8deb21db
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0025fad0 @ 0x0025fad0
void Node::FUN_0025fad0(hulk_intptr value) {
    if (((int)(hulk_uintptr)FUN_0025f670(&item, (const char **)(&value)))) return;
    Node* n = next;
    if (n) {
        void (Node::* volatile recurse)(hulk_intptr) = &Node::FUN_0025fad0;
        (n->*recurse)(value);
    }
}

} // namespace fn_f98b1434

// 0x0025fb00 FUN_0025fb00 (148 B): equivalent/0x0025fb00.cpp [wrapped: conflict: Node]
// sym: ?FUN_0025fb00@ItemTree@fn_0025fb00@@QAEXH@Z @c6fa7f2a9d26 @wdf733bd81054
namespace fn_0025fb00 {
// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 26/26)
// FUN_0025fb00 @ 0x0025fb00
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

class Item_25fb00 {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(int arg);
    Node node;
};

class ItemTree {
public:
    void FUN_0025fb00(hulk_intptr arg);

    char pad0[0x14];
    Node *root;
    Node nil;
    char pad1[0x30 - 0x24];
    ItemTree *child;
};

void ItemTree::FUN_0025fb00(hulk_intptr arg)
{
    if (child)
        child->FUN_0025fb00(arg);

    Item_25fb00 *item;
    if (root == &nil) {
        item = 0;
    } else {
        Node *n = root;
        while (n->left != &nil)
            n = n->left;
        item = (Item_25fb00 *)((char *)n - 4);
    }

    while (item) {
        item->vfn3(arg);

        Node *n = item->node.right;
        Node *next;
        if (n == &nil) {
            Node *cur = &item->node;
            next = cur->parent;
            while (next != &nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            next = n;
            while (next->left != &nil)
                next = next->left;
            // leftmost of right subtree
        }
        if (next == &nil)
            item = 0;
        else
            item = (Item_25fb00 *)((char *)next - 4);
    }
}
} // namespace fn_0025fb00

namespace fn_f98b1434 {

// 0x0025fba0 FUN_0025fba0 (55 B): matches/0x0025fba0.cpp
// sym: ?init@MetaTypeAttribBase@fn_f98b1434@@QAEPAU12@PAXII@Z
MetaTypeAttribBase* MetaTypeAttribBase::init(void* p, hulk_uintptr c, hulk_uintptr d) {
    a = d;
    vptr = (void*)((hulk_intptr)DAT_00429420);
    b = c;
    d = c;
    FUN_0025f450((char*)p + 0x14, (MetaTypeAttribBase *)this, (const char **)(&d));
    return this;
}

} // namespace fn_f98b1434

// 0x0025fbe0 FUN_0025fbe0 (71 B): equivalent/0x0025fbe0.cpp [wrapped: conflict: Node]
// sym: _FUN_0025fbe0 @e8d4ba2a9b56 @we3c8b8a54ccc
namespace fn_0025fbe0 {
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 7/8, incomplete)
// FUN_0025fbe0 @ 0x0025fbe0
struct Link { Link* next; }; struct Node { virtual void destroy(int); Link link; }; struct List { Link* first; Link end; }; extern "C++" __declspec(nothrow) void __cdecl FUN_0025f6e0(void *, void *); extern "C" void __cdecl FUN_0025fbe0(void * list_) {
    List * list = (List *)list_; Link* end = &list->end; while (list->first != end) { Link* link = list->first; while (link->next != end) link = link->next; Node* node = (Node*)((char*)link - 4); if (!node) break; FUN_0025f6e0((List *)list, (Node *)node); node->destroy(1); } }
} // namespace fn_0025fbe0

namespace fn_f98b1434 {

// 0x0025fc30 om::MetaType::vfunc_0 (65 B): matches/0x0025fc30.cpp
// sym: ?vfunc_0@MetaType@om@fn_f98b1434@@UAEPAV123@E@Z
// om::MetaType's scalar deleting destructor (slot 0): the destructor body of 0x0025fa80 inlined, then the delete
// (0x00247550 on the om allocator 0x004e79d0) when bit 0 of the flag is set.
// data: g_count_25fc30 = DAT_004e79b8.count, g_ptr = DAT_004cd360
om::MetaType* om::MetaType::vfunc_0(unsigned char param) {
    void* p = (*(void**)&DAT_004cd360);
    *(void**)this = (void*)((hulk_intptr)DAT_0042aa40);
    FUN_0025f390(p, this);
    DAT_004e79b8.count = DAT_004e79b8.count - 1;
    if (param & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e79d0), this);
    return this;
}


// 0x0025fc80 FUN_0025fc80 (11 B): matches/0x0025fc80.cpp
// sym: ?target@fn_f98b1434@@YIXPAUObj_25fc80@1@PAX@Z
void __fastcall target(Obj_25fc80* self, void*) {
    FUN_0025fbe0((char*)self + 0x14);
}

} // namespace fn_f98b1434
