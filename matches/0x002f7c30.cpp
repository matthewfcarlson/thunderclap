class Context {
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
    virtual int Check(int, int);
};
class Param {
  public:
    virtual void f0();
    char pad[12];
    int value;
    char pad2[0x4c - 0x14];
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
    virtual void Apply(int, int, int);
};
class physics_ImpulseBasedCollisionSolver_2f7c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(Param*, int, int, int);
    virtual void f4();
    Context* ctx;
    char pad[0x34 - 8];
    unsigned char flags;
};
void physics_ImpulseBasedCollisionSolver_2f7c30::vfunc_3(Param* p, int a, int b, int c) {
    if (p && !(flags & 1)) {
        int val = p->value;
        if (ctx->Check(val, a) != 1)
            p->Apply(c, a, b);
    }
}