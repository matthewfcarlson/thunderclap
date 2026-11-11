// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00242090..0x00243360 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f215d331 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f215d331 {} using namespace fn_f215d331;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f215d331 {
struct TreeLink { TreeLink *left; TreeLink *parent; TreeLink *right; };
struct TreeNode { int value; TreeLink link; };
struct TreeNode_2422e0 {
    TreeNode_2422e0 *left;        // 0x00
    TreeNode_2422e0 *right;       // 0x04
    TreeNode_2422e0 *parent;      // 0x08
    int color;             // 0x0c, 1 = red, 0 = black
    char pad10[0x20 - 0x10];
    int key;               // 0x20
};
struct Tree_2422e0 {
    TreeNode_2422e0 *root;
    TreeNode_2422e0 nil;
};
extern "C" void __cdecl FUN_00241880(Tree_2422e0 *t, TreeNode_2422e0 *x);
extern "C" void __cdecl FUN_002418d0(Tree_2422e0 *t, TreeNode_2422e0 *x);
extern "C" void* FUN_00241930(void*, void*);
extern "C" void FUN_00241970(void*, void*);
extern "C" void* FUN_00241cb0(void*, void*);
extern "C" void FUN_00241cf0(void*, void*);
struct Source_242860 {
    char pad0[0x18];
    float f18;
    float f1c;
    char pad20[8];
    unsigned char disabled;
};
struct Modifier_242860 {
    char pad0[0x2c];
    float f2c;
    float f30;
};
struct Link_242860;
struct Entry_242860 {
    char pad0[8];
    Link_242860 *next;
    char padC[4];
    Source_242860 *source;
    Modifier_242860 *modifier;
};
struct Link_242860 {
    Entry_242860 *entry() { return (Entry_242860 *)((char *)this - 8); }
};
struct TreeNode_242860 {
    TreeNode_242860 *left;
    TreeNode_242860 *right;
    TreeNode_242860 *parent;
    char padC[4];
    Link_242860 *links;
    char pad14[0x20 - 0x14];
    float product0;
    float product1;
};
struct Tree_242860 {
    TreeNode_242860 *root;
    TreeNode_242860 nil;
};
extern void* __cdecl FUN_00247530(void*);
extern "C" void __cdecl ReleaseThing_00247550(void*, int);
extern "C" bool __cdecl FUN_002422e0(void *, void *, int *);
extern "C" void __cdecl FUN_00257e80(int, void*);
struct Obj_242c30 {
    char pad[0x18];
    int a, b, c, d, e, f, g, h;
};
typedef unsigned int u32_242ca0;
struct Item_242ca0 {
    char pad[0x10];
    int member;
    char pad2[0x0c];
    hulk_intptr at20;
};
extern "C" void __cdecl FUN_002424a0(void *, void *);
extern "C" void FUN_00257f00(void*, void*);
extern void f3_00247550(void*, Item_242ca0*);
struct Obj_242d70 {
    char pad[0x1c];
    unsigned int count;
};
extern "C" void __cdecl FUN_00242680(void *, void *);
void __cdecl F2_00247550(void*, Obj_242d70*);
struct Link_242ec0 {
    Link_242ec0 *next;
    Link_242ec0 *prev;
};
struct Owner_242ec0 {
    char pad0[0x10];
    Link_242ec0 *head;             // 0x10
    Link_242ec0 *tail;             // 0x14
    char pad18[4];
    unsigned int refs;      // 0x1c
};
struct Node {
  public:
    union { Node *chain; Node* left; };
    union { int b; Node* right; };
    union { Link_242ec0 *next; Node* parent; };
    union { int data; Link_242ec0 *prev; };
    char _m_pad_10[0x8];
    Owner_242ec0 *owner;
    char _m_pad_1c[0xc];
    float duration;
    float progress;
    char _m_pad_30[0x4];
    int state;
};
struct Container_242ec0 {
    char pad0[0x18];
    Node *first;            // 0x18
    int count;              // 0x1c
};
void __cdecl FUN_00247550(void *pool, void *item);
struct Obj_242f60 {
    char pad0[0x28];
    int field28;
    char pad2c[8];
    int field34;
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00242da0(void *, void *);
struct Tree_242f90 {
    Node *root;
    Node nil;
};
struct Owner_242f90 {
    char pad00[0x14];
    Tree_242f90 tree;
};
extern void __cdecl FUN_00242ec0(Owner_242f90 *owner, Node *node);
typedef unsigned int U_243090;
void FUN_00242f90(U_243090, U_243090);
void FUN_00242860(U_243090, U_243090);
struct Block {
    unsigned size;
    unsigned* next;
};
struct Pool_2431a0 {
    unsigned int stride;
    char *head;
    char *buf;
};
typedef unsigned __int64 U64_243310;
class FUN_002584d0 {
  public:
    virtual void f();
    unsigned int reserved04;
    OmTypeBody body;
    FUN_002584d0(const OmKey*, const OmKey*, int, int);
};
class EntityType : public FUN_002584d0 {
  public:
    EntityType(const U64_243310*, const U64_243310*, int, int, int);
    unsigned int reserved48[8];
    int value;
    virtual void f();
};
void __fastcall FUN_002580e0(CEffectStopTrack*);


// 0x00242090 FUN_00242090 (1 B): matches/0x00242090.cpp
// sym: ?FUN_00242090@fn_f215d331@@YAXXZ
void FUN_00242090() {
    return;
}


// 0x00242130 FUN_00242130 (74 B): equivalent/0x00242130.cpp
// sym: ?FUN_00242130@fn_f215d331@@YAPAUTreeNode@1@PAU21@0@Z @f937dbdd3b94 @w109f8f8dd6d8
// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_00242130 @ 0x00242130
TreeNode *__cdecl FUN_00242130(TreeNode *head, TreeNode *current)
{
    TreeLink *sentinel = &head->link;
    TreeLink *node = current->link.parent;
    if (node != sentinel) {
        TreeLink *left = node->left;
        while (left != sentinel) {
            node = left;
            left = node->left;
        }
    } else {
        TreeLink *cursor = &current->link;
        node = cursor->right;
        while (node != sentinel && cursor == node->parent) {
            cursor = node;
            node = node->right;
        }
    }
    if (node == sentinel) return 0;
    return (TreeNode *)((char *)node - 4);
}


// 0x002422e0 FUN_002422e0 (434 B): equivalent/0x002422e0.cpp
// sym: _FUN_002422e0 @732d44cc54ec @w6044d9e1dce9
// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 38/40, incomplete)
// FUN_002422e0 @ 0x002422e0
extern "C" bool __cdecl FUN_002422e0(void * t_, void * node_, int *keyPtr)
{
    Tree_2422e0 * t = (Tree_2422e0 *)t_;
    TreeNode_2422e0 * node = (TreeNode_2422e0 *)node_;
    TreeNode_2422e0 *nil = &t->nil;
    TreeNode_2422e0 *y = nil;
    TreeNode_2422e0 *x = t->root;

    if (x != nil) {
        int key = *keyPtr;
        do {
            int d = (int)((unsigned int)key - (unsigned int)x->key);
            y = x;
            if (d < 0)
                x = x->left;
            else if (d <= 0)
                return false;
            else
                x = x->right;
        } while (x != nil);
    }

    node->parent = y;
    if (y == nil) {
        t->root = node;
    } else {
        int d = (int)((unsigned int)*keyPtr - (unsigned int)y->key);
        if (d < 0)
            y->left = node;
        else
            y->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != t->root && node->parent->color == 1) {
        TreeNode_2422e0 *p = node->parent;
        TreeNode_2422e0 *g = p->parent;
        TreeNode_2422e0 *gl = g->left;
        if (p == gl) {
            TreeNode_2422e0 *u = g->right;
            if (u->color == 1) {
                p->color = 0;
                u->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_00241880(t, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                TreeNode_2422e0 *gg = node->parent->parent;
                TreeNode_2422e0 *pivot = gg->left;
                gg->left = pivot->right;
                if (pivot->right != nil)
                    pivot->right->parent = gg;
                pivot->parent = gg->parent;
                TreeNode_2422e0 *gp = gg->parent;
                if (gp == nil)
                    t->root = pivot;
                else if (gg == gp->left)
                    gp->left = pivot;
                else
                    gp->right = pivot;
                pivot->right = gg;
                gg->parent = pivot;
            }
        } else {
            if (gl->color == 1) {
                p->color = 0;
                gl->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_002418d0(t, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                TreeNode_2422e0 *gg = node->parent->parent;
                TreeNode_2422e0 *pivot = gg->right;
                gg->right = pivot->left;
                if (pivot->left != nil)
                    pivot->left->parent = gg;
                pivot->parent = gg->parent;
                TreeNode_2422e0 *gp = gg->parent;
                if (gp == nil)
                    t->root = pivot;
                else if (gg == gp->left)
                    gp->left = pivot;
                else
                    gp->right = pivot;
                pivot->left = gg;
                gg->parent = pivot;
            }
        }
    }
    t->root->color = 0;
    return true;
}


// 0x002424a0 FUN_002424a0 (178 B): matches/0x002424a0.cpp
// sym: _FUN_002424a0
extern "C" void FUN_002424a0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00241930(((Node *)tree), ((Node *)node));
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
        FUN_00241970(((Node *)tree), y);
}


// 0x00242680 FUN_00242680 (178 B): matches/0x00242680.cpp
// sym: _FUN_00242680
extern "C" void FUN_00242680(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00241cb0(((Node *)tree), ((Node *)node));
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
        FUN_00241cf0(((Node *)tree), y);
}


// 0x00242860 FUN_00242860 (305 B): equivalent/0x00242860.cpp
// sym: ?FUN_00242860@fn_f215d331@@YAXPAUTree_242860@1@@Z @88ca765a5f94 @w80a1fd5ded18
// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 30/34, incomplete)
// FUN_00242860 @ 0x00242860
void FUN_00242860(Tree_242860 *tree)
{
    TreeNode_242860 *nil = &tree->nil;
    TreeNode_242860 *node = tree->root;
    if (node == nil)
        return;
    while (node->left != nil)
        node = node->left;

    do {
        hulk_freg a = 1.0f;
        hulk_freg b = 1.0f;

        if (node->links != 0) {
            Entry_242860 *e = node->links->entry();
            while (e != 0) {
                Source_242860 *src = e->source;
                Modifier_242860 *mod = e->modifier;
                if (src->f1c >= 1.0f) {
                    b = b * ((src->f1c - 1.0f) * mod->f2c + 1.0f);
                } else {
                    b = b * (1.0f - (1.0f - src->f1c) * mod->f2c);
                }
                hulk_freg x;
                if (src->disabled == 0)
                    x = src->f18;
                else
                    x = 0.0f;
                hulk_freg m = x + (1.0f - src->f18) * (1.0f - mod->f30);
                a = a * (m + (1.0f - mod->f2c) * (1.0f - m));
                e = e->next ? e->next->entry() : 0;
            }
        }
        node->product0 = a;
        node->product1 = b;

        TreeNode_242860 *s = node->right;
        if (s == nil) {
            TreeNode_242860 *child = node;
            s = node->parent;
            while (s != nil && child == s->right) {
                child = s;
                s = s->parent;
            }
        } else {
            while (s->left != nil)
                s = s->left;
        }
        node = s;
    } while (node != nil && node != 0);
}

} // namespace fn_f215d331

// 0x00242a00 FUN_00242a00 (451 B): equivalent/0x00242a00.cpp [wrapped: merged class would differ: Tree_242a00: field nil: Field(+0x4 Node nil) vs Field(+0x4 Node nil)]
// sym: _FUN_00242a00 @82049d332491 @wbd3a186af45c
namespace fn_00242a00 {
// STATUS: equivalent (tools/equiv.py level 3: 183 inputs, branch coverage 37/40, incomplete)
// FUN_00242a00 @ 0x00242a00
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    char pad[8];
    unsigned key;
};

struct Tree_242a00 {
    Node* root;
    Node nil;
};

extern "C" void FUN_00241c00(Tree_242a00* tree, Node* node);
extern "C" void FUN_00241c50(Tree_242a00* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_00242a00(void * tree_, void * nodeArg, const unsigned* keyPtr)
{
    Tree_242a00 * tree = (Tree_242a00 *)tree_;
    Node* nil = &tree->nil;
    Node* node = ((Node *)nodeArg);
    unsigned key = *keyPtr;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else if (key == cur->key) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (*keyPtr < parent->key) {
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
                    FUN_00241c00(tree, node);
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
                    FUN_00241c50(tree, node);
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
} // namespace fn_00242a00

namespace fn_f215d331 {

// 0x00242bd0 FUN_00242bd0 (56 B): matches/0x00242bd0.cpp
// sym: _FUN_00242bd0
// data: gPool_242bd0 = DAT_004e5db0
extern "C" Node* __cdecl FUN_00242bd0() {
    Node* p = (Node*)FUN_00247530(DAT_004e5db0);
    if (p) {
        int* q = (int*)p + 1;
        q[0] = (hulk_intptr)q;
        ((hulk_intptr*)p)[2] = (hulk_intptr)q;
        ((hulk_intptr*)p)[3] = (hulk_intptr)q;
        ((hulk_intptr*)p)[0] = (hulk_intptr)q;
        ((int*)p)[4] = 0;
        _ReadWriteBarrier();
        int* r = (int*)p + 6;
        r[0] = (hulk_intptr)r;
        ((hulk_intptr*)p)[7] = (hulk_intptr)r;
        ((hulk_intptr*)p)[8] = (hulk_intptr)r;
        ((int*)p)[9] = 0;
        ((hulk_intptr*)p)[5] = (hulk_intptr)r;
        return p;
    }
    return 0;
}


// 0x00242c10 FUN_00242c10 (31 B): matches/0x00242c10.cpp
// sym: _FUN_00242c10
extern "C" void __cdecl FUN_00242c10(int* p) {
    int x = *p;
    *p = 0;
    if (x != 0)
        ReleaseThing_00247550((void*)((hulk_intptr)DAT_004e5db0), x);
}


// 0x00242c30 FUN_00242c30 (97 B): matches/0x00242c30.cpp
// sym: _FUN_00242c30
// data: gData_242c30 = DAT_004e5df8
extern "C" Obj_242c30* __cdecl FUN_00242c30(int owner, int key) {
    Obj_242c30* q = (Obj_242c30*)FUN_00247530(((int*)&DAT_004e5df8));
    Obj_242c30* p;
    if (q) {
        q->a = 0;
        q->b = 0;
        p = q;
    } else
        p = 0;
    int zero = 0;
    p->d = owner;
    p->f = zero;
    p->g = 0x3f800000;
    p->e = zero;
    p->c = key;
    p->h = zero;
    FUN_002422e0((void *)(hulk_uintptr)(int)(owner + 0x14), p, &p->c);
    FUN_00257e80(key + 0x28, (char*)p + 0x10);
    return p;
}


// 0x00242ca0 FUN_00242ca0 (59 B): matches/0x00242ca0.cpp
// sym: ?target@fn_f215d331@@YAXPAXPAPAUItem_242ca0@1@@Z
// data: globalBss = DAT_004e5df8
void target(void* param1, Item_242ca0** param2) {
    Item_242ca0* p = *param2;
    *param2 = 0;
    FUN_002424a0((char*)param1 + 0x14, (Item_242ca0 *)p);
    FUN_00257f00((char*)p->at20 + 0x28, (char*)p + 0x10);
    f3_00247550(((char*)&DAT_004e5df8), p);
}

} // namespace fn_f215d331

// 0x00242ce0 FUN_00242ce0 (139 B): equivalent/0x00242ce0.cpp [wrapped: conflict: FUN_00247530]
// sym: ?FindOrInsert@fn_00242ce0@@YAPAUNode@1@PAUMap_242ce0@1@PBI@Z @999d2a1fd650 @w8301a1985ac3
namespace fn_00242ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 12/12)
// FUN_00242ce0 @ 0x00242ce0

struct Node {
    Node* left;
    Node* right;
    char pad[8];
    int v10, v14;
    unsigned key;
    int refs;
    float v20, v24;
};
struct Map_242ce0 { Node* root; };
Node* __cdecl FUN_00247530(void* heap);
extern "C++" __declspec(nothrow) char __cdecl FUN_00242a00(void *, void *, const unsigned *);
Node* FindOrInsert(Map_242ce0* map, const unsigned* key) {
    Node* nil = (Node*)((char*)map + 4);
    Node* n = map->root;
    Node* volatile hit = 0;
    if (n != nil) {
        unsigned k = *key;
        do {
            if (k < n->key) {
                n = n->left;
            } else if (k <= n->key) {
                hit = n;
                break;
            } else {
                n = n->right;
            }
        } while (n != nil);
    }
    if (hit) {
        hit->refs++;
        return hit;
    }
    Node* alloc = FUN_00247530(DAT_004e5e88);
    Node* node = 0;
    if (alloc) {
        alloc->v10 = 0;
        alloc->v14 = 0;
        node = alloc;
    }
    node->v20 = 1.0f;
    node->v24 = 1.0f;
    node->key = *key;
    FUN_00242a00((Map_242ce0 *)map, (Node *)node, &node->key);
    node->refs = 1;
    return node;
}
} // namespace fn_00242ce0

namespace fn_f215d331 {

// 0x00242d70 FUN_00242d70 (46 B): matches/0x00242d70.cpp
// sym: _FUN_00242d70
extern "C" void __cdecl FUN_00242d70(void* a, Obj_242d70* b) {
    if (b->count > 1) {
        --b->count;
        return;
    }
    FUN_00242680(a, (Obj_242d70 *)b);
    F2_00247550((void*)((hulk_intptr)DAT_004e5e88), b);
}

} // namespace fn_f215d331

// 0x00242da0 FUN_00242da0 (279 B): equivalent/0x00242da0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_00242da0 @3abc14821b7a @wa2cb20dc01b0
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_00242da0 {
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 30/30)
// FUN_00242da0 @ 0x00242da0


struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree_242da0 {
    Node *root;
    Node nil;
};

struct Link_242da0 {
    Link_242da0 *next;
    Link_242da0 *prev;
};

struct Target_242da0;
struct Group_242da0;

struct Entry_242da0;

// One binding of an entry to a target, kept in both the target's and the group's list.
struct Binding_242da0 {
    Link_242da0 groupLink;
    Link_242da0 targetLink;
    Entry_242da0 *entry;
    Group_242da0 *group;
    Target_242da0 *target;

