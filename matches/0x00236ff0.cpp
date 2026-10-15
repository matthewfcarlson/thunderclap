struct Node {
    int pad;
    Node* next;
    void Link(Node*);
};
class List {
  public:
    Node* head;
    int Add(Node* n);
};
int List::Add(Node* n) {
    if (!n)
        return -1;
    Node* last = 0;
    Node* p = head;
    int count = 0;
    while (p) {
        last = p;
        p = p->next;
        ++count;
    }
    n->Link(p);
    if (last)
        last->Link(n);
    else
        head = n;
    return count;
}