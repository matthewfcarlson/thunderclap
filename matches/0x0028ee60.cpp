#include "compat/ptr.h"
extern "C" char DAT_0042cb5c[];
class ShaderFloatBroadcast {
  public:
    hulk_intptr mVft;
    int mZero;
    int mA;
    int mB;
    ShaderFloatBroadcast(int a, int b);
};
ShaderFloatBroadcast::ShaderFloatBroadcast(int a, int b) {
    mZero = 0;
    mVft = ((hulk_intptr)DAT_0042cb5c);
    mA = a;
    mB = b;
}