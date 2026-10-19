struct Node {
    virtual void slot0();
    virtual void release();
    char pad[16];
    Node* prev;
    char pad2[8];
    Node* next;
};
struct Owner {
    char pad[28];
    Node* head;
    void FUN_002331c0();
};
void Owner::FUN_002331c0() {
    for (Node* node = head; node;) {
        Node* old = node;
        node = node->next;
        old->next = 0;
        old->prev = 0;
        old->release();
    }
    head = 0;
}