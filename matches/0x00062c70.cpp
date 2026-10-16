#include "gen/global.h"

class Helper_62c70 {
  public:
    int run(int, int);
};
extern Helper_62c70* __cdecl FUN_0008d690(int);

int CSmartPropRemoveInstanceTrack::vfunc_12(int arg) {
    Helper_62c70* p = FUN_0008d690(0x24);
    if (p)
        return p->run(arg, this->f_0c);
    return 0;
}
