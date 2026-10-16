#include "gen/global.h"

extern "C" int __cdecl lookup(int);
class Helper_efeb0 {
  public:
    int call(int, int);
};

int FEThingsBase::vfunc_59(int arg) {
    int p = lookup(0x3db0);
    if (p)
        return ((Helper_efeb0*)p)->call(arg, 0);
    return 0;
}
