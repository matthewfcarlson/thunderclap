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
extern "C" Node* FUN_00266f50(Node* node, int arg) {
    while (node != 0) {
        if (node->item->Match(arg)) {
            Node* r = FUN_00266f50(node->child, arg);
            if (r != 0)
                return r;
            return node;
        }
        node = node->next;
    }
    return 0;
}