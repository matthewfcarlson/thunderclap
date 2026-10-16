extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
};
class Locator : public Base {
  public:
    Locator();
    virtual void f();
    char pad[0x18];
    int a, b, c;
    float d;
};
Locator::Locator() {
    _ReadWriteBarrier();
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
}