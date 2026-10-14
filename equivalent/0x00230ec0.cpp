// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 27/28, incomplete)
// FUN_00230ec0 @ 0x00230ec0
// In-order walk of a red-black tree (STL map layout): call back for every node until the callback returns false.
struct Node {
    Node* left;
    Node* right;
    Node* parent;
};

typedef char (__cdecl *NodeCallback)(Node* node, int arg);

class Tree {
public:
    Node* root;
    Node nil;

    bool FUN_00230ec0(NodeCallback callback, int arg);
};

bool Tree::FUN_00230ec0(NodeCallback callback, int arg)
{
    Node* n;
    if (root == &nil) {
        n = 0;
    } else {
        n = root;
        while (n->left != &nil) {
            n = n->left;
        }
    }
    if (n == &nil || n == 0) {
        return true;
    }
    for (;;) {
        if (!callback(n, arg)) {
            return false;
        }
        Node* next = n->right;
        if (next != &nil) {
            while (next->left != &nil) {
                next = next->left;
            }
        } else {
            Node* child = n;
            next = n->parent;
            if (next == &nil) {
                return true;
            }
            while (child == next->right) {
                child = next;
                next = next->parent;
                if (next == &nil) {
                    break;
                }
            }
        }
        if (next == &nil || next == 0) {
            return true;
        }
        n = next;
    }
}
