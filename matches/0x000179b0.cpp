struct Manager_179b0;
struct Ctx_179b0 {
    Manager_179b0* f();
};
struct Manager_179b0 {
    Manager_179b0* g();
};
class X_179b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
};
class CAlertStatusAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual bool vfunc_6(int);
    virtual void a7();
    virtual void a8();
    char pad[0x18];
    Ctx_179b0* member;
    int arg;
};
bool CAlertStatusAction::vfunc_6(int) {
    Manager_179b0* p = member->f();
    p = p->g();
    X_179b0* x = *(X_179b0**)((char*)p + 0x1ca0);
    if (x)
        x->f8(arg);
    return false;
}