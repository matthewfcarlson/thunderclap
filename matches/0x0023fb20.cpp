#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_0023fa40(char **, char *, unsigned int, int);
void owners::Obj_23fb20::FUN_0023fb20(const char *a1, hulk_uintptr a2, hulk_uintptr a3, int a4) {
    a = (unsigned short)a4;
    b = (unsigned short)a2;
    if (a4 == 0) {
        value = a1;
        return;
    }
    if (a4 == 1) {
        value = a1;
        return;
    }
    FUN_0023fa40((char **)(&a1), (char *)a1, (unsigned int)a2, (unsigned int)a3);
    value = a1;
}
