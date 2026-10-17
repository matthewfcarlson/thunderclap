// STATUS: equivalent (tools/equiv.py level 3: 657 inputs, branch coverage 15/16, incomplete)
// FUN_00258870 @ 0x00258870
struct Key { unsigned int low, high; };
struct Node { Node* left; Node* right; char pad[0x20]; Key key; };
struct Tree { Node* root; Node sentinel; };
void* __cdecl FUN_00258870(Tree* tree, const Key* key) {
    Node* node = tree->root;
    Node* end = &tree->sentinel;
    while (node != end) {
        if (key->high < node->key.high || (key->high == node->key.high && key->low < node->key.low)) {
            node = node->left;
        } else if (key->high == node->key.high && key->low == node->key.low) {
            return (char*)node - 8;
        } else {
            node = node->right;
        }
    }
    return 0;
}