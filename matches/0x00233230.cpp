class Node {
  public:
    virtual void A();
    virtual void B();
    char pad[16];
    int value;
    char pad2[8];
    Node* next;
};
class List {
    char pad[28];
    Node* head;

  public:
    bool Remove(int n);
};
bool List::Remove(int n) {
    Node* p = head;
    Node* prev = 0;
    int i = 0;
    while (p) {
        if (i > n)
            break;
        if (i == n) {
            if (prev)
                prev->next = p->next;
            else
                head = p->next;
            p->value = 0;
            p->next = 0;
            p->B();
            return true;
        }
        prev = p;
        p = p->next;
        ++i;
    }
    return false;
}