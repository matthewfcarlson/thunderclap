// STATUS: equivalent (tools/equiv.py level 3: 314 inputs, branch coverage 51/64, incomplete)
// FUN_002448b0 @ 0x002448b0
struct Info_2448b0 {
    char pad0[0x30];
    unsigned int lo;
    unsigned int hi;
};

struct Key_2448b0 {
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
struct Obj_2448b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Info_2448b0 *getInfo();
    Node node;
};

struct Tree_2448b0 {
    Node *root;
    Node nil;
};

extern "C" int __cdecl FUN_00244080(const void *, void *);
extern "C" void __cdecl FUN_00243c80(void *, void *);
void __cdecl FUN_00243cd0(Tree_2448b0 *tree, Node *node);

extern "C" bool __cdecl FUN_002448b0(void * tree_, void * obj_, void *key)
{
    Tree_2448b0 * tree = (Tree_2448b0 *)tree_;
    Obj_2448b0 * obj = (Obj_2448b0 *)obj_;
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
        if (((Key_2448b0 *)key)->hi > cur->hi) {
            c = 1;
        } else if (((Key_2448b0 *)key)->hi < cur->hi) {
            c = -1;
        } else if (((Key_2448b0 *)key)->lo < cur->lo) {
            c = -1;
        } else if (((Key_2448b0 *)key)->lo > cur->lo) {
            c = 1;
        } else {
            Info_2448b0 *info = ((Obj_2448b0 *)((char *)cur - 4))->getInfo();
            if (((Key_2448b0 *)key)->hi2 > info->hi)
                c = 1;
            else if (((Key_2448b0 *)key)->hi2 < info->hi)
                c = -1;
            else if (((Key_2448b0 *)key)->lo2 < info->lo)
                c = -1;
            else if (((Key_2448b0 *)key)->lo2 > info->lo)
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
        if (FUN_00244080((Key_2448b0 *)((Key_2448b0 *)key), (Obj_2448b0 *)((Obj_2448b0 *)((char *)last - 4))) < 0)
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
                    FUN_00243c80((Tree_2448b0 *)tree, (Node *)x);
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
