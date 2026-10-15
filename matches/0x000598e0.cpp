class Parent {
  public:
    Parent();
    virtual void f();
    char pad[4];
};
class Base : public Parent {
  public:
    int value;
    int x, y;
    char pad[4];
    Base(int v) : Parent(), value(v), x(0), y(0) {}
};
class Sub {
  public:
    char pad0[0x4c];
    int a, b;
    char pad1[0xc];
    int c;
    char pad2[8];
    int d, e;
    char pad3[0x10];
    int f;
    void Init(int);
    Sub(int z) : a(0), b(0), c(0), d(0), e(0), f(0) { Init(z); }
};
class CFightParamsCollision : public Base {
  public:
    Sub sub;
    CFightParamsCollision(int, int);
    virtual void f();
};
CFightParamsCollision::CFightParamsCollision(int v, int n) : Base(v), sub(n) {}