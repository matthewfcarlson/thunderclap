// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00259d30..0x0025aa50 (kind game, layer engine, confidence high), dominant class audio::Mix
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_fac3e8a6 {
#define TREE_TU_END }
namespace fn_fac3e8a6 {} using namespace fn_fac3e8a6;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fac3e8a6 {
struct Node {
  public:
    union { Node* a; Node* left; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_259d30 {
    Node* root;
};
struct Tree_259d80 {
    Node* root;
    Node head;
};
struct Tree {
    char pad[4];
    Node sentinel;
};
struct RbNode_259e20 {
    RbNode_259e20* left;
    RbNode_259e20* right;
    RbNode_259e20* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_259e20 {
    RbNode_259e20* root;
    RbNode_259e20 nil;
};
struct Ctrl;
struct Actor_25a0b0 {
    char pad00[0x24];
    Ctrl *ctrl;             // 0x24
    char pad28[0xc];
    int state;              // 0x34
};
extern "C" int __cdecl FUN_002416f0(Ctrl *ctrl, Actor_25a0b0 *actor);
extern "C" void __cdecl FUN_002416c0(Ctrl *ctrl, Actor_25a0b0 *actor, int arg);
extern "C" int __cdecl FUN_00267f80();
extern "C" void __cdecl FUN_00243090(Ctrl *ctrl, float dt);
extern "C" hulk_intptr __cdecl GetThing() throw();
extern "C" void __cdecl Func_00257dd0(void*) throw();
class Entity_25a2c0 {
  public:
    Entity_25a2c0(int) throw();
    virtual void a();
    char pad[0x24];
};
struct Init0 {
    char m28[8];
};
struct Init1_25a2c0 {
    Init1_25a2c0() throw() {
        m30 = 1000;
        m34 = 1000;
    }
    int m30, m34;
};
class Mix : public Entity_25a2c0, public Init0, public Init1_25a2c0 {
  public:
    Mix() throw();
    virtual void a();
    void* p38;
    void* p3c;
    void* p40;
    void* p44;
    int m48;
};
struct BussData {
    char reserved[0x24];
    int nameCount;
};
unsigned int __cdecl FUN_00246f50(BussData *data, const char *format, ...);
extern "C" bool FUN_0024f010(void*, void*);
extern "C" bool FUN_0025ac10(void*, void*);
extern "C" bool FUN_0025aa80(void*, void*);


// 0x00259d30 FUN_00259d30 (78 B): matches/0x00259d30.cpp
// sym: _FUN_00259d30
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_00259d30(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_259d30 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_259d30 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_259d30 *)tree)) = child;
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


// 0x00259d80 FUN_00259d80 (81 B): matches/0x00259d80.cpp
// sym: ?swap_node@fn_fac3e8a6@@YAXPAUTree_259d80@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_259d80* tree, Node* node) {
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


// 0x00259de0 FUN_00259de0 (55 B): matches/0x00259de0.cpp
// sym: ?FUN_00259de0@fn_fac3e8a6@@YAPAUNode@1@PAUTree@1@PAU21@@Z
Node* __cdecl FUN_00259de0(Tree* tree, Node* current) {
    Node* end = &tree->sentinel;
    Node* next = current->parent;
    if (next != end) {
        while (next->left != end)
            next = next->left;
        return next;
    }
    next = current->right;
    while (next != end && current == next->parent) {
        current = next;
        next = next->right;
    }
    return next;
}


// 0x00259e20 FUN_00259e20 (604 B): equivalent/0x00259e20.cpp
// sym: _FUN_00259e20 @394c7c009b90 @w3415c875f53d
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00259e20 @ 0x00259e20
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00259e20(void * tree_, void * x_)
{
    RbTree_259e20 * tree = (RbTree_259e20 *)tree_;
    RbNode_259e20 * x = (RbNode_259e20 *)x_;
    RbNode_259e20* nil = &tree->nil;
    RbNode_259e20* y;
    RbNode_259e20* z;
    RbNode_259e20* p;
    RbNode_259e20* c;

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


// 0x0025a0b0 FUN_0025a0b0 (130 B): equivalent/0x0025a0b0.cpp
// sym: _FUN_0025a0b0 @5fda08ea4099 @wec3968472520
// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 10/10)
// FUN_0025a0b0 @ 0x0025a0b0
extern "C" void FUN_0025a0b0(void *actor)
{
    int status = FUN_002416f0(((Actor_25a0b0 *)actor)->ctrl, ((Actor_25a0b0 *)actor));
    bool finishing = (status == 1 || status == 2);

    FUN_002416c0(((Actor_25a0b0 *)actor)->ctrl, ((Actor_25a0b0 *)actor), 0);
    int last = FUN_00267f80();

    while (status != 0) {
        int now = FUN_00267f80();
        FUN_00243090(((Actor_25a0b0 *)actor)->ctrl, (float)(now - last));
        status = FUN_002416f0(((Actor_25a0b0 *)actor)->ctrl, ((Actor_25a0b0 *)actor));
        last = now;
    }

    if (finishing)
        ((Actor_25a0b0 *)actor)->state = 2;
}

} // namespace fn_fac3e8a6

// 0x0025a160 FUN_0025a160 (182 B): equivalent/0x0025a160.cpp [wrapped: conflict: Node]
// sym: _FUN_0025a160 @e635e7c6d78b @w8eaf54682a6f
namespace fn_0025a160 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0025a160 @ 0x0025a160
struct Node { Node *left; Node *right; Node *parent; int color; };
struct Tree_25a160 { Node *root; Node sentinel; };
struct Entry_25a160 { int data; Node node; };
extern Node *__cdecl FUN_00259de0(Tree_25a160 *, Node *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00259e20(void *, void *);
extern "C" void __cdecl FUN_0025a160(void * tree_, void * entry_) {
    Tree_25a160 * tree = (Tree_25a160 *)tree_;
    Entry_25a160 * entry = (Entry_25a160 *)entry_;
    Node *node = &entry->node;
    Node *nil = &tree->sentinel;
    Node *removed;
    if (node->left != nil && node->right != nil)
        removed = FUN_00259de0(tree, node);
    else
        removed = node;
    Node *child = removed->left;
    if (child == nil) child = removed->right;
    child->parent = removed->parent;
    Node *parent = removed->parent;
    if (parent == nil) tree->root = child;
    else if (parent->left == removed) parent->left = child;
    else parent->right = child;
    bool black = removed->color == 0;
    if (removed != node) {
        removed->parent = node->parent;
        removed->left = node->left;
        removed->right = node->right;
        removed->color = node->color;
        parent = removed->parent;
        if (parent == nil) tree->root = removed;
        else if (parent->left == node) parent->left = removed;
        else parent->right = removed;
        if (removed->left != nil) removed->left->parent = removed;
        if (removed->right->parent != nil) removed->right->parent = removed;
    }
    if (black) FUN_00259e20((Tree_25a160 *)tree, (Node *)child);
}
} // namespace fn_0025a160


// 0x0025a220 FUN_0025a220 (78 B): equivalent/0x0025a220.cpp [wrapped: merged class would differ: List: field sentinel: Field(+0x4 Node sentinel) vs Field(+0x4 Node sentinel)]
// sym: _FUN_0025a220 @f1b1366e490a @w7ee3e07896e2
namespace fn_0025a220 {
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 8/8)
// FUN_0025a220 @ 0x0025a220
struct Node { Node *next; }; struct List { Node *first; Node sentinel; }; extern "C++" __declspec(nothrow) void __cdecl FUN_0025a160(void *, void *); void * __cdecl FUN_00241670(); void __cdecl FUN_00247550(void *, void *); extern "C" void __cdecl FUN_0025a220(void * list_) {
    List * list = (List *)list_; while (list->first != &list->sentinel) { Node *node = list->first; while (node->next != &list->sentinel) node = node->next; Node *item = (Node *)((char *)node - 4); if (!item) break; FUN_0025a160((List *)list,(Node *)item); FUN_00247550(FUN_00241670(), item); } }
} // namespace fn_0025a220

namespace fn_fac3e8a6 {

// 0x0025a2c0 FUN_0025a2c0 (70 B): matches/0x0025a2c0.cpp
// sym: ??0Mix@fn_fac3e8a6@@QAE@XZ
Mix::Mix() throw() : Entity_25a2c0(GetThing()) {
    _ReadWriteBarrier();
    void** e = &p3c;
    *e = e;
    p40 = e;
    p44 = e;
    p38 = e;
    m48 = 0;
    Func_00257dd0(m28);
}

// 0x0025a310 audio::Mix::vfunc_8 (5 B): not yet verified
} // namespace fn_fac3e8a6

// 0x0025a330 audio::MixBuss::vfunc_0 (61 B): equivalent/0x0025a330.cpp
// sym: ?vfunc_0@MixBuss@audio@@UAEHH@Z @9f7374968b9f @w0038bae0ef40
// STATUS: equivalent (tools/equiv.py level 3: 2886 inputs, branch coverage 2/2)
// audio::MixBuss::vfunc_0 @ 0x0025a330
int audio::MixBuss::vfunc_0(hulk_intptr __p0) { BussData ** data = (BussData **)__p0;

    unsigned int result = FUN_00246f50(*data, "[\n");
    if ((unsigned char)result != 0) {
        ++(*data)->nameCount;
        result = FUN_00246f50(*data, "%s ", "mName");
    }
    return (int)(result & 0xffffff00U);
}


// 0x0025a370 audio::MixBuss::vfunc_1 (127 B): matches/0x0025a370.cpp
// sym: ?vfunc_1@MixBuss@audio@@UAEHPAX@Z
int audio::MixBuss::vfunc_1(void* __p0) { void * p = (void *)__p0;

    if (FUN_0024f010(p, &this->f_14) && FUN_0025ac10(p, &this->f_18) && FUN_0025ac10(p, &this->f_1c) && FUN_0025ac10(p, &this->f_20) &&
        FUN_0025ac10(p, &this->f_24) && FUN_0025aa80(p, &this->f_28))
        return 1;
    return 0;
}


// 0x0025a3f0 audio::Mix::vfunc_3 (306 B): equivalent/0x0025a3f0.cpp [wrapped: conflict: Tree; audio::Mix]
// sym: ?vfunc_3@Mix@audio@fn_0025a3f0@@UAEDPAUArchive@3@@Z @50ba9984d8c5 @wb72251b439de
namespace fn_0025a3f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2648 inputs, branch coverage 38/38)
// audio::Mix::vfunc_3 @ 0x0025a3f0
struct Writer {
    char pad0[0x24];
    int indent;
};

struct Archive {
    Writer *writer;
};

char FUN_00246f50(Writer *writer, const char *fmt, ...);
extern "C" char FUN_0025abb0(Archive *ar, unsigned int value);
extern "C" char FUN_0024eb60(Archive *ar, const char *name, unsigned int *value);

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

struct MixChild {
    virtual char save(Archive *ar);
    TreeNode node;
};

struct Tree {
    TreeNode *root;
    TreeNode nil;
};

namespace audio {

class Mix {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(Archive *ar);
    char pad04[0x30 - 4];
    unsigned int fadeInTimeMs;
    unsigned int fadeOutTimeMs;
    Tree children;
};

char Mix::vfunc_3(Archive *ar)
{
    if (!FUN_00246f50(ar->writer, "Version %u\n", 1))
        return 0;
    if (!FUN_00246f50(ar->writer, "%s ", "mFadeInTimeMs"))
        return 0;
    if (!FUN_0025abb0(ar, fadeInTimeMs))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n"))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeOutTimeMs", &fadeOutTimeMs))
        return 0;
    if (!FUN_00246f50(ar->writer, "[\n"))
        return 0;

    ar->writer->indent++;

    TreeNode *nil = &children.nil;
    TreeNode *node = children.root;
    if (node != nil) {
        while (node->left != nil)
            node = node->left;
        MixChild *child = (MixChild *)((char *)node - 4);
        while (child != 0) {
            if (!child->save(ar))
                return 0;

            TreeNode *s = child->node.right;
            if (s == nil) {
                TreeNode *c = &child->node;
                s = c->parent;
                while (s != nil && c == s->right) {
                    c = s;
                    s = s->parent;
                }
            } else {
                while (s->left != nil)
                    s = s->left;
            }
            if (s == nil)
                break;
            child = (MixChild *)((char *)s - 4);
        }
    }

    ar->writer->indent--;
    return FUN_00246f50(ar->writer, "]\n") != 0;
}

}
} // namespace fn_0025a3f0


