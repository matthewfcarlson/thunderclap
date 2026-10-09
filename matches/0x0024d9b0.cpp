class ListenerEffectGc {
  public:
    virtual void f0();
    virtual void f1();
    virtual ListenerEffectGc* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};
extern void FUN_00244f70();
extern void FUN_00247550(void*, void*);
char g_4e64d8;
ListenerEffectGc* ListenerEffectGc::vfunc_2(int flags) {
    FUN_00244f70();
    if (flags & 1)
        FUN_00247550(&g_4e64d8, this);
    return this;
}