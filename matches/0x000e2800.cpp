class Obj_e2800;
class Inner_e2800 {
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
    virtual void f14(unsigned int, Obj_e2800*);
};
class Obj_e2800 {
  public:
    char pad[0x14];
    Inner_e2800* member;
    unsigned int run(unsigned int);
};
unsigned int Obj_e2800::run(unsigned int param) {
    member->f14(param, this);
    return param;
}