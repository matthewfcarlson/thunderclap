// STATUS: equivalent (tools/equiv.py level 3: 527 inputs, branch coverage 14/14)
// FUN_00258820 @ 0x00258820
struct Link { Link* left; Link* parent; Link* right; };
struct Tree { char padding[4]; Link sentinel; };
struct Node { char padding[8]; Link links; };

Node* __cdecl FUN_00258820(Tree* tree, Node* node)
{
    Link* sentinel = &tree->sentinel;
    Link* current = &node->links;
    Link* result = current->parent;
    if (result != sentinel) {
        while (result->left != sentinel)
            result = result->left;
    } else {
        result = current->right;
        while (result != sentinel && current == result->parent) {
            current = result;
            result = result->right;
        }
    }
    if (result == sentinel)
        return 0;
    return reinterpret_cast<Node*>(reinterpret_cast<char*>(result) - 8);
}