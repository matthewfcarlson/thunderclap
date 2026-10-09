struct Node { Node* next; Node* prev; };
void FUN_00257f00(Node* out, Node* n) {
    if (n->prev == 0) out->next = n->next;
    else n->prev->next = n->next;
    if (n->next == 0) { out->prev = n->prev; return; }
    n->next->prev = n->prev;
}