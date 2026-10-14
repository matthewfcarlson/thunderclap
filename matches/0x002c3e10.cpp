class Base_2c3e10 {
  public:
    virtual void f();
    Base_2c3e10();
};
class PointLight : public Base_2c3e10 {
  public:
    char pad[0x50];
    int a;
    float b;
    int c, d, e;
    PointLight();
};
PointLight::PointLight() : Base_2c3e10() {
    c = 0;
    d = 0;
    e = 0;
    b = 1.0f;
    a = 1;
}