class Base {
  public:
    Base();
    virtual void V();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class Thing : public Base {
  public:
    Thing();
    int a;
    Part p;
    Part q;
    volatile char flag;
    char pad2[3];
    volatile int b, c, d, e;
    int f, g;
    virtual void V();
};
Thing::Thing() : a(0), flag(1), b(0), c(0), d(0), e(0), f(-10), g(0) {}