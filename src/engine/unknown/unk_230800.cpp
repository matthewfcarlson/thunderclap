// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00230800..0x002310a0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f39652ec {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f39652ec {} using namespace fn_f39652ec;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f39652ec {
struct RbNode_230900 {
    RbNode_230900* left;
    RbNode_230900* right;
    RbNode_230900* parent;
    char color; // 0 = black, 1 = red
};
struct RbTree_230900 {
    RbNode_230900* root;
    RbNode_230900 nil;
    void FUN_00230900(RbNode_230900* x);
};
typedef int(__cdecl* CompareFn_230ba0)(void*, void*);
struct Node_230ba0 {
    Node_230ba0* left;
    Node_230ba0* right;
};
class List_230ba0 {
  public:
    Node_230ba0* head;
    void* Find(CompareFn_230ba0 fn, void* key);
};
typedef int(__cdecl* CompareFn_230be0)(void*, void*);
struct Node {
  public:
    union { Node *left; Node* prev; };
    union { Node* next; Node *right; };
    Node *parent;
    union { unsigned char color; unsigned char red; };
    char _m_pad_d[0x3];
};
class Tree_230be0 {
  public:
    Node* head;
    Node* FindNode(CompareFn_230be0 compare, void* value);
};
struct Tree_230c30 {
    Node *root;
    Node nil;
    int count;
    void FUN_002308a0(Node *x);
    void Insert(Node *node, int (__cdecl *cmp)(Node *, Node *), Node *parent);
};
struct Tree_230de0 {
 Node* root;
 Node sentinel;
 unsigned int count;
 Node* FUN_00230800(Node* node);
 void FUN_00230900(Node* node);
 void FUN_00230de0(Node* node);
};
typedef void(__cdecl* Callback_230f50)(Node*, int);
class Container_230f50 {
  public:
    Node* root;
    int pad;
    Node* head;
    Node* tail;
    char flag[4];
    int value;
    void Clear(Callback_230f50 cb, hulk_intptr arg);
};

} // namespace fn_f39652ec

// 0x00230800 FUN_00230800 (75 B): equivalent/0x00230800.cpp [wrapped: conflict: Node]
// sym: ?FUN_00230800@Tree@fn_00230800@@QAEPAUNode@2@PAU32@@Z @f62b42597f6c @wbd029f23cc48
namespace fn_00230800 {
// STATUS: equivalent (tools/equiv.py level 3: 471 inputs, branch coverage 15/16, incomplete)
// FUN_00230800 @ 0x00230800
struct Node { Node* left; Node* parent; Node* right; }; struct Tree { char pad[4]; Node root; Node* FUN_00230800(Node* node); }; Node* Tree::FUN_00230800(Node* node) { Node* sentinel=&root; Node* next=node->parent; if(next==sentinel) { next=node->right; while(next!=sentinel && node==next->parent) { node=next; next=next->right; } } else { if(next->left!=sentinel) { next=next->left; while(next->left!=sentinel) next=next->left; } } return next==sentinel ? 0 : next; }
} // namespace fn_00230800


// 0x002308a0 FUN_002308a0 (83 B): matches/0x002308a0.cpp [wrapped: merged class would differ: Tree_2308a0: field header: Field(+0x4 Node header) vs Field(+0x4 Node header)]
// sym: ?Replace@Tree_2308a0@fn_002308a0@@QAEXPAUNode@2@@Z
namespace fn_002308a0 {
struct Node {
    Node* left;
    Node* next;
    Node* parent;
};
struct Tree_2308a0 {
    Node* root;
    Node header;
    void Replace(Node*);
};
void Tree_2308a0::Replace(Node* n) {
    Node* x = n->left;
    n->left = x->next;
    if (x->next != &header)
        x->next->parent = n;
    x->parent = n->parent;
    Node* p = n->parent;
    if (p == &header) {
        root = x;
        x->next = n;
        n->parent = x;
        return;
    }
    if (n == p->left)
        p->left = x;
    else
        p->next = x;
    x->next = n;
    n->parent = x;
}
} // namespace fn_002308a0

