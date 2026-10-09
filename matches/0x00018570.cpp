class CExplosionAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool vfunc_7(int);
    virtual void f8();
    char pad[0x18];
    struct A* mA;
    struct B* mB;
};
struct Vec3 {
    int a, b, c;
};
struct A {
    void* Get();
};
struct B {
    char pad[0x10];
    int val;
    Vec3 pos;
};
struct X {
    X* Next();
    void Build(Vec3*, Vec3*);
};
struct Final {
    void Go(Vec3, int, int, int);
};
struct G {
    char pad[0x10];
    Final* f;
};
extern G* gManager;
bool CExplosionAction::vfunc_7(int) {
    X* p = ((X*)mA->Get())->Next();
    Vec3 v = mB->pos;
    Vec3 out;
    p->Build(&v, &out);
    gManager->f->Go(out, mB->val, 0, 0);
    return false;
}
