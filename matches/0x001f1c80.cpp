struct Elem_1f1c80 {
    virtual void Del(int);
    char pad[4];
    Elem_1f1c80* next;
};
struct Item_1f1c80 {
    char pad[0xc];
    Item_1f1c80* next;
    Elem_1f1c80* list;
    void Clean();
};
struct Node {
    Node* first;
    Item_1f1c80* second;
    char pad[4];
    Node* next;
    char sub[4];
    void Run();
};
void __cdecl Destroy(void*);
void Node::Run() {
    Node* n = first;
    while (n) {
        Node* q = n;
        n = q->next;
        q->Run();
        Destroy(q);
    }
    Item_1f1c80* x = second;
    while (x) {
        Item_1f1c80* q = x;
        x = x->next;
        Elem_1f1c80* a = q->list;
        while (a) {
            Elem_1f1c80* z = a;
            a = z->next;
            z->Del(1);
        }
        q->Clean();
        Destroy(q);
    }
    ((Item_1f1c80*)((char*)this + 0x10))->Clean();
}