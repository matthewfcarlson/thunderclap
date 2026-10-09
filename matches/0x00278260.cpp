class XboxSaveDrive {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual unsigned int vfunc_6();
    char pad[0xc4 - 4];
    unsigned int value;
};
unsigned int XboxSaveDrive::vfunc_6() {
    return value;
}