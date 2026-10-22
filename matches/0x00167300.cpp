class Obj {
  public:
    int value();
};
class Mid {
  public:
    Obj* get();
};
class Arg {
  public:
    Mid* get();
};
class LocomotionMotionStateCondition_167300 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int, Arg*, int);
    char pad[8];
    int mode;
    int number;
};
bool LocomotionMotionStateCondition_167300::vfunc_6(int a, Arg* b, int c) {
    Obj* p = b->get()->get();
    int x = number;
    switch (mode) {
    case 0:
        return p->value() == x;
    case 1:
        return p->value() != x;
    default:
        return false;
    }
}