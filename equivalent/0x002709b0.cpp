// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002709b0 @ 0x002709b0
#include "decls/data/engine/unknown.h"

// the drive registry (records.h CoreDriveRegistryEntry): every drive unmounted, every source directory cleared
void __cdecl FUN_00277190(void *);
extern "C" void __cdecl FUN_00273530(unsigned int, unsigned int);
void __cdecl FUN_00276650(unsigned int, unsigned int);
extern "C" void __cdecl FUN_00275d20(unsigned int, unsigned int);
extern "C" void __cdecl FUN_00273500();
extern "C" void __cdecl FUN_0026d820(void *);
extern "C" int __cdecl FUN_00267400();
int __cdecl FUN_002709b0(unsigned int first, unsigned int second, unsigned int third, unsigned int fourth)
{
    DAT_0052a124 = third;
    FUN_00277190(((char*)&DAT_0052a10c));
    FUN_00273530(first, fourth);
    FUN_00276650(first, fourth);
    FUN_00275d20(second, fourth);
    FUN_00273500();
    FUN_0026d820(((char*)DAT_0052a0f0));
    for (int i = 0; i < 26; ++i) {
        DAT_00528418[i].drive = 0;
        DAT_00528418[i].details[0] = 0;
    }
    (*(unsigned int*)&DAT_0052a120) = fourth;
    (*(unsigned char*)&DAT_0052a11d) = 1;
    return FUN_00267400();
}