class SimpleFilter3D_308cc0 {
  public:
    virtual void f();
    char pad[0x28];
    SimpleFilter3D_308cc0();
};
class SimpleFilter1D_308cc0 {
  public:
    SimpleFilter1D_308cc0();
    char pad[0x14];
};
class SimpleFilterAbs3D : public SimpleFilter3D_308cc0 {
  public:
    SimpleFilter1D_308cc0 sub;
    int a, b, c, d;
    float x, y, z;
    unsigned char flag, flag2;
    char pad2[2];
    int last;
    SimpleFilterAbs3D();
    virtual void f();
};
SimpleFilterAbs3D::SimpleFilterAbs3D()
    : SimpleFilter3D_308cc0(), sub(), a(0), b(0), c(0), d(0), x(1.0f), y(1.0f), z(1.0f), flag(1), flag2(0), last(0) {}