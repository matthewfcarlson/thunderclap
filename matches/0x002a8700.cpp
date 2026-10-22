#include "compat/ptr.h"
extern "C" char DAT_0042dd24[];
class SimpleFrameController_2a8700 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
};
class ShaderAnimationController_2a8700 : public SimpleFrameController_2a8700 {
  public:
    char pad[0x40 - sizeof(SimpleFrameController_2a8700)];
    SimpleFrameController_2a8700* mRef;
    virtual SimpleFrameController_2a8700* own4();
    void setup(ShaderAnimationController_2a8700*);
};
extern void* __cdecl alloc(hulk_uintptr);
SimpleFrameController_2a8700* ShaderAnimationController_2a8700::own4() {
    ShaderAnimationController_2a8700* self = this;
    ShaderAnimationController_2a8700* p = (ShaderAnimationController_2a8700*)alloc(0x48);
    if (p) {
        p->setup(self);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0042dd24);
        p->mRef = 0;
        SimpleFrameController_2a8700* q = self->mRef;
        if (q)
            q->v0();
        if (p->mRef)
            p->mRef->v1();
        p->mRef = q;
        return (SimpleFrameController_2a8700*)p;
    }
    return 0;
}