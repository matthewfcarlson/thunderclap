// Same code shape as 0x0005e050 (propagated; names are from that function)
#include "gen/global.h"

class Helper_6aec0 {
  public:
    int go(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

int CDeathTrack::vfunc_12(int a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_6aec0*)p)->go(a);
    return 0;
}
