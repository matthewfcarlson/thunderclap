class Obj_e6b80 {
  public:
    void Helper(int);
};
class FEThingsBase {
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
    virtual void vfunc_19(int);
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27(int);
    char pad[0x175c - 4];
    Obj_e6b80* a;
    char p2[8];
    int b;
    int d;
    char p3[0x17f8 - 0x1770];
    int c;
};
void FEThingsBase::vfunc_19(int x) {
    if ((Obj_e6b80*)x != a) {
        b = x;
        if (x) {
            f27(x);
            c = 3;
            d = 2;
            if (a)
                a->Helper(2);
        }
    }
}
