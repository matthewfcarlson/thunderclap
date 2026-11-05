#include "compat/ptr.h"
class Sub_1c3b20 {
  public:
    int Fn(int, int);
};

class C_1c3b20 {
  public:
    char pad[8];
    Sub_1c3b20* mSub;
    hulk_intptr Forward(hulk_intptr, hulk_intptr);
};

hulk_intptr C_1c3b20::Forward(hulk_intptr a0, hulk_intptr a1) {
    return mSub->Fn(a0, a1);
}
