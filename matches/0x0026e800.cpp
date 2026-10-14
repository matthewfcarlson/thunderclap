class Helper_26e800 {
  public:
    void call(void*, unsigned int);
};
class DebugConsole {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7(int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    char pad[0x98 - 4];
    int field98;
    char pad2[0xa4 - 0x9c];
    Helper_26e800* fieldA4;
};
void DebugConsole::vfunc_7(int param) {
    int local[3];
    local[0] = 5;
    local[1] = (int)this;
    local[2] = param;
    fieldA4->call(local, 12);
    field98 = param;
}