// Same code shape as 0x002226e0 (propagated; names are from that function)
#include "compat/ptr.h"
class Inner_222710 {
  public:
    void call(int);
};
class Obj_222710 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
void Obj_222710::target(hulk_intptr a0) {
    ((Inner_222710*)((char*)this + 0x10))->call(a0);
}