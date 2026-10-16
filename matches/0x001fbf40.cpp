extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void fn();
};
class CLocator : public Base {
  public:
    CLocator();
    char pad[12];
    int a, b, c, d;
    char flag;
};
CLocator::CLocator() {
    c = 0;
    _ReadWriteBarrier();
    b = 0;
    a = 0;
    d = 0;
    flag = 0;
}