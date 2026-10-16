#include "gen/global.h"

class Helper_5e050 {
  public:
    int go(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

int CClearHitRecordsTrack::vfunc_12(int a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_5e050*)p)->go(a);
    return 0;
}
