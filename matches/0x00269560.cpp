typedef unsigned char u8_269560;
extern void __cdecl release(int, void*);
extern int globalValue;
class ControllerSystemXBox {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual ControllerSystemXBox* f2(u8_269560);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
ControllerSystemXBox* ControllerSystemXBox::f2(u8_269560 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}