// STATUS: equivalent (tools/equiv.py level 3: 822 inputs, branch coverage 54/56, incomplete)
// FUN_0025f170 @ 0x0025f170
#include "decls/data/records.h"
extern "C" int __cdecl strcmp(const char *a, const char *b);

// The tree of meta types (records.h's OmTree; 0x0025fa00 inserts each om::MetaType by its name).
static inline const char *key_of(OmTreeNode *n)
{
    return ((OmMetaType *)((char *)n - (hulk_intptr)&((OmMetaType *)0)->node))->name;
}

void __cdecl FUN_0025e900(OmTree *t, OmTreeNode *n);
void __cdecl FUN_0025e950(OmTree *t, OmTreeNode *n);

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
