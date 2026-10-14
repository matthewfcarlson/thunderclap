// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 41/52, incomplete)
// FUN_00258530 @ 0x00258530
struct Key {
    unsigned lo;
    unsigned hi;
};

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;  // 0 = black, 1 = red
    char pad10[0x28 - 0x10];
    Key key;
};

struct Item {
    char pad0[8];
    Node node;
};

struct Tree {
    Node* root;
    Node nil;
};

void __cdecl FUN_00258140(Tree* tree, Node* n);  // rotate left
void __cdecl FUN_00258190(Tree* tree, Node* n);  // rotate right

static inline const Key* KeyOf(const Node* n)
{
    return &n->key;
}

// Unique insert of item (keyed by a 64-bit key) into an intrusive red-black tree.
bool __cdecl FUN_00258530(Tree* tree, Item* item, const Key* key)
{
    Node* nil = &tree->nil;
    Node* added = &item->node;
    Node* x = tree->root;
    Node* y = nil;

    if (x != nil) {
        unsigned klo = key->lo;
        unsigned khi = key->hi;
        do {
            const Key* nk = KeyOf(x);
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
        const Key* yk = KeyOf(y);
        if (key->hi > yk->hi || (key->hi == yk->hi && key->lo >= yk->lo))
            y->right = added;
        else
            y->left = added;
    }
    added->left = nil;
    added->right = nil;
    added->color = 1;

    Node* n = added;
    while (n != tree->root && n->parent->color == 1) {
        Node* p = n->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
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
                Node* gp = n->parent->parent;
                Node* pivot = gp->left;
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
            Node* uncle = g->left;
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
                Node* gp = n->parent->parent;
                Node* pivot = gp->right;
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