namespace fn_f39652ec {

// 0x00230900 FUN_00230900 (599 B): equivalent/0x00230900.cpp
// sym: ?FUN_00230900@RbTree_230900@fn_f39652ec@@QAEXPAURbNode_230900@2@@Z @a6569af7fff5 @w5e6f89aab37e
// STATUS: equivalent (tools/equiv.py level 3: 3139 inputs, branch coverage 59/60, incomplete)
// FUN_00230900 @ 0x00230900
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
void RbTree_230900::FUN_00230900(RbNode_230900* x)
{
    RbTree_230900* tree = this;
    RbNode_230900* nil = &tree->nil;
    RbNode_230900* y;
    RbNode_230900* z;
    RbNode_230900* p;
    RbNode_230900* c;

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

} // namespace fn_f39652ec

// 0x00230b60 FUN_00230b60 (22 B): matches/0x00230b60.cpp
// sym: ?FUN_00230b60@X_230b60@owners@@QAEXXZ
void owners::X_230b60::FUN_00230b60() {
    int* p = &b;
    a = (hulk_intptr)p;
    b = (hulk_intptr)p;
    c = (hulk_intptr)p;
    d = (hulk_intptr)p;
    e = 0;
    f = 0;
}

namespace fn_f39652ec {

// 0x00230ba0 FUN_00230ba0 (63 B): matches/0x00230ba0.cpp
// sym: ?Find@List_230ba0@fn_f39652ec@@QAEPAXP6AHPAX0@Z0@Z
void* List_230ba0::Find(CompareFn_230ba0 fn, void* key) {
    Node_230ba0* p = head;
    Node_230ba0* end = (Node_230ba0*)((char*)this + sizeof(void*));
    while (p != end) {
        int r = fn(key, p);
        if (r < 0)
            p = p->left;
        else if (r > 0)
            p = p->right;
        else
            return p;
    }
    return 0;
}


// 0x00230be0 FUN_00230be0 (80 B): matches/0x00230be0.cpp
// sym: ?FindNode@Tree_230be0@fn_f39652ec@@QAEPAUNode@2@P6AHPAX0@Z0@Z
Node* Tree_230be0::FindNode(CompareFn_230be0 compare, void* value) {
    Node* node = head;
    Node* sentinel = (Node*)((char*)this + 4);
    Node* result = sentinel;
    while (node != sentinel) {
        result = node;
        int cmp = compare(value, node);
        if (cmp < 0)
            node = node->prev;
        else if (cmp > 0)
            node = node->next;
        else
            return 0;
    }
    return result;
}


// 0x00230c30 FUN_00230c30 (423 B): equivalent/0x00230c30.cpp
// sym: ?Insert@Tree_230c30@fn_f39652ec@@QAEXPAUNode@2@P6AH00@Z0@Z @ab6a17d45966 @w277f767e9497
// STATUS: equivalent (tools/equiv.py level 3: 12082 inputs, branch coverage 35/38, incomplete; run with --inputs 12000)
// FUN_00230c30 @ 0x00230c30
void Tree_230c30::Insert(Node *node, int (__cdecl *cmp)(Node *, Node *), Node *parent)
{
    Node *nil = &this->nil;
    node->parent = parent;
    if (parent == nil)
        root = node;
    else if (cmp(node, parent) < 0)
        parent->left = node;
    else
        parent->right = node;

    node->left = nil;
    node->right = nil;
    node->red = 1;

    Node *x = node;
    while (x != root && x->parent->red == 1) {
        Node *p = x->parent;
        Node *g = p->parent;
        if (p == g->left) {
            Node *u = g->right;
            if (u->red == 1) {
                p->red = 0;
                u->red = 0;
                x->parent->parent->red = 1;
                x = x->parent->parent;
            } else {
                if (x == p->right) {
                    x = p;
                    Node *y = x->right;
                    x->right = y->left;
                    if (y->left != nil)
                        y->left->parent = x;
                    y->parent = x->parent;
                    if (x->parent == nil)
                        root = y;
                    else if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                    y->left = x;
                    x->parent = y;
                }
                x->parent->red = 0;
                x->parent->parent->red = 1;
                Node *h = x->parent->parent;
                Node *y = h->left;
                h->left = y->right;
                if (y->right != nil)
                    y->right->parent = h;
                y->parent = h->parent;
                if (h->parent == nil) {
                    root = y;
                    y->right = h;
                } else if (h == h->parent->left) {
                    h->parent->left = y;
                    y->right = h;
                } else {
                    h->parent->right = y;
                    y->right = h;
                }
                h->parent = y;
            }
        } else {
            Node *u = g->left;
            if (u->red == 1) {
                x->parent->red = 0;
                u->red = 0;
                x->parent->parent->red = 1;
                x = x->parent->parent;
            } else {
                if (x == p->left) {
                    x = p;
                    FUN_002308a0(x);
                }
                x->parent->red = 0;
                x->parent->parent->red = 1;
                Node *h = x->parent->parent;
                Node *y = h->right;
                h->right = y->left;
                if (y->left != nil)
                    y->left->parent = h;
                y->parent = h->parent;
                if (h->parent == nil)
                    root = y;
                else if (h == h->parent->left)
                    h->parent->left = y;
                else
                    h->parent->right = y;
                y->left = h;
                h->parent = y;
            }
        }
    }
    root->red = 0;
    count++;
}


// 0x00230de0 FUN_00230de0 (179 B): equivalent/0x00230de0.cpp
// sym: ?FUN_00230de0@Tree_230de0@fn_f39652ec@@QAEXPAUNode@2@@Z @7ff310ea89ff @w247877d6fbdf
// STATUS: equivalent (tools/equiv.py level 3: 704 inputs, branch coverage 24/24)
// FUN_00230de0 @ 0x00230de0
void Tree_230de0::FUN_00230de0(Node* node) {
 Node* nil = &sentinel;
 Node* removed;
 if (node->left != nil && node->right != nil) removed = FUN_00230800(node);
 else removed = node;
 Node* child = removed->left;
 if (child == nil) child = removed->right;
 child->parent = removed->parent;
 Node* parent = removed->parent;
 if (parent == nil) root = child;
 else if (parent->left == removed) parent->left = child;
 else parent->right = child;
 bool black = removed->color == 0;
 if (removed != node) {
  removed->parent = node->parent;
  removed->left = node->left;
  removed->right = node->right;
  removed->color = node->color;
  parent = removed->parent;
  if (parent == nil) root = removed;
  else if (parent->left == node) parent->left = removed;
  else parent->right = removed;
  if (removed->left != nil) removed->left->parent = removed;
  if (removed->right->parent != nil) removed->right->parent = removed;
 }
 if (black) FUN_00230900(child);
 --count;
}

} // namespace fn_f39652ec

// 0x00230ea0 FUN_00230ea0 (27 B): matches/0x00230ea0.cpp [wrapped: conflict: Node]
// sym: @FUN_00230ea0@4
namespace fn_00230ea0 {
struct Node {
    Node* next;
};
extern "C" Node* __fastcall FUN_00230ea0(Node* p) {
    Node* n = p->next;
    if (n == (Node*)((char*)p + 4))
        return 0;
    while (n->next != (Node*)((char*)p + 4))
        n = n->next;
    return n;
}
} // namespace fn_00230ea0


// 0x00230ec0 FUN_00230ec0 (141 B): equivalent/0x00230ec0.cpp [wrapped: merged class would differ: Tree_230ec0: field nil: Field(+0x4 Node nil) vs Field(+0x4 Node nil)]
// sym: ?FUN_00230ec0@Tree_230ec0@fn_00230ec0@@QAE_NP6ADPAUNode@2@H@ZH@Z @987db732c67e @wb8ea86b8c62c
namespace fn_00230ec0 {
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 27/28, incomplete)
// FUN_00230ec0 @ 0x00230ec0
// In-order walk of a red-black tree (STL map layout): call back for every node until the callback returns false.
struct Node {
    Node* left;
    Node* right;
    Node* parent;
};

typedef char (__cdecl *NodeCallback)(Node* node, int arg);

class Tree_230ec0 {
public:
    Node* root;
    Node nil;

