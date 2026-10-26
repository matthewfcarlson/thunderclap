#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int U_23e880;
extern void* __cdecl FUN_0008d690(int);
class Helper_23e880 {
  public:
    U_23e880 FUN_0023e610(U_23e880, hulk_uintptr, U_23e880, U_23e880);
};

hulk_intptr fight::StopTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { U_23e880 a = (U_23e880)__p0; U_23e880 b = (U_23e880)__p1; U_23e880 c = (U_23e880)__p2;

    Helper_23e880* p = (Helper_23e880*)FUN_0008d690(0x2c);
    if (p)
        return (int)(p->FUN_0023e610(a, (hulk_uintptr)this, b, c));
    return (int)(0);
}
