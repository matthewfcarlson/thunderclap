// Same code shape as 0x00269560 (propagated; names are from that function)
typedef unsigned char u8_278a80;
extern void __cdecl release(int, void*);
extern int globalValue;
class XboxSaveDrive_278a80 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual XboxSaveDrive_278a80* f2(u8_278a80);
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
XboxSaveDrive_278a80* XboxSaveDrive_278a80::f2(u8_278a80 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}