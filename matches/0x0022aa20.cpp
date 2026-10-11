extern "C" char DAT_00427534[];
class Base {
  public:
    void Fn();
};
class LocomotionDriver {
  public:
    virtual void f0();
    virtual void f1();
    virtual LocomotionDriver* vfunc_2(int);
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
};
extern int g_count;
extern void __cdecl thunk_FUN_00267090(LocomotionDriver*);
LocomotionDriver* LocomotionDriver::vfunc_2(int flags) {
    *(void**)this = (void*)((int)DAT_00427534);
    g_count--;
    ((Base*)this)->Fn();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}