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
    virtual void f9(int);
    char pad[0x6c];
    int value;
    void Func(int x);
};
void Obj::Func(int x) {
    value = x;
    f9(0);
}