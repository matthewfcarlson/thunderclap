#include "gen/hulkfight.h"

class Helper_161720 {
  public:
    int f(hulkfight::motion::ClimbLocomotion4Track*, int);
};
extern "C" Helper_161720* FUN_0008d690(int);

int hulkfight::motion::ClimbLocomotion4Track::vfunc_10(int a, int b, int c) {
    Helper_161720* p = FUN_0008d690(0x4c);
    if (p)
        return p->f(this, c);
    return 0;
}
