class Owner_1ef260;
struct Node {
    int a;
    Owner_1ef260* owner;
    Node* next;
};
class Owner_1ef260 {
  public:
    char pad[0x10];
    Node* head;
    int count;
    void Add(Node* n);
};
void Owner_1ef260::Add(Node* n) {
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