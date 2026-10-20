// Same code shape as 0x0013a8e0 (propagated; names are from that function)
#include "compat/ptr.h"
typedef unsigned char byte_1447b0;
class Sub_1447b0 {
  public:
    void f();
};
class Base_1447b0 {
  public:
    void g();
};
extern void cdel(void*);
extern int vftable_1447b0;
class HitEffectTrack_1447b0 {
  public:
    int vf;
    char pad1[0x18 - 4];
    Sub_1447b0 a;
    char pad2[0x28 - 0x18 - 1];
    Sub_1447b0 b;
    HitEffectTrack_1447b0* vfunc_5(byte_1447b0 param);
};
HitEffectTrack_1447b0* HitEffectTrack_1447b0::vfunc_5(byte_1447b0 param) {
    vf = (hulk_intptr)&vftable_1447b0;
    b.f();
    a.f();
    ((Base_1447b0*)this)->g();
    if (param & 1)
        cdel(this);
    return this;
}
