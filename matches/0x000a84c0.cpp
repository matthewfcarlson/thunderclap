struct Mat {
    int d[16];
};
class Device {
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
    virtual void Set0(int);
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void Set1(int, int, int);
};
class Obj {
    char pad[0x170];
    Device* dev;
    char pad2[4];
    int value;
    float amount;
    Mat mat;

  public:
    void Fn(int, int, const Mat*);
};
void Obj::Fn(int a, int b, const Mat* m) {
    dev->Set1(a, 0, 0);
    dev->Set0(0);
    mat = *m;
    value = b;
    amount = 0.3f;
}