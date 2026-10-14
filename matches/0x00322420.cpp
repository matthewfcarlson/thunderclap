struct Child_322420 {
    void go();
};
struct Inner_322420 {
    char pad[0x208];
    Child_322420* child;
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
    Inner_322420* mInner;
};
void d3dExtVertexProgram::f1() {
    mInner->child->go();
}