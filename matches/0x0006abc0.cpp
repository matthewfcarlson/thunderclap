// Same code shape as 0x0006aaf0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class Other_6abc0 {
  public:
    int call(hulk_intptr, int);
};
extern "C" Other_6abc0* __cdecl FUN_0008d690(int);

hulk_intptr CStageTrack::vfunc_12(hulk_intptr param) {
    Other_6abc0* p = FUN_0008d690(0x24);
    if (p)
        return p->call(param, this->f_10);
    return 0;
}
