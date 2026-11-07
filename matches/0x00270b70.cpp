#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_0026d850(char*);
extern "C" void __cdecl FUN_0026d840(char*);
extern "C" void __cdecl FUN_00270b70(char* dst) {
    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    char* p = DAT_0052a10c;
    hulk_intptr d = (hulk_intptr)dst - (hulk_intptr)DAT_0052a10c;
    char c;
    do {
        c = *p;
        *(p + d) = c;
        ++p;
    } while (c != 0);
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
}
