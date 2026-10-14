class Obj_293bd0 {
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
class Holder_293bd0 {
  public:
    Obj_293bd0* p;
    Holder_293bd0* FUN_00293bd0(Obj_293bd0*);
};
Holder_293bd0* Holder_293bd0::FUN_00293bd0(Obj_293bd0* p) {
    this->p = p;
    p->f13(0);
    return this;
}