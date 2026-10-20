#include "compat/ptr.h"
extern "C" char DAT_0042db8c[];
typedef unsigned char u8_2a7aa0;
struct SceneGraphTransformAnimationController {
    virtual void v0();
    virtual void v1();
    virtual SceneGraphTransformAnimationController* vfunc_2(u8_2a7aa0);
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    void init();
    char pad[0x110 - 4];
    int member;
};
void destroy(SceneGraphTransformAnimationController*);
SceneGraphTransformAnimationController* SceneGraphTransformAnimationController::vfunc_2(u8_2a7aa0 flag) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042db8c);
    member = 0;
    init();
    if (flag & 1)
        destroy(this);
    return this;
}