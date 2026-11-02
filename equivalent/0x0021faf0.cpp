// STATUS: equivalent (tools/equiv.py level 3: 14398 inputs, branch coverage 2/2)
// FUN_0021faf0 @ 0x0021faf0
// FUN_0021faf0 @ 0x0021faf0
// FUN_0021faf0 @ 0x0021faf0
#include "compat/ptr.h"
struct Source { int data; };
struct Destination { char pad0[12]; int data; char pad1[28]; int count; };
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char *, unsigned int, void *);
// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(Source *source, const char *message);
int __cdecl FUN_0021add0(int data, int a, int b, int bytes);
// equiv-conv: FUN_0021f940 eax ecx edx stack
extern "C" void __cdecl FUN_0021f940(unsigned int, unsigned char *, void *, unsigned int);
// equiv-conv: FUN_0021faf0 eax ebx
extern "C" void FUN_0021faf0(void *source, void *destination)
{
    int count;
    FUN_0021f8c0((char *)(int *)(&count), 4, (Source *)((Source *)source));
    if (count < 0)
        FUN_0021f800(((Source *)source), "bad integer");
    ((Destination *)destination)->data = FUN_0021add0(((Source *)source)->data, 0, 0, count * 4);
    ((Destination *)destination)->count = count;
    FUN_0021f940((int)count, (unsigned char *)(hulk_uintptr)(int)(((Destination *)destination)->data), (Source *)((Source *)source), 4);
}
