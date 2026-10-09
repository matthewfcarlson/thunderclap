class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[0x1c];
    Node* next;
};
struct Helper {
    void f(void*);
};
class Branch {
  public:
    char pad[0x1c];
    Node* head;
    void vfunc_6();
};
void Branch::vfunc_6() {
    Node* p = head;
    while (p) {
        p->f6();
        p = p->next;
    }
    ((Helper*)((char*)this + 0x18))->f(this);
}