// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 31/32, incomplete)
// FUN_00249a90 @ 0x00249a90
struct Pair {
    int lo, hi;
};

struct Item {
    Item *next;                // 0x00
    char pad04[8];
    int state;                 // 0x0c
    char pad10[8];
    int lo;                    // 0x18
    int hi;                    // 0x1c
    int f20;                   // 0x20
    char pad24[4];
    int f28;                   // 0x28
};

struct Node {
    Node *left;                // 0x00
    Node *right;               // 0x04
    Node *parent;              // 0x08
    char pad0c[4];
    Item *items;               // 0x10
    char pad14[8];
};

struct Tree {
    char pad0[0x18];
    Node *first;               // 0x18
    Node nil;                  // 0x1c
};

// Visits the nodes of the tree in order and resets every live item's state to 5.
void __cdecl FUN_00249a90(Tree *tree, Pair *value)
{
    Node *nil = &tree->nil;
    Node *node = tree->first;
    if (node == nil)
        return;
    for (Node *n = node->left; n != nil; n = n->left)
        node = n;
    for (;;) {
        for (Item *it = node->items; it != 0; it = it->next) {
            if (it->state != 0 && it->state != 5) {
                it->state = 5;
                if (value != 0) {
                    it->lo = value->lo;
                    it->hi = value->hi;
                } else {
                    it->lo = 0;
                    it->hi = 0;
                }
                it->f28 = 0;
                it->f20 = 0;
            }
        }
        Node *next = node->right;
        if (next == nil) {
            Node *prev = node;
            Node *up = node->parent;
            if (up == nil)
                return;
            node = up;
            while (prev == node->right) {
                prev = node;
                node = node->parent;
                if (node == nil)
                    return;
            }
        } else {
            node = next;
            for (Node *n = node->left; n != nil; n = n->left)
                node = n;
        }
        if (node == nil || node == 0)
            return;
    }
}
