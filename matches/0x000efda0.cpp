#include "gen/global.h"

extern int __cdecl FUN_0008d690(int);
class Helper_efda0 {
  public:
    int call(FEThingsBase*, int);
};

int FEThingsBase::vfunc_50(int a, int b) {
    int x = FUN_0008d690(0xbc4);
    if (x)
        return ((Helper_efda0*)x)->call(this, b);
    return 0;
}
