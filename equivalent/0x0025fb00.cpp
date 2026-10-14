// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 26/26)
// FUN_0025fb00 @ 0x0025fb00
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

class Item_25fb00 {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(int arg);
    Node node;
};

class ItemTree {
public:
    void FUN_0025fb00(int arg);

    char pad0[0x14];
    Node *root;
    Node nil;
    char pad1[0x30 - 0x24];
    ItemTree *child;
};

void ItemTree::FUN_0025fb00(int arg)
{
    if (child)
        child->FUN_0025fb00(arg);

    Item_25fb00 *item;
    if (root == &nil) {
        item = 0;
    } else {
        Node *n = root;
        while (n->left != &nil)
            n = n->left;
        item = (Item_25fb00 *)((char *)n - 4);
    }

    while (item) {
        item->vfn3(arg);

        Node *n = item->node.right;
        Node *next;
        if (n == &nil) {
            Node *cur = &item->node;
            next = cur->parent;
            while (next != &nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            next = n;
            while (next->left != &nil)
                next = next->left;
            // leftmost of right subtree
        }
        if (next == &nil)
            item = 0;
        else
            item = (Item_25fb00 *)((char *)next - 4);
    }
}
