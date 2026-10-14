struct Trio_30d5f0 {
    int a, b, c;
    Trio_30d5f0() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
struct Sub_30d5f0 {
    char pad[0x1c];
    Sub_30d5f0() throw();
};
void* operator new(unsigned) throw();

class PhysicsJoint {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual PhysicsJoint* vf27();
    virtual void vf28(PhysicsJoint*);
    PhysicsJoint() throw() {}
    char pad1[0x1c];
    Trio_30d5f0 t;
    char pad2[0x1c];
    Sub_30d5f0 s48;
    Sub_30d5f0 s64;
    char pad3[0x120 - 0x80];
};

class PhysicsJoint1D : public PhysicsJoint {
  public:
    PhysicsJoint1D() throw() {}
    void Init(PhysicsJoint1D*);
    virtual PhysicsJoint* vf27();
};

PhysicsJoint* PhysicsJoint1D::vf27() {
    PhysicsJoint1D* clone = new PhysicsJoint1D;
    clone->Init(this);
    this->vf28(clone);
    return clone;
}
