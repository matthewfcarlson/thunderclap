extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[0x3c];
};
class Sub {
  public:
    void Init();
    char pad[0x40];
};
class BillboardQuadGroup : public Base {
  public:
    BillboardQuadGroup();
    virtual void f();
    Sub sub;
    float scale;
    int a;
    char b, c, d, pad3;
    int e, g;
};
BillboardQuadGroup::BillboardQuadGroup() : Base() {
    scale = 1.0f;
    a = 0;
    b = 1;
    c = 0;
    d = 0;
    _ReadWriteBarrier();
    e = 0;
    g = 0;
    sub.Init();
}