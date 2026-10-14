class ControllerSystemXBox {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7(int, int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    char pad[16];
    int mDiff;
    char gap[8];
    char data[4 * 0x4a0];
};
int helper();
class Pad_2683f0 {
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
    virtual void f18(int);
};
void ControllerSystemXBox::vfunc_7(int a, int b) {
    mDiff = b - a;
    char* p = data;
    int i = 4;
    do {
        if (p[0x49e]) {
            Pad_2683f0* q = (Pad_2683f0*)p;
            q->f18(helper() + mDiff);
        }
        p += 0x4a0;
        --i;
    } while (i);
}