// Same code shape as 0x00269560 (propagated; names are from that function)
typedef unsigned char u8_26f760;
extern void __cdecl release(int, void*);
extern int globalValue;
class XboxDrive_26f760 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual XboxDrive_26f760* f2(u8_26f760);
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
XboxDrive_26f760* XboxDrive_26f760::f2(u8_26f760 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}