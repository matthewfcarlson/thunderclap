// STATUS: equivalent (tools/equiv.py level 3: 615 inputs, branch coverage 15/16, incomplete)
// FUN_00263970 @ 0x00263970
struct Node { Node* left; Node* right; char pad[16]; unsigned int low; unsigned int high; };
struct Tree { Node* root; Node sentinel; };
struct Key { unsigned int low; unsigned int high; };
Node* __cdecl FUN_00263970(Tree* tree, const Key* key) {
    Node* node = tree->root;
    Node* end = &tree->sentinel;
    while (node != end) {
        if (key->high < node->high || (key->high == node->high && key->low < node->low)) {
            node = node->left;
        } else if (key->high == node->high && key->low <= node->low) {
            return node;
        } else {
            node = node->right;
        }
    }
    return 0;
}