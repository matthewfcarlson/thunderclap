class Base {
  public:
    virtual void f();
    Base(int);
    char pad[12];
};
class Derived_06c740 : public Base {
  public:
    virtual void f();
    int value;
    Derived_06c740(int a, int b);
};
Derived_06c740::Derived_06c740(int a, int b) : Base(a), value(b) {}