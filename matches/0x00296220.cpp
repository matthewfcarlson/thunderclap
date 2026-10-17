struct Node;
struct Visitor {
    virtual unsigned char accepts(Node* node);
};
struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual unsigned int count();
    virtual Node* child(unsigned int index);
};
void __cdecl FUN_00296220(Node* node, Visitor* visitor) {
    if (node && visitor->accepts(node) == 1) {
        unsigned int n = node->count();
        for (unsigned int i = 0; i < n; ++i)
            FUN_00296220(node->child(i), visitor);
    }
}
