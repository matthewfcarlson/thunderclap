struct Elem {
    virtual void Del(int);
    char pad[4];
    Elem* next;
};
struct Item {
    char pad[0xc];
    Item* next;
    Elem* list;
    void Clean();
};
struct Node {
    Node* first;
    Item* second;
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
    Item* x = second;
    while (x) {
        Item* q = x;
        x = x->next;
        Elem* a = q->list;
        while (a) {
            Elem* z = a;
            a = z->next;
            z->Del(1);
        }
        q->Clean();
        Destroy(q);
    }
    ((Item*)((char*)this + 0x10))->Clean();
}