// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0025fca0..0x00260730 (kind game, layer engine, confidence high), dominant class audio::SeqEvent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3ff1114 {
#define TREE_TU_END }
namespace fn_f3ff1114 {} using namespace fn_f3ff1114;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f3ff1114 {
class Text {
  public:
    const char* FUN_0023fb00();
};
class SeqEvent_25fd00 {
  public:
    SeqEvent_25fd00();
    virtual ~SeqEvent_25fd00();
};
extern void* hulk_at_0042aa60;
typedef unsigned int u32_25fd20;
extern "C" int FUN_00263db0(hulk_uintptr, u32_25fd20);
struct Node {
  public:
    union { Node* a; Node* left; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_25fdd0 {
    Node* root;
};
struct Tree_25fe20 {
    Node* root;
    Node head;
};
struct RbNode_25fec0 {
    RbNode_25fec0* left;
    RbNode_25fec0* right;
    RbNode_25fec0* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_25fec0 {
    RbNode_25fec0* root;
    RbNode_25fec0 nil;
};
} // namespace fn_f3ff1114
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
namespace fn_f3ff1114 {
void thunk_FUN_00267090(pure3d::NonCopyable*);
struct String {
    const char* FUN_0023fb00();
};
typedef OmTreeNode Node_2601d0;
static inline SeqEventTypeHead* entry_of(Node_2601d0* n)
{
    return (SeqEventTypeHead*)((char*)n - (hulk_intptr)&((SeqEventTypeHead*)0)->node);
}
struct SeqEventTree_2601d0 {
    static int __cdecl FUN_0025fca0(void *, void *);
    static void __cdecl FUN_0025fdd0(void *, void *);
};
void FUN_0025fe20(OmTree* tree, Node_2601d0* x);
typedef OmTreeNode Node_2603e0;
Node_2603e0 *__cdecl FUN_0025fe80(OmTree *, Node_2603e0 *);
struct SeqEventTree_2603e0 {     // class scope: FUN_0025fec0 is a C definition of this TU (gen_tree)
    static void __cdecl FUN_0025fec0(void *, void *);
};
struct Entry {
    char pad[0x48];
    Node node;
};
struct Head {
    char pad[4];
    Node sentinel;
};
struct Item {
    virtual void Slot0(int);
    virtual void Slot1(int);
    virtual void Slot2(int);
    virtual void Slot3(int);
    virtual void Destroy(int doDelete);
    Link link;
};
typedef unsigned int u32_260680;
struct Sub_260680 {
};
struct Obj_260680 {
    hulk_uintptr vf;
    char pad[0x54];
    void FUN_002580e0();
};


// 0x0025fca0 FUN_0025fca0 (81 B): matches/0x0025fca0.cpp
// sym: _FUN_0025fca0
// A name against a sequence event type's name (records.h SeqEventTypeHead): strcmp of the two texts.
extern "C" int FUN_0025fca0(void * a, void * b) {
    return strcmp(((Text *)a)->FUN_0023fb00(), ((Text *)&((SeqEventTypeHead *)b)->name)->FUN_0023fb00());
}


// 0x0025fd00 FUN_0025fd00 (9 B): matches/0x0025fd00.cpp
// sym: ??0SeqEvent_25fd00@fn_f3ff1114@@QAE@XZ
// Same code shape as 0x000b3de0 (propagated; names are from that function)
SeqEvent_25fd00::SeqEvent_25fd00() {}


// 0x0025fd10 FUN_0025fd10 (7 B): matches/0x0025fd10.cpp
// sym: @FUN_0025fd10@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_0025fd10(void* self) {
    *(void**)self = &hulk_at_0042aa60;
}

} // namespace fn_f3ff1114

// 0x0025fd20 audio::SeqEvent::vfunc_0 (18 B): matches/0x0025fd20.cpp
// sym: ?vfunc_0@SeqEvent@audio@@UAEHPAX@Z
int audio::SeqEvent::vfunc_0(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    return FUN_00263db0(arg, 0);
}


// 0x0025fd40 audio::SeqEvent::vfunc_1 (51 B): matches/0x0025fd40.cpp [wrapped: conflict: audio::SeqEvent]
// sym: ?vfunc_1@SeqEvent@audio@fn_0025fd40@@UAEEH@Z
namespace fn_0025fd40 {
typedef unsigned char u8_25fd40;
struct Buf_25fd40 {
    u8_25fd40 d[32];
    void init_002634c0();
    void fini_00263d30();
};
extern "C" u8_25fd40 __cdecl FUN_00263500(int, Buf_25fd40*);
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual u8_25fd40 vfunc_1(int);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
} // namespace audio
u8_25fd40 audio::SeqEvent::vfunc_1(int p) {
    Buf_25fd40 b;
    b.init_002634c0();
    u8_25fd40 r = FUN_00263500(p, &b);
    b.fini_00263d30();
    return r;
}
} // namespace fn_0025fd40

namespace fn_f3ff1114 {

// 0x0025fdd0 FUN_0025fdd0 (78 B): matches/0x0025fdd0.cpp
// sym: _FUN_0025fdd0
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_0025fdd0(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_25fdd0 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_25fdd0 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_25fdd0 *)tree)) = child;
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


