struct X_14f630 {
    void* a();
    void* b();
    void c(int);
};
class NoHitPushbackAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    X_14f630* member;
};
bool NoHitPushbackAction::vfunc_3(void*, void*) {
    X_14f630* p = member;
    if (p) {
        X_14f630* a = (X_14f630*)p->a();
        X_14f630* b = (X_14f630*)a->b();
        b->c(1);
    }
    return true;
}