// STATUS: equivalent (tools/equiv.py level 3: 549 inputs, branch coverage 12/12)
// FUN_00241930 @ 0x00241930
struct Node {
    Node *left;
    Node *parent;
    Node *right;
};
struct Tree {
    char padding[4];
    Node sentinel;
};
Node * __cdecl FUN_00241930(Tree *tree, Node *node)
{
    Node *end = &tree->sentinel;
    Node *next = node->parent;
    if (next == end) {
        next = node->right;
        while (next != end && node == next->parent) {
            node = next;
            next = next->right;
        }
        return next;
    }
    while (next->left != end)
        next = next->left;
    return next;
}
