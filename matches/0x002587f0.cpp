struct Node {
    Node* next;
    char data[4];
};

Node* FUN_002587f0(Node* head) {
    Node* end = (Node*)((char*)head + 4);
    if (head->next == end)
        return 0;
    Node* p = head->next;
    while (p->next != end)
        p = p->next;
    return (Node*)((char*)p - 8);
}