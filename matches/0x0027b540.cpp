#include "compat/ptr.h"
extern "C" char DAT_0042c1b4[];
// Same code shape as 0x0027b510 (propagated; names are from that function)
typedef unsigned char byte_27b540;
void thunk(void*);
class Limb_27b540 {
  public:
    virtual Limb_27b540* vfunc_0(byte_27b540);
    char pad[0x0c];
    void* field10;
};
Limb_27b540* Limb_27b540::vfunc_0(byte_27b540 param) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c1b4);
    if (field10)
        thunk(field10);
    if (param & 1)
        thunk(this);
    return this;
}