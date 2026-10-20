// Same code shape as 0x00269560 (propagated; names are from that function)
typedef unsigned char u8_26cbd0;
extern void __cdecl release(int, void*);
extern int globalValue;
class MemoryDlAllocator_26cbd0 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual MemoryDlAllocator_26cbd0* f2(u8_26cbd0);
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
MemoryDlAllocator_26cbd0* MemoryDlAllocator_26cbd0::f2(u8_26cbd0 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}