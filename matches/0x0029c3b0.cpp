#include "decls/data/engine/unknown.h"
// data: gThing_29c3b0 = DAT_0052cba0

class Thing_29c3b0 {
  public:
    virtual void F(int);
};
void FUN_0029c3b0() {
    if ((*(Thing_29c3b0**)&DAT_0052cba0))
        (*(Thing_29c3b0**)&DAT_0052cba0)->F(1);
    (*(Thing_29c3b0**)&DAT_0052cba0) = 0;
}