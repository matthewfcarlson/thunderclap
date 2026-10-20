#include "compat/ptr.h"
extern "C" char DAT_00431b08[];
class Ref_304ff0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CollisionObject {
  public:
    unsigned long vptr;
    char pad4[0x1c];
    Ref_304ff0* mRef;
    char pad24[0xc];
    void* mPtr;
    char pad34[4];
    char sub[0x10];
    void destroy();
};
class H38_304ff0 {
  public:
    void run();
};
class H10_304ff0 {
  public:
    void run();
};
class Htail {
  public:
    void run();
};
extern void thunk(void*);
void CollisionObject::destroy() {
    Ref_304ff0* r = mRef;
    vptr = ((hulk_intptr)DAT_00431b08);
    if (r)
        r->f1();
    ((H38_304ff0*)sub)->run();
    if (mPtr)
        thunk((char*)mPtr - 4);
    ((H10_304ff0*)((char*)this + 0x10))->run();
    ((Htail*)this)->run();
}