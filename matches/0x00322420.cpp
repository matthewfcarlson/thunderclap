struct Child {
    void go();
};
struct Inner {
    char pad[0x208];
    Child* child;
};
class d3dExtVertexProgram {
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
    Inner* mInner;
};
void d3dExtVertexProgram::f1() {
    mInner->child->go();
}