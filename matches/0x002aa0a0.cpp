#include "compat/ptr.h"
extern void* __cdecl alloc(hulk_uintptr);
inline void* operator new(unsigned int, void* where) {
    return where;
}

class SimpleFrameController_2aa0a0 {
  public:
    SimpleFrameController_2aa0a0(void* parent);
    virtual void b0();
    char pad[0x3c];
};

class ExpressionAnimationController_2aa0a0 : public SimpleFrameController_2aa0a0 {
  public:
    ExpressionAnimationController_2aa0a0(void* parent) : SimpleFrameController_2aa0a0(parent) {
        m[0] = 0;
        m[1] = 0;
        m[2] = 0;
        m[3] = 0;
    }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual ExpressionAnimationController_2aa0a0* f4();
    void g(int v);
    int m[4];
};

ExpressionAnimationController_2aa0a0* ExpressionAnimationController_2aa0a0::f4() {
    ExpressionAnimationController_2aa0a0* p = (ExpressionAnimationController_2aa0a0*)alloc(0x50);
    ExpressionAnimationController_2aa0a0* z = 0;
    if (p != z) {
        new (p) ExpressionAnimationController_2aa0a0(this);
        p->g(m[0]);
        return p;
    }
    return z;
}
