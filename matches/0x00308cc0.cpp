class Base {
  public:
    virtual void f();
    char pad[0x28];
    Base();
};
class Sub {
  public:
    Sub();
    char pad[0x14];
};
class SimpleFilterAbs3D : public Base {
  public:
    Sub sub;
    int a, b, c, d;
    float x, y, z;
    unsigned char flag, flag2;
    char pad2[2];
    int last;
    SimpleFilterAbs3D();
    virtual void f();
};
SimpleFilterAbs3D::SimpleFilterAbs3D()
    : Base(), sub(), a(0), b(0), c(0), d(0), x(1.0f), y(1.0f), z(1.0f), flag(1), flag2(0), last(0) {}