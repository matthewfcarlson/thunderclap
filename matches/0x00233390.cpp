class Branch;
class Sub_233390 {
  public:
    void helper(Branch*);
};
class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    Node* next;
};
class Branch {
  public:
    char pad[0x1c];
    Node* first;
    void vfunc_5();
};
void Branch::vfunc_5() {
    ((Sub_233390*)((char*)this + 0x18))->helper(this);
    for (Node* p = first; p; p = p->next)
        p->f5();
}