    bool FUN_00230ec0(NodeCallback callback, int arg);
};

bool Tree_230ec0::FUN_00230ec0(NodeCallback callback, int arg)
{
    Node* n;
    if (root == &nil) {
        n = 0;
    } else {
        n = root;
        while (n->left != &nil) {
            n = n->left;
        }
    }
    if (n == &nil || n == 0) {
        return true;
    }
    for (;;) {
        if (!callback(n, arg)) {
            return false;
        }
        Node* next = n->right;
        if (next != &nil) {
            while (next->left != &nil) {
                next = next->left;
            }
        } else {
            Node* child = n;
            next = n->parent;
            if (next == &nil) {
                return true;
            }
            while (child == next->right) {
                child = next;
                next = next->parent;
                if (next == &nil) {
                    break;
                }
            }
        }
        if (next == &nil || next == 0) {
            return true;
        }
        n = next;
    }
}
} // namespace fn_00230ec0

namespace fn_f39652ec {

// 0x00230f50 FUN_00230f50 (105 B): matches/0x00230f50.cpp
// sym: ?Clear@Container_230f50@fn_f39652ec@@QAEXP6AXPAUNode@2@H@ZH@Z
void Container_230f50::Clear(Callback_230f50 cb, hulk_intptr arg) {
    Node* sent = (Node*)((char*)this + 4);
    Node* n = root;
    if (n != sent)
        do {
            for (;;) {
                Node* p;
                while (n->left != sent)
                    n = n->left;
                p = n->right;
                if (p == sent)
                    break;
                n = p;
            }
            Node* ret = n;
            n = n->parent;
            if (n->left != sent)
                n->left = sent;
            else
                n->right = sent;
            cb(ret, arg);
        } while (n != sent);
    root = sent;
    head = sent;
    tail = sent;
    sent->left = sent;
    flag[0] = 0;
    value = 0;
}

} // namespace fn_f39652ec

// 0x00231050 FUN_00231050 (26 B): matches/0x00231050.cpp
// sym: ?FUN_00231050@C_231050@owners@@QAEXXZ
void owners::C_231050::FUN_00231050() {
    thunk(a);
    thunk(b);
}


// 0x00231070 FUN_00231070 (37 B): matches/0x00231070.cpp
// sym: ?FUN_00231070@X_231070@owners@@QAEXXZ
void owners::X_231070::FUN_00231070() {
    unsigned i = 0;
    while (i < count) {
        data[i] = 0;
        ++i;
    }
    a = 0;
    b = 0;
}

