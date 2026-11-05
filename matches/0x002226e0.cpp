#include "compat/ptr.h"
class Inner_2226e0 {
  public:
    void call(int);
};
class Obj_2226e0 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
void Obj_2226e0::target(hulk_intptr a0) {
    ((Inner_2226e0*)((char*)this + 0x10))->call(a0);
}