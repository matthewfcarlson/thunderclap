typedef unsigned int u32_177c20;
struct C_177c20 {
    bool go(u32_177c20, u32_177c20);
};
class Param {
  public:
    char pad[0xc];
    u32_177c20 fn;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    bool vfunc_6(u32_177c20 a, u32_177c20 b, u32_177c20 c);
};
bool Param::vfunc_6(u32_177c20 a, u32_177c20 b, u32_177c20 c) {
    if (!fn)
        return false;
    typedef bool (C_177c20::*Fn)(u32_177c20, u32_177c20);
    Fn p = *(Fn*)&fn;
    return ((C_177c20*)a->*p)(b, c);
}