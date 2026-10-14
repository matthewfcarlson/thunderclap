// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 31/32, incomplete)
// FUN_00249a90 @ 0x00249a90
struct Item {
    Item* next;
    char pad04[8];
    unsigned state;
    char pad10[8];
    unsigned value0;
    unsigned value1;
    unsigned field20;
    unsigned field24;
    unsigned field28;
};
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    unsigned field0c;
    Item* items;
};
struct Tree {
    char pad00[0x18];
    Node* root;
    Node sentinel;
};
struct Values { unsigned first; unsigned second; };
void __cdecl FUN_00249a90(Tree* tree, const Values* values) {
    Node* end = &tree->sentinel;
    Node* node = tree->root;
    if (node == end) return;
    while (node->left != end) node = node->left;
    for (;;) {
        for (Item* item = node->items; item != 0; item = item->next) {
            if (item->state != 0 && item->state != 5) {
                item->state = 5;
                if (values) {
                    item->value0 = values->first;
                    item->value1 = values->second;
                } else {
                    item->value0 = 0;
                    item->value1 = 0;
                }
                item->field28 = 0;
                item->field20 = 0;
            }
        }
        if (node->right != end) {
            node = node->right;
            while (node->left != end) node = node->left;
        } else {
            Node* parent = node->parent;
            if (parent == end) return;
            while (node == parent->right) {
                node = parent;
                parent = parent->parent;
                if (parent == end) return;
            }
            node = parent;
        }
        if (node == end || node == 0) return;
    }
}
