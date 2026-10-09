struct Node {
    Node* next;
};
struct Container {
    char pad[0x44];
    Node* head;
    Node* FindLast();
};
Node* Container::FindLast() {
    Node* p = head;
    Node* sentinel = (Node*)((char*)this + 0x48);
    if (p == sentinel)
        return 0;
    while (p->next != sentinel)
        p = p->next;
    return p;
}
