struct Node {
    Node* next;
    Node* prev;
};
struct Item_257c20 {
    char pad[0x14];
    Node n;
    char pad2[0x38 - 0x1c];
    int x;
};
struct L_257c20 {
    char pad[0x28];
    char s[0x3c - 0x28];
    Node* head;
    Node* tail;
    char Fn(Item_257c20* i);
};
char Add(void* s, Item_257c20* i, int* p);
char L_257c20::Fn(Item_257c20* i) {
    if (Add(&s, i, &i->x)) {
        Node* n = &i->n;
        if (head == 0) {
            head = n;
            n->prev = 0;
            tail = n;
            n->next = 0;
            return 1;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
        n->next = 0;
        return 1;
    }
    return 0;
}
