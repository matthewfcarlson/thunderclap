// STATUS: equivalent (tools/equiv.py level 3: 3126 inputs, branch coverage 48/48)
// FUN_002601d0 @ 0x002601d0
#include "decls/data/records.h"
struct String {
    const char* FUN_0023fb00();
};

// The tree of sequence event types (records.h: OmTree, the entries SeqEventTypeHead, keyed by name).
typedef OmTreeNode Node_2601d0;
static inline SeqEventTypeHead* entry_of(Node_2601d0* n)
{
    return (SeqEventTypeHead*)((char*)n - (hulk_intptr)&((SeqEventTypeHead*)0)->node);
}

// C functions of this TU, declared at class scope (gen_tree gives TU-mates' extern "C" declarations of a merged C
// definition C++ linkage)
struct SeqEventTree_2601d0 {
    static int __cdecl FUN_0025fca0(void *, void *);
    static void __cdecl FUN_0025fdd0(void *, void *);
};
void FUN_0025fe20(OmTree* tree, Node_2601d0* x);

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
