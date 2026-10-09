namespace core {
class ControllerSystemXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(int);
    virtual void f7(int, int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    char pad[0x10 - 4];
    unsigned char active;
    char pad1[7];
    int param;
    char pad2[0x12a0 - 0x1c];
    int field;
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20(int, int);
};
} // namespace core
void core::ControllerSystemXBox::vfunc_6(int p) {
    if (p == 0) {
        active = 0;
        f7(p, p);
        p = 10;
    } else
        active = 1;
    int x = field;
    param = p;
    ControllerSystemXBox* q = (ControllerSystemXBox*)((char*)this + 0x20);
    for (int i = 0; i < 4; i++, q = (ControllerSystemXBox*)((char*)q + 0x4a0))
        if (*((char*)q + 0x49e))
            q->g20(p, x);
}