// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 18/22, incomplete)
// FUN_0025b8e0 @ 0x0025b8e0
// Number of nodes of a red-black tree (sentinel node `nil` stored right after the root pointer),
// counted by an in-order walk.
struct Node {
    Node* left;
    Node* right;
    Node* parent;
};

struct Tree {
    Node* root;
    Node nil;
};

static Node* Leftmost(Node* n, Node* nil)
{
    while (n->left != nil)
        n = n->left;
    return n;
}

// in-order successor; returns nil past the last node
static Node* Next(Node* n, Node* nil)
{
    if (n->right != nil)
        return Leftmost(n->right, nil);
    Node* p = n->parent;
    if (p == nil)
        return nil;
    while (n == p->right) {
        n = p;
        p = p->parent;
        if (p == nil)
            break;
    }
    return p;
}

int __cdecl FUN_0025b8e0(Tree* tree)
{
    Node* nil = &tree->nil;
    Node* cur = tree->root;
    int count = 0;
    if (cur == nil)
        return 0;
    cur = Leftmost(cur, nil);
    do {
        count++;
        cur = Next(cur, nil);
    } while (cur != nil && cur != 0);
    return count;
}
