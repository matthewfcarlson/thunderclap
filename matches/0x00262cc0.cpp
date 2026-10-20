#include "compat/ptr.h"
typedef unsigned int uint_262cc0;
int FUN_0024c310(hulk_intptr);
int FUN_0024c2f0(void*);
struct Base_262cc0 {
    virtual void f0();
    virtual void f1();
    virtual int f2();
};
struct HalRadicalAdpcmDecodeStream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual uint_262cc0 v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    Base_262cc0* member4;
    uint_262cc0 vfunc_3();
};
uint_262cc0 HalRadicalAdpcmDecodeStream::vfunc_3() {
    uint_262cc0 a = member4->f2();
    uint_262cc0 b = FUN_0024c310(a);
    void* p = (char*)this + 8;
    uint_262cc0 c = FUN_0024c2f0(p);
    uint_262cc0 d = FUN_0024c310((hulk_intptr)p);
    return c * b / d;
}