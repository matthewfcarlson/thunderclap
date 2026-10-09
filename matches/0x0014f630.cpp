struct X {
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
    X* member;
};
bool NoHitPushbackAction::vfunc_3(void*, void*) {
    X* p = member;
    if (p) {
        X* a = (X*)p->a();
        X* b = (X*)a->b();
        b->c(1);
    }
    return true;
}