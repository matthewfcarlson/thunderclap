class Inner_1c1310 {
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
    virtual int f18(void*, unsigned);
};
class Outer_1c1310 {
    char pad[8];

  public:
    Inner_1c1310* p;
    int target(void* arg);
};
int Outer_1c1310::target(void* arg) {
    Inner_1c1310* q = p;
    return q->f18(arg, *(unsigned*)((char*)arg + 12));
}