// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28ddf0;
struct Buf_28ddf0 {
    char d[16];
    void Fn(u32_28ddf0);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28ddf0, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28ddf0, u32_28ddf0);
};
void QuaternionChannel::vfunc_6(u32_28ddf0 a, u32_28ddf0 b) {
    Buf_28ddf0 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
