// STATUS: equivalent (tools/equiv.py level 3: 547 inputs, branch coverage 15/16, incomplete)
// FUN_0025b560 @ 0x0025b560
struct Node { Node* left; Node* parent; Node* right; };
struct Tree { char pad[4]; Node sentinel; };
Node* __cdecl FUN_0025b560(Tree* tree, Node* node)
{
    Node* end = &tree->sentinel;
    Node* current = node->parent;
    if (current != end) {
        while (current->left != end)
            current = current->left;
    } else {
        current = node->right;
        while (current != end && current->parent == node) {
            node = current;
            current = current->right;
        }
    }
    return current == end ? 0 : current;
}