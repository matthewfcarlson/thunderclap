#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
class Ref_195150 {
  public:
    virtual void a();
    virtual void Release();
};
extern int vt_195150;
class FireProjectileAction {
  public:
    hulk_intptr vptr;
    char pad[0x18];
    int m1c;
    Ref_195150* m20;
    int m24;
    Ref_195150* m28;
    Ref_195150* m2c;
    void finish();
    void clean();
};
void FireProjectileAction::clean() {
    vptr = (hulk_intptr)&vt_195150;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    finish();
}
