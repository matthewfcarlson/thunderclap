class Node {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual float* vfunc_17();
    char pad[12];
    int state;
    Node* child;
};
float* Node::vfunc_17() {
    state &= ~4;
    if (child)
        return child->vfunc_17();
    extern float one;
    return &one;
}