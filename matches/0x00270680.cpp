class ControllerBuffer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    char pad[0x18 - 4];
    int field;
    void vfunc_3(int, int);
};
void ControllerBuffer::vfunc_3(int a, int b) {
    field = b;
    f4(a);
}