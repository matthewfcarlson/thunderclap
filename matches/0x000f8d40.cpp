#include "compat/ptr.h"
#include "gen/owners.h"
extern char DAT_004a17a8;
extern char DAT_004a17c4;
extern "C" int __cdecl FUN_00344e74(hulk_intptr a, int b, void* c, void* d, int e);
hulk_intptr owners::ThisWrap_000f8d40::FUN_000f8d40(int a) {
    return FUN_00344e74(this->FUN_000f8cc0(a), 0, &DAT_004a17a8, &DAT_004a17c4, 0);
}
