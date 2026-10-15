namespace pure3d {
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
    virtual void f23(float*, float);
    virtual void vfunc_24(float, float, float);
    virtual void f25(float, float*, float*);
    virtual void f26();
};
void Camera::vfunc_24(float a, float b, float c) {
    float p[3];
    float q[3];
    f25(a, p, q);
    f23(p, b);
    f23(q, c);
}
} // namespace pure3d