#include "compat/ptr.h"
#include "gen/global.h"

class Helper_efdd0 {
  public:
    int forwarder(FEThingsBase*, int);
};
extern int __cdecl lookup(int);

int FEThingsBase::vfunc_51(int a, int b) {
    hulk_intptr x = lookup(0x9b0);
    if (x)
        return ((Helper_efdd0*)x)->forwarder(this, b);
    return 0;
}
