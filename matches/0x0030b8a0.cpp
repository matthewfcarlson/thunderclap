class PhysicsJoint3D {
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
    virtual void vfunc_17(float*, float, float*);
};
void PhysicsJoint3D::vfunc_17(float* a, float s, float* b) {
    float d = b[2] * a[2];
    d = d + b[1] * a[1];
    d = d + a[0] * b[0];
    float t = -(d / (s * s));
    b[0] = t * a[0] + b[0];
    b[1] = t * a[1] + b[1];
    b[2] = t * a[2] + b[2];
}
