// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28da60;
struct Buf_28da60 {
    char d[16];
    void Fn(u32_28da60);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28da60, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28da60, u32_28da60);
};
void QuaternionChannel::vfunc_6(u32_28da60 a, u32_28da60 b) {
    Buf_28da60 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
