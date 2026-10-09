class Obj {
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
    virtual void f13(int);
};
class Holder {
  public:
    Obj* p;
    Holder* FUN_00293bd0(Obj*);
};
Holder* Holder::FUN_00293bd0(Obj* p) {
    this->p = p;
    p->f13(0);
    return this;
}