class Base {
  public:
    Base();
    virtual void f();
    char pad[0x3c];
};
class Middle : public Base {
  public:
    int x40, x44, x48, x4c, x50;
    char pad2[4];
    int x58;
    Middle(int a, int b) : x40(0), x44(0), x48(a), x4c(b), x50(-1), x58(0) {}
};
class PrimGroupOptimized : public Middle {
  public:
    PrimGroupOptimized(int a, int b);
    virtual void f();
};
PrimGroupOptimized::PrimGroupOptimized(int a, int b) : Middle(a, b) {}