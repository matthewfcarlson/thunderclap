class CActorManager {
  public:
    void f();
};
class Method0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[0x1c - 4];
    void (CActorManager::*mFn)();
    void vfunc_2(CActorManager*, void*, void*);
};
void Method0::vfunc_2(CActorManager* a, void*, void*) {
    (a->*mFn)();
}
