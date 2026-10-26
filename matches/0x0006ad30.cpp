#include "compat/ptr.h"
#include "gen/global.h"

class Helper_6ad30 {
  public:
    int run(CHeadTrackerTrack*, int);
};
extern void* __cdecl FUN_0008d690(unsigned int);

hulk_intptr CHeadTrackerTrack::vfunc_12(hulk_intptr param) {
    Helper_6ad30* p = (Helper_6ad30*)FUN_0008d690(0x90);
    if (p)
        return p->run(this, param);
    return 0;
}
