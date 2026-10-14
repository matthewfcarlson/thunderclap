// STATUS: equivalent (tools/equiv.py level 3: 314 inputs, branch coverage 51/64, incomplete)
// FUN_002448b0 @ 0x002448b0
struct Info {
    char pad0[0x30];
    unsigned int lo;
    unsigned int hi;
};

struct Key {
    unsigned int lo;
    unsigned int hi;
    unsigned int lo2;
    unsigned int hi2;
};

struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int color; // 0 = black, 1 = red
    int pad10;
    unsigned int lo;
    unsigned int hi;
};

// Object that embeds a tree node right after its vptr.
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Info *getInfo();
    Node node;
};

struct Tree {
    Node *root;
    Node nil;
};

int __cdecl FUN_00244080(Key *key, Obj *parent);
void __cdecl FUN_00243c80(Tree *tree, Node *node);
void __cdecl FUN_00243cd0(Tree *tree, Node *node);

bool __cdecl FUN_002448b0(Tree *tree, Obj *obj, Key *key)
{
    Node *nil = &tree->nil;
    Node *n = &obj->node;
    Node *cur = tree->root;
    Node *last = nil;
    Node *x;
    Node *p;
    Node *g;
    Node *y;

    while (cur != nil) {
        int c;
        last = cur;
        if (key->hi > cur->hi) {
            c = 1;
        } else if (key->hi < cur->hi) {
            c = -1;
        } else if (key->lo < cur->lo) {
            c = -1;
        } else if (key->lo > cur->lo) {
            c = 1;
        } else {
            Info *info = ((Obj *)((char *)cur - 4))->getInfo();
            if (key->hi2 > info->hi)
                c = 1;
            else if (key->hi2 < info->hi)
                c = -1;
            else if (key->lo2 < info->lo)
                c = -1;
            else if (key->lo2 > info->lo)
                c = 1;
            else
                c = 0;
        }
        if (c < 0)
            cur = cur->left;
        else if (c > 0)
            cur = cur->right;
        else
            return false;
    }

    n->parent = last;
    if (last == nil) {
        tree->root = n;
    } else {
        if (FUN_00244080(key, (Obj *)((char *)last - 4)) < 0)
            last->left = n;
        else
            last->right = n;
    }
    n->left = nil;
    n->right = nil;
    n->color = 1;

    x = n;
    while (x != tree->root && x->parent->color == 1) {
        p = x->parent;
        g = p->parent;
        if (p == g->left) {
            y = g->right;
            if (y->color == 1) {
                p->color = 0;
                y->color = 0;
                g->color = 1;
                x = g;
            } else {
                if (x == p->right) {
                    x = p;
                    FUN_00243c80(tree, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                g = x->parent->parent;
                y = g->left;
                g->left = y->right;
                if (y->right != nil)
                    y->right->parent = g;
                y->parent = g->parent;
                if (g->parent == nil)
                    tree->root = y;
                else if (g == g->parent->left)
                    g->parent->left = y;
                else
                    g->parent->right = y;
                y->right = g;
                g->parent = y;
            }
        } else {
            y = g->left;
            if (y->color == 1) {
                p->color = 0;
                y->color = 0;
                g->color = 1;
                x = g;
            } else {
                if (x == p->left) {
                    x = p;
                    FUN_00243cd0(tree, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                g = x->parent->parent;
                y = g->right;
                g->right = y->left;
                if (y->left != nil)
                    y->left->parent = g;
                y->parent = g->parent;
                if (g->parent == nil)
                    tree->root = y;
                else if (g == g->parent->left)
                    g->parent->left = y;
                else
                    g->parent->right = y;
                y->left = g;
                g->parent = y;
            }
        }
    }
    tree->root->color = 0;
    return true;
}