// 0x0025fe20 FUN_0025fe20 (81 B): matches/0x0025fe20.cpp
// sym: ?swap_node@fn_f3ff1114@@YAXPAUTree_25fe20@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_25fe20* tree, Node* node) {
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


// 0x0025fe80 FUN_0025fe80 (55 B): matches/0x0025fe80.cpp
// sym: ?FUN_0025fe80@fn_f3ff1114@@YAPAUNode@1@PAU21@0@Z
Node* __cdecl FUN_0025fe80(Node* n, Node* x) {
    Node* p = (Node*)&n->parent;
    Node* a = x->parent;
    if (a != p) {
        while (a->left != p)
            a = a->left;
        return a;
    }
    a = x->right;
    while (a != p && x == a->parent) {
        x = a;
        a = a->right;
    }
    return a;
}


// 0x0025fec0 FUN_0025fec0 (604 B): equivalent/0x0025fec0.cpp
// sym: _FUN_0025fec0 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_0025fec0 @ 0x0025fec0
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_0025fec0(void * tree_, void * x_)
{
    RbTree_25fec0 * tree = (RbTree_25fec0 *)tree_;
    RbNode_25fec0 * x = (RbNode_25fec0 *)x_;
    RbNode_25fec0* nil = &tree->nil;
    RbNode_25fec0* y;
    RbNode_25fec0* z;
    RbNode_25fec0* p;
    RbNode_25fec0* c;

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

} // namespace fn_f3ff1114

// 0x00260120 audio::SeqEvent::vfunc_4 (31 B): matches/0x00260120.cpp
// sym: ?f2@NonCopyable@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

