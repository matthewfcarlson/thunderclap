// Same code shape as 0x000e4d50 (propagated; names are from that function)
class Child_e5600 {
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
    virtual void f9(int);
    virtual void f10(int);
};
class FEScreenBase {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void vfunc_15();
    char pad[0x44];
    Child_e5600* child;
};
void FEScreenBase::vfunc_15() {
    if (child) {
        child->f10(3);
        child->f9(0);
    }
}