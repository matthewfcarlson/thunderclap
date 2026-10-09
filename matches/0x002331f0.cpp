typedef unsigned int u32;
struct Node {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    char a[0x10];
    int field14;
    char b[8];
    Node* next;
};
struct Helper {
    void go();
};
struct Branch {
    char pad[0x1c];
    Node* head;
    void vfunc_7();
};
void Branch::vfunc_7() {
    ((Helper*)((char*)this + 0x18))->go();
    Node* p = head;
    while (p) {
        Node* c = p;
        p = c->next;
        c->next = 0;
        c->field14 = 0;
        c->f1();
    }
    head = 0;
}
