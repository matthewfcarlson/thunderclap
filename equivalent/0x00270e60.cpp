// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 8/8)
// FUN_00270e60 @ 0x00270e60
#include "decls/data/engine/unknown.h"

extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
int __cdecl FUN_00270c10(const char *);
struct Record_270e60 { char name[0x11c]; };

void __cdecl FUN_00270e60(const char *key, char *output)
{
    char buffer[17];
    strncpy(buffer, key, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);
    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    int index = FUN_00270c10(buffer);
    if (index == -1) {
        output[0] = 0;
    } else {
        const char *source = ((Record_270e60*)((char*)&DAT_0052842c + 4))[index].name;
        char value;
        do {
            value = *source++;
            *output++ = value;
        } while (value);
    }
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
}