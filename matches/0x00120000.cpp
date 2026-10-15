class Base {
  public:
    Base(int);
    virtual void f();
    char pad[12];
};
class PathLocatorTestCondition : public Base {
  public:
    PathLocatorTestCondition(int, int, int, int);
    int a, b, c;
};
PathLocatorTestCondition::PathLocatorTestCondition(int x, int y, int z, int w) : Base(x), a(y), b(z), c(w) {}