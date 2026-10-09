class Camera {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void vfunc_25(float*, float*, float*);
    virtual void f26();
    char pad[0x18];
    float a, b, c, d;
};
void Camera::vfunc_25(float* x, float* y, float* z) {
    float q = 1.0f / a;
    float r = 1.0f / b;
    y[0] = *x / (q * c * 0.5f);
    y[1] = x[1] / (q * d * 0.5f);
    y[2] = a;
    z[0] = *x / (r * c * 0.5f);
    z[1] = x[1] / (r * d * 0.5f);
    z[2] = b;
}