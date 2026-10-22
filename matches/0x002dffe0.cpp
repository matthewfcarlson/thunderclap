#include "compat/ptr.h"
extern "C" char DAT_0042fbd4[];
class PrimGroupOptimized_2dffe0 {
  public:
    void Init();
};
class PrimGroupSkinnedOptimized : public PrimGroupOptimized_2dffe0 {
  public:
    char pad[0x40];
    int a40, a44, a48, a4c, a50;
    char p54[4];
    int a58;
    char p5c[4];
    int a60, a64;
    PrimGroupSkinnedOptimized* setup(int x, int y);
};
PrimGroupSkinnedOptimized* PrimGroupSkinnedOptimized::setup(int x, int y) {
    Init();
    a40 = 0;
    a44 = 0;
    a48 = x;
    a4c = y;
    a58 = 0;
    a60 = 0;
    a64 = 0;
    a50 = -1;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042fbd4);
    return this;
}
