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
    virtual unsigned int vfunc_8(unsigned int, unsigned int);
    virtual void a9();
    char helper(unsigned int, unsigned int);
};
unsigned int Node::vfunc_8(unsigned int a, unsigned int b) {
    if (helper(a, b))
        return (unsigned int)this;
    return 0;
}