#include "compat/ptr.h"
extern "C" char DAT_0043186c[];
class RootMatrixDriver {
  public:
    hulk_intptr vf;
    char pad[0x14];
    int value;
    RootMatrixDriver(int);
};
class PhysicsJointMatrixModifier_2fc1d0 {
  public:
    void Init();
};
RootMatrixDriver::RootMatrixDriver(int x) {
    ((PhysicsJointMatrixModifier_2fc1d0*)this)->Init();
    value = x;
    vf = ((hulk_intptr)DAT_0043186c);
}