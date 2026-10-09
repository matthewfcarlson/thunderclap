class Obj;
class Inner {
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
    virtual void f15(int, Obj*);
};
class Obj {
  public:
    char pad[0x14];
    Inner* m;
    int method(int);
};
int Obj::method(int param) {
    m->f15(param, this);
    return param;
}