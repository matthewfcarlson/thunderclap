class SimpleFrameController {
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void vfunc_24(int, int, int);
    virtual void f25();
    char pad[0x38];
};
class D {
  public:
    void* get(void*, int);
};
class C {
  public:
    D* go(int);
};
class SceneGraphVisibilityAnimationController : public SimpleFrameController {
  public:
    C* field3c;
    void* field40;
    virtual void vfunc_24(int, int, int);
};
void SceneGraphVisibilityAnimationController::vfunc_24(int a, int b, int c) {
    SimpleFrameController::vfunc_24(a, b, c);
    D* d = field3c->go(0);
    field40 = d->get((void*)0x00534956, 0x4c4f4f42);
}
