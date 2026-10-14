// Same code shape as 0x00177c20 (propagated; names are from that function)
typedef unsigned int u32_1a1950;
struct C_1a1950 {
    bool go(u32_1a1950, u32_1a1950);
};
class Param {
  public:
    char pad[0xc];
    u32_1a1950 fn;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    bool vfunc_6(u32_1a1950 a, u32_1a1950 b, u32_1a1950 c);
};
bool Param::vfunc_6(u32_1a1950 a, u32_1a1950 b, u32_1a1950 c) {
    if (!fn)
        return false;
    typedef bool (C_1a1950::*Fn)(u32_1a1950, u32_1a1950);
    Fn p = *(Fn*)&fn;
    return ((C_1a1950*)a->*p)(b, c);
}