// STATUS: equivalent (tools/equiv.py level 3: 3052 inputs, branch coverage 22/28, incomplete)
// FUN_00233990 @ 0x00233990
struct Node {
    char pad0[0x14];
    Node *parent;
    char pad18[4];
    Node *firstChild;
    Node *next;
    Node *FUN_00233990();
};

// Walks down from this: at each level, picks the last child (counting from the end of the
// child list) whose parent pointer is the current node. Returns the current node when it has
// no such child, or the chosen child when that child is a leaf.
Node *Node::FUN_00233990()
{
    Node *cur = this;
    for (;;) {
        Node *head = cur->firstChild;
        int count = 0;
        for (Node *c = head; c != 0; c = c->next)
            count++;
        Node *found = 0;
        for (int i = count - 1; i >= 0 && found == 0; i--) {
            Node *c = head;
            for (int k = 0; c != 0 && k < i; k++)
                c = c->next;
            if (c != 0 && c->parent == cur)
                found = c;
        }
        if (found == 0)
            return cur;
        if (found->firstChild == 0)
            return found;
        cur = found;
    }
}
