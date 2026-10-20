#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
class Obj_1762c0 {
  public:
    virtual void F0();
    virtual void F1();
};
class Base_1762c0 {
  public:
    void Finish();
};
class TargetIconDistanceAction : public Base_1762c0 {
  public:
    int vptr;
    char pad04[0x18];
    Obj_1762c0* m1c;
    Obj_1762c0* m20;
    void Clean();
};
extern int vt_1762c0;
void TargetIconDistanceAction::Clean() {
    vptr = (hulk_intptr)&vt_1762c0;
    _ReadWriteBarrier();
    Obj_1762c0* p = m20;
    if (p) {
        p->F1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Finish();
}