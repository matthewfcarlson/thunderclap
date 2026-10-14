class HalStream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};
class Device_263050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int, unsigned, int);
};
class HalRsdFileStream : public HalStream {
  public:
    char pad04[0x20 - 4];
    Device_263050* device;
    char pad24[8];
    unsigned length;
    char pad30[0x3c - 0x30];
    unsigned amount;
    char pad40[4];
    unsigned state;
    void vfunc_6(int, int, unsigned);
};
void HalRsdFileStream::vfunc_6(int a, int b, unsigned n) {
    if (length < n)
        amount = length;
    else
        amount = n;
    if (amount > 0) {
        device->v3(a, amount, b);
        state = 5;
        return;
    }
    state = 6;
}
