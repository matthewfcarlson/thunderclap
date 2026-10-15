class Base {
  public:
    virtual void f();
    char pad[4];
    Base();
};
class PrimGroupLoader : public Base {
  public:
    virtual void g();
    int a, b;
    char c, d;
    short e;
    int f0, f1, f2, f3, f4, f5;
    PrimGroupLoader();
};
PrimGroupLoader::PrimGroupLoader()
    : Base(), a(0), b(0), c(0), e(0), f0(0), f3(0), f4(0), f5(0), d(1), f1(-1), f2(-1) {}