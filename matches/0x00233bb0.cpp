class Node {
  public:
    virtual void A();
    virtual void B();
    char pad[0x1c];
    Node* next;
};
class Owner {
    char pad[0x1c];
    Node* head;

  public:
    void F(int);
    void G(int, Node*);
    char H(int i, int v);
};
char Owner::H(int i, int v) {
    Node* n = head;
    int k = 0;
    while (n) {
        if (i < k)
            return 0;
        if (i == k)
            break;
        n = n->next;
        ++k;
    }
    if (!n)
        return 0;
    n->A();
    F(i);
    G(v, n);
    n->B();
    return 1;
}