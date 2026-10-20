#include "compat/ptr.h"
struct A_484c0 {
    void* f();
};
struct B_484c0 {
    int f();
};
struct CButtonCondition {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(void*);
    virtual void f10();
    char pad[8];
    int mIndex;
};
void CButtonCondition::f9(void* arg) {
    void* p = ((A_484c0*)arg)->f();
    hulk_intptr v = ((B_484c0*)p)->f();
    f9((void*)(v + 0x1f58 + mIndex * 12));
}
