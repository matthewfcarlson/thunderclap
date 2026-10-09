class PhysicsJoint3D {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void vfunc_5(unsigned int *out);
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28();
    char pad[0x138 - 4];
    unsigned int a,b,c;
};
void PhysicsJoint3D::vfunc_5(unsigned int *out) { out[0]=a; out[1]=b; out[2]=c; }