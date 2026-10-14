// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 24/24)
// FUN_00260520 @ 0x00260520
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree_260520 {
    Node *root;
    Node nil;
};

struct Item_260520 {
    char pad[0x48];
    Node node;
};

static __forceinline Item_260520 *ItemOf(Node *n)
{
    return (Item_260520 *)((char *)n - 0x48);
}

Item_260520 *FUN_00260520(Tree_260520 *tree, int steps)
{
    Node *nil = &tree->nil;
    Node *node = tree->root;
    Item_260520 *item;
    if (node == nil) {
        item = 0;
    } else {
        while (node->left != nil)
            node = node->left;
        item = ItemOf(node);
    }
    for (; steps != 0; steps--) {
        node = &item->node;
        Node *next = node->right;
        if (next == nil) {
            next = node->parent;
            while (next != nil && node == next->right) {
                node = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        item = (next == nil) ? 0 : ItemOf(next);
    }
    return item;
}
