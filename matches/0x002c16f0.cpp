extern "C" void _ReadWriteBarrier();
class Entity_2c16f0 {
  public:
    Entity_2c16f0();
    virtual void f();
};
class Locator : public Entity_2c16f0 {
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