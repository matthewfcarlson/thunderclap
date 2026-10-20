#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(hulk_uintptr);
class Helper_efe00 {
  public:
    int call(int);
};

int FEThingsBase::vfunc_53(int x) {
    Helper_efe00* p = (Helper_efe00*)FUN_0008d690(0x980);
    if (p)
        return p->call(x);
    return 0;
}
