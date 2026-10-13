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
};

class Container {
  public:
    char pad[0x10];
    Obj* member;

    void Fn();
};

void Container::Fn() {
    member->f7();
}
