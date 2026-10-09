// Same code shape as 0x002c3cc0 (propagated; names are from that function)
class ProximityLight {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int, int, int);
    virtual void f8();
    virtual void f9(int);
    int pad[5];
    int a, b, c;
};
void ProximityLight::f7(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
    f9(1);
}