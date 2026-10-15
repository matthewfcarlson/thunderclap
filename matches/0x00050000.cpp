class Base {
  public:
    Base(int);
    virtual void f();
    char pad[12];
};
class Derived : public Base {
  public:
    Derived(int, int, int, int);
    virtual void f();
    int a, b, c;
};
Derived::Derived(int x, int y, int z, int w) : Base(x), a(y), b(z), c(w) {}