// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 34/34)
// FUN_00242f90 @ 0x00242f90
struct Node {
    Node *left;
    Node *right;
    Node *parent;
    char pad0c[0x1c];
    float duration;
    float progress;
    char pad30[4];
    int state;
};

struct Tree {
    Node *root;
    Node nil;
};

struct Owner {
    char pad00[0x14];
    Tree tree;
};

extern void __cdecl FUN_00242ec0(Owner *owner, Node *node);

// Advances every node's fade: state 1 ramps progress up to 1 (then state 2), state 3 ramps it
// down and releases the node once it drops below 0.
void FUN_00242f90(Owner *owner, float dt)
{
    Node *nil = &owner->tree.nil;
    Node *node = owner->tree.root;
    if (node == nil)
        return;
    while (node->left != nil)
        node = node->left;
    do {
        if (node->state == 1) {
            bool done = true;
            if (node->duration > 0.0f) {
                node->progress = dt / node->duration + node->progress;
                done = node->progress > 1.0f;
            }
            if (done) {
                node->progress = 1.0f;
                node->state = 2;
            }
        } else if (node->state == 3) {
            bool release = true;
            if (node->duration > 0.0f) {
                node->progress = node->progress - dt / node->duration;
                release = node->progress < 0.0f;
            }
            if (release) {
                node->state = 0;
                node->progress = 0;
                FUN_00242ec0(owner, node);
            }
        }

        // in-order successor
        Node *cur = node;
        Node *next = cur->right;
        if (next == nil) {
            next = cur->parent;
            while (next != nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        node = next;
    } while (node != nil && node != 0);
}
