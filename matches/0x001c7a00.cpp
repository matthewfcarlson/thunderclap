#include "compat/ptr.h"
extern "C" char DAT_00421a68[];
class Sub_1c7a00 {
  public:
    void Init();
};
class ShadowGenerator {
  public:
    int mVft;
    int mValue;
    Sub_1c7a00 mSub;
    ShadowGenerator();
};
ShadowGenerator::ShadowGenerator() {
    mValue = 0;
    mVft = ((hulk_intptr)DAT_00421a68);
    mSub.Init();
}