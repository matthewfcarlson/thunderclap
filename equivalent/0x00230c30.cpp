// STATUS: equivalent (tools/equiv.py level 3: 12082 inputs, branch coverage 35/38, incomplete; run with --inputs 12000)
// FUN_00230c30 @ 0x00230c30
struct Node {
    Node *left;
    Node *right;
    Node *parent;
    unsigned char red;
};

struct Tree_230c30 {
    Node *root;
    Node nil;
    int count;
    void FUN_002308a0(Node *x);
    void Insert(Node *node, int (__cdecl *cmp)(Node *, Node *), Node *parent);
};

void Tree_230c30::Insert(Node *node, int (__cdecl *cmp)(Node *, Node *), Node *parent)
{
    Node *nil = &this->nil;
    node->parent = parent;
    if (parent == nil)
        root = node;
    else if (cmp(node, parent) < 0)
        parent->left = node;
    else
        parent->right = node;

    node->left = nil;
    node->right = nil;
    node->red = 1;

    Node *x = node;
    while (x != root && x->parent->red == 1) {
        Node *p = x->parent;
        Node *g = p->parent;
        if (p == g->left) {
            Node *u = g->right;
            if (u->red == 1) {
                p->red = 0;
                u->red = 0;
                x->parent->parent->red = 1;
                x = x->parent->parent;
            } else {
                if (x == p->right) {
                    x = p;
                    Node *y = x->right;
                    x->right = y->left;
                    if (y->left != nil)
                        y->left->parent = x;
                    y->parent = x->parent;
                    if (x->parent == nil)
                        root = y;
                    else if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                    y->left = x;
                    x->parent = y;
                }
                x->parent->red = 0;
                x->parent->parent->red = 1;
                Node *h = x->parent->parent;
                Node *y = h->left;
                h->left = y->right;
                if (y->right != nil)
                    y->right->parent = h;
                y->parent = h->parent;
                if (h->parent == nil) {
                    root = y;
                    y->right = h;
                } else if (h == h->parent->left) {
                    h->parent->left = y;
                    y->right = h;
                } else {
                    h->parent->right = y;
                    y->right = h;
                }
                h->parent = y;
            }
        } else {
            Node *u = g->left;
            if (u->red == 1) {
                x->parent->red = 0;
                u->red = 0;
                x->parent->parent->red = 1;
                x = x->parent->parent;
            } else {
                if (x == p->left) {
                    x = p;
                    FUN_002308a0(x);
                }
                x->parent->red = 0;
                x->parent->parent->red = 1;
                Node *h = x->parent->parent;
                Node *y = h->right;
                h->right = y->left;
                if (y->left != nil)
                    y->left->parent = h;
                y->parent = h->parent;
                if (h->parent == nil)
                    root = y;
                else if (h == h->parent->left)
                    h->parent->left = y;
                else
                    h->parent->right = y;
                y->left = h;
                h->parent = y;
            }
        }
    }
    root->red = 0;
    count++;
}