namespace fn_f3ff1114 {

// 0x002601d0 FUN_002601d0 (514 B): equivalent/0x002601d0.cpp
// sym: _FUN_002601d0 @c913194c1320 @w85a7b1e42798
// STATUS: equivalent (tools/equiv.py level 3: 3126 inputs, branch coverage 48/48)
// FUN_002601d0 @ 0x002601d0
// Unique-key insertion into a red-black tree keyed by string. Returns whether
// the element was inserted.
extern "C" char FUN_002601d0(void * tree_, void * elem_, void * key)
{
    OmTree * tree = (OmTree *)tree_;
    SeqEventTypeHead * elem = (SeqEventTypeHead *)elem_;
    Node_2601d0* x = &elem->node;
    Node_2601d0* nil = &tree->nil;
    Node_2601d0* cur = tree->root;
    Node_2601d0* parent = nil;

    while (cur != nil) {
        parent = cur;
        const char* a = ((String *)&entry_of(cur)->name)->FUN_0023fb00();
        const char* b = ((String *)key)->FUN_0023fb00();
        int cmp = 0;
        for (;;) {
            unsigned char cb = (unsigned char)*b;
            if (cb != (unsigned char)*a) {
                cmp = cb < (unsigned char)*a ? -1 : 1;
                break;
            }
            if (cb == 0)
                break;
            a++;
            b++;
        }
        if (cmp < 0)
            cur = cur->left;
        else if (cmp > 0)
            cur = cur->right;
        else
            return 0;
    }

    x->parent = parent;
    if (parent == nil) {
        tree->root = x;
    } else if (SeqEventTree_2601d0::FUN_0025fca0((String *)((String *)key), entry_of(parent)) < 0) {
        parent->left = x;
    } else {
        parent->right = x;
    }
    x->left = nil;
    x->right = nil;
    x->color = 1;

    while (x != tree->root && x->parent->color == 1) {
        Node_2601d0* p = x->parent;
        Node_2601d0* g = p->parent;
        if (p == g->left) {
            Node_2601d0* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == p->right) {
                    x = p;
                    SeqEventTree_2601d0::FUN_0025fdd0(tree, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                Node_2601d0* gp = x->parent->parent;
                Node_2601d0* top = gp->left;
                gp->left = top->right;
                if (top->right != &tree->nil)
                    top->right->parent = gp;
                top->parent = gp->parent;
                Node_2601d0* ggp = gp->parent;
                if (ggp == &tree->nil) {
                    tree->root = top;
                } else if (gp == ggp->left) {
                    ggp->left = top;
                } else {
                    ggp->right = top;
                }
                top->right = gp;
                gp->parent = top;
            }
        } else {
            Node_2601d0* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == p->left) {
                    x = p;
                    FUN_0025fe20(tree, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                Node_2601d0* gp = x->parent->parent;
                Node_2601d0* top = gp->right;
                gp->right = top->left;
                if (top->left != &tree->nil)
                    top->left->parent = gp;
                top->parent = gp->parent;
                Node_2601d0* ggp = gp->parent;
                if (ggp == &tree->nil) {
                    tree->root = top;
                } else if (gp == ggp->left) {
                    ggp->left = top;
                } else {
                    ggp->right = top;
                }
                top->left = gp;
                gp->parent = top;
            }
        }
    }
    tree->root->color = 0;
    return 1;
}


// 0x002603e0 FUN_002603e0 (182 B): equivalent/0x002603e0.cpp
// sym: _FUN_002603e0 @0e18f080af41 @w9c898005045a
// STATUS: equivalent (tools/equiv.py level 3: 2947 inputs, branch coverage 24/24)
// FUN_002603e0 @ 0x002603e0
// The tree of sequence event types (records.h: OmTree of SeqEventTypeHead entries).
extern "C" void __cdecl FUN_002603e0(void * tree_, void * item_) {
    OmTree * tree = (OmTree *)tree_;
    SeqEventTypeHead * item = (SeqEventTypeHead *)item_;
 Node_2603e0 *s = &item->node;
 Node_2603e0 *nil = &tree->nil;
 Node_2603e0 *n;
 if (s->left != nil && s->right != nil) n = FUN_0025fe80(tree,s);
 else n = s;
 Node_2603e0 *child = n->left;
 if (child == nil) child = n->right;
 child->parent = n->parent;
 Node_2603e0 *p = n->parent;
 if (p == nil) tree->root = child;
 else if (p->left == n) p->left = child;
 else p->right = child;
 bool black = n->color == 0;
 if (n != s) {
 n->parent = s->parent;
 n->left = s->left;
 n->right = s->right;
 n->color = s->color;
 p = n->parent;
 if (p == nil) tree->root = n;
 else if (p->left == s) p->left = n;
 else p->right = n;
 Node_2603e0 *l = n->left;
 if (l != nil) l->parent = n;
 Node_2603e0 *r = n->right;
 if (r->parent != nil) r->parent = n;
 }
 if (black) SeqEventTree_2603e0::FUN_0025fec0((OmTree *)tree,(Node_2603e0 *)child);
}


// 0x002604d0 FUN_002604d0 (74 B): matches/0x002604d0.cpp
// sym: ?FUN_002604d0@fn_f3ff1114@@YAPAUEntry@1@PAUHead@1@PAU21@@Z
Entry* __cdecl FUN_002604d0(Head* head, Entry* entry) {
    Node* previous = &entry->node;
    Node* current = previous->parent;
    Node* end = &head->sentinel;
    if (current != end) {
        while (current->left != end)
            current = current->left;
    } else {
        Node* child = previous->right;
        if (child == end)
            return 0;
        do {
            if (previous != child->parent)
                break;
            previous = child;
            child = child->right;
        } while (child != end);
        current = child;
    }
    return current == end ? 0 : (Entry*)((char*)current - 0x48);
}

} // namespace fn_f3ff1114

// 0x00260520 FUN_00260520 (111 B): equivalent/0x00260520.cpp [wrapped: conflict: Node]
// sym: ?FUN_00260520@fn_00260520@@YAPAUItem_260520@1@PAUTree_260520@1@H@Z @4b6e750e6107 @wa5f6cbf7d27a
namespace fn_00260520 {
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 24/24)
// FUN_00260520 @ 0x00260520
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree_260520 {
    Node *root;
    Node nil;
};

struct Item_260520 {
    char pad[0x48];
    Node node;
};

static __forceinline Item_260520 *ItemOf(Node *n)
{
    return (Item_260520 *)((char *)n - 0x48);
}

