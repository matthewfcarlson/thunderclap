struct Node { Node* next; };
Node* __fastcall FUN_00230ea0(Node* p) {
    Node* n = p->next;
    if (n == (Node*)((char*)p + 4)) return 0;
    while (n->next != (Node*)((char*)p + 4)) n = n->next;
    return n;
}