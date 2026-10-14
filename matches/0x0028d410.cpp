// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28d410;
struct Buf_28d410 {
    char d[16];
    void Fn(u32_28d410);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28d410, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28d410, u32_28d410);
};
void QuaternionChannel::vfunc_6(u32_28d410 a, u32_28d410 b) {
    Buf_28d410 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
