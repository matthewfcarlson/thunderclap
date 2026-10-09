class BranchNode {
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
    virtual unsigned int vfunc_12(unsigned int);
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    int pad[5];
    unsigned int count;
    unsigned int* items;
};
unsigned int BranchNode::vfunc_12(unsigned int i) {
    if (i < count)
        return items[i];
    return 0;
}