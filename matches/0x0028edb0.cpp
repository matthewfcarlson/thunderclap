#include "compat/ptr.h"
extern "C" char DAT_0042cb44[];
typedef unsigned int u32_28edb0;
struct Service_28edb0 {
    virtual void f0();
};
struct Manager_28edb0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual Service_28edb0* Get(const char*, int);
};
extern Manager_28edb0* gManager_28edb0;
struct Base_28edb0 {
    Base_28edb0();
};
struct Shader : Base_28edb0 {
    void* vtable;
    char pad4[0xc];
    Service_28edb0* mService;
    unsigned char flag;
    char pad15[3];
    u32_28edb0 value;
    Shader();
};
Shader::Shader() {
    vtable = (void*)((hulk_intptr)DAT_0042cb44);
    flag = 0;
    value = 0;
    mService = gManager_28edb0->Get("simple", 0);
    mService->f0();
}