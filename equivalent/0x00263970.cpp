// STATUS: equivalent (tools/equiv.py level 3: 615 inputs, branch coverage 15/16, incomplete)
// FUN_00263970 @ 0x00263970
struct Node { Node* left; Node* right; char pad[16]; unsigned int low; unsigned int high; };
struct Tree { Node* root; Node sentinel; };
struct Key { unsigned int low; unsigned int high; };
extern "C" void * __cdecl FUN_00263970(void * tree_, const void * key) {
    Tree * tree = (Tree *)tree_;
    Node* node = tree->root;
    Node* end = &tree->sentinel;
    while (node != end) {
        if (((const Key *)key)->high < node->high || (((const Key *)key)->high == node->high && ((const Key *)key)->low < node->low)) {
            node = node->left;
        } else if (((const Key *)key)->high == node->high && ((const Key *)key)->low <= node->low) {
            return (Node *)node;
        } else {
            node = node->right;
        }
    }
    return (Node *)0;
}