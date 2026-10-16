// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002709b0 @ 0x002709b0
#include "decls/data/engine/unknown.h"

struct Record_2709b0 { unsigned int value; unsigned char active; char unused[0x117]; };
void __cdecl FUN_00277190(void *);
void __cdecl FUN_00273530(unsigned int, unsigned int);
void __cdecl FUN_00276650(unsigned int, unsigned int);
void __cdecl FUN_00275d20(unsigned int, unsigned int);
void __cdecl FUN_00273500();
void __cdecl FUN_0026d820(void *);
int __cdecl FUN_00267400();
int __cdecl FUN_002709b0(unsigned int first, unsigned int second, unsigned int third, unsigned int fourth)
{
    DAT_0052a124 = third;
    FUN_00277190(((char*)&DAT_0052a10c));
    FUN_00273530(first, fourth);
    FUN_00276650(first, fourth);
    FUN_00275d20(second, fourth);
    FUN_00273500();
    FUN_0026d820(((char*)((char*)&DAT_0052842c + 7364)));
    for (int i = 0; i < 26; ++i) {
        ((Record_2709b0*)&DAT_0052842c)[i].value = 0;
        ((Record_2709b0*)&DAT_0052842c)[i].active = 0;
    }
    (*(unsigned int*)&DAT_0052a120) = fourth;
    (*(unsigned char*)&DAT_0052a11d) = 1;
    return FUN_00267400();
}