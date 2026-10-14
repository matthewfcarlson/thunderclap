extern "C" char DAT_00427688[];
class Part_231d40 {
  public:
    void init();
};
class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual Node* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    char pad[0x28 - 4];
    void second();
};
extern void third(Node*);
Node* Node::vfunc_2(unsigned char p) {
    *(void**)this = (void*)((int)DAT_00427688);
    ((Part_231d40*)((char*)this + 0x28))->init();
    second();
    if (p & 1)
        third(this);
    return this;
}