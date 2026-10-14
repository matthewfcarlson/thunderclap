extern int gA_278280;
extern int gB_278280;
void __stdcall cleanup(int);
class XboxSaveDrive {
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
    virtual int f10(int, int);
    virtual void f11(int, int);
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
    char pad[0xc4];
    int refs;
};
int XboxSaveDrive::f10(int a, int b) {
    f11(a, b);
    if (gA_278280 == a)
        gB_278280 = 0;
    cleanup(a);
    refs = refs - 1;
    return 1;
}
