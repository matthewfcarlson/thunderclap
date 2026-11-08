// The heap tree's lookup: the deepest node whose allocator owns the block (slot 5, core::IMemoryAllocator's
// ownership test, takes the block as a pointer).
class Item_266f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool Match(void*);
};
class Node_266f50 {
  public:
    Item_266f50* item;
    Node_266f50* child;
    Node_266f50* next;
};
extern "C" Node_266f50* FUN_00266f50(Node_266f50* node, void* arg) {
    while (node != 0) {
        if (node->item->Match(arg)) {
            Node_266f50* r = FUN_00266f50(node->child, arg);
            if (r != 0)
                return r;
            return node;
        }
        node = node->next;
    }
    return 0;
}
