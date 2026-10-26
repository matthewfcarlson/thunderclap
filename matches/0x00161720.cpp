#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Helper_161720 {
  public:
    int f(hulkfight::motion::ClimbLocomotion4Track*, hulk_intptr);
};
extern "C" Helper_161720* FUN_0008d690(int);

hulk_intptr hulkfight::motion::ClimbLocomotion4Track::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    Helper_161720* p = FUN_0008d690(0x4c);
    if (p)
        return p->f(this, c);
    return 0;
}
