extern void* __cdecl FUN_0008d690(unsigned int);
class Helper {
  public:
    int make(void*, unsigned int);
};
class FEContainer {
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
    virtual int vfunc_21(int);
    virtual int vfunc_22(int);
};
int FEContainer::vfunc_22(int param) {
    void* p = FUN_0008d690(0x270);
    int r;
    if (p)
        r = ((Helper*)p)->make(this, param);
    else
        r = 0;
    vfunc_21(r);
    return r;
}