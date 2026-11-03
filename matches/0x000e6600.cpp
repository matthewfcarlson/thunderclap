#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

extern "C" int __cdecl FUN_0008d690(int);
class Helper_e6600 {
  public:
};

int FEThingsBase::vfunc_62(int a) {
    hulk_intptr x = FUN_0008d690(0x204);
    if (x)
        return ((int)(hulk_uintptr)((owners::Obj_f8bb0 *)(((Helper_e6600*)x)))->FUN_000f8bb0((hulk_intptr)a));
    return 0;
}
