#include "compat/ptr.h"
class Ref_305320 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int collisionVtable;
class H38_305320 {
  public:
    void run38();
};
class H10_305320 {
  public:
    void run10();
};
class H0_305320 {
  public:
    void run0();
};
namespace physics { class CollisionObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual CollisionObject* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    char pad10[0x1c];
    int field20;
    char pad24[12];
    hulk_intptr field30;
    char pad34[4];
}; }
void __cdecl freeA(void*);
void __cdecl freeB(void*);
physics::CollisionObject* physics::CollisionObject::vfunc_2(unsigned char p) {
    *(hulk_intptr*)this = (hulk_intptr)&collisionVtable;
    if (field20) {
        Ref_305320* r = *(Ref_305320**)&field20;
        r->f1();
    }
    ((H38_305320*)((char*)this + 0x38))->run38();
    if (field30)
        freeA((char*)field30 - 4);
    ((H10_305320*)((char*)this + 0x10))->run10();
    ((H0_305320*)this)->run0();
    if (p & 1)
        freeB(this);
    return this;
}