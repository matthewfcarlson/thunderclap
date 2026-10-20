#include "compat/ptr.h"
extern "C" char DAT_0041460c[];
class Obj_151bc0 {
  public:
    virtual void F();
    virtual void G();
};
struct Ctor_00232660 {
    Ctor_00232660();
};
class Hit_151bc0 : public Ctor_00232660 {
  public:
    volatile int v;
    char pad[0x18];
    volatile int a;
    Obj_151bc0* b;
    char gap[0x1c];
    Hit_151bc0(int p, Obj_151bc0* q);
};
Hit_151bc0::Hit_151bc0(int p, Obj_151bc0* q) : Ctor_00232660() {
    v = ((hulk_intptr)DAT_0041460c);
    a = 0;
    b = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x40) = 0;
    a = p;
    if (q)
        q->F();
    if (b)
        b->G();
    b = q;
}