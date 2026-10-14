extern float gOne_295e00;
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual float* vfunc_16();
    virtual void f17();
    char pad[0x10];
    Node* child;
};
float* Node::vfunc_16() {
    if (child)
        return child->vfunc_16();
    return &gOne_295e00;
}