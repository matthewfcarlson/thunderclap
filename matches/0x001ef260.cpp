class Owner;
struct Node {
    int a;
    Owner* owner;
    Node* next;
};
class Owner {
  public:
    char pad[0x10];
    Node* head;
    int count;
    void Add(Node* n);
};
void Owner::Add(Node* n) {
    if (n) {
        n->next = 0;
        n->owner = this;
        ++count;
        Node* p = head;
        if (!p) {
            head = n;
            return;
        }
        while (p->next)
            p = p->next;
        p->next = n;
    }
}