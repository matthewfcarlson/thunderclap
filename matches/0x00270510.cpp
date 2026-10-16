#include "decls/data/engine/core.h"

extern "C" void __stdcall FUN_00209f01(void*);
extern "C" void __cdecl FUN_00270510(void) {
    char local[32];
    FUN_00209f01(local);
    (*(int*)&DAT_00528410) = *(int*)(local + 12);
}