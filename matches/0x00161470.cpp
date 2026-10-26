#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Helper_161470 {
  public:
    int run(hulkfight::motion::LocomotionStrafe4Track*, hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

hulk_intptr hulkfight::motion::LocomotionStrafe4Track::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* p = FUN_0008d690(0x48);
    if (p)
        return ((Helper_161470*)p)->run(this, c);
    return 0;
}
