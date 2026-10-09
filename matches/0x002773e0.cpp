class CementLibrary {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6();
    virtual void f7();
    virtual void f8();
    char pad[0x20 - 4];
    int value;
};
bool CementLibrary::vfunc_6() {
    return value == 1;
}