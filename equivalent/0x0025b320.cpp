// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 40/40)
// FUN_0025b320 @ 0x0025b320
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    int key;
};

struct Tree {
    Node* root;
    Node nil;
};

extern "C" int FUN_0025ad30(const void* key, const Node* node);
extern "C" void FUN_0025af20(Tree* tree, Node* node);
extern "C" void FUN_0025af70(Tree* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
char FUN_0025b320(Tree* tree, Node* node, const void* key)
{
    Node* nil = &tree->nil;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        int c = FUN_0025ad30(key, cur);
        if (c < 0) {
            cur = cur->left;
        } else if (c <= 0) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (FUN_0025ad30(key, parent) < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != tree->root && node->parent->color == 1) {
        Node* p = node->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_0025af20(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->left;
                gg->left = pv->right;
                if (pv->right != nil)
                    pv->right->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->right = gg;
                gg->parent = pv;
            }
        } else {
            Node* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_0025af70(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->right;
                gg->right = pv->left;
                if (pv->left != nil)
                    pv->left->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->left = gg;
                gg->parent = pv;
            }
        }
    }
    tree->root->color = 0;
    return 1;
}
