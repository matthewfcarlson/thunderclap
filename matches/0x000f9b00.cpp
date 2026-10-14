class Node {
  public:
    virtual void Release(int);
    Node* next;
};
class Holder_f9b00 {
  public:
    Node* head;
    void Set(Node*);
};
void Holder_f9b00::Set(Node* value) {
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