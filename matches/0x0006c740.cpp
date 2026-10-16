class Base {
  public:
    virtual void f();
    Base(int);
    char pad[12];
};
class Derived : public Base {
  public:
    virtual void f();
    int value;
    Derived(int a, int b);
};
Derived::Derived(int a, int b) : Base(a), value(b) {}