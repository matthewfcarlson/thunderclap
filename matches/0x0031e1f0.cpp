#include "decls/data/engine/pure3d.h"
// data: gThing_31e1f0 = DAT_005554ac

class Thing_31e1f0 {
  public:
    virtual void Call(int, int);
};
void thunk(int a, int b) {
    if ((*(Thing_31e1f0**)&DAT_005554ac))
        (*(Thing_31e1f0**)&DAT_005554ac)->Call(a, b);
}