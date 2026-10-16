// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_69850 {
  public:
    int invoke(CComboMessageTrack*, int);
};
extern R_69850* FUN_0008d690(int);

int CComboMessageTrack::vfunc_12(int param) {
    R_69850* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
