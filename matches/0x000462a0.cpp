#include "compat/ptr.h"
extern "C" char hulk_at_003f6334[];
class Base_462a0 {
  public:
    int vptr;
    Base_462a0();
    int data;
};
Base_462a0::Base_462a0() {
    vptr = ((hulk_intptr)(hulk_at_003f6334 + 0x4));
}
