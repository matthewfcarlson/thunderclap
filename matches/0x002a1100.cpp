extern "C" void _ReadWriteBarrier();
class Root {
  public:
    Root();
    virtual void f();
    char pad[12];
};
class Base : public Root {
  public:
    Base() : a(0), b(0) {}
    int a, b;
};
class LightGroup : public Base {
  public:
    LightGroup();
    virtual void f();
    int c, d;
};
LightGroup::LightGroup() {
    _ReadWriteBarrier();
    c = 0;
    d = 0;
}