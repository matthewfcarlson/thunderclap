typedef unsigned int U_327690;
class d3dPrimBufferStream {
  public:
    virtual void f0();
    virtual void f1(U_327690, U_327690, U_327690);
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
    virtual void f16();
    virtual void f17();
    char pad[0x20];
    U_327690* mDst;
    void finish();
    void vfunc_15(U_327690*, U_327690*);
};
void d3dPrimBufferStream::vfunc_15(U_327690* a, U_327690* b) {
    U_327690* p = mDst;
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    f1(b[0], b[1], b[2]);
    finish();
}