Item_260520 *FUN_00260520(Tree_260520 *tree, int steps)
{
    Node *nil = &tree->nil;
    Node *node = tree->root;
    Item_260520 *item;
    if (node == nil) {
        item = 0;
    } else {
        while (node->left != nil)
            node = node->left;
        item = ItemOf(node);
    }
    for (; steps != 0; steps--) {
        node = &item->node;
        Node *next = node->right;
        if (next == nil) {
            next = node->parent;
            while (next != nil && node == next->right) {
                node = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        item = (next == nil) ? 0 : ItemOf(next);
    }
    return item;
}
} // namespace fn_00260520

namespace fn_f3ff1114 {

// 0x00260590 FUN_00260590 (74 B): equivalent/0x00260590.cpp
// sym: _FUN_00260590 @7de2dfd68a4a @wfb162e91e198
// STATUS: equivalent (tools/equiv.py level 3: 1411 inputs, branch coverage 7/7)
// FUN_00260590 @ 0x00260590
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from list->head), so the search never runs and prev is always 0.
// equiv-dead: +0x1a not taken, +0x26 taken, +0x26 not taken, +0x2a taken, +0x2a not taken: node is always the head
extern "C" void FUN_00260590(List* list)
{
    for (;;) {
        Link* node = list->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 4);
        if (item == 0)
            return;
        list->head = node->next;
        if (node->next == 0)
            list->tail = 0;
        item->Destroy(1);
    }
}

} // namespace fn_f3ff1114

// 0x002605e0 FUN_002605e0 (150 B): equivalent/0x002605e0.cpp [wrapped: conflict: audio::SeqEventType; om::Type]
// sym: ?FUN_002605e0@SeqEventType@audio@fn_002605e0@@QAEPAV123@PBDPAXHH@Z @a51067cb3e5b @w5d2298630b2f
inline void *operator new(size_t, void *p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002605e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_002605e0 @ 0x002605e0
// audio::SeqEventType constructor: base type registration, own vtable, then insertion into the global type tree.
// equiv-map: ??0FUN_002584d0@@QAE@PAUKey_2605e0@@PAXHH@Z = 0x002584d0
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



struct Key_2605e0 {
    unsigned int lo, hi;
};

struct String {
    void FUN_00240170(const char *s);
};

extern "C++" __declspec(nothrow) char __cdecl FUN_002601d0(void *, void *, void *);


namespace om {
class Type {
public:
    virtual void v0();
    unsigned int reserved04;   // records.h OmType
    OmTypeBody body;
    Type() throw() {}
};
}
// om::Type's constructor (0x002584d0), on a stand-in class named by its address for the native links.
class FUN_002584d0 {
public:
    FUN_002584d0(Key_2605e0 *key, void *b, int c, int d) throw();
};

namespace audio {
class SeqEventType : public om::Type {
public:
    virtual void v0();
    OmTreeNode node;   // records.h SeqEventTypeHead: the node, then the name
    OmString name;
    SeqEventType() throw() {}
    SeqEventType *FUN_002605e0(const char *name, void *b, int c, int d);
};

SeqEventType *SeqEventType::FUN_002605e0(const char *name, void *b, int c, int d)
{
    Key_2605e0 key;
    unsigned __int64 k = FUN_002672f0("Data_Sequence", 0, 0);
    key.lo = (unsigned int)k;
    key.hi = (unsigned int)(k >> 32);
    new (this) FUN_002584d0(&key, b, c, d);
    new (this) SeqEventType;
    ((String *)&this->name)->FUN_00240170(name);
    OmTree *tree = (*(OmTree**)&DAT_004cd380);
    if (DAT_004e7a18.count == 0 && tree) {
        OmTreeNode *nil = &tree->nil;
        nil->left = nil;
        tree->nil.right = nil;
        tree->nil.parent = nil;
        tree->nil.color = 0;
        tree->root = nil;
    }
    FUN_002601d0(tree, this, &this->name);
    DAT_004e7a18.count++;
    return this;
}
}
} // namespace fn_002605e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3ff1114 {

// 0x00260680 FUN_00260680 (51 B): matches/0x00260680.cpp
// sym: @FUN_00260680@4
// data: gCount_260680 = DAT_004e7a18.count
extern "C" void __fastcall FUN_00260680(Obj_260680* self) {
    void* p = (*(void**)&DAT_004cd380);
    self->vf = ((hulk_intptr)DAT_0042aa7c);
    FUN_002603e0(p, self);
    --DAT_004e7a18.count;
    ((owners::Str_240060 *)&((SeqEventTypeHead *)self)->name)->FUN_00240060();
    self->FUN_002580e0();
}

} // namespace fn_f3ff1114
