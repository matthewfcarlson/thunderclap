#include "compat/ptr.h"
extern "C" char DAT_0042d2dc[];
class Obj_2970a0 {
  public:
    virtual void a();
    virtual void b();
};
class Scenegraph {
  public:
    virtual void v0();
    virtual void v1();
    virtual Scenegraph* vfunc_2(unsigned char);
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
    char pad[0x3c];
    Obj_2970a0* volatile mObj;
    void cleanup();
};
void __cdecl thunk(Scenegraph*);
Scenegraph* Scenegraph::vfunc_2(unsigned char flag) {
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_0042d2dc);
    Obj_2970a0* p = mObj;
    if (p) {
        p->b();
        mObj = 0;
    }
    cleanup();
    if (flag & 1)
        thunk(this);
    return this;
}