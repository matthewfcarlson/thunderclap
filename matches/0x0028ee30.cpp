#include "compat/ptr.h"
typedef unsigned int u32_28ee30;
struct Receiver_28ee30 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(u32_28ee30, u32_28ee30);
};
struct ShaderIntBroadcast {
    char pad[8];
    u32_28ee30 mA;
    u32_28ee30 mB;
    hulk_intptr vfunc_3(void* param);
};
hulk_intptr ShaderIntBroadcast::vfunc_3(void* param) {
    if (param) {
        Receiver_28ee30* r = *(Receiver_28ee30**)((char*)param + 0x10);
        r->f6(mA, mB);
    }
    return (hulk_intptr)param;
}
