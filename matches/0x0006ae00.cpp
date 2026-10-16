// Same code shape as 0x0006aaf0 (propagated; names are from that function)
#include "gen/global.h"

class Other_6ae00 {
  public:
    int call(int, int);
};
extern "C" Other_6ae00* __cdecl FUN_0008d690(int);

int CAlertStatusTrack::vfunc_12(int param) {
    Other_6ae00* p = FUN_0008d690(0x24);
    if (p)
        return p->call(param, this->f_10);
    return 0;
}
