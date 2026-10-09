struct Node { char pad[0x64]; Node* next; int index; };
class Queue {
public:
    void Push(Node* n);
    Node* heads[4];
};
void Queue::Push(Node* n) {
    int i = n->index;
    if (heads[i] == 0) {
        heads[i] = n;
        n->next = 0;
        heads[i + 2] = n;
    } else {
        Node* tail = heads[i + 2];
        tail->next = n;
        n->next = 0;
        heads[i + 2] = n;
    }
}
