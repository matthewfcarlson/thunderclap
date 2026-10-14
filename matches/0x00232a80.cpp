class Node {
  public:
    virtual void F();
    virtual void G();
    char pad[12];
    Node* next;
    void Rel(Node*);
};
class Owner_232a80 {
  public:
    Node* head;
    void Set(Node*);
};
void Owner_232a80::Set(Node* arg) {
    if (arg) {
        Node* p = head;
        Node* last = 0;
        while (p) {
            last = p;
            p = p->next;
        }
        arg->Rel(p);
        if (last) {
            last->Rel(arg);
            return;
        }
        arg->F();
        if (head)
            head->G();
        head = arg;
    }
}