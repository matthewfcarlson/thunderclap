class X {
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
    void set(int, int, int);
};
void X::set(int a, int b, int c) {
    *(int*)((char*)this + 0x60) = c;
    f9(0);
}