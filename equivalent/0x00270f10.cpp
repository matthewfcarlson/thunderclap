// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00270f10 @ 0x00270f10
#include "decls/data/engine/unknown.h"

void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
// equiv-conv: FUN_00270980 eax
void __cdecl FUN_00270980(char *);
void __cdecl FUN_00270c80(void **, const char *, void *);
int __cdecl FUN_00270f10(const char *name, void *argument)
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
    FUN_00270c80(&local.result, local.text, argument);
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
    return local.result != 0;
}