class X_2c3f00 {
  public:
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}
    virtual void f5() {}
    virtual void f6() {}
    virtual void f7() {}
    virtual void f8() {}
    virtual void f9(int v);
    char pad[0x58 - 4];
    int a;
    int b;
    int c;
    void Set(int x, int y, int z);
};

void X_2c3f00::Set(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
    f9(0);
}
