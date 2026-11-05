// Same code shape as 0x002226e0 (propagated; names are from that function)
#include "compat/ptr.h"
class Inner_222720 {
  public:
    void call(int);
};
class Obj_222720 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
void Obj_222720::target(hulk_intptr a0) {
    ((Inner_222720*)((char*)this + 0x10))->call(a0);
}