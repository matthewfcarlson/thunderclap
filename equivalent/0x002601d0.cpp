// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 43/48, incomplete)
// FUN_002601d0 @ 0x002601d0
struct String {
    const char* FUN_0023fb00();
};

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    String key;
};

struct Elem {
    char pad00[0x48];
    Node node;
};

struct Tree {
    Node* root;
    Node nil;
};

int FUN_0025fca0(String* key, Elem* elem);
void FUN_0025fdd0(Tree* tree, Node* x);
void FUN_0025fe20(Tree* tree, Node* x);

// Unique-key insertion into a red-black tree keyed by string. Returns whether
// the element was inserted.
char FUN_002601d0(Tree* tree, Elem* elem, String* key)
{
    Node* x = &elem->node;
    Node* nil = &tree->nil;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        const char* a = cur->key.FUN_0023fb00();
        const char* b = key->FUN_0023fb00();
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
    } else if (FUN_0025fca0(key, (Elem*)((char*)parent - 0x48)) < 0) {
        parent->left = x;
    } else {
        parent->right = x;
    }
    x->left = nil;
    x->right = nil;
    x->color = 1;

    while (x != tree->root && x->parent->color == 1) {
        Node* p = x->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == p->right) {
                    x = p;
                    FUN_0025fdd0(tree, x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                Node* gp = x->parent->parent;
                Node* top = gp->left;
                gp->left = top->right;
                if (top->right != &tree->nil)
                    top->right->parent = gp;
                top->parent = gp->parent;
                Node* ggp = gp->parent;
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
            Node* uncle = g->left;
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
                Node* gp = x->parent->parent;
                Node* top = gp->right;
                gp->right = top->left;
                if (top->left != &tree->nil)
                    top->left->parent = gp;
                top->parent = gp->parent;
                Node* ggp = gp->parent;
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
