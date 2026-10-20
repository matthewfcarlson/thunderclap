// Same code shape as 0x00269560 (propagated; names are from that function)
typedef unsigned char u8_334040;
extern void __cdecl release(int, void*);
extern int globalValue;
class PlayerBink_334040 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual PlayerBink_334040* f2(u8_334040);
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
PlayerBink_334040* PlayerBink_334040::f2(u8_334040 flag) {
    cleanup();
    if (flag & 1)
        release(globalValue, this);
    return this;
}