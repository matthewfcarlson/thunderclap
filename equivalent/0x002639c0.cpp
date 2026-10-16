// STATUS: equivalent (tools/equiv.py level 3: 1180 inputs, branch coverage 39/52, incomplete)
// FUN_002639c0 @ 0x002639c0
struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int color;
    char pad10[8];
    unsigned keyLo;
    unsigned keyHi;
};

struct Tree {
    Node *root;
    Node nil;
};

struct Key {
    unsigned lo;
    unsigned hi;
};

void FUN_002635a0(Tree *t, Node *x);
void FUN_002635f0(Tree *t, Node *x);

char FUN_002639c0(Tree *t, Node *n, Key *k)
{
    Node *nil = &t->nil;
    Node *x = t->root;
    Node *p = nil;
    unsigned lo = k->lo;
    unsigned hi = k->hi;

    while (x != nil) {
        p = x;
        if (hi < x->keyHi || (hi == x->keyHi && lo < x->keyLo)) {
            x = x->left;
        } else if (hi > x->keyHi || lo > x->keyLo) {
            x = x->right;
        } else {
            return 0;
        }
    }

    n->parent = p;
    if (p == nil) {
        t->root = n;
    } else if (k->hi > p->keyHi || (k->hi == p->keyHi && k->lo >= p->keyLo)) {
        p->right = n;
    } else {
        p->left = n;
    }

    n->left = nil;
    n->right = nil;
    n->color = 1;

    while (n != t->root && n->parent->color == 1) {
        Node *par = n->parent;
        Node *gp = par->parent;
        if (par == gp->left) {
            Node *u = gp->right;
            if (u->color == 1) {
                par->color = 0;
                u->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == par->right) {
                    n = par;
                    FUN_002635a0(t, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                Node *g = n->parent->parent;
                Node *y = g->left;
                g->left = y->right;
                if (y->right != nil)
                    y->right->parent = g;
                y->parent = g->parent;
                Node *gg = g->parent;
                if (gg == nil)
                    t->root = y;
                else if (g == gg->left)
                    gg->left = y;
                else
                    gg->right = y;
                y->right = g;
                g->parent = y;
            }
        } else {
            Node *u = gp->left;
            if (u->color == 1) {
                par->color = 0;
                u->color = 0;
                n->parent->parent->color = 1;
                n = n->parent->parent;
            } else {
                if (n == par->left) {
                    n = par;
                    FUN_002635f0(t, n);
                }
                n->parent->color = 0;
                n->parent->parent->color = 1;
                Node *g = n->parent->parent;
                Node *y = g->right;
                g->right = y->left;
                if (y->left != nil)
                    y->left->parent = g;
                y->parent = g->parent;
                Node *gg = g->parent;
                if (gg == nil)
                    t->root = y;
                else if (g == gg->left)
                    gg->left = y;
                else
                    gg->right = y;
                y->left = g;
                g->parent = y;
            }
        }
    }
    t->root->color = 0;
    return 1;
}
