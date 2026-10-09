struct PhysicsJoint {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
};
struct PhysicsJoint1D : PhysicsJoint {
    virtual void b15();
    virtual void b16(unsigned int, float*);
    virtual void b17();
    virtual void vfunc_18(unsigned int, float*);
    char pad[0xe4];
    float scale;
};
void PhysicsJoint1D::vfunc_18(unsigned int p, float* v) {
    b16(p, v);
    float f = scale;
    v[0] = f * v[0];
    v[1] = f * v[1];
    v[2] = f * v[2];
}
