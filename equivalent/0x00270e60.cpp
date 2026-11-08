// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 8/8)
// FUN_00270e60 @ 0x00270e60
#include "decls/data/engine/unknown.h"

extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
extern "C" int __cdecl FUN_00270c10(const char *);
// the drive registry (records.h CoreDriveRegistryEntry)

void __cdecl FUN_00270e60(const char *key, char *output)
{
    char buffer[17];
    strncpy(buffer, key, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);
    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10(buffer);
    if (index == -1) {
        output[0] = 0;
    } else {
        const char *source = DAT_00528418[index].details;
        char value;
        do {
            value = *source++;
            *output++ = value;
        } while (value);
    }
    FUN_0026d840(((char*)DAT_0052a0f0));
}