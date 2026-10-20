// Same code shape as 0x00177c20 (propagated; names are from that function)
#include "compat/ptr.h"
typedef unsigned int u32_1a19f0;
struct C_1a19f0 {
    bool go(u32_1a19f0, u32_1a19f0);
};
class Param {
  public:
    char pad[0xc];
    u32_1a19f0 fn;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    bool vfunc_6(hulk_uintptr a, u32_1a19f0 b, u32_1a19f0 c);
};
bool Param::vfunc_6(hulk_uintptr a, u32_1a19f0 b, u32_1a19f0 c) {
    if (!fn)
        return false;
    typedef bool (C_1a19f0::*Fn)(u32_1a19f0, u32_1a19f0);
    Fn p = *(Fn*)&fn;
    return ((C_1a19f0*)a->*p)(b, c);
}