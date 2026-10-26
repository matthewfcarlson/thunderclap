#include "compat/ptr.h"
#include "gen/global.h"

class Helper_60810 {
  public:
    int Run(CEffectTrack*, int, int);
};
extern void* Get(int);

hulk_intptr CEffectTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* p = Get(0x2c);
    if (p)
        return ((Helper_60810*)p)->Run(this, c, a);
    return 0;
}
