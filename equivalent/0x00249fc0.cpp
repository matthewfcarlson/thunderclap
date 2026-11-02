// STATUS: equivalent (tools/equiv.py level 3: 702 inputs, branch coverage 8/8)
// FUN_00249fc0 @ 0x00249fc0
struct Node { Node *left; Node *right; char pad[8]; unsigned int key; }; struct Tree { Node *root; Node sentinel; }; extern "C" void *__cdecl FUN_00249fc0(void * tree_, const unsigned int *key) {
    Tree * tree = (Tree *)tree_; Node *node = tree->root; Node *end = &tree->sentinel; while (node != end) { if (*key < node->key) node = node->left; else if (*key == node->key) return (Node *)node; else node = node->right; } return (Node *)0; }