class Obj_c79a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};

class Container_c79a0 {
  public:
    char pad[0x10];
    Obj_c79a0* member;

    void Fn();
};

void Container_c79a0::Fn() {
    member->f7();
}
