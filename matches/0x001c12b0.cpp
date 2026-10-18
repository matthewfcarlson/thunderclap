class A_1c12b0 {
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
    virtual int f14();
    virtual void f15();
};
class B_1c12b0 {
  public:
    char pad[8];
    A_1c12b0* p;
};
int __fastcall target(B_1c12b0* self) {
    return self->p->f14();
}