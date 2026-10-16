#include "gen/global.h"

class Helper_60810 {
  public:
    int Run(CEffectTrack*, int, int);
};
extern void* Get(int);

int CEffectTrack::vfunc_10(int a, int b, int c) {
    void* p = Get(0x2c);
    if (p)
        return ((Helper_60810*)p)->Run(this, c, a);
    return 0;
}
