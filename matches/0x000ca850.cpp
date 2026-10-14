class X_ca850 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
    void target();
};

void X_ca850::target() {
    f5(0);
}
