// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002f4650 @ 0x002f4650
#include "compat/ptr.h"
void __cdecl FUN_002f40f0(unsigned short *, int, hulk_intptr, unsigned int);
void __cdecl FUN_002f4650(unsigned short *first, unsigned short *last)
{
    hulk_intptr bytes = (char *)last - (char *)first;
    while ((bytes >> 1) > 1) {
        unsigned int saved = *(unsigned short *)((char *)first + bytes - 2);
        *(unsigned short *)((char *)first + bytes - 2) = *first;
        FUN_002f40f0(first, 0, (bytes - 2) >> 1, saved);
        bytes -= 2;
    }
}