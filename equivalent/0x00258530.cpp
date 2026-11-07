// STATUS: equivalent (tools/equiv.py level 3: 1132 inputs, branch coverage 51/52, incomplete)
// FUN_00258530 @ 0x00258530
#include "compat/ptr.h"
#include "decls/data/records.h"
// The tree of om types by key (records.h OmType: the type's node, keyed by its own key; the tree is the OmTree layout,
// 0x004cd1a8's has no count).

void __cdecl FUN_00258140(OmTree* tree, OmTreeNode* n);  // rotate left
void __cdecl FUN_00258190(OmTree* tree, OmTreeNode* n);  // rotate right

static inline const OmKey* KeyOf(const OmTreeNode* n)
{
    return &((const OmType*)((const char*)n - (hulk_intptr) & ((OmType*)0)->body.node))->body.key;
}

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
