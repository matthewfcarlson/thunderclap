typedef unsigned int u32_28ab20;
struct Buf_28ab20 {
    char d[16];
    void Fn(u32_28ab20);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28ab20, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28ab20, u32_28ab20);
};
void QuaternionChannel::vfunc_6(u32_28ab20 a, u32_28ab20 b) {
    Buf_28ab20 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
