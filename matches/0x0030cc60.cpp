class PhysicsJoint0D {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5(void*);
};
void PhysicsJoint0D::vfunc_5(void* p) {
    int* q = (int*)p;
    q[2] = 0;
    q[1] = 0;
    q[0] = 0;
}