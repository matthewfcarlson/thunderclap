// Same code shape as 0x00269560 (propagated; names are from that function)
typedef unsigned char u8_277b10;
extern void __cdecl release(int, void*);
extern int globalValue;
class CementLibrary_277b10 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual CementLibrary_277b10* f2(u8_277b10);
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
CementLibrary_277b10* CementLibrary_277b10::f2(u8_277b10 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}