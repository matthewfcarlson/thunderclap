#include "decls/data/engine/pure3d.h"
// data: gThing_31e1f0 = DAT_005554ac

class Thing_31e1f0 {
  public:
    virtual void Call(int, int);
};
extern "C" void FUN_0031e1f0(int a, int b) {
    if ((*(Thing_31e1f0**)&DAT_005554ac))
        (*(Thing_31e1f0**)&DAT_005554ac)->Call(a, b);
}