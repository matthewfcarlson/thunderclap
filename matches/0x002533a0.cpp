#include "compat/ptr.h"
extern int vtable_2533a0;
class SeqEventVarPitchRand {
  public:
    void init();
    SeqEventVarPitchRand();
    hulk_intptr vptr;
    int unused;
    int a;
    int b;
};
SeqEventVarPitchRand::SeqEventVarPitchRand() {
    init();
    vptr = (hulk_intptr)&vtable_2533a0;
    a = 0x3f4ccccd;
    b = 0x3f99999a;
}
