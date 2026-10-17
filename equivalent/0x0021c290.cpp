// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// FUN_0021c290 @ 0x0021c290
struct Node {
    int unused;
    int first;
    int previous;
    int current;
    int next;
    int tail;
    int finalValue;
};
int __cdecl FUN_0021bbc0(Node* node, int* next);
// equiv-conv: FUN_0021c290 esi ecx
int FUN_0021c290(Node* node, int key) {
    if (node->current != key) return 0;
    node->previous = node->first;
    if (node->tail != 0x11f) {
        int oldTail = node->tail;
        node->tail = 0x11f;
        node->current = oldTail;
        node->next = node->finalValue;
    } else {
        node->current = FUN_0021bbc0(node, &node->next);
    }
    return 1;
}