// 0x0025a530 audio::Mix::vfunc_4 (155 B): equivalent/0x0025a530.cpp [wrapped: merged class would differ: Mix: multiple bases]
// sym: ?vfunc_4@Mix@fn_0025a530@@UAE_NH@Z @83839a9f0f69 @w4b6de2f5008b
namespace fn_0025a530 {
// STATUS: equivalent (tools/equiv.py level 3: 192 inputs, branch coverage 10/10)
// audio::Mix::vfunc_4 @ 0x0025a530
struct Head_25a530 { char pad[0x10]; };
struct Link_25a530 { char data[0x14]; };
struct Track : Head_25a530, Link_25a530 {
    int f24;
    char pad28[0xc];
    int state;
};
struct List_25a530 { char data[0x10]; };
struct Other_25a530 { char data[4]; };

extern "C" Link_25a530 *__cdecl FUN_00257ec0(List_25a530 *list);
extern "C" Link_25a530 *__cdecl FUN_00257ee0(Link_25a530 *l);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025a0b0(void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025a220(void *);
extern "C" void __cdecl FUN_00242f60(int a, Track *t, int b);

class Mix {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual bool vfunc_4(int arg);
    virtual bool vfunc_5(int arg);
    char pad04[0x24];
    List_25a530 tracks;
    Other_25a530 other;
};

bool Mix::vfunc_4(int arg)
{
    for (Link_25a530 *l = FUN_00257ec0(&tracks); l != 0; l = FUN_00257ee0(l))
        FUN_0025a0b0((Track *)(static_cast<Track *>(l)));
    FUN_0025a220((Other_25a530 *)(&other));
    bool result = vfunc_5(arg);
    for (Link_25a530 *l = FUN_00257ec0(&tracks); l != 0; l = FUN_00257ee0(l)) {
        Track *t = static_cast<Track *>(l);
        if (t->state == 2) {
            t->state = 0;
            FUN_00242f60(t->f24, t, 0);
        }
    }
    return result;
}
} // namespace fn_0025a530


// 0x0025a610 FUN_0025a610 (451 B): equivalent/0x0025a610.cpp [wrapped: conflict: Node]
// sym: ?FUN_0025a610@fn_0025a610@@YADPAUTree_25a610@1@PAUHolder_25a610@1@PBI@Z @b001aa8b154d @wc8bbcb9e65e8
namespace fn_0025a610 {
// STATUS: equivalent (tools/equiv.py level 3: 169 inputs, branch coverage 39/40, incomplete)
// FUN_0025a610 @ 0x0025a610
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    unsigned key;
};

struct Tree_25a610 {
    Node* root;
    Node nil;
};

struct Holder_25a610 {
    int prefix;
    Node node;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_00259d30(void *, void *);
extern "C" void FUN_00259d80(Tree_25a610* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
char FUN_0025a610(Tree_25a610* tree, Holder_25a610* nodeArg, const unsigned* keyPtr)
{
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
                    FUN_00259d30((Tree_25a610 *)tree, (Node *)node);
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
                    FUN_00259d80(tree, node);
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
} // namespace fn_0025a610


// 0x0025a8c0 FUN_0025a8c0 (38 B): matches/0x0025a8c0.cpp [wrapped: conflict: Mix]
// sym: ?target@fn_0025a8c0@@YIXPAUMix@1@@Z
namespace fn_0025a8c0 {
extern "C" char DAT_0042a6e4[];
struct Mix {
    int pad[14];
    void Finish_00244f70();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0025a220(void *);
extern "C" void __cdecl FUN_00257df0(void*);
void __fastcall target(Mix* self) {
    self->pad[0] = ((hulk_intptr)DAT_0042a6e4);
    FUN_0025a220(&self->pad[14]);
    FUN_00257df0(&self->pad[10]);
    self->Finish_00244f70();
}
} // namespace fn_0025a8c0


// 0x0025a8f0 audio::Mix::vfunc_5 (266 B): equivalent/0x0025a8f0.cpp [wrapped: conflict: audio::Mix; audio::MixBuss]
// sym: ?vfunc_5@Mix@audio@fn_0025a8f0@@UAE_NPAX@Z @abdbda5f3186 @wda18b37df805
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_0025a8f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 20/20)
// audio::Mix::vfunc_5 @ 0x0025a8f0
typedef unsigned int uint;

extern "C" bool __cdecl FUN_0025abd0(void*, uint*);
extern void* __cdecl FUN_00241670();
extern "C" void* __cdecl FUN_00247530(void*);
namespace audio {
struct MixBuss {
 virtual int vfunc_0_0025a330(hulk_intptr); virtual bool vfunc_1(void*);
 char pad[0x14-4]; uint link; float volume,pitch; uint a,b; unsigned char flag;
};
struct Mix {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(void*);
 char pad[0x30-4]; uint a,b,list;
};
}
extern bool __cdecl FUN_0025a610(uint*, audio::MixBuss*, uint*);
bool audio::Mix::vfunc_5(void* stream) {
 uint version,count;
 if (!FUN_0025abd0(stream,&version) || version != 1) return false;
 if (!FUN_0025abd0(stream,&a)) return false;
 if (!FUN_0025abd0(stream,&b)) return false;
 if (!FUN_0025abd0(stream,&count)) return false;
 for(uint i=0;i<count;++i) {
 void* memory=FUN_00247530(FUN_00241670());
 MixBuss* buss=0;
 if(memory) {
 buss=new(memory) MixBuss;
 buss->volume=1.0f; buss->pitch=1.0f; buss->a=0; buss->b=0; buss->flag=0;
 }
 if(!buss->vfunc_1(stream)) return false;
 if(!FUN_0025a610(&list,buss,&buss->link)) return false;
 }
 return true;
}
} // namespace fn_0025a8f0


// 0x0025aa00 audio::Mix::vfunc_2 (65 B): matches/0x0025aa00.cpp [wrapped: merged class would differ: Mix: multiple bases]
// sym: ?f2@Mix@fn_0025aa00@@UAEPAV12@E@Z
namespace fn_0025aa00 {
extern char hulk_at_0042a6e4;
void f70();
class Mix {
  public:
    virtual void f0();
    virtual void f1();
    virtual Mix* f2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    OmTreeNode node;                        // records.h AudioMix (OmEntity's words, then the mix's) past the vftable
    unsigned int reserved14;
    OmKey key;
    unsigned short flags20;
    unsigned short refs;
    unsigned int reserved24;
    AudioList mixerMixes;
    int value30;
    int value34;
    AudioTree busses;
    void setup_00244f70();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0025a220(void *);
extern "C" void FUN_00257df0(void*);
int f660_00241660();
int f550_00247550(int, Mix*);
Mix* Mix::f2(unsigned char x) {
    *(void**)this = &hulk_at_0042a6e4;
    FUN_0025a220(&this->busses);
    FUN_00257df0(&this->mixerMixes);
    setup_00244f70();
    if (x & 1) {
        f550_00247550(f660_00241660(), this);
    }
    return this;
}
} // namespace fn_0025aa00

