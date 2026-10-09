class PhysicsObject {
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
    virtual unsigned char vfunc_11();
    char pad[0x1f4 - 4];
    unsigned char mFlag;
};
unsigned char PhysicsObject::vfunc_11() {
    volatile unsigned char* p = &mFlag;
    unsigned char x = *p;
    x >>= 1;
    x &= 1;
    return x;
}