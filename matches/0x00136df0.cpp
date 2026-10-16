class Base {
  public:
    Base(int);
    virtual void f();
};
class Range : public Base {
  public:
    Range(int, int);
    virtual void f();
    char pad[12];
    int v;
};
Range::Range(int a, int b) : Base(a), v(b) {}