#include "compat/ptr.h"
extern "C" char DAT_004298fc[];
extern int SeqActionVftable;
extern int gBss_253a10;
extern void __cdecl FUN_00247550(void*, void*);
class SeqAction {
  public:
    int* vptr;
};
class SeqActionVarPitch : public SeqAction {
  public:
    SeqAction* vfunc_0(int);
};
SeqAction* SeqActionVarPitch::vfunc_0(int flag) {
    SeqAction* self = this;
    vptr = (int*)((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550(&gBss_253a10, self);
    return self;
}