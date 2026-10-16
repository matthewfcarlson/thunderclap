class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void Set(void*);
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual int Check();
};
class Owner {
    char pad[0x1c];

  public:
    Node* node;
};
int __cdecl FUN_00246960(Owner* o, void* p) {
    o->node->Set(p);
    return !o->node->Check();
}