// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00270f10 @ 0x00270f10
#include "decls/data/engine/unknown.h"

#include "compat/ptr.h"
extern "C" void FUN_0026d850(void *arg);
extern "C" int FUN_0026d840(void *arg);
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
// equiv-conv: FUN_00270980 eax
extern "C" void __cdecl FUN_00270980(char *);
unsigned char __cdecl FUN_00270c80(void **result, const char *name, unsigned int options);
extern "C" int __cdecl FUN_00270f10(const char *name, void *argument)
{
    struct Local { void *result; char text[20]; } local;
    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    if (name) {
        strncpy(local.text, name, 16);
        local.text[16] = 0;
        FUN_00270980(local.text);
    } else {
        strncpy(local.text, DAT_0052a10c, 16);
    }
    FUN_00270c80(&local.result, local.text, (unsigned int)(hulk_uintptr)argument);
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
    return local.result != 0;
}