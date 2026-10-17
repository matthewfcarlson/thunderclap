// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00233320 @ 0x00233320
struct Node { char pad0[8]; int key1; int key2; char pad10[12]; Node *child; Node *next; Node *FUN_00233320(int key1, int key2); };
Node *Node::FUN_00233320(int first, int second) {
    if (key1 == first && key2 == second) return this;
    for (Node *node = child; node != 0; node = node->next) {
        if (node->key1 == first && node->key2 == second) return node;
    }
    return 0;
}