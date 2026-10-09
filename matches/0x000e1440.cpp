class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(int, int);
};
class FEAnimation {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4(int);
    virtual void f5();
    virtual void f6();
    char pad[8];
    Obj* mObj;
};
void FEAnimation::vfunc_4(int) {
    if (mObj)
        mObj->g(0, 0);
}