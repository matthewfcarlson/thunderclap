// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00256660..0x00257dd0 (kind game, layer engine, confidence high), dominant class audio::Sequence
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f06eb07d {
#define TREE_TU_END }
namespace fn_f06eb07d {} using namespace fn_f06eb07d;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f06eb07d {
struct Node {
  public:
    union { Node* a; Node* left; Node* next; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_256780 {
    Node* root;
};
struct Tree_2567d0 {
    Node* root;
    Node head;
};
struct Tree_256850 {
    Node* root;
};
struct Tree_2568a0 {
    Node* root;
    Node head;
};
struct RbNode_256940 {
    RbNode_256940* left;
    RbNode_256940* right;
    RbNode_256940* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_256940 {
    RbNode_256940* root;
    RbNode_256940 nil;
};
extern "C" char DAT_0042a600[];
struct Sub_256c80 {
    void Init_002607a0();
};
class SeqTrack {
  public:
    char pad[0x1c];
    SeqTrack* Build(unsigned char);
};
int __cdecl GetTrack_00262030();
void __cdecl Cleanup_00247550(int, SeqTrack*);
struct N_256e80 {
    N_256e80* next;
    N_256e80* l;
    N_256e80* r;
};
struct RbNode_256f10 {
    RbNode_256f10* left;
    RbNode_256f10* right;
    RbNode_256f10* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_256f10 {
    RbNode_256f10* root;
    RbNode_256f10 nil;
};
struct Container_257250 {
    char pad[0x44];
    Node* head;
    Node* FindLast();
};
extern int __cdecl helper_00256e80(void*, unsigned int);
struct Writer_257290 {
    char pad0[0x24];
    int indent;
};
struct Archive_257290 {
    Writer_257290* writer;
};
char FUN_00246f50(Writer_257290* writer, const char* fmt, ...);
struct Link_257290 {
    Link_257290* next;
};
class Track {
public:
    virtual char Write(Archive_257290* ar);
    char pad4[0x10];
};
class TrackItem : public Track, public Link_257290 {
};
class SeqTrackList {
public:
    char pad0[0x3c];
    Link_257290* first;

    bool FUN_00257290(Archive_257290* ar);
};
struct Stream_257410 {
    char pad0[0x24];
    int indent;
};
bool __cdecl FUN_00246f50(Stream_257410 *s, const char *fmt, ...);
} // namespace fn_f06eb07d
namespace audio {
struct Sequence_nv_257410 {
    bool FUN_00257320(Stream_257410 **w);
    bool FUN_00257290(Stream_257410 **w);
};
}
namespace fn_f06eb07d {
class Entity_257b00 {
  public:
    virtual void a();
    virtual void b();
};
void InitA_00256d40(void*);
void InitB_00257730(void*);
extern void* DAT_0042a640[];
void FUN_00256d40(void*);
void FUN_00257730(void*);
void FUN_00247550(void*, void*);
class Entity_257c90 {
  public:
    void* vptr;
    void Fin_00244f70();
};
class Sequence_257c90 : public Entity_257c90 {
  public:
    char pad[0x24];
    struct SB {
        char* p;
        char b[0x10];
        void Reset() { p = b; }
    } sb;
    char m3c[8];
    char m44[8];
    Sequence_257c90* f2(unsigned char flags);
};
class Entity_257d80 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Sequence_nv_257d80 {
    bool first_00257b30(hulk_intptr);
    bool second_00257ce0(hulk_intptr);
};
extern bool __cdecl check_0025abd0(int, int*);


// 0x00256660 FUN_00256660 (6 B): matches/0x00256660.cpp
// sym: _FUN_00256660
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7620: a static om type (records.h)
extern "C" int* FUN_00256660() {
    return &(*(int*)&DAT_004e7620);
}

} // namespace fn_f06eb07d

// 0x00256740 FUN_00256740 (55 B): matches/0x00256740.cpp [wrapped: conflict: Node]
// sym: ?fn@fn_00256740@@YAPAUNode@1@PAU21@0@Z
namespace fn_00256740 {
struct Node {
    Node* parent;
    Node* left;
    Node* right;
};
Node* __cdecl fn(Node* x, Node* y) {
    Node* end = (Node*)&x->left;
    Node* n = y->left;
    if (n != end) {
        while (n->parent != end)
            n = n->parent;
    } else {
        n = y->right;
        while (n != end && y == n->left) {
            y = n;
            n = n->right;
        }
    }
    return n;
}
} // namespace fn_00256740

namespace fn_f06eb07d {

// 0x00256780 FUN_00256780 (78 B): matches/0x00256780.cpp
// sym: ?insert@fn_f06eb07d@@YAXPAUTree_256780@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_256780* tree, Node* node) {
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


// 0x002567d0 FUN_002567d0 (81 B): matches/0x002567d0.cpp
// sym: ?swap_node@fn_f06eb07d@@YAXPAUTree_2567d0@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_2567d0* tree, Node* node) {
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


// 0x00256850 FUN_00256850 (78 B): matches/0x00256850.cpp
// sym: _FUN_00256850
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_00256850(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_256850 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_256850 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_256850 *)tree)) = child;
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


// 0x002568a0 FUN_002568a0 (81 B): matches/0x002568a0.cpp
// sym: ?swap_node@fn_f06eb07d@@YAXPAUTree_2567d0@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_2568a0* tree, Node* node) {
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


// 0x00256900 FUN_00256900 (55 B): matches/0x00256900.cpp
// sym: ?findNode@fn_f06eb07d@@YAPAUNode@1@PAU21@0@Z
Node* findNode(Node* base, Node* node) {
    Node* sentinel = (Node*)&base->parent;
    Node* p = node->parent;
    if (p != sentinel) {
        while (p->left != sentinel)
            p = p->left;
        return p;
    }
    p = node->right;
    while (p != sentinel && node == p->parent) {
        node = p;
        p = p->right;
    }
    return p;
}


// 0x00256940 FUN_00256940 (604 B): equivalent/0x00256940.cpp
// sym: _FUN_00256940 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00256940 @ 0x00256940
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00256940(void * tree_, void * x_)
{
    RbTree_256940 * tree = (RbTree_256940 *)tree_;
    RbNode_256940 * x = (RbNode_256940 *)x_;
    RbNode_256940* nil = &tree->nil;
    RbNode_256940* y;
    RbNode_256940* z;
    RbNode_256940* p;
    RbNode_256940* c;

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

} // namespace fn_f06eb07d

// 0x00256c20 FUN_00256c20 (92 B): matches/0x00256c20.cpp [wrapped: conflict: audio::SequenceType]
// sym: ??0SequenceType@audio@fn_00256c20@@QAE@XZ
namespace fn_00256c20 {
// data: Data_Sequence = DAT_0042a630, Sequence = DAT_0042a620

typedef unsigned __int64 U64_256c20;
extern "C" U64_256c20 __cdecl FUN_002672f0(const char*, int, int);
class FUN_00243310 {
  public:
    FUN_00243310(const U64_256c20&, const U64_256c20&, int, int, int);
    virtual void f();
};
namespace audio {
class SequenceType : public FUN_00243310 {
  public:
    SequenceType();
    virtual void f();
};
} // namespace audio
audio::SequenceType::SequenceType()
    : FUN_00243310(FUN_002672f0(DAT_0042a620, 0, 0), FUN_002672f0(DAT_0042a630, 0, 0), 0x1000001, (int)sizeof(AudioSequence), 8) { HULK_SIZE32(AudioSequence, 0x58); }
} // namespace fn_00256c20

namespace fn_f06eb07d {

// 0x00256c80 FUN_00256c80 (45 B): matches/0x00256c80.cpp
// sym: ?Build@SeqTrack@fn_f06eb07d@@QAEPAV12@E@Z
SeqTrack* SeqTrack::Build(unsigned char flags) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042a600);
    ((Sub_256c80*)((char*)this + 0x1c))->Init_002607a0();
    if (flags & 1)
        Cleanup_00247550(GetTrack_00262030(), this);
    return this;
}

} // namespace fn_f06eb07d

// 0x00256d40 FUN_00256d40 (93 B): equivalent/0x00256d40.cpp [wrapped: conflict: DAT_0042a600]
// sym: ?FUN_00256d40@fn_00256d40@@YAXPAUList@1@@Z @e6f42b49c12e @w3b15a654acc6
namespace fn_00256d40 {
// STATUS: equivalent (tools/equiv.py level 3: 16597 inputs, branch coverage 8/8)
// FUN_00256d40 @ 0x00256d40
struct Tail { void FUN_002607a0(); };
struct Link { Link *next; Link *previous; };
struct SeqTrack {
    void *vptr;
    char reserved[0x10];
    Link link;
    Tail tail;
};
struct List { Link *first; Link *last; };
extern void *DAT_0042a600[];
void * __cdecl FUN_00262030(SeqTrack *track);
void __cdecl FUN_00247550(void *pool, void *p);  // the pool release: two words (as its other callers)
void __cdecl FUN_00256d40(List *list) {
    while (list->first) {
        Link *link = list->first;
        SeqTrack *track = (SeqTrack *)((char *)link - 0x14);
        if (!track) break;
        if (link->previous) link->previous->next = link->next;
        else list->first = link->next;
        if (link->next) link->next->previous = link->previous;
        else list->last = link->previous;
        track->vptr = DAT_0042a600;
        track->tail.FUN_002607a0();
        // the original pushes track for FUN_00262030 and leaves it as the release's second word (one `add esp, 8`)
        FUN_00247550(FUN_00262030(track), track);
    }
}
} // namespace fn_00256d40


// 0x00256da0 FUN_00256da0 (178 B): matches/0x00256da0.cpp [wrapped: conflict: Node]
// sym: _FUN_00256da0
namespace fn_00256da0 {
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
void* FUN_00256900(void*, void*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00256940(void *, void *);
extern "C" void FUN_00256da0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00256900(((Node *)tree), ((Node *)node));
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
        FUN_00256940(((Node *)tree), y);
}
} // namespace fn_00256da0

namespace fn_f06eb07d {

// 0x00256e80 FUN_00256e80 (75 B): matches/0x00256e80.cpp
// sym: _FUN_00256e80
extern "C" N_256e80* __cdecl FUN_00256e80(N_256e80* s, N_256e80* n) {
    N_256e80* x = n->l;
    N_256e80* end = (N_256e80*)((char*)s + 4);
    if (x != end) {
        while (x->next != end)
            x = x->next;
    } else {
        x = n->r;
        if (x != end) {
            do {
                if (n != x->l)
                    break;
                n = x;
                x = x->r;
            } while (x != end);
        }
    }
    return x == end ? 0 : x;
}


// 0x00256f10 FUN_00256f10 (604 B): equivalent/0x00256f10.cpp
// sym: ?FUN_00256f10@fn_f06eb07d@@YAXPAURbTree_256f10@1@PAURbNode_256f10@1@@Z @394c7c009b90 @wb8331f7a823d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00256f10 @ 0x00256f10
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
void FUN_00256f10(RbTree_256f10* tree, RbNode_256f10* x)
{
    RbNode_256f10* nil = &tree->nil;
    RbNode_256f10* y;
    RbNode_256f10* z;
    RbNode_256f10* p;
    RbNode_256f10* c;

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


// 0x00257200 audio::Sequence::vfunc_8 (6 B): matches/0x00257200.cpp
// sym: _FUN_00257200
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7620: a static om type (records.h)
extern "C" int* FUN_00257200() {
    return &(*(int*)&DAT_004e7620);
}


// 0x00257250 FUN_00257250 (28 B): matches/0x00257250.cpp
// sym: ?FindLast@Container_257250@fn_f06eb07d@@QAEPAUNode@2@XZ
Node* Container_257250::FindLast() {
    Node* p = head;
    Node* sentinel = (Node*)((char*)this + 0x48);
    if (p == sentinel)
        return 0;
    while (p->next != sentinel)
        p = p->next;
    return p;
}

} // namespace fn_f06eb07d

// 0x00257270 FUN_00257270 (20 B): matches/0x00257270.cpp
// sym: ?FUN_00257270@C_257270@owners@@QAEHI@Z
hulk_intptr owners::C_257270::FUN_00257270(hulk_uintptr x) {
    return helper_00256e80((char*)this + 0x44, ((unsigned int)x));
}

namespace fn_f06eb07d {

// 0x00257290 FUN_00257290 (141 B): equivalent/0x00257290.cpp
// sym: ?FUN_00257290@SeqTrackList@fn_f06eb07d@@QAE_NPAUArchive_257290@2@@Z @99ffa7799b9b @wc80bac8810f4
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 14/14)
// FUN_00257290 @ 0x00257290
// Write the "mSeqTrackList" block: every track in the linked list, one per line.
bool SeqTrackList::FUN_00257290(Archive_257290* ar)
{
    if (!FUN_00246f50(ar->writer, "mSeqTrackList\n[\n")) {
        return false;
    }
    ar->writer->indent++;
    for (TrackItem* track = static_cast<TrackItem*>(first); track != 0; track = static_cast<TrackItem*>(track->next)) {
        if (!track->Write(ar)) {
            return false;
        }
        if (!FUN_00246f50(ar->writer, "\n")) {
            return false;
        }
    }
    ar->writer->indent--;
    return FUN_00246f50(ar->writer, "]\n") != 0;
}

} // namespace fn_f06eb07d

// 0x00257320 FUN_00257320 (226 B): equivalent/0x00257320.cpp [wrapped: conflict: Node]
// sym: ?FUN_00257320@Owner_257320@fn_00257320@@QAE_NPCRAUOutput_257320@2@@Z @f887bf3b1c8a @wfbd1db47db27
namespace fn_00257320 {
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 28/28)
// FUN_00257320 @ 0x00257320
struct Output_257320 { char pad[0x24]; volatile int depth; };
extern int __cdecl FUN_00246f50(Output_257320*, const char*, ...);
struct Text_257320 { const char* FUN_0023fb00(); };
struct Node { Node* volatile left; Node* volatile right; Node* volatile parent; Text_257320* FUN_0024c710(); };
struct Owner_257320 { char pad[0x44]; Node* volatile root; Node sentinel; bool FUN_00257320(Output_257320* volatile* output); };
bool Owner_257320::FUN_00257320(Output_257320* volatile* output) {
 if (!(unsigned char)FUN_00246f50(*output, "mBussList\n[\n")) return false;
 ++(*output)->depth;
 Node* end = &sentinel;
 Node* volatile node = root;
 if (node == end) node = 0;
 else { Node* left = node->left; while (left != end) { node = left; left = node->left; } }
 while (node) {
  Output_257320* stream = *output;
  Text_257320* text = node->FUN_0024c710();
  const char* name = text->FUN_0023fb00();
  if (!(unsigned char)FUN_00246f50(stream, "\"%s\"\n", name)) return false;
  Node* next = node->right;
  if (next != end) {
   Node* left = next->left;
   while (left != end) { next = left; left = next->left; }
  } else {
   Node* child = node;
   next = node->parent;
   while (next != end && child == next->right) {
    child = next;
    next = next->parent;
   }
  }
  node = next == end ? 0 : next;
 }
 --(*output)->depth;
 return (unsigned char)FUN_00246f50(*output, "]\n") != 0;
}
} // namespace fn_00257320


// 0x00257410 audio::Sequence::vfunc_3 (118 B): equivalent/0x00257410.cpp
// sym: ?vfunc_3@Sequence@audio@@UAE_NPAX@Z @dcc11bb2fc42 @wa7a19b9f8b9a
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// audio::Sequence::vfunc_3 @ 0x00257410
bool audio::Sequence::vfunc_3(void* __p0) { Stream_257410 ** w = (Stream_257410 **)__p0;

    if (!FUN_00246f50(*w, "Version %d\n", 1))
        return false;
    if (!FUN_00246f50(*w, "[\n"))
        return false;
    (*w)->indent++;
    if (!((Sequence_nv_257410*)this)->FUN_00257320(w))
        return false;
    if (!((Sequence_nv_257410*)this)->FUN_00257290(w))
        return false;
    (*w)->indent--;
    if (!FUN_00246f50(*w, "]\n"))
        return false;
    return true;
}


// 0x00257560 FUN_00257560 (451 B): equivalent/0x00257560.cpp [wrapped: conflict: Node]
// sym: _FUN_00257560 @c7c7ca1bbb53 @we4f9ea90325d
namespace fn_00257560 {
// STATUS: equivalent (tools/equiv.py level 3: 193 inputs, branch coverage 39/40, incomplete)
// FUN_00257560 @ 0x00257560
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    char pad[36];
    unsigned key;
};

struct Tree_257560 {
    Node* root;
    Node nil;
};

struct Holder_257560 {
    int prefix;
    Node node;
};

extern "C" void FUN_00256780(Tree_257560* tree, Node* node);
extern "C" void FUN_002567d0(Tree_257560* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_00257560(void * tree_, void * nodeArg_, const unsigned* keyPtr)
{
    Tree_257560 * tree = (Tree_257560 *)tree_;
    Holder_257560 * nodeArg = (Holder_257560 *)nodeArg_;
    Node* nil = &tree->nil;
    Node* node = &nodeArg->node;
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
                    FUN_00256780(tree, node);
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
                    FUN_002567d0(tree, node);
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
} // namespace fn_00257560


// 0x00257730 FUN_00257730 (67 B): equivalent/0x00257730.cpp [wrapped: conflict: List]
// sym: ?FUN_00257730@fn_00257730@@YAXPAUList@1@@Z @a809ed1d4652 @wfc2092ed5934
namespace fn_00257730 {
// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 6/6)
// FUN_00257730 @ 0x00257730

struct Node { Node* next; }; struct List { Node* head; Node sentinel; }; extern "C++" __declspec(nothrow) void __cdecl FUN_00256da0(void *, void *); void __cdecl FUN_00247550(void*,Node*);  void __cdecl FUN_00257730(List* list) { while (list->head != &list->sentinel) { Node* node = list->head; while (node->next != &list->sentinel) node = node->next; FUN_00256da0((List *)list,(Node *)node); FUN_00247550(((char*)&DAT_004e7690),node); } }
} // namespace fn_00257730


// 0x00257780 FUN_00257780 (451 B): equivalent/0x00257780.cpp [wrapped: conflict: Node]
// sym: _FUN_00257780 @3da1263fa036 @wf9b0fecdcda2
namespace fn_00257780 {
// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 37/40, incomplete)
// FUN_00257780 @ 0x00257780
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    unsigned key;
};

struct Tree_257780 {
    Node* root;
    Node nil;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_00256850(void *, void *);
extern "C" void FUN_002568a0(Tree_257780* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_00257780(void * tree_, void * nodeArg, const unsigned* keyPtr)
{
    Tree_257780 * tree = (Tree_257780 *)tree_;
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
                    FUN_00256850((Tree_257780 *)tree, (Node *)node);
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
                    FUN_002568a0(tree, node);
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
} // namespace fn_00257780


// 0x00257980 audio::SequenceType::vfunc_2 (91 B): equivalent/0x00257980.cpp [wrapped: conflict: audio::Sequence; audio::SequenceType; om::EntityType]
// sym: ?vfunc_2@SequenceType@audio@fn_00257980@@UAEPAUSequence@23@XZ @db38185f666e @waf555c2c7a10
__forceinline void* operator new(size_t, void* p) { return p; }
namespace fn_00257980 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 2/2)
// audio::SequenceType::vfunc_2 @ 0x00257980

/* size_t: tree_prelude.h */
void* __cdecl FUN_00247530(void*);
namespace om { struct EntityType { virtual void vfunc_0(); virtual void vfunc_1(); }; }
namespace audio {
struct Sequence : om::EntityType {
    virtual void vfunc_2();
    char pad[0x24];
    void* firstEntry;
    void* firstAnchor;
    void* firstHead;
    void* firstTail;
    int firstCount;
    int field3c;
    int field40;
    void* secondEntry;
    void* secondAnchor;
    void* secondHead;
    void* secondTail;
    int secondCount;
};
struct SequenceType : om::EntityType { virtual Sequence* vfunc_2(); };
}
struct Sequence_257980 { void FUN_00244ea0(void*); };

audio::Sequence* audio::SequenceType::vfunc_2() {
    audio::Sequence* result = (audio::Sequence*)FUN_00247530(((char*)((char*)&DAT_004e7620)));
    if (result) {
        ((Sequence_257980*)result)->FUN_00244ea0(((char*)((char*)&DAT_004e7620)));
        result = new (result) audio::Sequence;
        result->firstCount = 0;
        result->firstHead = &result->firstAnchor;
        result->firstTail = &result->firstAnchor;
        result->firstEntry = &result->firstAnchor;
        result->firstAnchor = &result->firstAnchor;
        result->field3c = 0;
        result->field40 = 0;
        result->secondCount = 0;
        result->secondHead = &result->secondAnchor;
        result->secondTail = &result->secondAnchor;
        result->secondEntry = &result->secondAnchor;
        result->secondAnchor = &result->secondAnchor;
    }
    return result;
}
} // namespace fn_00257980


// 0x002579f0 FUN_002579f0 (44 B): matches/0x002579f0.cpp [wrapped: conflict: audio::Sequence; om::Entity]
// sym: ??1Sequence@audio@fn_002579f0@@UAE@XZ
namespace fn_002579f0 {
namespace om {
class Entity {
  public:
    virtual ~Entity() throw();
    char pad[0x24];
};
} // namespace om
extern char g_pool_2579f0[];
void Release2(void*, void*) throw();
void F1_00256d40(void*) throw();
void F2_00257730(void*) throw();
namespace audio {
class Sequence : public om::Entity {
  public:
    struct SB {
        char* p;
        char b[0x10];
        void Reset() { p = b; }
    } sb;
    char m3c[8];
    char m44[8];
    virtual ~Sequence() throw();
    static void operator delete(void* p) { Release2(g_pool_2579f0, p); }
};
Sequence::~Sequence() throw() {
    sb.Reset();
    F1_00256d40(m3c);
    F2_00257730(m44);
}
} // namespace audio
} // namespace fn_002579f0


// 0x00257b00 audio::Sequence::vfunc_4 (46 B): matches/0x00257b00.cpp
// sym: ?vfunc_4@Sequence@audio@@UAE_NH@Z
bool audio::Sequence::vfunc_4(int __p0) { unsigned int p = (unsigned int)__p0;

    *(void**)((char*)this + 0x28) = (char*)this + 0x2c;
    InitA_00256d40((char*)this + 0x3c);
    InitB_00257730((char*)this + 0x44);
    return (bool)(vfunc_5(p));
}


// 0x00257b30 FUN_00257b30 (234 B): equivalent/0x00257b30.cpp [wrapped: conflict: FUN_00247530]
// sym: ?target@Owner_257b30@fn_00257b30@@QAE_NPAX@Z @79bd5499b1eb @wd189bbfc99b6
namespace fn_00257b30 {
// STATUS: equivalent (tools/equiv.py level 3: 373 inputs, branch coverage 11/12, incomplete)
// FUN_00257b30 @ 0x00257b30

struct Text_257b30 { char data[12]; void FUN_0023fac0(); const char* FUN_0023fb00();  };
struct Entry_257b30 { char pad[16]; void* name; };
struct List_257b30 { char opaque; };
extern bool __cdecl FUN_0025abd0(void*, unsigned*);
extern Entry_257b30* __cdecl FUN_00247530(void*);
extern "C" void* __cdecl FUN_002673a0(const char*, int);
extern "C" bool __cdecl FUN_0025bce0(void*, Text_257b30*);
extern "C++" __declspec(nothrow) char __cdecl FUN_00257780(void *, void *, const unsigned *);
extern void __cdecl FUN_00247550(void*, Entry_257b30*);
struct Owner_257b30 { char pad[0x44]; List_257b30 list; bool target(void*); };
bool Owner_257b30::target(void* input) {
 unsigned count;
 if (!FUN_0025abd0(input, &count)) return false;
 for (unsigned i=0; i<count; ++i) {
  Entry_257b30* item = FUN_00247530(((char*)&DAT_004e7690));
  if (item) item->name = FUN_002673a0("MyBuss",0);
  Text_257b30 text;
  text.FUN_0023fac0();
  bool ok = FUN_0025bce0(input,&text);
  void** slot = &item->name;
  if (slot) *slot = FUN_002673a0(text.FUN_0023fb00(),0);
  ((owners::Str_240060 *)&text)->FUN_00240060();
  if (!ok) { FUN_00247550(((char*)&DAT_004e7690),item); return false; }
  FUN_00257780((List_257b30 *)(&list),(Entry_257b30 *)item,(const unsigned *)(void * *)slot);
 }
 return true;
}
} // namespace fn_00257b30


// 0x00257c20 FUN_00257c20 (99 B): matches/0x00257c20.cpp [wrapped: merged class would differ: Item_257c20: field n: Field(+0x14 Node n) vs Field(+0x14 Node n)]
// sym: ?Fn@L_257c20@fn_00257c20@@QAEDPAUItem_257c20@2@@Z
namespace fn_00257c20 {
struct Node {
    Node* next;
    Node* prev;
};
struct Item_257c20 {
    char pad[0x14];
    Node n;
    char pad2[0x38 - 0x1c];
    int x;
};
struct L_257c20 {
    char pad[0x28];
    char s[0x3c - 0x28];
    Node* head;
    Node* tail;
    char Fn(Item_257c20* i);
};
extern "C++" __declspec(nothrow) char __cdecl FUN_00257560(void *, void *, const unsigned *);
char L_257c20::Fn(Item_257c20* i) {
    if (FUN_00257560(&s, (Item_257c20 *)i, (const unsigned *)(int *)(&i->x))) {
        Node* n = &i->n;
        if (head == 0) {
            head = n;
            n->prev = 0;
            tail = n;
            n->next = 0;
            return 1;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
        n->next = 0;
        return 1;
    }
    return 0;
}
} // namespace fn_00257c20

namespace fn_f06eb07d {

// 0x00257c90 audio::Sequence::vfunc_2 (70 B): matches/0x00257c90.cpp
// sym: ?f2@Sequence_257c90@fn_f06eb07d@@QAEPAV12@E@Z
Sequence_257c90* Sequence_257c90::f2(unsigned char flags) {
    vptr = DAT_0042a640;
    sb.Reset();
    FUN_00256d40(m3c);
    FUN_00257730(m44);
    Fin_00244f70();
    if (flags & 1)
        FUN_00247550(((char*)((char*)&DAT_004e7620)), this);
    return this;
}

} // namespace fn_f06eb07d

// 0x00257ce0 FUN_00257ce0 (155 B): equivalent/0x00257ce0.cpp [wrapped: conflict: FUN_00247530; audio::SeqTrack]
// sym: ?FUN_00257ce0@Mix@fn_00257ce0@@QAE_NTStreamArg_257ce0@2@@Z @b18a9c4d50e2 @w59cfd236bce9
namespace fn_00257ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 407 inputs, branch coverage 10/10)
// FUN_00257ce0 @ 0x00257ce0
struct Stream;
struct Sub_257ce0 { char data[4]; void FUN_002607a0(); };

namespace audio {
class SeqTrack {
public:
    virtual ~SeqTrack() throw() { sub.FUN_002607a0(); }
    virtual bool vfunc_1(Stream *s);
    char pad04[0x18];
    Sub_257ce0 sub;
};
}

struct SeqTrack_257ce0 { audio::SeqTrack *FUN_00262090(); };
void *__cdecl FUN_00262030();
SeqTrack_257ce0 *__cdecl FUN_00247530(void *pool);
void __cdecl FUN_00247550(void *pool, audio::SeqTrack *t);
bool __cdecl FUN_0025abd0(Stream *s, unsigned int *count);

// The stream pointer's stack slot doubles as the out-count.
union StreamArg_257ce0 {
    Stream *stream;
    unsigned int count;
};

class Mix {
public:
    void FUN_00257c20(audio::SeqTrack *t);
    bool FUN_00257ce0(StreamArg_257ce0 arg);
};

bool Mix::FUN_00257ce0(StreamArg_257ce0 arg)
{
    Stream *s = arg.stream;
    if (!FUN_0025abd0(s, &arg.count))
        return false;
    for (unsigned int i = 0; i < arg.count; i++) {
        SeqTrack_257ce0 *p = FUN_00247530(FUN_00262030());
        audio::SeqTrack *t = p ? p->FUN_00262090() : 0;
        if (!t->vfunc_1(s)) {
            t->audio::SeqTrack::~SeqTrack();
            FUN_00247550(FUN_00262030(), t);
            return false;
        }
        FUN_00257c20(t);
    }
    return true;
}
} // namespace fn_00257ce0


// 0x00257d80 audio::Sequence::vfunc_5 (71 B): matches/0x00257d80.cpp
// sym: ?vfunc_5@Sequence@audio@@UAE_NH@Z
bool audio::Sequence::vfunc_5(hulk_intptr x) {
    int t;
    if (check_0025abd0(x, &t) && t == 1 && ((Sequence_nv_257d80*)this)->first_00257b30(x) && ((Sequence_nv_257d80*)this)->second_00257ce0(x))
        return true;
    return false;
}

