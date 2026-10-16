#include "gen/global.h"

class Other_6aaf0 {
  public:
    int call(int, int);
};
extern "C" Other_6aaf0* __cdecl FUN_0008d690(int);

int CRageModeTrack::vfunc_12(int param) {
    Other_6aaf0* p = FUN_0008d690(0x24);
    if (p)
        return p->call(param, this->f_10);
    return 0;
}
