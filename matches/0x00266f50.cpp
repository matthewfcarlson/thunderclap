class Item_266f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool Match(int);
};
class Node {
  public:
    Item_266f50* item;
    Node* child;
    Node* next;
};
Node* Find(Node* node, int arg) {
    while (node != 0) {
        if (node->item->Match(arg)) {
            Node* r = Find(node->child, arg);
            if (r != 0)
                return r;
            return node;
        }
        node = node->next;
    }
    return 0;
}