#include "compat/ptr.h"
#include "gen/global.h"

class Other_6aaf0 {
  public:
    int call(hulk_intptr, int);
};
extern "C" Other_6aaf0* __cdecl FUN_0008d690(int);

hulk_intptr CRageModeTrack::vfunc_12(hulk_intptr param) {
    Other_6aaf0* p = FUN_0008d690(0x24);
    if (p)
        return p->call(param, this->f_10);
    return 0;
}
