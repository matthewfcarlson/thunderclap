// Same code shape as 0x00080ba0 (propagated; names are from that function)
#include "decls/data/engine/physics.h"

class Obj_2f2750 {
  public:
    int method(unsigned int, unsigned int);
};
extern "C" int FUN_002f2750(unsigned int a, unsigned int b) {
    return (*(Obj_2f2750**)&DAT_00554c30)->method(a, b);
}