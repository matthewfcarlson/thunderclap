class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual bool Test(int);
};
struct Node {
    Item* item;
    Node* child;
    Node* next;
};
Node* Find(Node* node, int arg) {
    while (node != 0) {
        if (node->item->Test(arg)) {
            Node* found = Find(node->child, arg);
            if (found != 0)
                return found;
            return node;
        }
        node = node->next;
    }
    return 0;
}