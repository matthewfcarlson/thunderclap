// STATUS: equivalent (tools/equiv.py level 3: 657 inputs, branch coverage 15/16, incomplete)
// FUN_00258870 @ 0x00258870
struct Key { unsigned int low, high; };
struct Node { Node* left; Node* right; char pad[0x20]; Key key; };
struct Tree { Node* root; Node sentinel; };
extern "C" void* __cdecl FUN_00258870(void * tree_, const void * key) {
    Tree * tree = (Tree *)tree_;
    Node* node = tree->root;
    Node* end = &tree->sentinel;
    while (node != end) {
        if (((const Key *)key)->high < node->key.high || (((const Key *)key)->high == node->key.high && ((const Key *)key)->low < node->key.low)) {
            node = node->left;
        } else if (((const Key *)key)->high == node->key.high && ((const Key *)key)->low == node->key.low) {
            return (char*)node - 8;
        } else {
            node = node->right;
        }
    }
    return 0;
}