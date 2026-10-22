// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 6/6)
// FUN_00096d80 @ 0x00096d80
// cl-flags: /GS
#include "decls/address.h"
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
extern "C" unsigned long __cdecl FUN_00345d81(const char*, char**, int);
unsigned __int64 __cdecl FUN_00096d80(const char* text)
{
    unsigned __int64 result;
    if (!text) {
        result = 0;
    } else if (text[0] == '0' && text[1] == 'x') {
        char buffer[32];
        char* end;
        FUN_00267760(buffer, 32, "%s", text);
        buffer[10] = 0;
        unsigned long high = FUN_00345d81(buffer, &end, 0);
        FUN_00267760(buffer, 32, "0x%s", text + 10);
        unsigned long low = FUN_00345d81(buffer, &end, 0);
        result = (unsigned __int64)high * 0x100000000ui64 + low;
    } else {
        result = FUN_0027b020(text);
    }
    return result;
}