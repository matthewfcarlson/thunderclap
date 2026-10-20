// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002a2510 @ 0x002a2510
#include "compat/ptr.h"
void __cdecl FUN_002a1e60(int*, int, hulk_intptr, int, int);
void __cdecl FUN_002a2510(int* first, int* last, int value)
{
    hulk_intptr bytes = (char*)last - (char*)first;
    while ((bytes >> 2) > 1) {
        int oldLast = *(int*)((char*)first + bytes - 4);
        *(int*)((char*)first + bytes - 4) = *first;
        FUN_002a1e60(first, 0, (bytes - 4) >> 2, oldLast, value);
        bytes -= 4;
    }
}