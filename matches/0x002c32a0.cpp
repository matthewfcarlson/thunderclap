class Base {
  public:
    virtual void f();
    char pad[0xcc];
    Base();
};
class PointCamera : public Base {
  public:
    int a, b, c, d, e, f0, g;
    float h;
    int i, j;
    PointCamera();
    virtual void f();
};
PointCamera::PointCamera() {
    volatile int* p = &a;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[8] = 0;
    h = 1.0f;
    p[9] = 0;
}