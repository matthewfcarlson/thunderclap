#include "compat/ptr.h"
extern "C" char DAT_004325f4[];
class Obj_31cb20 {
  public:
    hulk_intptr vptr;
    void Init();
    Obj_31cb20();
};
Obj_31cb20::Obj_31cb20() {
    Init();
    vptr = ((hulk_intptr)DAT_004325f4);
}