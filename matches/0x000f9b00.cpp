class Node { public: virtual void Release(int); Node* next; };
class Holder { public: Node* head; void Set(Node*); };
void Holder::Set(Node* value) {
    Node* p = head;
    if (p) {
        do {
            Node* n = p->next;
            p->Release(1);
            p = n;
        } while (p);
    }
    head = value;
}