#include "gen/hulkfight.h"

class Helper_161470 {
  public:
    int run(hulkfight::motion::LocomotionStrafe4Track*, int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

int hulkfight::motion::LocomotionStrafe4Track::vfunc_10(int a, int b, int c) {
    void* p = FUN_0008d690(0x48);
    if (p)
        return ((Helper_161470*)p)->run(this, c);
    return 0;
}
