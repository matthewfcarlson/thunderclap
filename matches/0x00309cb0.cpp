extern const float zero;
class PhysicsJoint1D {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[0xe8];
    char flag;
    char pad2[0xf];
    float a, b, c, d, e;
    void vfunc_21(float* p);
};
void PhysicsJoint1D::vfunc_21(float* p) {
    if ((a * p[0] + b * p[1] + c * p[2]) * e < zero) {
        flag = 1;
        d = -e;
    }
}