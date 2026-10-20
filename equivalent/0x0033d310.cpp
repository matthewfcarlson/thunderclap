// STATUS: equivalent (tools/equiv.py level 3: 224 inputs, branch coverage 17/18, incomplete)
// FUN_0033d310 @ 0x0033d310
#include "compat/ptr.h"
extern "C" char* __cdecl strchr(const char*, int);
extern "C" int __cdecl isdigit(int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __cdecl FUN_00338e20(void*, const char*);
// equiv-conv: FUN_0033d310 ebx stack stack stack
char* __cdecl FUN_0033d310(char* input, void* context, char* output, int* precision)
{
    char* cursor = input;
    while (strchr("-+ #0", (signed char)*cursor)) ++cursor;
    if (isdigit((unsigned char)*cursor)) ++cursor;
    if (isdigit((unsigned char)*cursor)) ++cursor;
    if (*cursor == '.') {
        ++cursor;
        *precision = 1;
        if (isdigit((unsigned char)*cursor)) ++cursor;
        if (isdigit((unsigned char)*cursor)) ++cursor;
    }
    if (isdigit((unsigned char)*cursor))
        FUN_00338e20(context, "invalid format (width or precision too long)");
    hulk_intptr length = cursor - input;
    if (length + 2 > 20)
        FUN_00338e20(context, "invalid format (too long)");
    *output = '%';
    strncpy(output + 1, input, length + 1);
    output[length + 2] = 0;
    return cursor;
}