// STATUS: equivalent (tools/equiv.py level 3: 2578 inputs, branch coverage 55/56, incomplete)
// FUN_0025f450 @ 0x0025f450
extern "C" int __cdecl strcmp(const char *a, const char *b);

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

void __cdecl FUN_0025ec50(Tree *t, Node *n);
void __cdecl FUN_0025eca0(Tree *t, Node *n);

bool FUN_0025f450(Tree *t, Item *item, const char **pkey)
{
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
                    FUN_0025ec50(t, z);
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
