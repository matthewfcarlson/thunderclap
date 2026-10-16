#include "gen/global.h"

extern "C" int __cdecl FUN_0008d690(int);
class Helper_e6600 {
  public:
    int run(int);
};

int FEThingsBase::vfunc_62(int a) {
    int x = FUN_0008d690(0x204);
    if (x)
        return ((Helper_e6600*)x)->run(a);
    return 0;
}
