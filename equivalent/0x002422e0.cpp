// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 38/40, incomplete)
// FUN_002422e0 @ 0x002422e0
struct TreeNode_2422e0 {
    TreeNode_2422e0 *left;        // 0x00
    TreeNode_2422e0 *right;       // 0x04
    TreeNode_2422e0 *parent;      // 0x08
    int color;             // 0x0c, 1 = red, 0 = black
    char pad10[0x20 - 0x10];
    int key;               // 0x20
};

struct Tree_2422e0 {
    TreeNode_2422e0 *root;
    TreeNode_2422e0 nil;
};

void __cdecl FUN_00241880(Tree_2422e0 *t, TreeNode_2422e0 *x);
void __cdecl FUN_002418d0(Tree_2422e0 *t, TreeNode_2422e0 *x);

bool __cdecl FUN_002422e0(Tree_2422e0 *t, TreeNode_2422e0 *node, int *keyPtr)
{
    TreeNode_2422e0 *nil = &t->nil;
    TreeNode_2422e0 *y = nil;
    TreeNode_2422e0 *x = t->root;

    if (x != nil) {
        int key = *keyPtr;
        do {
            int d = (int)((unsigned int)key - (unsigned int)x->key);
            y = x;
            if (d < 0)
                x = x->left;
            else if (d <= 0)
                return false;
            else
                x = x->right;
        } while (x != nil);
    }

    node->parent = y;
    if (y == nil) {
        t->root = node;
    } else {
        int d = (int)((unsigned int)*keyPtr - (unsigned int)y->key);
        if (d < 0)
            y->left = node;
        else
            y->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != t->root && node->parent->color == 1) {
        TreeNode_2422e0 *p = node->parent;
        TreeNode_2422e0 *g = p->parent;
        TreeNode_2422e0 *gl = g->left;
        if (p == gl) {
            TreeNode_2422e0 *u = g->right;
            if (u->color == 1) {
                p->color = 0;
                u->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_00241880(t, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                TreeNode_2422e0 *gg = node->parent->parent;
                TreeNode_2422e0 *pivot = gg->left;
                gg->left = pivot->right;
                if (pivot->right != nil)
                    pivot->right->parent = gg;
                pivot->parent = gg->parent;
                TreeNode_2422e0 *gp = gg->parent;
                if (gp == nil)
                    t->root = pivot;
                else if (gg == gp->left)
                    gp->left = pivot;
                else
                    gp->right = pivot;
                pivot->right = gg;
                gg->parent = pivot;
            }
        } else {
            if (gl->color == 1) {
                p->color = 0;
                gl->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_002418d0(t, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                TreeNode_2422e0 *gg = node->parent->parent;
                TreeNode_2422e0 *pivot = gg->right;
                gg->right = pivot->left;
                if (pivot->left != nil)
                    pivot->left->parent = gg;
                pivot->parent = gg->parent;
                TreeNode_2422e0 *gp = gg->parent;
                if (gp == nil)
                    t->root = pivot;
                else if (gg == gp->left)
                    gp->left = pivot;
                else
                    gp->right = pivot;
                pivot->left = gg;
                gg->parent = pivot;
            }
        }
    }
    t->root->color = 0;
    return true;
}