    Binding_242da0() throw()
    {
        groupLink.next = 0;
        groupLink.prev = 0;
        targetLink.next = 0;
        targetLink.prev = 0;
        entry = 0;
        group = 0;
        target = 0;
    }
};

struct Target_242da0 {
    char pad00[0x10];
    Link_242da0 *head;
    Link_242da0 *tail;
};

struct Entry_242da0 {
    int vptr;
    Node node;
    char pad10[4];
    int key;
};

struct Owner_242da0 {
    char pad00[0x38];
    Tree_242da0 tree;
};

struct Group_242da0 {
    char pad00[0x18];
    Link_242da0 *head;
    Link_242da0 *tail;
    Owner_242da0 *owner;
};

struct Context;

extern Target_242da0 *__cdecl FUN_00242ce0(Context *ctx, int *key);
extern void *__cdecl FUN_00247530(void *pool);
extern char DAT_004e5e40[];

static Entry_242da0 *EntryOf(Node *n)
{
    return (Entry_242da0 *)((char *)n - 4);
}

extern "C" void FUN_00242da0(void *ctx, void *group)
{
    Owner_242da0 *owner = ((Group_242da0 *)group)->owner;
    Node *nil = &owner->tree.nil;
    Entry_242da0 *e;
    if (owner->tree.root == nil) {
        e = 0;
    } else {
        Node *n = owner->tree.root;
        while (n->left != nil)
            n = n->left;
        e = EntryOf(n);
    }
    if (!e)
        return;
    do {
        Target_242da0 *target = FUN_00242ce0(((Context *)ctx), &e->key);
        Binding_242da0 *b = (Binding_242da0 *)FUN_00247530(DAT_004e5e40);
        if (b)
            new (b) Binding_242da0;
        b->target = target;
        b->group = ((Group_242da0 *)group);
        b->entry = e;

        Link_242da0 *tl = &b->targetLink;
        if (target->head == 0) {
            target->head = tl;
            tl->prev = 0;
        } else {
            target->tail->next = tl;
            tl->prev = target->tail;
        }
        target->tail = tl;
        tl->next = 0;

        Link_242da0 *gl = &b->groupLink;
        if (((Group_242da0 *)group)->head == 0) {
            ((Group_242da0 *)group)->head = gl;
            gl->prev = 0;
        } else {
            ((Group_242da0 *)group)->tail->next = gl;
            gl->prev = ((Group_242da0 *)group)->tail;
        }
        ((Group_242da0 *)group)->tail = gl;
        gl->next = 0;

        // in-order successor
        Node *cur = &e->node;
        Node *next = cur->right;
        if (next == nil) {
            next = cur->parent;
            while (next != nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        e = next == nil ? 0 : EntryOf(next);
    } while (e != 0);
}
} // namespace fn_00242da0

namespace fn_f215d331 {

// 0x00242ec0 FUN_00242ec0 (148 B): equivalent/0x00242ec0.cpp
// sym: ?FUN_00242ec0@fn_f215d331@@YAXHPAUContainer_242ec0@1@@Z @ed77b45f244d @w51d9fc3a3912
// STATUS: equivalent (tools/equiv.py level 3: 2832 inputs, branch coverage 10/10)
// FUN_00242ec0 @ 0x00242ec0
void __cdecl FUN_00242ec0(hulk_intptr arg, Container_242ec0 *list)
{
    Node *node = list->first;
    while (node != 0) {
        Node *current = node;
        Owner_242ec0 *owner = current->owner;
        if (current->prev == 0)
            owner->head = current->next;
        else
            current->prev->next = current->next;
        if (current->next == 0)
            owner->tail = current->prev;
        else
            current->next->prev = current->prev;

        owner = current->owner;
        if (owner->refs > 1) {
            owner->refs--;
        } else {
            FUN_00242680((void *)(hulk_uintptr)(int)arg, (Owner_242ec0 *)owner);
            FUN_00247550(((char*)&DAT_004e5e88), owner);
        }
        node = current->chain;
        FUN_00247550(((char*)((char*)&DAT_004e5e40)), current);
    }
    list->first = 0;
    list->count = 0;
}


// 0x00242f60 FUN_00242f60 (48 B): matches/0x00242f60.cpp
// sym: _FUN_00242f60
extern "C" void FUN_00242f60(int a, Obj_242f60* b, int c) {
    if (b->field34 == 0)
        FUN_00242da0((void *)(hulk_uintptr)(int)a, (Obj_242f60 *)b);
    if (b->field34 != 2) {
        b->field34 = 1;
        b->field28 = c;
    }
}


// 0x00242f90 FUN_00242f90 (242 B): equivalent/0x00242f90.cpp
// sym: ?FUN_00242f90@fn_f215d331@@YAXPAUOwner_242f90@1@M@Z @6ca12c3b9bd5 @w5fdb33ca54d2
// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 34/34)
// FUN_00242f90 @ 0x00242f90
// Advances every node's fade: state 1 ramps progress up to 1 (then state 2), state 3 ramps it
// down and releases the node once it drops below 0.
void FUN_00242f90(Owner_242f90 *owner, float dt)
{
    Node *nil = &owner->tree.nil;
    Node *node = owner->tree.root;
    if (node == nil)
        return;
    while (node->left != nil)
        node = node->left;
    do {
        if (node->state == 1) {
            bool done = true;
            if (node->duration > 0.0f) {
                node->progress = dt / node->duration + node->progress;
                done = node->progress > 1.0f;
            }
            if (done) {
                node->progress = 1.0f;
                node->state = 2;
            }
        } else if (node->state == 3) {
            bool release = true;
            if (node->duration > 0.0f) {
                node->progress = node->progress - dt / node->duration;
                release = node->progress < 0.0f;
            }
            if (release) {
                node->state = 0;
                node->progress = 0;
                FUN_00242ec0(owner, node);
            }
        }

        // in-order successor
        Node *cur = node;
        Node *next = cur->right;
        if (next == nil) {
            next = cur->parent;
            while (next != nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        node = next;
    } while (node != nil && node != 0);
}


// 0x00243090 FUN_00243090 (30 B): matches/0x00243090.cpp
// sym: _FUN_00243090
extern "C" void FUN_00243090(U_243090 a, U_243090 b) {
    FUN_00242f90(a, b);
    FUN_00242860(a, b);
}


// 0x002430c0 FUN_002430c0 (5 B): matches/0x002430c0.cpp
// sym: ?FUN_002430c0@fn_f215d331@@YAHH@Z
int FUN_002430c0(int x) {
    return x;
}


// 0x002430d0 FUN_002430d0 (20 B): matches/0x002430d0.cpp
// sym: ?FUN_002430d0@fn_f215d331@@YAHPAUNode@1@@Z
hulk_intptr __cdecl FUN_002430d0(Node* p) {
    hulk_intptr r = p->b;
    if (r) {
        p->b = *(int*)r;
    } else {
        r = 0;
    }
    return r;
}


// 0x00243110 FUN_00243110 (53 B): matches/0x00243110.cpp
// sym: ?FUN_00243110@fn_f215d331@@YAXPAUBlock@1@PAII@Z
void __cdecl FUN_00243110(Block* b, unsigned* p, unsigned n) {
    if (!p || !n)
        return;
    unsigned count = n / b->size - 1;
    while (count) {
        *(hulk_uintptr*)p = (hulk_uintptr)p + b->size;
        p = (unsigned*)*(hulk_uintptr*)p;
        --count;
    }
    *(hulk_uintptr*)p = (hulk_uintptr)b->next;
    b->next = p;
}


// 0x002431a0 FUN_002431a0 (108 B): equivalent/0x002431a0.cpp
// sym: ?FUN_002431a0@fn_f215d331@@YAPAUPool_2431a0@1@PAU21@PADII@Z @ea0e32d81e71 @w29680836e393
// STATUS: equivalent (tools/equiv.py level 3: 166 inputs, branch coverage 9/10, incomplete)
// FUN_002431a0 @ 0x002431a0
Pool_2431a0 *FUN_002431a0(Pool_2431a0 *p, char *buf, unsigned int total, unsigned int elem)
{
    if (elem < 4)
        elem = 4;
    if ((elem & 3) != 0)
        elem = elem - (elem & 3) + 4;
    unsigned int count = total / elem;
    p->stride = elem;
    p->buf = buf;
    if (count == 0) {
        p->head = 0;
        return p;
    }
    p->head = buf;
    char **cur = (char **)buf;
    for (unsigned int i = 0; i < count; i++) {
        char *next = p->head + p->stride * i;
        *cur = next;
        cur = (char **)next;
    }
    *cur = 0;
    return p;
}


// 0x00243310 FUN_00243310 (49 B): matches/0x00243310.cpp
// sym: ??0EntityType@fn_f215d331@@QAE@PB_K0HHH@Z
// om::EntityType's constructor: the om::Type constructor (0x002584d0) with the two type keys, then the own field
// (records.h OmEntityType). The base class is named by its constructor's address so that the native links bind the
// call by address; the two keys are passed by address (the callers' references).
EntityType::EntityType(const U64_243310* a, const U64_243310* b, int c, int d, int e)
    : FUN_002584d0((const OmKey*)a, (const OmKey*)b, d, e), value(c) {}


// 0x00243350 FUN_00243350 (11 B): matches/0x00243350.cpp
// sym: ?FUN_00243350@fn_f215d331@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_00243350(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_002580e0(self);
}

} // namespace fn_f215d331
