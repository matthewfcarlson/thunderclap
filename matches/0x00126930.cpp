class Base {
  public:
    virtual void f();
    char pad[12];
    Base(int);
};
class Derived : public Base {
  public:
    virtual void f();
    int a, b, c;
    Derived(int, int, int, int);
};
Derived::Derived(int x, int y, int z, int w) : Base(x) {
    a = y;
    b = z;
    c = w;
}