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
    struct A_18570* mA;
    struct B_18570* mB;
};
struct Vec3_18570 {
    int a, b, c;
};
struct A_18570 {
    void* Get();
};
struct B_18570 {
    char pad[0x10];
    int val;
    Vec3_18570 pos;
};
struct X_18570 {
    X_18570* Next();
    void Build(Vec3_18570*, Vec3_18570*);
};
struct Final_18570 {
    void Go(Vec3_18570, int, int, int);
};
struct G_18570 {
    char pad[0x10];
    Final_18570* f;
};
extern G_18570* gManager_18570;
bool CExplosionAction::vfunc_7(int) {
    X_18570* p = ((X_18570*)mA->Get())->Next();
    Vec3_18570 v = mB->pos;
    Vec3_18570 out;
    p->Build(&v, &out);
    gManager_18570->f->Go(out, mB->val, 0, 0);
    return false;
}
