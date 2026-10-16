class Base {
  public:
    virtual void f();
    Base(int);
};
class Range : public Base {
  public:
    virtual void f();
    char pad[12];
    int value;
    Range(int a, int b);
};
Range::Range(int a, int b) : Base(a), value(b) {}