// Same code shape as 0x0028a9f0 (propagated; names are from that function)
class QuaternionChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, void*);
    virtual void f4(int, int);
    virtual void f5();
    virtual void f6();
    void vfunc_4(int a, int b, int c);
};
struct Helper_28d2a0 {
    void call(int);
};
void QuaternionChannel::vfunc_4(int a, int b, int c) {
    char local[16];
    f3(a, b, local);
    ((Helper_28d2a0*)local)->call(*(int*)(&b + 1));
}