class Obj {
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
    virtual __int64 get();
    virtual void f15();
    virtual __int64 convert(__int64);
    virtual void finish();
    __int64 run();
};
__int64 Obj::run() {
    __int64 y = convert(get());
    finish();
    return y;
}