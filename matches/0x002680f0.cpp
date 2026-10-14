class Timer;
class Child_2680f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(Timer*);
};
class Owner_2680f0 {
  public:
    virtual void f0();
    virtual void f1();
    char pad[0x14];
    Child_2680f0* child;
};
class Timer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
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
    int refs;
    char pad[0x18];
    Owner_2680f0* owner;
};
void Timer::f1() {
    if (--refs == 0) {
        Owner_2680f0* o = owner;
        f2(0);
        o->child->f4(this);
        o->f1();
    }
}
