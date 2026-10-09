class C {
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
    char pad[0x18 - 4];
    int value;
    void set(int x);
};
void C::set(int x) {
    value = x;
    f7();
}