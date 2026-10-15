struct Node {
    Node* next;
    Node* link;
    void Set(Node*);
};
class List {
  public:
    Node* head;
    int Add(Node* p);
};
int List::Add(Node* p) {
    if (!p)
        return -1;
    Node* n = head;
    Node* last = 0;
    int i = 0;
    while (n) {
        last = n;
        n = n->link;
        ++i;
    }
    p->Set(n);
    if (last)
        last->Set(p);
    else
        head = p;
    return i;
}