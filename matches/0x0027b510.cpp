#include "compat/ptr.h"
extern "C" char DAT_0042c1b4[];
typedef unsigned char byte_27b510;
void thunk(void*);
class Partition {
  public:
    virtual Partition* vfunc_0(byte_27b510);
    char pad[0x0c];
    void* field10;
};
Partition* Partition::vfunc_0(byte_27b510 param) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c1b4);
    if (field10)
        thunk(field10);
    if (param & 1)
        thunk(this);
    return this;
}