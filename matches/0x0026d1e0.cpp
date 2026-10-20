#include "compat/ptr.h"
extern "C" char DAT_0042af64[];
// Same code shape as 0x00267ed0 (propagated; names are from that function)
class Object_26d1e0 {
  public:
    virtual void vfunc_0();
};
class RefCount_26d1e0 : public Object_26d1e0 {
  public:
    int field;
    virtual RefCount_26d1e0* vfunc_0(unsigned char);
};
extern volatile int g_saved;
extern void __cdecl FUN_00266f00(int, RefCount_26d1e0*);
RefCount_26d1e0* RefCount_26d1e0::vfunc_0(unsigned char param) {
    g_saved = field;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042af64);
    if (param & 1)
        FUN_00266f00(g_saved, this);
    return this;
}