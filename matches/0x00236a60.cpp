#include "compat/ptr.h"
extern "C" char DAT_00427f28[];
class Params {
  public:
    void* x;
    int value;
    Params();
};
Params::Params() : x(0), value(0) {
    x = (void*)((hulk_intptr)DAT_00427f28);
}