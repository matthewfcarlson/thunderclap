// Same code shape as 0x00269560 (propagated; names are from that function)
typedef unsigned char u8_26ee30;
extern void __cdecl release(int, void*);
extern int globalValue;
class DebugConsole_26ee30 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual DebugConsole_26ee30* f2(u8_26ee30);
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
DebugConsole_26ee30* DebugConsole_26ee30::f2(u8_26ee30 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}